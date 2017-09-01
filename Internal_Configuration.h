 #ifndef INTERNAL_CONFIG_H_INCLUDED
#define INTERNAL_CONFIG_H_INCLUDED
#include "King.h"
#include "Soul.h"
#include "External_Configuration.h" 

 class Internal_Config
 { 
	private: 
	
		//Object's linking parts
		Chain_Link Master_Link, Slave_Link;

		std::string Level_Name;

		//Writing location where to send player
		int Object_Current_X, Object_Current_Y, Object_Current_Z;
		 
		int Type, On_Screen_Type;

		//Used with Gate objects
		int Location, Level, Warp_Type;

		// total number of all objects
		int Total_Gate_Objects,  Total_Render_Objects, Total_Misc_Objects, Total_Hit_Box_Objects, Total_On_Screen_Misc_Objects; 

		//Num of child objects managed by regular object
		int Child_Num;

		// Track Gaate info
		int Track_Gate_Objects[MAX_GAME_OBJECTS];		
		int Track_Misc_Objects[MAX_GAME_OBJECTS];
		int Track_Hit_Box_Objects[MAX_GAME_OBJECTS];
		int Track_On_Screen_Misc_Objects[MAX_GAME_OBJECTS];
		int Track_Render_Objects[MAX_GAME_OBJECTS];

		int Misc_Objects_Type[MAX_GAME_OBJECTS];
		int On_Screen_Misc_Objects_Type[MAX_GAME_OBJECTS];
		int On_Screen_Child_Num[20];

		bool Alive_Key;
		
	public: 
		//Initializes variables 
		Internal_Config(); 
		
		//Sets up variables to optimized calculations
		void Optimization_Variable_Definer( Soul *Spirit[] );

		//Give all chain links their addresses
		void Optimization_Chain_Link_Definer( Soul *Spirit[] );

		//Defines variables based on conditions at any momnet called
		void Variable_Setter_Conditional(int condition);

		void Level_Gate_Collision(Soul *Spirit[],External_Configuration config);
		void Misc_Object_Collision(Soul *Spirit[],External_Configuration config);
		void On_Screen_Misc_Object_Collision(Soul *Spirit[],External_Configuration config);
		void Hit_Box_Object_Collision(Soul *Spirit[]);
		//void Variable_Manager();

		void Hit_Box_Placement();
		// Turns on a switch that allow objects to be rendered in rendered class for objects that appear all the time.
		void Default_Object_Render(Soul *Spirit[]);
	//	void Interactive_Config_Object(Soul *Spirit[],External_Configuration config);

		//
		////
		/////////
		////////////////
		///HEALTH CONDITION FUNCTIONS FOR GAME OBJECTS//////////////
		////////////////
		/////////
		////
		//
		void Internal_Config::Text_Speak(int spirit_num, Soul *Spirit[]);
		
 }; 

 #endif // PHYSICS_H_INCLUDED