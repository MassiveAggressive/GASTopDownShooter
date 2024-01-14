// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AbilitySystemInterface.h"
#include "TDSPlayerState.generated.h"

UCLASS()
class TDS_API ATDSPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ATDSPlayerState();

	UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Gas", meta = (AllowPrivateAccess = true))
	class UTDSHealthSet* HealthSet;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Gas", meta = (AllowPrivateAccess = true))
	class UTDSWeaponSet* WeaponSet;
protected:
	UPROPERTY()
	class UAbilitySystemComponent* AbilitySystemComponent;
};
