#include "Function.h"

void Title_Screen()
{
	bool Editor = false;

	int Button = 0;

	SDL_SetAlpha( ScreenEffects, SDL_SRCALPHA, 255 );
	
	while (Game_Mode == START_MENU)
	{
		
		
		//While there's events to handle
        while( SDL_PollEvent( &event ) )
        {
			Button = Button_Command();
			
			if (Button == SPACE)
			{
				SDL_SetAlpha( ScreenEffects, SDL_SRCALPHA, 0 );
				Game_Mode = GAMEPLAY_MODE;
			}

        }
	
	
			
		Apply_Surface( 0, 0, ScreenEffects,  Screen, &Screen_Effects_Clips[0] ) ;
		SDL_Flip( Screen );

		
	}
}


SDL_Surface *load_image( std::string filename )
{
   //The image that's loaded 
 SDL_Surface* loadedImage = NULL; 

 //The optimized surface that will be used 
 SDL_Surface* optimizedImage = NULL; 

 //Load the image 
 loadedImage = IMG_Load( filename.c_str() ); 

	//If the image loaded 
	if( loadedImage != NULL ) 
	{ 
		//Create an optimized surface 
		optimizedImage = SDL_DisplayFormat( loadedImage ); 

		//Free the old surface 
		SDL_FreeSurface( loadedImage ); 

		//If the surface was optimized 
		if( optimizedImage != NULL ) 
		{ 
			//Color key surface 
			SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, SDL_MapRGB( optimizedImage->format, 0, 0xFF, 0xFF ) ); 
		} 
	} 

	//Return the optimized surface 
	return optimizedImage; 
}

void Apply_Surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip ) 
 { 
	//Holds offsets 
	 SDL_Rect offset; 

	//Get offsets 
	offset.x = x; 
	offset.y = y; 

	//Blit 
	SDL_BlitSurface( source, clip, destination, &offset ); 
 } 

Uint32 Get_Pixel32(int x, int y, SDL_Surface *font)
{
	Uint32 *pixels = (Uint32 *)font-> pixels;

	return pixels [( y * font->w ) + x ];
}
bool Init() 
 { 
	//Initialize all SDL subsystems 
		if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 ) 
		{ 
			return false; 
		} 

		//Set up the screen 
		Screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE ); 

		//If there was an error in setting up the screen 
		if( Screen == NULL ) 
		{ 
			return false; 
		} 

		//Set the window caption 
		SDL_WM_SetCaption( "Sup Bitches", NULL ); 

	//If everything initialized fine 
	return true; 
 } 

bool Load_Files() 
{
	//Loading the files needed
	Character1 = load_image("Character1.png");
	if( Character1 == NULL ){return false;}
	
	CryonTanryokuSheet = load_image("CryonTanryokuSheet.png");
	if( CryonTanryokuSheet == NULL ){return false;}

	ShadowCryonTanryokuSheet = load_image("ShadowCryonTanryokuSheet.png");
	if( ShadowCryonTanryokuSheet == NULL ){return false;}
	

	FloorTileSheet = load_image("FloorTileSheet.png");
	if( FloorTileSheet == NULL ){return false;}
	
	FloatTileSheet = load_image("FloatTileSheet.png");
	if( FloatTileSheet  == NULL ){return false;}

	TransparentFloatTileSheet = load_image("FloatTileSheet.png");
	if( TransparentFloatTileSheet == NULL ){return false;}

	ShadowFloatTileSheet = load_image("ShadowFloatTileSheet.png");
	if( ShadowFloatTileSheet  == NULL ){return false;}

	ExitTileSheet = load_image("ExitTileSheet.png");
	if( ExitTileSheet  == NULL ){return false;}

	ScreenEffects = load_image("ScreenEffects.png");
	if( ScreenEffects  == NULL ){return false;}


	OnScreen = load_image("OnScreen.png");
	if(OnScreen  == NULL ){return false;}



	OnScreenBG = load_image("ScreenEffects.png");
	if( OnScreenBG  == NULL ){return false;}

	SkyLine = load_image("ScreenEffects.png");
	if( SkyLine  == NULL ){return false;}

	YstarFont = load_image("YstarFont.png");
	if( YstarFont  == NULL ){return false;}

	EnemySheet = load_image("EnemySheet.png");
	if(EnemySheet  == NULL ){return false;}

	ChromeCrystalMasterGray = load_image("ChromeCrystalMasterGraySheet.png");
	if(ChromeCrystalMasterGray == NULL){return false;}

	//If everything loaded fine
    return true;
}

void Clean_Up( Soul *Spirit[] )
{
    //Free the surfaces
	SDL_FreeSurface( Screen );
	SDL_FreeSurface( ScreenEffects );
	SDL_FreeSurface( SkyLine );
	SDL_FreeSurface( OnScreen);
	SDL_FreeSurface( Character1 );
	SDL_FreeSurface( CryonTanryokuSheet );
	SDL_FreeSurface( ShadowCryonTanryokuSheet );
    SDL_FreeSurface( FloorTileSheet );
	SDL_FreeSurface( FloatTileSheet );
	SDL_FreeSurface( ShadowFloatTileSheet );
	SDL_FreeSurface( ExitTileSheet );
    //Free the tiles

	  //Free the tiles
    for( int t = 0; t <  MAX_GAME_OBJECTS ; t++ )
    {
		if (Spirit[t] == NULL)
		{
			break;
		}
	
			delete Spirit[ t ];
		
    }
}


// W = Base character. Y = Cornice characeter. V = E base. S = E cornice SHADOW FUNCTIONS.
bool Shadow_Enable(Square W, Square Y, Square V, Square S )
{
	//The sides of the rectangles 
	int S_left, S_right, S_top, S_bottom;
	int V_left, V_right, V_top, V_bottom;
	int W_left, W_right, W_top, W_bottom;
	int Y_left, Y_right, Y_top, Y_bottom;
	


	//Calculate the sides of rect S
	S_left = S.x; 
	S_right = S.x + S.w; 
	S_top = S.y; 
	S_bottom = S.y + S.h; 
	
	//Calculate the sides of rect V 
	V_left = V.x; 
	V_right = V.x + V.w; 
	V_top = V.y; 
	V_bottom = V.y + V.h; 

	//Calculate the sides of rect W
	W_left = W.x; 
	W_right = W.x + W.w; 
	W_top = W.y; 
	W_bottom = W.y + W.h; 
	
	//Calculate the sides of rect V 
	Y_left = Y.x; 
	Y_right = Y.x + Y.w; 
	Y_top = Y.y; 
	Y_bottom = Y.y + Y.h; 


	
	if(( W_bottom >= V_top ) &&(W_top < V_bottom  ) &&( W_right >= V_left ) && ( W_left <= V_right ) )
	{ 
		if (Y_bottom >= S_bottom)
		{
			return true;
		}
	} 

	 // May be upgraded later. Collision for circles yo be added later.                                                      
	 return false; 
}
int Drop_Shadow_Enable(Square W, Square Y, Square V, Square S )
{
	//The sides of the rectangles 
	int S_left, S_right, S_top, S_bottom, S_height;
	int V_left, V_right, V_top, V_bottom;
	int W_left, W_right, W_top, W_bottom, W_base_point;
	int Y_left, Y_right, Y_top, Y_bottom;
	
	int Tracking = 0;

	//Calculate the sides of rect S
	S_left = S.x; 
	S_right = S.x + S.w; 
	S_top = S.y; 
	S_bottom = S.y + S.h; 
	S_height = S.front_cliff;

	//Calculate the sides of rect V 
	V_left = V.x; 
	V_right = V.x + V.w; 
	V_top = V.y; 
	V_bottom = V.y + V.h; 

	//Calculate the sides of rect W
	W_left = W.x; 
	W_right = W.x + W.w; 
	W_top = W.y; 
	W_bottom = W.y + W.h; 
	W_base_point = W.front_cliff;

	//Calculate the sides of rect V 
	Y_left = Y.x; 
	Y_right = Y.x + Y.w; 
	Y_top = Y.y; 
	Y_bottom = Y.y + Y.h; 


	//if (returner == 0)
	//{
		if(( W_bottom >= V_top ) &&(W_top < V_bottom  ) &&( W_right >= V_left ) && ( W_left <= V_right ) )
		{ 
			Tracking = W_base_point - V_top -  W.h/2;
			if (Y_top <= S_top + Tracking)
			{
				
				return  S_top + Tracking  ;
			}
		} 
	//}

	//Shadow at the base. Might be used later for game mechanic Ideas
	/*if (returner == 1)
	{
		if(( W_bottom >= V_top ) &&(W_top < V_bottom  ) &&( W_right >= V_left ) && ( W_left <= V_right ) )
		{ 
			Tracking = W_base_point - V_top;
			if (Y_top <= V_top - Tracking)
			{
				
				return  V_top + Tracking - S_height - 1 ;
			}
		} 
	}*/
	 // May be upgraded later. Collision for circles yo be added later.                                                      
	 return -1; 
}
bool Transparent_Enable(Square W, Square Y, Square V, Square S)
{
	//The sides of the rectangles 
	int W_left, W_right, W_top, W_bottom;
	int Y_left, Y_right, Y_top, Y_bottom;
	

	int V_left, V_right, V_top, V_bottom;
	int S_left, S_right, S_top, S_bottom;
	
	//Calculate the sides of rect W
	W_left = W.x; 
	W_right = W.x + W.w; 
	W_top = W.y; 
	W_bottom = W.y + W.h; 


	//Calculate the sides of rect V 
	Y_left = Y.x; 
	Y_right = Y.x + Y.w; 
	Y_top = Y.y; 
	Y_bottom = Y.y + Y.h; 

	//Calculate the sides of rect V 
	V_left = V.x; 
	V_right = V.x + V.w; 
	V_top = V.y; 
	V_bottom = V.y + V.h; 


	//Calculate the sides of rect S
	S_left = S.x; 
	S_right = S.x + S.w; 
	S_top = S.y; 
	S_bottom = S.y + S.h; 


	
	


	if (W_bottom < V_top )
	{
		if ((Y_bottom >= S_top ) && (Y_top <= S_bottom) && (Y_left <= S_right) && (Y_right  >= S_left))
		{
			return true;
		}
	}


	return false;


}

