// Fill out your copyright notice in the Description page of Project Settings.


#include "AGameCharacter.h"

	// Sets default values
AAGameCharacter::AAGameCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAGameCharacter::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AAGameCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAGameCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}