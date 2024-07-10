// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UGameBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTA_API UGameBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "GameGolabFunction")
		static FName GetObjectPath(const UObject* pObj);

	UFUNCTION(BlueprintCallable, Category = "GameGolabFunction")
		static UObject* LoadObjectFromPath(const FName& Path);

	UFUNCTION(BlueprintCallable, Category = "GameGolabFunction")
		static UDataAsset* LoadDataAssetFromPath(const FName& Path);

	UFUNCTION(BlueprintCallable, Category = "GameGolabFunction")
		static APlayerController* GetLocalPlayerController(UWorld* World);

	UFUNCTION(BlueprintCallable, Category = "GameGolabFunction")
		static AActor* GetUserPlayer();

	UFUNCTION(BlueprintCallable, Category = "GameGolabFunction")
		static USkeletalMeshComponent* GetUserPlayerSkinMesh();

	UFUNCTION(BlueprintCallable, Category = "GameGolabFunction")
		static int		 GetGenerateNpcActorId();

	UFUNCTION(BlueprintCallable, Category = "GameGolabFunction")
		static int				GetNpcNum();

	UFUNCTION(BlueprintCallable, Category = "GameGolabFunction")
		static AActor*			FindLevelActorByName(const FString& Name);

	UFUNCTION(BlueprintCallable, Category = "GameGolabFunction")
		static void				ShowUI(int UIType, bool To3D = false);
	UFUNCTION(BlueprintCallable, Category = "GameGolabFunction")
		static void				HideUI(int UIType);

private:
	template<typename ObjClass>
	static FORCEINLINE ObjClass* LoadObjFormPath(const FName& Path)
	{
		if (Path == NAME_None)
			return nullptr;

		return Cast<ObjClass>(StaticLoadObject(ObjClass::StaticClass(), NULL, *Path.ToString()));
	}
};
