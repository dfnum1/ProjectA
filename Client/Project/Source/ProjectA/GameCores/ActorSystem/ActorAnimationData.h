// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActorAnimationData.generated.h"

USTRUCT()
struct FAnimationEvent
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditDefaultsOnly, Category = TriggerEvnetParam)
	FString Name;

	UPROPERTY(EditDefaultsOnly, Category = TriggerEvnetParam)
	TArray<FString> Param;

	UPROPERTY(EditDefaultsOnly, Category = TriggerEvnetParam)
	float TriggerTime;
};

USTRUCT()
struct FAnimationData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditDefaultsOnly, Category = Animation)
	int		Id;

	UPROPERTY(EditDefaultsOnly, Category = Animation)
	FString SignName;

	/** initial clips */
	UPROPERTY(EditDefaultsOnly, Category = Animation)
	class UAnimMontage* Anim;

	UPROPERTY(EditDefaultsOnly, Category = Animation)
	class UAnimationAsset* AnimAsset;


	UPROPERTY(EditDefaultsOnly, Category = Animation)
	int		nLoop;

	UPROPERTY(EditDefaultsOnly, Category = Animation)
	TArray<FAnimationEvent> TriggerEventParam;

	/** defaults */
	FAnimationData()
	{
		Id = 0;
		SignName = "";
		nLoop = 1;
		AnimAsset = nullptr;
		Anim = nullptr;
	}
};

USTRUCT()
struct FAnimationQueue
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditDefaultsOnly, Category = Config)
	TArray<FAnimationData> Animations;
};