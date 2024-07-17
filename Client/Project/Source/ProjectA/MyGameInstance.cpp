// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"

namespace gameNS
{
	//----------------------------------------------------
	MyGameInstance::MyGameInstance()
	{
		m_pDataMgr = new DataManager();
	}
	//----------------------------------------------------
	MyGameInstance::~MyGameInstance()
	{
		delete m_pDataMgr;
	}
	//----------------------------------------------------
	IMPLEMENT_SINGLETON(MyGameInstance)
	//----------------------------------------------------
	void MyGameInstance::Init(UGameInstance* pInstance)
	{
		MyGameModule::Init(pInstance);

		m_pDataMgr->Init();
	}
}

