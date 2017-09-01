#include "Function.h"


Rendering::Rendering()
{
	

	Sky_Line_Key = false;
	Transpancy_Skip = -1;

	Total_Floor_Objects = 0;
	Total_Float_Base_Objects = 0;
	Total_Character_Objects = 0;
	Total_Objects = 0;
	Total_Screen_Objects = 0;
	Order = 0;

	On_Screen_Type = 0;
	On_Screen_Object_Type = 0;
	On_Screen_Child_Num = 0;
	On_Screen_Frames = 0;

	Level_Width = 0;
	Level_Lenght = 0;

	Character_X = 0;
	Character_Y = 0;
	Character_Z = 0; 

	Magnitude = 0;

//	Level_Width = 0;
//	Level_Lenght = 0; 

	Character_State = 0;
	Button = 0;
	Degree = 0;
	
	Frame = 0;
	Frame_Start = 0;
	Frame_Go = 0;
	Frame_Stop = 0;
	Frame_Speed = 0;
	Frame_Animation = 0;

	Loop = false;
	Get_Loop_Started = false;
	Complex_Loop = false;

	Character_Altitude = 0;
	Animation_Exception = -1;
	Transparency = 0;
}

void Rendering::Set_Camera() 
 { 
	 enum {LEVEL_WIDTH, LEVEL_LENGHT};
	//Center the camera over the dot 
	Camera.x = ( Character_X   ) - SCREEN_WIDTH / 2; 
	Camera.y = ( Character_Z + 25 / 2  ) - SCREEN_HEIGHT / 2; 

	


	//Keep the camera in bounds. 
	if( Camera.x < 0 ) 
	{ 
		Camera.x = 0; 
	} 
	if( Camera.y < 0 ) 
	{ 
		Camera.y = 0; 
	} 
	if( Camera.x > Level_Width - Camera.w ) 
	{ 
		Camera.x = Level_Width - Camera.w; 
	} 
	if( Camera.y > Level_Lenght - Camera.h ) 
	{ 
		Camera.y = Level_Lenght - Camera.h; 
	} 
 } 

void Rendering::Shader_Setter()
{

		SDL_SetAlpha( Character1, SDL_SRCALPHA, 150 );
		SDL_SetAlpha( ShadowFloatTileSheet, SDL_SRCALPHA, 150 );
		SDL_SetAlpha( ShadowCryonTanryokuSheet, SDL_SRCALPHA, 100 ); 
		SDL_SetAlpha( TransparentFloatTileSheet, SDL_SRCALPHA, 100 );
	
	
}

