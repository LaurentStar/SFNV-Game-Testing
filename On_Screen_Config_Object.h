#ifndef ON_SCREEN_CONFIG_OBJECT_H_INCLUDED
#define ON_SCREEN_CONFIG_OBJECT_H_INCLUDED
#include "Soul.h"

class On_Screen_Config_Object: public Soul
 { 
	private:
	// Sub objects apart of an array linked to a main object. Not equivelent to class child
	enum { MAX_OBJECT_CHILDREN = 3};
	
	Chain_Link  Link; 

	std::string Text;

	//Represents a single object on the 2D screen
	Square Screen_Object;
	Square Screen_Object_Children[ MAX_OBJECT_CHILDREN];

	float Friction, Degree, Magnitude, X_Vel, Y_Vel;

	// The Coordinates of all object in a 2D view
	float Target_X, Target_Y, Target_X_Child, Target_Y_Child;

	int Lenght, Width;

	// Types help scroll through the menu
	int Object_Type, Type, Child_Num;

	int Slave_Order;
	//Allows objects to move
	int Gravity_Physics;
		
	int Button;


	//Assigning a value to this allow you to decide what game_mode an object should render in
	int Game_Stat;

	bool Alive_Key;
	bool Render_Key ;

	public:
		
		On_Screen_Config_Object(int x, int y, int type);
		
		
		
		void Variable_Setter();
		void Variable_Setter_Bool_Conditional(int condition, bool condition2);
		void Variable_Setter_Special_Conditional(int condition, int condition2, bool conditionBool, int conditionInt);
		void Soul_Input();
		void Variable_Update(Uint32 deltaTicks);
			
		void Command_Slave_Calculation();
	
		int Get_X();
		int Get_Y();

		int Get_Object_Type();
		
		int Get_Type();
		//Reveals the mode the object should render in. 
		int Get_Gate_Type();
		
		int Get_Gravity_Physics();
		int Get_Child_Num();
		bool Get_Render_Key();
		bool Get_Alive_Key();
		
		std::string Get_Text() ;
		Chain_Link Get_Chain_Link();
		
		Square Get_Objects();
		Square Get_Objects_Children(int condition);
	
		void Show(int condition);
		void Show_Children(int condition, int condition2);

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

		void Variable_Setter_Int_Conditional(int condition, int condition2){}
		void Variable_Setter_Ai_Brain_Conditional(int condition, Ai_Brain Copy_Brain) {}

		//The physics of an objects and movement
		void Soul_Physics(int condition, Uint32 deltaTicks){}
		void Soul_Logic(Ai_Brain Copy_Brain, Uint32 deltaTicks){}
		void Soul_Health_Condtions(Uint32 deltaTicks){}

		//Teleport an object during a level transition. 
		void Move_Special_Object(){}
		void Teleport_Direct_Input() {}
		void Teleport_Force_Input(float condition, int condition2){}
	
		
		//The location a gate goes too
	
	
		int Get_Object_Elevation(){return 0;}
		int Get_Object_State(){return 0;}
		
		int Get_Health() {return -1;}
	
		int Get_Z(){return 0;}

		

		//Only used for Squares, Circles, and other known shapes. No vectors.
		int Get_Center_Base(){return 0;}
		
		Square Get_Objects_Base(){return Screen_Object;}
		
		
		
		
		bool Get_Animated_Key(){return false;}
		bool Get_Active_Animation_Key(){return false;}
		

		void Show_Base(){}

		//Exclusive float type functions
		void Build_Font(SDL_Surface *font){}
		//Show the Recticle
		void Show(){}
		
		void Show_Graphic_Fx_Shadowed(){}
		void Show_Graphic_Fx_Drop_Shadow(int coord){} 
		void Show_Graphic_Fx_Transparancy(){}
		void Show_Text( int x, int y, std::string text, SDL_Surface *font ){}
 }; 
 

#endif // CHARACTER_H_INCLUDED