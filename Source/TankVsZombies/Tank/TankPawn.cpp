// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPawn.h"
#include "EnhancedInputComponent.h"
#include "TankController.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ATankPawn::ATankPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ATankPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATankPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ATankPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	if (const ATankController* Controller = Cast<ATankController>(GetController()))
	{
		Input->BindAction(Controller->MoveForwardAction, ETriggerEvent::Ongoing, this, &ATankPawn::Move);
	}
}

void ATankPawn::Move(const FInputActionInstance& Instance)
{
	if (Instance.GetValue().Get<bool>())
	{
		const float Scalar = UGameplayStatics::GetWorldDeltaSeconds(this) * Speed;
		AddActorLocalOffset(FVector::ForwardVector * Scalar, true);
	}
}