int Rendering::Character_State_Of_Animation()
{

	// Step one, Figure out the button state
	// Step Two, Figure how the character is interacting with the enivornement
	// Step three, Figure out which way the character is facing. 
	//Step four, Sometimes get the magnitude to perform other actions
	switch (Button)
	{
		case NO_KEY:	switch (Character_State) //...........................................................
						{
							case GROUNDED:	switch (Degree) //11111111111111111111111111111111111111111111111
											{
												case UP_DIRECTION: if ((Magnitude > 0)&&(Magnitude <= 600)) {return SLIDE_UP; }
																	return IDLE_UP; 
																	break;
												case LEFT_DIRECTION: if ((Magnitude > 0)&&(Magnitude <= 600)) {return SLIDE_LEFT; } 
																	return IDLE_LEFT; 
																	break;
												case RIGHT_DIRECTION: if ((Magnitude > 0)&&(Magnitude <= 600)) {return SLIDE_RIGHT; } 
																	return IDLE_RIGHT; 
																	break;
												case DOWN_DIRECTION: if ((Magnitude > 0)&&(Magnitude <= 600)) {return SLIDE_DOWN; } 
																	return IDLE_DOWN; 
																	break;
												case LEFT_UP_DIRECTION: if ((Magnitude > 0)&&(Magnitude <= 600)) {return SLIDE_LEFTUP; } 
																	return IDLE_LEFTUP; 
																	break;
												case RIGHT_UP_DIRECTION: if ((Magnitude > 0)&&(Magnitude <= 600)) {return SLIDE_RIGHTUP; }	
																	return IDLE_RIGHTUP; 
																	break;
												case RIGHT_DOWN_DIRECTION: if ((Magnitude > 0)&&(Magnitude <= 600)) {return SLIDE_RIGHTDOWN; } 
																	return IDLE_RIGHTDOWN; 
																	break;
												case LEFT_DOWN_DIRECTION: if ((Magnitude > 0)&&(Magnitude <= 600)) {return SLIDE_LEFTDOWN; } 
																	return IDLE_RIGHTUP; 
																	break;
											}
							break;
							/*case MIDAIR:	switch (Degree) //11111111111111111111111111111111111111111111111
											{
												case FORWARD_DIRECTION: 
												case LEFT_DIRECTION: 
												case RIGHT_DIRECTION: 
												case BACKWARD_DIRECTION:
												case FORWARD_LEFT_DIRECTION: 
												case FOWARD_RIGHT_DIRECTION:
												case BACKWARD_RIGHT_DIRECTION: 
												case BACKWARD_LEFT_DIRECTION: break;
											}
							case  FALLING_THROUGH_FLOOR:	switch(Degree) //11111111111111111111111111111111111111111111111
															{
																case FORWARD_DIRECTION: 
																case LEFT_DIRECTION: 
																case RIGHT_DIRECTION: 
																case BACKWARD_DIRECTION:
																case FORWARD_LEFT_DIRECTION: 
																case FOWARD_RIGHT_DIRECTION:
																case BACKWARD_RIGHT_DIRECTION: 
																case BACKWARD_LEFT_DIRECTION: break;
															}
							*/
							case  STANDING_ON_TOP:	switch (Degree) //11111111111111111111111111111111111111111111111
													{
														case UP_DIRECTION: return IDLE_UP; break;
														case LEFT_DIRECTION: return IDLE_LEFT; break;
														case RIGHT_DIRECTION: return IDLE_RIGHT; break;
														case DOWN_DIRECTION: return IDLE_DOWN; break;
														case LEFT_UP_DIRECTION: return IDLE_LEFTUP; break;
														case RIGHT_UP_DIRECTION: return IDLE_RIGHTUP; break;
														case RIGHT_DOWN_DIRECTION: return IDLE_RIGHTDOWN; break;
														case LEFT_DOWN_DIRECTION: return IDLE_RIGHTUP; break;
													}
							break;
							/*case  HIT_FROM_BELOW:	switch(Degree) //11111111111111111111111111111111111111111111111
													{
														case FORWARD_DIRECTION: 
														case LEFT_DIRECTION: 
														case RIGHT_DIRECTION: 
														case BACKWARD_DIRECTION:
														case FORWARD_LEFT_DIRECTION: 
														case FOWARD_RIGHT_DIRECTION:
														case BACKWARD_RIGHT_DIRECTION: 
														case BACKWARD_LEFT_DIRECTION: break;
													}
							case  AGAINST_FRONT:	switch(Degree) //11111111111111111111111111111111111111111111111
													{
														case FORWARD_DIRECTION: 
														case LEFT_DIRECTION: 
														case RIGHT_DIRECTION: 
														case BACKWARD_DIRECTION:
														case FORWARD_LEFT_DIRECTION: 
														case FOWARD_RIGHT_DIRECTION:
														case BACKWARD_RIGHT_DIRECTION: 
														case BACKWARD_LEFT_DIRECTION: break;
													}
							case  AGAINST_BACK:		switch(Degree) //11111111111111111111111111111111111111111111111
													{
														case FORWARD_DIRECTION: 
														case LEFT_DIRECTION: 
														case RIGHT_DIRECTION: 
														case BACKWARD_DIRECTION:
														case FORWARD_LEFT_DIRECTION: 
														case FOWARD_RIGHT_DIRECTION:
														case BACKWARD_RIGHT_DIRECTION: 
														case BACKWARD_LEFT_DIRECTION: break;
													}
							case  AGAINST_LEFT_SIDE:		switch(Degree) //11111111111111111111111111111111111111111111111
														{
															case FORWARD_DIRECTION: 
															case LEFT_DIRECTION: 
															case RIGHT_DIRECTION: 
															case BACKWARD_DIRECTION:
															case FORWARD_LEFT_DIRECTION: 
															case FOWARD_RIGHT_DIRECTION:
															case BACKWARD_RIGHT_DIRECTION: 
															case BACKWARD_LEFT_DIRECTION: break;
														}
							case  AGAINST_RIGHT_SIDE:	switch(Degree) //11111111111111111111111111111111111111111111111
														{
															case FORWARD_DIRECTION: 
															case LEFT_DIRECTION: 
															case RIGHT_DIRECTION: 
															case BACKWARD_DIRECTION:
															case FORWARD_LEFT_DIRECTION: 
															case FOWARD_RIGHT_DIRECTION:
															case BACKWARD_RIGHT_DIRECTION: 
															case BACKWARD_LEFT_DIRECTION: break;
														}*/
						}
			break;
		case UP:		switch (Character_State) //...........................................................
						{
							case GROUNDED:	switch (Degree) //11111111111111111111111111111111111111111111111
											{
												case UP_DIRECTION: return WALK_UP; break;
												//case LEFT_DIRECTION: return IDLE_LEFT; break;
												//case RIGHT_DIRECTION: return IDLE_RIGHT; break;
												//case DOWN_DIRECTION: return WALK_DOWN; break;
												//case LEFT_UP_DIRECTION: return IDLE_LEFTUP; break;
												//case RIGHT_UP_DIRECTION: return WALK_RIGHTUP; break;
												//case RIGHT_DOWN_DIRECTION: return IDLE_RIGHTDOWN; break;
												//case LEFT_DOWN_DIRECTION: return WALK_LEFTDOWN; break;
											}
							break;
						}
			break;
		case UP_LEFT:	case GROUNDED:	switch (Degree) //11111111111111111111111111111111111111111111111
											{
												//case UP_DIRECTION: return WALK_UP; break;
												//case LEFT_DIRECTION: return IDLE_LEFT; break;
												//case RIGHT_DIRECTION: return IDLE_RIGHT; break;
												//case DOWN_DIRECTION: return WALK_DOWN; break;
												case LEFT_UP_DIRECTION: return WALK_LEFTUP; break;
												//case RIGHT_UP_DIRECTION: return WALK_RIGHTUP; break;
												//case RIGHT_DOWN_DIRECTION: return IDLE_RIGHTDOWN; break;
												//case LEFT_DOWN_DIRECTION: return WALK_LEFTDOWN; break;
											}
							break;			
			break;
		case UP_RIGHT:	switch (Character_State) //...........................................................
						{
							case GROUNDED:	switch (Degree) //11111111111111111111111111111111111111111111111
											{
												//case UP_DIRECTION: return IDLE_UP; break;
												//case LEFT_DIRECTION: return IDLE_LEFT; break;
												//case RIGHT_DIRECTION: return IDLE_RIGHT; break;
												//case DOWN_DIRECTION: return WALK_DOWN; break;
												//case LEFT_UP_DIRECTION: return IDLE_LEFTUP; break;
												case RIGHT_UP_DIRECTION: return WALK_RIGHTUP; break;
												//case RIGHT_DOWN_DIRECTION: return IDLE_RIGHTDOWN; break;
												//case LEFT_DOWN_DIRECTION: return WALK_LEFTDOWN; break;
											}
							break;
						}				
			break;/*
		case UP_DOWN:	switch (Character_State) //...........................................................
						{
							case GROUNDED:	Z_Coord -= 10; Z_Vel -= 500; break;
							case STANDING_ON_TOP: Z_Coord -= 10; Z_Vel -= 100; break;
						} 
			break;
		case UP_SPACE:	switch (Character_State) //...........................................................
						{
							case GROUNDED:	Z_Coord -= 10; Z_Vel -= 500; break;
							case STANDING_ON_TOP: Z_Coord -= 10; Z_Vel -= 100; break;
						}
			break;
		case UP_RIGHT_SPACE:	switch (Character_State) //...........................................................
								{
									case GROUNDED:	Z_Coord -= 10; Z_Vel -= 500; break;
									case STANDING_ON_TOP: Z_Coord -= 10; Z_Vel -= 100; break;
								}
			break;
		case UP_LEFT_SPACE:		switch (Character_State) //...........................................................
								{
									case GROUNDED:	Z_Coord -= 10; Z_Vel -= 500; break;
									case STANDING_ON_TOP: Z_Coord -= 10; Z_Vel -= 100; break;
								}
			break;*/
		case DOWN:		switch (Character_State) //...........................................................
						{
							case GROUNDED:	switch (Degree) //11111111111111111111111111111111111111111111111
											{
												//case UP_DIRECTION: return IDLE_UP; break;
												//case LEFT_DIRECTION: return IDLE_LEFT; break;
												//case RIGHT_DIRECTION: return IDLE_RIGHT; break;
												case DOWN_DIRECTION: return WALK_DOWN; break;
												//case LEFT_UP_DIRECTION: return IDLE_LEFTUP; break;
												//case RIGHT_UP_DIRECTION: return IDLE_RIGHTUP; break;
												//case RIGHT_DOWN_DIRECTION: return IDLE_RIGHTDOWN; break;
												//case LEFT_DOWN_DIRECTION: return WALK_LEFTDOWN; break;
											}
							break;
						}	
			break;
		case DOWN_LEFT:	switch (Character_State) //...........................................................
						{
							case GROUNDED:	switch (Degree) //11111111111111111111111111111111111111111111111
											{
												//case UP_DIRECTION: return IDLE_UP; break;
												//case LEFT_DIRECTION: return IDLE_LEFT; break;
												//case RIGHT_DIRECTION: return IDLE_RIGHT; break;
												//case DOWN_DIRECTION: return IDLE_DOWN; break;
												//case LEFT_UP_DIRECTION: return IDLE_LEFTUP; break;
												//case RIGHT_UP_DIRECTION: return IDLE_RIGHTUP; break;
												//case RIGHT_DOWN_DIRECTION: return IDLE_RIGHTDOWN; break;
												case LEFT_DOWN_DIRECTION: return WALK_LEFTDOWN; break;
											}
							break;
						}
			break;
			
		case DOWN_RIGHT:	switch (Character_State) //...........................................................
							{
								case GROUNDED:	switch (Degree) //11111111111111111111111111111111111111111111111
												{
													//case UP_DIRECTION: return IDLE_UP; break;
													//case LEFT_DIRECTION: return IDLE_LEFT; break;
													//case RIGHT_DIRECTION: return IDLE_RIGHT; break;
													//case DOWN_DIRECTION: return IDLE_DOWN; break;
													//case LEFT_UP_DIRECTION: return IDLE_LEFTUP; break;
													//case RIGHT_UP_DIRECTION: return IDLE_RIGHTUP; break;
													case RIGHT_DOWN_DIRECTION: return WALK_RIGHTDOWN; break;
													//case LEFT_DOWN_DIRECTION: return WALK_LEFTDOWN; break;
												}
								break;
							}
			break;
		/*case DOWN_SPACE:	switch (Character_State) //...........................................................
							{
								case GROUNDED:	Z_Coord -= 10; Z_Vel -= 500; break;
								case STANDING_ON_TOP: Z_Coord -= 10; Z_Vel -= 100; break;
							}
			break;
		case DOWN_RIGHT_SPACE:	switch (Character_State) //...........................................................
								{
									case GROUNDED:	Z_Coord -= 10; Z_Vel -= 500; break;
									case STANDING_ON_TOP: Z_Coord -= 10; Z_Vel -= 100; break;
								}
			break;

		case DOWN_LEFT_SPACE:	switch (Character_State) //...........................................................
								{
									case GROUNDED:	Z_Coord -= 10; Z_Vel -= 500; break;
									case STANDING_ON_TOP: Z_Coord -= 10; Z_Vel -= 100; break;
								}*/
			break;
		case LEFT:	switch (Character_State) //...........................................................
					{		case GROUNDED:	switch (Degree) //11111111111111111111111111111111111111111111111
											{
												case UP_DIRECTION: return IDLE_UP; break;
												case LEFT_DIRECTION: return WALK_LEFT; break;
												case RIGHT_DIRECTION: return IDLE_RIGHT; break;
												case DOWN_DIRECTION: return IDLE_DOWN; break;
												case LEFT_UP_DIRECTION: return IDLE_LEFTUP; break;
												case RIGHT_UP_DIRECTION: return IDLE_RIGHTUP; break;
												case RIGHT_DOWN_DIRECTION: return IDLE_RIGHTDOWN; break;
												case LEFT_DOWN_DIRECTION: return IDLE_RIGHTUP; break;
											}
							break;
					}
			break;/*
		case LEFT_RIGHT:	switch (Character_State) //...........................................................
							{
								case GROUNDED:	Z_Coord -= 10; Z_Vel -= 500; break;
								case STANDING_ON_TOP: Z_Coord -= 10; Z_Vel -= 100; break;
							}
			break;
		case  LEFT_SPACE:	switch (Character_State) //...........................................................
							{
								case GROUNDED:	Z_Coord -= 10; Z_Vel -= 500; break;
								case STANDING_ON_TOP: Z_Coord -= 10; Z_Vel -= 100; break;
							}
			break;*/
		case RIGHT:		switch (Character_State) //...........................................................
					{		case GROUNDED:	switch (Degree) //11111111111111111111111111111111111111111111111
											{
												case UP_DIRECTION: return IDLE_UP; break;
												case LEFT_DIRECTION: return IDLE_LEFT; break;
												case RIGHT_DIRECTION: return WALK_RIGHT; break;
												case DOWN_DIRECTION: return IDLE_DOWN; break;
												case LEFT_UP_DIRECTION: return IDLE_LEFTUP; break;
												case RIGHT_UP_DIRECTION: return IDLE_RIGHTUP; break;
												case RIGHT_DOWN_DIRECTION: return IDLE_RIGHTDOWN; break;
												case LEFT_DOWN_DIRECTION: return IDLE_RIGHTUP; break;
											}
							break;
					}
			break;/*
		case RIGHT_SPACE:	switch (Character_State) //...........................................................
							{
								case GROUNDED:	Z_Coord -= 10; Z_Vel -= 500; break;
								case STANDING_ON_TOP: Z_Coord -= 10; Z_Vel -= 100; break;
							}
			break;
		case Z:		switch (Character_State) //...........................................................
					{
						case GROUNDED:	Z_Coord -= 10; Z_Vel -= 500; break;
						case STANDING_ON_TOP: Z_Coord -= 10; Z_Vel -= 100; break;
					}	
			break;
		
		case SPACE:		switch (Character_State) //...........................................................
						{
							case GROUNDED:	Z_Coord -= 10; Z_Vel -= 500; break;
							case STANDING_ON_TOP: Z_Coord -= 10; Z_Vel -= 100; break;
						}
			break;*/
	}

	return 0;
}

