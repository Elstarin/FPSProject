// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "FPSGameMode.generated.h"

// Enum to store the current state of gameplay
enum class EFPSProjectPlayState : uint8{
	EPlaying,
	EGameOver,
	EUnknown
};

UCLASS()
class FPSPROJECT_API AFPSGameMode : public AGameMode{
	GENERATED_BODY()
	
	AFPSGameMode(const FObjectInitializer& ObjectInitializer);

	virtual void StartPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	
	// UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Power)
	float DecayRate;
	
	EFPSProjectPlayState GetCurrentState() const;
	
	void SetCurrentState(EFPSProjectPlayState NewState);
	
private:
	EFPSProjectPlayState CurrentState;
	
	void HandleNewState(EFPSProjectPlayState NewState);
};

FORCEINLINE EFPSProjectPlayState AFPSGameMode::GetCurrentState() const{
	return CurrentState;
}
