// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSProject.h"
#include "Frame.h"

int32 Frame::count = 0;
TMap<FString, Frame::Strata> Frame::StrataMap;
const FString Frame::strataList[5] = {"BACKGROUND", "LOW", "MEDIUM", "HIGH", "OVERLAY"};

TArray<Frame*> Frame::FrameList;
TArray<Frame*> Frame::Level::FrameList;
TArray<Frame::Scripts> Frame::OnUpdateList;
TMap<int32, Frame::Level> Frame::Strata::LevelMap;

TArray<Frame*> Frame::MOUSE_ENTER_list;
TArray<Frame*> Frame::MOUSE_EXIT_list;
TArray<Frame*> Frame::GAME_START_list;
TArray<Frame*> Frame::GAME_QUIT_list;
TArray<Frame*> Frame::FRAME_CREATED_list;
TArray<Frame*> Frame::MOUSE_CLICKED_DOWN_list;
TArray<Frame*> Frame::MOUSE_CLICKED_UP_list;
TArray<Frame*> Frame::MOUSE_MOVEMENT_list;
TArray<Frame*> Frame::KEY_DOWN_list;
TArray<Frame*> Frame::KEY_UP_list;
TArray<Frame*> Frame::UPDATE_list;
TArray<Frame*> Frame::WINDOW_FOCUS_list;

Frame::Frame()
{
  w = 0.f;
  h = 0.f;
  x = 0.f;
  y = 0.f;
  r = 0.f;
  g = 0.f;
  b = 0.f;
  a = 0.f;
  shown = true;
  mouseOver = false;
  scale = 1.f;
  level = 0.f;
  strata = "BACKGROUND";
  name = "Frame_" + FString::FromInt(count);
  // Frame* parent;
  
  // TMap<EventEnum, FuncType> EventMap;
  // EventMap.Emplace(EventEnum::UPDATE, UPDATE);
  
  count++; // Track the total number of frames
}

Frame::~Frame()
{
}

// Event setting functions /////////////////////////////////////////////////////
void Frame::Set_MOUSE_ENTER(FuncType func)
{
  if (EventMap.Contains(EventEnum::MOUSE_ENTER))
    EventMap[EventEnum::MOUSE_ENTER] = func;
  else
    EventMap.Emplace(EventEnum::MOUSE_ENTER, func);
}

void Frame::Set_MOUSE_EXIT(FuncType func)
{
  if (EventMap.Contains(EventEnum::MOUSE_EXIT))
    EventMap[EventEnum::MOUSE_EXIT] = func;
  else
    EventMap.Emplace(EventEnum::MOUSE_EXIT, func);
}

void Frame::Set_MOUSE_CLICKED_DOWN(FuncType func)
{
  if (EventMap.Contains(EventEnum::MOUSE_CLICKED_DOWN))
    EventMap[EventEnum::MOUSE_CLICKED_DOWN] = func;
  else
    EventMap.Emplace(EventEnum::MOUSE_CLICKED_DOWN, func);
}

void Frame::Set_MOUSE_CLICKED_UP(FuncType func)
{
  if (EventMap.Contains(EventEnum::MOUSE_CLICKED_UP))
    EventMap[EventEnum::MOUSE_CLICKED_UP] = func;
  else
    EventMap.Emplace(EventEnum::MOUSE_CLICKED_UP, func);
}

void Frame::Set_UPDATE(FuncType func)
{
  if (EventMap.Contains(EventEnum::UPDATE))
    EventMap[EventEnum::UPDATE] = func;
  else
    EventMap.Emplace(EventEnum::UPDATE, func);
}

void Frame::Set_FRAME_CREATED(FuncType func)
{
  if (EventMap.Contains(EventEnum::FRAME_CREATED))
    EventMap[EventEnum::FRAME_CREATED] = func;
  else
    EventMap.Emplace(EventEnum::FRAME_CREATED, func);
}

void Frame::Set_WINDOW_FOCUS_GAINED(FuncType func)
{
  if (EventMap.Contains(EventEnum::WINDOW_FOCUS_GAINED))
    EventMap[EventEnum::WINDOW_FOCUS_GAINED] = func;
  else
    EventMap.Emplace(EventEnum::WINDOW_FOCUS_GAINED, func);
}

void Frame::Set_WINDOW_FOCUS_LOST(FuncType func)
{
  if (EventMap.Contains(EventEnum::WINDOW_FOCUS_LOST))
    EventMap[EventEnum::WINDOW_FOCUS_LOST] = func;
  else
    EventMap.Emplace(EventEnum::WINDOW_FOCUS_LOST, func);
}

void Frame::Set_KEY_DOWN(FuncType func)
{
  if (EventMap.Contains(EventEnum::KEY_DOWN))
    EventMap[EventEnum::KEY_DOWN] = func;
  else
    EventMap.Emplace(EventEnum::KEY_DOWN, func);
}

void Frame::Set_KEY_UP(FuncType func)
{
  if (EventMap.Contains(EventEnum::KEY_UP))
    EventMap[EventEnum::KEY_UP] = func;
  else
    EventMap.Emplace(EventEnum::KEY_UP, func);
}

void Frame::Set_GAME_START(FuncType func)
{
  if (EventMap.Contains(EventEnum::GAME_START))
    EventMap[EventEnum::GAME_START] = func;
  else
    EventMap.Emplace(EventEnum::GAME_START, func);
}

void Frame::Set_GAME_PAUSE(FuncType func)
{
  if (EventMap.Contains(EventEnum::GAME_PAUSE))
    EventMap[EventEnum::GAME_PAUSE] = func;
  else
    EventMap.Emplace(EventEnum::GAME_PAUSE, func);
}

