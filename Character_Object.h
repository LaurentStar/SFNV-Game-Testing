#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED
#include "Physics.h"
#include "External_Configuration.h"
#include "Bullet.h"
//#include "Soul.h"


 class The_Ys_Guy: public Soul 
 { 
	private: 	
	
		Chain_Link Link;
		
		// Collision boxes of the character.
		Square  Character_Base, Character_Cornice;

		//Allows stuff to come into existance
		Circle Existance_Bubble; 

		//Movement abtributes
		float X_Coord, Y_Coord, Z_Coord;
		float Friction, Degree, Magnitude, X_Vel, Y_Vel, Z_Vel;

		// Objects general details
		int Object_Type;
		int Gravity_Physics;
		int Character_State_Of_Being;
		int Button;		
		int Object_Elevation;
		int Center_Base;

		int Character_General_Direction;
		int Character_Drop_Shadow;

	

		int Frame_Coord_X, Frame_Coord_Y, Frame_Coord_Z;
		// The frame to show at the moment
		int Character_Frame;
		
		//Key_press is a record of the last 2 keys pressed.
		// Phase_count keep track of how many times the phase looped
		//Phase_end ends a phase after a certain time frame
		int  Phase, Phase_Count, Phase_End, Phase_Renew, Key_Press1, Key_Press2;


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
		The_Ys_Guy(); 
		
		//Converts the key presses based on direction
		void Key_Press_Converter();
		
		void Movement_ZXC(Bullet_Object *bullet[]);

		// Used to effect a character stats such as health, speed, ect..
		void Character_Stats_Controller(Bullet_Object *bullet[],Uint32 deltaTicks);
		void Character_Stats_Animation(Uint32 deltaTicks);
		int Character_Stats_Fight_Controller();

		void Character_Reaction_Gather( Bullet_Object);
		// interaction with special objects
		void Game_Object_Interaction( Soul *Spirit[]);

	

		

		void Variable_Definer_Inactive(External_Configuration config);
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
		

		void Game_Start(External_Configuration config);
		void Variable_Setter_Bool_Conditional(int condition, bool condition2);
		void Variable_Setter_Int_Conditional(int condition, int condition2);
		void Variable_Update(Uint32 deltaTicks);
		void Soul_Physics(int condition, Uint32 deltaTicks);
		void Soul_Health_Condtions(Uint32 deltaTicks);
		void Soul_Input();
		void Move_Special_Object();
		void Teleport_Force_Input(float  condition, int condition2);





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

		void Variable_Setter_Special_Conditional(int condition, int condition2, bool conditionBool, int conditionInt){}	
		void Variable_Setter_Ai_Brain_Conditional(int condition, Ai_Brain Copy_Brain) {}

		void Soul_Logic(Ai_Brain Copy_Brain, Uint32 deltaTicks){}

		void Build_Font(SDL_Surface *font){}
		void Variable_Setter(){}
		void Teleport_Direct_Input() {}

		int Get_Type(){return 0;}
		int Get_Gate_Type(){return 0;}// function that changes meaning in almost all classes
		int Get_Child_Num(){return 0;}
		int Get_Slave_Order(){return 0;}
	

		bool Get_Render_Key(){return false;}
		bool Get_Animated_Key(){return false;}
		bool Get_Active_Animation_Key(){return false;}
	
		void Command_Slave_Calculation(){}

		Chain_Link Get_Chain_Link(){return Link;} 
		
		std::string Get_Text() {return "";}
		
		Square Get_Objects_Children(int condition){return Character_Cornice;}

		void Show(){}
		void Show_Children(int condition, int condition2){}
		void Show_Graphic_Fx_Transparancy(){}
		void Show_Text( int x, int y, std::string text, SDL_Surface *font ){}	
 };

 class Cyron_Tanryoku: public Soul 
 { 
		private: 	
		Chain_Link Link;
			
		// Collision boxes of the character.
		Square  Character_Base, Character_Cornice;

		//Allows stuff to come into existance
		Circle Existance_Bubble; 

		//Movement abtributes
		float X_Coord, Y_Coord, Z_Coord;
		float Friction, Degree, Magnitude, X_Vel, Y_Vel, Z_Vel;

		// Objects general details
		int Object_Type;
		int Gravity_Physics;
		int Character_State_Of_Being;
		
		
		int Object_Elevation;
		int Center_Base;

		int Character_General_Direction;
		int Character_Drop_Shadow;

		int Button;
		
		// Where the frames should be
		int Frame_Coord_X, Frame_Coord_Y, Frame_Coord_Z;
		// The frame to show at the moment
		int Character_Frame;
		
		//Key_press is a record of the last 2 keys pressed.
		// Phase_count keep track of how many times the phase looped
		//Phase_end ends a phase after a certain time frame
		int  Phase, Phase_Count, Phase_End, Phase_Renew, Key_Press1, Key_Press2;


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
		 Cyron_Tanryoku(); 
		
		//Converts the key presses based on direction
		void Key_Press_Converter();
		
		void Movement_ZXC(Bullet_Object *bullet[]);

		// Used to effect a character stats such as health, speed, ect..
		void Character_Stats_Controller(Bullet_Object *bullet[],Uint32 deltaTicks);
		void Character_Stats_Animation(Uint32 deltaTicks);
		int Character_Stats_Fight_Controller();

		void Character_Reaction_Gather( Bullet_Object);
		// interaction with special objects
		void Game_Object_Interaction( Soul *Spirit[]);


		

		void Variable_Definer_Inactive(External_Configuration config);
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
		

		void Game_Start(External_Configuration config);
		void Variable_Setter_Bool_Conditional(int condition, bool condition2);
		void Variable_Setter_Int_Conditional(int condition, int condition2);
		void Variable_Update(Uint32 deltaTicks);
		void Soul_Physics(int condition, Uint32 deltaTicks);
		void Soul_Health_Condtions(Uint32 deltaTicks);
		void Soul_Input();
		void Move_Special_Object();
		void Teleport_Force_Input(float  condition, int condition2);





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

		void Variable_Setter_Special_Conditional(int condition, int condition2, bool conditionBool, int conditionInt){}	
		void Variable_Setter_Ai_Brain_Conditional(int condition, Ai_Brain Copy_Brain) {}
		void Soul_Logic(Ai_Brain Copy_Brain, Uint32 deltaTicks){}

		void Build_Font(SDL_Surface *font){}
		void Variable_Setter(){}
		void Teleport_Direct_Input() {}
		void Command_Slave_Calculation(){}


		int Get_Type(){return 0;}
		int Get_Gate_Type(){return 0;}// function that changes meaning in almost all classes
		int Get_Child_Num(){return 0;}
		int Get_Slave_Order(){return 0;}


		bool Get_Render_Key(){return false;}
		bool Get_Animated_Key(){return false;}
		bool Get_Active_Animation_Key(){return false;}
	
		Chain_Link Get_Chain_Link(){return Link;} 
		
		std::string Get_Text() {return "";}
		
		Square Get_Objects_Children(int condition){return Character_Cornice;}

		void Show(){}
		void Show_Children(int condition, int condition2){}
		void Show_Graphic_Fx_Transparancy(){}
		void Show_Text( int x, int y, std::string text, SDL_Surface *font ){}	
		
 };

 class Cxx120: public Soul 
 { 
	private: 	
		
		Chain_Link Link;
		
		// Collision boxes of the character.
		Square  Character_Base, Character_Cornice;

		//Allows stuff to come into existance
		Circle Existance_Bubble; 

		//Movement abtributes
		float X_Coord, Y_Coord, Z_Coord;
		float Friction, Degree, Magnitude, X_Vel, Y_Vel, Z_Vel;

		// Objects general details
		int Object_Type;
		int Gravity_Physics;
		int Character_State_Of_Being;
		
		
		int Object_Elevation;
		int Center_Base;

		int Character_General_Direction;
		int Character_Drop_Shadow;

		int Button;
		
		// Where the frames should be
		int Frame_Coord_X, Frame_Coord_Y, Frame_Coord_Z;
		// The frame to show at the moment
		int Character_Frame;
		
		//Key_press is a record of the last 2 keys pressed.
		// Phase_count keep track of how many times the phase looped
		//Phase_end ends a phase after a certain time frame
		int  Phase, Phase_Count, Phase_End, Phase_Renew, Key_Press1, Key_Press2;


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
		  Cxx120(); 
		
		//Converts the key presses based on direction
		void Key_Press_Converter();
		
		void Movement_ZXC(Bullet_Object *bullet[]);

		// Used to effect a character stats such as health, speed, ect..
		void Character_Stats_Controller(Bullet_Object *bullet[],Uint32 deltaTicks);
		void Character_Stats_Animation(Uint32 deltaTicks);
		int Character_Stats_Fight_Controller();

		void Character_Reaction_Gather( Bullet_Object);
		// interaction with special objects
		void Game_Object_Interaction( Soul *Spirit[]);



		

		void Variable_Definer_Inactive(External_Configuration config);
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
		

		void Game_Start(External_Configuration config);
		void Variable_Setter_Bool_Conditional(int condition, bool condition2);
		void Variable_Setter_Int_Conditional(int condition, int condition2);
		void Variable_Update(Uint32 deltaTicks);
		void Soul_Physics(int condition, Uint32 deltaTicks);
		void Soul_Health_Condtions(Uint32 deltaTicks);

		void Soul_Input();
		void Move_Special_Object();
		void Teleport_Force_Input(float  condition, int condition2);





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
		
		////
		//////////
		///////////////////////
		////////////////////////////////////////////////
		//WORTHLESS//
		////////////////////////////////////////////////
		///////////////////////
		//////////
		////
		void Variable_Setter_Special_Conditional(int condition, int condition2, bool conditionBool, int conditionInt){}
		void Variable_Setter_Ai_Brain_Conditional(int condition, Ai_Brain Copy_Brain) {}

		void Soul_Logic(Ai_Brain Copy_Brain, Uint32 deltaTicks){}

		void Build_Font(SDL_Surface *font){}
		void Teleport_Direct_Input() {}
		void Variable_Setter(){}
		void Command_Slave_Calculation(){}

		int Get_Type(){return 0;}
		int Get_Gate_Type(){return 0;}// function that changes meaning in almost all classes
		int Get_Child_Num(){return 0;}
		int Get_Slave_Order(){return 0;}
		
		
		bool Get_Render_Key(){return false;}
		bool Get_Animated_Key(){return false;}
		bool Get_Active_Animation_Key(){return false;}
		
		Chain_Link Get_Chain_Link(){return Link;}  
		
		std::string Get_Text() {return "";}

		Square Get_Objects_Children(int condition){return Character_Cornice;}
		


		void Show(){}
		void Show_Children(int condition, int condition2){}
		void Show_Graphic_Fx_Transparancy(){}
		void Show_Text( int x, int y, std::string text, SDL_Surface *font ){}
 };

 class Character: public Soul 
 { 
	private: 	
		// Collision boxes of the character.
		Square  Character_Base, Character_Cornice;
		
		Chain_Link Link;
		
		//Allows stuff to come into existance
		Circle Existance_Bubble; 

		//Movement abtributes
		float X_Coord, Y_Coord, Z_Coord;
		float Friction, Degree, Magnitude, X_Vel, Y_Vel, Z_Vel;

		// Objects general details
		int Object_Type;
		int Gravity_Physics;
		int Character_State_Of_Being;
		
		
		int Object_Elevation;
		int Center_Base;

		int Character_General_Direction;
		int Character_Drop_Shadow;
		int Button;
		
		// Where the frames should be
		int Frame_Coord_X, Frame_Coord_Y, Frame_Coord_Z;
		// The frame to show at the moment
		int Character_Frame;
		
		//Key_press is a record of the last 2 keys pressed.
		// Phase_count keep track of how many times the phase looped
		//Phase_end ends a phase after a certain time frame
		int  Phase, Phase_Count, Phase_End, Phase_Renew, Key_Press1, Key_Press2;


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
		 Character(); 
		
		//Converts the key presses based on direction
		void Key_Press_Converter();
		
		void Movement_ZXC(Bullet_Object *bullet[]);

		// Used to effect a character stats such as health, speed, ect..
		void Character_Stats_Controller(Bullet_Object *bullet[],Uint32 deltaTicks);
		void Character_Stats_Animation(Uint32 deltaTicks);
		int Character_Stats_Fight_Controller();

		void Character_Reaction_Gather( Bullet_Object);
		// interaction with special objects
		void Game_Object_Interaction( Soul *Spirit[]);

		

		void Variable_Definer_Inactive(External_Configuration config);
		
		float Get_Character_Degree();
		float Get_Character_Magnitude();

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
		

		void Game_Start(External_Configuration config);
		void Variable_Update(Uint32 deltaTicks);
		void Soul_Physics(int condition, Uint32 deltaTicks);
		void Soul_Input();
		void Move_Special_Object();
		void Teleport_Force_Input(float  condition, int condition2);

		Square Get_Objects_Base();
		Square Get_Objects();

		int Get_Object_Type();	
		int Get_Gravity_Physics();
		int Get_Object_Elevation();
		int Get_X();
		int Get_Y();
		int Get_Z();
		int Get_Center_Base();
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
		void Variable_Setter_Special_Conditional(int condition, int condition2, bool conditionBool, int conditionInt){}
		void Variable_Setter_Ai_Brain_Conditional(int condition, Ai_Brain Copy_Brain) {}
		void Soul_Logic(Ai_Brain Copy_Brain, Uint32 deltaTicks){}

		void Build_Font(SDL_Surface *font){}
		void Variable_Setter_Bool_Conditional(int condition, bool condition2){}		
		void Variable_Setter_Int_Conditional(int condition, int condition2){}
		void Variable_Setter(){}
		void Teleport_Direct_Input() {}
		void Soul_Health_Condtions(Uint32 deltaTicks){}
		void Command_Slave_Calculation(){}


		int Get_Type(){return 0;}
		int Get_Gate_Type(){return 0;}// function that changes meaning in almost all classes
		int Get_Child_Num(){return 0;}
		int Get_Slave_Order(){return 0;}
		int Get_Health(){return -1;}
		
		bool Get_Render_Key(){return false;}
		bool Get_Animated_Key(){return false;}
		bool Get_Active_Animation_Key(){return false;}
		
		Chain_Link Get_Chain_Link(){return Link;} 
		std::string Get_Text() {return "";}

		Square Get_Objects_Children(int condition){return Character_Cornice;}

		void Show(){}
		void Show_Graphic_Fx_Transparancy(){}
		void Show_Children(int condition, int condition2){}
		void Show_Text( int x, int y, std::string text, SDL_Surface *font ){}
		
 };
 #endif // CHARACTER_H_INCLUDED