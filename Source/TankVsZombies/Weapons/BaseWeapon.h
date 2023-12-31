// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseWeapon.generated.h"

UENUM()
enum EFireType
{
	Single,
	Burst,
	Auto
};

UCLASS()
class TANKVSZOMBIES_API ABaseWeapon : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABaseWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	void Fire();
	virtual void FireInternal();

	void CeaseFire();

	virtual void Reload(int AmmoToAdd);

	UPROPERTY(EditAnywhere)
	int Ammo = 0;
	
	UPROPERTY(EditAnywhere)
	float FireRate = 1;

	UPROPERTY(EditAnywhere)
	TEnumAsByte<EFireType> FireType = Single;

	UPROPERTY(EditAnywhere)
	bool bIsInfAmmo = false;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* ProjectileSpawnPoint;

private:
	FTimerHandle FireTimerHandle;
};
