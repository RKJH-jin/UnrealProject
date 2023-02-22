// Copyright Epic Games, Inc. All Rights Reserved.

#include "ProjectileTool.h"
#include "ProjectileToolStyle.h"
#include "ProjectileToolCommands.h"
#include "LevelEditor.h"
#include "Widgets/Docking/SDockTab.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/SViewport.h"
#include "Widgets/SOverlay.h"

#include "ToolMenus.h"

static const FName ProjectileToolTabName("ProjectileTool");

#define LOCTEXT_NAMESPACE "FProjectileToolModule"

void FProjectileToolModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FProjectileToolStyle::Initialize();
	FProjectileToolStyle::ReloadTextures();

	FProjectileToolCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FProjectileToolCommands::Get().OpenPluginWindow,
		FExecuteAction::CreateRaw(this, &FProjectileToolModule::PluginButtonClicked),
		FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FProjectileToolModule::RegisterMenus));
	
	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(ProjectileToolTabName, FOnSpawnTab::CreateRaw(this, &FProjectileToolModule::OnSpawnPluginTab))
		.SetDisplayName(LOCTEXT("FProjectileToolTabTitle", "ProjectileTool"))
		.SetMenuType(ETabSpawnerMenuType::Hidden);
}

void FProjectileToolModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FProjectileToolStyle::Shutdown();

	FProjectileToolCommands::Unregister();

	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(ProjectileToolTabName);
}

TSharedRef<SDockTab> FProjectileToolModule::OnSpawnPluginTab(const FSpawnTabArgs& SpawnTabArgs)
{
	FText WidgetText = FText::Format(
		LOCTEXT("WindowWidgetText", "Add code to {0} in {1} to override this window's contents"),
		FText::FromString(TEXT("FProjectileToolModule::OnSpawnPluginTab")),
		FText::FromString(TEXT("ProjectileTool.cpp"))
		);


	_DockTab = SAssignNew(_DockTab, SDockTab)
		.TabRole(ETabRole::NomadTab)
		[
			SNew(SBox)
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			[
				SAssignNew(_Viewport, SViewport)
				.ShowEffectWhenDisabled(false)
				.EnableGammaCorrection(false)
				[
					SAssignNew(_ViewportOverlay, SOverlay)
					+ SOverlay::Slot()
					[
						SNew(SBorder)
						.Padding(0.0f)
						.ShowEffectWhenDisabled(false)
					]
				]
				//SNew(STextBlock)
				//.Text(WidgetText)
				//SNew(SSCSEditorViewport)
			]

			
		];

	return _DockTab.ToSharedRef();
	//return SNew(SDockTab)
	//	.TabRole(ETabRole::NomadTab)
	//	[
	//		// Put your tab content here!
	//		SNew(SBox)
	//		.HAlign(HAlign_Center)
	//		.VAlign(VAlign_Center)
	//		[
	//			SNew(STextBlock)
	//			.Text(WidgetText)
	//		]
	//		
	//		//SNew(SSCSEditorViewport)
	//		//.BlueprintEditor(SharedThis(this))

	//	];
}

void FProjectileToolModule::PluginButtonClicked()
{
	FGlobalTabmanager::Get()->TryInvokeTab(ProjectileToolTabName);
}

void FProjectileToolModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
			Section.AddMenuEntryWithCommandList(FProjectileToolCommands::Get().OpenPluginWindow, PluginCommands);
		}
	}

	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("Settings");
			{
				FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FProjectileToolCommands::Get().OpenPluginWindow));
				Entry.SetCommandList(PluginCommands);
			}
		}
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FProjectileToolModule, ProjectileTool)