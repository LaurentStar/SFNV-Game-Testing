#include "Function.h"



bool Pick_Level(Soul *Spirit[], External_Configuration &config, int level)
{
	//Erase the level
	for (int tz = LAST + 1; tz  <  MAX_GAME_OBJECTS; tz++)
	{
		if (Spirit[tz] == NULL)
		{
			break;
		}

		if (Spirit[tz] != NULL)
		{
			delete Spirit[ tz ];
		}
	}
	



	switch (level)
	{
		case LEVEL_1_A: if (Load_Level_LEVEL_1_A(Spirit, config, 0 ) == false)
						{
							return false;
						} 
			break;
		case LEVEL_1_B:  if (Load_Level_LEVEL_1_B(Spirit, config, 0 ) == false)
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
		Spirit[ tz ]->Move_Special_Object();
	}

	Level_Warp_Key = true;
	return true;
}

bool Load_Level_LEVEL_1_A( Soul *Spirit[], External_Configuration &config, int load_source)
{
	int Start_Num;


	Start_Num = Load_Level_Lv1A_Floor(LAST + 1, Spirit, config , load_source);
	if(Start_Num != -1) 
	{
		Start_Num =  Load_Level_Lv1A_Float(Start_Num, Spirit, config, load_source );
		if ( Start_Num != -1)
		{

			Start_Num =  Load_Level_Lv1A_Config( Start_Num, Spirit, config, load_source);
			if ( Start_Num != -1)
			{
				Start_Num =  Load_Level_Smart_AI(Start_Num, Spirit, config, load_source);
				if ( Start_Num != -1)
				{
				
				}
			}	
		}
	}	

	for (int z = Start_Num; z <  MAX_GAME_OBJECTS; z++)
	{
		Spirit[ z ] = NULL;
	}

	if(Start_Num == -1) 
	{
		return false;
	}

	return true;
}
int Load_Level_Lv1A_Floor(int Start_Num, Soul *Spirit[], External_Configuration &config, int load_source)
{
	//Starting point of tile placement
	int x = 0, y = 0; 

	int Start_Number = Start_Num;

	// Total tiles is declared in respected files. it is the first number.
	int Total_Floor_Objects;
	int Level_Value;

	bool Failure = false; 
	//Name of the level
    std::string Level;

	switch (load_source) //Decide where to go to get level info
	{
		case 0: Level = config.Get_Current_Level_Name(); break;
		case 1: Level = config.Get_Level_Name(); break;
	}
	// Level value is to make the code flexible
	Level_Value = Object_Setting_Helper(Level);

	// ALL the files are loaded but that aren't all used. This code has many switch case statements
	std::ifstream Lv1AFloor( "Lv1AFloor.map" );if( Lv1AFloor == NULL ) { return false; }
	std::ifstream Lv1BFloor( "Lv1BFloor.map" );if( Lv1BFloor == NULL ) { return false; }
		
	
	switch (Level_Value)
	{					 // Definig the total number of title. remember it the first element
		case LEVEL_1_A:  Lv1AFloor >> Total_Floor_Objects; break;
		case LEVEL_1_B:  Lv1BFloor >> Total_Floor_Objects; break;
	}

	//Initialize the tiles 
	for( int t = 0; t < Total_Floor_Objects; t++ ) 
	{ 
		//Determines what kind of tile will be made 
		int tileType = -1; 

		switch (Level_Value)
		{					 //Read from map file****** Stop loading if there was a problem
			case LEVEL_1_A:  Lv1AFloor >> tileType;  if( Lv1AFloor.fail() == true ) {Failure = true;} break;
			case LEVEL_1_B:  Lv1BFloor >> tileType;  if( Lv1BFloor.fail() == true ) {Failure = true;} break;																		

		}
		
		// if anything messed up shut down
		if (Failure == true)
		{
			Lv1AFloor.close(); 
			Lv1BFloor.close(); 
			return -1; 
				
		}

		

		//If the number is a valid tile number 
		if( ( tileType >= 0 ) && ( tileType <= FLOOR_TILE_SPRITES ) ) 
		{ 
		Spirit[ Start_Number ] = new Environment_Floor_Objects( x, y, tileType ); 
			//Move to next tile spot 
			x += TILE_WIDTH; 

		} 

		//If we don't recognize the tile type 
		else 
		{ 
			//CLOSE ALL FILES! ALL OF THEM
			Lv1AFloor.close(); 
			Lv1BFloor.close(); 
			return -1; 
		} 

		//If we've gone too far 
		if( x >= config.Get_Level_Width_Lenght(0)) 
		{ 
			//Move back 
			x = 0; 

			//Move to the next row 
			y += TILE_HEIGHT; 
		}
		Start_Number++;
	
	} 
	
	//Closing the file.
	Lv1AFloor.close(); 
	Lv1BFloor.close(); 
	return Start_Number;
}
int Load_Level_Lv1A_Float(int Start_Num, Soul *Spirit[],External_Configuration &config, int load_source)
{
	int x = 0, y = 0, z = 0; 
	int Total_Floating_Objects;	
	int Start_Number = Start_Num;

	int Level_Value;
	std::string Level;

	bool Failure = false; 
	//Name of the level
    switch (load_source) //Decide where to go to get level info
	{
		case 0: Level = config.Get_Current_Level_Name(); break;
		case 1: Level = config.Get_Level_Name(); break;
	}
	
	// Level value is to make the code flexible
	Level_Value = Object_Setting_Helper(Level);
	
	
	std::ifstream Lv1AFloatingXYZ ("Lv1AFloatingXYZ.map" );if( Lv1AFloatingXYZ == NULL ) {Lv1AFloatingXYZ.close();  return false; }
	std::ifstream Lv1BFloatingXYZ ("Lv1BFloatingXYZ.map" );if( Lv1BFloatingXYZ == NULL ) {Lv1BFloatingXYZ.close();  return false; }

	switch (Level_Value)
	{					
						// Open one of these file ONLY for reading. 
		case LEVEL_1_A:	Lv1AFloatingXYZ >> Total_Floating_Objects; break;
		case LEVEL_1_B:	Lv1BFloatingXYZ >> Total_Floating_Objects; break;

	}
	
	
	
	//Initialize the tiles 
	for( int t = 0; t < Total_Floating_Objects; t++ ) 
	{ 
		int TileType = -1; 
		switch (Level_Value)
		{				//MUST BE READ IN THIS ORDER NO EXCEPTIONS!	
			case LEVEL_1_A: Lv1AFloatingXYZ >> TileType; Lv1AFloatingXYZ >> x; Lv1AFloatingXYZ >> y; Lv1AFloatingXYZ >> z;  
				if( Lv1AFloatingXYZ.fail() == true ) { Failure = true; }break;
			case LEVEL_1_B: Lv1BFloatingXYZ >> TileType; Lv1BFloatingXYZ >> x; Lv1BFloatingXYZ >> y; Lv1BFloatingXYZ >> z;  
				if( Lv1BFloatingXYZ.fail() == true ) { Failure = true; }break;

		}
		//If the was a problem in reading the map 
		if( Failure == true ) 
		{ 
			//CLOSE ALL FILES
			Lv1AFloatingXYZ.close(); 
			Lv1BFloatingXYZ.close(); 
			return -1; 
		} 

		//If the number is a valid tile number 
		if( ( TileType >= 0 ) && ( TileType <= FLOATING_TILE_SPRITES ) ) 
		{ 
			Spirit[ Start_Number ] = new Environment_Float_Objects ( x,  y, z, TileType ); 
		} 

		//If we don't recognize the tile type 
		else 
		{ 
			//CLOSE ALL FILES
			Lv1AFloatingXYZ.close(); 
			Lv1BFloatingXYZ.close(); 
			return -1; 
		} 

		Start_Number++;
	
	} 
	
					
	                                               

		Lv1AFloatingXYZ.close(); 
		Lv1BFloatingXYZ.close(); 
	

 return Start_Number; 
}
int Load_Level_Lv1A_Config(int Start_Num, Soul *Spirit[],External_Configuration &config, int load_source)
{
	int x = 0, y = 0, z = 0; 
	int Total_Config_Objects;
	
	int Start_Number = Start_Num;

	int Level_Value;
	std::string Level;

	bool Failure = false; 
	//Name of the level
    switch (load_source) //Decide where to go to get level info
	{
		case 0: Level = config.Get_Current_Level_Name(); break;
		case 1: Level = config.Get_Level_Name(); break;
	}
	
	// Level value is to make the code flexible
	Level_Value = Object_Setting_Helper(Level);
	
	
	std::ifstream Lv1AConfig ("Lv1AConfig.map" );if( Lv1AConfig == NULL ) {Lv1AConfig.close();  return false; }
	std::ifstream Lv1BConfig ("Lv1BConfig.map" );if( Lv1BConfig == NULL ) {Lv1BConfig.close();  return false; }

	switch (Level_Value)
	{					
						// Open one of these file ONLY for reading. 
		case LEVEL_1_A:	Lv1AConfig >> Total_Config_Objects; break;
		case LEVEL_1_B:	Lv1BConfig >> Total_Config_Objects; break;

	}
	
	
	
	//Initialize the tiles 
	for( int t = 0; t < Total_Config_Objects; t++ ) 
	{ 
		int TileType = -1; 
		int GateType = -1;
		switch (Level_Value)
		{				//MUST BE READ IN THIS ORDER NO EXCEPTIONS!	
			case LEVEL_1_A: Lv1AConfig >> TileType; Lv1AConfig >> x; Lv1AConfig >> y; Lv1AConfig >> z;  Lv1AConfig >> GateType;
				if( Lv1AConfig.fail() == true ) { Failure = true; }break;
			case LEVEL_1_B: Lv1BConfig >> TileType; Lv1BConfig >> x; Lv1BConfig >> y; Lv1BConfig >> z;   Lv1AConfig >> GateType;
				if( Lv1BConfig.fail() == true ) { Failure = true; }break;

		}
		//If the was a problem in reading the map 
		if( Failure == true ) 
		{ 
			//CLOSE ALL FILES
			Lv1AConfig.close(); 
			Lv1BConfig.close(); 
			return -1; 
		} 

		//If the number is a valid tile number 
		if( ( TileType >= 0 ) && ( TileType <= FLOATING_TILE_SPRITES ) ) 
		{ 
			Spirit[ Start_Number ] = new  Config_Objects( x,  y, z, TileType, GateType ); 
		} 

		//If we don't recognize the tile type 
		else 
		{ 
			//CLOSE ALL FILES
			Lv1AConfig.close(); 
			Lv1BConfig.close(); 
			return -1; 
		} 

		Start_Number++;
	
	} 
	
					
	                                               

		Lv1AConfig.close(); 
		Lv1BConfig.close(); 
	

 return Start_Number; 
}


