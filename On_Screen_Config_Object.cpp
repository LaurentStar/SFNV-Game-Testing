#include "Function.h"

On_Screen_Config_Object::On_Screen_Config_Object(int x, int y, int type)
{
	//Decide 
	Alive_Key = true;
	Render_Key = false;
	Child_Num = 0;

	Object_Type = ON_SCREEN_CONFIG;
	Type = type;
	
	Link.Master_Address = -1; // When master has no address

	Target_X = x;
	Target_Y = y;
	
	Variable_Setter();

	Screen_Object.x = Target_X;
	Screen_Object.y = Target_Y;
	Screen_Object.w = Width;
	Screen_Object.h = Lenght;
	
	

	Friction = 0;
	Degree = 0;
	Magnitude = 0;
	X_Vel = 0;
	Y_Vel = 0;
	
	Button = 0;
}

void On_Screen_Config_Object::Variable_Setter()
{
	switch (Type)
	{
	   case RETURN_MENU_BUTTON:	Game_Stat =  SAVE_MENU;
								Gravity_Physics = STATIC_G;
								Alive_Key = true; 
								Lenght = 72;
								Width = 165;
								Text = "Return";							
									
								//TEXT PLACEMENT IS ALWAYS CHILD ZERO
								Screen_Object_Children[0].x = Target_X + 35 ;
								Screen_Object_Children[0].y = Target_Y + 7;
								Screen_Object_Children[0].w = 126;
								Screen_Object_Children[0].h = 58;

								//Link definign
								
								Link.Master_Type = 	Object_Type;
								Link.Master_Sub_Type = 	Type;
								Link.Master_Text = Text;
								Link.Master_X_Child[0] = Screen_Object_Children[0].x;
								Link.Master_Y_Child[0] = Screen_Object_Children[0].y;

								Link.Active_Link = false;
								Link.Performing = false;

								
				break;
	   case SWITCH_MENU_BUTTON:	Game_Stat =  SAVE_MENU;
								Gravity_Physics = STATIC_G;
								Alive_Key = true; 
								Lenght = 72;
								Width = 165;
								Text = "Switch";
								Slave_Order = 1;
								
								//TEXT PLACEMENT IS ALWAYS CHILD ZERO
								Screen_Object_Children[0].x = Target_X + 45 ;
								Screen_Object_Children[0].y = Target_Y + 7;
								Screen_Object_Children[0].w = 126;
								Screen_Object_Children[0].h = 58;

								//Link definign
								
								Link.Master_Type = 	Object_Type;
								Link.Master_Sub_Type = 	Type;
								Link.Master_Text = Text;
								Link.Master_X_Child[0] = Screen_Object_Children[0].x;
								Link.Master_Y_Child[0] = Screen_Object_Children[0].y;

								Link.Active_Link = false;
								Link.Performing = false;
				break;
	   case SWITCH_MENU_BUTTON_EXPAND1:	Game_Stat =  SAVE_MENU;
										Gravity_Physics = STATIC_G;
										Alive_Key = false; 
										Child_Num = MAX_OBJECT_CHILDREN;
										Lenght = 209;
										Width = 165;

										Screen_Object_Children[0].x = Target_X + 30 ;
										Screen_Object_Children[0].y = Target_Y + 7;
										Screen_Object_Children[0].w = 126;
										Screen_Object_Children[0].h = 58;

										Screen_Object_Children[1].x = Target_X + 30;
										Screen_Object_Children[1].y = Screen_Object_Children[0].y + Screen_Object_Children[0].h;
										Screen_Object_Children[1].w = 126;
										Screen_Object_Children[1].h = 58;

										Screen_Object_Children[2].x = Target_X + 30 ;
										Screen_Object_Children[2].y = Screen_Object_Children[1].y + Screen_Object_Children[1].h;
										Screen_Object_Children[2].w = 126;
										Screen_Object_Children[2].h = 58;
				break;
		 case SAVE_MENU_BUTTON:	Game_Stat =  SAVE_MENU;
								Gravity_Physics = STATIC_G;
								Alive_Key = true; 
								Lenght = 72;
								Width = 165;
								Text = "Save";
								Slave_Order = 1;

								//TEXT PLACEMENT IS ALWAYS CHILD ZERO
								Screen_Object_Children[0].x = Target_X + 55 ;
								Screen_Object_Children[0].y = Target_Y + 7;
								Screen_Object_Children[0].w = 126;
								Screen_Object_Children[0].h = 58;

								//Link definign
								
								Link.Master_Type = 	Object_Type;
								Link.Master_Sub_Type = 	Type;
								Link.Master_Text = Text;
								Link.Master_X_Child[0] = Screen_Object_Children[0].x;
								Link.Master_Y_Child[0] = Screen_Object_Children[0].y;

								Link.Active_Link = false;
								Link.Performing = false;
				break;
	}

}

