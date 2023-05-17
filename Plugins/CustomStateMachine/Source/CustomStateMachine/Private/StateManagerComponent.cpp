// Fill out your copyright notice in the Description page of Project Settings.


#include "StateManagerComponent.h"

// Sets default values for this component's properties
UStateManagerComponent::UStateManagerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UStateManagerComponent::BeginPlay()
{
	Super::BeginPlay();

	InitializeStates();
}


// Called every frame
void UStateManagerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (bCanTickState)
	{
		CurrentState->StateTick();
	}
	if (bDebug)
	{
		if (CurrentState)
		{
			GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Green, CurrentState->StateDisplayName.ToString());
		}
		if (StateHistory.Num() > 0)
		{
			for (int32 i = 0; i < StateHistory.Num(); i++)
			{
				GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::Purple, FString::FromInt(i) + ' ' + StateHistory[i]->GetName());
			}
		}
	}
}

void UStateManagerComponent::SwitchStateByKey(const FString& StateKey)
{
	UBaseState* newState = StateMap.FindRef(StateKey);

	if (newState->IsValidLowLevel())
	{
		if (!CurrentState)
		{
			CurrentState = newState;
		}
		else
		{
			if (CurrentState->GetClass() == newState->GetClass() && !CurrentState->bCanRepeat)
			{
				if (bDebug)
				{
					GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, "State switch failed");
				}
			}
			else
			{
				bCanTickState = false;

				CurrentState->OnStateExit();  

				if (StateHistory.Num() < StateHistoryLength)
				{
					StateHistory.Push(CurrentState);
				}
				else
				{
					StateHistory.Push(CurrentState);
					StateHistory.RemoveAt(0);
				}
			}

			CurrentState = newState;
		}

		if (CurrentState)
		{
			CurrentState->OnStateEnter(GetOwner());
			bCanTickState = true;
		}
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, "State is invalid");
	}
}

void UStateManagerComponent::SwitchState(const UBaseState* NewState)
{
}

void UStateManagerComponent::InitStateManager()
{
	SwitchStateByKey(InitialState);
}

void UStateManagerComponent::InitializeStates()
{
	for (auto It = AvailableStates.CreateConstIterator(); It; ++It) {
		UBaseState* State = NewObject<UBaseState>(this, It->Value);
		StateMap.Add(It->Key, State);
	}
}

