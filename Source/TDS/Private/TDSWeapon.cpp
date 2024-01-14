// Fill out your copyright notice in the Description page of Project Settings.


#include "TDSWeapon.h"

// Sets default values
ATDSWeapon::ATDSWeapon()
	: Damage(5.f), FireRate(2.f), IsAuto(false)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATDSWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATDSWeapon::Equip()
{
	OnEquip();
}

void ATDSWeapon::UnEquip()
{
	OnUnEquip();
}
