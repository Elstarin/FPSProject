// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

enum EventEnum
{
	MOUSE_ENTER,
	MOUSE_EXIT,
	GAME_START,
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
	ZEPPLIN_FALLING,
	MOUSE_MOVEMENT,
	
	// Key events
	KEY_DOWN_MouseX,
	KEY_UP_MouseX,
	KEY_DOWN_MouseY,
	KEY_UP_MouseY,
	KEY_DOWN_MouseScrollUp,
	KEY_UP_MouseScrollUp,
	KEY_DOWN_MouseScrollDown,
	KEY_UP_MouseScrollDown,
	KEY_DOWN_MouseWheelAxis,
	KEY_UP_MouseWheelAxis,
	
	KEY_DOWN_LeftMouseButton,
	KEY_UP_LeftMouseButton,
	KEY_DOWN_RightMouseButton,
	KEY_UP_RightMouseButton,
	KEY_DOWN_MiddleMouseButton,
	KEY_UP_MiddleMouseButton,
	KEY_DOWN_ThumbMouseButton,
	KEY_UP_ThumbMouseButton,
	KEY_DOWN_ThumbMouseButton2,
	KEY_UP_ThumbMouseButton2,
	
	KEY_DOWN_BackSpace,
	KEY_UP_BackSpace,
	KEY_DOWN_Tab,
	KEY_UP_Tab,
	KEY_DOWN_Enter,
	KEY_UP_Enter,
	KEY_DOWN_Pause,
	KEY_UP_Pause,
	
	KEY_DOWN_CapsLock,
	KEY_UP_CapsLock,
	KEY_DOWN_Escape,
	KEY_UP_Escape,
	KEY_DOWN_SpaceBar,
	KEY_UP_SpaceBar,
	KEY_DOWN_PageUp,
	KEY_UP_PageUp,
	KEY_DOWN_PageDown,
	KEY_UP_PageDown,
	KEY_DOWN_End,
	KEY_UP_End,
	KEY_DOWN_Home,
	KEY_UP_Home,
	
	KEY_DOWN_Left,
	KEY_UP_Left,
	KEY_DOWN_Up,
	KEY_UP_Up,
	KEY_DOWN_Right,
	KEY_UP_Right,
	KEY_DOWN_Down,
	KEY_UP_Down,
	
	KEY_DOWN_Insert,
	KEY_UP_Insert,
	KEY_DOWN_Delete,
	KEY_UP_Delete,
	
	KEY_DOWN_Zero,
	KEY_UP_Zero,
	KEY_DOWN_One,
	KEY_UP_One,
	KEY_DOWN_Two,
	KEY_UP_Two,
	KEY_DOWN_Three,
	KEY_UP_Three,
	KEY_DOWN_Four,
	KEY_UP_Four,
	KEY_DOWN_Five,
	KEY_UP_Five,
	KEY_DOWN_Six,
	KEY_UP_Six,
	KEY_DOWN_Seven,
	KEY_UP_Seven,
	KEY_DOWN_Eight,
	KEY_UP_Eight,
	KEY_DOWN_Nine,
	KEY_UP_Nine,
	
	KEY_DOWN_A,
	KEY_UP_A,
	KEY_DOWN_B,
	KEY_UP_B,
	KEY_DOWN_C,
	KEY_UP_C,
	KEY_DOWN_D,
	KEY_UP_D,
	KEY_DOWN_E,
	KEY_UP_E,
	KEY_DOWN_F,
	KEY_UP_F,
	KEY_DOWN_G,
	KEY_UP_G,
	KEY_DOWN_H,
	KEY_UP_H,
	KEY_DOWN_I,
	KEY_UP_I,
	KEY_DOWN_J,
	KEY_UP_J,
	KEY_DOWN_K,
	KEY_UP_K,
	KEY_DOWN_L,
	KEY_UP_L,
	KEY_DOWN_M,
	KEY_UP_M,
	KEY_DOWN_N,
	KEY_UP_N,
	KEY_DOWN_O,
	KEY_UP_O,
	KEY_DOWN_P,
	KEY_UP_P,
	KEY_DOWN_Q,
	KEY_UP_Q,
	KEY_DOWN_R,
	KEY_UP_R,
	KEY_DOWN_S,
	KEY_UP_S,
	KEY_DOWN_T,
	KEY_UP_T,
	KEY_DOWN_U,
	KEY_UP_U,
	KEY_DOWN_V,
	KEY_UP_V,
	KEY_DOWN_W,
	KEY_UP_W,
	KEY_DOWN_X,
	KEY_UP_X,
	KEY_DOWN_Y,
	KEY_UP_Y,
	KEY_DOWN_Z,
	KEY_UP_Z,
	