int Rendering::Character_State_Of_Condition_Animation()
{

	// Step one, Figure out which exception animation needs to be played
	// Step Two, Figure how the character is interacting with the enivornement
	// Step three, Figure out which way the character is facing. 
	// Step four, Sometimes get the magnitude to perform other actions
	
	switch (Animation_Exception)
	{
		case  FALL_DAMAGED:	switch (Degree) //11111111111111111111111111111111111111111111111
							{
								case UP_DIRECTION: return IDLE_UP; break;
								case LEFT_DIRECTION: return IDLE_LEFT; break;
								case RIGHT_DIRECTION: return IDLE_RIGHT; break;
								case DOWN_DIRECTION: return IDLE_DOWN; break;
								case LEFT_UP_DIRECTION: return IDLE_LEFTUP; break;
								case RIGHT_UP_DIRECTION: return IDLE_RIGHTUP; break;
								case RIGHT_DOWN_DIRECTION: return IDLE_RIGHTDOWN; break;
								case LEFT_DOWN_DIRECTION: return IDLE_RIGHTUP; break;
							}
							break;
	}
			         

	return 0;
}


void Rendering::Frame_Definer(Uint32 deltaTicks)
{
	////////////////////////////////////////////////////////////////////
	// PART ONE OF THIS FUNCTION!
	////////////////////////////////////////////////////////////////////
	

	//SETTING INSTRUCTION

	// There are two modes, single animation and looped animation. Set the first frame of the animation
	// The set frame stop the last frame of the animation + 1. 
	// NO CONFLICTING FRAMES. 

	
	if (Frame_Start < Frame_Go) {Loop = true;}
	if (Frame_Start == Frame_Go) {Loop = false;}

	
	// These animation are mostly shared between character. Unqiue stuff require a new function and conditioning.
	switch (Frame_Animation)
	{
		case IDLE_LEFT:			Frame_Start = 0; Frame_Go = 0;  Frame_Stop = 0; Frame_Speed = SPEED_III; 
			break;
		case IDLE_LEFTDOWN:		Frame_Start = 1; Frame_Go = 1;  Frame_Stop = 1; Frame_Speed = SPEED_III; 
			break;
		case IDLE_DOWN:			Frame_Start = 2; Frame_Go = 2;  Frame_Stop = 2; Frame_Speed = SPEED_III; 
			break;
		case IDLE_RIGHTDOWN:	Frame_Start = 3; Frame_Go = 3;  Frame_Stop = 3; Frame_Speed = SPEED_III; 
			break;
		case IDLE_RIGHT:		Frame_Start = 4; Frame_Go = 4;  Frame_Stop = 4; Frame_Speed = SPEED_III; 
			break;
		case IDLE_RIGHTUP:		Frame_Start = 5; Frame_Go = 5;  Frame_Stop = 5; Frame_Speed = SPEED_III; 
			break;
		case IDLE_UP:			Frame_Start = 6; Frame_Go = 6;  Frame_Stop = 6; Frame_Speed = SPEED_III; 
			break;
		case IDLE_LEFTUP:		Frame_Start = 7; Frame_Go = 7;  Frame_Stop = 7; Frame_Speed = SPEED_III;
			break;
		case WALK_LEFT:			Frame_Start = 0; Frame_Go = 8;  Frame_Stop = 13; Frame_Speed = SPEED_III; 
			break;
		case WALK_LEFTDOWN:		Frame_Start = 0; Frame_Go = 14;  Frame_Stop = 19; Frame_Speed = SPEED_III; 
			break;
		case WALK_DOWN:			Frame_Start = 0; Frame_Go = 20;  Frame_Stop = 25; Frame_Speed = SPEED_III; 
			break;
		case WALK_RIGHTDOWN:	Frame_Start = 0; Frame_Go = 26;  Frame_Stop = 31; Frame_Speed = SPEED_III; 
			break;
		case WALK_RIGHT:		Frame_Start = 0; Frame_Go = 32;  Frame_Stop = 37; Frame_Speed = SPEED_III; 
			break;
		case WALK_RIGHTUP:		Frame_Start = 0; Frame_Go = 38;  Frame_Stop = 43; Frame_Speed = SPEED_III; 
			break;
		case WALK_UP:			Frame_Start = 0; Frame_Go = 44;  Frame_Stop = 49; Frame_Speed = SPEED_III; 
			break;
		case WALK_LEFTUP:		Frame_Start = 0; Frame_Go = 50;  Frame_Stop = 55; Frame_Speed = SPEED_III; 
			break;
		case SLIDE_LEFT:		Frame_Start = 0; Frame_Go = 56;  Frame_Stop = 57; Frame_Speed = SPEED_IV; 
			break;
		case SLIDE_LEFTDOWN:	Frame_Start = 0; Frame_Go = 58;  Frame_Stop = 59; Frame_Speed = SPEED_IV; 
			break;
		case SLIDE_DOWN:		Frame_Start = 0; Frame_Go = 60;  Frame_Stop = 61; Frame_Speed = SPEED_IV; 
			break;
		case SLIDE_RIGHTDOWN:	Frame_Start = 0; Frame_Go = 62;  Frame_Stop = 63; Frame_Speed = SPEED_IV; 
			break;
		case SLIDE_RIGHT:		Frame_Start = 0; Frame_Go = 64;  Frame_Stop = 65; Frame_Speed = SPEED_IV; 
			break;
		case SLIDE_RIGHTUP:		Frame_Start = 0; Frame_Go = 66;  Frame_Stop = 67; Frame_Speed = SPEED_IV; 
			break;
		case SLIDE_UP:			Frame_Start = 0; Frame_Go = 68;  Frame_Stop = 69; Frame_Speed = SPEED_IV; 
			break; 
		case SLIDE_LEFTUP:		Frame_Start = 0; Frame_Go = 70;  Frame_Stop = 71; Frame_Speed = SPEED_IV; 
			break;

	}
	/////////////////////////////////////////////////////////////////////
	// PART TWO OF THIS FUNCTION!
	/////////////////////////////////////////////////////////////////////

	switch (Loop)
	{
		case true: if (Complex_Loop == false)
				   {
						if (Get_Loop_Started == false)
						{
							Frame = Frame_Go;
							Get_Loop_Started = true;
						}
						if (Get_Loop_Started == true)
						{
							if (Frame > Frame_Stop)
							{
								Frame = Frame_Go;
							}
						}
				   }
			break;
		case false: Frame = Frame_Start; Frame_Speed = SPEED_OMEGAMATHETA; Get_Loop_Started = false;
			break;
	}

	Frame += Frame_Speed * ( deltaTicks / 1000.f );
}

