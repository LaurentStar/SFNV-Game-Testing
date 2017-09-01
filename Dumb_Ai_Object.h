#ifndef DUMB_AI_OBJECT_H_INCLUDED
#define DUMB_AI_OBJECT_H_INCLUDED
#include "Physics.h"
#include "External_Configuration.h"
#include "Soul.h"


class Dumb_AI_Object: public Soul 
 { 
	private: 	
	
		Chain_Link Link;
		
		Ai_Brain Brain;

		// Collision boxes of the character.
		Square Ai_Base, Ai_Cornice;
		Square Screen_Object_Children[ 3];


		//Allows stuff to come into existance
		Circle Existance_Bubble; 

		//Movement abtributes
		int Object_Coord_x, Object_Coord_y, Object_Coord_z;
		float Friction, Degree, Magnitude, X_Vel, Y_Vel, Z_Vel;

		// Objects general details
		int Object_Type, Type, Object_Location;
		int Gravity_Physics;
		int Character_State_Of_Being;
		int Button;		
		int Center_Base;

		int Object_Width, Object_Lenght, Object_Height;
		int Object_Front_Edge, Object_Elevation;
		
		int Character_General_Direction;
		int Character_Drop_Shadow;

	

		int Frame_Coord_X, Frame_Coord_Y, Frame_Coord_Z;
		// The frame to show at the moment
		int Character_Frame;
		
	


		// When this is not -1, it effects the character's animation 
		// and movement regardless of button input
		int Character_Animation_Exception;
		
		int Character_Health, Health_Plus, Health_Minus, Health_Timer, Character_Health_Time;
	
		int Health_Recovery_Speed;

		

		float Attack_Phase_Timer;
		float Character_Animation_Exception_Timer;
		// Health stats
		float Character_Health_Timer;

		//Various modes to play in
		bool Attack_Mode, Attack_Phase, Combo_Null_Guide;

		// The Charcter's reaction to being in dark spots.
		bool Alive_Key;
		bool Fall_Damage;
		bool Character_Regeneration ;

		enum { GRAVITY = 300};
		enum {NO_DIRECTION, WEST, SOUTH_WEST, SOUTH, SOUTH_EAST, EAST, NORTH_EAST, NORTH, NORTH_WEST};
	public: 
		//Initializes variables 
		Dumb_AI_Object(int x, int y,  int z, int object_type, int object_location); 
		
/////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
		

		//AI


		void Variable_Setter();
		void Variable_Setter_Bool_Conditional(int condition, bool condition2);
		void Variable_Setter_Int_Conditional(int condition, int condition2);
		void Variable_Setter_Ai_Brain_Conditional(int condition, Ai_Brain Copy_Brain);
		void Variable_Update(Uint32 deltaTicks);
		void Soul_Physics(int condition, Uint32 deltaTicks);
		void Soul_Logic(Ai_Brain Copy_Brain, Uint32 deltaTicks);
		void Soul_Health_Condtions(Uint32 deltaTicks);
		void Soul_Input();
		void Move_Special_Object();
		void Teleport_Force_Input(float  condition, int condition2);
		void Command_Slave_Calculation(){}


		Square Get_Objects_Base();
		Square Get_Objects();
		

		float Get_Character_Degree();
		float Get_Character_Magnitude();

		int Get_Object_Type();	
		int Get_Gravity_Physics();
		int Get_Object_Elevation();

		int Get_X();
		int Get_Y();
		int Get_Z();
		int Get_Center_Base();


		int Get_Health();
		int Get_Character_Animation_Exception();
		int Get_Object_State();

		bool Get_Alive_Key();

		void Show(int condition);
		void Show_Base();
		void Show_Graphic_Fx_Shadowed();
		void Show_Graphic_Fx_Drop_Shadow(int coord);
		
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
		void Variable_Setter_Special_Conditional(int condition, int condition2, bool conditionBool, int conditionInt){}	
		
		void Build_Font(SDL_Surface *font){}
		
		void Teleport_Direct_Input() {}

		int Get_Type(){return 0;}
		int Get_Gate_Type(){return 0;}// function that changes meaning in almost all classes
		int Get_Child_Num(){return 0;}
		int Get_Slave_Order(){return 0;}
	

		bool Get_Render_Key(){return false;}
		bool Get_Animated_Key(){return false;}
		bool Get_Active_Animation_Key(){return false;}
	
		Chain_Link Get_Chain_Link(){return Link;} 
		
		std::string Get_Text() {return "";}
		
		Square Get_Objects_Children(int condition){return Ai_Cornice;}

		void Show(){}
		void Show_Children(int condition, int condition2){}
		void Show_Graphic_Fx_Transparancy(){}
		void Show_Text( int x, int y, std::string text, SDL_Surface *font ){}	
 };


#endif // CHARACTER_H_INCLUDED