//Before deletion study for future uses//////////////////////////////////////////////////////
/*bool Load_New_Level_Loader_Objects(External_Configuration *object[])
{
	// Erase the level's Exit tiles.
	for (int tz = 0; tz < MAX_LEVEL_EXIT_OBJECTS; tz++)
	{
		if (object[tz] == NULL)
		{
			break;
		}

		if (object[tz] != NULL)
		{
			delete object[ tz ];
		}

	}
	std::ifstream Load( "current_location" ); if( Load == NULL ) {Load.close();  return false; }
	
	int x = 0, y = 0, z = 0; 
	int Total_Exit_Objects;	
	int Level_Value;

	//Name of the level
    std::string Level;
	std::string  READ_FILE;

	getline( Load, READ_FILE);	
	getline( Load, Level );

	// Level value is to make the code flexible
	Level_Value = Object_Setting_Helper(Level);
	
	
	std::ifstream Lv1AExits ("Lv1AExits.map" );if( Lv1AExits == NULL ) {Lv1AExits.close();  return false; }
	std::ifstream Lv1BExits ("Lv1BExits.map" );if( Lv1AExits == NULL ) {Lv1BExits.close();  return false; }

	switch (Level_Value)
	{					
					
		case LEVEL_1_A:	Lv1AExits >> Total_Exit_Objects; break;
		case LEVEL_1_B:	Lv1BExits >> Total_Exit_Objects; break;

	}
	
	
	
	//Initialize the tiles 
	for( int t = 0; t < Total_Exit_Objects; t++ ) 
	{ 
		int TileType = -1; 
		switch (Level_Value)
		{				//MUST BE READ IN THIS ORDER NO EXCEPTIONS!	
			case LEVEL_1_A: Lv1AExits >> TileType; Lv1AExits >> x; Lv1AExits >> y; Lv1AExits >> z; break;
			case LEVEL_1_B: Lv1BExits >> TileType; Lv1BExits >> x; Lv1BExits >> y; Lv1BExits >> z; break;

		}
		//If the was a problem in reading the map 
		if( Lv1AExits.fail() == true ) 
		{ 
			//CLOSE ALL FILES
			Lv1AExits.close(); 
			Load.close();
			Lv1BExits.close(); 
			return false; 
		} 

		//If the number is a valid tile number 
		if( ( TileType >= 0 ) && ( TileType <= MAX_LEVEL_EXIT_OBJECTS ) ) 
		{ 
			
			//CRITICAL! CRITICAL! CRITICAL!!!!!! MUST BE DEALLOCATED IN CLEANUP
			object[ t ] = new External_Configuration( x, y, z, TileType); 
		} 

		//If we don't recognize the tile type 
		else 
		{ 
			//CLOSE ALL FILES
			Load.close();
			Lv1AExits.close(); 
			Lv1BExits.close(); 
			return false; 
		} 
	
	} 
	
	for( int z = Total_Exit_Objects; z < MAX_LEVEL_EXIT_OBJECTS; z++ ) 
	{
		object[ z ] = NULL;
	}
					
	                                               
	Load.close();
	Lv1AExits.close(); 
	Lv1BExits.close(); 

 return true; 
}*/
/////////////////////////////////////////////////////////////////////////////////////////////

//Generate the level during Start point of the game.
//Uses all the functions to create the world
bool Set_Objects(Soul *Spirit[], External_Configuration &config)
{
	///int Start_Num;
	int Level_Value;
    std::string Level;
	
	//Special spirits not related to the physical world manually made. Used alot and no need of duplication. 
	//KNOTE!! Everything will be it's owe object until the 2nd game's optimization. 
	Spirit[ XGHOSTX]= new Character(); 
	Spirit[ XCYRON_TANRYOKUX]= new Cyron_Tanryoku(); 
	Spirit[ XTHE_YS_GUYX]= new The_Ys_Guy(); 
	Spirit[ XCXX120X]= new Cxx120(); 

	Spirit[XRETURN_MENU_BUTTONX]= new On_Screen_Config_Object(450, 20, RETURN_MENU_BUTTON); 
	Spirit[XSWITCH_MENU_BUTTONX]= new On_Screen_Config_Object(450, 100, SWITCH_MENU_BUTTON); 
	Spirit[XSWITCH_MENU_BUTTON_EXPAND1X]= new On_Screen_Config_Object(275, 100, SWITCH_MENU_BUTTON_EXPAND1); 
	Spirit[XSAVE_MENU_BUTTONX]= new On_Screen_Config_Object(450, 180, SAVE_MENU_BUTTON); 
	Spirit[XCYRON_GAUGEX]= new On_Screen_Object(0, 360, CYRON_GAUGE); 
	Spirit[XYS_GAUGEX]= new On_Screen_Object(0, 360, YS_GAUGE); 
	Spirit[XCXX120_GAUGEX]= new On_Screen_Object(0, 360, CXX120_GAUGE); 
	Spirit[XTARGET_REDICALX ]= new On_Screen_Object(0, 0, TARGET_REDICAL); 
	Spirit[XHEALTH_BARX ]= new On_Screen_Object(30, 463, HEALTH_BAR); 
	
	Spirit[ XBITMAP_TEXT_STARTX] = new Bitmap_Text_Pool_Object(0,0,0, YstarFont);
	Spirit[ XBITMAP_TEXT2X] = new Bitmap_Text_Pool_Object(0,0,0, YstarFont);
//	Spirit[ XBITMAP_TEXT3X] = new Bitmap_Text_Object(0,0,0, YstarFont);
	Spirit[ XBITMAP_TEXT_ENDX] = new Bitmap_Text_Pool_Object(0,0,0, YstarFont);

	Spirit[XBLACK_BGX]= new On_Screen_BG_Object(0, 0,  BLACK_BG); 
	



	Level = config.Get_Level_Name();	
	Level_Value = Object_Setting_Helper(Level);

	if (Pick_Start_Level(Spirit, config, Level_Value) == false)
	{
		return false;
	}



/*
	Start_Num = LAST + 1;


	//Create the world. The last element of the enum + 1
	Start_Num = Set_Floor_Objects(Start_Num, Spirit, config );
	if(Start_Num != -1) 
	{
		Start_Num = Set_Floating_Objects( Start_Num, Spirit,  config);
		if ( Start_Num != -1)
		{
			Start_Num = Set_Config_Objects( Start_Num, Spirit,  config);
			if ( Start_Num != -1)
			{


			}
		}
	}	


	//Set the remaining unused object to null. 
	for (int z = Start_Num; z <  MAX_GAME_OBJECTS; z++)
	{
		Spirit[ z ] = NULL;
	}


	if(Start_Num == -1) 
	{
		return false;
	}*/

	return true;
}
bool Pick_Start_Level(Soul *Spirit[], External_Configuration &config, int level)
{

	switch (level)
	{
		case LEVEL_1_A: if (Load_Level_LEVEL_1_A(Spirit, config, 1) == false)
						{
							return false;
						} 
			break;
		case LEVEL_1_B:  if (Load_Level_LEVEL_1_B(Spirit, config, 1 ) == false)
						{
							return false;
						} break;


	}

	for (int tz = 0; tz  <  MAX_GAME_OBJECTS; tz++)
	{
		if (Spirit[tz] == NULL)
		{
			break;
		}
			if(Spirit[ tz ]->Get_Object_Type() < AI_SMART) // Temporary testing 
			{
				Spirit[ tz ]->Move_Special_Object();
			}
	}

	return true;
}




bool Set_Grounded_Objects( Environment_Objects *object[], External_Configuration config) 
 { 
	int x = 0, y = 0, z = 0; 
	int Total_Ground_Objects;	
	int Level_Value;
	bool Failure = false; 
	bool True = true;
	//Name of the level
    std::string Level  = config.Get_Level_Name();
	
	// Level value is to make the code flexible
	Level_Value = Object_Setting_Helper(Level);
	
	
	std::ifstream Lv1AGround ("Lv1AGround.map" );if( Lv1AGround == NULL ) {Lv1AGround.close();  return false; }
	std::ifstream Lv1BGround ("Lv1BGround.map" );if( Lv1BGround == NULL ) {Lv1BGround.close();  return false; }
	switch (Level_Value)
	{					
						// Open one of these file ONLY for reading. 
		case LEVEL_1_A:	Lv1AGround >> Total_Ground_Objects; break;
		case LEVEL_1_B:	Lv1BGround >> Total_Ground_Objects; break;
	}
	
	
	
	//Initialize the tiles 
	for( int t = 0; t < Total_Ground_Objects; t++ ) 
	{ 
		int TileType = -1; 
		switch (Level_Value)
		{				//MUST BE READ IN THIS ORDER NO EXCEPTIONS!	
			case LEVEL_1_A: Lv1AGround>> TileType; Lv1AGround>> x; Lv1AGround >> y; Lv1AGround>> z; 
				if( Lv1AGround.fail() == true ) {Failure = true;} break;
			case LEVEL_1_B: Lv1BGround>> TileType; Lv1BGround>> x; Lv1BGround >> y; Lv1BGround>> z; 
 				if( Lv1BGround.fail() == true ) {Failure = true;} break;

		}
		//If the was a problem in reading the map 
		if( Failure == true ) 
		{ 
			//CLOSE ALL FILES
			Lv1AGround.close(); 
			Lv1BGround.close();
			return false; 
		} 

		//If the number is a valid tile number 
		if( ( TileType >= 0 ) && ( TileType <= GROUNDED_TILE_SPRITES ) ) 
		{ 
			object[ t ] = new Environment_Objects ( True ,x,  y,  z, TileType ); 
		} 

		//If we don't recognize the tile type 
		else 
		{ 
			//CLOSE ALL FILES
			Lv1AGround.close(); 
			Lv1BGround.close();
			return false; 
		} 
	
	} 
	
	for( int z = Total_Ground_Objects; z < MAX_GROUND_OBJECTS; z++ ) 
	{
		object[ z ] = NULL;
	}
					
	                                               

		Lv1AGround.close(); 
		Lv1BGround.close();
	

 return true; 
 } 
/*bool Set_Enemy_Objects( Enemy_Object *object[], External_Configuration config)

 { 
	int x = 0, y = 0, z = 0; 
	int Total_Enemy_Objects;	
	int Level_Value;

	bool Failure = false; 
	//Name of the level
    std::string Level  = config.Get_Level_Name();
	
	// Level value is to make the code flexible
	Level_Value = Object_Setting_Helper(Level);
	
	
	std::ifstream Lv1AEnemy ("Lv1AEnemy.map" );if( Lv1AEnemy == NULL ) {Lv1AEnemy.close();  return false; }
	//std::ifstream Lv1BFloatingXYZ ("Lv1AEnemy.map" );if( Lv1BFloatingXYZ == NULL ) {Lv1BFloatingXYZ.close();  return false; }

	switch (Level_Value)
	{					
						// Open one of these file ONLY for reading. 
		case LEVEL_1_A:	Lv1AEnemy >> Total_Enemy_Objects; break;
	//	case LEVEL_1_B:	Lv1BFloatingXYZ >> Total_Enemy_Objects; break;

	}
	
	
	
	//Initialize the tiles 
	for( int t = 0; t < Total_Enemy_Objects; t++ ) 
	{ 
		int TileType = -1; 
		switch (Level_Value)
		{				//MUST BE READ IN THIS ORDER NO EXCEPTIONS!	
			case LEVEL_1_A: Lv1AEnemy >> TileType; Lv1AEnemy >> x; Lv1AEnemy >> y; Lv1AEnemy >> z;  
				if( Lv1AEnemy.fail() == true ) { Failure = true; }break;
		//	case LEVEL_1_B: Lv1BFloatingXYZ >> TileType; Lv1BFloatingXYZ >> x; Lv1BFloatingXYZ >> y; Lv1BFloatingXYZ >> z;  
		//		if( Lv1BFloatingXYZ.fail() == true ) { Failure = true; }break;

		}
		//If the was a problem in reading the map 
		if( Failure == true ) 
		{ 
			//CLOSE ALL FILES
			Lv1AEnemy.close(); 
			//Lv1BFloatingXYZ.close(); 
			return false; 
		} 

		//If the number is a valid tile number 
		if( ( TileType >= 0 ) && ( TileType <=  ENEMY_TILE_SPRITES ) ) 
		{ 
			object[ t ] = new Enemy_Object( x,  y,  z, TileType ); 
		} 

		//If we don't recognize the tile type 
		else 
		{ 
			//CLOSE ALL FILES
			Lv1AEnemy.close();  
			//Lv1BFloatingXYZ.close(); 
			return false; 
		} 
	
	} 
	
	for( int z = Total_Enemy_Objects; z <MAX_ENEMY_OBJECTS; z++ ) 
	{
		object[ z ] = NULL;
	}
					
	                                               

		Lv1AEnemy.close(); 
		//Lv1BFloatingXYZ.close(); 
	

 return true; 
 } 
*/
void Set_Bullet_Objects( Bullet_Object *object[])
{   
	//Initialize the tiles 
	for( int t = 0; t < MAX_BULLET_OBJECTS; t++ ) 
	{ 
		object[ t ] = new Bullet_Object(); 	
	} 
} 