void Rendering::Frame_Range_On_Screen()
{
	//regular on screen type handling
	switch (On_Screen_Object_Type)
	{
		case  ON_SCREEN:  						
			switch (On_Screen_Type)
			{
			case  YS_GAUGE:	On_Screen_Frame_Start = CLIP_GAUGE_YS; On_Screen_Frame_End = CLIP_GAUGE_YS; break;
			case  CYRON_GAUGE:	On_Screen_Frame_Start = CLIP_GAUGE_CT; On_Screen_Frame_End = CLIP_GAUGE_CT; break;
			case  CXX120_GAUGE:	 On_Screen_Frame_Start = CLIP_GAUGE_CXX; On_Screen_Frame_End = CLIP_GAUGE_CXX; break;
			case  TARGET_REDICAL:	On_Screen_Frame_Start =  CLIP_TARGET_REDICAL; On_Screen_Frame_End =  CLIP_TARGET_REDICAL; break;
			case  HEALTH_BAR:	On_Screen_Frame_Start =  HEALTH_0; On_Screen_Frame_End =  HEALTH_0; break;
			}
			break;	


		case  ON_SCREEN_CONFIG:  						
			switch (On_Screen_Type)
			{
				case	RETURN_MENU_BUTTON: On_Screen_Frame_Start =  CLIP_MENU_RETURN_BUTTON; On_Screen_Frame_End =  CLIP_MENU_RETURN_BUTTON; break;
				case	SWITCH_MENU_BUTTON:  On_Screen_Frame_Start =  CLIP_MENU_SWITCH_BUTTON; On_Screen_Frame_End =   CLIP_MENU_SWITCH_BUTTON; break;
				case	SWITCH_MENU_BUTTON_EXPAND1:  
					
													On_Screen_Frame_Start = CLIP_MENU_SWITCH_BUTTON_EXPAND1; On_Screen_Frame_End =   CLIP_MENU_SWITCH_BUTTON_EXPAND1;  
													On_Screen_Child_Frame_Start[0] = CLIP_MENU_SWITCH_YS_ICON; On_Screen_Child_Frame_End[0] =  CLIP_MENU_SWITCH_YS_ICON;
													On_Screen_Child_Frame_Start[1] = CLIP_MENU_SWITCH_CYRON_ICON; On_Screen_Child_Frame_End[1] = CLIP_MENU_SWITCH_CYRON_ICON;
													On_Screen_Child_Frame_Start[2] = CLIP_MENU_SWITCH_CXX120_ICON; On_Screen_Child_Frame_End[2] = CLIP_MENU_SWITCH_CXX120_ICON;
														 break;
				case	SAVE_MENU_BUTTON:  On_Screen_Frame_Start =  CLIP_MENU_SAVE_BUTTON; On_Screen_Frame_End =   CLIP_MENU_SAVE_BUTTON; break;
			}		
			break;	
	}
}

void Rendering::Frame_State_On_Screen(Soul *Spirit[])
{

	//WHAT NEEDED TO DETERMINE THE NEXT FRAME.
	//STEP1: Get Direction
	//STEP2: Get Animation to be played number

	//Conditional frame setting
	switch (On_Screen_Object_Type)
	{
		///////////////////////////////////////
		//REGULAR TYPE
		///////////////////////////////////////
		case  ON_SCREEN:  						
			switch (On_Screen_Type)
			{
				case  HEALTH_BAR:	Screen_Object_Condition_Check_HEALTH_BAR(Spirit);

					break;
			}
			break;	

		///////////////////////////////////////
		//CONFIGURATION TYPE
		///////////////////////////////////////
		case  ON_SCREEN_CONFIG:  						
			switch (On_Screen_Type)
			{
				case	RETURN_MENU_BUTTON:		//On_Screen_Frame_Start =  CLIP_MENU_RETURN_BUTTON; On_Screen_Frame_End =  CLIP_MENU_RETURN_BUTTON;
					break;
			}		
			break;	
	}
}

void Rendering::Frame_Handle_On_Screen( Soul *Spirit[], int condition)
{

	Frame_Range_On_Screen();


	
		// if the object has animations to play
		if (Screen_Animated_Key[condition] == true)
		{	
			//Evalulate the conditions for playing an animation and the frames that are needed

			//If they need to play an animation right now
		//	if (Spirit[Screen_Object_Track[condition]]->Get_Active_Animation_Key() == true)
		//	{
				Frame_State_On_Screen(Spirit);
		//	}
		}

		else 
		{
			On_Screen_Frames = On_Screen_Frame_Start;
			 
			for(int z = 0; z < Screen_Child_Num[condition]; z++)
			{
				On_Screen_Frames_Children[z] = On_Screen_Child_Frame_Start[z];
			}
		}
}

