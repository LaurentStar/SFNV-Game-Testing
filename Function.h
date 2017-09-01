#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED

#include "SDL.h"
#include "SDL_image.h"
#include <string>
#include <fstream>
#include <cmath>

#include "Constant.h"
#include "Constant_Animation_Frame.h"
#include "Constant_Link_Commands.h"
#include "All_Enterance_Coords.h"
#include "Global.h"


#include "External_Configuration.h"
#include "Soul.h"



//#include "Editor_Functions.h"
#include "Art_Clip.h"
#include "Load_Level_Functions.h"
#include "King.h"


#include "Environment_Objects.h"
#include "Timer.h"

//#include "Character.h"
#include "Internal_Configuration.h"
#include "Physics.h"
#include "AI_Logic.h"

#include "Bullet.h"
//#include "Enemy.h"
#include "On_Screen_BG_Object.h"

#include "Config_Objects.h"
#include "On_Screen_Config_Object.h"
#include "On_Screen_Object.h"

#include "Character_Object.h"
#include "Smart_AI_Object.h"
#include "Dumb_AI_Object.h"
#include "Hit_Box_Pool_Object.h"
#include "Bitmap_Text_Pool_Object.h"




//#include "Menu.h"

#include "Rendering.h"

#include "Joker.h"



void Title_Screen();

SDL_Surface *load_image( std::string filename );
// Used for printing to the screen
void Apply_Surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL ); 

Uint32 Get_Pixel32(int x, int y, SDL_Surface *font);



bool Init(); 

bool Load_Files();

void Clean_Up(Soul *Spirit[] );


bool Shadow_Enable(Square W, Square Y, Square V, Square S);
int Drop_Shadow_Enable(Square W, Square Y, Square V, Square S );
bool Transparent_Enable(Square W, Square Y, Square V, Square S);

bool Load_New_Levels(Soul *Spirit[],Environment_Objects *G[],External_Configuration *L[]);

bool Load_New_Level_Loader_Objects(External_Configuration *object[], External_Configuration config);

bool Set_Objects(Soul *Spirit[], External_Configuration &config);
bool Pick_Start_Level(Soul *Spirit[], External_Configuration &config, int level);

bool Set_Grounded_Objects( Environment_Objects *object[], External_Configuration config);
//bool Set_Enemy_Objects( Enemy_Object *object[], External_Configuration config);
void Set_Bullet_Objects( Bullet_Object *object[]);


int Object_Setting_Helper(std::string level_name);
std::string Level_Identitfier(int exit_type);
int Character_Coords_Matcher(int exit_type,int returner);
bool Write_Current_Location(int Exit, std::string level_name,int x, int y, int z);
bool Write_Save_Game_Pad(Soul *Spirit[]);


//void Spawn_Ai();
//void Ai_Spawn_Points();



//Use in collsion detection. Check destant with shapes. 
double Distance( int x1, int y1, int x2, int y2 );
double Direction(int x1, int y1, int x2, int y2);

bool Square_Object_Detection(Square V, Square S );

int Tracking(int returner, Square character_base, Square square_base);

//Use to detect collision on base objects with characters. EDIT now gifted with ability to track player location. -1 equals no collision 
int Base_Object_Detection(Square character_base, Square character_cornice, Square square_base);

// Used to detrimine collsion with floating objects
int Object_Detection_Above_Below(int track_a, int track_b, Square character_cornice, Square square);
int Object_Detection_Above_Below_Two(int track_a, int track_b, Square character_base ,Square character_cornice, Square square);

//int Object_Detection_Sides( int track_a, int track_b, Square character_cornice, Square square );
int Object_Detection_Front_Back(int track_a, int track_b, Square character_cornice, Square square);
int Object_Detection_Front_Back_Two(int track_a, int track_b, int pre_collision, Square base, Square character_cornice, Square square);



// Now capable of returning shape and type of object. 
int Collision_Detection(Square base, Square cornice, Soul *Spirit[]);
//int Collision_Detection_Two( Square base ,Square Cornice, Environment_Objects *object[]);


bool Exit_Object_Collision(Square Base, Square Cornice, External_Configuration *objects[]);




void Game_Start_Soul(Soul *Spirit[], External_Configuration config);


//ALL FUNCTION FOR USING BULLETS
void Projectile_Active(Bullet_Object *bullet[], Uint32 deltaTicks);
void Projectile_Definer(Bullet_Object *bullet[], int type, int x, int y, int z ,int lenght, int width, int height, int time);
int Button_Command();



int Graphic_Event_Fade_Out(int activation_type);
int Graphic_Event_Fade_In(int activation_type);
void Level_Warpping(int warp_type, int level, int location, int action, bool level_warp, Soul *Spirit[], External_Configuration config);
void Final_Warp_Process(Internal_Config &IN_config, Rendering &graphic, Soul *spirit[] );


void Change_Game_Mode(int change_mode);
void Change_Selected_Character(int selected_character);

#endif // CHARACTER_H_INCLUDED
