// Fill out your copyright notice in the Description page of Project Settings.


#include "MainWidget.h"
#include "Components/TextBlock.h"
#include "Kismet/KismetMathLibrary.h"


void UMainWidget::NativeConstruct()
{
    Super::NativeConstruct();
    APlayerController* PlayerController = GetOwningPlayer();
      if (PlayerController)
    {
        // Get the pawn (character) possessed by the player controller
        ASpaceship* spaceship = Cast<ASpaceship>(PlayerController->GetPawn());

        if (spaceship)
        {
            // Access public variables of the player character
            retval = spaceship->returnVal();
            // Do something with PlayerHealth...
        }
    }

    if (ChangeColorButton)
    {
        ChangeColorButton->OnClicked.AddDynamic(this, &UMainWidget::OnButtonClicked);
    }
    InitializeWithPlayerCharacter();
    
}

void UMainWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
    APlayerController* PlayerController = GetOwningPlayer();
    if (PlayerController)
    {
        // Get the pawn (character) possessed by the player controller
        ASpaceship* spaceship = Cast<ASpaceship>(PlayerController->GetPawn());

        if (spaceship)
        {
            // Access public variables of the player character
            retval = spaceship->returnVal();
            // Do something with PlayerHealth...
        }
    }
  
    ColorLabel->SetText(FText::AsNumber(retval));
    
}

void UMainWidget::OnButtonClicked()
{
    ChangeLabelColor();
}

void UMainWidget::ChangeLabelColor()
{
    if (ColorLabel)
    {
        ColorLabel->SetColorAndOpacity(GetRandomColor());
    }
}

FLinearColor UMainWidget::GetRandomColor() const
{
    return FLinearColor(FMath::FRand(), FMath::FRand(), FMath::FRand(), 1.0f);
}

void UMainWidget::InitializeWithPlayerCharacter()
{
   
 


}
