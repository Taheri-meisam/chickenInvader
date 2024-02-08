// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Spaceship.h"
#include "MainWidget.generated.h"

/**
 * 
 */
UCLASS()
class CHICKENINVADER_API UMainWidget : public UUserWidget
{
	GENERATED_BODY()
public:
    virtual void NativeConstruct() override;

protected:
    // Override the NativeTick function
    virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

protected:
    UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
    UButton* ChangeColorButton;

    UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
    UTextBlock* ColorLabel;

    UFUNCTION()
    void OnButtonClicked();

    void ChangeLabelColor();

    FLinearColor GetRandomColor() const;
public:
    UPROPERTY()
    ASpaceship* mySpaceShip;
    UPROPERTY()
    float retval= 1110;


public:
    UFUNCTION(BlueprintCallable)
    void InitializeWithPlayerCharacter();
	
};
