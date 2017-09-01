#ifndef CONFIG_OBJECTS_H_INCLUDED
#define CONFIG_OBJECTS_H_INCLUDED

//#include "Global.h"
#include "Soul.h"


//The tile
class Config_Objects: public Soul
{
	  private: 	
	Chain_Link Link;
	Square Floating_Objects, Floating_Objects_Base;


	int Gravity_Physics;

    //The tile type and the type of the class
    int Type, Gate_Type, Object_Type;
	
	//Coordinates of the objects
	int Object_Coord_x, Object_Coord_y, Object_Coord_z;
	int Center_Base;


	// Collsion detection properties of Objects. Width relates to x, Lenght relate to y, Height relates to z. 
	int Object_Width, Object_Lenght, Object_Height;
	
	// The front edge of an object. Have a value in relation to y
	int Object_Front_Edge, Object_Elevation;

	// Activate animation for objects base on type
	bool Animated;
	bool Alive_Key; 


	int Location, Level;


    public:
    
	//(0) This constructor set the values of a few special variables.
	Config_Objects();



	//(2) The construtor for floating square objects. Requires many many  test. Check logs to see completeion prerequisits.  
    Config_Objects( int x, int y, int z, int object_type, int gate_type );




	//Define a square using object type. 
	void Variable_Setter();
	void Variable_Update(Uint32 deltaTicks);


	void Soul_Physics(int condition, Uint32 deltaTicks);



    //Get the tile type
    int Get_Type();
	int Get_Object_Type();
	int Get_Gate_Type();

	int Get_Gravity_Physics();
	int Get_Object_Elevation();
	

	int Get_X();
	int Get_Y();
	int Get_Z();

	int Get_Center_Base();
    //Get the collision box of squares. 


	bool Get_Alive_Key();


	Square Get_Objects();
	Square Get_Objects_Base();


	//Display functions only
	void Show();
	void Show_Base();



	//
	///////
	////////////////
	//////////////////////////
	//////////////////////////////////////
	///////////////////////////////////////////////////
	//USELESS
	///////////////////////////////////////////////////
	///////////////////////////////////////
	///////////////////////////
	////////////////
	///////
	//
	void Game_Start(External_Configuration config){}
	void Build_Font(SDL_Surface *font){}
	void Move_Special_Object(){}
	void Soul_Health_Condtions(Uint32 deltaTicks){}
	void Variable_Setter_Bool_Conditional(int condition, bool condition2){}
	void Variable_Setter_Int_Conditional(int condition, int condition2){}
	void Variable_Setter_Special_Conditional(int condition, int condition2, bool conditionBool, int conditionInt){}
	void Variable_Setter_Ai_Brain_Conditional(int condition, Ai_Brain Copy_Brain) {}
	void Soul_Logic(Ai_Brain Copy_Brain, Uint32 deltaTicks){}
	void Teleport_Direct_Input(){}
	void Teleport_Force_Input(float condition, int condition2){}
	void Command_Slave_Calculation(){}

	int Get_Health() {return -1;}
	int Get_Object_State() {return 0;}
	int Get_Child_Num(){return 0;}
	int Get_Slave_Order(){return 0;}
	bool Get_Render_Key(){return false;}
	bool Get_Animated_Key(){return false;}
	bool Get_Active_Animation_Key(){return false;}
	
	Chain_Link Get_Chain_Link(){return Link;} 
	
	std::string Get_Text() {return "";}
	
	Square Get_Objects_Children(int condition){return  Floating_Objects;}

	void Soul_Input(){}

	void Show(int o){}
	void Show_Children(int condition, int condition2){}
	void Show_Text( int x, int y, std::string text, SDL_Surface *font ){}
	
	void Show_Graphic_Fx_Shadowed(){}
	void Show_Graphic_Fx_Drop_Shadow(int coord){}
	void Show_Graphic_Fx_Transparancy(){}
};



#endif // ENVIRONMENT_OBJECTS_H_INCLUDED