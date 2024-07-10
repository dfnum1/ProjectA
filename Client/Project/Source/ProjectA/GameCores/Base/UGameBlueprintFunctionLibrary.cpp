// Fill out your copyright notice in the Description page of Project Settings.


#include "UGameBlueprintFunctionLibrary.h"
#include "../../MyGameInstance.h"


FName UGameBlueprintFunctionLibrary::GetObjectPath(const UObject* pObj)
{
	if (pObj == NULL)
		return NAME_None;

	FStringAssetReference ThePath = FStringAssetReference(pObj);
	if (!ThePath.IsValid())
		return NAME_None;

	FString str = pObj->GetClass()->GetDescription();

	str += "";
	str += ThePath.ToString();
	str += "";

	return FName(*str);
}
UObject* UGameBlueprintFunctionLibrary::LoadObjectFromPath(const FName& Path)
{
	if (Path == NAME_None)
		return nullptr;

	return LoadObjFormPath<UObject>(Path);
}

UDataAsset* UGameBlueprintFunctionLibrary::LoadDataAssetFromPath(const FName& Path)
{
	if (Path == NAME_None)
		return nullptr;

	return LoadObjFormPath<UDataAsset>(Path);
}

APlayerController* UGameBlueprintFunctionLibrary::GetLocalPlayerController(UWorld* World)
{
	if (World)
	{
// 		if (CGameInstance::Ins()->GetLocalPlayer())
// 		{
// 			return CGameInstance::Ins()->GetLocalPlayer()->GetPlayerController(World);
// 		}
// 		for (FConstPlayerControllerIterator Iterator = World->GetPlayerControllerIterator(); Iterator; ++Iterator)
// 		{
// 			APlayerController* PlayerController = *Iterator;
// 			if (PlayerController->IsLocalController())
// 			{
// 				// For this project, we will only ever have one local player.  
// 				return PlayerController;
// 			}
// 		}
	}
	return nullptr;
}

AActor* UGameBlueprintFunctionLibrary::GetUserPlayer()
{
// 	AActor* pPlayer = CGameInstance::Ins()->GetPlayer();
// 	if (pPlayer == nullptr)
// 		return nullptr;
// 
// 	if (CGameInstance::Ins()->GetLocalPlayer())
// 	{
// 		if (CGameInstance::Ins()->GetUEWorld() &&
// 			CGameInstance::Ins()->GetLocalPlayer()->GetPlayerController(CGameInstance::Ins()->GetUEWorld()))
// 		{
// 			return CGameInstance::Ins()->GetLocalPlayer()->GetPlayerController(CGameInstance::Ins()->GetUEWorld())->GetOwner();
// 		}
// 	}
// 
// 	AGameUserCharacter* pChar = Cast<AGameUserCharacter>(pPlayer);
// 	if (pChar == nullptr)
// 		return nullptr;
// 	if (pChar->isRiding())
// 		return pChar->GetRideActor();
// 
// 	return pChar;
	return NULL;
}

USkeletalMeshComponent* UGameBlueprintFunctionLibrary::GetUserPlayerSkinMesh()
{
 	AActor* pPlayer =gameNS::MyGameInstance::Ins()->GetCurrentPlayer();
 	if (pPlayer == nullptr)
 		return nullptr;
//  	AGameUserCharacter* pChar = Cast<AGameUserCharacter>(pPlayer);
//  	if (pChar == nullptr)
//  		return nullptr;
//  	return pChar->GetSkeletalMeshComponent();
	return NULL;
}

int UGameBlueprintFunctionLibrary::GetGenerateNpcActorId()
{
	//return CGameInstance::Ins()->GetGenerateNpcActorId();
	return 0;
}

int UGameBlueprintFunctionLibrary::GetNpcNum()
{
// 	if (CGameInstance::Ins()->GetUEInstance() == nullptr)
// 		return 0;
// 	if (CGameInstance::Ins()->GetUEInstance()->GetWorld() == nullptr)
// 		return 0;

	int num = 0;

// 	for (FConstPawnIterator it = CGameInstance::Ins()->GetUEInstance()->GetWorld()->GetPawnIterator(); it; ++it)
// 	{
// 		AGameUserNpcCharacter* pActor = Cast<AGameUserNpcCharacter>(*it);
// 		if (pActor && pActor->IsAlive())
// 			num++;
// 	}

	return num;
}

AActor* UGameBlueprintFunctionLibrary::FindLevelActorByName(const FString& Name)
{
	UWorld* pWorld = gameNS::MyGameInstance::Ins()->GetEngineWorld();
 	if (pWorld == nullptr)
 		return nullptr;
// 	TArray<AActor*> Actors;
// 	UGameplayStatics::GetAllActorsOfClass(pWorld, AActor::StaticClass(), Actors);
// 
// 	for (AActor* Actor : Actors)
// 	{
// 		if (Actor->GetName() == Name)
// 			return Actor;
// 	}
	return nullptr;
}

void UGameBlueprintFunctionLibrary::ShowUI(int UIType, bool To3D)
{
// 	CUIBase* pBase = CUIMgr::Ins()->GetUI((EFnType)(int)UIType);
// 	if (pBase)
// 	{
// 		pBase->Show(To3D);
// 		CGameInstance::Ins()->ShowMouseCursor(true);
// 	}
}

void UGameBlueprintFunctionLibrary::HideUI(int UIType)
{
// 	CUIBase* pBase = CUIMgr::Ins()->GetUI((EFnType)(int)UIType);
// 	if (pBase)
// 	{
// 		pBase->Hide();
// 	}
}

