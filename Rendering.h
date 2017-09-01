#ifndef RENDERING_H_INCLUDED
#define RENDERING_H_INCLUDED


#include "Character_Object.h"
#include "Enemy.h"
#include "Environment_Objects.h"
//#include "Editor_Player.h"
#include "On_Screen_Object.h"
#include "Bullet.h"

 class Rendering 
 { 
	private: 

		//Slave handler variables

		Chain_Link Master_Link,Slave_Link;


		// Turns Skyline on and off
		bool Sky_Line_Key;
		// Skips rendering an object in full transparacny. 
		int Transpancy_Skip; 
		
		//////////////////////////////////////////////////////////////////////////////////
		//Base objects rendering and floor types
		/////////////////////////////////////////////////////////////////////////////////
		//Counts and finds the total number of floor objects in a level
		int Total_Floor_Objects, Total_Float_Base_Objects, Total_Character_Objects, Total_Smart_AI_Objects;

		//Tracks Soul objects element IDs that are floor type. Remaining undefined element IDs of this array are set to -1 = NULL;
		int Track_Floor_Objects[MAX_GAME_OBJECTS];
		int Track_Float_Base_Objects[MAX_GAME_OBJECTS];
		int Track_Character_Base_Objects[MAX_GAME_OBJECTS];
		int Track_Smart_AI_Base_Objects[MAX_GAME_OBJECTS];
		//////////////////////////////////////////////////////////////////////////////////
		//objects rendering and Float types
		/////////////////////////////////////////////////////////////////////////////////
		//Counts the total number of objects that aren't floor.
		int Total_Objects;

		//Tracks Soul objects element IDs that aren't floor type. Remaining undefined element IDs of this array are set to -1 = NULL;
		int Object_Track[MAX_GAME_OBJECTS];

		//Track the object type for faster function picking and rendering
		int Object_Type[MAX_GAME_OBJECTS];

		// Keeps track of the physics of objects 
		int Object_Physics[MAX_GAME_OBJECTS];

		// Keeps track of the base location of an object. Updated only if Physics aren't static type.  
		int  Object_Base[MAX_GAME_OBJECTS];

		//The elevention of static and dynamic objects
		int Object_Elevation[MAX_GAME_OBJECTS];
		
		
		//////////////////////////////////////////////////////////////////////////////////
		//On Screen Objects rendering 
		/////////////////////////////////////////////////////////////////////////////////
		//Counts the total number of objects that aren't floor.
		int Total_Screen_Objects;
	
		int Screen_Object_Track[MAX_GAME_OBJECTS];
		
		//Track the object type for faster function picking and rendering
		int Screen_Object_Type[MAX_GAME_OBJECTS];
		int Screen_Type[MAX_GAME_OBJECTS];
		int Screen_Object_Stat[MAX_GAME_OBJECTS];
		int Screen_Child_Num[20];
		bool Screen_Animated_Key[MAX_GAME_OBJECTS];


		//////////////////////////////////////////////////////////////////////////////////
		//objects calculating float type
		/////////////////////////////////////////////////////////////////////////////////
		// Is used to keep track of object and is reset to zero after rendering
		int Order;
		int Magnitude;
		// calculate the order to render using collision detection and elevation height. No two int element has the same number 
		int Render_Order_Optimizate[MAX_GAME_OBJECTS];
		int Render_Order_Optimizate_Past[MAX_GAME_OBJECTS];
		int Render_Order[MAX_GAME_OBJECTS];
		int Render_Order_Past[MAX_GAME_OBJECTS];
		
		//////////////////////////////////////////////////////////////////////////////////
		//On Screen Object Frame handling
		/////////////////////////////////////////////////////////////////////////////////

		int On_Screen_Frames;
		int On_Screen_Frames_Children[20];
		int On_Screen_Frame_Start, On_Screen_Frame_End;
		int On_Screen_Child_Frame_Start[20], On_Screen_Child_Frame_End[20]; // Only 20 children for now. 
		
		int On_Screen_Type, On_Screen_Object_Type;
		int On_Screen_Child_Num;

		int Level_Width, Level_Lenght;


		//The Character's coordinates on map. Retrieved from a function
		float Character_X, Character_Y, Character_Z; 
		float Character_Magnitude;

		int Character_State, Button, Degree;
		int Transparency; 
		int Character_Altitude;

		
		// "Star"t is where you start from, "Go" is where you reset to loop, "Stop" is ending the animation, Animation
		// is the animation that gets played. "Frame is the actual imagine value give to the function argument" 
		int Animation_Exception;

		float Frame;
		int Frame_Start, Frame_Go, Frame_Stop, Frame_Speed, Frame_Animation;
		bool Loop, Get_Loop_Started, Complex_Loop;


		// Looping conditions
		enum {LOOP, NO_LOOP};

		//The speeds the frames get played... "OMEGAMATHETA" Is a combinatination of the greek letters... Gamma, Omega, Theta.
		// It means nothing....
		enum {SPEED_OMEGAMATHETA, SPEED_I, SPEED_II, SPEED_III = 10, SPEED_IV = 15, SPEED_V};


		//Various directions the character could face
		enum {UP_DIRECTION = 90, LEFT_DIRECTION = 180, RIGHT_DIRECTION = 0, DOWN_DIRECTION = 270,
			  LEFT_UP_DIRECTION = 135, RIGHT_UP_DIRECTION = 45, RIGHT_DOWN_DIRECTION = 315, 
			  LEFT_DOWN_DIRECTION = 225};

	
	public: 
		//Initializes variables 
		Rendering(); 
	
		void Set_Camera();

		void Shader_Setter();


		int Character_State_Of_Animation();

		int Character_State_Of_Condition_Animation();
		//Configs the frame variables base. 1/2 of Character_State function responsiblity. 
		void Frame_Definer(Uint32 deltaTicks);
		
		// Sets the range of frames to use for a special action. 
		void Frame_Range_On_Screen();

		// Uses info from the object to determine what frame should be played
		void Frame_State_On_Screen(Soul *Spirit[]);
		void Frame_Handle_On_Screen( Soul *Spirit[], int condition);

		//Defines variables of the render class to avoid calling virtual functions for information.
		void Optimization_Variable_Definer( Soul *Spirit[] );

		//Where all the layering and rendering is done
		void Layering( Soul *Spirit[] );


		//void Layering_Menu(Menu &data );
		//Manages slave used as a separate function from layering
		void Slave_Management(Soul *Spirit[]);
	
			// Takes Game auto configuration as an argument. 
		void Variable_Update_Inactive(External_Configuration config);
		
		
		void Variable_Update_Active( Soul *Spirit[] );
		void Variable_Definer_Game_Start(External_Configuration config);
		void Show_Screen_Objects();
		
		void Sky_Line_View(Soul *Spirit[]);
		void Shadowed(Soul *Spirit[]);
		void Drop_Shadow(Soul *Spirit[]);
		bool Transparented(Soul *Spirit[], int condition);
		void Text_Speak( Soul *Spirit[]);
		void Free_Slave( Soul *Spirit[]);

		//
		////
		/////////
		////////////////
		///RENDER FRAME CONDITIONING FUNCTIONS //////////////
		////////////////
		/////////
		////
		//

		bool Find_Avaialble_Slave( Soul *Spirit[]);
		

		bool Slave_Object_Text_Speak_Calculation_MENU_BUTTON_TEXT( Soul *Spirit[]);
		void Slave_Object_Free_Calculation_MENU_BUTTON_TEXT( Soul *Spirit[]);

		
		void Screen_Object_Condition_Check_HEALTH_BAR(Soul *Spirit[]);


 }; 




 #endif 