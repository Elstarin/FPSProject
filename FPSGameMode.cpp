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
	: Super(ObjectInitializer){
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnObject(TEXT("Pawn'/Game/Blueprints/BP_FPSCharacter.BP_FPSCharacter_C'"));
	
  if (PlayerPawnObject.Class != NULL){
    DefaultPawnClass = PlayerPawnObject.Class;
  }
  
	// Base decay rate
	DecayRate = 1.f;
	
  HUDClass = AFPSHUD::StaticClass();
};

// AFPSGameMode::AFPSGameMode(const class FPostConstructInitializeProperties& PCIP)
// 	: Super(PCIP){
// 	// You can obtain the asset path of your HUD blueprint through the editor
// 	// by right-clicking the Blueprint asset and choosing "Copy Reference".
// 	// You should then add the "_C" suffix so that the class finder properly
// 	// points to the actual class used by the game, as opposed to its Blueprint
// 	// which is an editor-only concept).
// 	//
// 	// For instance, given a blueprint named BP_JoyHUD, the class path would be
// 	//	"/Game/Blueprints/BP_JoyHUD_C"
// 	static ConstructorHelpers::FClassFinder<AHUD> TheHUDOb(TEXT("/Game/Blueprints/BP_AFPSHUD_C"));
// 	if (TheHUDOb.Class != NULL)
// 	{
// 		HUDClass = TheHUDOb.Class;
// 	}
// };

void AFPSGameMode::StartPlay(){
  Super::StartPlay();

  StartMatch();
	
  
	// print(World->GetRealTimeSeconds());
	
	// FDateTime timeObj;
	
	// auto time = FDateTime::Now().GetTimeOfDay().GetTicks();
	// auto time = FDateTime::Now().GetTimeOfDay().GetTotalMilliseconds();
	
	// print(TimerSystem::GetTime());
	// print(timeObj.GetTicks());
	
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

void AFPSGameMode::HandleNewState(EFPSProjectPlayState NewState){
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
