#ifndef ENVIRONMENT_OBJECTS_H_INCLUDED
#define ENVIRONMENT_OBJECTS_H_INCLUDED
//#include "Global.h"
#include "Soul.h"


//The tile
class Environment_Floor_Objects: public Soul
{
	private:  
	Chain_Link Link;
	Square Floor_Objects;

    //The tile type
    int Type, Object_Type;
	
	//Coordinates of the objects
	int Object_Coord_x, Object_Coord_y;
	int Center_Base;

	// Collsion detection properties of Objects. Width relates to x, Lenght relate to y, Height relates to z. 
	int Object_Width, Object_Lenght;

	// Activate animation for objects base on type
	bool Animated;
	bool Alive_Key;




    public:
    
	Environment_Floor_Objects();

	//(1) The construtor for the base floor objects.Most base floor tiles are squares.
	Environment_Floor_Objects( int x, int y,  int object_type );




	// Use restricted to Constructor 1 until further anylisis. Uses type to give value to height and width. 
	//void Width_Height_Assigner(int type);


    //Get the tile type
    int Get_Type();
	int Get_Object_Type();
	int Get_X();
	int Get_Y();
			
	int Get_Center_Base();
 
	bool Get_Alive_Key();

	//Display functions only
	void Show();
	
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

	void Soul_Physics(int condition, Uint32 deltaTicks){}
	void Soul_Logic(Ai_Brain Copy_Brain, Uint32 deltaTicks){}
	void Soul_Health_Condtions(Uint32 deltaTicks){}

	void Soul_Input(){}
	void Move_Special_Object(){}
	void Teleport_Direct_Input() {}
	void Teleport_Force_Input(float condition, int condition2){}
	void Game_Start(External_Configuration config){}
	void Variable_Setter_Bool_Conditional(int condition, bool condition2){}
	void Variable_Setter_Int_Conditional(int condition, int condition2){}
	void Variable_Setter_Special_Conditional(int condition, int condition2, bool conditionBool, int conditionInt){}
	void Variable_Setter_Ai_Brain_Conditional(int condition, Ai_Brain Copy_Brain) {}
	void Variable_Setter(){}
	void Build_Font(SDL_Surface *font){}

	void Variable_Update(Uint32 deltaTicks){}
	void Command_Slave_Calculation(){}

    Square Get_Objects(){ return Floor_Objects;}
	Square Get_Objects_Base(){ return Floor_Objects;}
	
	int Get_Health() {return -1;}
	int Get_Gate_Type(){return 0;} 
	int Get_Gravity_Physics(){return 0;}
	int Get_Object_Elevation(){return 0;}
	int Get_Child_Num(){return 0;}
	int Get_Slave_Order(){return 0;}
	Chain_Link Get_Chain_Link(){return Link;} 
	bool Get_Render_Key(){return false;}
	bool Get_Animated_Key(){return false;}
	bool Get_Active_Animation_Key(){return false;}
	bool Get_In_Use(){return false;} 
	std::string Get_Text() {return "";}
	int Get_Object_State() {return 0;}
	int Get_Z() {return 0;}

	Square Get_Objects_Children(int condition){return  Floor_Objects;}
	
	void Show_Base(){}
	void Show(int o){}
	void Show_On_Screen(){}
	void Show_Children(int condition, int condition2){}
	void Show_Graphic_Fx_Shadowed(){}
	void Show_Graphic_Fx_Drop_Shadow(int coord){}
	void Show_Graphic_Fx_Transparancy(){}
	void Show_Text( int x, int y, std::string text, SDL_Surface *font ){}
};


class Environment_Float_Objects: public Soul
{
    private: 	
	Chain_Link Link; 
	Square Floating_Objects, Floating_Objects_Base;


	int Gravity_Physics;

    //The tile type and the type of the class
    int Type, Object_Type;
	
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




    public:
    
	//(0) This constructor set the values of a few special variables.
	Environment_Float_Objects(); 
    Environment_Float_Objects( int x, int y, int z, int object_type );




	//Define a square using object type. 
	void Variable_Setter();
	void Variable_Update(Uint32 deltaTicks);


	void Soul_Physics(int condition, Uint32 deltaTicks);


