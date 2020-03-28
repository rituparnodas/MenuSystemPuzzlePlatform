// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu.h"
#include "Components/Button.h"
#include "Engine/Engine.h"


bool UMainMenu::Initialize()
{
	bool Success = Super::Initialize(); // If This Method Fails
	if(!Success) return false;

	if (!ensure(Host != nullptr)) return false;
	Host->OnClicked.AddDynamic(this, &UMainMenu::HostServer);
	return true;
}

void UMainMenu::SetMenuInterface(IMenuInterface* MenuToInterface)
{
	this->MenuInterface = MenuToInterface;
}

void UMainMenu::HostServer()
{
	UE_LOG(LogTemp, Warning, TEXT("Host Clicked"))

	if (MenuInterface != nullptr)
	{
		MenuInterface->Host();
	}
}