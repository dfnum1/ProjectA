// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorAnimationGraph.h"
#include "ActorAnimationData.h"

namespace gameNS
{
	sTriggerParam::sTriggerParam() :_bTriggered(false), _fTime(0.f), _fDurtion(0.f) {}
	//----------------------------------------------------
	ActorAnimationGraph::ActorAnimationGraph()
		: m_pActorMe(nullptr)
		, m_pSkeletalMeshComponent(nullptr)
	{
		m_mAnimation.Empty();
		for (int i = 0; i < (int)EAvatarType::eNum; ++i)
			m_vAvatarMesh[i] = NULL;
	}
	//----------------------------------------------------
	ActorAnimationGraph::ActorAnimationGraph(AActor* pActor)
		: m_pActorMe(pActor)
		, m_pSkeletalMeshComponent(nullptr)
	{
		for (int i = 0; i < (int)EAvatarType::eNum; ++i)
			m_vAvatarMesh[i] = NULL;
	}
	//----------------------------------------------------
	ActorAnimationGraph::~ActorAnimationGraph()
	{
		m_mAnimation.Empty();
	}
	//----------------------------------------------------
	void ActorAnimationGraph::BindMesh(USkeletalMeshComponent* pMesh)
	{
		m_pSkeletalMeshComponent = pMesh;
	}
	//----------------------------------------------------
	void ActorAnimationGraph::BindActor(AActor* pActor)
	{
		m_pActorMe = pActor;

		// 		AGameUserCharacter* pChar = Cast<AGameUserCharacter>(pActor);
		// 		if (pChar)
		// 		{
		// 			for (int i = 0; i < (int)EAvatarType::Num; ++i)
		// 				m_vAvatarMesh[i] = pChar->m_vAvatarMesh[i];
		// 		}
	}
	//----------------------------------------------------
	AActor* ActorAnimationGraph::GetActor()
	{
		return m_pActorMe;
	}
	//----------------------------------------------------
	void ActorAnimationGraph::OnTick(float DeltaTime)
	{
		if (m_mTriggerEvent.Num() > 0)
		{
			TArray<int> vTriggered;
			for (auto& Pair : m_mTriggerEvent)
			{
				if (!Pair.Value._bTriggered)
				{
					Pair.Value._fTime += DeltaTime;
					if (Pair.Value._fTime >= Pair.Value._fDurtion)
					{
						TriggerEvent(Pair.Value._Name, Pair.Value._vParam);
						Pair.Value._bTriggered = true;

						vTriggered.Add(Pair.Key);
					}
				}
			}
			for (int32 i = 0; i < vTriggered.Num(); ++i)
				m_mTriggerEvent.Remove(vTriggered[i]);
		}
	}
	//----------------------------------------------------
	FAnimationData* ActorAnimationGraph::GetAnimationByName(const FString& Name)
	{
		if (m_mAnimation.Find(Name))
			return m_mAnimation[Name];
		return nullptr;
	}
	//----------------------------------------------------
	FAnimationData* ActorAnimationGraph::GetAnimationById(int Id)
	{
		if (m_mAnimationId.Find(Id))
			return m_mAnimationId[Id];
		return nullptr;
	}
	//----------------------------------------------------
	void ActorAnimationGraph::BindAnimation(FAnimationQueue& Queue)
	{
		m_mAnimation.Empty();
		m_mAnimationId.Empty();

		for (int i = 0; i < Queue.Animations.Num(); ++i)
		{
			FAnimationData* pData = &Queue.Animations[i];
			m_mAnimation.Add(pData->SignName, pData);
			m_mAnimationId.Add(pData->Id, pData);
		}
	}
	//----------------------------------------------------
	float ActorAnimationGraph::PlayAnimation(const FString& Name)
	{
		FAnimationData* pData = GetAnimationByName(Name);
		float fDuration = PlayAnimation(pData);

		return fDuration;
	}
	//----------------------------------------------------
	float ActorAnimationGraph::PlayAnimation(int Id)
	{
		FAnimationData* pData = GetAnimationById(Id);
		float	fDuration = PlayAnimation(pData);

		return fDuration;
	}
	//----------------------------------------------------
	void ActorAnimationGraph::AddEvent(const FString& Name, float fTriggerTime, const TArray<FString>& Param)
	{
		if (Param.Num() <= 0)
			return;

		if (fTriggerTime <= 0.f)
		{
			TriggerEvent(Name, Param);
			return;
		}

		sTriggerParam param;
		param._fTime = 0.f;
		param._fDurtion = fTriggerTime;
		param._Name = Name;
		param._vParam = Param;

		m_mTriggerEvent.Add(m_mTriggerEvent.Num(), param);
	}
	//----------------------------------------------------
	void ActorAnimationGraph::TriggerEvent(const FString& Name, const TArray<FString>& vParam)
	{
		if (vParam.Num() <= 0 || Name.IsEmpty())
			return;

		// 		if (Name.Equals("SoundLocation"))
		// 		{
		// 			USoundCue* SoundBattle = (USoundCue*)UGameBlueprintFunctionLibrary::LoadObjectFromPath(*vParam[0]);
		// 			if (SoundBattle)
		// 				UGameplayStatics::PlaySoundAtLocation(m_pActorMe, SoundBattle, m_pActorMe->GetActorLocation());
		// 		}
		// 		else if (Name.Equals("SoundAttach"))
		// 		{
		// 			USoundCue* SoundBattle = (USoundCue*)UGameBlueprintFunctionLibrary::LoadObjectFromPath(*vParam[0]);
		// 			if (SoundBattle)
		// 			{
		// 				UGameplayStatics::SpawnSoundAttached(SoundBattle, m_pActorMe->GetRootComponent());
		// 			}
		// 		}
		// 		else if (Name.Equals("Sound2D"))
		// 		{
		// 			USoundCue* SoundBattle = (USoundCue*)UGameBlueprintFunctionLibrary::LoadObjectFromPath(*vParam[0]);
		// 			if (SoundBattle)
		// 			{
		// 				UGameplayStatics::SpawnSound2D(m_pActorMe, SoundBattle);
		// 			}
		// 		}
	}
	//----------------------------------------------------
	float ActorAnimationGraph::PlayAnimation(const FAnimationData* pData)
	{
		if (!pData)
			return 0.f;

		float fDuration = 0.f;

		if (m_pSkeletalMeshComponent && m_pSkeletalMeshComponent->AnimScriptInstance)
		{
			if (pData->Anim)
			{
				UAnimMontage* pCur = m_pSkeletalMeshComponent->AnimScriptInstance->GetCurrentActiveMontage();
				fDuration = m_pSkeletalMeshComponent->AnimScriptInstance->Montage_Play(pData->Anim);
			}
			else if (pData->AnimAsset)
			{
				fDuration = pData->AnimAsset->GetPlayLength();
				m_pSkeletalMeshComponent->PlayAnimation(pData->AnimAsset, pData->nLoop == 0);
			}
			else
				return 0.f;
		}

		for (int i = 0; i < (int)EAvatarType::eNum; ++i)
		{
			if (m_vAvatarMesh[i] && m_vAvatarMesh[i]->AnimScriptInstance)
			{
				if (pData->Anim)
				{
					UAnimMontage* pCur = m_vAvatarMesh[i]->AnimScriptInstance->GetCurrentActiveMontage();
					fDuration = FMath::Max(m_vAvatarMesh[i]->AnimScriptInstance->Montage_Play(pData->Anim), fDuration);
				}
				else if (pData->AnimAsset)
				{
					fDuration = FMath::Max(pData->AnimAsset->GetPlayLength(), fDuration);
					m_vAvatarMesh[i]->PlayAnimation(pData->AnimAsset, pData->nLoop == 0);
				}
			}
		}


		for (int i = 0; i < pData->TriggerEventParam.Num(); ++i)
		{
			AddEvent(pData->TriggerEventParam[i].Name, pData->TriggerEventParam[i].TriggerTime, pData->TriggerEventParam[i].Param);
		}

		return fDuration;
	}
	//----------------------------------------------------
	float ActorAnimationGraph::PlayAnimation(class UAnimationAsset* AnimAsset, bool bLoop)
	{
		if (!AnimAsset)
			return 0.f;

		FAnimationData data;
		data.AnimAsset = AnimAsset;
		data.nLoop = bLoop ? 0 : 1;

		return PlayAnimation(&data);
	}
	//----------------------------------------------------
	float ActorAnimationGraph::PlayAnimation(class UAnimMontage* AnimMontage, float InPlayRate, FName StartSectionName)
	{
		if (!AnimMontage)
			return 0.f;

		float fDuration = 0.f;

		if (m_pSkeletalMeshComponent && m_pSkeletalMeshComponent->AnimScriptInstance)
		{
			fDuration = m_pSkeletalMeshComponent->AnimScriptInstance->Montage_Play(AnimMontage, InPlayRate);

			if (StartSectionName != NAME_None)
			{
				fDuration = AnimMontage->GetSectionLength(AnimMontage->GetSectionIndex(StartSectionName));
				m_pSkeletalMeshComponent->AnimScriptInstance->Montage_JumpToSection(StartSectionName, AnimMontage);
			}
		}

		for (int i = 0; i < (int)EAvatarType::eNum; ++i)
		{
			if (m_vAvatarMesh[i] && m_vAvatarMesh[i]->AnimScriptInstance)
			{
				fDuration = m_vAvatarMesh[i]->AnimScriptInstance->Montage_Play(AnimMontage, InPlayRate);
				if (StartSectionName != NAME_None)
				{
					fDuration = AnimMontage->GetSectionLength(AnimMontage->GetSectionIndex(StartSectionName));
					m_vAvatarMesh[i]->AnimScriptInstance->Montage_JumpToSection(StartSectionName, AnimMontage);
				}
			}
		}

		return fDuration;
	}
	//----------------------------------------------------
	void ActorAnimationGraph::StopAnimMontage(class UAnimMontage* AnimMontage)
	{
		if (!AnimMontage)
			return;

		if (m_pSkeletalMeshComponent && m_pSkeletalMeshComponent->AnimScriptInstance)
		{
			if (m_pSkeletalMeshComponent->AnimScriptInstance->Montage_IsPlaying(AnimMontage))
			{
				m_pSkeletalMeshComponent->AnimScriptInstance->Montage_Stop(AnimMontage->BlendOut.GetBlendTime());
			}
		}

		for (int i = 0; i < (int)EAvatarType::eNum; ++i)
		{
			if (m_vAvatarMesh[i] && m_vAvatarMesh[i]->AnimScriptInstance)
			{
				if (m_vAvatarMesh[i]->AnimScriptInstance->Montage_IsPlaying(AnimMontage))
				{
					m_vAvatarMesh[i]->AnimScriptInstance->Montage_Stop(AnimMontage->BlendOut.GetBlendTime());
				}
			}
		}
	}
	//----------------------------------------------------
	void ActorAnimationGraph::StopAllAnimMontages()
	{
		if (m_pSkeletalMeshComponent && m_pSkeletalMeshComponent->AnimScriptInstance)
		{
			m_pSkeletalMeshComponent->AnimScriptInstance->Montage_Stop(0.0f);
		}

		for (int i = 0; i < (int)EAvatarType::eNum; ++i)
		{
			if (m_vAvatarMesh[i] && m_vAvatarMesh[i]->AnimScriptInstance)
			{
				m_vAvatarMesh[i]->AnimScriptInstance->Montage_Stop(0.0f);
			}
		}
	}
}