int Object_Setting_Helper(std::string level_name)
{	
	if (level_name == "Lv1A") {return LEVEL_1_A;}
	if (level_name == "Lv1B") {return LEVEL_1_B;}
	return -1;
}
std::string Level_Identitfier(int exit_type)
{
	int Exit_Name = exit_type;
	//std::string Level_Name;

	switch (Exit_Name)
	{
		case LV1A_1: return "Lv1A"; break;
		case LV1A_2: return "Lv1A"; break;
		case LV1A_3: return "Lv1A"; break;
		case LV1B_1: return "Lv1B"; break;
	}

	return "Secret_World";
}

int Character_Coords_Matcher(int exit_type, int returner)
{
	int Return = returner;
	int Exit_Type = exit_type;
	
	// DECIDE RATHER TO RETURN X Y OR Z COORDINATES 
	// 0 = X, 1 = Y, 2 = Z
	// Depending on the the value of the exit type detirmine the coorsponding coords/
	if (Return == 0)
	{
		// USE THE
		switch (Exit_Type)
		{
			case LV1A_1: return X_LV1A_1;
			case LV1B_1: return X_LV1B_1;
		}
	}	
	
	
	if (Return == 1)
	{
		switch (Exit_Type)
		{
			case LV1A_1: return Y_LV1A_1;
			case LV1B_1: return Y_LV1B_1;
		}
	}	
	
	
	if (Return == 2)
	{
		switch (Exit_Type)
		{
			case LV1A_1: return Z_LV1A_1;
			case LV1B_1: return Z_LV1B_1;
		}
	}	
	

	return 0;
}
bool Write_Current_Location(int Exit, std::string level_name, int x, int y, int z)
{

	std::ofstream Load( "current_location" );
	if( Load == NULL ){ return false;}

	Load << "Level_Name \n";
	Load << level_name;
	Load << "\n \n" ;
	Load <<"Exit_Type \n";
	Load << Exit;
	Load << "\n \n" ;
	Load <<"Character_Coord \n";
	Load << x;
	Load << " ";
	Load << y;
	Load << " ";
	Load << z;
	Load << " ";


	Load.close();

	return true;
}
bool Write_Save_Game_Pad(Soul *Spirit[])
{

	//Saving the game is a complex problem. Certain things will be as clear as day but character health and 
	// Other dispoable stats will be encyrted in binary without mentions what they are. Hacker will hack but 
	// Average players will not
	////////////////////////////////////////////////////////////
	//DECLARATIONS
	////////////////////////////////////////////////////////////
	int x, y, z;
	int Health = 0;

	std::string READ_FILE;	
	std::string Level_Name;

	std::ofstream Load( "game_save_pad" );
	if( Load == NULL ){ return false;}
	std::ifstream Read( "current_location ");
	if( Read == NULL ){ return false;}


	x = Spirit[Selected_Spirit]->Get_X();
	y = Spirit[Selected_Spirit]->Get_Y();
	z = Spirit[Selected_Spirit]->Get_Z();
	
	//Health = ??????????????

	/////////////////////////////////////////
	// READ!!!!
	////////////////////////////////////////////
	getline( Read, READ_FILE);	
	Read >> Level_Name;
	
	
	/////////////////////////////////////////
	// WRITE!!!!!
	////////////////////////////////////////////
	

	Load << "LEVEL_NAME\n";
	Load <<  Level_Name;
	Load << "\n \n" ;
	Load <<"CHARACTER_COORD\n";
	Load << x;
	Load << " ";
	Load << y;
	Load << " ";
	Load << z;
	Load << " ";
	Load << "\n \n" ;
	Load <<"CHARACTER_HEALTH\n";
	Load << Health;

	Load.close();
	Read.close();
	return true;
}

double Distance( int x1, int y1, int x2, int y2 )
{
	int Squared_x = x2 - x1;
	int Squared_y = y2 - y1;
	
	double value;
	value = sqrt(((double)(x2 - x1)* Squared_x) + ((double)(y2 - y1)* Squared_y));
   
	//Return the distance between the two points
    //ORIGINAL // return sqrt(((int)(x2 - x1)* Squared_x) + ((int)(y2 - y1)* Squared_y));
	return value;
}
double Direction(int x1, int y1, int x2, int y2)
{
	//Unit circle
	//Oppositie wall / adjacent floor. 
	double Value;
	int Adj, Opp;
	double Hyp;

	if (x1 <= x2){ Adj = x2 - x1;}
	else{ Adj = x1 - x2;}

	if (y1 <= y2){ Opp = y1 - y2;}
	else {Opp = y2 - y1;}

	Hyp = Opp/Adj;

	Value = atan(Hyp);
	
	return Value;
}

// All purpose square on sqyuare collsion detection. Used by the enviroment. 
bool Square_Object_Detection(Square V, Square S )
{


	//The sides of the rectangles 
	int S_left, S_right, S_top, S_bottom;
	int V_left, V_right, V_top, V_bottom;

	


	//Calculate the sides of rect S
	S_left = S.x; 
	S_right = S.x + S.w; 
	S_top = S.y; 
	S_bottom = S.y + S.h; 
	
	//Calculate the sides of rect V 
	V_left = V.x; 
	V_right = V.x + V.w; 
	V_top = V.y; 
	V_bottom = V.y + V.h; 

	//When the character jumps on top of a block
	if(( S_bottom >= V_top ) &&(S_top < V_bottom  ) &&( S_right >= V_left ) && ( S_left <= V_right ) )
	{ 
		return true; 
	} 

	 // May be upgraded later. Collision for circles yo be added later.                                                      
	 return false; 
}


int Tracking(int returner, Square character_base, Square square_base)
{
	enum {RETURN_UPPER, RETURN_BOTTOM};
	//The sides of the rectangles 
	int Square_Base_Left, Square_Base_Right, Square_Base_Top, Square_Base_Bottom, Square_Base_Front_Cliff;
	
	//The Character's based
	int Character_Base_Left, Character_Base_Right, Character_Base_Top, Character_Base_Bottom, Character_Base_Point;
	
	int Starting_Point_One, Starting_Point_Two;

	// Track the player's movement on an rectangle
	int Upper_Track, Bottom_Track;

	int Returner;

	/************************************************************
	//					DEFINING OF ALL VARIABLES			   //
	************************************************************/
	//Calculate the sides of rect A 
	Square_Base_Left = square_base.x; 
	Square_Base_Right = square_base.x + square_base.w; 
	Square_Base_Top = square_base.y; 
	Square_Base_Bottom = square_base.y + square_base.h; 
	Square_Base_Front_Cliff = square_base.front_cliff;

	Character_Base_Left = character_base.x;
	Character_Base_Right = character_base.x + character_base.w;
	Character_Base_Top = character_base.y;
	Character_Base_Bottom = character_base.y + character_base.h;
	Character_Base_Point = character_base.front_cliff;
	
	Starting_Point_One = Square_Base_Top - CHARACTER_LENGHT;
	Starting_Point_Two = Square_Base_Bottom + CHARACTER_LENGHT;

	Upper_Track = Character_Base_Point - Starting_Point_One;
	Bottom_Track = Starting_Point_Two - Character_Base_Point;  

	Returner = returner;
	/************************************************************
	//						RETURNING						   //
	************************************************************/

	switch (Returner)
	{
		case RETURN_UPPER: return Upper_Track; break;
		case RETURN_BOTTOM: return Bottom_Track; break;
	}

	return -1; 

}



//GROUNDED AURGUMENT TO BE ADDED SOON....
int Base_Object_Detection(Square character_base, Square character_cornice, Square square_base)
{
	/************************************************************
	//		DECLARATION OF ALL VARIBLES FOR THIS FUNCTION	   //
	************************************************************/
	

	//The sides of the rectangles 
	int Square_Base_Left, Square_Base_Right, Square_Base_Top, Square_Base_Bottom, Square_Base_Front_Cliff;

	//The character defined
	int Character_Cornice_Left, Character_Cornice_Right, Character_Cornice_Top, Character_Cornice_Bottom;
	
	//The Character's based
	int Character_Base_Left, Character_Base_Right, Character_Base_Top, Character_Base_Bottom, Character_Base_Point;
	
	/************************************************************
	//					DEFINING OF ALL VARIABLES			   //
	************************************************************/
	//Calculate the sides of rect A 
	Square_Base_Left = square_base.x; 
	Square_Base_Right = square_base.x + square_base.w; 
	Square_Base_Top = square_base.y; 
	Square_Base_Bottom = square_base.y + square_base.h; 
	Square_Base_Front_Cliff = square_base.front_cliff;

	//Calculate the side of the character's square
	Character_Cornice_Left = character_cornice.x;	
	Character_Cornice_Right = character_cornice.x + character_cornice.w;
	Character_Cornice_Top = character_cornice.y;
	Character_Cornice_Bottom = character_cornice.y + character_cornice.h;

	Character_Base_Left = character_base.x;
	Character_Base_Right = character_base.x + character_base.w;
	Character_Base_Top = character_base.y;
	Character_Base_Bottom = character_base.y + character_base.h;
	Character_Base_Point = character_base.front_cliff;

	
	/************************************************************
	//						CALCULATIONS					   //
	************************************************************/

	//1st Condition. Check the collision of grounded objects with the character base //To be added
	//2nd Condition. Check the collision of the character with his/her "base" OR floor //Complete!
	//3rd Condition. Check the collision of an base enivornment object and the character's base //Currently working

	//2ND CONDITION. 
	if ( Character_Base_Point <= Character_Cornice_Bottom )  
	{ 
		// Even while on the ground check for collision before confirming as grounded.
		if (( Character_Base_Top <= Square_Base_Bottom ) && ( Character_Base_Bottom >= Square_Base_Top ) && ( Character_Base_Left <= Square_Base_Right) &&(Character_Base_Right >= Square_Base_Left)) 
		{
			return GROUND_OBJECT_TOUCH;
		}
		return GROUNDED; 
	} 

	//3RD CONDITION.
	if (( Character_Base_Top <= Square_Base_Bottom ) && ( Character_Base_Bottom >= Square_Base_Top ) && ( Character_Base_Left <= Square_Base_Right) &&(Character_Base_Right >= Square_Base_Left)) 
	{ 
		return BASE_OBJECT_TOUCH; 
	} 

	//4TH CONDITIONS
	return MIDAIR ; 
}


