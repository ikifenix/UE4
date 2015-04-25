// Fill out your copyright notice in the Description page of Project Settings.

#include "GoldenEgg.h"
#include "Avatar.h"


// Sets default values
AAvatar::AAvatar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAvatar::BeginPlay()
{
	Super::BeginPlay();
	MouseSensitivity = 100.f;
	
}

// Called every frame
void AAvatar::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void AAvatar::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

	check(InputComponent);
	InputComponent->BindAxis("Forward", this, &AAvatar::MoveForward);
	InputComponent->BindAxis("Strafe", this, &AAvatar::MoveRight);
	InputComponent->BindAxis("Yaw", this, &AAvatar::Yaw);
	InputComponent->BindAxis("Pitch", this, &AAvatar::Pitch);
	InputComponent->BindAction("IncreaseMouseSensitivity", IE_Pressed, this, &AAvatar::IncreaseMouseSensitivity);
	InputComponent->BindAction("ReduceMouseSensitivity", IE_Pressed, this, &AAvatar::ReduceMouseSensitivity);
}

void AAvatar::MoveForward(float amount)
{
	if (Controller && amount)
	{
		FVector fwd = GetActorForwardVector();
		AddMovementInput(fwd, amount);
	}
}

void AAvatar::MoveRight(float amount)
{
	if (Controller && amount)
	{
		FVector right = GetActorRightVector();
		AddMovementInput(right, amount);
	}
}

void AAvatar::Yaw(float amount)
{
	if (Controller && amount)
	{
		AddControllerYawInput(MouseSensitivity * amount * GetWorld()->GetDeltaSeconds());
	}
}

void AAvatar::Pitch(float amount)
{
	if (Controller && amount)
	{
		AddControllerPitchInput(MouseSensitivity * amount * GetWorld()->GetDeltaSeconds());
	}
}


void AAvatar::IncreaseMouseSensitivity()
{
	if (MouseSensitivity < 200.f)
	{
		MouseSensitivity = MouseSensitivity + 10;
	}
}

void AAvatar::ReduceMouseSensitivity()
{
	if (MouseSensitivity > 10.f)
	{
		MouseSensitivity = MouseSensitivity - 10;
	}
}