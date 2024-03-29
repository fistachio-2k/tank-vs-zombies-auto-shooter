﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ZombieCharacter.generated.h"

class AMeleeWeapon;

UCLASS()
class TANKVSZOMBIES_API AZombieCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AZombieCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<AMeleeWeapon> WeaponClass;

	
	UPROPERTY(EditAnywhere)
	FName WeaponSocket = "WeaponSocket_R";

public:
	UPROPERTY()
	AMeleeWeapon* MeleeWeapon;
};
