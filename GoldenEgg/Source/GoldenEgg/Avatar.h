// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "Avatar.generated.h"

UCLASS()
class GOLDENEGG_API AAvatar : public ACharacter
{
	GENERATED_BODY()
	float MouseSensitivity;

public:
	// Sets default values for this character's properties
	AAvatar();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	//Las 4 nuevas funciones
	//Se usan para mover el personaje
	void MoveForward(float amount);
	void MoveRight(float amount);
	void Yaw(float amount);
	void Pitch(float amount);
	void IncreaseMouseSensitivity();
	void ReduceMouseSensitivity();
	
};