void Frame::Set_GAME_STOP(FuncType func)
{
  if (EventMap.Contains(EventEnum::GAME_STOP))
    EventMap[EventEnum::GAME_STOP] = func;
  else
    EventMap.Emplace(EventEnum::GAME_STOP, func);
}

// void Frame::Set_MOUSE_MOVEMENT(FuncType func)
// {
//   if (EventMap.Contains(EventEnum::MOUSE_MOVEMENT))
//     EventMap[EventEnum::MOUSE_MOVEMENT = func;
//   else
//     EventMap.Emplace(EventEnum::MOUSE_MOVEMENT, func);
// }

void Frame::Set_MOUSE_X_DOWN(FuncType func)
{
  if (EventMap.Contains(EventEnum::MOUSE_X_DOWN))
    EventMap[EventEnum::MOUSE_X_DOWN] = func;
  else
    EventMap.Emplace(EventEnum::MOUSE_X_DOWN, func);
}

void Frame::Set_MOUSE_X_UP(FuncType func)
{
  if (EventMap.Contains(EventEnum::MOUSE_X_UP))
    EventMap[EventEnum::MOUSE_X_UP] = func;
  else
    EventMap.Emplace(EventEnum::MOUSE_X_UP, func);
}

void Frame::Set_MOUSE_Y_DOWN(FuncType func)
{
  if (EventMap.Contains(EventEnum::MOUSE_Y_DOWN))
    EventMap[EventEnum::MOUSE_Y_DOWN] = func;
  else
    EventMap.Emplace(EventEnum::MOUSE_Y_DOWN, func);
}

void Frame::Set_MOUSE_Y_UP(FuncType func)
{
  if (EventMap.Contains(EventEnum::MOUSE_Y_UP))
    EventMap[EventEnum::MOUSE_Y_UP] = func;
  else
    EventMap.Emplace(EventEnum::MOUSE_Y_UP, func);
}

void Frame::Set_MOUSE_SCROLL_DOWN(FuncType func)
{
  if (EventMap.Contains(EventEnum::MOUSE_SCROLL_DOWN))
    EventMap[EventEnum::MOUSE_SCROLL_DOWN] = func;
  else
    EventMap.Emplace(EventEnum::MOUSE_SCROLL_DOWN, func);
}

void Frame::Set_MOUSE_SCROLL_UP(FuncType func)
{
  if (EventMap.Contains(EventEnum::MOUSE_SCROLL_UP))
    EventMap[EventEnum::MOUSE_SCROLL_UP] = func;
  else
    EventMap.Emplace(EventEnum::MOUSE_SCROLL_UP, func);
}

void Frame::Set_MOUSE_AXIS_DOWN(FuncType func)
{
  if (EventMap.Contains(EventEnum::MOUSE_AXIS_DOWN))
    EventMap[EventEnum::MOUSE_AXIS_DOWN] = func;
  else
    EventMap.Emplace(EventEnum::MOUSE_AXIS_DOWN, func);
}

void Frame::Set_MOUSE_AXIS_UP(FuncType func)
{
  if (EventMap.Contains(EventEnum::MOUSE_AXIS_UP))
    EventMap[EventEnum::MOUSE_AXIS_UP] = func;
  else
    EventMap.Emplace(EventEnum::MOUSE_AXIS_UP, func);
}

// Get functions /////////////////////////////////////////////////////////////
float Frame::GetWidth() const {return w;}
float Frame::GetHeight() const {return h;}
float Frame::GetSize() const {return w, h;}
float Frame::GetX() const {return x;}
float Frame::GetY() const {return y;}
float Frame::GetPosition() const {return x, y;}
float Frame::GetColorInt() const {return r, g, b, a;}
FLinearColor Frame::GetColor() const {return FLinearColor(r, g, b, a);}
float Frame::GetAlpha() const {return a;}
float Frame::GetScale() const {return scale;}
int32 Frame::GetLevel() const {return level;}
bool Frame::IsShown() const {return shown;}
bool Frame::GetMouseOver() const {return mouseOver;}
FString Frame::GetType() const {return type;}
FString Frame::GetStrata() const {return strata;}
FString Frame::GetName() const {return name;}
Frame* Frame::GetParent() const {return parent;}
// Frame& Frame::GetPtr(){return *f;}
// END get functions ///////////////////////////////////////////////////////////

// Set functions ///////////////////////////////////////////////////////////////
void Frame::SetWidth(float nW){w = nW;}
void Frame::SetHeight(float nH){h = nH;}
void Frame::SetSize(float nW, float nH){w = nW; h = nH;}
void Frame::SetX(float nX){x = nX;}
void Frame::SetY(float nY){y = nY;}
void Frame::SetPosition(float nX, float nY){x = nX; y = nY;}
void Frame::SetScale(float nScale){scale = nScale;}
void Frame::SetName(FString nName){name = nName;}
void Frame::SetType(FString nType){type = nType;}
void Frame::SetShown(bool nVisibility){shown = nVisibility;}
void Frame::SetMouseOver(bool nMouseOver){mouseOver = nMouseOver;}

void Frame::SetColor(float nR, float nG, float nB, float nA)
{
  // All of these default to 1.f if they are not supplied.
  
  if ((nR >= 0.f) && (1.f >= nR)) r = nR; // It is between 0 and 1
  else if (0.f > nR) r = 0.f; // Less than 0, set it to 0
  else if (nR > 1.f) r = 1.f; // More than 1, set it to 1
  
  if ((nG >= 0.f) && (1.f >= nG)) g = nG;
  else if (0.f > nG) g = 0.f;
  else if (nG > 1.f) g = 1.f;
  
  if ((nB >= 0.f) && (1.f >= nB)) b = nB;
  else if (0.f > nB) b = 0.f;
  else if (nB > 1.f) b = 1.f;
  
  if ((nA >= 0.f) && (1.f >= nA)) a = nA;
  else if (0.f > nA) a = 0.f;
  else if (nA > 1.f) a = 1.f;
}

