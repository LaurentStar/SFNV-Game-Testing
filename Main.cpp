
#include "Function.h"

//PROGRAM THE A VARIABLE SETTER FOR ALL CLASSES
int main( int argc, char* args[] )
{

	/************************************************
	//		DECLARATION OF EVERYTHING			   //
	************************************************/
    //Quit flag
    bool Quit = false;
		
    //Initialize
    if( Init() == false )
    {
        return 1;
    }
	
    //Load the files
    if( Load_Files() == false )
    {
        return 1;
    }

    //Clip all art to be used
	Clip_Test();
	Cyron_Tanryoku_Clip();
	Chrome_Crystal_Master_Gray_Clip();
	Floor_Object_Clip();
	Float_Object_Clip();	
	Shadow_Float_Object_Clip();
	Exit_Object_Clip();
	Screen_Effects_Clip(); 
	On_Screen_Clip();
	Enemy_Object_Clip();
	
	// Configuring the game
	External_Configuration Config;
	
	//Similar to config
	Internal_Config IN_Config;

	// Graphic handling
	Rendering Graphic;
	
	Physics Physic; //SOON TO BE OF GREAT IMPORTANTS
	//Enemies
	//Enemy_Object *Foe [MAX_ENEMY_OBJECTS];
	//Bullet_Object *Bullet[MAX_BULLET_OBJECTS ];

	//The soul of the game
	Soul *Spirits[MAX_GAME_OBJECTS];

	//Environment_Objects *E_Ground_Object[ MAX_GROUND_OBJECTS ];

    //The frame rate regulator
    Timer Delta;

	//GameStart


	/************************************************
	//			GAME STARTING VARIABLES	DEFINED		//
	************************************************/
	if (Config.Configurate_Level_Name()== false)
	{
		return 1;
	}
	if (Config.Configurate_Character_Coord() == false)
	{
		return 1;
	}
	if (Config.Configurate_Level_Width_Lenght()== false )
	{
		return 1;
	}
	/*************************************************************
	//			USING THE VARIABLES TO GET EVERYTHING STARTED	//
	*************************************************************/
	// Placing the player when the game starts. Only called here. 
	//Player.Variable_Definer_Game_Start(Config);
	Graphic.Variable_Update_Inactive(Config);
	
	/*if (Set_Level_Loader_Objects(Level_Loader_Object, Config)==false)
	{
		return 1;
	}*/
  
	if (Set_Objects(Spirits, Config) == false)
	{
		return 0;
	}
	
	Game_Start_Soul(Spirits, Config);

    /*if (Set_Grounded_Objects( E_Ground_Object,  Config) == false)
	{
		return 1;
	}*/
	/*if (Set_Enemy_Objects(Foe,Config) == false)
	{
		return 1;
	}*/
	//Set_Bullet_Objects( Bullet);


	Graphic.Shader_Setter();

	//Title_Screen();

// These functions are called to skip the title screen. Erase as nessary. 	
SDL_SetAlpha( ScreenEffects, SDL_SRCALPHA, 0 );
Game_Mode = GAMEPLAY_MODE;	


Graphic.Optimization_Variable_Definer( Spirits );
IN_Config.Optimization_Variable_Definer( Spirits );
IN_Config.Optimization_Chain_Link_Definer( Spirits );

	//While the user hasn't quit
    while( Quit == false )
    {
        //While there's events to handle
        while( SDL_PollEvent( &event ) )
        {
            Button_Command();

            //If the user has Xed out the window
            if( event.type == SDL_QUIT )
            {
                //Quit the program
                Quit = true;
            }
        }
		
		switch (Selected_Character)
		{
			case CYRON_TANRYOKU:Selected_Spirit =  XCYRON_TANRYOKUX;  break;
			case THE_YS_GUY: Selected_Spirit =  XTHE_YS_GUYX; break;
			case CXX120: Selected_Spirit = XCXX120X; break;
			case GHOST: Selected_Spirit = XGHOSTX; break;
		}
		
		//Has the power to change levels. Extremely powerful	
		IN_Config.Level_Gate_Collision(Spirits, Config);
		Final_Warp_Process(IN_Config, Graphic, Spirits );
		IN_Config.Misc_Object_Collision(Spirits, Config);
		IN_Config.On_Screen_Misc_Object_Collision(Spirits,Config);
		IN_Config.Default_Object_Render(Spirits);
		

	/************************************************
	//	ALL ACTIVE VARIABLE DEFINE IN THIS ARE	   //
	************************************************/
	// ####################################
	//	Player.Character_Stats_Controller(Bullet,Delta.get_ticks());

		
		Physic.Game_Physics_Object_Update(Spirits,Delta.get_ticks());
		Graphic.Variable_Update_Active( Spirits );
		//Player.Variable_Definer_Active( Physic,Config,Spirits, Delta.get_ticks());
		
	//	AI_Handling_Variable_Refresh(Foe, Physic, Config, /*E_Object*/Spirits, E_Ground_Object, Delta.get_ticks());


	//	Projectile_Active(Bullet,Delta.get_ticks());

	//	J_Data.Character_variable_definer(Player);
	//	J_Data.King_Character_variable_giving(K_Data);


//		Graphic.Variable_Definer_Active(Player);
		
		
		Physic.Game_Physics(Spirits,Delta.get_ticks());
    /************************************************
	//	ALL ACTION PERFORMED HERE				   //
	************************************************/
	

		Graphic.Frame_Definer(Delta.get_ticks());

		
		//Player.Movement_Active(Delta.get_ticks());
		//Player.Game_Object_Interaction(Spirits);
	//	Player.Movement();
		//Player.Movement_ZXC(Bullet);

	//	AI_Handling_Movement_Active(Foe, Delta.get_ticks());
	//	AI_Handling_Behavior_Controller(Foe, Player, Delta.get_ticks());
	//	AI_Handling_Basic_Actions(Foe, Player);
		
		// Actions that happen in Menu Mode
		//Menu_GUI.Recticle_Functionality(Player);

		//Restart delta timer
        Delta.start();
	/************************************************
	//		GRAPHIC AREA. ALL ART RELATED FUNCTION //
	************************************************/


        //Set the camera
        Graphic.Set_Camera();
	

		//Render everything  
		Graphic.Layering(Spirits);
		//Graphic.Layering_Menu(Menu_GUI );
		
		// Find and free unneeded slaves
		Graphic.Free_Slave(Spirits);
      
		if (Left_Key == true){Apply_Surface( 0, 0, Character1,  Screen, &Character_Test_Clips[1] ) ;}
		if (Right_Key == true)  {Apply_Surface( 90, 0, Character1,  Screen, &Character_Test_Clips[1] ) ;}
		if (Up_Key == true) {Apply_Surface( 30, 0, Character1,  Screen, &Character_Test_Clips[1] ) ;}
		if (Down_Key == true) {Apply_Surface( 120, 0, Character1,  Screen, &Character_Test_Clips[1] ) ;}
		if (Space_Key == true) {Apply_Surface( 60, 0, Character1,  Screen, &Character_Test_Clips[1] ) ;}

		
        //Update the screen
        if( SDL_Flip( Screen ) == -1 )
        {
            return 1;
        }

    }

    //Clean up
	Clean_Up( Spirits );

	
	//Quit SDL
    SDL_Quit();
    return 0;
}
