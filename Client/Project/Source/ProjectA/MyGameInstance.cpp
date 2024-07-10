// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"

namespace gameNS
{
	//----------------------------------------------------
	MyGameInstance::MyGameInstance()
	{
	}
	//----------------------------------------------------
	MyGameInstance::~MyGameInstance()
	{
	}
	//----------------------------------------------------
	IMPLEMENT_SINGLETON(MyGameInstance)
	//----------------------------------------------------
	void MyGameInstance::Init(UGameInstance* pInstance)
	{
		MyGameModule::Init(pInstance);
	}
}