void Frame::SetAlpha(float nA)
{
  // Defaults to 1.f if not supplied
  
  if ((nA >= 0.f) && (1.f >= nA)) a = nA; // It is between 0 and 1
  else if (0.f > nA) a = 0.f; // Less than 0, set it to 0
  else if (nA > 1.f) a = 1.f; // More than 1, set it to 1
}

void Frame::SetLevel(int32 nLevel)
{
  if ((nLevel >= -10.f) && (nLevel <= 10.f))
  {
    level = nLevel;
  }
  else
  {
    print("Invalid level:", nLevel);
  }
}

void Frame::SetStrata(FString nStrata)
{
  // Make sure it's a valid strata
  if (
      (nStrata == "BACKGROUND") ||
      (nStrata == "LOW") ||
      (nStrata == "MEDIUM") ||
      (nStrata == "HIGH") ||
      (nStrata == "OVERLAY")
    )
  {
    strata = nStrata;
  }
  else // Not valid
  {
    print("Invalid strata: ", nStrata);
  }
}

void Frame::SetParent()
{
}

void Frame::SetScript(ScriptTypes script, void (*func)())
{
  switch (script)
  {
    case OnUpdate:
      OnUpdateList.Emplace(func);
      break;
    default:
      break;
  }
}
// END Set functions ///////////////////////////////////////////////////////////

// void Frame::RegisterEvent(EventEnum event)
// {
//   Frame* f = this;
//   switch (event)
//   {
//   case EventEnum::MOUSE_ENTER:
//       MOUSE_ENTER_list.Emplace(f);
//       break;
//     case EventEnum::MOUSE_EXIT:
//       MOUSE_EXIT_list.Emplace(f);
//       break;
//     case EventEnum::GAME_START:
//       GAME_START_list.Emplace(f);
//       break;
//     case EventEnum::UPDATE:
//       UPDATE_list.Emplace(f);
//       break;
//     case EventEnum::FRAME_CREATED:
//       FRAME_CREATED_list.Emplace(f);
//       break;
//     case EventEnum::WINDOW_FOCUS:
//       WINDOW_FOCUS_list.Emplace(f);
//       break;
//     case EventEnum::KEY_DOWN:
//       KEY_DOWN_list.Emplace(f);
//       break;
//     case EventEnum::KEY_UP:
//       KEY_UP_list.Emplace(f);
//       break;
//     case EventEnum::GAME_QUIT:
//       GAME_QUIT_list.Emplace(f);
//       break;
//     case EventEnum::MOUSE_CLICKED_DOWN:
//       MOUSE_CLICKED_DOWN_list.Emplace(f);
//       break;
//     case EventEnum::MOUSE_CLICKED_UP:
//       MOUSE_CLICKED_UP_list.Emplace(f);
//       break;
//     case EventEnum::MOUSE_MOVEMENT:
//       MOUSE_MOVEMENT_list.Emplace(f);
//       break;
//     default:
//       print("No event: ", event);
//       break;
//   }
// }

void Frame::OnEvent(void (*func)(Frame*, EventEnum))
{
  OnEventFunc = func;
}

