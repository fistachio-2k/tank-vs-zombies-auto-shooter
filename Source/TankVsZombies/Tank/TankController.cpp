// Fill out your copyright notice in the Description page of Project Settings.


#include "TankController.h"
#include "EnhancedInputSubsystems.h"

void ATankController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (const ULocalPlayer* LocalPlayer = Cast<ULocalPlayer>(Player))
	{
		if (UEnhancedInputLocalPlayerSubsystem* InputSystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			if (!InputMapping.IsNull())
			{
				InputSystem->AddMappingContext(InputMapping.LoadSynchronous(), 0);
			}
		}
	}
}