void Rendering::Optimization_Variable_Definer( Soul *Spirit[] )
{

	Total_Floor_Objects = 0;
	Total_Float_Base_Objects = 0;
	Total_Character_Objects = 0;
	Total_Smart_AI_Objects = 0; 
	Total_Objects = 0;
	Total_Screen_Objects = 0;
	//////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////
	//Floor variable definer
	for (int a = 0; a < MAX_GAME_OBJECTS ; a++ )
	{
		if(Spirit[a] != NULL)
		{
			if(Spirit[a]->Get_Object_Type() ==  FLOOR)
			{
				Track_Floor_Objects[Total_Floor_Objects] =  a;
				Total_Floor_Objects++;
				
			
			}

		}
		else 
		{
			break;
		}
		
	}

	//Remaining floor values
	for (int s = Total_Floor_Objects; s < MAX_GAME_OBJECTS; s++ )
	{
			Track_Floor_Objects[s] =  -1;
	}
	
	
	///////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////
	//Shadow Square Variables
	for (int a = 0; a < MAX_GAME_OBJECTS ; a++ )
	{
		if(Spirit[a] != NULL)
		{
			if((Spirit[a]->Get_Object_Type() ==  FLOAT) || (Spirit[a]->Get_Object_Type() ==  CONFIG))
			{
				
				Track_Float_Base_Objects[Total_Float_Base_Objects] = a;
				Total_Float_Base_Objects++;
			}

		}
		else 
		{
			break;
		}
		
	}

	//Remaining Shadow Square values
	for (int s = Total_Float_Base_Objects; s < MAX_GAME_OBJECTS; s++ )
	{
			Track_Float_Base_Objects[s] =  -1;
	}


	///////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////
	//Character Base 
	for (int a = 0; a < MAX_GAME_OBJECTS ; a++ )
	{
		if(Spirit[a] != NULL)
		{
			if((Spirit[a]->Get_Object_Type() ==  CYRON_TANRYOKU) || (Spirit[a]->Get_Object_Type() == THE_YS_GUY) || (Spirit[a]->Get_Object_Type() == CXX120))
			{
				
				Track_Character_Base_Objects[Total_Character_Objects] = a;
				Total_Character_Objects++;
			}

		}
		else 
		{
			break;
		}
		
	}


	for (int s = Total_Character_Objects; s < MAX_GAME_OBJECTS; s++ )
	{
			Track_Character_Base_Objects[s] =  -1;
	}
	///////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////
	//AI Base 
	for (int a = 0; a < MAX_GAME_OBJECTS ; a++ )
	{
		if(Spirit[a] != NULL)
		{
			if((Spirit[a]->Get_Object_Type() ==  AI_SMART))
			{
				
				Track_Smart_AI_Base_Objects[Total_Smart_AI_Objects] = a;
				Total_Smart_AI_Objects++;
			}

		}
		else 
		{
			break;
		}
		
	}


	for (int s = Total_Smart_AI_Objects; s < MAX_GAME_OBJECTS; s++ )
	{
			Track_Smart_AI_Base_Objects[s] =  -1;
	}
	

	//////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////
	//Screen objects
	for (int a = 0; a < MAX_GAME_OBJECTS ; a++ )
	{
		if(Spirit[a] != NULL)
		{
			if((Spirit[a]->Get_Object_Type() ==  ON_SCREEN) || (Spirit[a]->Get_Object_Type() ==  ON_SCREEN_BG)||(Spirit[a]->Get_Object_Type() ==  ON_SCREEN_CONFIG))
			{
				
				Screen_Object_Track[Total_Screen_Objects] = a;
				Screen_Object_Type[Total_Screen_Objects] = Spirit[a]->Get_Object_Type();
				Screen_Type[Total_Screen_Objects] =  Spirit[a]->Get_Type();
				//Gameplay mode usage. 
				Screen_Object_Stat[Total_Screen_Objects] = Spirit[a]->Get_Gate_Type();
				Screen_Child_Num[Total_Screen_Objects] = Spirit[a]->Get_Child_Num();
				Screen_Animated_Key[Total_Screen_Objects] = Spirit[a]->Get_Animated_Key();


				Total_Screen_Objects++;

				

			}

		}
		else 
		{
			break;
		}
		
	}

	for (int s = Total_Screen_Objects; s < MAX_GAME_OBJECTS; s++ )
	{
			Screen_Object_Track[s] = -1;
			Screen_Object_Type[s] = -1;
			Screen_Object_Stat[s] = 1;
			Screen_Type[s] =  -1;
			if (s < 20)
			{
				Screen_Child_Num[s] = 0;
			}
		
			Screen_Animated_Key[s] = false;

	}
	

	//////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////
	//Floating Object definer/ Objects not on screen or floor
	for (int a = 0; a < MAX_GAME_OBJECTS ; a++ )
	{
		if(Spirit[a] != NULL)
		{
			if((Spirit[a]->Get_Object_Type() !=  FLOOR) &&(Spirit[a]->Get_Object_Type() !=  ON_SCREEN) && (Spirit[a]->Get_Object_Type() !=  ON_SCREEN_BG))
			{
				if  ( (Spirit[a]->Get_Object_Type() !=  ON_SCREEN_CONFIG))
				{
					Object_Track[Total_Objects] = a;
					Object_Physics[Total_Objects] = Spirit[a]->Get_Gravity_Physics();
					Object_Base[Total_Objects] = Spirit[a]->Get_Y();
					Object_Type[Total_Objects] = Spirit[a]->Get_Object_Type();
					Object_Elevation[Total_Objects] = Spirit[a]->Get_Object_Elevation();

					Total_Objects++;
				}
			}

		}
		else 
		{
			break;
		}
		
	}

	//Remaining float objects
	for (int s = Total_Objects; s < MAX_GAME_OBJECTS; s++ )
	{
			Object_Track[s] = -1;
			Object_Physics[s] = -1;
			Object_Base[s] = -1;
			Object_Type[s] = -1;
			Object_Elevation[s] = -1;
	}
	//////////////////////////////////////////////////////////////////
	///////////// CORRECT THE SLAVE ADDRESS/////////////////////////////////////////////////////




}

