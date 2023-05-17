// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StateManagerComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CUSTOMSTATEMACHINE_API UStateManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UStateManagerComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
public:
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "State Machine")
		FString InitialState;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "State Machine")
		TMap<FString, TSubclassOf<UBaseState>> AvailableStates;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "State Machine Debug")
		bool bDebug = false;

	UPROPERTY(BlueprintReadOnly)
		TArray<UBaseState*> StateHistory;
	UPROPERTY(BlueprintReadOnly)
		int32 StateHistoryLength;
	UPROPERTY(BLueprintReadOnly)
		UBaseState* CurrentState = nullptr;

	UPROPERTY()
		TMap<FString, UBaseState*> StateMap;

	UFUNCTION(BlueprintCallable, Category = "State Machine")
		void SwitchStateByKey(const FString& StateKey);
	UFUNCTION(BlueprintCallable, Category = "State Machine")
		void SwitchState(const UBaseState* NewState);
	UFUNCTION(BlueprintCallable, Category = "State Machine")
		void InitStateManager();

private:
	bool bCanTickState = false;
	void InitializeStates();
};
