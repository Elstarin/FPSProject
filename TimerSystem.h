// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// #include "TimerSystem.generated.h"

/**
 *
 */
// class FPSPROJECT_API TimerSystem
// {
// public:
// 	TimerSystem();
// 	~TimerSystem();
// };

class FPSPROJECT_API TimerSystem // FPSPROJECT_API
{
  public:
    struct TimerStruct
    {
      double remaining;
			void (*callback)();
    };
    
    struct TickerStruct
    {
      double current;
      double interval;
      void (*callback)();
      void (*callbackArg)(TickerStruct*);
      int32 ticks;
      bool cancelled;
      bool arg;
      
      // Set it to cancelled; it will be removed next iteration
      inline void Cancel(){this->cancelled = true;}
    };
		
		TimerSystem();
		~TimerSystem();
		
		static double GetTime();
		static uint32 GetCycles();
		static int32 GetTodayTime();
		static int64 GetTodayTicks();
    
    static TArray<TimerStruct*> TimerList;
    static TArray<TickerStruct*> TickerList;
    
    static void SetTimer(double time, void (*func)());
    
    static void SetTicker(double time, void (*func)(), int32 numTicks = -1);
    
    // Overload function that will pass the ticker
    static void SetTicker(double time, void (*func)(TickerStruct*), int32 numTicks = -1);
    
    static void IterateTimerArrays();
};
