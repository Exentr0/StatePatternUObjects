// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerBaseState.h"
#include "CustomPlayerController.h"
#include "Kismet/GameplayStatics.h"

void UPlayerBaseState::PressJump()
{
	
}

void UPlayerBaseState::OnStateEnter(AActor* OwnerRef)
{
	Super::OnStateEnter(OwnerRef);

	if (!PlayerRef)
	{
		PlayerRef = Cast<AFirstPersonCharacter>(OwnerRef);
	}

	if (!PlayerController)
	{
		PlayerController = Cast<ICustomPlayerControllerInterface>(UGameplayStatics::GetPlayerController(this, 0));
	}

	if (PlayerController)
	{
		PlayerController->GetJumpDelegate()->AddUObject(this, &UPlayerBaseState::PressJump);
	}
}

void UPlayerBaseState::OnStateExit()
{
	Super::OnStateExit();
	PlayerController->GetJumpDelegate()->RemoveAll(this);
}