void Rendering::Layering( Soul *Spirit[]  )
{
	if(Game_Mode == GAMEPLAY_MODE)
	{

	/*************************************************
	//  EVERYTHING THAT CAN BE LAYERED MANULALLY   //
	*************************************************/
		if (Sky_Line_Key == false)
		{
			//PRINT FLOOR;
			for (int a = 0; a < Total_Floor_Objects; a++ )
			{
				Spirit[Track_Floor_Objects[a]]->Show();
			}
			
			//PRINT FLOAT BASE
			for (int a = 0; a < Total_Float_Base_Objects; a++ )
			{
				Spirit[Track_Float_Base_Objects[a]]->Show_Base();
			}
			//PRINT THE CHARACTERS SHADOWS
			for (int a = 0; a < Total_Character_Objects ; a++ )
			{
				if (Spirit[Track_Character_Base_Objects[a]]->Get_Object_Type() ==  Selected_Character)
				{
					Spirit[Track_Character_Base_Objects[a]]->Show_Base();
				}
			}		
			//PRINT AI SHADOW
			for (int a = 0; a < Total_Smart_AI_Objects ; a++ )
			{
					Spirit[Track_Smart_AI_Base_Objects[a]]->Show_Base();
			}			
		}

		// PRINT SKYLINE VIEW
		Sky_Line_View(Spirit);
	


		//Calculate render order using y axis values
		for (int tz = 0; tz <  LV1_LENGHT; tz++)
		{			
			// Go through all found object
			for (int a = 0; a < Total_Objects ; a++ )
			{	
				//Figure out if position needs updating
				if (Object_Physics[a] != STATIC_G)
				{
					//If the position is equal to the number
					if (Spirit[Object_Track[a]]->Get_Center_Base() == tz)		
					{						
							Render_Order_Optimizate[Order] = a;
							Render_Order_Optimizate_Past[Order] = a;
							Render_Order[Order] = Object_Track[a];
							Render_Order_Past[Order] =  Object_Track[a];
					
							Order++;								
					}
				}	
				else if (Object_Physics[a] == STATIC_G)
				{
					if (Object_Base[a] == tz)		
					{	
						Render_Order_Optimizate[Order] = a;
						Render_Order_Optimizate_Past[Order] = a;
						Render_Order[Order] = Object_Track[a];
						Render_Order_Past[Order] =  Object_Track[a];
						
						Order++;
					}
				}
			}
		}
	
		
		
		//Alter render order base on collision and object elevation
		for (int a = 0; a < Total_Objects ; a++ )
		{	
			for (int z = 0; z < Total_Objects ; z++ )
			{	
				// Check for collision
				if((Square_Object_Detection(Spirit[Render_Order[a]]->Get_Objects_Base() , Spirit[Render_Order[z]]->Get_Objects_Base())== true))
				{
					//If a is higher than z.
					if (Spirit[Render_Order[a]]->Get_Object_Elevation() > Spirit[Render_Order[z]]->Get_Object_Elevation() )
					{	
						// if a rendered before z
						if (a < z)
						{
							
							for (int p = a ; p < z; p++ )
							{
								Render_Order[p] = Render_Order[p + 1];	//Render_Order_Past[p + 1];	
								Render_Order_Optimizate[p] = Render_Order_Optimizate[p + 1];
							}
							// Set the first value and automatically do the rest
							Render_Order[z] = Render_Order_Past[a];
							Render_Order_Optimizate[z] = Render_Order_Optimizate_Past[a];
							// update the order list
							for (int p = 0; p < Total_Objects ; p++ )
							{
								Render_Order_Past[p] = Render_Order[p];	
								Render_Order_Optimizate_Past[p] = Render_Order_Optimizate[p];
							}
							
						}

					}
				}	
			}	
		}

	


		//PRINT FLOAT OBJECT IN ORDER
		for (int a = 0; a < Total_Objects ; a++ )
		{
			
			if(Object_Type[Render_Order_Optimizate[a]] ==  AI_SMART)
			{
				
				Spirit[Render_Order[a]]->Show((int)Frame);
			}

			if(Object_Type[Render_Order_Optimizate[a]] ==  CONFIG)
			{
				Spirit[Render_Order[a]]->Show();
			}

			if(Object_Type[Render_Order_Optimizate[a]] ==  FLOAT)
			{
				if (Transparented(Spirit, a) == false)
				{
					Spirit[Render_Order[a]]->Show();
				}
				else
				{
					Spirit[Render_Order[a]]->Show_Graphic_Fx_Transparancy();
				}

			}
					
			if(Object_Type[Render_Order_Optimizate[a]] == Selected_Character)
			{
				
				Drop_Shadow(Spirit);
				Spirit[Render_Order[a]]->Show((int)Frame);
				Shadowed(Spirit);
			}	
		}
		Order = 0;
		
		
		
	
		for (int a = 0; a < Total_Screen_Objects ; a++ )
		{
			if (Screen_Object_Type[a] ==  ON_SCREEN)
			{	
				if(Screen_Object_Stat[a] == GAMEPLAY_MODE)
				{
					if(Spirit[Screen_Object_Track[a]]->Get_Alive_Key() == true)
					{
						On_Screen_Type =  Screen_Type[a];
						On_Screen_Object_Type =  Screen_Object_Type[a];
					
						//Handles On screen frames
						Frame_Handle_On_Screen(Spirit, a);


						//On_Screen_Type = Spirit[Screen_Object_Track[a]]->Get_Type();
 						Spirit[Screen_Object_Track[a]]->Show(On_Screen_Frames);
					}
				}	
			}
		}

		//Decide to render On_Screen_BG_Object
		for (int a = 0; a < Total_Screen_Objects ; a++ )
		{
			if (Screen_Object_Type[a] ==  ON_SCREEN_BG)
			{
				if(Screen_Object_Stat[a] == GAMEPLAY_MODE)
				{
					if (Spirit[Screen_Object_Track[a]]->Get_Render_Key() == true)
					{
						Spirit[Screen_Object_Track[a]]->Show();
					}
				}
			}
		}


		//Darkens the object when under a shadow.
		
		//PRINT SCREEN OBJECTS
		//player.Show_Character_Gauge();

			//	Show_Screen_Objects();
			//}*/

		//Apply_Surface( 0, 0, ScreenEffects,  Screen, &Screen_Effects_Clips[1] ) ;
	}
	////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////
	//////////////////////////////////////////////////
	//////////////////////////////////////
	////////////////////////////
	///////////////////
	//////////
	////
	//
	
	if(Game_Mode == SAVE_MENU)
	{
		SDL_SetAlpha( ScreenEffects, SDL_SRCALPHA, 255 );
		//PRINT BACKGROUNDS
		for (int a = 0; a < Total_Screen_Objects ; a++ )
		{
			if (Screen_Object_Type[a] ==  ON_SCREEN_BG)
			{
				if(Screen_Object_Stat[a] == SAVE_MENU)
				{
					if (Spirit[Screen_Object_Track[a]]->Get_Render_Key() == true)
					{
						Spirit[Screen_Object_Track[a]]->Show();
					}
				}
			}
		}

		// PRINT BUTTONS
		for (int a = 0; a < Total_Screen_Objects ; a++ )
		{
			if (Screen_Object_Type[a] !=  ON_SCREEN_BG)
			{
				if(Spirit[Screen_Object_Track[a]]->Get_Alive_Key() == true)
				{
					if(Spirit[Screen_Object_Track[a]]->Get_Gate_Type() == SAVE_MENU)
					{
						Master_Link = Spirit[Screen_Object_Track[a]]->Get_Chain_Link();

						On_Screen_Type =  Screen_Type[a];
						On_Screen_Object_Type =  Screen_Object_Type[a];
						On_Screen_Child_Num =  Screen_Child_Num[a];
						//Handles On screen frames
						Frame_Handle_On_Screen(Spirit, a);

						//if (On_Screen_Type == RETURN_MENU_BUTTON)
						//{
							//Spirit[Screen_Object_Track[a]]->Show(On_Screen_Frames);
						//}
						//if (On_Screen_Type == SWITCH_MENU_BUTTON)
						//{
							//Spirit[Screen_Object_Track[a]]->Show(On_Screen_Frames);
						//}

						//if (On_Screen_Type == SWITCH_MENU_BUTTON)
						//{
							//Spirit[Screen_Object_Track[a]]->Show(On_Screen_Frames);
						//}

						//if (On_Screen_Type ==   TARGET_REDICAL) 
						//{
							Spirit[Screen_Object_Track[a]]->Show(On_Screen_Frames);
							Text_Speak( Spirit);
							if ( Screen_Child_Num[a] != 0 )
							{
								for (int c = 0; c <  Screen_Child_Num[a]; c++)
								{
									Spirit[Screen_Object_Track[a]]->Show_Children(c , On_Screen_Frames_Children[c]);
								}
							}
					}	
				}
			}
		}
	}
}

void Rendering::Variable_Update_Inactive(External_Configuration config)
{
	int LEVEL_WIDTH = 0; 
	int LEVEL_LENGHT = 1;


	Level_Width = config.Get_Level_Width_Lenght(LEVEL_WIDTH);
	Level_Lenght = config.Get_Level_Width_Lenght( LEVEL_LENGHT); 

}

