// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

namespace gameNS
{
	UENUM()
	enum class EAvatarType : uint8
	{
		eBody = 0,
		eFace,
		eLeg,
		eNum,
	};
}