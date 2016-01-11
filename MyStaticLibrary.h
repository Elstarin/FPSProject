// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "MyStaticLibrary.generated.h"

//General Log
DECLARE_LOG_CATEGORY_EXTERN(YourLog, Log, All);

// Main log
DEFINE_LOG_CATEGORY_STATIC(Main, Warning, All);

// #define DEBUG
//
// #ifdef DEBUG
//   #define PRINT print
// #else
//   #define PRINT(...) ((void)0) //strip out PRINT instructions from code
// #endif

/**
 *
 */
// class FPSPROJECT_API MyStaticLibrary
// {
// public:
// };

// class Registration
// {
//   public:
//     void callback(void){ callback_(); }
//     void setCallback((*callback)(void));
//     void addToEventSystem(int32 ID, EventSystem &eventSystem);
//   private:
//     void (*callback_)(void);
// };

// class EventSystem
// {
// public:
//     void register(int32 ID, Registration* registration);
//     void unRegister(int32 ID, Registration* registration);
//     void addNotificationToQueue(int32 ID);
//     void addNotificationToSchedule(int32 ID, int32 notificationTime);
//     void processQueuedNotifications(void);
//     void processNextScheduled(void);
//     int32 getCurrentTime(void);
// private:
//     //placeholder types
//     <list> notificationQueue;
//     <binaryheap> notificationSchedule;
// };

extern TArray<FString> FStrPrintArray;
// extern TMap<int32, > TimerMap;
extern double Time;
double GetTime();

// General global functions ////////////////////////////////////////////////////
void GetDisplay();
////////////////////////////////////////////////////////////////////////////////
 
UCLASS()
class FPSPROJECT_API UMyStaticLibrary : public UObject
{
	GENERATED_UCLASS_BODY()
	
	public:
		UMyStaticLibrary();
		~UMyStaticLibrary();
	 
		//FORCEINLNE function
		static FORCEINLINE bool IsValid(AActor* TheActor)
		{
			if(!TheActor) return false;
			if(!TheActor->IsValidLowLevel()) return false;
			return true;
		}
		
		TArray<int32> IntArray;
		TArray<int32>* Pointer = &IntArray;
		const TArray<int32>& Value = *Pointer;
	 
		//cpp function
		static int32 ComplicatedGameDataAnalysis();
		
    // static void profileCode();
		static void profileCode(UWorld* const World);
		
		static void finishPrint(FString str);
};

// Convert to FString overload functions ///////////////////////////////////////
extern inline FString convert();
extern inline FString convert(FString x);
extern inline FString* convert(FString* x);
extern inline FString convert(const char* x);
extern inline FString convert(std::string x);
extern inline FString convert(bool x);
extern inline FString convert(int32 x);
extern inline FString convert(int8 x);
extern inline FString convert(int16 x);
extern inline FString convert(int64 x);
extern inline FString convert(uint8 x);
extern inline FString convert(uint16 x);
extern inline FString convert(uint32 x);
extern inline FString convert(uint64 x);
extern inline FString convert(double x);
extern inline FString convert(float x);
extern inline FString convert(FVector x);
extern inline FString convert(FVector2D x);
extern inline FString convert(FRotator x);
extern inline FString convert(FLinearColor x);
extern inline FString convert(UObject x);
extern inline FString convert(AActor x);
extern inline FString convert(AActor* x);
extern inline FString convert(void* x);
////////////////////////////////////////////////////////////////////////////////

static FString printStr;

template <typename T>
void print(T value){
  printStr += convert(value);
	
	UMyStaticLibrary::finishPrint(printStr);
	
  // GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, *(printStr + "\n"));
	
	// Add the FString to the TArray
	// FStrPrintArray.Emplace(printStr);
	
	// // Add the timer to the TArray
	// printTimerArray.Emplace(15.f);

	// Empty the FString
	printStr.Reset();
}

template <typename T, typename... Args>
void print(T value, Args... args){ // Recursive variadic function
  // static const unsigned short int32 size = sizeof...(Arguments);
  // <Args...>::name()

	// Catch each value and store it up in printStr
  printStr += (convert(value) + FString(" "));

  print(args...);
}

#define print(...) (print(JOYSTR_CUR_CLASS_LINE + ": ", __VA_ARGS__))

template <typename Last>
std::string type_name(){
  return std::string(typeid(Last).name());
}

template <typename First, typename Second, typename ...Rest>
std::string type_name(){
  return type_name<First>() + " " + type_name<Second, Rest...>();
}
