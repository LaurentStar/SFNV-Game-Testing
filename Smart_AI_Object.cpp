#include "Function.h"

Smart_AI_Object::Smart_AI_Object(int x, int y,  int z, int object_type, int object_location): Soul(x, y,  z, object_type, object_location)
{
	Alive_Key = true;


	Object_Elevation =  z;



	Object_Type = AI_SMART;
	Type = object_type;
	Object_Location = object_location;
		
	Object_Coord_x = x;
	Object_Coord_y = y;
	Object_Coord_z = y - z;


	//Set variables
	Variable_Setter();


	Ai_Base.x = Object_Coord_x ;
	Ai_Base.y = Object_Coord_y ;
	Ai_Base.w = Object_Width;
	Ai_Base.h = Object_Lenght; 
	Ai_Base.front_cliff =Object_Coord_y + Object_Lenght/2;  

	Ai_Cornice.x = Object_Coord_x;
	Ai_Cornice.y = Object_Coord_z;
	Ai_Cornice.w = Object_Width;
	Ai_Cornice.h = Object_Height;
	Ai_Cornice.front_cliff = Object_Front_Edge; 

	Existance_Bubble.x = Object_Coord_x;
	Existance_Bubble.y = Object_Coord_y;
	Existance_Bubble.r = CHARACTER_FIELD_OF_EXISTANCE ;

	
	
	Friction = 0;
	Degree = 0;
	Magnitude = 0;
	X_Vel = 0;
	Y_Vel = 0;
	Z_Vel = 0; 

	Character_General_Direction = 0;

	Character_State_Of_Being = 0;
	Center_Base = 0;
	Button = 0;

	Frame_Coord_X = 0;
	Frame_Coord_Y = 0;
	Frame_Coord_Z = 0;

	
	


	Character_Frame = 0;


	
	Character_Health = 2;
	Health_Plus = 0;
	Health_Minus = 0;

	Character_Animation_Exception = -1;
	Character_Animation_Exception_Timer = 0;

	Character_Health_Timer = 0;
	Character_Health_Time = 0;
	Health_Timer = 0;
	Health_Recovery_Speed = 0;
	Character_Regeneration = false;
	Freeze_All_Actions = false;
	Fall_Damage = false;

	Attack_Phase_Timer = 0;

	Attack_Mode = false;
	Attack_Phase = false;
	Combo_Null_Guide = false;

	
}


/////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////


void Smart_AI_Object::Variable_Setter()
{
   switch (Type)
   {
	   case CHROME_CRYSTAL_MASTER_GRAY:	
						Object_Width = 53;
						Object_Lenght = 32;  
						Object_Front_Edge = Object_Lenght; 
						Object_Height = 95; 
						Gravity_Physics = DYNAMIC_G;
				break;
   }
}

void Smart_AI_Object::Variable_Setter_Bool_Conditional(int condition, bool condition2)
{
	switch (condition)
	{
		case 0 : Alive_Key = condition2; break;
	}
}

void Smart_AI_Object::Variable_Setter_Int_Conditional(int condition, int condition2)
{
	switch (condition)
	{
		case 0:		Object_Coord_x = condition2; break;
		case 1:		Object_Coord_y = condition2; break; 
		case 2:		Object_Coord_z = condition2; break;
	}

}

