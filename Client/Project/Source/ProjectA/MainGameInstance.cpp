// Fill out your copyright notice in the Description page of Project Settings.


#include "MainGameInstance.h"
#include "MyGameInstance.h"

void UMainGameInstance::Init()
{
	Super::Init();
	gameNS::MyGameInstance::Ins()->Init(this);
}
void UMainGameInstance::StartGameInstance()
{
	Super::StartGameInstance();

}
void UMainGameInstance::Shutdown()
{
	Super::Shutdown();
}