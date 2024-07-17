// Fill out your copyright notice in the Description page of Project Settings.


#include "DataManager.h"

namespace gameNS
{
	DataManager::DataManager()
	{
	}
	//-----------------------------------------------------------------------------
	DataManager::~DataManager()
	{
	}
	//-----------------------------------------------------------------------------
	bool DataManager::Init()
	{
		UObject* pAsset2 = UGameBlueprintFunctionLibrary::LoadObjectFromPath("/Game/GameDatas/ConfigDatas.ConfigDatas_C");
		UDataAsset* pAsset = UGameBlueprintFunctionLibrary::LoadDataAssetFromPath("/Game/GameDatas/ConfigDatas.ConfigDatas");
		if (pAsset != NULL)
		{

		}
		return true;
	}
}

