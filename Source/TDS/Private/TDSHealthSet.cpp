// Fill out your copyright notice in the Description page of Project Settings.


#include "TDSHealthSet.h"
#include "Net/UnrealNetwork.h"
#include "GameplayEffectExtension.h"

UTDSHealthSet::UTDSHealthSet()
	: Health(100.f), MaxHealth(100.f), Shield(0.f), MaxShield(0.f), ShieldRegen(0.f), ShieldRegenDelay(1.f)
{
}

void UTDSHealthSet::ClampAttributeOnChange(const FGameplayAttribute& Attribute, float& NewValue) const
{
	Super::ClampAttributeOnChange(Attribute, NewValue);

	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxHealth());
	}
	else if (Attribute == GetShieldAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxShield());
	}
}

void UTDSHealthSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UTDSHealthSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UTDSHealthSet, MaxHealth, COND_None, REPNOTIFY_Always);
}

void UTDSHealthSet::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UTDSHealthSet, Health, OldHealth);
}

void UTDSHealthSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UTDSHealthSet, MaxHealth, OldMaxHealth);
}

void UTDSHealthSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	if(Data.EvaluatedData.Attribute == GetInDamageAttribute())
	{
		float InDamageDone = GetInDamage();
		SetInDamage(0.f);
		if(InDamageDone > 0.f)
		{
			if(GetShield() > 0.f)
			{
				float NewShield = GetShield();
				const float ShieldDiff = FMath::Min(NewShield, InDamageDone);
				InDamageDone -= ShieldDiff;
				NewShield -= ShieldDiff;
				SetShield(NewShield);
			}

			if(InDamageDone > 0.f)
			{
				float NewHealth = GetHealth();
				const float HealthDiff = FMath::Min(NewHealth, InDamageDone);
				SetHealth(NewHealth - HealthDiff);
			}
		}
	}
}
