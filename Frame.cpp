// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSProject.h"
#include "Frame.h"

int32 Frame::count = 0;
TMap<FString, Frame::Strata> Frame::StrataMap;
const FString Frame::strataList[5] = {"BACKGROUND", "LOW", "MEDIUM", "HIGH", "OVERLAY"};

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
  
  count++; // Track the total number of frames
}

Frame::~Frame()
{
}

// Get functions /////////////////////////////////////////////////////////////
int32 Frame::GetWidth() const {return w;}
int32 Frame::GetHeight() const {return h;}
int32 Frame::GetSize() const {return w, h;}
int32 Frame::GetX() const {return x;}
int32 Frame::GetY() const {return y;}
int32 Frame::GetPosition() const {return x, y;}
int32 Frame::GetColorInt() const {return r, g, b, a;}
FLinearColor Frame::GetColor() const {return FLinearColor(r, g, b, a);}
int32 Frame::GetAlpha() const {return a;}
int32 Frame::GetScale() const {return scale;}
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
void Frame::SetWidth(int32 nW){w = nW;}
void Frame::SetHeight(int32 nH){h = nH;}
void Frame::SetSize(int32 nW, int32 nH){w = nW; h = nH;}
void Frame::SetX(int32 nX){x = nX;}
void Frame::SetY(int32 nY){y = nY;}
void Frame::SetPosition(int32 nX, int32 nY){x = nX; y = nY;}
void Frame::SetScale(int32 nScale){scale = nScale;}
void Frame::SetName(FString nName){name = nName;}
void Frame::SetType(FString nType){type = nType;}
void Frame::SetShown(bool nVisibility){shown = nVisibility;}
void Frame::SetMouseOver(bool nMouseOver){mouseOver = nMouseOver;}

void Frame::SetColor(int32 nR, int32 nG, int32 nB, int32 nA)
{
  if ((0.f >= nR) && (nR > 1.f)) // It is between 0 and 1
  {
    r = nR;
  }
  else if (0.f >= nR) // To low
  {
    r = 0.f;
  }
  else if (nR >= 1.f) // To high
  {
    r = 1.f;
  }
  
  if ((0.f >= nG) && (nG > 1.f))
  {
    g = nG;
  }
  else if (0.f >= nG)
  {
    g = 0.f;
  }
  else if (nG >= 1.f)
  {
    g = 1.f;
  }
  
  if ((0.f >= nB) && (nB > 1.f))
  {
    b = nB;
  }
  else if (0.f >= nB)
  {
    b = 0.f;
  }
  else if (nB >= 1.f)
  {
    b = 1.f;
  }
  
  if ((0.f >= nA) && (nA > 1.f))
  {
    a = nA;
  }
  else if (0.f >= nA)
  {
    a = 0.f;
  }
  else if (nA >= 1.f)
  {
    a = 1.f;
  }
}