int Object_Detection_Above_Below(int track_a, int track_b, Square character_cornice, Square square)
{
	
	/************************************************************
	//		DECLARATION OF ALL VARIBLES FOR THIS FUNCTION	   //
	************************************************************/
	


	//The sides of the rectangles 
	int Square_Left, Square_Right, Square_Top, Square_Bottom, Square_Front_Cliff, Square_Back_Cliff;

	//The character defined
	int Character_Cornice_Left, Character_Cornice_Right, Character_Cornice_Top, Character_Cornice_Bottom;
	
	int Upper_Starting_Point_One, Upper_Starting_Point_Two;
	int Bottom_Starting_Point_One, Bottom_Starting_Point_Two ;

	int Cornice_Height;
	int Track_A, Track_B;
	
	/************************************************************
	//					DEFINING OF ALL VARIABLES			   //
	************************************************************/
	//Calculate the sides of rect A 
	Square_Left = square.x; 
	Square_Right = square.x + square.w; 
	Square_Top = square.y; 
	Square_Bottom = square.y + square.h; 
	Square_Front_Cliff = square.y + square.front_cliff;
	Square_Back_Cliff = square.y + square.h - square.front_cliff;

	//Calculate the side of the character's square
	Character_Cornice_Left = character_cornice.x;	
	Character_Cornice_Right = character_cornice.x + character_cornice.w;
	Character_Cornice_Top = character_cornice.y;
	Character_Cornice_Bottom = character_cornice.y + character_cornice.h;

	Upper_Starting_Point_One = Square_Top - CHARACTER_LENGHT;
	Upper_Starting_Point_Two = Square_Front_Cliff + CHARACTER_LENGHT;

	Bottom_Starting_Point_One =  Square_Bottom + CHARACTER_LENGHT;
	Bottom_Starting_Point_Two =  Square_Back_Cliff - CHARACTER_LENGHT;

	Cornice_Height = (Square_Bottom - Square_Front_Cliff)/2;

	Track_A = track_a;
	Track_B = track_b;
	/************************************************************
	//						CALCULATIONS					   //
	************************************************************/
	

	//1ST. Check rather the character is below or above the rectangle
	//2nd Check  for side collisions

	//1ST. Part 1
	
	

	if(( Character_Cornice_Bottom <= Upper_Starting_Point_Two)&&(Character_Cornice_Top <= Bottom_Starting_Point_Two))
	{	
		if ((Character_Cornice_Bottom >= Upper_Starting_Point_One + Track_A + 3)&&( Character_Cornice_Left >= Square_Right - 1) && ( Character_Cornice_Left <= Square_Right))
		{
			return AGAINST_LEFT_SIDE;
		}
		if ((Character_Cornice_Bottom >= Upper_Starting_Point_One + Track_A + 2)&&( Character_Cornice_Right <= Square_Left + 1) && ( Character_Cornice_Right >= Square_Left))
		{
			return AGAINST_RIGHT_SIDE;
		}

		if ((Character_Cornice_Bottom >= Upper_Starting_Point_One + Track_A + Cornice_Height /*14*/)  && ( Character_Cornice_Left <= Square_Right) && ( Character_Cornice_Right >= Square_Left))
		{
			return INSIDE_BLOCK; 
		}
		
		if ((Character_Cornice_Bottom >= Upper_Starting_Point_One + Track_A) && (Character_Cornice_Bottom <=  Upper_Starting_Point_One + Track_A + 3/*6*/) && ( Character_Cornice_Left <= Square_Right) && ( Character_Cornice_Right >= Square_Left))
		{
			return STANDING_ON_TOP;
		}

		if ((Character_Cornice_Bottom >= Upper_Starting_Point_One + Track_A + 4/*13*/)&&(Character_Cornice_Bottom <= Upper_Starting_Point_One + Track_A + (Cornice_Height/2)/2) &&( Character_Cornice_Left <= Square_Right) && ( Character_Cornice_Right >= Square_Left))
		{
			return FALLING_THROUGH_FLOOR1; 
		}

		else if ((Character_Cornice_Bottom >= Upper_Starting_Point_One + Track_A + 4/*13*/)&&(Character_Cornice_Bottom <= Upper_Starting_Point_One + Track_A + Cornice_Height/2) &&( Character_Cornice_Left <= Square_Right) && ( Character_Cornice_Right >= Square_Left))
		{
			return FALLING_THROUGH_FLOOR2; 
		}
		else if ((Character_Cornice_Bottom >= Upper_Starting_Point_One + Track_A + 4/*13*/)&&(Character_Cornice_Bottom <= Upper_Starting_Point_One + Track_A + Cornice_Height) &&( Character_Cornice_Left <= Square_Right) && ( Character_Cornice_Right >= Square_Left))
		{
			return FALLING_THROUGH_FLOOR3; 
		}
	} 

	//1ST. Part 2
	if( Character_Cornice_Top >= Bottom_Starting_Point_Two)
	{	
		if ((Character_Cornice_Top <= Bottom_Starting_Point_Two + Track_A) && ( Character_Cornice_Left <= Square_Right) && ( Character_Cornice_Right >= Square_Left)) 
		{		
			return HIT_FROM_BELOW;
		}		
	} 


	//No collision detection while in mid air
	return 1;
}
int Object_Detection_Above_Below_Two(int track_a, int track_b,  Square character_base ,Square character_cornice, Square square)
{
	
	/************************************************************
	//		DECLARATION OF ALL VARIBLES FOR THIS FUNCTION	   //
	************************************************************/
	


	//The sides of the rectangles 
	int Square_Left, Square_Right, Square_Top, Square_Bottom, Square_Height;

	//The character defined
	int Character_Cornice_Left, Character_Cornice_Right, Character_Cornice_Top, Character_Cornice_Bottom;
	
	//The character defined
	int Character_Base_Left, Character_Base_Right, Character_Base_Top, Character_Base_Bottom, Character_Base_Point;

	int Position;

	int Track_A, Track_B;
	
	/************************************************************
	//					DEFINING OF ALL VARIABLES			   //
	************************************************************/
	//Calculate the sides of rect A 
	Square_Left = square.x; 
	Square_Right = square.x + square.w; 
	Square_Top = square.y; 
	Square_Bottom = square.y + square.h; 
	Square_Height = square.front_cliff;


	//Calculate the side of the character's square
	Character_Cornice_Left = character_cornice.x;	
	Character_Cornice_Right = character_cornice.x + character_cornice.w;
	Character_Cornice_Top = character_cornice.y;
	Character_Cornice_Bottom = character_cornice.y + character_cornice.h;

	//Calculate the side of the character's square
	Character_Base_Left = character_base.x;	
	Character_Base_Right = character_base.x + character_base.w;
	Character_Base_Top = character_base.y;
	Character_Base_Bottom = character_base.y + character_base.h;
	Character_Base_Point = character_base.front_cliff;


	Track_A = track_a;
	Track_B = track_b;

	Position = (Square_Top - CHARACTER_LENGHT) + Track_A;
	/************************************************************
	//						CALCULATIONS					   //
	************************************************************/
	

	//1ST. Check rather the character is below or above the rectangle
	//2nd Check  for side collisions

	//1ST. Part 1
	
	

	if ((Character_Base_Point >= Square_Top) &&(Character_Base_Point <= Square_Bottom)&&( Character_Base_Left <= Square_Right) && ( Character_Base_Right >= Square_Left))
	{
			if ((Character_Cornice_Bottom >= Position - Square_Height)&&( Character_Cornice_Left <= Square_Right) && ( Character_Cornice_Left >= Square_Right - 4) )
			{
				return AGAINST_LEFT_SIDE;
			}
			if ((Character_Cornice_Bottom >= Position - Square_Height)&&( Character_Cornice_Right >= Square_Left ) && ( Character_Cornice_Right <= Square_Left + 4))
			{
				return AGAINST_RIGHT_SIDE;
			}
		//( Character_Cornice_Left <= Square_Right) && ( Character_Cornice_Right <= Square_Left)&& (Track_A >= 5))
		/*	if ((Character_Cornice_Bottom >= Position - Square_Height) && ( Character_Cornice_Left <= Square_Right - 3) && ( Character_Cornice_Right >= Square_Left)&& (Track_A >= 5))
			{
				return STANDING_ON_TOP;
			}
			
			else if ((Character_Cornice_Bottom >= Position - Square_Height) && ( Character_Cornice_Left <= Square_Right ) && ( Character_Cornice_Right >= Square_Left + 3)&& (Track_B >=  5))
			{
				return STANDING_ON_TOP;
			}

			if ((Character_Cornice_Bottom >= Position - Square_Height + 1)&& ( Character_Cornice_Left <= Square_Right) &&  ( Character_Cornice_Right >= Square_Left)&& (Track_A >=  5))
			{
				return FALLING_THROUGH_FLOOR; 
			}
			else if ((Character_Cornice_Bottom >= Position - Square_Height + 1)&& ( Character_Cornice_Left <= Square_Right) &&  ( Character_Cornice_Right >= Square_Left)&& (Track_B >=  5))
			{
				return FALLING_THROUGH_FLOOR; 
			}*/

			if ((Character_Cornice_Bottom >= Position - Square_Height) && ( Character_Cornice_Left <= Square_Right - 3) && ( Character_Cornice_Right >= Square_Left)&& (Track_A >= 2))
			{
				return STANDING_ON_TOP;
			}
			
			else if ((Character_Cornice_Bottom >= Position - Square_Height) && ( Character_Cornice_Left <= Square_Right ) && ( Character_Cornice_Right >= Square_Left + 3)&& (Track_B >=  2))
			{
				return STANDING_ON_TOP;
			}

			if ((Character_Cornice_Bottom >= Position - Square_Height + 1)&& ( Character_Cornice_Left <= Square_Right) &&  ( Character_Cornice_Right >= Square_Left)&& (Track_A >=  2))
			{
				return FALLING_THROUGH_FLOOR3; 
			}
			else if ((Character_Cornice_Bottom >= Position - Square_Height + 1)&& ( Character_Cornice_Left <= Square_Right) &&  ( Character_Cornice_Right >= Square_Left)&& (Track_B >=  2))
			{
				return FALLING_THROUGH_FLOOR3; 
			}
	}

	//No collision detection while in mid air
	return MIDAIR;
}

