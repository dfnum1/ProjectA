// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameCsvAsset.generated.h"

USTRUCT(Blueprintable)
struct FCsvAssetData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CsvData")
	int						CsvType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CsvData")
		TAssetPtr<UDataTable>   CsvData;
};

UCLASS(Blueprintable)
class PROJECTA_API UGameCsvAsset : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CsvData")
		TArray<FCsvAssetData>   CsvData;
};