// bool bEventList[] = {
//   MOUSE_ENTER,
//   MOUSE_EXIT,
//   GAME_START,
//   GAME_LOAD,
//   LOAD_FILE,
//   DRAWING,
//   UPDATE,
//   FRAME_CREATED,
//   MOUSE_DOWN,
//   WINDOW_FOCUS,
//   WINDOW_VISIBLE,
//   KEY_DOWN,
//   KEY_UP,
//   GAME_QUIT,
//   SCORE_UPDATE,
//   MOUSE_CLICKED_DOWN,
//   MOUSE_CLICKED_UP,
//   ZEPPLIN_FALLING,
//   MOUSE_MOVEMENT,
//
//   // Key events
//   KEY_DOWN_MouseX,
//   KEY_UP_MouseX,
//   KEY_DOWN_MouseY,
//   KEY_UP_MouseY,
//   KEY_DOWN_MouseScrollUp,
//   KEY_UP_MouseScrollUp,
//   KEY_DOWN_MouseScrollDown,
//   KEY_UP_MouseScrollDown,
//   KEY_DOWN_MouseWheelAxis,
//   KEY_UP_MouseWheelAxis,
//
//   KEY_DOWN_LeftMouseButton,
//   KEY_UP_LeftMouseButton,
//   KEY_DOWN_RightMouseButton,
//   KEY_UP_RightMouseButton,
//   KEY_DOWN_MiddleMouseButton,
//   KEY_UP_MiddleMouseButton,
//   KEY_DOWN_ThumbMouseButton,
//   KEY_UP_ThumbMouseButton,
//   KEY_DOWN_ThumbMouseButton2,
//   KEY_UP_ThumbMouseButton2,
//
//   KEY_DOWN_BackSpace,
//   KEY_UP_BackSpace,
//   KEY_DOWN_Tab,
//   KEY_UP_Tab,
//   KEY_DOWN_Enter,
//   KEY_UP_Enter,
//   KEY_DOWN_Pause,
//   KEY_UP_Pause,
//
//   KEY_DOWN_CapsLock,
//   KEY_UP_CapsLock,
//   KEY_DOWN_Escape,
//   KEY_UP_Escape,
//   KEY_DOWN_SpaceBar,
//   KEY_UP_SpaceBar,
//   KEY_DOWN_PageUp,
//   KEY_UP_PageUp,
//   KEY_DOWN_PageDown,
//   KEY_UP_PageDown,
//   KEY_DOWN_End,
//   KEY_UP_End,
//   KEY_DOWN_Home,
//   KEY_UP_Home,
//
//   KEY_DOWN_Left,
//   KEY_UP_Left,
//   KEY_DOWN_Up,
//   KEY_UP_Up,
//   KEY_DOWN_Right,
//   KEY_UP_Right,
//   KEY_DOWN_Down,
//   KEY_UP_Down,
//
//   KEY_DOWN_Insert,
//   KEY_UP_Insert,
//   KEY_DOWN_Delete,
//   KEY_UP_Delete,
//
//   KEY_DOWN_Zero,
//   KEY_UP_Zero,
//   KEY_DOWN_One,
//   KEY_UP_One,
//   KEY_DOWN_Two,
//   KEY_UP_Two,
//   KEY_DOWN_Three,
//   KEY_UP_Three,
//   KEY_DOWN_Four,
//   KEY_UP_Four,
//   KEY_DOWN_Five,
//   KEY_UP_Five,
//   KEY_DOWN_Six,
//   KEY_UP_Six,
//   KEY_DOWN_Seven,
//   KEY_UP_Seven,
//   KEY_DOWN_Eight,
//   KEY_UP_Eight,
//   KEY_DOWN_Nine,
//   KEY_UP_Nine,
//
//   KEY_DOWN_A,
//   KEY_UP_A,
//   KEY_DOWN_B,
//   KEY_UP_B,
//   KEY_DOWN_C,
//   KEY_UP_C,
//   KEY_DOWN_D,
//   KEY_UP_D,
//   KEY_DOWN_E,
//   KEY_UP_E,
//   KEY_DOWN_F,
//   KEY_UP_F,
//   KEY_DOWN_G,
//   KEY_UP_G,
//   KEY_DOWN_H,
//   KEY_UP_H,
//   KEY_DOWN_I,
//   KEY_UP_I,
//   KEY_DOWN_J,
//   KEY_UP_J,
//   KEY_DOWN_K,
//   KEY_UP_K,
//   KEY_DOWN_L,
//   KEY_UP_L,
//   KEY_DOWN_M,
//   KEY_UP_M,
//   KEY_DOWN_N,
//   KEY_UP_N,
//   KEY_DOWN_O,
//   KEY_UP_O,
//   KEY_DOWN_P,
//   KEY_UP_P,
//   KEY_DOWN_Q,
//   KEY_UP_Q,
//   KEY_DOWN_R,
//   KEY_UP_R,
//   KEY_DOWN_S,
//   KEY_UP_S,
//   KEY_DOWN_T,
//   KEY_UP_T,
//   KEY_DOWN_U,
//   KEY_UP_U,
//   KEY_DOWN_V,
//   KEY_UP_V,
//   KEY_DOWN_W,
//   KEY_UP_W,
//   KEY_DOWN_X,
//   KEY_UP_X,
//   KEY_DOWN_Y,
//   KEY_UP_Y,
//   KEY_DOWN_Z,
//   KEY_UP_Z,
// };

void Frame::Fire(EventEnum event)
{
  for (int32 i = 0; i < FrameList.Num(); i++)
    for (auto& element : FrameList[i]->EventMap)
      if ((element.Key == event) && (element.Value))
        element.Value();
  
  
  // switch (event)
  // {
  //   case EventEnum::MOUSE_ENTER:
  //     for (int32 i = 0; i < FrameList.Num(); i++)
  //       if (FrameList[i]->MOUSE_ENTER) FrameList[i]->MOUSE_ENTER();
  //     break;
  //   case EventEnum::MOUSE_EXIT:
  //     for (int32 i = 0; i < FrameList.Num(); i++)
  //       if (FrameList[i]->MOUSE_EXIT) FrameList[i]->MOUSE_EXIT();
  //     break;
  //   case EventEnum::UPDATE:
  //     for (int32 i = 0; i < FrameList.Num(); i++)
  //       if (FrameList[i]->UPDATE) FrameList[i]->UPDATE();
  //     break;
  //   case EventEnum::FRAME_CREATED:
  //     for (int32 i = 0; i < FrameList.Num(); i++)
  //       if (FrameList[i]->FRAME_CREATED) FrameList[i]->FRAME_CREATED();
  //     break;
  //   case EventEnum::WINDOW_FOCUS_GAINED:
  //     for (int32 i = 0; i < FrameList.Num(); i++)
  //       if (FrameList[i]->WINDOW_FOCUS_GAINED) FrameList[i]->WINDOW_FOCUS_GAINED();
  //     break;
  //   case EventEnum::WINDOW_FOCUS_LOST:
  //     for (int32 i = 0; i < FrameList.Num(); i++)
  //       if (FrameList[i]->WINDOW_FOCUS_LOST) FrameList[i]->WINDOW_FOCUS_LOST();
  //     break;
  //   case EventEnum::KEY_DOWN:
  //     for (int32 i = 0; i < FrameList.Num(); i++)
  //       if (FrameList[i]->KEY_DOWN) FrameList[i]->KEY_DOWN();
  //     break;
  //   case EventEnum::KEY_UP:
  //     for (int32 i = 0; i < FrameList.Num(); i++)
  //       if (FrameList[i]->KEY_UP) FrameList[i]->KEY_UP();
  //     break;
  //   case EventEnum::GAME_START:
  //     for (int32 i = 0; i < FrameList.Num(); i++)
  //       if (FrameList[i]->GAME_START) FrameList[i]->GAME_START();
  //     break;
  //   case EventEnum::GAME_PAUSE:
  //     for (int32 i = 0; i < FrameList.Num(); i++)
  //       if (FrameList[i]->GAME_PAUSE) FrameList[i]->GAME_PAUSE();
  //     break;
  //   case EventEnum::GAME_STOP:
  //     for (int32 i = 0; i < FrameList.Num(); i++)
  //       if (FrameList[i]->GAME_STOP) FrameList[i]->GAME_STOP();
  //     break;
  //   case EventEnum::MOUSE_CLICKED_DOWN:
  //     for (int32 i = 0; i < FrameList.Num(); i++)
  //       if (FrameList[i]->MOUSE_CLICKED_DOWN) FrameList[i]->MOUSE_CLICKED_DOWN();
  //     break;
  //   case EventEnum::MOUSE_CLICKED_UP:
  //     for (int32 i = 0; i < FrameList.Num(); i++)
  //       if (FrameList[i]->MOUSE_CLICKED_UP) FrameList[i]->MOUSE_CLICKED_UP();
  //     break;
  //   case EventEnum::MOUSE_MOVEMENT:
  //     for (int32 i = 0; i < FrameList.Num(); i++)
  //       if (FrameList[i]->MOUSE_MOVEMENT) FrameList[i]->MOUSE_MOVEMENT();
  //     break;
  //   default:
  //     break;
  // }
}