int Object_Detection_Front_Back(int track_a, int track_b, Square character_cornice, Square square)
{
	/************************************************************
	//		DECLARATION OF ALL VARIBLES FOR THIS FUNCTION	   //
	************************************************************/

	//The sides of the rectangles 
	int Square_Left, Square_Right, Square_Top, Square_Bottom, Square_Front_Cliff, Square_Back_Cliff;

	//The character defined
	int Character_Cornice_Left, Character_Cornice_Right, Character_Cornice_Top, Character_Cornice_Bottom;
	
	int Upper_Starting_Point_One, Upper_Starting_Point_Two;
	int Bottom_Starting_Point_One, Bottom_Starting_Point_Two ;

	int Track_A, Track_B;
	
	/************************************************************
	//					DEFINING OF ALL VARIABLES			   //
	************************************************************/
	//Calculate the sides of rect A 
	Square_Left = square.x; 
	Square_Right = square.x + square.w; 
	Square_Top = square.y; 
	Square_Bottom = square.y + square.h; 
	Square_Front_Cliff = square.y + square.front_cliff;
	Square_Back_Cliff = square.y + square.h - square.front_cliff;

	//Calculate the side of the character's square
	Character_Cornice_Left = character_cornice.x;	
	Character_Cornice_Right = character_cornice.x + character_cornice.w;
	Character_Cornice_Top = character_cornice.y;
	Character_Cornice_Bottom = character_cornice.y + character_cornice.h;

	Upper_Starting_Point_One = Square_Top - CHARACTER_LENGHT;
	Upper_Starting_Point_Two = Square_Front_Cliff + CHARACTER_LENGHT;

	Bottom_Starting_Point_One =  Square_Bottom + CHARACTER_LENGHT;
	Bottom_Starting_Point_Two =  Square_Back_Cliff - CHARACTER_LENGHT;

	Track_A = track_a;
	Track_B = track_b;
	/************************************************************
	//						CALCULATIONS					   //
	************************************************************/
	

	//1ST. Check rather the character is below or above the rectangle


	//1ST. Part 1
	//When the character hit a block from below
	if(( Character_Cornice_Bottom <= Square_Bottom) && ( Character_Cornice_Bottom >= Square_Front_Cliff + 4)&&( Character_Cornice_Right >= Square_Left ) && ( Character_Cornice_Left <= Square_Right )&& (Track_B < 10) )
	{ 
		return AGAINST_FRONT; 
	} 

	//When the character hit a block from below
	if(( Character_Cornice_Bottom <= Square_Back_Cliff) && ( Character_Cornice_Bottom >= Square_Top)&&( Character_Cornice_Right >= Square_Left ) && ( Character_Cornice_Left <= Square_Right )&& (Track_A < 10) )
	{ 
		return AGAINST_BACK; 
	} 



	//No collision detection while in mid air
	return MIDAIR;
}
int Object_Detection_Front_Back_Two(int track_a, int track_b, int pre_collision, Square character_base ,Square character_cornice, Square square)
{
	/************************************************************
	//		DECLARATION OF ALL VARIBLES FOR THIS FUNCTION	   //
	************************************************************/

	//The sides of the rectangles 
	int Square_Left, Square_Right, Square_Top, Square_Bottom, Square_Front_Cliff;

	//The character defined
	int Character_Cornice_Left, Character_Cornice_Right, Character_Cornice_Top, Character_Cornice_Bottom;
	int Character_Base_Left, Character_Base_Right, Character_Base_Top, Character_Base_Bottom, Character_Base_Point;


	int Track_A, Track_B;
	
	/************************************************************
	//					DEFINING OF ALL VARIABLES			   //
	************************************************************/
	//Calculate the sides of rect A 
	Square_Left = square.x; 
	Square_Right = square.x + square.w; 
	Square_Top = square.y; 
	Square_Bottom = square.y + square.h; 
	Square_Front_Cliff = square.front_cliff;
	
	//Calculate the side of the character's square
	Character_Cornice_Left = character_cornice.x;	
	Character_Cornice_Right = character_cornice.x + character_cornice.w;
	Character_Cornice_Top = character_cornice.y;
	Character_Cornice_Bottom = character_cornice.y + character_cornice.h;

	//Calculate the side of the character's square
	Character_Base_Left = character_base.x;	
	Character_Base_Right = character_base.x + character_base.w;
	Character_Base_Top = character_base.y;
	Character_Base_Bottom = character_base.y + character_base.h;
	Character_Base_Point = character_base.front_cliff;


	Track_A = track_a;
	Track_B = track_b;
	/************************************************************
	//						CALCULATIONS					   //
	************************************************************/
	


	// ORIGINAL CODE, CURRENTLY TESTING AGAIN FOR IMPROVEMENTS
	//1ST. Check rather the character is below or above the rectangle
	if (pre_collision == GROUND_OBJECT_TOUCH)
	{

		if(( Character_Base_Point <= Square_Bottom)&&( Character_Base_Point >= Square_Bottom - 1)&& (Character_Cornice_Right >= Square_Left ) && ( Character_Cornice_Left <= Square_Right ))
		{ 
			if(( Character_Cornice_Bottom <= Square_Bottom) && ( Character_Cornice_Bottom >= Square_Bottom - Square_Front_Cliff))
			{
				//if (Character_Cornice_Bottom )
				return GROUND_AGAINST_FRONT;
			}
		} 
		else if(( Character_Base_Point <= Square_Bottom)&&( Character_Base_Point >= Square_Bottom - 5)&&( Character_Cornice_Right >= Square_Left ) && ( Character_Cornice_Left <= Square_Right ))
		{ 
			if(( Character_Cornice_Bottom <= Square_Bottom) && ( Character_Cornice_Bottom >= Square_Bottom - Square_Front_Cliff))
			{
				return GROUND_INSIDE_FRONT; 
			}
		} 

		////////////////////////////
		/////////////////////////////////////
		//////////////////////////////////////////////
		///////////////////////////////////////////////////////


		if(( Character_Base_Point >= Square_Top - 2) && ( Character_Base_Point  <= Square_Top )&&( Character_Cornice_Right >= Square_Left ) && ( Character_Cornice_Left <= Square_Right )  )
		{ 
			if(( Character_Cornice_Bottom <= Square_Top) && ( Character_Cornice_Bottom >= Square_Top - Square_Front_Cliff))
			{
				return GROUND_AGAINST_BACK; 
			}
		} 
		else if(( Character_Base_Point  >= Square_Top -2  ) &&( Character_Base_Point <= Square_Top + 1)&&( Character_Cornice_Right >= Square_Left ) && ( Character_Cornice_Left <= Square_Right ) )
		{ 
			if(( Character_Cornice_Bottom <= Square_Top  ) && ( Character_Cornice_Bottom >= Square_Top - Square_Front_Cliff))
			{
				return GROUND_INSIDE_BACK; 
			}
		} 
	}













	if (pre_collision == BASE_OBJECT_TOUCH)
	{

		if(( Character_Base_Point <= Square_Bottom + 1)&&( Character_Base_Point >= Square_Bottom - 1)&& (Character_Cornice_Right >= Square_Left ) && ( Character_Cornice_Left <= Square_Right ) )
		{ 
			if(( Character_Cornice_Bottom <= Square_Bottom  + 1) && ( Character_Cornice_Bottom >= Square_Bottom - Square_Front_Cliff))
			{
				//if (Character_Cornice_Bottom )
				return AGAINST_FRONT;
			}
		} 
		else if(( Character_Base_Point <= Square_Bottom + 1)&&( Character_Base_Point >= Square_Bottom - 5)&&( Character_Cornice_Right >= Square_Left ) && ( Character_Cornice_Left <= Square_Right ))
		{ 
			if(( Character_Cornice_Bottom <= Square_Bottom + 1) && ( Character_Cornice_Bottom >= Square_Bottom - Square_Front_Cliff))
			{
				return INSIDE_FRONT; 
			}
		} 

		////////////////////////////
		/////////////////////////////////////
		//////////////////////////////////////////////
		///////////////////////////////////////////////////////


		if(( Character_Base_Point >= Square_Top - 2) && ( Character_Base_Point <= Square_Top)&&( Character_Cornice_Right >= Square_Left ) && ( Character_Cornice_Left <= Square_Right ) )
		{ 
			if(( Character_Cornice_Bottom <= Square_Top) && ( Character_Cornice_Bottom >= Square_Top - Square_Front_Cliff))
			{
				return AGAINST_BACK; 
			}
		} 
		else if(( Character_Base_Point >= Square_Top -2) &&( Character_Base_Point <= Square_Top + 1 )&&( Character_Cornice_Right >= Square_Left ) && ( Character_Cornice_Left <= Square_Right ))
		{ 
			if(( Character_Cornice_Bottom <= Square_Top ) && ( Character_Cornice_Bottom >= Square_Top - Square_Front_Cliff))
			{
				return INSIDE_BACK; 
			}
		} 
	}


	//No collision detection while in mid air
	return MIDAIR;
}


int Collision_Detection(Square Base, Square Cornice, Soul *Spirit[])
{
/*	

	//What the character's base is touching
	int Base_Collision;

	//What's returned.
	int Collision_Value;

	//Tracking the player
	int Upper_Tracked, Bottom_Tracked;
	

	for (int i = 0; i < SMAX_GAME_OBJECTS; i++)
	{
		if (Spirit[i] != NULL) // The array will always be 200 but not everything gets used. the remainder are pointed to null.
		{
			if(Spirit[i]-> Get_Object_Type() == FLOAT )
			{
				Base_Collision = Base_Object_Detection(Base, Cornice, Spirit[i]->Get_Objects_Base());
			
				switch (Base_Collision)
				{
					case MIDAIR: break;
					case BASE_OBJECT_TOUCH: 			
					
						Upper_Tracked = Tracking(0, Base, Spirit[i]->Get_Objects_Base());
						Bottom_Tracked = Tracking(1, Base, Spirit[i]->Get_Objects_Base());
						
							if (Object_Detection_Front_Back(Upper_Tracked, Bottom_Tracked , Cornice, Spirit[i]->Get_Objects())!= MIDAIR)
							{
								Collision_Value = Object_Detection_Front_Back(Upper_Tracked, Bottom_Tracked , Cornice, Spirit[i]->Get_Objects());
								return Collision_Value;
							}

							if (Object_Detection_Above_Below(Upper_Tracked, Bottom_Tracked,  Cornice, Spirit[i]->Get_Objects())!= MIDAIR)
							{
								Collision_Value = Object_Detection_Above_Below(Upper_Tracked, Bottom_Tracked , Cornice, Spirit[i]->Get_Objects());
								return Collision_Value;
							}
				}
			
			}
		}

		if (Spirit[i] == NULL)
		{
			//End the cycle!  There are no Collisions. 
			return MIDAIR;
		}
	}

	*/
	return MIDAIR; // No collision
}

