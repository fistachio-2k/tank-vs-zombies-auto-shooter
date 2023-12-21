// Fill out your copyright notice in the Description page of Project Settings.


#include "ZombieAnimInstance.h"

#include "Kismet/KismetMathLibrary.h"

float UZombieAnimInstance::GetSpeed()
{
	if (const APawn* Zombie = TryGetPawnOwner())
	{
		Speed = Zombie->GetVelocity().Length();
	}

	return Speed;
}

float UZombieAnimInstance::GetAngle()
{
	if (const APawn* Zombie = TryGetPawnOwner())
	{
		// Calc the velocity vector relative the actor rotation
		const FVector VelocityRelativeDirection = Zombie->GetActorTransform().InverseTransformVector(Zombie->GetVelocity());
		// Find the Yaw rotation angle
		Angle = UKismetMathLibrary::MakeRotFromX(VelocityRelativeDirection).Yaw;
	}

	return Angle;
}
