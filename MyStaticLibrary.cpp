// Fill out your copyright notice in the Description page of Project Settings.

// KEYWORDS: AActor, UPrimitiveComponent, FHitResult, UParticleSystem, UParticleSystemComponent, TSubobjectPtr, NULL, AActor

#include "FPSProject.h"
#include "TimerSystem.h"
#include "FPSHUD.h"

TArray<FString> FStrPrintArray;

UMyStaticLibrary::UMyStaticLibrary()
{
}

UMyStaticLibrary::~UMyStaticLibrary()
{
}
 
// MyStaticLibrary /////////////////////////////////////////////////////////////
 
UMyStaticLibrary::UMyStaticLibrary(const FObjectInitializer& ObjectInitializer): Super(ObjectInitializer){
  // static TArray<FString> globalArray; // Make the array
  // static TArray<FString>* globalArrayPtr = &globalArray;
  // globalArray.SetNum(8);
  
  // globalArray.Emplace(TEXT("STRING"));
  // printStrArrayPtr = &printStrArray; // Create the pointer
  // TArray<FString>* printStrArrayPtr = &printStrArray; // Create the pointer
  // TArray<FString>& strArray = *printStrArrayPtr;
  // strArray.Emplace(TEXT("%d"));
  // strArray.Emplace(TEXT("%d"));
  
  // UE_LOG(Main, Warning, TEXT("StaticLib Pointer: %d"), globalArrayPtr);
  // UE_LOG(Main, Warning, TEXT("StaticLib num: %d"), (*globalArrayPtr).Num());
  // UE_LOG(Main, Warning, TEXT("StaticLib constructor: %d"), printStrArray.Num());
}
 
int32 UMyStaticLibrary::ComplicatedGameDataAnalysis(){
	//Do lots of stuff that requires the entire Game's compiled header source,
	//  involving lots of your custom project-specific classes,
	//    classes that have not been compiled in the .h of this library
	//    since they depend on it.
        return 9000;
}

void timerCallback()
{
  // print("Timer called back!");
}

// void UMyStaticLibrary::profileCode()
void UMyStaticLibrary::profileCode(UWorld* const World)
{
  // int loopNum = 100;
  // int loopNum = 1000; // 1k
  // int loopNum = 10000; // 10k
  // int loopNum = 100000; // 100k
  // int loopNum = 500000; // 500k
  int loopNum = 1000000; // 1m
  // int loopNum = 10000000; // 10m
  // int loopNum = 100000000; // 100m
  
  if (true){ // Toggle this to easily disable profiling
    print("Profiling... Iterations:", loopNum);
    
    enum List
    {
      MOUSE_ENTER,
      MOUSE_EXIT,
      GAME_RUN,
      GAME_LOAD,
      LOAD_FILE,
      DRAWING,
      UPDATE,
      FRAME_CREATED,
      MOUSE_DOWN,
      WINDOW_FOCUS,
      WINDOW_VISIBLE,
      KEY_DOWN,
      KEY_UP,
      GAME_QUIT,
      SCORE_UPDATE,
      MOUSE_CLICKED_DOWN,
      MOUSE_CLICKED_UP,
      MOUSE_UP,
      MOUSE_MOVEMENT,
    };
    
    // TMap<int32, int32> TestMap;
    //
    // for (int i = 1; i <= 19; i++)
    // {
    //   TestMap.Emplace(i, i);
    // }
    
    // APlayerController* PlayerCon = UObject::GetOwningPlayerController();
    // auto PlayerCon = UGameplayStatics::GetPlayerController(World, 0);
    // auto PlayerCon = GetWorld()->GetFirstPlayerController();
    
    // Code to test
    auto start = TimerSystem::GetTime();
    for (int i = 1; i <= loopNum; i++)
    {
      AFPSHUD::CheckAllKeys();
    }
    
    print("Total MS:", (TimerSystem::GetTime() - start) * 1000.f);
  }
}

void UMyStaticLibrary::finishPrint(FString str)
{
  str.Trim();
  str.Shrink();
  FStrPrintArray.Emplace(str);
};

inline FString convert(){
  return "NONE";
}

inline FString convert(FString x){
  return x;
}

inline FString* convert(FString* x){
  return x;
}

inline FString convert(const char* x){
	return x;
}

inline FString convert(std::string x){
  return x.c_str();
}

inline FString convert(bool x){
	if (x){
		return TEXT("true");
	} else {
		return TEXT("false");
	}
}

inline FString convert(int x){
  return FString::FromInt(x);
}

inline FString convert(int8 x){
  return FString::FromInt(x);
}

inline FString convert(int16 x){
  return FString::FromInt(x);
}

inline FString convert(int64 x){
  return FString::FromInt(x);
}

inline FString convert(uint8 x){
  return FString::FromInt(x);
}

inline FString convert(uint16 x){
  return FString::FromInt(x);
}

inline FString convert(uint32 x){
  return FString::FromInt(x);
}

inline FString convert(uint64 x){
  return FString::FromInt(x);
}

inline FString convert(double x){
  return FString::SanitizeFloat(x);
}

inline FString convert(float x){
  return FString::SanitizeFloat(x);
}

inline FString convert(FVector x){
  return x.ToString();
}

inline FString convert(FVector2D x){
  return x.ToString();
}

inline FString convert(FRotator x){
  return x.ToString();
}

inline FString convert(FLinearColor x){
  return x.ToString();
}

inline FString convert(UObject x){
  return x.GetName();
}

inline FString convert(AActor x){
  return x.GetName();
}

inline FString convert(AActor* x)
{
  return x->GetName();
}

inline FString convert(void* x)
{
  return "Pointer: " + FString::Printf(TEXT("%d"), x);
}