// Collsion detection used for grounded object and maybe ect
int Collision_Detection_Two( Square Base, Square Cornice, Environment_Objects *object[])
{

	//What's returned.
	int Collision_Value;
	int Pre_Collision;
	//Tracking the player
	int Upper_Tracked, Bottom_Tracked;
	

	for (int i = 0; i < MAX_GROUND_OBJECTS; i++)
	{
		
		if (object[i] != NULL) // The array will always be 200 but not everything gets used. the remainder are pointed to null.
		{		
			if (Base_Object_Detection(Base, Cornice, object[i]->Get_Ground_Square_Objects()) != MIDAIR)
			{
					Upper_Tracked = Tracking(0, Base, object[i]->Get_Ground_Square_Objects());
					Bottom_Tracked = Tracking(1, Base, object[i]->Get_Ground_Square_Objects());
						
					Pre_Collision = Base_Object_Detection(Base, Cornice, object[i]->Get_Ground_Square_Objects());


					if (Object_Detection_Front_Back_Two(Upper_Tracked, Bottom_Tracked , Pre_Collision, Base, Cornice, object[i]->Get_Ground_Square_Objects())!= MIDAIR)
					{
						Collision_Value = Object_Detection_Front_Back_Two(Upper_Tracked, Bottom_Tracked , Pre_Collision ,Base, Cornice, object[i]->Get_Ground_Square_Objects());
						return Collision_Value;
					}

					if (Object_Detection_Above_Below_Two(Upper_Tracked,Bottom_Tracked, Base, Cornice, object[i]->Get_Ground_Square_Objects())!= MIDAIR)
					{
						Collision_Value = Object_Detection_Above_Below_Two(Upper_Tracked,Bottom_Tracked, Base,Cornice, object[i]->Get_Ground_Square_Objects());
						return Collision_Value;
					}
			}

		}
		

		if (object[i] == NULL)
		{
			//End the cycle!  There are no Collisions. 
			return MIDAIR;
		}
	}



	
	return MIDAIR; // No collision
}


/*bool Exit_Object_Collision(Square Base, Square Cornice, External_Configuration *objects[])
{
	
	
	int Exit_Type;
	std::string Level_Name;
	int Coordx, Coordy, Coordz;

	//What the character's base is touching
	bool Base_Collision = false, Collision_Value  = false;


	for (int i = 0; i < MAX_LEVEL_EXIT_OBJECTS; i++)
	{
		
		if (objects[i] != NULL) // The array will always be 200 but not everything gets used. the remainder are pointed to null.
		{
			// Record the info but only apply it when there is a collision
			Exit_Type = objects[i]-> Get_Exit_Type();
			Level_Name = Level_Identitfier(Exit_Type);
			Base_Collision = Square_Object_Detection(Base, objects[i]->Get_Exit_Base() );
			
			Coordx = Character_Coords_Matcher(Exit_Type, 0);
			Coordy = Character_Coords_Matcher(Exit_Type, 1);
			Coordz = Character_Coords_Matcher(Exit_Type, 2);




			switch (Base_Collision)
			{
				case true:	Collision_Value = Square_Object_Detection(Cornice, objects[i]->Get_Exit() );
							if( Collision_Value == true)
							{
								Write_Current_Location(Exit_Type, Level_Name, Coordx, Coordy, Coordz);
								return 	Collision_Value;
							}break;
				case false: break;		
			}
		}
		if (objects[i] == NULL)
		{
			//End the cycle!  There are no Collisions. 
			return false;
		}
	}



	
	return false; // No collision
}
*/

/*//FUNCTIONS MADE FOR CALLING THE ENEMY OR AI OBJECTS WITHOUT CHARACTER INTERVESION
void AI_Handling_Variable_Refresh(Enemy_Object *foe[],  Physics p_data, External_Configuration C, Environment_Objects *object[], Environment_Objects *ground_object[], Uint32 deltaTicks)
{
	for (int i = 0; i < MAX_ENEMY_OBJECTS; i++)
	{
		
		if (foe[i] != NULL) 
		{
			foe[i]->Enemy_Detection_Variable_Refresh(p_data,C, object, ground_object, deltaTicks);
		}

		if (foe[i] == NULL) 
		{
			break;
		}
	}
}
void AI_Handling_Movement_Active(Enemy_Object *foe[], Uint32 deltaTicks)
{
	for (int i = 0; i < MAX_ENEMY_OBJECTS; i++)
	{
		
		if (foe[i] != NULL) 
		{
			foe[i]->Enemy_Movement_Active(deltaTicks);
		}

		if (foe[i] == NULL) 
		{
			break;
		}
	}

}
void AI_Handling_Basic_Actions(Enemy_Object *foe[], Character data)
{
	for (int i = 0; i < MAX_ENEMY_OBJECTS; i++)
	{
		
		if (foe[i] != NULL) 
		{
			foe[i]->Enemy_Basic_Actions(data);
		}

		if (foe[i] == NULL) 
		{
			break;
		}
	}
}
void AI_Handling_Behavior_Controller(Enemy_Object *foe[], Character data, Uint32 deltaTicks)
{
	for (int i = 0; i < MAX_ENEMY_OBJECTS; i++)
	{
		
		if (foe[i] != NULL) 
		{
			foe[i]->Enemy_Behavior_Controller( data, deltaTicks);
		}

		if (foe[i] == NULL) 
		{
			break;
		}
	}

}
*/
//ALL FUNCTION FOR USING BULLETS
void Projectile_Active(Bullet_Object *bullet[], Uint32 deltaTicks)
{
	for (int i = 0; i < MAX_BULLET_OBJECTS; i++)
	{
		
		if (bullet[i]->Get_Active() == true) 
		{
			 bullet[i]->Bullet_Type_Assigner(deltaTicks);
		}

		if (bullet[i]->Get_Active() == false) 
		{
			break;
		}
	}
}
void Projectile_Definer(Bullet_Object *bullet[], int type, int x, int y, int z ,int lenght, int width, int height, int time)
{
	for (int i = 0; i < MAX_BULLET_OBJECTS; i++)
	{
		if (bullet[i]->Get_Active() == false) 
		{
			bullet[i]->Bullet_Definer( type,  x,  y, z ,lenght,width,height,time);
		}

	}
}



void Game_Start_Soul(Soul *Spirit[], External_Configuration config)
{
	for (int a = 0; a < MAX_GAME_OBJECTS ; a++ )
	{
		if (Spirit[a] == NULL)
		{
			break;
		}
		Spirit[a]->Game_Start(config);

	}
}

