// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "Spaceship.generated.h"

UCLASS()
class CHICKENINVADER_API ASpaceship : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASpaceship();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = " Input", meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* inputMapping;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = " Input", meta = (AllowPrivateAccess = "true"))
	class UInputAction* inputMoveForward;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = " Input", meta = (AllowPrivateAccess = "true"))
	class UInputAction* inputMoveRight;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = " Input", meta = (AllowPrivateAccess = "true"))
	class UInputAction* inputShoot;


	//
	void Move(const FInputActionValue& Value);
	float val;

public:
	float returnVal() {
		return val;
	}

};
