// Fill out your copyright notice in the Description page of Project Settings.
#include "MainMenu.h"

bool UMainMenu::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success) return false;

	// TODO: setup

	if (!ensure(ButtonHost != nullptr)) return false;
	ButtonHost->OnClicked.AddDynamic(this, &UMainMenu::HostServer);

	return true;
}

void UMainMenu::HostServer()
{
	UE_LOG(LogTemp, Warning, TEXT("Host Button Clicked"));
}
