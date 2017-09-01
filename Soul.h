#ifndef SOUL_H_INCLUDED
#define SOUL_H_INCLUDED
#include <string>
// So far this is the only class that outrank the soul. It works behind the scene compared to physics and render classes
//#include "External_Configuration.h"

// Soul take on roles in the world, This is yet an actor in the play of life
class Soul
{
	protected:
	
//	Square Floor_Objects;

    //The tile type
  //  int Type;
	
	//Coordinates of the objects
//	int Object_Coord_x, Object_Coord_y, Object_Coord_z;
	
	// Collsion detection properties of Objects. Width relates to x, Lenght relate to y, Height relates to z. 
	//int Object_Width, Object_Lenght, Object_Height;
	
		
	
	public:
		
		//List of classes this Constructor supports
		//CHARACTER
		Soul(){}

		//List of classes this Constructor supports
		//FLOOR_OBJECT
		Soul(int x, int y,  int object_type ){}
	

		
		
		Soul(int x, int y,  int z, int object_type ){}

		Soul(int x, int y,  int z, int object_type,  int gate_type  ){}
		
		Soul(int x, int y, int z, SDL_Surface *font){}
		// Called to set up variables before the game starts
		virtual void Game_Start(External_Configuration config) = 0;

		//Called in a constructor to use the objects type to define more features. 
		virtual void Variable_Setter() = 0;
		

		//Set variables on special conditions
		virtual void Variable_Setter_Bool_Conditional(int condition, bool condition2) = 0;
		virtual void Variable_Setter_Int_Conditional(int condition, int condition2) = 0;
		//Can set anytype of variable regardless of type. Variables with sub pieces can only be updated piece by piece
		virtual void Variable_Setter_Special_Conditional(int condition, int condition2, bool conditionBool, int conditionInt) = 0;
		//Updates and changes the entire Ai_Brain variable
		virtual void Variable_Setter_Ai_Brain_Conditional(int condition, Ai_Brain Copy_Brain) = 0;
		virtual void Build_Font(SDL_Surface *font) = 0;

		// Updates the location, status, and values of variable associated with a class.
		virtual void Variable_Update(Uint32 deltaTicks) = 0;
		
		//The physics of an objects and movement
		virtual void Soul_Physics(int condition, Uint32 deltaTicks) = 0;
		virtual void Soul_Logic(Ai_Brain Copy_Brain, Uint32 deltaTicks) = 0;
		virtual void Soul_Input() = 0;

		//Resposible for all conditions that affects the characters health
		virtual void Soul_Health_Condtions(Uint32 deltaTicks) = 0;

		/*A powerful function used by the internal_config class. Manipulate variables of a class regardless of type. 
		Uses 2 value to do this process. Magic numbers are used within the IN_config class to pick a vairable
		and the effect detirmine the change however more constant defining is applied
		within the class effected
		*/


		//Teleport an object during a level transition. 
		virtual void Move_Special_Object() = 0;
		//teleport an object at a constant location where it should be
		virtual void Teleport_Direct_Input() = 0;
		//Move an object relative to it's current location
		virtual void Teleport_Force_Input(float condition, int condition2) = 0;



		virtual int Get_Type() = 0;
		virtual int Get_Object_Type() = 0;
		virtual bool Get_Alive_Key() = 0;
		virtual bool Get_Animated_Key() = 0;
		virtual bool Get_Active_Animation_Key() = 0;

		//The location a gate goes too
		//virtual int Get_Health() = 0;
		virtual int Get_Gate_Type() = 0;
		virtual int Get_Gravity_Physics() = 0;
		virtual int Get_Object_Elevation() = 0;
		virtual int Get_Object_State() = 0;
		virtual int Get_Child_Num() = 0;

		// Get a special unique variable from an object
		virtual bool Get_Render_Key() = 0;
		
		virtual int Get_Health() = 0;


		virtual int Get_X() = 0;
		virtual int Get_Y() = 0;
		virtual int Get_Z() = 0;

		//Only used for Squares, Circles, and other known shapes. No vectors.
		virtual int Get_Center_Base() = 0;
		virtual Square Get_Objects() = 0;
		virtual Square Get_Objects_Base() = 0;
		virtual Square Get_Objects_Children(int condition) = 0;
	
		virtual Chain_Link Get_Chain_Link() = 0;
		virtual std::string Get_Text() = 0;
		
		virtual void Show() = 0;
		virtual void Show_Base() = 0;

		//Exclusive float type functions
		virtual void Show(int condition) = 0;
		virtual void Show_Children(int condition, int condition2) = 0;
		//Effects applied to the game. Environments object get no effects.
		// Standing in the shade of an object
		virtual void Show_Graphic_Fx_Shadowed() = 0;
		virtual void Show_Graphic_Fx_Drop_Shadow(int coord) = 0; 
		virtual void Show_Graphic_Fx_Transparancy() = 0; 
		
		virtual void Show_Text( int x, int y, std::string text, SDL_Surface *font ) = 0;		
};


 #endif 