void Smart_AI_Object::Variable_Update(Uint32 deltaTicks)
{
	
		Button = Button_Command();
		


		//COODINATES
		Object_Coord_x += X_Vel *( deltaTicks / 1000.f );
		Ai_Base.x = Object_Coord_x;
		Ai_Cornice.x = Object_Coord_x;


		Object_Coord_y += Y_Vel *( deltaTicks / 1000.f );	
		Ai_Base.y = Object_Coord_y;
		Ai_Cornice.y = Object_Coord_z;
		


		Ai_Base.front_cliff = Ai_Base.y + (Object_Lenght/2); 
		Center_Base = Ai_Base.front_cliff;

		Object_Elevation =  Object_Coord_y - Object_Coord_z;
		


		// CONDITIONAL STATEMENTS
		if (Object_Coord_x < 0)
		{Object_Coord_x -= X_Vel *( deltaTicks / 1000.f );}
		//if (X_Coord + CHARACTER_WIDTH > C.Get_Level_Width_Lenght(0))
		//{X_Coord -= X_Vel *( deltaTicks / 1000.f );}
		if (Object_Coord_y < 0)
		{Object_Coord_y-= Y_Vel *( deltaTicks / 1000.f );}
		//if (Y_Coord + CHARACTER_HEIGHT > C.Get_Level_Width_Lenght(0))
		//{Y_Coord -= Y_Vel *( deltaTicks / 1000.f );}
	

		/*
		if (Character_Health > 20)
		{
			Character_Health = 20;
		}
		if (Character_Health <= 1)
		{
			Character_Health = 0;
		}*/

		Soul_Health_Condtions(deltaTicks);
		
}

void Smart_AI_Object::Soul_Physics(int condition, Uint32 deltaTicks)
{
	Character_State_Of_Being = condition;

	if(Game_Mode == GAMEPLAY_MODE)
	{
		if (Freeze_All_Actions == NOT_FROZEN)
		{
			

			switch (Character_State_Of_Being)
			{
				case GROUNDED:							Z_Vel = 0;
														Object_Coord_z = Center_Base - Object_Height ; 

												break;

				case MIDAIR:							
														Z_Vel += GRAVITY  * ( deltaTicks / 1000.f );
														Object_Coord_z += Y_Vel  * ( deltaTicks / 1000.f );
														Object_Coord_z += Z_Vel  * ( deltaTicks / 1000.f );
										
														//Controlling the character's jump height....test
														if ((Space_Key == false)&&(Z_Vel < 0))
														{
															Z_Vel -= Z_Vel/20;
														}
												break; 
				case FALLING_THROUGH_FLOOR1:			Z_Vel = 0;
														Object_Coord_z -= 2; 
												break;
				case FALLING_THROUGH_FLOOR2:			Z_Vel = 0;
														Object_Coord_z -= 5; 
												break;
				case FALLING_THROUGH_FLOOR3:			Z_Vel = 0;
														Object_Coord_z -= 7; 
												break;
				case STANDING_ON_TOP:					Z_Vel = Y_Vel;  Object_Coord_z += Z_Vel * ( deltaTicks / 1000.f ); 
												break;
				case HIT_FROM_BELOW:				//Going down we do nothing
														if(Z_Vel >= 0)
														{
															//Z_Coord ++;
															Z_Vel += GRAVITY * ( deltaTicks / 1000.f ); 
															Object_Coord_z += Z_Vel * ( deltaTicks / 1000.f ); 
															Object_Coord_x -= X_Vel * ( deltaTicks / 1000.f ); 
														}

														// Going up we push down
														if(Z_Vel < 0)
														{
															Object_Coord_z += 1;
															Z_Vel = 0;
															Z_Vel += GRAVITY * ( deltaTicks / 1000.f ); 
															Object_Coord_z += Z_Vel * ( deltaTicks / 1000.f );
															Object_Coord_x += X_Vel * ( deltaTicks / 1000.f );
														} 
												break;
				case AGAINST_BACK:		// Hard!!!!
													Z_Vel += GRAVITY * ( deltaTicks / 1000.f );
													Z_Vel -= Y_Vel * ( deltaTicks / 1000.f );
													Object_Coord_y--;
													Object_Coord_y -= Y_Vel * ( deltaTicks / 1000.f ); 
													Object_Coord_z += Z_Vel * ( deltaTicks / 1000.f ); 
												break;
				case AGAINST_FRONT:		// Hard!!!!
													Z_Vel += GRAVITY * ( deltaTicks / 1000.f );
													Object_Coord_y++;
													Object_Coord_y -= Y_Vel* ( deltaTicks / 1000.f ); 
													Object_Coord_z += Z_Vel * ( deltaTicks / 1000.f ); 
												break;		

				case AGAINST_LEFT_SIDE:				Z_Vel += GRAVITY * ( deltaTicks / 1000.f );
													Object_Coord_z += Z_Vel * ( deltaTicks / 1000.f );
													Object_Coord_x -= X_Vel * ( deltaTicks / 1000.f ); 
												break;			
				case GOING_THROUGH_LEFT_SIDE:		Z_Vel += GRAVITY * ( deltaTicks / 1000.f );
													Object_Coord_z += Z_Vel * ( deltaTicks / 1000.f );
													--Object_Coord_x;
													Object_Coord_x -= X_Vel * ( deltaTicks / 1000.f ); 
												break;	
										
				case AGAINST_RIGHT_SIDE:			Z_Vel += GRAVITY * ( deltaTicks / 1000.f );
													Object_Coord_z += Z_Vel * ( deltaTicks / 1000.f );
													Object_Coord_x -= X_Vel * ( deltaTicks / 1000.f ); 
												break;
				case GOING_THROUGH_RIGHT_SIDE:		Z_Vel += GRAVITY * ( deltaTicks / 1000.f );
													Object_Coord_z += Z_Vel * ( deltaTicks / 1000.f );
													Object_Coord_x -= X_Vel * ( deltaTicks / 1000.f ); 
													++Object_Coord_x;
													
												break;	
				case INSIDE_BLOCK: break;
			}
		}
	}
}

