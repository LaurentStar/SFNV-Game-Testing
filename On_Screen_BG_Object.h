#ifndef ON_SCREEN_BG_OBJECT_H_INCLUDED
#define ON_SCREEN_BG_OBJECT_H_INCLUDED
#include "Soul.h"

class On_Screen_BG_Object: public Soul
 { 
	private:

	bool Render_Key ;

	Chain_Link Link; 
	//Represents a single object on the 2D screen
	Square Screen_Object;

	float Friction, Degree, Magnitude, X_Vel, Y_Vel;

	// The Coordinates of all object in a 2D view
	float Target_X, Target_Y;

	// Types help scroll through the menu
	int Object_Type, Type;

	//Allows objects to move
	int Gravity_Physics;
		
	int Button;


	//Assigning a value to this allow you to decide what game_mode an object should render in
	int Game_Stat;
	bool Alive_Key;
	enum {SAVE_MENU_RETURN, SAVE_MENU_SAVE, SAVE_MENU_MAP, SAVE_MENU_SWITCH, SAVE_MENU_DATALOG, SAVE_MENU_QUIT};
	public:
		
		On_Screen_BG_Object(int x, int y, int type);
		
		
		void Variable_Setter();
		void Variable_Setter_Bool_Conditional(int condition, bool condition2);

		void Soul_Input();
		void Variable_Update(Uint32 deltaTicks);

		int Get_Object_Type();
		
		int Get_Type();
		//Reveals the mode the object should render in. 
		int Get_Gate_Type();
		bool Get_Render_Key();
		bool Get_Alive_Key();
		int Get_Gravity_Physics();

		//Show the Recticle
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
		void Game_Start(External_Configuration config){}

		void Variable_Setter_Int_Conditional(int condition, int condition2){}
		void Variable_Setter_Special_Conditional(int condition, int condition2, bool conditionBool, int conditionInt){}
		void Variable_Setter_Ai_Brain_Conditional(int condition, Ai_Brain Copy_Brain) {}

		//The physics of an objects and movement
		void Soul_Physics(int condition, Uint32 deltaTicks){}
		void Soul_Logic(Ai_Brain Copy_Brain, Uint32 deltaTicks){}
		void Soul_Health_Condtions(Uint32 deltaTicks){}

		void Teleport_Direct_Input() {}
		void Teleport_Force_Input(float condition, int condition2){}
		//Teleport an object during a level transition. 
		void Move_Special_Object(){}

		
		void Build_Font(SDL_Surface *font){}
		void Command_Slave_Calculation(){}
		//The location a gate goes too
	
	
		int Get_Object_Elevation(){return 0;}
		int Get_Object_State(){return 0;}
		int Get_Slave_Order(){return 0;}

		int Get_Health() {return -1;}
		int Get_X(){return 0;}
		int Get_Y(){return 0;}
		int Get_Z(){return 0;}
		int Get_Child_Num(){return 0;}

		//Only used for Squares, Circles, and other known shapes. No vectors.
		int Get_Center_Base(){return 0;}
		Square Get_Objects(){return Screen_Object;}
		Square Get_Objects_Base(){return Screen_Object;}
		bool Get_Animated_Key(){return false;}
		bool Get_Active_Animation_Key(){return false;}
	
		Chain_Link Get_Chain_Link(){return Link;} 
		std::string Get_Text() {return "";}

		Square Get_Objects_Children(int condition){return  Screen_Object;}

		void Show_Base(){}

		//Exclusive float type functions
		void Show(int condition){}
		void Show_Children(int condition, int condition2){}
		void Show_Graphic_Fx_Shadowed(){}
		void Show_Graphic_Fx_Drop_Shadow(int coord){} 
		void Show_Graphic_Fx_Transparancy(){}
		void Show_Text( int x, int y, std::string text, SDL_Surface *font ){}
 }; 
 

#endif // CHARACTER_H_INCLUDED