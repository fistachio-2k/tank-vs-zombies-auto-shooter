// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MeleeWeapon.generated.h"

UCLASS()
class TANKVSZOMBIES_API AMeleeWeapon : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMeleeWeapon();
	// ApplyDamage(actor) -> Call the apply damage function on the actor argument (private)
	// Implement the OnPointDamageApply method on the player.
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void TraceHit();

	void ToggleTrace(bool);

private:
	
	UPROPERTY(EditAnywhere, Category="Initialization")
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, Category="Initialization")
	FName SocketName;

	UPROPERTY(EditAnywhere, Category="Initialization")
	float TraceRadius;

	UPROPERTY(EditAnywhere, Category="Initialization")
	TArray<TEnumAsByte<EObjectTypeQuery>> CollisionObjectType;

	UPROPERTY(EditAnywhere, Category="Initialization")
	float Damage = 10;
	
	UPROPERTY()
	TArray<AActor*> AlreadyHitActors;
	
	UPROPERTY()
	TArray<AActor*> ActorsToIgnore;
};