void Smart_AI_Object::Soul_Health_Condtions(Uint32 deltaTicks)
{
		/////////////////////////////////
		// HEALTH REGENERATION.
		/////////////////////////////////
		if (Character_Health < 20)
		{
			
			Character_Health_Timer += 10 * (  deltaTicks / 1000.f ); 

			if (Character_Regeneration == false)
			{
				// Set wait time
				Character_Health_Time = rand()% 70 + 1;
				// Set health recovery
				Health_Plus = rand() % 3;
				//Ready to regenerate
				Character_Regeneration = true;
			}
			
			// If the timer passes the wait time
			if ((int)Character_Health_Timer >= Character_Health_Time)
			{
				//Start at zero
				Character_Health_Timer= 0;
				//Give the character health
 				Character_Health += Health_Plus;
				//Set the health to false to be ready to recover again. 
   				Character_Regeneration = false; 			
			}
		}
		//Max health, magic number. 
		if (Character_Health > 20)
		{
			Character_Health = 20;
		}

		/////////////////////////////////
		// HEALTH REGENERATION.
		/////////////////////////////////
		//FALL DAMAGE
		/////////////////////////////////
		if ((Z_Vel >= 500) && (Character_State_Of_Being == MIDAIR))
		{
			Fall_Damage = true;
			Health_Minus = 2;
		}
		if ((Z_Vel <= 500) && (Character_State_Of_Being == MIDAIR))
		{
			Fall_Damage = false;
		}

		if((Fall_Damage == true)&&(Character_State_Of_Being != MIDAIR))
		{
			Character_Health -= Health_Minus;
			Y_Vel = 0;
			X_Vel = 0;
			Health_Minus = 0;
			Fall_Damage = false;
			Character_Animation_Exception =  FALL_DAMAGED; 
		}
		/////////////////////////////////
		//FALL DAMAGE
		/////////////////////////////////////
}

void Smart_AI_Object::Soul_Input()
{

	if(Game_Mode == GAMEPLAY_MODE)
	{
	
		if (Freeze_All_Actions == LEVEL_WRAP)
		{
				Magnitude = 0;
				X_Vel = 0;
				Y_Vel = 0;
				Z_Vel = 0;
		}
		
		
		
		switch (Button)
		{
				case SPACE:  switch (Character_State_Of_Being) 
				{
					case GROUNDED:	Object_Coord_z -= 30; Z_Vel -= 600; break;
					case STANDING_ON_TOP: Object_Coord_z -= 10; Z_Vel -= 100; break;
				}
				break;			
		}
	}
}

