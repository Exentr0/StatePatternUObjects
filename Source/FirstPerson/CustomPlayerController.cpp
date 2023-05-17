#include "CustomPlayerController.h"
#include "Components/InputComponent.h"

void ACustomPlayerController::JumpPressed()
{
    if (JumpDelegate.IsBound())
    {
        JumpDelegate.Broadcast();
    }
}

void ACustomPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();
   
}

FJumpSignature* ACustomPlayerController::GetJumpDelegate()
{
    return &JumpDelegate;
}