	KEY_DOWN_NumPadZero,
	KEY_UP_NumPadZero,
	KEY_DOWN_NumPadOne,
	KEY_UP_NumPadOne,
	KEY_DOWN_NumPadTwo,
	KEY_UP_NumPadTwo,
	KEY_DOWN_NumPadThree,
	KEY_UP_NumPadThree,
	KEY_DOWN_NumPadFour,
	KEY_UP_NumPadFour,
	KEY_DOWN_NumPadFive,
	KEY_UP_NumPadFive,
	KEY_DOWN_NumPadSix,
	KEY_UP_NumPadSix,
	KEY_DOWN_NumPadSeven,
	KEY_UP_NumPadSeven,
	KEY_DOWN_NumPadEight,
	KEY_UP_NumPadEight,
	KEY_DOWN_NumPadNine,
	KEY_UP_NumPadNine,
	
	KEY_DOWN_Multiply,
	KEY_UP_Multiply,
	KEY_DOWN_Add,
	KEY_UP_Add,
	KEY_DOWN_Subtract,
	KEY_UP_Subtract,
	KEY_DOWN_Decimal,
	KEY_UP_Decimal,
	KEY_DOWN_Divide,
	KEY_UP_Divide,
	
	KEY_DOWN_F1,
	KEY_UP_F1,
	KEY_DOWN_F2,
	KEY_UP_F2,
	KEY_DOWN_F3,
	KEY_UP_F3,
	KEY_DOWN_F4,
	KEY_UP_F4,
	KEY_DOWN_F5,
	KEY_UP_F5,
	KEY_DOWN_F6,
	KEY_UP_F6,
	KEY_DOWN_F7,
	KEY_UP_F7,
	KEY_DOWN_F8,
	KEY_UP_F8,
	KEY_DOWN_F9,
	KEY_UP_F9,
	KEY_DOWN_F10,
	KEY_UP_F10,
	KEY_DOWN_F11,
	KEY_UP_F11,
	KEY_DOWN_F12,
	KEY_UP_F12,
	
	KEY_DOWN_NumLock,
	KEY_UP_NumLock,
	
	KEY_DOWN_ScrollLock,
	KEY_UP_ScrollLock,
	
	KEY_DOWN_LeftShift,
	KEY_UP_LeftShift,
	KEY_DOWN_RightShift,
	KEY_UP_RightShift,
	KEY_DOWN_LeftControl,
	KEY_UP_LeftControl,
	KEY_DOWN_RightControl,
	KEY_UP_RightControl,
	KEY_DOWN_LeftAlt,
	KEY_UP_LeftAlt,
	KEY_DOWN_RightAlt,
	KEY_UP_RightAlt,
	KEY_DOWN_LeftCommand,
	KEY_UP_LeftCommand,
	KEY_DOWN_RightCommand,
	KEY_UP_RightCommand,
	
	KEY_DOWN_Semicolon,
	KEY_UP_Semicolon,
	KEY_DOWN_Equals,
	KEY_UP_Equals,
	KEY_DOWN_Comma,
	KEY_UP_Comma,
	KEY_DOWN_Underscore,
	KEY_UP_Underscore,
	KEY_DOWN_Hyphen,
	KEY_UP_Hyphen,
	KEY_DOWN_Period,
	KEY_UP_Period,
	KEY_DOWN_Slash,
	KEY_UP_Slash,
	KEY_DOWN_Tilde,
	KEY_UP_Tilde,
	KEY_DOWN_LeftBracket,
	KEY_UP_LeftBracket,
	KEY_DOWN_LeftParantheses,
	KEY_UP_LeftParantheses,
	KEY_DOWN_Backslash,
	KEY_UP_Backslash,
	KEY_DOWN_RightBracket,
	KEY_UP_RightBracket,
	KEY_DOWN_RightParantheses,
	KEY_UP_RightParantheses,
	KEY_DOWN_Apostrophe,
	KEY_UP_Apostrophe,
	KEY_DOWN_Quote,
	KEY_UP_Quote,
	