// void Frame::Fire(EventEnum event)
// {
//   // This function is called from various places all around the code
//   // It is given an event from an enum list
//   // It figures out which TArray of registered frames belongs with that event
//   // Then loops through each registered frame, calling its OnEventFunc function
//
//   // TArray<EventEnum> eventArray;
//   //
//   // for (int32 i = 0; i < ARRAY_COUNT(bEventList); i++)
//   // {
//   //   bEventList[i] = false;
//   // }
//
//   switch (event)
//   {
//     case EventEnum::MOUSE_ENTER:
//       if (MOUSE_ENTER_list.Num() > 0)
//         for (int32 i = MOUSE_ENTER_list.Num() - 1; i >= 0; --i)
//           // Make sure that this is the actual frame that's moused over
//           // Otherwise it will react to any frame registered
//           if (true == MOUSE_ENTER_list[i]->GetMouseOver())
//             {MOUSE_ENTER_list[i]->OnEventFunc(MOUSE_ENTER_list[i], event);}
//       break;
//     case EventEnum::MOUSE_EXIT:
//       if (MOUSE_EXIT_list.Num() > 0)
//         for (int32 i = MOUSE_EXIT_list.Num() - 1; i >= 0; --i)
//           // True because the event is fired BEFORE it's changed to false
//           // Otherwise it will react to the wrong frames
//           if (true == MOUSE_ENTER_list[i]->GetMouseOver())
//             {MOUSE_EXIT_list[i]->OnEventFunc(MOUSE_ENTER_list[i], event);}
//       break;
//     case EventEnum::GAME_START:
//       if (GAME_START_list.Num() > 0)
//         for (int32 i = GAME_START_list.Num() - 1; i >= 0; --i)
//             {GAME_START_list[i]->OnEventFunc(MOUSE_ENTER_list[i], event);}
//       break;
//     case EventEnum::UPDATE:
//       if (UPDATE_list.Num() > 0)
//         for (int32 i = UPDATE_list.Num() - 1; i >= 0; --i)
//             {UPDATE_list[i]->OnEventFunc(MOUSE_ENTER_list[i], event);}
//       break;
//     case EventEnum::FRAME_CREATED:
//       if (FRAME_CREATED_list.Num() > 0)
//         for (int32 i = FRAME_CREATED_list.Num() - 1; i >= 0; --i)
//             {FRAME_CREATED_list[i]->OnEventFunc(MOUSE_ENTER_list[i], event);}
//       break;
//     case EventEnum::WINDOW_FOCUS:
//       if (WINDOW_FOCUS_list.Num() > 0)
//         for (int32 i = WINDOW_FOCUS_list.Num() - 1; i >= 0; --i)
//             {WINDOW_FOCUS_list[i]->OnEventFunc(MOUSE_ENTER_list[i], event);}
//       break;
//     case EventEnum::KEY_DOWN:
//       if (KEY_DOWN_list.Num() > 0)
//         for (int32 i = KEY_DOWN_list.Num() - 1; i >= 0; --i)
//             {KEY_DOWN_list[i]->OnEventFunc(MOUSE_ENTER_list[i], event);}
//       break;
//     case EventEnum::KEY_UP:
//       if (KEY_UP_list.Num() > 0)
//         for (int32 i = KEY_UP_list.Num() - 1; i >= 0; --i)
//             {KEY_UP_list[i]->OnEventFunc(MOUSE_ENTER_list[i], event);}
//       break;
//     case EventEnum::GAME_QUIT:
//       if (GAME_QUIT_list.Num() > 0)
//         for (int32 i = GAME_QUIT_list.Num() - 1; i >= 0; --i)
//             {GAME_QUIT_list[i]->OnEventFunc(MOUSE_ENTER_list[i], event);}
//       break;
//     case EventEnum::MOUSE_CLICKED_DOWN:
//       if (MOUSE_CLICKED_DOWN_list.Num() > 0)
//         for (int32 i = MOUSE_CLICKED_DOWN_list.Num() - 1; i >= 0; --i)
//             {MOUSE_CLICKED_DOWN_list[i]->OnEventFunc(MOUSE_ENTER_list[i], event);}
//       break;
//     case EventEnum::MOUSE_CLICKED_UP:
//       if (MOUSE_CLICKED_UP_list.Num() > 0)
//         for (int32 i = MOUSE_CLICKED_UP_list.Num() - 1; i >= 0; --i)
//             {MOUSE_CLICKED_UP_list[i]->OnEventFunc(MOUSE_ENTER_list[i], event);}
//       break;
//     case EventEnum::MOUSE_MOVEMENT:
//       if (MOUSE_MOVEMENT_list.Num() > 0)
//         for (int32 i = MOUSE_MOVEMENT_list.Num() - 1; i >= 0; --i)
//             {MOUSE_MOVEMENT_list[i]->OnEventFunc(MOUSE_ENTER_list[i], event);}
//       break;
//     default:
//       print("No event: ", event);
//       break;
//   }
// }

