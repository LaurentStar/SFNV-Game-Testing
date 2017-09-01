

#include "SDL.h"
#include "Global.h"
#include "Constant.h"
//The surfaces

//The camera
Square Camera = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };

//Surfaces.
SDL_Surface *YstarFont = NULL;

SDL_Surface *Screen = NULL;
SDL_Surface *ScreenEffects = NULL;
SDL_Surface *OnScreenBG = NULL;
SDL_Surface *OnScreen = NULL;
SDL_Surface *SkyLine = NULL;

SDL_Surface *Character1 = NULL;
SDL_Surface *CryonTanryokuSheet = NULL; 
SDL_Surface *ShadowCryonTanryokuSheet = NULL; 
SDL_Surface *ChromeCrystalMasterGray = NULL; // Objects will not be named exclusively later. Blink surfaces will be assigned meaning
SDL_Surface *EnemySheet = NULL;

SDL_Surface *FloorTileSheet = NULL;
SDL_Surface *FloatTileSheet = NULL;
SDL_Surface *ShadowFloatTileSheet = NULL;
SDL_Surface *TransparentFloatTileSheet = NULL;

SDL_Surface *ExitTileSheet = NULL;

//Sprite from the tile sheet
SDL_Rect Screen_Effects_Clips[26];
SDL_Rect On_Screen_Clips[32];
SDL_Rect Character_Test_Clips[2];
SDL_Rect Cyron_Tanryoku_Clips[72];
SDL_Rect ChromeCrystalMasterGray_Clips[1];
SDL_Rect Enemy_Clips[1];


SDL_Rect Floor_Object_Clips[ 4];
SDL_Rect Float_Object_Clips[ 3];
SDL_Rect Shadow_Float_Object_Clips[ 4];
SDL_Rect Shadow_Float_Config_Object_Clips[ 4];
SDL_Rect Exit_Object_Clips[ 4];
SDL_Rect Game_Object_Clips[1];

//The event structure
SDL_Event event;


bool Left_Key = false;
bool Right_Key = false;
bool Up_Key = false;
bool Down_Key = false;
bool Z_Key = false;
bool X_Key = false;
bool C_Key = false;
bool Space_Key = false;

bool Button_Delay = false;
float Button_Delay_Timer = 0;
float Button_Timer_Value = 0; // Alter in timer class. Get_tick
bool Button_Double_Tap = false; 
int Button_Press_Tracked_Alpha = 0;
int Button_Press_Tracked_Omega = 0;
float Button_Press_Timer = 0;

 // Altered in timer class get tick. Also Character_stats controller

// Only the 
bool Level_Warp = false;
bool Level_Warp_Key = false;

int Freeze_All_Actions = 0;
int Transparant = 0;



int Game_Mode = START_MENU;
int Terrorist_Level = 0;


//Represent which character is currently playable
int Selected_Character =  THE_YS_GUY;
int Selected_Spirit = XTHE_YS_GUYX;
