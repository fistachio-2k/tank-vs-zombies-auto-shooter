// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPawn.h"
#include "EnhancedInputComponent.h"
#include "TankController.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TankVsZombies/Weapons/BaseWeapon.h"

// Sets default values
ATankPawn::ATankPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsul Collider"));
	SetRootComponent(Capsule);
	
	BodyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body Mesh"));
	BodyMesh->SetupAttachment(Capsule);
}

void ATankPawn::OnReceivePointDamage(AActor* DamagedActor, float Damage, AController* InstigatedBy, FVector HitLocation,
	UPrimitiveComponent* FHitComponent, FName BoneName, FVector ShotFromDirection, const UDamageType* DamageType,
	AActor* DamageCauser)
{
	// UGameplayStatics::PlaySoundAtLocation(GetWorld(),HitCue, HitLocation);
	// UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), BloodEmitter, HitLocation, ShotFromDirection.Rotation());
	// PlayAnimMontage(HitMontage);
	Healthh -= Damage;
	UE_LOG(LogTemp, Warning, TEXT("Received %f damage"), Healthh);
	
	if (Healthh <= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("You are dead!"))
	}
}

// Called when the game starts or when spawned
void ATankPawn::BeginPlay()
{
	Super::BeginPlay();
	PlayerController = Cast<APlayerController>(GetController());

	MainWeapon = GetWorld()->SpawnActor<ABaseWeapon>(MainWeaponClass, BodyMesh->GetSocketLocation(MainWeaponSocket), BodyMesh->GetSocketRotation(MainWeaponSocket));
	MainWeapon->AttachToActor(this, FAttachmentTransformRules::KeepWorldTransform, MainWeaponSocket);

	OnTakePointDamage.AddUniqueDynamic(this, &ATankPawn::OnReceivePointDamage);
}

// Called to bind functionality to input
void ATankPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	if (const ATankController* TankController = Cast<ATankController>(GetController()))
	{
		Input->BindAction(TankController->MoveForwardAction, ETriggerEvent::Triggered, this, &ATankPawn::MoveForward);
		Input->BindAction(TankController->TurnRightAction, ETriggerEvent::Triggered, this, &ATankPawn::TurnRight);
		Input->BindAction(TankController->RotateTurretAction, ETriggerEvent::Triggered, this, &ATankPawn::RotateTurret);
	}
}

void ATankPawn::MoveForward(const FInputActionInstance& Instance)
{
	const float Value = Instance.GetValue().Get<float>();
	if (Value != 0.f)
	{
		const float Scalar = UGameplayStatics::GetWorldDeltaSeconds(this) * MoveSpeed * Value;
		AddActorLocalOffset(FVector::ForwardVector * Scalar, true);
	}
}

void ATankPawn::TurnRight(const FInputActionInstance& Instance)
{
	const float Value = Instance.GetValue().Get<float>();
	if (Value != 0.f)
	{
		FRotator DeltaRotation = FRotator::ZeroRotator;
		DeltaRotation.Yaw = UGameplayStatics::GetWorldDeltaSeconds(this) * TurnSpeed * Value;
		AddActorLocalRotation(DeltaRotation, true);
	}
}

void ATankPawn::RotateTurret(const FInputActionInstance& Instance)
{
	if (PlayerController)
	{
		FHitResult Hit;
		PlayerController->GetHitResultUnderCursor(ECC_Visibility, false, Hit);
		if (Hit.ImpactPoint != FVector::ZeroVector)
		{
			const FVector LookAtTarget = Hit.ImpactPoint;
			const FVector ToTarget = LookAtTarget - MainWeapon->GetActorLocation();
			const FRotator Rotation = FRotator(0, ToTarget.Rotation().Yaw, 0);
			MainWeapon->SetActorRotation(Rotation);
		}
	}
}