void Rendering::Variable_Update_Active( Soul *Spirit[] )
{
	


	for (int a = 0; a < MAX_GAME_OBJECTS; a++)
	{
		if(Spirit[a] == NULL)
		{
			break;
		}
		if (Spirit[a]->Get_Object_Type() ==  Selected_Character)
		{

			Character_X = Spirit[a]->Get_X();
			Character_Y = Spirit[a]->Get_Y();
			Character_Z = Spirit[a]->Get_Z();
			//Magnitude = data.Get_Character_Magnitude();

		//	Button = Button_Command();
			//Character_State = data.Get_Character_State_Of_Being();
			//Degree = data.Get_Character_Degree();
			//Frame_Animation = Character_State_Of_Animation();
			//Animation_Exception = data.Get_Character_Animation_Exception();
		}
	}
}

void Rendering::Show_Screen_Objects()
{
	
	Apply_Surface( 0, 0, ScreenEffects,  Screen, &Screen_Effects_Clips[1] ) ;
}

void Rendering::Sky_Line_View(Soul *Spirit[] )
{
	

	for (int a = 0; a < Total_Objects ; a++ )
	{
		if(Object_Type[Object_Track[a]] ==  Selected_Character)
		{
			Character_Altitude =  Spirit[Object_Track[a]]->Get_Object_Elevation();
		}
	}

	

		
		if (Character_Altitude >= 300)
		{
			Sky_Line_Key = true;
			SDL_SetAlpha(SkyLine, SDL_SRCALPHA, 255 );
 			Apply_Surface( 0, 0, SkyLine,  Screen, &Screen_Effects_Clips[0] ) ;
		}
		else if (Character_Altitude >= 250)
		{
			Sky_Line_Key = false;
			SDL_SetAlpha( SkyLine, SDL_SRCALPHA, 30 );
 			Apply_Surface( 0, 0, SkyLine,  Screen, &Screen_Effects_Clips[0] ) ;
		}
		else if (Character_Altitude >= 200)
		{	
			Sky_Line_Key = false;
			SDL_SetAlpha( SkyLine, SDL_SRCALPHA, 5 );
 			Apply_Surface( 0, 0, SkyLine,  Screen, &Screen_Effects_Clips[0] ) ;
		}
		
		
		if (Character_Altitude <= 100)
		{
			Sky_Line_Key = false;
			SDL_SetAlpha( SkyLine, SDL_SRCALPHA, 0 );
 			Apply_Surface( 0, 0, SkyLine,  Screen, &Screen_Effects_Clips[0] ) ;
		}

	
	

}

void Rendering::Shadowed(Soul *Spirit[] )
{
	bool Skip_Collision_Check = false;

	for (int s = 0; s < Total_Objects; s++)
	{		
		if (Spirit[Object_Track[s]]->Get_Object_Type() ==   CYRON_TANRYOKU)	
		{
				Skip_Collision_Check = true;
		}
		if (Spirit[Object_Track[s]]->Get_Object_Type() ==  CXX120)	
		{
				Skip_Collision_Check = true;
		}
		if (Spirit[Object_Track[s]]->Get_Object_Type() ==  THE_YS_GUY)	
		{
			Skip_Collision_Check = true;
		}

		if(Skip_Collision_Check == false)
		{
			if(s !=  Selected_Spirit)
			{
				if (Shadow_Enable(Spirit[ Selected_Spirit]->Get_Objects_Base(), Spirit[ Selected_Spirit]->Get_Objects(), Spirit[Object_Track[s]]->Get_Objects_Base(),  Spirit[Object_Track[s]]->Get_Objects()) == true )
				{
					Spirit[ Selected_Spirit]->Show_Graphic_Fx_Shadowed();	
					break;
				}
			}
		}
		else
		{
			Skip_Collision_Check = false;
		}
	}
}

void Rendering::Drop_Shadow(Soul *Spirit[])
{
	int Value = -1;
	bool Skip_Collision_Check = false;

	for (int s = 0; s < Total_Objects; s++)
	{		
		if (Spirit[ Render_Order[Total_Objects - 1 - s]]->Get_Object_Type() ==   CYRON_TANRYOKU)	
		{
				Skip_Collision_Check = true;
		}
		if (Spirit[ Render_Order[Total_Objects - 1 - s]]->Get_Object_Type() ==  CXX120)	
		{
				Skip_Collision_Check = true;
		}
		if (Spirit[ Render_Order[Total_Objects - 1 - s]]->Get_Object_Type() ==  THE_YS_GUY)	
		{
			Skip_Collision_Check = true;
		}

		if(Skip_Collision_Check == false)
		{
			if(Render_Order[Total_Objects - 1 - s] !=  Selected_Spirit)
			{
				Value = Drop_Shadow_Enable(Spirit[ Selected_Spirit]->Get_Objects_Base(), Spirit[ Selected_Spirit]->Get_Objects(), Spirit[ Render_Order[Total_Objects - 1 - s]]->Get_Objects_Base(),  Spirit[ Render_Order[Total_Objects - 1 - s]]->Get_Objects());
				if (Value != -1) 
				{			
					Spirit[ Selected_Spirit]->Show_Graphic_Fx_Drop_Shadow(Value);
					break;
				}
			}
		}
		else
		{
			Skip_Collision_Check = false;
		}
	}
}

bool Rendering::Transparented(Soul *Spirit[], int condition)
{		
	return Transparent_Enable(Spirit[ Selected_Spirit]->Get_Objects_Base(), Spirit[ Selected_Spirit]->Get_Objects(), Spirit[Render_Order[condition]]->Get_Objects_Base(),  Spirit[Render_Order[condition]]->Get_Objects());
}

void Rendering::Text_Speak( Soul *Spirit[])
{			

		switch (Master_Link.Master_Type)
		{
			/*case FLOOR:
				//STEP(3) Detect the sub type of the master
				switch (Master_Link.Master_Sub_Type)
				{	
					//FINAL STEP(4) Perform a specialize calculation for this object
					case 0: break;
					case 1: break;
					case 2: break;
				}
				break;

			case FLOAT:
				//STEP(3) Detect the sub type of the master
				switch (Master_Link.Master_Sub_Type)
				{	
					//FINAL STEP(4) Perform a specialize calculation for this object
					case 0: break;
					case 1: break;
					case 2: break;
				}
				break;
			case CONFIG:
				//STEP(3) Detect the sub type of the master
				switch (Master_Link.Master_Sub_Type)
				{	
					//FINAL STEP(4) Perform a specialize calculation for this object
					case 0: break;
					case 1: break;
					case 2: break;
				}
				break;
			case ON_SCREEN:
				//STEP(3) Detect the sub type of the master
				switch (Master_Link.Type_Master_Sub)
				{	
					//FINAL STEP(4) Perform a specialize calculation for this object
					case 0: break;
					case 1: break;
					case 2: break;
				}
				break;*/
			case ON_SCREEN_CONFIG:
				switch (Master_Link.Master_Sub_Type)
				{	
					//FINAL STEP(4) Perform a specialize calculation for this object
					case RETURN_MENU_BUTTON:	Slave_Object_Text_Speak_Calculation_MENU_BUTTON_TEXT(Spirit);break;
					case SWITCH_MENU_BUTTON:	Slave_Object_Text_Speak_Calculation_MENU_BUTTON_TEXT(Spirit);break;
					case SAVE_MENU_BUTTON:	 Slave_Object_Text_Speak_Calculation_MENU_BUTTON_TEXT(Spirit);break;
				}
				break;
			/*case ON_SCREEN_BG:
				//STEP(3) Detect the sub type of the master
				switch (Master_Link.Type_Master_Sub)
				{	
					//FINAL STEP(4) Perform a specialize calculation for this object
					case 0: break;
					case 1: break;
					case 2: break;
				}
				break;
			case BITMAP_TEXT: break;
			case CYRON_TANRYOKU:
			case THE_YS_GUY:
			case CXX120:
			case GHOST:
			case AI_SMART: 
			case AI_IDIOT:
			case HIT_BOX: break;*/
		}

	if((Master_Link.Active_Link == true) && (Master_Link.Performing == true) && (Master_Link.Perform == LINK_COMMAND_TEXT_TALK))
	{
		// Display the Text this objects wants to speak.
		Spirit[Slave_Link.Slave_Address]->Show_Text( Master_Link.Master_X_Child[0],  Master_Link.Master_Y_Child[0],  Master_Link.Master_Text, Screen); 
	}
}

