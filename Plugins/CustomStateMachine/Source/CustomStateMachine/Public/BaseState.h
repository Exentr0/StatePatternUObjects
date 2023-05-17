// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BaseState.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class CUSTOMSTATEMACHINE_API UBaseState : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	bool bCanTickState = false;
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	bool bCanRepeat = false;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	FName StateDisplayName;

public:
	virtual void OnStateEnter(AActor* StateOwner);
	virtual void StateTick();
	virtual void OnStateExit();
};
