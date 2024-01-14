// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TDSBaseSet.h"
#include "AbilitySystemComponent.h"
#include "TDSWeaponSet.generated.h"

UCLASS()
class TDS_API UTDSWeaponSet : public UTDSBaseSet
{
	GENERATED_BODY()

public:
	UTDSWeaponSet();
	
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", meta = (AllowPrivateAccess = "true"))
	FGameplayAttributeData Damage;
	ATTRIBUTE_ACCESSORS(UTDSWeaponSet, Damage);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", meta = (AllowPrivateAccess = "true"))
	FGameplayAttributeData FireRate;
	ATTRIBUTE_ACCESSORS(UTDSWeaponSet, FireRate);
};