	KEY_DOWN_Asterix,
	KEY_UP_Asterix,
	KEY_DOWN_Ampersand,
	KEY_UP_Ampersand,
	KEY_DOWN_Caret,
	KEY_UP_Caret,
	KEY_DOWN_Dollar,
	KEY_UP_Dollar,
	KEY_DOWN_Exclamation,
	KEY_UP_Exclamation,
	KEY_DOWN_Colon,
	KEY_UP_Colon,
	
	KEY_DOWN_A_AccentGrave,
	KEY_UP_A_AccentGrave,
	KEY_DOWN_E_AccentGrave,
	KEY_UP_E_AccentGrave,
	KEY_DOWN_E_AccentAigu,
	KEY_UP_E_AccentAigu,
	KEY_DOWN_C_Cedille,
	KEY_UP_C_Cedille,
	KEY_DOWN_Section,
	KEY_UP_Section,
};

class FrameText
{
  private:
    int32 w, h;
    int32 x, y;
    int32 r, g, b, a;
    int32 scale;
    bool shown;
    FString type;
    FString strata;
    FString name;
    // Frame* parent;
    static int32 count;

  public:
};

/**
 *
 */
class FPSPROJECT_API Frame
{
	private:
		int32 w, h;
		int32 x, y;
		int32 r, g, b, a;
		int32 scale;
		int32 level;
		bool shown;
		bool mouseOver;
		FString type;
		FString strata;
		FString name;
		Frame* parent;
		static int32 count;
		
		enum ScriptTypes
		{
		  OnUpdate,
		};
		
		enum AnchorPoints
		{
			TOPLEFT,
			TOP,
			TOPRIGHT,
			LEFT,
			CENTER,
			RIGHT,
			BOTTOMLEFT,
			BOTTOM,
			BOTTOMRIGHT,
		};
		
		struct Level
		{
			static TArray<Frame*> FrameList;
			Level(){}
		};
		
		struct Strata // The basic array
		{
			static TMap<int32, Level> LevelMap;
			Strata(){}
		};
		
		typedef void (*Scripts)();
		
		static TArray<Scripts> OnUpdateList;
		static TArray<FString> EventList;
	protected:
		
  public:
		static TArray<Frame*> MOUSE_ENTER_list;
		static TArray<Frame*> MOUSE_EXIT_list;
		static TArray<Frame*> GAME_START_list;
		static TArray<Frame*> GAME_QUIT_list;
		static TArray<Frame*> FRAME_CREATED_list;
		static TArray<Frame*> MOUSE_CLICKED_DOWN_list;
		static TArray<Frame*> MOUSE_CLICKED_UP_list;
		static TArray<Frame*> MOUSE_MOVEMENT_list;
		static TArray<Frame*> KEY_DOWN_list;
		static TArray<Frame*> KEY_UP_list;
		static TArray<Frame*> UPDATE_list;
		static TArray<Frame*> WINDOW_FOCUS_list;
		
		static TArray<Frame*> Frame::DOWN_MouseX_list;
		static TArray<Frame*> Frame::UP_MouseX_list;
		static TArray<Frame*> Frame::DOWN_MouseY_list;
		static TArray<Frame*> Frame::UP_MouseY_list;
		static TArray<Frame*> Frame::DOWN_MouseScrollUp_list;
		static TArray<Frame*> Frame::UP_MouseScrollUp_list;
		static TArray<Frame*> Frame::DOWN_MouseScrollDown_list;
		static TArray<Frame*> Frame::UP_MouseScrollDown_list;
		static TArray<Frame*> Frame::DOWN_MouseWheelAxis_list;
		static TArray<Frame*> Frame::UP_MouseWheelAxis_list;
		
		static TArray<Frame*> Frame::DOWN_LeftMouseButton_list;
		static TArray<Frame*> Frame::UP_LeftMouseButton_list;
		static TArray<Frame*> Frame::DOWN_RightMouseButton_list;
		static TArray<Frame*> Frame::UP_RightMouseButton_list;
		static TArray<Frame*> Frame::DOWN_MiddleMouseButton_list;
		static TArray<Frame*> Frame::UP_MiddleMouseButton_list;
		static TArray<Frame*> Frame::DOWN_ThumbMouseButton_list;
		static TArray<Frame*> Frame::UP_ThumbMouseButton_list;
		static TArray<Frame*> Frame::DOWN_ThumbMouseButton2_list;
		static TArray<Frame*> Frame::UP_ThumbMouseButton2_list;
		
