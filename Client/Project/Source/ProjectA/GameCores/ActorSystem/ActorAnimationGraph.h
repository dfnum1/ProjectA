// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
namespace gameNS
{
	struct FAnimationData;
	struct FAnimationQueue;

	typedef TMap<FString, FAnimationData*>	tAnimationMap;
	typedef TMap<int, FAnimationData*>	tAnimationIdMap;

	struct sTriggerParam
	{
		float					_fTime;
		float					_fDurtion;

		FString					_Name;
		TArray<FString>			_vParam;

		bool					_bTriggered;

		sTriggerParam() :_bTriggered(false), _fTime(0.f), _fDurtion(0.f)
		{}
	};

	typedef TMultiMap<int, sTriggerParam>		tActorEventMap;//key-id

	class ActorAnimationGraph
	{
	public:
		ActorAnimationGraph(AActor* pActor);
		ActorAnimationGraph();
		virtual ~ActorAnimationGraph();

		void			BindMesh(USkeletalMeshComponent* pMesh);
		void			BindActor(AActor* pActor);
		AActor*			GetActor();

		void			OnTick(float DeltaTime);

		void			BindAnimation(FAnimationQueue& Queue);
		float			PlayAnimation(const FString& Name);
		float			PlayAnimation(int Id);
		float			PlayAnimation(const FAnimationData* pData);
		float			PlayAnimation(class UAnimMontage* AnimMontage, float InPlayRate = 1.f, FName StartSectionNam = NAME_None);
		float			PlayAnimation(class UAnimationAsset* AnimAsset, bool bLoop);
		void			StopAnimMontage(class UAnimMontage* AnimMontage);
		void			StopAllAnimMontages();
		FAnimationData* GetAnimationByName(const FString& Name);
		FAnimationData* GetAnimationById(int Id);

		void			AddEvent(const FString& Name, float fTriggerTime, const TArray<FString>& Param);
		void			TriggerEvent(const FString& Name, const TArray<FString>& vParam);
	private:
		AActor*							m_pActorMe;
		USkeletalMeshComponent*			m_pSkeletalMeshComponent;
		USkeletalMeshComponent*			m_vAvatarMesh[EAvatarType::eNum];

		tAnimationMap					m_mAnimation;
		tAnimationIdMap					m_mAnimationId;

		tActorEventMap					m_mTriggerEvent;
	};

}