void Frame::IterateScriptArrays()
{
  for (int32 i = OnUpdateList.Num() - 1; i >= 0; --i)
  {
    OnUpdateList[i]();
  }
}

void Frame::InitializeEventList()
{
  EventList.Empty();

  EventList.Emplace("FIRING");
  EventList.Emplace("MOUSE_ENTER");
  EventList.Emplace("MOUSE_EXIT");
  EventList.Emplace("MOUSE_MOVEMENT");
  EventList.Emplace("MOUSE_CLICK_DOWN");
  EventList.Emplace("MOUSE_CLICK_UP");
  EventList.Emplace("GAME_QUIT");
}

Frame* Frame::CreateFrame(FString nName = "", FString nStrata = "BACKGROUND", int32 nLevel = 0)
{
  Frame* f = new Frame();
  FrameList.Emplace(f);
  
  // delete f; // TODO: Move this to the right place.
  
  // If there wasn't a name passed, give it a default name
  if (nName == "") f->SetName("Frame_" + FString::FromInt(count));
  else f->SetName(nName);
  
  f->strata = nStrata;
  f->level = nLevel;

  if (!StrataMap.Contains(f->strata)) // Hasn't been added before
  {
    Strata strataObj;
    StrataMap.Emplace(f->strata, strataObj); // Add the new strata to the list
  }

  if (!StrataMap[f->strata].LevelMap.Contains(f->level)) // Hasn't been added before
  {
    Level levelObj;
    StrataMap[f->strata].LevelMap.Emplace(f->level, levelObj); // Add the new level to the list
    // StrataMap[strata].LevelMap[level].Sort(); // Sort them
  }

  StrataMap[f->strata].LevelMap[f->level].FrameList.Emplace(f); // Store it

  return f;
}

TArray<Frame*> Frame::DOWN_MouseX_list;
TArray<Frame*> Frame::UP_MouseX_list;
TArray<Frame*> Frame::DOWN_MouseY_list;
TArray<Frame*> Frame::UP_MouseY_list;
TArray<Frame*> Frame::DOWN_MouseScrollUp_list;
TArray<Frame*> Frame::UP_MouseScrollUp_list;
TArray<Frame*> Frame::DOWN_MouseScrollDown_list;
TArray<Frame*> Frame::UP_MouseScrollDown_list;
TArray<Frame*> Frame::DOWN_MouseWheelAxis_list;
TArray<Frame*> Frame::UP_MouseWheelAxis_list;

TArray<Frame*> Frame::DOWN_LeftMouseButton_list;
TArray<Frame*> Frame::UP_LeftMouseButton_list;
TArray<Frame*> Frame::DOWN_RightMouseButton_list;
TArray<Frame*> Frame::UP_RightMouseButton_list;
TArray<Frame*> Frame::DOWN_MiddleMouseButton_list;
TArray<Frame*> Frame::UP_MiddleMouseButton_list;
TArray<Frame*> Frame::DOWN_ThumbMouseButton_list;
TArray<Frame*> Frame::UP_ThumbMouseButton_list;
TArray<Frame*> Frame::DOWN_ThumbMouseButton2_list;
TArray<Frame*> Frame::UP_ThumbMouseButton2_list;

TArray<Frame*> Frame::DOWN_BackSpace_list;
TArray<Frame*> Frame::UP_BackSpace_list;
TArray<Frame*> Frame::DOWN_Tab_list;
TArray<Frame*> Frame::UP_Tab_list;
TArray<Frame*> Frame::DOWN_Enter_list;
TArray<Frame*> Frame::UP_Enter_list;
TArray<Frame*> Frame::DOWN_Pause_list;
TArray<Frame*> Frame::UP_Pause_list;

TArray<Frame*> Frame::DOWN_CapsLock_list;
TArray<Frame*> Frame::UP_CapsLock_list;
TArray<Frame*> Frame::DOWN_Escape_list;
TArray<Frame*> Frame::UP_Escape_list;
TArray<Frame*> Frame::DOWN_SpaceBar_list;
TArray<Frame*> Frame::UP_SpaceBar_list;
TArray<Frame*> Frame::DOWN_PageUp_list;
TArray<Frame*> Frame::UP_PageUp_list;
TArray<Frame*> Frame::DOWN_PageDown_list;
TArray<Frame*> Frame::UP_PageDown_list;
TArray<Frame*> Frame::DOWN_End_list;
TArray<Frame*> Frame::UP_End_list;
TArray<Frame*> Frame::DOWN_Home_list;
TArray<Frame*> Frame::UP_Home_list;

TArray<Frame*> Frame::DOWN_Left_list;
TArray<Frame*> Frame::UP_Left_list;
TArray<Frame*> Frame::DOWN_Up_list;
TArray<Frame*> Frame::UP_Up_list;
TArray<Frame*> Frame::DOWN_Right_list;
TArray<Frame*> Frame::UP_Right_list;
TArray<Frame*> Frame::DOWN_Down_list;
TArray<Frame*> Frame::UP_Down_list;

TArray<Frame*> Frame::DOWN_Insert_list;
TArray<Frame*> Frame::UP_Insert_list;
TArray<Frame*> Frame::DOWN_Delete_list;
TArray<Frame*> Frame::UP_Delete_list;

TArray<Frame*> Frame::DOWN_Zero_list;
TArray<Frame*> Frame::UP_Zero_list;
TArray<Frame*> Frame::DOWN_One_list;
TArray<Frame*> Frame::UP_One_list;
TArray<Frame*> Frame::DOWN_Two_list;
TArray<Frame*> Frame::UP_Two_list;
TArray<Frame*> Frame::DOWN_Three_list;
TArray<Frame*> Frame::UP_Three_list;
TArray<Frame*> Frame::DOWN_Four_list;
TArray<Frame*> Frame::UP_Four_list;
TArray<Frame*> Frame::DOWN_Five_list;
TArray<Frame*> Frame::UP_Five_list;
TArray<Frame*> Frame::DOWN_Six_list;
TArray<Frame*> Frame::UP_Six_list;
TArray<Frame*> Frame::DOWN_Seven_list;
TArray<Frame*> Frame::UP_Seven_list;
TArray<Frame*> Frame::DOWN_Eight_list;
TArray<Frame*> Frame::UP_Eight_list;
TArray<Frame*> Frame::DOWN_Nine_list;
TArray<Frame*> Frame::UP_Nine_list;