		static TArray<Frame*> Frame::DOWN_BackSpace_list;
		static TArray<Frame*> Frame::UP_BackSpace_list;
		static TArray<Frame*> Frame::DOWN_Tab_list;
		static TArray<Frame*> Frame::UP_Tab_list;
		static TArray<Frame*> Frame::DOWN_Enter_list;
		static TArray<Frame*> Frame::UP_Enter_list;
		static TArray<Frame*> Frame::DOWN_Pause_list;
		static TArray<Frame*> Frame::UP_Pause_list;
		
		static TArray<Frame*> Frame::DOWN_CapsLock_list;
		static TArray<Frame*> Frame::UP_CapsLock_list;
		static TArray<Frame*> Frame::DOWN_Escape_list;
		static TArray<Frame*> Frame::UP_Escape_list;
		static TArray<Frame*> Frame::DOWN_SpaceBar_list;
		static TArray<Frame*> Frame::UP_SpaceBar_list;
		static TArray<Frame*> Frame::DOWN_PageUp_list;
		static TArray<Frame*> Frame::UP_PageUp_list;
		static TArray<Frame*> Frame::DOWN_PageDown_list;
		static TArray<Frame*> Frame::UP_PageDown_list;
		static TArray<Frame*> Frame::DOWN_End_list;
		static TArray<Frame*> Frame::UP_End_list;
		static TArray<Frame*> Frame::DOWN_Home_list;
		static TArray<Frame*> Frame::UP_Home_list;
		
		static TArray<Frame*> Frame::DOWN_Left_list;
		static TArray<Frame*> Frame::UP_Left_list;
		static TArray<Frame*> Frame::DOWN_Up_list;
		static TArray<Frame*> Frame::UP_Up_list;
		static TArray<Frame*> Frame::DOWN_Right_list;
		static TArray<Frame*> Frame::UP_Right_list;
		static TArray<Frame*> Frame::DOWN_Down_list;
		static TArray<Frame*> Frame::UP_Down_list;
		
		static TArray<Frame*> Frame::DOWN_Insert_list;
		static TArray<Frame*> Frame::UP_Insert_list;
		static TArray<Frame*> Frame::DOWN_Delete_list;
		static TArray<Frame*> Frame::UP_Delete_list;
		
		static TArray<Frame*> Frame::DOWN_Zero_list;
		static TArray<Frame*> Frame::UP_Zero_list;
		static TArray<Frame*> Frame::DOWN_One_list;
		static TArray<Frame*> Frame::UP_One_list;
		static TArray<Frame*> Frame::DOWN_Two_list;
		static TArray<Frame*> Frame::UP_Two_list;
		static TArray<Frame*> Frame::DOWN_Three_list;
		static TArray<Frame*> Frame::UP_Three_list;
		static TArray<Frame*> Frame::DOWN_Four_list;
		static TArray<Frame*> Frame::UP_Four_list;
		static TArray<Frame*> Frame::DOWN_Five_list;
		static TArray<Frame*> Frame::UP_Five_list;
		static TArray<Frame*> Frame::DOWN_Six_list;
		static TArray<Frame*> Frame::UP_Six_list;
		static TArray<Frame*> Frame::DOWN_Seven_list;
		static TArray<Frame*> Frame::UP_Seven_list;
		static TArray<Frame*> Frame::DOWN_Eight_list;
		static TArray<Frame*> Frame::UP_Eight_list;
		static TArray<Frame*> Frame::DOWN_Nine_list;
		static TArray<Frame*> Frame::UP_Nine_list;
		
