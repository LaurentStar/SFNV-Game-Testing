#include "Function.h"

On_Screen_BG_Object::On_Screen_BG_Object(int x, int y, int type)
{
	//Decide 
	Alive_Key = true;
	 Render_Key = false;
	Object_Type = ON_SCREEN_BG;
	Type = type;
	Variable_Setter();

	Target_X = x;
	Target_Y = y;


	Screen_Object.x = Target_X;
	Screen_Object.y = Target_Y;
	Screen_Object.w = 0;
	Screen_Object.h = 0;
	
	Friction = 0;
	Degree = 0;
	Magnitude = 0;
	X_Vel = 0;
	Y_Vel = 0;
	
	Button = 0;
}

void On_Screen_BG_Object::Variable_Setter()
{
	 switch (Type)
	 {

	   case  BLACK_BG:	Game_Stat =  SAVE_MENU;
							Gravity_Physics = STATIC_G;
				break;
   
	 
	}

}

void On_Screen_BG_Object::Variable_Setter_Bool_Conditional(int condition, bool condition2 )
{
	switch (condition)
	{
		case 0: Render_Key = condition2;



	}


}

void On_Screen_BG_Object::Soul_Input()
{
	if (Game_Mode == SAVE_MENU)
	{
		if (Type ==  TARGET_REDICAL )
		{
			switch (Button)
			{
				case NO_KEY:	Magnitude -= 5.0; X_Vel = cos(Degree * DEG) * Magnitude;
								Y_Vel = -sin(Degree * DEG) * Magnitude; 
								if(Magnitude < 0) {Magnitude = 0; X_Vel = 0; Y_Vel = 0;} 
					break;
				case UP:		Degree = 90.0; Magnitude = 50;  
								X_Vel = cos(Degree * DEG) * Magnitude;
								Y_Vel = -sin(Degree * DEG) * Magnitude; 
					break;
				case UP_LEFT:	Degree = 135.0; Magnitude = 50; 
								X_Vel = cos(Degree * DEG) * Magnitude; 
								Y_Vel = -sin(Degree * DEG) * Magnitude;		
					break;
				case UP_RIGHT:	Degree = 45.0; Magnitude = 50; 
								X_Vel = cos(Degree * DEG) * Magnitude; 
								Y_Vel = -sin(Degree * DEG) * Magnitude;				
					break;
				case UP_DOWN:	Magnitude -= Friction; if (Magnitude < 0) {Magnitude = 0;} X_Vel += 0; Y_Vel = 0; 
					break;	

				case DOWN:		Degree = 270.0; Magnitude = 50;  
								X_Vel = cos(Degree * DEG) * Magnitude;
								Y_Vel = -sin(Degree * DEG) * Magnitude; 	
					break;
				case DOWN_LEFT: Degree = 225.0; Magnitude = 50;  
								X_Vel = cos(Degree * DEG) * Magnitude;
								Y_Vel = -sin(Degree * DEG) * Magnitude;
					break;
				case DOWN_RIGHT:	Degree = 315.0; Magnitude = 50;  
									X_Vel = cos(Degree * DEG) * Magnitude;
									Y_Vel = -sin(Degree * DEG) * Magnitude;
					break;
				case LEFT: Degree = 180.0; Magnitude = 50;  
									X_Vel = cos(Degree * DEG) * Magnitude;
									Y_Vel = -sin(Degree * DEG) * Magnitude; 
							break;
					case LEFT_RIGHT: Magnitude -= Friction; if (Magnitude < 0) {Magnitude = 0;} X_Vel += 0; Y_Vel = 0; 
							break;
					case RIGHT: Degree = 0.0; Magnitude = 50;  
									X_Vel = cos(Degree * DEG) * Magnitude;
									Y_Vel = -sin(Degree * DEG) * Magnitude; 
							break;
			}
		}
	}
}

void On_Screen_BG_Object::Variable_Update(Uint32 deltaTicks)
{
		Button = Button_Command();

		Target_X += X_Vel *( deltaTicks / 1000.f );
		Target_Y += Y_Vel *( deltaTicks / 1000.f );	

		if ((Target_X < 0)||(Target_X > SCREEN_WIDTH))
		{Target_X -= X_Vel *( deltaTicks / 1000.f );}

		if ((Target_Y < 0)||( Target_Y > SCREEN_HEIGHT))
		{Target_Y -= Y_Vel *( deltaTicks / 1000.f );}
}

int On_Screen_BG_Object::Get_Type()
{
	return Type;
}

int On_Screen_BG_Object::Get_Object_Type()
{
	return Object_Type;
}

int On_Screen_BG_Object::Get_Gate_Type()
{
	return Game_Stat;
}

bool On_Screen_BG_Object::Get_Alive_Key()
{
	return Alive_Key;
}

bool On_Screen_BG_Object::Get_Render_Key()
{
	return  Render_Key;
}

int On_Screen_BG_Object::Get_Gravity_Physics()
{
	return Gravity_Physics;
}

void On_Screen_BG_Object::Show()
{
		Apply_Surface( Target_X, Target_Y, OnScreenBG,  Screen, &Screen_Effects_Clips[Type] ) ;
}