TArray<Frame*> Frame::DOWN_A_list;
TArray<Frame*> Frame::UP_A_list;
TArray<Frame*> Frame::DOWN_B_list;
TArray<Frame*> Frame::UP_B_list;
TArray<Frame*> Frame::DOWN_C_list;
TArray<Frame*> Frame::UP_C_list;
TArray<Frame*> Frame::DOWN_D_list;
TArray<Frame*> Frame::UP_D_list;
TArray<Frame*> Frame::DOWN_E_list;
TArray<Frame*> Frame::UP_E_list;
TArray<Frame*> Frame::DOWN_F_list;
TArray<Frame*> Frame::UP_F_list;
TArray<Frame*> Frame::DOWN_G_list;
TArray<Frame*> Frame::UP_G_list;
TArray<Frame*> Frame::DOWN_H_list;
TArray<Frame*> Frame::UP_H_list;
TArray<Frame*> Frame::DOWN_I_list;
TArray<Frame*> Frame::UP_I_list;
TArray<Frame*> Frame::DOWN_J_list;
TArray<Frame*> Frame::UP_J_list;
TArray<Frame*> Frame::DOWN_K_list;
TArray<Frame*> Frame::UP_K_list;
TArray<Frame*> Frame::DOWN_L_list;
TArray<Frame*> Frame::UP_L_list;
TArray<Frame*> Frame::DOWN_M_list;
TArray<Frame*> Frame::UP_M_list;
TArray<Frame*> Frame::DOWN_N_list;
TArray<Frame*> Frame::UP_N_list;
TArray<Frame*> Frame::DOWN_O_list;
TArray<Frame*> Frame::UP_O_list;
TArray<Frame*> Frame::DOWN_P_list;
TArray<Frame*> Frame::UP_P_list;
TArray<Frame*> Frame::DOWN_Q_list;
TArray<Frame*> Frame::UP_Q_list;
TArray<Frame*> Frame::DOWN_R_list;
TArray<Frame*> Frame::UP_R_list;
TArray<Frame*> Frame::DOWN_S_list;
TArray<Frame*> Frame::UP_S_list;
TArray<Frame*> Frame::DOWN_T_list;
TArray<Frame*> Frame::UP_T_list;
TArray<Frame*> Frame::DOWN_U_list;
TArray<Frame*> Frame::UP_U_list;
TArray<Frame*> Frame::DOWN_V_list;
TArray<Frame*> Frame::UP_V_list;
TArray<Frame*> Frame::DOWN_W_list;
TArray<Frame*> Frame::UP_W_list;
TArray<Frame*> Frame::DOWN_X_list;
TArray<Frame*> Frame::UP_X_list;
TArray<Frame*> Frame::DOWN_Y_list;
TArray<Frame*> Frame::UP_Y_list;
TArray<Frame*> Frame::DOWN_Z_list;
TArray<Frame*> Frame::UP_Z_list;

TArray<Frame*> Frame::DOWN_NumPadZero_list;
TArray<Frame*> Frame::UP_NumPadZero_list;
TArray<Frame*> Frame::DOWN_NumPadOne_list;
TArray<Frame*> Frame::UP_NumPadOne_list;
TArray<Frame*> Frame::DOWN_NumPadTwo_list;
TArray<Frame*> Frame::UP_NumPadTwo_list;
TArray<Frame*> Frame::DOWN_NumPadThree_list;
TArray<Frame*> Frame::UP_NumPadThree_list;
TArray<Frame*> Frame::DOWN_NumPadFour_list;
TArray<Frame*> Frame::UP_NumPadFour_list;
TArray<Frame*> Frame::DOWN_NumPadFive_list;
TArray<Frame*> Frame::UP_NumPadFive_list;
TArray<Frame*> Frame::DOWN_NumPadSix_list;
TArray<Frame*> Frame::UP_NumPadSix_list;
TArray<Frame*> Frame::DOWN_NumPadSeven_list;
TArray<Frame*> Frame::UP_NumPadSeven_list;
TArray<Frame*> Frame::DOWN_NumPadEight_list;
TArray<Frame*> Frame::UP_NumPadEight_list;
TArray<Frame*> Frame::DOWN_NumPadNine_list;
TArray<Frame*> Frame::UP_NumPadNine_list;

TArray<Frame*> Frame::DOWN_Multiply_list;
TArray<Frame*> Frame::UP_Multiply_list;
TArray<Frame*> Frame::DOWN_Add_list;
TArray<Frame*> Frame::UP_Add_list;
TArray<Frame*> Frame::DOWN_Subtract_list;
TArray<Frame*> Frame::UP_Subtract_list;
TArray<Frame*> Frame::DOWN_Decimal_list;
TArray<Frame*> Frame::UP_Decimal_list;
TArray<Frame*> Frame::DOWN_Divide_list;
TArray<Frame*> Frame::UP_Divide_list;

