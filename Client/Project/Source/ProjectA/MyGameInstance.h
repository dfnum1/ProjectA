// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyGameModule.h"
#include "GameSingleton.h"

namespace gameNS
{
	class MyGameInstance : public MyGameModule
	{
	public:
		MyGameInstance();
		virtual ~MyGameInstance();

		DECLARE_SINGLETON(MyGameInstance);

	public:
		virtual void Init(UGameInstance* pInstance) override;
	};

}