void Frame::SetAlpha(int32 nA)
{
  if ((0.f >= nA) && (nA > 1.f)) // It is between 0 and 1
  {
    a = nA;
  }
  else if (0.f >= nA) // To low
  {
    a = 0.f;
  }
  else if (nA >= 1.f) // To high
  {
    a = 1.f;
  }
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

void Frame::RegisterEvent(EventEnum event)
{
  Frame* f = this;
  switch (event)
  {
    case MOUSE_ENTER:
      print("Registering MOUSE_ENTER", f->GetName());
      MOUSE_ENTER_list.Emplace(f);
      break;
    case MOUSE_EXIT:
      print("Registering MOUSE_EXIT", f->GetName());
      MOUSE_EXIT_list.Emplace(f);
      break;
    case GAME_START:
      GAME_START_list.Emplace(f);
      break;
    case UPDATE:
      UPDATE_list.Emplace(f);
      break;
    case FRAME_CREATED:
      FRAME_CREATED_list.Emplace(f);
      break;
    case WINDOW_FOCUS:
      WINDOW_FOCUS_list.Emplace(f);
      break;
    case KEY_DOWN:
      KEY_DOWN_list.Emplace(f);
      break;
    case KEY_UP:
      KEY_UP_list.Emplace(f);
      break;
    case GAME_QUIT:
      GAME_QUIT_list.Emplace(f);
      break;
    case MOUSE_CLICKED_DOWN:
      MOUSE_CLICKED_DOWN_list.Emplace(f);
      break;
    case MOUSE_CLICKED_UP:
      MOUSE_CLICKED_UP_list.Emplace(f);
      break;
    case MOUSE_MOVEMENT:
      MOUSE_MOVEMENT_list.Emplace(f);
      break;
    default:
      print("No event: ", event);
      break;
  }
}

void Frame::OnEvent(void (*func)(Frame*, EventEnum))
{
  OnEventFunc = func;
}

void Frame::Fire(EventEnum event)
{
  // This function is called from various places all around the code
  // It is given an event from an enum list
  // It figures out which TArray of registered frames belongs with that event
  // Then loops through each registered frame, calling its OnEventFunc function
  
  switch (event)
  {
    case MOUSE_ENTER:
      if (MOUSE_ENTER_list.Num() > 0)
        for (int i = MOUSE_ENTER_list.Num() - 1; i >= 0; --i)
          // Make sure that this is the actual frame that's moused over
          // Otherwise it will react to any frame registered
          if (true == MOUSE_ENTER_list[i]->GetMouseOver())
            {MOUSE_ENTER_list[i]->OnEventFunc(MOUSE_ENTER_list[i], event);}
      break;
    case MOUSE_EXIT:
      if (MOUSE_EXIT_list.Num() > 0)
        for (int i = MOUSE_EXIT_list.Num() - 1; i >= 0; --i)
          // True because the event is fired BEFORE it's changed to false
          // Otherwise it will react to the wrong frames
          if (true == MOUSE_ENTER_list[i]->GetMouseOver())
            {MOUSE_EXIT_list[i]->OnEventFunc(MOUSE_ENTER_list[i], event);}
      break;
    case GAME_START:
      if (GAME_START_list.Num() > 0)
        for (int i = GAME_START_list.Num() - 1; i >= 0; --i)
            {GAME_START_list[i]->OnEventFunc(MOUSE_ENTER_list[i], event);}
      break;
    case UPDATE:
      if (UPDATE_list.Num() > 0)
        for (int i = UPDATE_list.Num() - 1; i >= 0; --i)
            {UPDATE_list[i]->OnEventFunc(MOUSE_ENTER_list[i], event);}
      break;
    case FRAME_CREATED:
      if (FRAME_CREATED_list.Num() > 0)
        for (int i = FRAME_CREATED_list.Num() - 1; i >= 0; --i)
            {FRAME_CREATED_list[i]->OnEventFunc(MOUSE_ENTER_list[i], event);}
      break;
    case WINDOW_FOCUS:
      if (WINDOW_FOCUS_list.Num() > 0)
        for (int i = WINDOW_FOCUS_list.Num() - 1; i >= 0; --i)
            {WINDOW_FOCUS_list[i]->OnEventFunc(MOUSE_ENTER_list[i], event);}
      break;
    case KEY_DOWN:
      if (KEY_DOWN_list.Num() > 0)
        for (int i = KEY_DOWN_list.Num() - 1; i >= 0; --i)
            {KEY_DOWN_list[i]->OnEventFunc(MOUSE_ENTER_list[i], event);}
      break;
    case KEY_UP:
      if (KEY_UP_list.Num() > 0)
        for (int i = KEY_UP_list.Num() - 1; i >= 0; --i)
            {KEY_UP_list[i]->OnEventFunc(MOUSE_ENTER_list[i], event);}
      break;
    case GAME_QUIT:
      if (GAME_QUIT_list.Num() > 0)
        for (int i = GAME_QUIT_list.Num() - 1; i >= 0; --i)
            {GAME_QUIT_list[i]->OnEventFunc(MOUSE_ENTER_list[i], event);}
      break;
    case MOUSE_CLICKED_DOWN:
      if (MOUSE_CLICKED_DOWN_list.Num() > 0)
        for (int i = MOUSE_CLICKED_DOWN_list.Num() - 1; i >= 0; --i)
            {MOUSE_CLICKED_DOWN_list[i]->OnEventFunc(MOUSE_ENTER_list[i], event);}
      break;
    case MOUSE_CLICKED_UP:
      if (MOUSE_CLICKED_UP_list.Num() > 0)
        for (int i = MOUSE_CLICKED_UP_list.Num() - 1; i >= 0; --i)
            {MOUSE_CLICKED_UP_list[i]->OnEventFunc(MOUSE_ENTER_list[i], event);}
      break;
    case MOUSE_MOVEMENT:
      if (MOUSE_MOVEMENT_list.Num() > 0)
        for (int i = MOUSE_MOVEMENT_list.Num() - 1; i >= 0; --i)
            {MOUSE_MOVEMENT_list[i]->OnEventFunc(MOUSE_ENTER_list[i], event);}
      break;
    default:
      print("No event: ", event);
      break;
  }
}

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

Frame* Frame::CreateFrame(FString nName = "NAME", FString nStrata = "BACKGROUND", int32 nLevel = 0)
{
  Frame* f = new Frame();
  
  // delete f; // TODO: Move f to the right place.
  
  f->SetName(nName);
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
