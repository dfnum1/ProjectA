// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModule.h"

namespace gameNS
{
	MyGameModule::MyGameModule()
		: m_pEngineInstance(NULL)
		, m_pCurrentPlayer(NULL)
	{
	}
	//-----------------------------------------------------------------------------
	MyGameModule::~MyGameModule()
	{
		m_pEngineInstance = NULL;
	}
	//-----------------------------------------------------------------------------
	void MyGameModule::Init(UGameInstance* pInstance)
	{
		m_pEngineInstance = pInstance;
	}
	//-----------------------------------------------------------------------------
	UWorld* MyGameModule::GetEngineWorld()
	{
		if (m_pEngineInstance == NULL) return NULL;
		return m_pEngineInstance->GetWorld();
	}
}
