// Fill out your copyright notice in the Description page of Project Settings.


#include "Spaceship.h"
#include "InputMappingContext.h"
#include "InputAction.h"

#include "EnhancedInputSubsystems.h"
#include <EnhancedInputComponent.h>


// Sets default values
ASpaceship::ASpaceship()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpaceship::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Display, TEXT("SubSystem OK"));
	APlayerController* PlayerController = Cast<APlayerController>(Controller);
	if (PlayerController) {
		UE_LOG(LogTemp, Display, TEXT("Player controller OK"));
		UEnhancedInputLocalPlayerSubsystem* subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());
		if (subsystem) {
			subsystem->AddMappingContext(inputMapping, 0);
		}
		UE_LOG(LogTemp, Display, TEXT("SubSystem OK"));

	}
	
}

// Called every frame
void ASpaceship::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASpaceship::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {

		//Bind Move() to the mapping
		//BindAction for enhanced system takes Action, ETriggerEvent, object, and function
		//ETriggerEvent is an enum, where Triggered means "button is held down".
		EnhancedInputComponent->BindAction(inputMoveForward, ETriggerEvent::Triggered, this, &ASpaceship::Move);
	}
	else {
		UE_LOG(LogTemp, Display, TEXT("Cast error line 47"));

	}
}

void ASpaceship::Move(const FInputActionValue& Value)
{
	val = Value.Get<float>();
	UE_LOG(LogTemp, Display, TEXT("Float value: %f"), val);
	
}

