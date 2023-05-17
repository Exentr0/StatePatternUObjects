// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerBaseState.h"
#include "PlayerAirState.generated.h"

/**
 * 
 */
UCLASS()
class FIRSTPERSON_API UPlayerAirState : public UPlayerBaseState
{
	GENERATED_BODY()
	
protected:
	virtual void PressJump() override;
	virtual void StateTick() override;
};
