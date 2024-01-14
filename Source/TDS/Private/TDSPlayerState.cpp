// Fill out your copyright notice in the Description page of Project Settings.


#include "TDSPlayerState.h"
#include "AbilitySystemComponent.h"
#include "TDSHealthSet.h"
#include "TDSWeaponSet.h"

ATDSPlayerState::ATDSPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);

	HealthSet = CreateDefaultSubobject<UTDSHealthSet>("HealthSet");
	WeaponSet = CreateDefaultSubobject<UTDSWeaponSet>("WeaponSet");
}

UAbilitySystemComponent* ATDSPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