void On_Screen_Config_Object::Variable_Setter_Bool_Conditional(int condition, bool condition2 )
{
	switch (condition)
	{
		case 0: Render_Key = condition2; break;
		case 1: Alive_Key = condition2; break;


	}


}

void On_Screen_Config_Object::Variable_Setter_Special_Conditional(int condition, int condition2, bool conditionBool, int conditionInt)
{
	switch (condition)
	{
		case 0: switch (condition2)
				{
					case 0: Link.Active_Link = conditionBool; 		
						break;
					case 1: Link.Master_Address = conditionInt; 
						break;
					case 2: Link.Slave_Address = conditionInt;
						break;
					case 3:	Link.Performing = conditionBool;
						break;
					case 4:  Link.Perform = conditionInt;
						break;

							
				}
		break;
	}
}

void On_Screen_Config_Object::Soul_Input()
{
	if (Game_Mode == SAVE_MENU)
	{
	}
}

void On_Screen_Config_Object::Variable_Update(Uint32 deltaTicks)
{
		Button = Button_Command();

		Target_X += X_Vel *( deltaTicks / 1000.f );
		Target_Y += Y_Vel *( deltaTicks / 1000.f );	
		Link.Master_x = Target_X;
		Link.Master_y = Target_Y;

		if ((Target_X < 0)||(Target_X > SCREEN_WIDTH))
		{Target_X -= X_Vel *( deltaTicks / 1000.f );}

		if ((Target_Y < 0)||( Target_Y > SCREEN_HEIGHT))
		{Target_Y -= Y_Vel *( deltaTicks / 1000.f );}
}

void On_Screen_Config_Object::Command_Slave_Calculation()
{

	// Figure out the game mode
	switch (Game_Mode)
	{
		case YOU_DUN_GOOFED:  break;
		case START_MENU: //Figure out the type of the master break;
		case GAMEPLAY_MODE: break;
		case SAVE_MENU: break;
	
	}
}

int On_Screen_Config_Object::Get_X()
{
	return Target_X;
}
		

int On_Screen_Config_Object::Get_Y()
{
	return Target_Y;
}

int On_Screen_Config_Object::Get_Type()
{
	return Type;
}

int On_Screen_Config_Object::Get_Object_Type()
{
	return Object_Type;
}

int On_Screen_Config_Object::Get_Gate_Type()
{
	return Game_Stat;
}

bool On_Screen_Config_Object::Get_Render_Key()
{
	return  Render_Key;
}

bool  On_Screen_Config_Object::Get_Alive_Key()
{
	return Alive_Key;
}

std::string On_Screen_Config_Object::Get_Text() 
{
	return Text;
}

Chain_Link  On_Screen_Config_Object::Get_Chain_Link()
{
	return Link;
}


int On_Screen_Config_Object::Get_Gravity_Physics()
{
	return Gravity_Physics;
}

int On_Screen_Config_Object::Get_Child_Num()
{
	return Child_Num;
}

Square On_Screen_Config_Object::Get_Objects()
{
	return Screen_Object;
}

Square On_Screen_Config_Object::Get_Objects_Children(int condition)
{
	return Screen_Object_Children[condition]; 
}

void On_Screen_Config_Object::Show(int condition)
{
		Apply_Surface( Target_X, Target_Y, OnScreen,  Screen, &On_Screen_Clips[condition] ) ;
}

void On_Screen_Config_Object::Show_Children(int condition, int condition2)
{
	Target_X_Child = Screen_Object_Children[condition].x;
	Target_Y_Child = Screen_Object_Children[condition].y; 
	Apply_Surface( Target_X_Child, Target_Y_Child, OnScreen,  Screen, &On_Screen_Clips[condition2] ) ;
}