bool Load_Level_LEVEL_1_B( Soul *Spirit[], External_Configuration &config, int load_source)
{
	int Start_Num;


	Start_Num = Load_Level_Lv1B_Floor(LAST + 1, Spirit, config, load_source );
	if(Start_Num != -1) 
	{
		Start_Num =  Load_Level_Lv1B_Float(Start_Num, Spirit, config , load_source);
		if ( Start_Num != -1)
		{
			Start_Num =  Load_Level_Lv1B_Config( Start_Num, Spirit,  config, load_source);
			if ( Start_Num != -1)
			{


			}	
		}
	}	

	for (int z = Start_Num; z <  MAX_GAME_OBJECTS; z++)
	{
		Spirit[ z ] = NULL;
	}

	if(Start_Num == -1) 
	{
		return false;
	}

	return true;
}
int Load_Level_Lv1B_Floor(int Start_Num, Soul *Spirit[], External_Configuration &config, int load_source)
{
	//Starting point of tile placement
	int x = 0, y = 0; 

	int Start_Number = Start_Num;

	// Total tiles is declared in respected files. it is the first number.
	int Total_Floor_Objects;

	int Level_Value;
	bool Failure = false; 
	//Name of the level
    std::string Level;
	switch (load_source) //Decide where to go to get level info
	{
		case 0: Level = config.Get_Current_Level_Name(); break;
		case 1: Level = config.Get_Level_Name(); break;
	}
	
	// Level value is to make the code flexible
	Level_Value = Object_Setting_Helper(Level);

	// ALL the files are loaded but that aren't all used. This code has many switch case statements
	std::ifstream Lv1BFloor( "Lv1BFloor.map" );if( Lv1BFloor == NULL ) { return false; }
		
	
	switch (Level_Value)
	{					 // Definig the total number of title. remember it the first element
		case LEVEL_1_B:  Lv1BFloor >> Total_Floor_Objects; break;
	}

	//Initialize the tiles 
	for( int t = 0; t < Total_Floor_Objects; t++ ) 
	{ 
		//Determines what kind of tile will be made 
		int tileType = -1; 

		switch (Level_Value)
		{					 //Read from map file****** Stop loading if there was a problem
			case LEVEL_1_B:  Lv1BFloor >> tileType;  if( Lv1BFloor.fail() == true ) {Failure = true;} break;
		}
		
		// if anything messed up shut down
		if (Failure == true)
		{
			Lv1BFloor.close(); 
			return -1; 		
		}

		

		//If the number is a valid tile number 
		if( ( tileType >= 0 ) && ( tileType <= FLOOR_TILE_SPRITES ) ) 
		{ 
			Spirit[ Start_Number ] = new Environment_Floor_Objects( x, y, tileType ); 
			//Move to next tile spot 
			x += TILE_WIDTH; 

		} 

		//If we don't recognize the tile type 
		else 
		{ 
			//CLOSE ALL FILES! ALL OF THEM
			Lv1BFloor.close(); 
			return -1; 
		} 

		//If we've gone too far 
		if( x >= config.Get_Level_Width_Lenght(0)) 
		{ 
			//Move back 
			x = 0; 

			//Move to the next row 
			y += TILE_HEIGHT; 
		}
		Start_Number++;
	
	} 
	
	//Closing the file.
	Lv1BFloor.close(); 
	return Start_Number;
}
int Load_Level_Lv1B_Float(int Start_Num, Soul *Spirit[],External_Configuration &config, int load_source)
{
	int x = 0, y = 0, z = 0; 
	int Total_Floating_Objects;	
	int Start_Number = Start_Num;

	int Level_Value;
	std::string Level;
	bool Failure = false; 
	//Name of the level
    switch (load_source) //Decide where to go to get level info
	{
		case 0: Level = config.Get_Current_Level_Name(); break;
		case 1: Level = config.Get_Level_Name(); break;
	}
	
	// Level value is to make the code flexible
	Level_Value = Object_Setting_Helper(Level);
	

	std::ifstream Lv1BFloatingXYZ ("Lv1BFloatingXYZ.map" );if( Lv1BFloatingXYZ == NULL ) {Lv1BFloatingXYZ.close();  return false; }

	switch (Level_Value)
	{					
						// Open one of these file ONLY for reading. 
		case LEVEL_1_B:	Lv1BFloatingXYZ >> Total_Floating_Objects; break;

	}
	
	
	
	//Initialize the tiles 
	for( int t = 0; t < Total_Floating_Objects; t++ ) 
	{ 
		int TileType = -1; 
		switch (Level_Value)
		{				//MUST BE READ IN THIS ORDER NO EXCEPTIONS!	
			case LEVEL_1_B: Lv1BFloatingXYZ >> TileType; Lv1BFloatingXYZ >> x; Lv1BFloatingXYZ >> y; Lv1BFloatingXYZ >> z;  
				if( Lv1BFloatingXYZ.fail() == true ) { Failure = true; }break;

		}
		//If the was a problem in reading the map 
		if( Failure == true ) 
		{ 
			//CLOSE ALL FILES
			Lv1BFloatingXYZ.close(); 
			return -1; 
		} 

		//If the number is a valid tile number 
		if( ( TileType >= 0 ) && ( TileType <= FLOATING_TILE_SPRITES ) ) 
		{ 
			Spirit[ Start_Number ] = new Environment_Float_Objects ( x,  y, z, TileType ); 
		} 

		//If we don't recognize the tile type 
		else 
		{ 
			//CLOSE ALL FILES
			Lv1BFloatingXYZ.close(); 
			return -1; 
		} 

		Start_Number++;
	
	} 
	
					
	                                               
		Lv1BFloatingXYZ.close(); 
	

 return Start_Number; 
}
int Load_Level_Lv1B_Config(int Start_Num, Soul *Spirit[],External_Configuration &config, int load_source)
{

	int x = 0, y = 0, z = 0; 
	int Total_Config_Objects;
	
	int Start_Number = Start_Num;

	int Level_Value;
	std::string Level;

	bool Failure = false; 
	//Name of the level
    switch (load_source) //Decide where to go to get level info
	{
		case 0: Level = config.Get_Current_Level_Name(); break;
		case 1: Level = config.Get_Level_Name(); break;
	}
	
	// Level value is to make the code flexible
	Level_Value = Object_Setting_Helper(Level);
	
	

	std::ifstream Lv1BConfig ("Lv1BConfig.map" );if( Lv1BConfig == NULL ) {Lv1BConfig.close();  return false; }

	switch (Level_Value)
	{					
						// Open one of these file ONLY for reading. 

		case LEVEL_1_B:	Lv1BConfig >> Total_Config_Objects; break;

	}
	
	
	
	//Initialize the tiles 
	for( int t = 0; t < Total_Config_Objects; t++ ) 
	{ 
		int TileType = -1; 
		int GateType = -1;
		switch (Level_Value)
		{				//MUST BE READ IN THIS ORDER NO EXCEPTIONS!	
			case LEVEL_1_B: Lv1BConfig >> TileType; Lv1BConfig >> x; Lv1BConfig >> y; Lv1BConfig >> z;   Lv1BConfig >> GateType;
				if( Lv1BConfig.fail() == true ) { Failure = true; }break;

		}
		//If the was a problem in reading the map 
		if( Failure == true ) 
		{ 
			//CLOSE ALL FILES

			Lv1BConfig.close(); 
			return -1; 
		} 

		//If the number is a valid tile number 
		if( ( TileType >= 0 ) && ( TileType <= FLOATING_TILE_SPRITES ) ) 
		{ 
			Spirit[ Start_Number ] = new  Config_Objects( x,  y, z, TileType, GateType ); 
		} 

		//If we don't recognize the tile type 
		else 
		{ 
			Lv1BConfig.close(); 
			return -1; 
		} 

		Start_Number++;
	
	} 
	
					
	                                               
		Lv1BConfig.close(); 
	

 return Start_Number; 
}