		static TArray<Frame*> Frame::DOWN_A_list;
		static TArray<Frame*> Frame::UP_A_list;
		static TArray<Frame*> Frame::DOWN_B_list;
		static TArray<Frame*> Frame::UP_B_list;
		static TArray<Frame*> Frame::DOWN_C_list;
		static TArray<Frame*> Frame::UP_C_list;
		static TArray<Frame*> Frame::DOWN_D_list;
		static TArray<Frame*> Frame::UP_D_list;
		static TArray<Frame*> Frame::DOWN_E_list;
		static TArray<Frame*> Frame::UP_E_list;
		static TArray<Frame*> Frame::DOWN_F_list;
		static TArray<Frame*> Frame::UP_F_list;
		static TArray<Frame*> Frame::DOWN_G_list;
		static TArray<Frame*> Frame::UP_G_list;
		static TArray<Frame*> Frame::DOWN_H_list;
		static TArray<Frame*> Frame::UP_H_list;
		static TArray<Frame*> Frame::DOWN_I_list;
		static TArray<Frame*> Frame::UP_I_list;
		static TArray<Frame*> Frame::DOWN_J_list;
		static TArray<Frame*> Frame::UP_J_list;
		static TArray<Frame*> Frame::DOWN_K_list;
		static TArray<Frame*> Frame::UP_K_list;
		static TArray<Frame*> Frame::DOWN_L_list;
		static TArray<Frame*> Frame::UP_L_list;
		static TArray<Frame*> Frame::DOWN_M_list;
		static TArray<Frame*> Frame::UP_M_list;
		static TArray<Frame*> Frame::DOWN_N_list;
		static TArray<Frame*> Frame::UP_N_list;
		static TArray<Frame*> Frame::DOWN_O_list;
		static TArray<Frame*> Frame::UP_O_list;
		static TArray<Frame*> Frame::DOWN_P_list;
		static TArray<Frame*> Frame::UP_P_list;
		static TArray<Frame*> Frame::DOWN_Q_list;
		static TArray<Frame*> Frame::UP_Q_list;
		static TArray<Frame*> Frame::DOWN_R_list;
		static TArray<Frame*> Frame::UP_R_list;
		static TArray<Frame*> Frame::DOWN_S_list;
		static TArray<Frame*> Frame::UP_S_list;
		static TArray<Frame*> Frame::DOWN_T_list;
		static TArray<Frame*> Frame::UP_T_list;
		static TArray<Frame*> Frame::DOWN_U_list;
		static TArray<Frame*> Frame::UP_U_list;
		static TArray<Frame*> Frame::DOWN_V_list;
		static TArray<Frame*> Frame::UP_V_list;
		static TArray<Frame*> Frame::DOWN_W_list;
		static TArray<Frame*> Frame::UP_W_list;
		static TArray<Frame*> Frame::DOWN_X_list;
		static TArray<Frame*> Frame::UP_X_list;
		static TArray<Frame*> Frame::DOWN_Y_list;
		static TArray<Frame*> Frame::UP_Y_list;
		static TArray<Frame*> Frame::DOWN_Z_list;
		static TArray<Frame*> Frame::UP_Z_list;
		
		static TArray<Frame*> Frame::DOWN_NumPadZero_list;
		static TArray<Frame*> Frame::UP_NumPadZero_list;
		static TArray<Frame*> Frame::DOWN_NumPadOne_list;
		static TArray<Frame*> Frame::UP_NumPadOne_list;
		static TArray<Frame*> Frame::DOWN_NumPadTwo_list;
		static TArray<Frame*> Frame::UP_NumPadTwo_list;
		static TArray<Frame*> Frame::DOWN_NumPadThree_list;
		static TArray<Frame*> Frame::UP_NumPadThree_list;
		static TArray<Frame*> Frame::DOWN_NumPadFour_list;
		static TArray<Frame*> Frame::UP_NumPadFour_list;
		static TArray<Frame*> Frame::DOWN_NumPadFive_list;
		static TArray<Frame*> Frame::UP_NumPadFive_list;
		static TArray<Frame*> Frame::DOWN_NumPadSix_list;
		static TArray<Frame*> Frame::UP_NumPadSix_list;
		static TArray<Frame*> Frame::DOWN_NumPadSeven_list;
		static TArray<Frame*> Frame::UP_NumPadSeven_list;
		static TArray<Frame*> Frame::DOWN_NumPadEight_list;
		static TArray<Frame*> Frame::UP_NumPadEight_list;
		static TArray<Frame*> Frame::DOWN_NumPadNine_list;
		static TArray<Frame*> Frame::UP_NumPadNine_list;
		
		static TArray<Frame*> Frame::DOWN_Multiply_list;
		static TArray<Frame*> Frame::UP_Multiply_list;
		static TArray<Frame*> Frame::DOWN_Add_list;
		static TArray<Frame*> Frame::UP_Add_list;
		static TArray<Frame*> Frame::DOWN_Subtract_list;
		static TArray<Frame*> Frame::UP_Subtract_list;
		static TArray<Frame*> Frame::DOWN_Decimal_list;
		static TArray<Frame*> Frame::UP_Decimal_list;
		static TArray<Frame*> Frame::DOWN_Divide_list;
		static TArray<Frame*> Frame::UP_Divide_list;
		