// All functions below this point are capable of sin against programming jesus.... they use and alter global variables.
int Button_Command()
{	
	
	if(event.type == SDL_KEYDOWN ) 
	{ 
		
		//Adjust the velocity 
		switch( event.key.keysym.sym ) 
		{ 
			case SDLK_UP: 	 Up_Key = true; break; 	
			case SDLK_DOWN:  Down_Key = true;  break; 
			case SDLK_LEFT:  Left_Key = true; break; 
			case SDLK_RIGHT: Right_Key = true;  break; 
			case SDLK_SPACE: Space_Key = true;  break;
			case SDLK_z:     Z_Key = true; break;
			case SDLK_x:	 X_Key = true; break;
			case SDLK_c:	 C_Key = true; break;
		} 
	} 
	//If a key was released 
	else if(( event.type == SDL_KEYUP ))
	{ 
	
		//Adjust the velocity 
		switch( event.key.keysym.sym ) 
		{ 
			case SDLK_UP: 	 Up_Key = false; break; 	
			case SDLK_DOWN:  Down_Key = false; break; 
			case SDLK_LEFT:  Left_Key = false; break; 
			case SDLK_RIGHT: Right_Key = false; break; 
			case SDLK_SPACE: Space_Key = false; break;
			case SDLK_z:     Z_Key = false; break;
			case SDLK_x:	 X_Key = false; break;
			case SDLK_c:	 C_Key = false; break;
		} 
	}
	
	//Button Delay signals. Only arrow keys for now.
	if(((Up_Key == true)&&(Left_Key == true))||((Up_Key == true)&&(Right_Key == true))||((Down_Key == true)&&(Left_Key == true))||((Down_Key == true)&&(Right_Key == true)))
	{
		Button_Delay = true;
	}
	if (Button_Delay == true)
	{
		Button_Delay_Timer += 60 *(Button_Timer_Value / 1000.f );
		if (Button_Delay_Timer >= 15)
		{
			Button_Delay = false;
		}
	}
	if (Button_Delay == false)
	{
		Button_Delay_Timer = 0;
	}
	////////////////////////////////////
	// DOUBLE TAP FEATURE STARTS HERE///
	////////////////////////////////////
	////////////////////////////////////
	////////////////////////////////////

	if (Button_Double_Tap == true)
	{
		Button_Press_Timer  += 60 *(Button_Timer_Value / 1000.f );
			if (Button_Press_Timer >= 60)
			{
				Button_Double_Tap = false;
				Button_Press_Tracked_Alpha = NO_KEY;
			}
	}


	// All combination with the UP arrow Key
	if(Up_Key == true)
	{
		// HARD PRESSES
		if (Button_Double_Tap == true) 
		{

			if((Up_Key == true)&&(Right_Key == true)&&(Space_Key == true))
			{
				if (Button_Press_Tracked_Omega == UP_RIGHT_SPACE)
				{
					Button_Press_Timer = 0;
					return HARD_UP_RIGHT_SPACE;
				}
			}

			if((Up_Key == true)&&(Left_Key == true)&&(Space_Key == true))
			{
				if (Button_Press_Tracked_Omega == UP_LEFT_SPACE)
				{
					Button_Press_Timer = 0;
					return HARD_UP_LEFT_SPACE;
				}
			}	

			if((Up_Key == true)&&(Left_Key == true))
			{
				if (Button_Press_Tracked_Omega == UP_LEFT)
				{
					Button_Press_Timer = 0;
					if (Space_Key == true)
					{
						return  HARD_UP_LEFT_SPACE;
					}
					return HARD_UP_LEFT;
				}
			}
			if((Up_Key == true)&&(Right_Key == true))
			{
				if (Button_Press_Tracked_Omega == UP_RIGHT)
				{
					Button_Press_Timer = 0;
					if (Space_Key == true)
					{
						return  HARD_UP_RIGHT_SPACE;
					}
					return HARD_UP_RIGHT;
				}
			}
			if((Up_Key == true)&&(Down_Key == true))
			{
				if (Button_Press_Tracked_Omega == UP_DOWN)
				{
					Button_Press_Timer = 0;
					return HARD_UP_DOWN;
				}
			}
			if((Up_Key == true)&&(Z_Key == true))
			{
				if (Button_Press_Tracked_Omega == UP_Z)
				{
					Button_Press_Timer = 0;
					return HARD_UP_Z;
				}
			}
			if((Up_Key == true)&&(X_Key == true))
			{
				if (Button_Press_Tracked_Omega == UP_X)
				{
					Button_Press_Timer = 0;
					return HARD_UP_X;
				}
			}
			if((Up_Key == true)&&(C_Key == true))
			{
				if (Button_Press_Tracked_Omega == UP_C)
				{
					Button_Press_Timer = 0;
					return HARD_UP_C;
				}
			}
			if((Up_Key == true)&&(Space_Key == true))
			{
				if (Button_Press_Tracked_Omega == UP_SPACE)
				{
					Button_Press_Timer = 0;
					return HARD_UP_SPACE;
				}
			}
		

			if (Button_Delay == false)
			{ 
				if (Button_Press_Tracked_Omega == UP)
				{
					Button_Press_Timer = 0;
					if (Space_Key == true)
					{
						return HARD_UP_SPACE;
					}
					return HARD_UP;
				}
			}
		}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

			if((Up_Key == true)&&(Right_Key == true)&&(Space_Key == true))
			{
				Button_Press_Tracked_Alpha = UP_RIGHT_SPACE;
				return UP_RIGHT_SPACE;
			}

			if((Up_Key == true)&&(Left_Key == true)&&(Space_Key == true))
			{
				Button_Press_Tracked_Alpha = UP_LEFT_SPACE;
				return UP_LEFT_SPACE;
			}	

			if((Up_Key == true)&&(Left_Key == true))
			{
				Button_Press_Tracked_Alpha = UP_LEFT;
				return UP_LEFT;
			}
			if((Up_Key == true)&&(Right_Key == true))
			{
				Button_Press_Tracked_Alpha = UP_RIGHT;
				return UP_RIGHT;
			}
			if((Up_Key == true)&&(Down_Key == true))
			{
				Button_Press_Tracked_Alpha = UP_DOWN;
				return UP_DOWN;
			}
			if((Up_Key == true)&&(Z_Key == true))
			{
				Button_Press_Tracked_Alpha = UP_Z;
				return UP_Z;
			}
			if((Up_Key == true)&&(X_Key == true))
			{
				Button_Press_Tracked_Alpha = UP_X;
				return UP_X;
			}
			if((Up_Key == true)&&(C_Key == true))
			{
				Button_Press_Tracked_Alpha = UP_C;
				return UP_C;
			}
			if((Up_Key == true)&&(Space_Key == true))
			{
				Button_Press_Tracked_Alpha = UP_SPACE;
				return UP_SPACE;
			}
		

			if (Button_Delay == false)
			{ 
				Button_Press_Tracked_Alpha = UP;
				return UP;
			}
	}

/*************************************************************************************/
/*************************************************************************************/

	//All down key combinations
	if(Down_Key == true)
	{
		// HARD PRESSES
		if (Button_Double_Tap == true) 
		{
			if((Down_Key == true)&&(Right_Key == true)&&(Space_Key == true))
			{
				if (Button_Press_Tracked_Omega == DOWN_RIGHT_SPACE)
				{
					Button_Press_Timer = 0;
					return HARD_DOWN_RIGHT_SPACE;
				}	
			}

			if((Down_Key == true)&&(Left_Key == true)&&(Space_Key == true))
			{
				if (Button_Press_Tracked_Omega == DOWN_LEFT_SPACE)
				{
					Button_Press_Timer = 0;
					return HARD_DOWN_LEFT_SPACE;
				}
			}
			if((Down_Key == true)&&(Left_Key == true))
			{
				if (Button_Press_Tracked_Omega == DOWN_LEFT)
				{
					Button_Press_Timer = 0;
					if (Space_Key == true)
					{
						return HARD_DOWN_LEFT_SPACE;
					}
					return HARD_DOWN_LEFT;
				}
			}
			if((Down_Key == true)&&(Right_Key == true))
			{ 
				if (Button_Press_Tracked_Omega == DOWN_RIGHT)
				{
					Button_Press_Timer = 0;
					if (Space_Key == true)
					{
						return HARD_DOWN_RIGHT_SPACE;
					}
					return HARD_DOWN_RIGHT;
				}
			}
			if((Down_Key == true)&&(Up_Key == true))
			{
				if (Button_Press_Tracked_Omega == UP_DOWN)
				{
					Button_Press_Timer = 0;
					return HARD_UP_DOWN;
				}
			}
			if((Down_Key == true)&&(Z_Key == true))
			{
				if (Button_Press_Tracked_Omega == DOWN_Z)
				{
					Button_Press_Timer = 0;
					return HARD_DOWN_Z;
				}
			}
			if((Down_Key == true)&&(X_Key == true))
			{
				if (Button_Press_Tracked_Omega == DOWN_X)
				{
					Button_Press_Timer = 0;
					return HARD_DOWN_X;
				}
			}
			if((Down_Key == true)&&(C_Key == true))
			{
				if (Button_Press_Tracked_Omega == DOWN_C)
				{
					Button_Press_Timer = 0;
					return HARD_DOWN_C;
				}
			}
			if((Down_Key == true)&&(Space_Key == true))
			{
				if (Button_Press_Tracked_Omega == DOWN_SPACE)
				{
					Button_Press_Timer = 0;

					return HARD_DOWN_SPACE;
				}
			}
			if (Button_Delay == false)
			{ 
				if (Button_Press_Tracked_Omega == DOWN)
				{
					Button_Press_Timer = 0;
					if (Space_Key == true)
					{
						return HARD_DOWN_SPACE;
					}
					return HARD_DOWN;
				}
				
			}
		}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

			if((Down_Key == true)&&(Right_Key == true)&&(Space_Key == true))
			{
				Button_Press_Tracked_Alpha = DOWN_RIGHT_SPACE;
				return DOWN_RIGHT_SPACE;
			}

			if((Down_Key == true)&&(Left_Key == true)&&(Space_Key == true))
			{
				Button_Press_Tracked_Alpha = DOWN_LEFT_SPACE;
				return DOWN_LEFT_SPACE;
			}
			if((Down_Key == true)&&(Left_Key == true))
			{
				Button_Press_Tracked_Alpha = DOWN_LEFT;
				return DOWN_LEFT;
			}
			if((Down_Key == true)&&(Right_Key == true))
			{
				Button_Press_Tracked_Alpha = DOWN_RIGHT;
				return DOWN_RIGHT;
			}
			if((Down_Key == true)&&(Up_Key == true))
			{
				Button_Press_Tracked_Alpha = UP_DOWN;
				return UP_DOWN;
			}
			if((Down_Key == true)&&(Z_Key == true))
			{
				Button_Press_Tracked_Alpha = DOWN_Z;
				return DOWN_Z;
			}
			if((Down_Key == true)&&(X_Key == true))
			{
				Button_Press_Tracked_Alpha = DOWN_X;
				return DOWN_X;
			}
			if((Down_Key == true)&&(C_Key == true))
			{
				Button_Press_Tracked_Alpha = DOWN_C;
				return DOWN_C;
			}
			if((Down_Key == true)&&(Space_Key == true))
			{
				Button_Press_Tracked_Alpha = DOWN_SPACE;
				return DOWN_SPACE;
			}
			if (Button_Delay == false)
			{ 
				Button_Press_Tracked_Alpha = DOWN;
				
				return DOWN;
			}
	}
/*************************************************************************************/
/*************************************************************************************/

	if(Left_Key == true)
	{
		if (Button_Double_Tap == true) 
		{
			if((Down_Key == true)&&(Left_Key == true)&&(Space_Key == true))
			{
				if (Button_Press_Tracked_Omega == DOWN_LEFT_SPACE)
				{
					Button_Press_Timer = 0;
					return HARD_DOWN_LEFT_SPACE;
				}
			}
			if((Up_Key == true)&&(Left_Key == true)&&(Space_Key == true))
			{
				if (Button_Press_Tracked_Omega == UP_LEFT_SPACE)
				{
					Button_Press_Timer = 0;
					return HARD_UP_LEFT_SPACE;
				}
			}

			if((Left_Key == true)&&(Up_Key == true))
			{
				if (Button_Press_Tracked_Omega == UP_LEFT)
				{
					Button_Press_Timer = 0;
					if (Space_Key == true)
					{
						return HARD_UP_LEFT_SPACE;
					}
					return HARD_UP_LEFT;
				}
			}
			if((Left_Key == true)&&(Down_Key == true))
			{
				if (Button_Press_Tracked_Omega == DOWN_LEFT)
				{
					Button_Press_Timer = 0;
					if (Space_Key == true)
					{
						return HARD_DOWN_LEFT_SPACE;
					}
					return HARD_DOWN_LEFT;
				}
			}
			if((Left_Key == true)&&(Right_Key == true))
			{
				if (Button_Press_Tracked_Omega == LEFT_RIGHT)
				{
					Button_Press_Timer = 0;
					return HARD_LEFT_RIGHT;
				}
			}
			if((Left_Key == true)&&(Z_Key == true))
			{
				if (Button_Press_Tracked_Omega == LEFT_Z)
				{
					Button_Press_Timer = 0;
					return HARD_LEFT_Z;
				}
			}
			if((Left_Key == true)&&(X_Key == true))
			{
				if (Button_Press_Tracked_Omega == LEFT_X)
				{
					Button_Press_Timer = 0;
					return HARD_LEFT_X;
				}
			}
			if((Left_Key == true)&&(C_Key == true))
			{
				if (Button_Press_Tracked_Omega == LEFT_C)
				{
					Button_Press_Timer = 0;
					return HARD_LEFT_C;
				}
			}
			if((Left_Key == true)&&(Space_Key == true))
			{
 				if (Button_Press_Tracked_Omega == LEFT_SPACE)
				{
					Button_Press_Timer = 0;
					return HARD_LEFT_SPACE;
				}
			}


			if (Button_Delay == false)
			{ 
				if (Button_Press_Tracked_Omega == LEFT)
				{
					Button_Press_Timer = 0;
					if (Space_Key == true)
					{
						return HARD_LEFT_SPACE;
					}
					return HARD_LEFT;
				}
			}
		}


		///////////////////////////////////////////////////////
		//////////////////////////////////////////////////////
		//////////////////////////////////////////////////////


		if((Down_Key == true)&&(Left_Key == true)&&(Space_Key == true))
		{
			Button_Press_Tracked_Alpha = DOWN_LEFT_SPACE;
			return DOWN_LEFT_SPACE;
		}
		if((Up_Key == true)&&(Left_Key == true)&&(Space_Key == true))
		{
			Button_Press_Tracked_Alpha = UP_LEFT_SPACE;
			return UP_LEFT_SPACE;
		}

		if((Left_Key == true)&&(Up_Key == true))
		{
			Button_Press_Tracked_Alpha = UP_LEFT;
			return UP_LEFT;
		}
		if((Left_Key == true)&&(Down_Key == true))
		{
			Button_Press_Tracked_Alpha = DOWN_LEFT;
			return DOWN_LEFT;
		}
		if((Left_Key == true)&&(Right_Key == true))
		{
			Button_Press_Tracked_Alpha = LEFT_RIGHT;
			return LEFT_RIGHT;
		}
		if((Left_Key == true)&&(Z_Key == true))
		{
			Button_Press_Tracked_Alpha = LEFT_Z;
			return LEFT_Z;
		}
		if((Left_Key == true)&&(X_Key == true))
		{
			Button_Press_Tracked_Alpha = LEFT_C;
			return LEFT_X;
		}
		if((Left_Key == true)&&(C_Key == true))
		{
			Button_Press_Tracked_Alpha = LEFT_C;
			return LEFT_C;
		}
		if((Left_Key == true)&&(Space_Key == true))
		{
			Button_Press_Tracked_Alpha = LEFT_SPACE;
			return LEFT_SPACE;
		}


		if (Button_Delay == false)
		{ 
			Button_Press_Tracked_Alpha = LEFT;
			return LEFT;
		}
	}

/*************************************************************************************/
/*************************************************************************************/

	if(Right_Key == true)
	{
		if (Button_Double_Tap == true) 
		{

			if((Down_Key == true)&&(Right_Key == true)&&(Space_Key == true))
			{
				if (Button_Press_Tracked_Omega == DOWN_RIGHT_SPACE)
				{
					Button_Press_Timer = 0;
					return HARD_DOWN_RIGHT_SPACE;
				}
			}
			if((Up_Key == true)&&(Right_Key == true)&&(Space_Key == true))
			{
				if (Button_Press_Tracked_Omega == UP_RIGHT_SPACE)
				{
					Button_Press_Timer = 0;
					return HARD_UP_RIGHT_SPACE;
				}
			}

			if((Right_Key == true)&&(Up_Key == true))
			{
				if (Button_Press_Tracked_Omega == UP_RIGHT)
				{
					Button_Press_Timer = 0;
					if (Space_Key == true)
					{
						return HARD_UP_RIGHT_SPACE;
					}
					return HARD_UP_RIGHT;
				}
			}	
			if((Right_Key == true)&&(Down_Key == true))
			{
				if (Button_Press_Tracked_Omega == DOWN_RIGHT)
				{
					Button_Press_Timer = 0;
					if (Space_Key == true)
					{
						return HARD_DOWN_RIGHT_SPACE;
					}
					return HARD_DOWN_RIGHT;
				}
			}
			if((Right_Key == true)&&(Left_Key == true))
			{
				if (Button_Press_Tracked_Omega == LEFT_RIGHT)
				{
					Button_Press_Timer = 0;
					return HARD_LEFT_RIGHT;
				}
			}
			if((Right_Key == true)&&(Z_Key == true))
			{
				if (Button_Press_Tracked_Omega == RIGHT_Z)
				{
					Button_Press_Timer = 0;
					return HARD_RIGHT_Z;
				}
			}
			if((Right_Key == true)&&(X_Key == true))
			{
				if (Button_Press_Tracked_Omega == RIGHT_X)
				{
					Button_Press_Timer = 0;
					return HARD_RIGHT_X;
				}
			}
			if((Right_Key == true)&&(C_Key == true))
			{
				if (Button_Press_Tracked_Omega == RIGHT_C)
				{
					Button_Press_Timer = 0;
					return HARD_RIGHT_C;
				}
			}
			if((Right_Key == true)&&(Space_Key == true))
			{
				if (Button_Press_Tracked_Omega == RIGHT_SPACE)
				{
					Button_Press_Timer = 0;
					return HARD_RIGHT_SPACE;
				}
			}
			if (Button_Delay == false)
			{ 
				if (Button_Press_Tracked_Omega == RIGHT)
				{
					Button_Press_Timer = 0;
					if (Space_Key == true)
					{
						return HARD_RIGHT_SPACE;
					}
					
					return HARD_RIGHT;
				}
			}
		}
		/////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////

		if((Down_Key == true)&&(Right_Key == true)&&(Space_Key == true))
		{
			Button_Press_Tracked_Alpha = DOWN_RIGHT_SPACE;
			return DOWN_RIGHT_SPACE;
		}
		if((Up_Key == true)&&(Right_Key == true)&&(Space_Key == true))
		{
			Button_Press_Tracked_Alpha = UP_RIGHT_SPACE;
			return UP_RIGHT_SPACE;
		}

		if((Right_Key == true)&&(Up_Key == true))
		{
			Button_Press_Tracked_Alpha = UP_RIGHT;
			return UP_RIGHT;
		}
		if((Right_Key == true)&&(Down_Key == true))
		{
			Button_Press_Tracked_Alpha = DOWN_RIGHT;
			return DOWN_RIGHT;
		}
		if((Right_Key == true)&&(Left_Key == true))
		{
			Button_Press_Tracked_Alpha = LEFT_RIGHT;
			return LEFT_RIGHT;
		}
		if((Right_Key == true)&&(Z_Key == true))
		{
			Button_Press_Tracked_Alpha = RIGHT_Z;
			return RIGHT_Z;
		}
		if((Right_Key == true)&&(X_Key == true))
		{
			Button_Press_Tracked_Alpha = RIGHT_X;
			return RIGHT_X;
		}
		if((Right_Key == true)&&(C_Key == true))
		{
			Button_Press_Tracked_Alpha = RIGHT_C;
			return RIGHT_C;
		}
		if((Right_Key == true)&&(Space_Key == true))
		{
			Button_Press_Tracked_Alpha = RIGHT_SPACE;
			return RIGHT_SPACE;
		}

		if (Button_Delay == false)
		{ 
			Button_Press_Tracked_Alpha = RIGHT;
			return RIGHT;
		}
	}

/*************************************************************************************/
/*************************************************************************************/
	if(Z_Key == true)
	{
		if((Z_Key == true)&&(Up_Key == true))
		{
			return UP_Z;
		}
		if((Z_Key == true)&&(Down_Key == true))
		{
			return DOWN_Z;
		}
		if((Z_Key == true)&&(Left_Key == true))
		{
			return LEFT_Z;
		}
		if((Z_Key == true)&&(X_Key == true))
		{
			return Z_X;
		}
		if((Z_Key == true)&&(C_Key == true))
		{
			return Z_C;
		}
		if((Z_Key == true)&&(Space_Key == true))
		{
			return Z_SPACE;
		}
		if((Z_Key == true)&&(Right_Key == true))
		{
			return RIGHT_Z;
		}
		return Z;
	}

	if(X_Key == true)
	{
		if((X_Key == true)&&(Up_Key == true))
		{
			return UP_X;
		}
		if((X_Key == true)&&(Down_Key == true))
		{
			return DOWN_X;
		}
		if((X_Key == true)&&(Left_Key == true))
		{
			return LEFT_X;
		}
		if((X_Key == true)&&(Z_Key == true))
		{
			return Z_X;
		}
		if((X_Key == true)&&(C_Key == true))
		{
			return X_C;
		}
		if((X_Key == true)&&(Space_Key == true))
		{
			return X_SPACE;
		}
		if((X_Key == true)&&(Right_Key == true))
		{
			return RIGHT_X;
		}
		return X;
	}

	if(C_Key == true)
	{
		if((C_Key == true)&&(Up_Key == true))
		{
			return UP_C;
		}
		if((C_Key == true)&&(Down_Key == true))
		{
			return DOWN_C;
		}
		if((C_Key == true)&&(Left_Key == true))
		{
			return LEFT_C;
		}
		if((C_Key == true)&&(Z_Key == true))
		{
			return Z_C;
		}
		if((C_Key == true)&&(X_Key == true))
		{
			return X_C;
		}
		if((C_Key == true)&&(Space_Key == true))
		{
			return C_SPACE;
		}
		if((C_Key == true)&&(Right_Key == true))
		{
			return RIGHT_C;
		}
		return C;
	}

	if(Space_Key == true)
	{
		return SPACE;
	}

	// Double Tapping
	if (Button_Press_Tracked_Alpha == NO_KEY)
	{
		
		Button_Double_Tap = false;
		Button_Press_Timer = 0;
	}
	if (Button_Press_Tracked_Alpha != NO_KEY)
	{
		
		Button_Double_Tap = true;
		Button_Press_Tracked_Omega = Button_Press_Tracked_Alpha; 
		return NO_KEY;
	}


	Button_Press_Tracked_Alpha = NO_KEY;
	return NO_KEY;
}

