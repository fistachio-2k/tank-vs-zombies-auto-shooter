// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputAction.h"
#include "GameFramework/Pawn.h"
#include "TankPawn.generated.h"

class UCapsuleComponent;
class UCameraComponent;
class USpringArmComponent;

UCLASS()
class TANKVSZOMBIES_API ATankPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATankPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void MoveForward(const FInputActionInstance& Instance);
	void TurnRight(const FInputActionInstance& Instance);
	void RotateTurret(const FInputActionInstance& Instance);

	UPROPERTY()
	APlayerController* PlayerController;
	
	UPROPERTY(EditAnywhere, Category="Locomotion")
	float MoveSpeed = 200;
	
	UPROPERTY(EditAnywhere, Category="Locomotion")
	float TurnSpeed = 100;

	UPROPERTY(VisibleAnywhere)
	UCapsuleComponent* Capsule;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* BodyMesh;
	
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* TurretMesh;
};
