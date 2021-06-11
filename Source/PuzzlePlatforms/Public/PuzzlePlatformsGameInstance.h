// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "OnlineSubsystem.h"
#include "OnlineSessionSettings.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "Blueprint/UserWidget.h"
#include <PuzzlePlatforms/MenuSystem/MenuInterface.h>
#include <PuzzlePlatforms/MenuSystem/MainMenu.h>
#include "PuzzlePlatformsGameInstance.generated.h"

UCLASS()
class PUZZLEPLATFORMS_API UPuzzlePlatformsGameInstance final : public UGameInstance, public IMenuInterface
{
	GENERATED_BODY()

public:
	explicit  UPuzzlePlatformsGameInstance(const FObjectInitializer& ObjectInitializer);

	virtual void Init() override;

	UFUNCTION(BlueprintCallable)
	void LoadMenuWidget();

	UFUNCTION(BlueprintCallable)
	void InGameLoadMenu();

	UFUNCTION(Exec)
	virtual void Host(FString ServerName) override;

	UFUNCTION(Exec)
	virtual void Join(uint32 Index) override;

	virtual void LoadMainMenu() override;

	virtual void RefreshServerList() override;

private:
	TSubclassOf<class UUserWidget> MenuClass;
	TSubclassOf<class UUserWidget> InGameMenuClass;

	class UMainMenu* Menu;

	IOnlineSessionPtr SessionInterface;
	TSharedPtr< class FOnlineSessionSearch> SessionSearch;

	void OnCreateSessionComplete(FName SessionName, bool Success);
	void OnDestroySessionCompleteDelegates(FName SessionName, bool Success);
	void OnFindSessionCompleteDelegates(bool Success);
	void OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result);

	FString DesiredServerName;
	void CreateSession();
};
