// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseState.h"
#include "CustomPlayerControllerInterface.h"
#include "FirstPersonCharacter.h"
#include "PlayerBaseState.generated.h"

/**
 * 
 */
UCLASS()
class FIRSTPERSON_API UPlayerBaseState : public UBaseState
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly)
	AFirstPersonCharacter* PlayerRef = nullptr;
	ICustomPlayerControllerInterface* PlayerController;

	virtual void OnStateEnter(AActor* OwnerRef) override;
	virtual void OnStateExit() override;

protected:
	virtual void PressJump();
};