TArray<Frame*> Frame::DOWN_F1_list;
TArray<Frame*> Frame::UP_F1_list;
TArray<Frame*> Frame::DOWN_F2_list;
TArray<Frame*> Frame::UP_F2_list;
TArray<Frame*> Frame::DOWN_F3_list;
TArray<Frame*> Frame::UP_F3_list;
TArray<Frame*> Frame::DOWN_F4_list;
TArray<Frame*> Frame::UP_F4_list;
TArray<Frame*> Frame::DOWN_F5_list;
TArray<Frame*> Frame::UP_F5_list;
TArray<Frame*> Frame::DOWN_F6_list;
TArray<Frame*> Frame::UP_F6_list;
TArray<Frame*> Frame::DOWN_F7_list;
TArray<Frame*> Frame::UP_F7_list;
TArray<Frame*> Frame::DOWN_F8_list;
TArray<Frame*> Frame::UP_F8_list;
TArray<Frame*> Frame::DOWN_F9_list;
TArray<Frame*> Frame::UP_F9_list;
TArray<Frame*> Frame::DOWN_F10_list;
TArray<Frame*> Frame::UP_F10_list;
TArray<Frame*> Frame::DOWN_F11_list;
TArray<Frame*> Frame::UP_F11_list;
TArray<Frame*> Frame::DOWN_F12_list;
TArray<Frame*> Frame::UP_F12_list;

TArray<Frame*> Frame::DOWN_NumLock_list;
TArray<Frame*> Frame::UP_NumLock_list;

TArray<Frame*> Frame::DOWN_ScrollLock_list;
TArray<Frame*> Frame::UP_ScrollLock_list;

TArray<Frame*> Frame::DOWN_LeftShift_list;
TArray<Frame*> Frame::UP_LeftShift_list;
TArray<Frame*> Frame::DOWN_RightShift_list;
TArray<Frame*> Frame::UP_RightShift_list;
TArray<Frame*> Frame::DOWN_LeftControl_list;
TArray<Frame*> Frame::UP_LeftControl_list;
TArray<Frame*> Frame::DOWN_RightControl_list;
TArray<Frame*> Frame::UP_RightControl_list;
TArray<Frame*> Frame::DOWN_LeftAlt_list;
TArray<Frame*> Frame::UP_LeftAlt_list;
TArray<Frame*> Frame::DOWN_RightAlt_list;
TArray<Frame*> Frame::UP_RightAlt_list;
TArray<Frame*> Frame::DOWN_LeftCommand_list;
TArray<Frame*> Frame::UP_LeftCommand_list;
TArray<Frame*> Frame::DOWN_RightCommand_list;
TArray<Frame*> Frame::UP_RightCommand_list;

// TArray<Frame*> Frame::DOWN_Semicolon_list;
// TArray<Frame*> Frame::UP_Semicolon_list;
// TArray<Frame*> Frame::DOWN_Equals_list;
// TArray<Frame*> Frame::UP_Equals_list;
// TArray<Frame*> Frame::DOWN_Comma_list;
// TArray<Frame*> Frame::UP_Comma_list;
// TArray<Frame*> Frame::DOWN_Underscore_list;
// TArray<Frame*> Frame::UP_Underscore_list;
// TArray<Frame*> Frame::DOWN_Hyphen_list;
// TArray<Frame*> Frame::UP_Hyphen_list;
// TArray<Frame*> Frame::DOWN_Period_list;
// TArray<Frame*> Frame::UP_Period_list;
// TArray<Frame*> Frame::DOWN_Slash_list;
// TArray<Frame*> Frame::UP_Slash_list;
// TArray<Frame*> Frame::DOWN_Tilde_list;
// TArray<Frame*> Frame::UP_Tilde_list;
// TArray<Frame*> Frame::DOWN_LeftBracket_list;
// TArray<Frame*> Frame::UP_LeftBracket_list;
// TArray<Frame*> Frame::DOWN_LeftParantheses_list;
// TArray<Frame*> Frame::UP_LeftParantheses_list;
// TArray<Frame*> Frame::DOWN_Backslash_list;
// TArray<Frame*> Frame::UP_Backslash_list;
// TArray<Frame*> Frame::DOWN_RightBracket_list;
// TArray<Frame*> Frame::UP_RightBracket_list;
// TArray<Frame*> Frame::DOWN_RightParantheses_list;
// TArray<Frame*> Frame::UP_RightParantheses_list;
// TArray<Frame*> Frame::DOWN_Apostrophe_list;
// TArray<Frame*> Frame::UP_Apostrophe_list;
// TArray<Frame*> Frame::DOWN_Quote_list;
// TArray<Frame*> Frame::UP_Quote_list;
//
// TArray<Frame*> Frame::DOWN_Asterix_list;
// TArray<Frame*> Frame::UP_Asterix_list;
// TArray<Frame*> Frame::DOWN_Ampersand_list;
// TArray<Frame*> Frame::UP_Ampersand_list;
// TArray<Frame*> Frame::DOWN_Caret_list;
// TArray<Frame*> Frame::UP_Caret_list;
// TArray<Frame*> Frame::DOWN_Dollar_list;
// TArray<Frame*> Frame::UP_Dollar_list;
// TArray<Frame*> Frame::DOWN_Exclamation_list;
// TArray<Frame*> Frame::UP_Exclamation_list;
// TArray<Frame*> Frame::DOWN_Colon_list;
// TArray<Frame*> Frame::UP_Colon_list;
//
// TArray<Frame*> Frame::DOWN_A_AccentGrave_list;
// TArray<Frame*> Frame::UP_A_AccentGrave_list;
// TArray<Frame*> Frame::DOWN_E_AccentGrave_list;
// TArray<Frame*> Frame::UP_E_AccentGrave_list;
// TArray<Frame*> Frame::DOWN_E_AccentAigu_list;
// TArray<Frame*> Frame::UP_E_AccentAigu_list;
// TArray<Frame*> Frame::DOWN_C_Cedille_list;
// TArray<Frame*> Frame::UP_C_Cedille_list;
// TArray<Frame*> Frame::DOWN_Section_list;
// TArray<Frame*> Frame::UP_Section_list;
