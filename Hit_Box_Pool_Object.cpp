#include "Function.h"

Hit_Box_Pool_Object::Hit_Box_Pool_Object( int x, int y, int z )
{
	Alive_Key = true;


	//Get the tile type// Perfect
	Object_Type = FLOAT;
	Type = -1;

	// Perfect
	Object_Elevation =  z;

	 
	// Assigns values to class variables
	Object_Coord_x = x;
	Object_Coord_y = y;
	Object_Coord_z = y - z;
	
	
	// Set the variables so everthing can be defined
	Variable_Setter();

    //Get the offsets
    Hit_Box_Objects.x = Object_Coord_x;
    Hit_Box_Objects.y = Object_Coord_z;
    Hit_Box_Objects.w = Object_Width;
    Hit_Box_Objects.h = Object_Height;
	Hit_Box_Objects.front_cliff = Object_Front_Edge;

	Hit_Box_Objects_Base.x = Object_Coord_x;
	Hit_Box_Objects_Base.y = Object_Coord_y;
	Hit_Box_Objects_Base.w = Object_Width;
	Hit_Box_Objects_Base.h = Object_Lenght;
	Hit_Box_Objects_Base.front_cliff = Object_Coord_y + Object_Lenght/2;

	Center_Base = Object_Coord_y + (Object_Lenght/2);


	In_Use = false; 
	Link.Active_Link = false;
	//Link.Address_Master = -1;

}


void Hit_Box_Pool_Object::Variable_Setter()
{
	
	/*
   switch (Variable_Set)
   {
	   //case BLUE_CUBE:	
						Object_Width = 40;
						Object_Lenght = 40;  
						Object_Front_Edge = Object_Lenght; 
						Object_Height = 40; 
						Gravity_Physics = STATIC_G;
				break;

  }*/
}

void Hit_Box_Pool_Object::Variable_Setter_Special_Conditional(int condition, int condition2, bool conditionBool, int conditionInt)
{
	switch (condition)
	{
		case 0: switch (condition2)
				{
					case 0:  Link.Active_Link = conditionBool; 
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

void Hit_Box_Pool_Object::Variable_Update(Uint32 deltaTicks)
{
	//Nothing so far........


}


void Hit_Box_Pool_Object::Soul_Physics(int condition, Uint32 deltaTicks)
{

	/*
	switch (condition)
	{
		
		case MIDAIR:		Z_Vel += GRAVITY  * ( deltaTicks / 1000.f );
								Z_Vel  += Y_Vel * ( deltaTicks / 1000.f );  
								Z_Coord += Z_Vel  * ( deltaTicks / 1000.f );
										
								//Controlling the character's jump height....test
								if ((Space_Key == false)&&(Z_Vel < 0))
								{
									Z_Vel -= Z_Vel/20;
								}
								break; 
				


	}*/
}
	
int Hit_Box_Pool_Object::Get_Type()
{
    return Type;
}

int Hit_Box_Pool_Object::Get_Object_Type()
{
    return Object_Type;
}

int Hit_Box_Pool_Object::Get_Gravity_Physics()
{
	return Gravity_Physics;
}

int Hit_Box_Pool_Object::Get_Object_Elevation()
{
	return Object_Elevation;
}

int Hit_Box_Pool_Object::Get_X()
{
    return Object_Coord_x;
}
int Hit_Box_Pool_Object::Get_Y()
{
    return Object_Coord_y;
}
int Hit_Box_Pool_Object::Get_Z()
{
    return Object_Coord_z;
}

int Hit_Box_Pool_Object::Get_Center_Base()
{
	return Center_Base;
}

Square Hit_Box_Pool_Object::Get_Objects()
{
	return  Hit_Box_Objects;
}
Square Hit_Box_Pool_Object::Get_Objects_Base()
{
	return  Hit_Box_Objects_Base;
}

bool Hit_Box_Pool_Object::Get_Alive_Key()
{
	return Alive_Key;
}

void Hit_Box_Pool_Object::Show(/*int condition*/)
{
	//if (condition != 2)
	//{
	//	if (condition == 0)
	//	{
	//		if( Square_Object_Detection (Camera, Floating_Objects ) == true ) 
	//		{
				Apply_Surface( Object_Coord_x - Camera.x, Object_Coord_z - Camera.y, FloatTileSheet, Screen, &Float_Object_Clips[Type] ); 
	//		}
	//	}
		
	//	if (condition == 1)
	//	{
	//		if( Square_Object_Detection (Camera, Floating_Objects ) == true ) 
	//		{
	//			Apply_Surface( Object_Coord_x - Camera.x, Object_Coord_z - Camera.y, TransparentFloatTileSheet, Screen, &Float_Object_Clips[Type] ); 
	//		}
	//	}
	//}

}

void  Hit_Box_Pool_Object::Show_Base()
{
		if( Square_Object_Detection (Camera,  Hit_Box_Objects_Base ) == true ) 
		{
			Apply_Surface( Object_Coord_x - Camera.x, Object_Coord_y - Camera.y, ShadowFloatTileSheet, Screen, &Shadow_Float_Object_Clips[Type] ); 
		}


	//	for (int i = 0; i < 9; i++)
	//	{



	//	}

}

