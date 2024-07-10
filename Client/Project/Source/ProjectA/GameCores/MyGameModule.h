// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

namespace gameNS
{
	class MyGameModule
	{
	public:
		MyGameModule();
		virtual ~MyGameModule();

	public:
		virtual void Init(UGameInstance* pInstance);

		AActor* GetCurrentPlayer() { return m_pCurrentPlayer; }

		UGameInstance* GetEngienInstance() { return m_pEngineInstance; }
		UWorld* GetEngineWorld();
	protected:
		UGameInstance* m_pEngineInstance;

		AActor* m_pCurrentPlayer;
	};
}
