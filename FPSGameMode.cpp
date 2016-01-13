// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSProject.h"
#include "FPSGameMode.h"
#include "FPSHUD.h"
#include "FPSCharacter.h"
#include "Kismet/GameplayStatics.h"
// #include "MyStaticLibrary.h"

double Time = 0; // Extern from MyStaticLibrary.h
double GetTime(){return Time;} // Also from MyStaticLibrary.h

AFPSGameMode::AFPSGameMode(const class FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnObject(TEXT("Pawn'/Game/Blueprints/BP_FPSCharacter.BP_FPSCharacter_C'"));
	// static ConstructorHelpers::FClassFinder<APawn> PlayerPawnObject(TEXT("Blueprint'/Game/MixamoAnimPack/Mixamo_Maria/Mixamo_Maria.Mixamo_Maria_C'"));
	// static ConstructorHelpers::FClassFinder<APawn> PlayerPawnObject(TEXT("Blueprint'/Game/BP_Avatar.BP_Avatar_C'"));
	
  if (PlayerPawnObject.Class != NULL){
    DefaultPawnClass = PlayerPawnObject.Class;
  }
  
	// Base decay rate
	DecayRate = 1.f;
	
  HUDClass = AFPSHUD::StaticClass();
};

void AFPSGameMode::StartPlay(){
  Super::StartPlay();

  StartMatch();
	
	
	
	UWorld* const World = GetWorld();
	UMyStaticLibrary::profileCode(World);
	// UMyStaticLibrary::profileCode();
}

void AFPSGameMode::Tick(float DeltaSeconds){
	Time += DeltaSeconds;
	
	// UE_LOG(Main, Warning, TEXT("%f"), TimerSystem::GetCycles());

	AFPSCharacter* MyCharacter = Cast<AFPSCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
	
	// If still has power
	if (MyCharacter->PowerLevel > 0.05){
		// Decrease power
		MyCharacter->PowerLevel = FMath::FInterpTo(MyCharacter->PowerLevel, 0.f, DeltaSeconds, DecayRate);
	} else {
		SetCurrentState(EFPSProjectPlayState::EGameOver);
	}
}

void AFPSGameMode::SetCurrentState(EFPSProjectPlayState NewState){
	CurrentState = NewState;
	
	HandleNewState(NewState);
}

void AFPSGameMode::HandleNewState(EFPSProjectPlayState NewState)
{
	switch (NewState){
		case EFPSProjectPlayState::EPlaying:
			break;
			
		case EFPSProjectPlayState::EGameOver:
			break;
			
		case EFPSProjectPlayState::EUnknown:
			break;
			
		default:
			break;
	}
}