		static TArray<Frame*> Frame::DOWN_F1_list;
		static TArray<Frame*> Frame::UP_F1_list;
		static TArray<Frame*> Frame::DOWN_F2_list;
		static TArray<Frame*> Frame::UP_F2_list;
		static TArray<Frame*> Frame::DOWN_F3_list;
		static TArray<Frame*> Frame::UP_F3_list;
		static TArray<Frame*> Frame::DOWN_F4_list;
		static TArray<Frame*> Frame::UP_F4_list;
		static TArray<Frame*> Frame::DOWN_F5_list;
		static TArray<Frame*> Frame::UP_F5_list;
		static TArray<Frame*> Frame::DOWN_F6_list;
		static TArray<Frame*> Frame::UP_F6_list;
		static TArray<Frame*> Frame::DOWN_F7_list;
		static TArray<Frame*> Frame::UP_F7_list;
		static TArray<Frame*> Frame::DOWN_F8_list;
		static TArray<Frame*> Frame::UP_F8_list;
		static TArray<Frame*> Frame::DOWN_F9_list;
		static TArray<Frame*> Frame::UP_F9_list;
		static TArray<Frame*> Frame::DOWN_F10_list;
		static TArray<Frame*> Frame::UP_F10_list;
		static TArray<Frame*> Frame::DOWN_F11_list;
		static TArray<Frame*> Frame::UP_F11_list;
		static TArray<Frame*> Frame::DOWN_F12_list;
		static TArray<Frame*> Frame::UP_F12_list;
		
		static TArray<Frame*> Frame::DOWN_NumLock_list;
		static TArray<Frame*> Frame::UP_NumLock_list;
		
		static TArray<Frame*> Frame::DOWN_ScrollLock_list;
		static TArray<Frame*> Frame::UP_ScrollLock_list;
		
		static TArray<Frame*> Frame::DOWN_LeftShift_list;
		static TArray<Frame*> Frame::UP_LeftShift_list;
		static TArray<Frame*> Frame::DOWN_RightShift_list;
		static TArray<Frame*> Frame::UP_RightShift_list;
		static TArray<Frame*> Frame::DOWN_LeftControl_list;
		static TArray<Frame*> Frame::UP_LeftControl_list;
		static TArray<Frame*> Frame::DOWN_RightControl_list;
		static TArray<Frame*> Frame::UP_RightControl_list;
		static TArray<Frame*> Frame::DOWN_LeftAlt_list;
		static TArray<Frame*> Frame::UP_LeftAlt_list;
		static TArray<Frame*> Frame::DOWN_RightAlt_list;
		static TArray<Frame*> Frame::UP_RightAlt_list;
		static TArray<Frame*> Frame::DOWN_LeftCommand_list;
		static TArray<Frame*> Frame::UP_LeftCommand_list;
		static TArray<Frame*> Frame::DOWN_RightCommand_list;
		static TArray<Frame*> Frame::UP_RightCommand_list;
		
    // void (*OnEventFunc)();
    void (*OnEventFunc)(Frame* f, EventEnum event);
    static const FString strataList[5];
    
    static TMap<FString, Strata> StrataMap;
    static TArray<FrameText> TextList;
    
    Frame();
    ~Frame();
    
    static void InitializeEventList();
    
    // Get functions /////////////////////////////////////////////////////////////
    int32 GetWidth() const;
    int32 GetHeight() const;
    int32 GetSize() const;
    int32 GetX() const;
    int32 GetY() const;
    int32 GetPosition() const;
    int32 GetColorInt() const;
    FLinearColor GetColor() const;
    int32 GetAlpha() const;
    int32 GetScale() const;
    int32 GetLevel() const;
    bool IsShown() const;
    bool GetMouseOver() const;
    FString GetType() const;
    FString GetStrata() const;
    FString GetName() const;
    Frame* GetParent() const;
    // Frame& GetPtr() const;
    //////////////////////////////////////////////////////////////////////////////
    
    // Set functions /////////////////////////////////////////////////////////////
    void SetWidth(int32 nW);
    void SetHeight(int32 nH);
    void SetSize(int32 nW, int32 nH);
    void SetX(int32 nX);
    void SetY(int32 nY);
    void SetPosition(int32 nX, int32 nY);
    void SetScale(int32 nScale);
    void SetName(FString nName);
    void SetType(FString nType);
    void SetShown(bool nVisibility);
    void SetMouseOver(bool nMouseOver);
    