void Smart_AI_Object::Soul_Logic(Ai_Brain Copy_Brain, Uint32 deltaTicks)
{
	if (Brain.Act == 1)//1 equal attck mode
	{
		/*switch (Brain.Attack_Option)
		{

			case 0: Screen_Object_Children[0].x =
					Screen_Object_Children[0].y =
					Screen_Object_Children[0].w =
					Screen_Object_Children[0].h = 

					Screen_Object_Children[1].x 
					Screen_Object_Children[1].y 
					Screen_Object_Children[1].w 
					Screen_Object_Children[1].h 
						
					Screen_Object_Children[2].x 
					Screen_Object_Children[2].y 
					Screen_Object_Children[2].w 
					Screen_Object_Children[2].h 	
						//Idle
			case 1: // Perform the standard attack
		
		}*/
		X_Vel = cos(Brain.Target_Direction * DEG) * 50;
		Y_Vel = -sin(Brain.Target_Direction * DEG) * 50;

	}
}
			
void Smart_AI_Object::Move_Special_Object()
{
	std::ifstream Load( "current_location" ); if( Load == NULL ) {Load.close();  }
	
	//Name of the level
	std::string  READ_FILE;

	getline( Load, READ_FILE);	
	getline( Load, READ_FILE);	
	getline( Load, READ_FILE);	
	getline( Load, READ_FILE);	
	getline( Load, READ_FILE);	
	getline( Load, READ_FILE);	
	getline( Load, READ_FILE);	

	//Start recording the numbers
	Load >> Object_Coord_x;
	Load >> Object_Coord_y;
	Load >> Object_Coord_z;	

	Load.close();

}

void Smart_AI_Object::Teleport_Force_Input(float condition, int condition2)
{
	Object_Coord_z += -sin(condition * DEG) *  condition2;
}

Square Smart_AI_Object::Get_Objects_Base()
{
	return Ai_Base;
}

Square Smart_AI_Object::Get_Objects()
{
	return Ai_Cornice;
}

float Smart_AI_Object::Get_Character_Degree()
{
	return Degree;
}

float Smart_AI_Object::Get_Character_Magnitude()
{
	return Magnitude;
}
	
int Smart_AI_Object::Get_Object_Type()
{
	return Object_Type;
}

bool Smart_AI_Object::Get_Alive_Key()
{
	return Alive_Key;
}

int Smart_AI_Object::Get_Gravity_Physics()
{
	return Gravity_Physics;
}

int Smart_AI_Object::Get_Object_Elevation()
{
	return Object_Elevation;
}

int Smart_AI_Object::Get_X()
{
	return Object_Coord_x ;
}

int Smart_AI_Object::Get_Y()
{
	return Object_Coord_y ;
}

int Smart_AI_Object::Get_Z()
{
	return Object_Coord_z ;
}

int Smart_AI_Object::Get_Center_Base()
{
	return Center_Base;
}

int Smart_AI_Object::Get_Health()
{
	return Character_Health;
}

int Smart_AI_Object::Get_Character_Animation_Exception()
{
	return 	Character_Animation_Exception;
}

int Smart_AI_Object::Get_Object_State()
{
	return Character_State_Of_Being;
}


void Smart_AI_Object::Show(int condition)
{
	Apply_Surface( (int)Object_Coord_x - Camera.x , (int)Object_Coord_z - Camera.y, ChromeCrystalMasterGray  , Screen, &ChromeCrystalMasterGray_Clips[0] ) ;
}

void Smart_AI_Object::Show_Base()
{
	Apply_Surface( (int)Object_Coord_x - Camera.x, (int)Object_Coord_y - Camera.y, Character1,  Screen, &Character_Test_Clips[1] ) ;
}

void Smart_AI_Object::Show_Graphic_Fx_Shadowed()
{
	Apply_Surface( (int)Object_Coord_x - Camera.x , (int)Object_Coord_z - Camera.y, ShadowCryonTanryokuSheet , Screen, &Cyron_Tanryoku_Clips[Character_Frame] ) ;
}

void Smart_AI_Object::Show_Graphic_Fx_Drop_Shadow(int coord)
{
	Apply_Surface( (int)Object_Coord_x - Camera.x, Object_Coord_y - Camera.y, Character1,  Screen, &Character_Test_Clips[1] ) ;
}