//Smart Ai moves around. Only one function is needed to detect them in a level
int Load_Level_Smart_AI(int Start_Num, Soul *Spirit[],External_Configuration &config, int load_source)
{
	int x = 0, y = 0, z = 0; 
	int Location = -1;
	int Total_Smart_AI_Objects;
	
	int Level_Value;
	std::string Level;

	int Start_Number = Start_Num;

	
	bool Failure = false; 
	//Name of the level
 
	//Name of the level
    switch (load_source) //Decide where to go to get level info
	{
		case 0: Level = config.Get_Current_Level_Name(); break;
		case 1: Level = config.Get_Level_Name(); break;
	}
	
	// Level value is to make the code flexible
	Level_Value = Object_Setting_Helper(Level);
	

	
	
	std::ifstream Smart_AI ("Smart_AI.map" );if( Smart_AI == NULL ) {Smart_AI.close();  return false; }
	
	Smart_AI  >> Total_Smart_AI_Objects; 

	//Initialize the tiles 
	for( int t = 0; t < Total_Smart_AI_Objects; t++ ) 
	{ 
		int Ai_Type = -1; 

		 Smart_AI >> Location; Smart_AI >> Ai_Type; Smart_AI >> x; Smart_AI >> y; Smart_AI >> z;  
				
		 if(  Smart_AI.fail() == true ) 
		 { 
			 Failure = true; 
		 }

		//If the was a problem in reading the map 
		if( Failure == true ) 
		{ 
			//CLOSE ALL FILES
			Smart_AI.close(); 
			Smart_AI.close(); 
			return -1; 
		} 

		//If the number is a valid tile number and the AI is in the level
		if( ( Ai_Type >= 0 ) && ( Ai_Type <= AI_TYPE_COUNT )) 
		{ 
			//If the ai in the level
			if (Location == Level_Value)
			{
				Spirit[ Start_Number ] = new  Smart_AI_Object( x,  y, z, Ai_Type , Location ); 
			}
		} 

		//If we don't recognize the tile type 
		else 
		{ 
			//CLOSE ALL FILES
			Smart_AI.close(); 
			return -1; 
		} 

		Start_Number++;
	
	} 
	
					
	                                               

		Smart_AI.close(); 
 return Start_Number; 
}