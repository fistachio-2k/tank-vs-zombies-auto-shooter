// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseWeapon.h"
#include "MainCannon.generated.h"

UCLASS()
class TANKVSZOMBIES_API AMainCannon : public ABaseWeapon
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMainCannon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	virtual void FireInternal() override;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class AProjectile> ProjectileClass;
};