// Used to exit to other areas 
int Graphic_Event_Fade_Out(int activation_type)
{

	int Activation = activation_type;
	
	const int DONE = 0, NOT_DONE = 1;
	
	// Global varibles. Location of editing marked
	
	
	switch (Activation)
	{
		case LEVEL_WRAP:		
																
								
								
								
								SDL_SetAlpha( ScreenEffects, SDL_SRCALPHA, Transparant);
								
								
								if (Transparant < SDL_ALPHA_OPAQUE)
								{	
									Transparant+= 5;
									return NOT_DONE;
								}
								break;
	}
	return DONE;
}

int Graphic_Event_Fade_In(int activation_type)
{
	int Activation = activation_type;
	const int DONE = 0, NOT_DONE = 1;

	if (Transparant <= SDL_ALPHA_TRANSPARENT)
	{
		Transparant = 0;
		return DONE;
	}

	Transparant-= 5;
	switch (Activation)
	{
		case LEVEL_WRAP:		SDL_SetAlpha( ScreenEffects, SDL_SRCALPHA, Transparant);
																
								if (Transparant > SDL_ALPHA_TRANSPARENT)
								{	
									return NOT_DONE;
								}break;
	}
	return DONE;
}


//Argument represent How to transistion, Where to warp, and a special action the triggers.
void Level_Warpping(int warp_type, int level, int location, int action, bool level_warp, Soul *Spirit[], External_Configuration config)
{


	// "L" is a level loader object. This function is temporaraly disable to install the new polymorpic base struture. 
//	Level_Wrap = Exit_Object_Collision(player.Get_Character_Base(), player.Get_Character(), L);
	Level_Warp = level_warp;


	switch (Level_Warp)
	{
		case true:  Freeze_All_Actions = LEVEL_WRAP;
					
						if (Graphic_Event_Fade_Out( warp_type) == 0)
						{
							 Pick_Level(Spirit, config, level);
						}
		
		break;
		case false: if (Graphic_Event_Fade_In(Freeze_All_Actions)==0)
					{
						//Deactivator
						Freeze_All_Actions = NOT_FROZEN;
					}
				
			break;
	}

}

void Final_Warp_Process(Internal_Config &IN_config, Rendering &graphic, Soul *spirit[] )
{
	switch (Level_Warp_Key)
	{
		case true:	graphic.Optimization_Variable_Definer(spirit);
					IN_config.Optimization_Variable_Definer(spirit);
					Level_Warp_Key = false;
			break;
	}
}

void Change_Game_Mode(int change_mode)
{
	Game_Mode = change_mode;
}

void Change_Selected_Character(int selected_character)
{
	Selected_Character = selected_character;
}