void Rendering::Free_Slave(Soul *Spirit[])
{

	for (int a = 0; a < Total_Screen_Objects; a++)
	{
		Master_Link = Spirit[Screen_Object_Track[a]]->Get_Chain_Link();
		if (Master_Link.Active_Link == true)
		{
			//STEP(2) Detect the Master object type	
			switch (Master_Link.Master_Type)
			{
				case ON_SCREEN_CONFIG:
					//STEP(3) Detect the sub type of the master
					switch (Master_Link.Master_Sub_Type)
					{	
						//FINAL STEP(4) Turn off the slave
						case RETURN_MENU_BUTTON:	Slave_Object_Free_Calculation_MENU_BUTTON_TEXT(Spirit); break;
						case SWITCH_MENU_BUTTON:	Slave_Object_Free_Calculation_MENU_BUTTON_TEXT(Spirit); break;
						case SAVE_MENU_BUTTON:		Slave_Object_Free_Calculation_MENU_BUTTON_TEXT(Spirit); break;
					}
				break;
			}			
		}
	}	
}

//
////
/////////
////////////////
///RENDER FRAME CONDITIONING FUNCTIONS //////////////
////////////////
/////////
////
//

bool Rendering::Find_Avaialble_Slave( Soul *Spirit[])
{
	//Check if a link is already established to the master object requesting a slave.
	for (int t = XBITMAP_TEXT_STARTX; t <  XBITMAP_TEXT_ENDX + 1 ; t++ )
	{
		Slave_Link = Spirit[t]->Get_Chain_Link();
		if((Slave_Link.Active_Link == true)&&(Master_Link.Active_Link == true) && (Slave_Link.Master_Address == Master_Link.Master_Address)&& (Slave_Link.Slave_Address == Master_Link.Slave_Address))
		{
			return true; // End it now
		}
	}

	//if the slave have not been assigned yet
	if(Slave_Link.Active_Link == false)
	{
		for (int t = XBITMAP_TEXT_STARTX; t <  XBITMAP_TEXT_ENDX + 1 ; t++ )
		{
			// The link
			Slave_Link = Spirit[t]->Get_Chain_Link();
			if(Slave_Link.Active_Link == false)
			{
				// Set the slave up
				Spirit[Slave_Link.Slave_Address]->Variable_Setter_Special_Conditional(0, 0, Master_Link.Active_Link, 0); // The link is activated. Linking in progress
				Spirit[Slave_Link.Slave_Address]->Variable_Setter_Special_Conditional(0, 1, true, Master_Link.Master_Address);  // The address of the master is stored
				Spirit[Slave_Link.Slave_Address]->Variable_Setter_Special_Conditional(0, 3, true, Master_Link.Performing);
				Spirit[Slave_Link.Slave_Address]->Variable_Setter_Special_Conditional(0, 4, true, Master_Link.Perform);


				//Set the master up
				Spirit[ Master_Link.Master_Address]->Variable_Setter_Special_Conditional(0, 2, false, t);   // Set slave address in master
				
				//Variable update
				Slave_Link = Spirit[Slave_Link.Slave_Address]->Get_Chain_Link();
				Master_Link = Spirit[ Master_Link.Master_Address]->Get_Chain_Link();

				break;
			}
		}
	}
	return false; 
}



//A calculation for activation and another for the execution. Turning off the linking is done elsewhere. 
bool Rendering::Slave_Object_Text_Speak_Calculation_MENU_BUTTON_TEXT( Soul *Spirit[])
{
	//Condition that activate the master
	if ((Game_Mode == SAVE_MENU) && (Master_Link.Active_Link == false))
	{
		Spirit[ Master_Link.Master_Address]->Variable_Setter_Special_Conditional(0, 0, true, 0); //Make active linking true
		Spirit[ Master_Link.Master_Address]->Variable_Setter_Special_Conditional(0, 3, true, 0); //It is performing the actions
		Spirit[ Master_Link.Master_Address]->Variable_Setter_Special_Conditional(0, 4, false, LINK_COMMAND_TEXT_TALK); //The master want to perform a text talk
		Master_Link = Spirit[Master_Link.Master_Address]->Get_Chain_Link();

		Find_Avaialble_Slave(Spirit);
		return true;
	}
	if ((Game_Mode == SAVE_MENU) && (Master_Link.Active_Link == true))
	{
		if (Find_Avaialble_Slave(Spirit) == true)
		{
			return true;
		}
	}

	return false;
}
void Rendering::Slave_Object_Free_Calculation_MENU_BUTTON_TEXT( Soul *Spirit[])
{
	if (Game_Mode == GAMEPLAY_MODE)
	{

		//One quick update before eraser
		Slave_Link = Spirit[Master_Link.Slave_Address]->Get_Chain_Link();
		
		//Master frees slave
		Spirit[Master_Link.Slave_Address]->Variable_Setter_Special_Conditional(0, 0, false, 0);   // Turn off the active linking
		Spirit[Master_Link.Slave_Address]->Variable_Setter_Special_Conditional(0, 1, false, -1);  // Master is disowned
		Spirit[Master_Link.Slave_Address]->Variable_Setter_Special_Conditional(0, 3, false, -1);   // Turn off all actions
		Spirit[Master_Link.Slave_Address]->Variable_Setter_Special_Conditional(0, 4, false, -1);   // Set actions to idle

		//Master gives up rights to own slave
		Spirit[Master_Link.Master_Address]->Variable_Setter_Special_Conditional(0, 0, false, 0);   // Turn off the active linking
		Spirit[Master_Link.Master_Address]->Variable_Setter_Special_Conditional(0, 2, false, -1);  // Master frees slave
		Spirit[Master_Link.Master_Address]->Variable_Setter_Special_Conditional(0, 3, false, -1);   // Turn off all actions
		Spirit[Master_Link.Master_Address]->Variable_Setter_Special_Conditional(0, 4, false, -1);   // Set actions to idle 
	}
}


void Rendering::Screen_Object_Condition_Check_HEALTH_BAR(Soul *Spirit[])
{
	int Health;
	//The health bar animation condition depends solely on the currently playing character's health value.
	switch (Selected_Character)
	{
		case THE_YS_GUY:  Health = Spirit[XTHE_YS_GUYX]->Get_Health(); break;
		case CYRON_TANRYOKU:  Health = Spirit[XCYRON_TANRYOKUX]->Get_Health(); break;
		case CXX120:  Health = Spirit[XCXX120X]->Get_Health(); break;
	}	

	On_Screen_Frames = HEALTH_0 + Health;
	//On_Screen_Frame_End = On_Screen_Frame_Start;
	//On_Screen_Frames = On_Screen_Frame_Start
}

