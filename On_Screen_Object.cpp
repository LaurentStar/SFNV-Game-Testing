#include "Function.h"

On_Screen_Object::On_Screen_Object(int x, int y, int type)
{
	
	Object_Type = ON_SCREEN;
	Type = type;
	Variable_Setter();

	Target_X = x;
	Target_Y = y;


	Screen_Object.x = Target_X;
	Screen_Object.y = Target_Y;
	Screen_Object.w = 30;
	Screen_Object.h = 30;
	
	Friction = 0;
	Degree = 0;
	Magnitude = 0;
	X_Vel = 0;
	Y_Vel = 0;
	
	Button = 0;

	Active_Animation_Key = false;
}

void On_Screen_Object::Variable_Setter()
{
	//When Animated_Key = true conditional statements are needed because the frames change based on condition
	 switch (Type)
	 {

	   case  CYRON_GAUGE:	Game_Stat =  GAMEPLAY_MODE;
							Gravity_Physics = STATIC_G;
							Animated_Key = false;
							if(Selected_Character == CYRON_TANRYOKU){ Alive_Key = true;}
							else {Alive_Key = false;}
				break;
	   case	 YS_GAUGE:		Game_Stat =  GAMEPLAY_MODE;
							Gravity_Physics = STATIC_G;
							Animated_Key = false;
							if(Selected_Character == THE_YS_GUY){ Alive_Key = true;}
							else {Alive_Key = false;}
				break;
	case	 CXX120_GAUGE:	Game_Stat =  GAMEPLAY_MODE;
							Gravity_Physics = STATIC_G;
							Animated_Key = false;
							if(Selected_Character == CXX120){ Alive_Key = true;}
							else {Alive_Key = false;}
				break;
	   case  TARGET_REDICAL:	Game_Stat =  SAVE_MENU;
								Gravity_Physics = DYNAMIC_G;
								Animated_Key = false;
								Alive_Key = true;
				break;
	   case  HEALTH_BAR:		Game_Stat =  GAMEPLAY_MODE;
								Gravity_Physics = STATIC_G;
								Animated_Key = true;
								Alive_Key = true;
				break;
	
	}

}


void On_Screen_Object::Soul_Input()
{
	if (Game_Mode == SAVE_MENU)
	{
		if (Type ==  TARGET_REDICAL )
		{
			switch (Button)
			{
				case NO_KEY:	Magnitude -= 6.0; X_Vel = cos(Degree * DEG) * Magnitude;
								Y_Vel = -sin(Degree * DEG) * Magnitude; 
								if(Magnitude < 0) {Magnitude = 0; X_Vel = 0; Y_Vel = 0;} 
					break;
				case UP:		Degree = 90.0; Magnitude = 100;  
								X_Vel = cos(Degree * DEG) * Magnitude;
								Y_Vel = -sin(Degree * DEG) * Magnitude; 
					break;
				case UP_LEFT:	Degree = 135.0; Magnitude = 100; 
								X_Vel = cos(Degree * DEG) * Magnitude; 
								Y_Vel = -sin(Degree * DEG) * Magnitude;		
					break;
				case UP_RIGHT:	Degree = 45.0; Magnitude = 100; 
								X_Vel = cos(Degree * DEG) * Magnitude; 
								Y_Vel = -sin(Degree * DEG) * Magnitude;				
					break;
				case UP_DOWN:	Magnitude -= Friction; if (Magnitude < 0) {Magnitude = 0;} X_Vel += 0; Y_Vel = 0; 
					break;	

				case DOWN:		Degree = 270.0; Magnitude = 100;  
								X_Vel = cos(Degree * DEG) * Magnitude;
								Y_Vel = -sin(Degree * DEG) * Magnitude; 	
					break;
				case DOWN_LEFT: Degree = 225.0; Magnitude = 100;  
								X_Vel = cos(Degree * DEG) * Magnitude;
								Y_Vel = -sin(Degree * DEG) * Magnitude;
					break;
				case DOWN_RIGHT:	Degree = 315.0; Magnitude = 100;  
									X_Vel = cos(Degree * DEG) * Magnitude;
									Y_Vel = -sin(Degree * DEG) * Magnitude;
					break;
				case LEFT:			Degree = 180.0; Magnitude = 100;  
									X_Vel = cos(Degree * DEG) * Magnitude;
									Y_Vel = -sin(Degree * DEG) * Magnitude; 
							break;
					case LEFT_RIGHT: Magnitude -= Friction; if (Magnitude < 0) {Magnitude = 0;} X_Vel += 0; Y_Vel = 0; 
							break;
					case RIGHT: Degree = 0.0; Magnitude = 100;  
									X_Vel = cos(Degree * DEG) * Magnitude;
									Y_Vel = -sin(Degree * DEG) * Magnitude; 
							break;
			}
		}
	}
}

void On_Screen_Object::Teleport_Direct_Input() 
{
	switch (Type)
	{
		case TARGET_REDICAL: Target_X = SCREEN_WIDTH/2;  Target_Y = SCREEN_HEIGHT/2; break;
	}

}

void On_Screen_Object::Variable_Update(Uint32 deltaTicks)
{
		Button = Button_Command();

		Target_X += X_Vel *( deltaTicks / 1000.f );
		Screen_Object.x = Target_X;

		Target_Y += Y_Vel *( deltaTicks / 1000.f );	
		Screen_Object.y = Target_Y;

		




		if ((Target_X < 0)||(Target_X > SCREEN_WIDTH))
		{Target_X -= X_Vel *( deltaTicks / 1000.f );}

		if ((Target_Y < 0)||( Target_Y > SCREEN_HEIGHT))
		{Target_Y -= Y_Vel *( deltaTicks / 1000.f );}
}

bool On_Screen_Object:: Get_Animated_Key()
{
	return  Animated_Key;
}

bool  On_Screen_Object::Get_Active_Animation_Key()
{
	return Active_Animation_Key;
}

bool On_Screen_Object::Get_Alive_Key()
{
	return Alive_Key;
}

int On_Screen_Object::Get_Type()
{
	return Type;
}

int On_Screen_Object::Get_Object_Type()
{
	return Object_Type;
}

int On_Screen_Object::Get_Gate_Type()
{
	return Game_Stat;
}

int On_Screen_Object::Get_Gravity_Physics()
{
	return Gravity_Physics;
}


Square On_Screen_Object::Get_Objects()
{
	return Screen_Object;
}

void On_Screen_Object::Show(int condition)
{
		Apply_Surface( Target_X, Target_Y, OnScreen,  Screen, &On_Screen_Clips[condition] ) ;
}