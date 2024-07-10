// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

namespace gameNS
{
#define DECLARE_SINGLETON(class_name) \
protected:\
	static class_name*	s_pIns; \
public: \
	static class_name*	Ins(); \

#define IMPLEMENT_SINGLETON(class_name) \
	class_name* class_name::s_pIns = nullptr; \
	class_name* class_name::Ins(){\
		if(!s_pIns)\
			s_pIns = new class_name(); \
		return s_pIns;\
	}\

}