    //Get the tile type
    int Get_Type();
	int Get_Object_Type();
	int Get_Gravity_Physics();
	int Get_Object_Elevation();


	int Get_X();
	int Get_Y();
	int Get_Z();

	int Get_Center_Base();
    //Get the collision box of squares. 
 
	Square Get_Objects();
	Square Get_Objects_Base();

	bool Get_Alive_Key();


	//Display functions only
	void Show();
	void Show_Base();
	void Show_Graphic_Fx_Transparancy();


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
	void Variable_Setter_Bool_Conditional(int condition, bool condition2){}
	void Variable_Setter_Int_Conditional(int condition, int condition2){}
	void Variable_Setter_Special_Conditional(int condition, int condition2, bool conditionBool, int conditionInt){}
	void Variable_Setter_Ai_Brain_Conditional(int condition, Ai_Brain Copy_Brain) {}
	void Teleport_Direct_Input() {}
	void Teleport_Force_Input(float condition, int condition2){}
	void Build_Font(SDL_Surface *font){}
	void Soul_Input(){}
	void Soul_Logic(Ai_Brain Copy_Brain, Uint32 deltaTicks){}
	void Soul_Health_Condtions(Uint32 deltaTicks){}
	void Move_Special_Object(){}
	void Command_Slave_Calculation(){}
	int Get_Health() {return -1;}
	int Get_Gate_Type(){return 0;} 
	int Get_Object_State() {return 0;}
	int Get_Child_Num(){return 0;}
	int Get_Slave_Order(){return 0;}
	bool Get_Render_Key(){return false;}
	bool Get_Animated_Key(){return false;}
	bool Get_Active_Animation_Key(){return false;}
	Chain_Link Get_Chain_Link(){return Link;} 
	std::string Get_Text() {return "";}
	Square Get_Objects_Children(int condition){return  Floating_Objects;}




	void Show(int o){}
	void Show_On_Screen(){}
	void Show_Children(int condition, int condition2){}
	void Show_Graphic_Fx_Shadowed(){}
	void Show_Graphic_Fx_Drop_Shadow(int coord){}
	void Show_Text( int x, int y, std::string text, SDL_Surface *font ){}
};



class Environment_Objects
{
    private:
    
	

	Square Floor_Objects;
	Square Floating_Objects, Floating_Objects_Base;
	Square Grounded_Objects;

    //The tile type
    int Type;
	
	//Coordinates of the objects
	int Object_Coord_x, Object_Coord_y, Object_Coord_z;
	
	// Collsion detection properties of Objects. Width relates to x, Lenght relate to y, Height relates to z. 
	int Object_Width, Object_Lenght, Object_Height;
	
	// The front edge of an object. Have a value in relation to y
	int Object_Front_Edge, Object_Elevation;

	// Activate animation for objects base on type
	bool Animated;


	enum {SQUARE, CIRCLE, TRIANGLE};


    public:
    
	//(0) This constructor set the values of a few special variables.
	Environment_Objects();

	//(1) The construtor for the base floor objects.Most base floor tiles are squares.
	Environment_Objects( int x, int y,  int object_type );


	//(2) The construtor for floating square objects. Requires many many  test. Check logs to see completeion prerequisits.  
    Environment_Objects( int x, int y, int z, int object_type );

	//(3) The construtor for grounded square objects. Bool constructor has no usage. Used so compiler won't confuse consturtors.
    Environment_Objects( bool Required, int x, int y, int z, int object_type );

	// Use restricted to Constructor 1 until further anylisis. Uses type to give value to height and width. 
	void Width_Height_Assigner(int type);

	//Define a square using object type. 
	void Square_Assigner(int type , int y);

    //Get the tile type
    int Get_Type();
	int Get_X();
	int Get_Y();
	int Get_Z();
    //Get the collision box of squares. 
    Square Get_Floor_Objects();
	Square Get_Floating_Square_Objects();
	Square Get_Floating_Square_Objects_Base();
	Square Get_Ground_Square_Objects();

	//Display functions only
	void Show_Environment_Float_Object(int condition);
	void Show_Environment_Float_Base_Object();
	void Show_Environment_Ground_Object();
	void Show_Environment_Floor_Object();

	
	void Set_Values(int x, int y,  int object_type);

};



#endif // ENVIRONMENT_OBJECTS_H_INCLUDED