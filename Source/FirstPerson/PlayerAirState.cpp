// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerAirState.h"
#include "GameFramework/CharacterMovementComponent.h"

void UPlayerAirState::PressJump()
{
	Super::PressJump();

	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Blue, "I am in the air");
}

void UPlayerAirState::StateTick()
{
	Super::StateTick();

	if(PlayerRef->GetCharacterMovement()->IsMovingOnGround())
	{
		PlayerRef->StateManager->SwitchStateByKey("Idle");
	}
}
