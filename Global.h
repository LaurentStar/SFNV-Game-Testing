#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED
#include "SDL.h"
#include <string>


//The objects
struct Circle {
    int x ; 
	int y ;
    int r ;
};

struct Square        
{
    int x, y;
    int w, h;

	int front_cliff;
};

struct Triangle_Object{
	// A triangle needs three points. We'll make lines using fomulas 
	int x1, y1;
	int x2, y2;
	int x3, y3; 
};

//Holds data about other classes so they can communicate quickly
struct Chain_Link{
	//////////////////////////////////////////////////////////
	//MASTERS VARIABLES
	//////////////////////////////////////////////////////////
	//The address of the object asking for it's service
	int Master_Address;

	//The type of the master and slave.
	int Master_Type, Master_Sub_Type;

	//Address2, Address3 //Many masters concepts might appear later.

	// Coordinate of the master.
	int Master_x, Master_y, Master_z;

	//The number of children the master has
	int Master_X_Child[4], Master_Y_Child[4], Master_Z_Child[4];

	//The number that represent the 5 set of int variables to be effected by the int variables below
	int Master_Variable_Set; 

	// The variables the slave must alter sometimes for the master. 
	int Master_Variable_I, Master_Variable_II, Master_Variable_III, Master_Variable_IV, Master_Variable_V; 

	//Made for easy talking
	std::string Master_Text;


	//////////////////////////////////////////////////////////
	//SLAVES VARIABLES
	//////////////////////////////////////////////////////////
	//The adress of the object performing the serive
	int Slave_Address;

	//The type the slave needs to be
	int Slave_Type;

	//////////////////////////////////////////////////////////
	//MISC VARIABLES
	//////////////////////////////////////////////////////////

	//Shows rather objects are linked/ When the master needs a slave
	bool Active_Link;

	// Detremine when to performs an action
	bool Performing;
	
	//the action to perform if the master asks
	int  Perform;




	
};

struct Ai_Brain
{
	float Target_Direction;	//Direction of target of interest
	int Target_Distance;	
	int Target_Elevation;	// The elevation of the target of interest
	int Act;				// The state of the brain at the moment
	int Attack_Option;		//The attack to perform when Act is in attack mode
};


//The camera
extern Square Camera ;

extern SDL_Surface *YstarFont;

//The surfaces
extern SDL_Surface *Screen ;
extern SDL_Surface *ScreenEffects;
extern SDL_Surface *OnScreenBG;
extern SDL_Surface *OnScreen;
extern SDL_Surface *SkyLine; //Skyline can change trancparency and shares the same resources with ScreenEffects

extern SDL_Surface *Character1; // TESTING ONLY
extern SDL_Surface *CryonTanryokuSheet; 
extern SDL_Surface *ShadowCryonTanryokuSheet; 
extern SDL_Surface *EnemySheet;
extern SDL_Surface *ChromeCrystalMasterGray;

extern SDL_Surface *FloorTileSheet ; // Floor tile art only
extern SDL_Surface *FloatTileSheet ; // for all floating objects
extern SDL_Surface *ShadowFloatTileSheet ;
extern SDL_Surface *TransparentFloatTileSheet ;
extern SDL_Surface *ExitTileSheet ;

//Sprite from the tile sheet
extern SDL_Rect Screen_Effects_Clips[];
extern SDL_Rect On_Screen_Clips[];
extern SDL_Rect Character_Test_Clips[];
extern SDL_Rect Cyron_Tanryoku_Clips[];
extern SDL_Rect ChromeCrystalMasterGray_Clips[];
extern SDL_Rect Enemy_Clips[];

extern SDL_Rect Floor_Object_Clips[ ];
extern SDL_Rect Float_Object_Clips[ ];
extern SDL_Rect Shadow_Float_Object_Clips[ ];
extern SDL_Rect Shadow_Float_Config_Object_Clips[ ];
extern SDL_Rect Exit_Object_Clips[ ];
extern SDL_Rect Game_Object_Clips[ ];

//The event structure
extern SDL_Event event;



// The button function is the only one that edited these
extern bool Left_Key;
extern bool Right_Key;
extern bool Up_Key;
extern bool Down_Key;
extern bool Z_Key;
extern bool X_Key;
extern bool C_Key;
extern bool Space_Key;
extern bool Button_Delay;
extern float Button_Delay_Timer;
extern float Button_Timer_Value;// Alter in timer class. Get_tick
extern bool Button_Double_Tap; 
extern int Button_Press_Tracked_Alpha;
extern int Button_Press_Tracked_Omega;
extern float Button_Press_Timer;



extern bool Level_Warp; // Altered Internal_Configuration.h->Level_Gate_Collision()
extern bool Level_Warp_Key; //Allow other classes to react to a level warp
/* Altered: 
//void Final_Warp_Process();
//bool Pick_Level(Soul *Spirit[], External_Configuration config, int level)*/

// Used when you need the player to stay still. Only 2 function can alter this
extern int Freeze_All_Actions; // Altered Internal_Configuration.h->Level_Gate_Collision()
extern int Transparant; // Altered in Graphic_Event_Fade_In

/* 
Edited by "Title_Screen()"
To be Continued....
*/



/*GAME_MODE: 
function.h Title_Screen()
*/
extern int Game_Mode; // This special variable will be edited by a lot of places. Keep track of ever edit. 

extern int Terrorist_Level;

//Represent which character is currently playable
extern int Selected_Character;
extern int Selected_Spirit;
#endif // TILE_H_INCLUDED