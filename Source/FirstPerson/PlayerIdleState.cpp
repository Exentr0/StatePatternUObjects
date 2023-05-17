// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerIdleState.h"
#include "GameFramework/CharacterMovementComponent.h"

void UPlayerIdleState::PressJump()
{
	Super::PressJump();

	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, "JUMP!");

	PlayerRef->Jump();
}

void UPlayerIdleState::StateTick()
{
	Super::StateTick();

	if (!PlayerRef->GetCharacterMovement()->IsMovingOnGround()) 
	{
		PlayerRef->StateManager->SwitchStateByKey("Air");
	}
}