    void SetScript(ScriptTypes script, void (*func)());
    
    void OnEvent(void (*func)(Frame*, EventEnum));
    
    void SetColor(int32 nR = 1.f, int32 nG = 1.f, int32 nB = 1.f, int32 nA = 1.f);
    
    void SetAlpha(int32 nA = 1.f);
    
    void SetLevel(int32 nLevel);
    
    void SetStrata(FString nStrata);
    
    void RegisterEvent(EventEnum event);
    
    void SetParent();
    //////////////////////////////////////////////////////////////////////////////
    
    static Frame* CreateFrame(FString nName, FString nStrata, int32 nLevel);
    
    static void IterateScriptArrays();
		
		static void Fire(EventEnum event);
};



// static TArray<Frame*> Frame::DOWN_Semicolon_list;
// static TArray<Frame*> Frame::UP_Semicolon_list;
// static TArray<Frame*> Frame::DOWN_Equals_list;
// static TArray<Frame*> Frame::UP_Equals_list;
// static TArray<Frame*> Frame::DOWN_Comma_list;
// static TArray<Frame*> Frame::UP_Comma_list;
// static TArray<Frame*> Frame::DOWN_Underscore_list;
// static TArray<Frame*> Frame::UP_Underscore_list;
// static TArray<Frame*> Frame::DOWN_Hyphen_list;
// static TArray<Frame*> Frame::UP_Hyphen_list;
// static TArray<Frame*> Frame::DOWN_Period_list;
// static TArray<Frame*> Frame::UP_Period_list;
// static TArray<Frame*> Frame::DOWN_Slash_list;
// static TArray<Frame*> Frame::UP_Slash_list;
// static TArray<Frame*> Frame::DOWN_Tilde_list;
// static TArray<Frame*> Frame::UP_Tilde_list;
// static TArray<Frame*> Frame::DOWN_LeftBracket_list;
// static TArray<Frame*> Frame::UP_LeftBracket_list;
// static TArray<Frame*> Frame::DOWN_LeftParantheses_list;
// static TArray<Frame*> Frame::UP_LeftParantheses_list;
// static TArray<Frame*> Frame::DOWN_Backslash_list;
// static TArray<Frame*> Frame::UP_Backslash_list;
// static TArray<Frame*> Frame::DOWN_RightBracket_list;
// static TArray<Frame*> Frame::UP_RightBracket_list;
// static TArray<Frame*> Frame::DOWN_RightParantheses_list;
// static TArray<Frame*> Frame::UP_RightParantheses_list;
// static TArray<Frame*> Frame::DOWN_Apostrophe_list;
// static TArray<Frame*> Frame::UP_Apostrophe_list;
// static TArray<Frame*> Frame::DOWN_Quote_list;
// static TArray<Frame*> Frame::UP_Quote_list;
//
// static TArray<Frame*> Frame::DOWN_Asterix_list;
// static TArray<Frame*> Frame::UP_Asterix_list;
// static TArray<Frame*> Frame::DOWN_Ampersand_list;
// static TArray<Frame*> Frame::UP_Ampersand_list;
// static TArray<Frame*> Frame::DOWN_Caret_list;
// static TArray<Frame*> Frame::UP_Caret_list;
// static TArray<Frame*> Frame::DOWN_Dollar_list;
// static TArray<Frame*> Frame::UP_Dollar_list;
// static TArray<Frame*> Frame::DOWN_Exclamation_list;
// static TArray<Frame*> Frame::UP_Exclamation_list;
// static TArray<Frame*> Frame::DOWN_Colon_list;
// static TArray<Frame*> Frame::UP_Colon_list;
//
// static TArray<Frame*> Frame::DOWN_A_AccentGrave_list;
// static TArray<Frame*> Frame::UP_A_AccentGrave_list;
// static TArray<Frame*> Frame::DOWN_E_AccentGrave_list;
// static TArray<Frame*> Frame::UP_E_AccentGrave_list;
// static TArray<Frame*> Frame::DOWN_E_AccentAigu_list;
// static TArray<Frame*> Frame::UP_E_AccentAigu_list;
// static TArray<Frame*> Frame::DOWN_C_Cedille_list;
// static TArray<Frame*> Frame::UP_C_Cedille_list;
// static TArray<Frame*> Frame::DOWN_Section_list;
// static TArray<Frame*> Frame::UP_Section_list;
