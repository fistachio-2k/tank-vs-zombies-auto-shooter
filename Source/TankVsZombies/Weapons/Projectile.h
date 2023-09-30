// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class TANKVSZOMBIES_API AProjectile : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* ProjectileMesh;

	UPROPERTY(EditAnywhere)
	UParticleSystem* HitParticle;

	UPROPERTY(VisibleAnywhere)
	UParticleSystemComponent* TrailParticle;
	
	UPROPERTY(VisibleAnywhere)
	class UProjectileMovementComponent* MovementComponent;

	UPROPERTY(EditAnywhere)
	USoundBase* HitSound;
	
	UPROPERTY(EditAnywhere)
	USoundBase* LaunchSound;
	
	UPROPERTY(EditAnywhere)
	float Damage = 50.f;

};
