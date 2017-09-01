#ifndef PHYSICS_H_INCLUDED
#define PHYSICS_H_INCLUDED
//#include "King.h"
//#include "Soul.h"
#include "External_Configuration.h" 

 class Physics
 { 
	private: 
		//The Character's coordinates on map. Retrieved from a function
		float Character_X, Character_Y, Character_Z; 

		// The Character, Enemy, NCP ....ect state of being. 
		int State_Of_Being; 

		int Object_Type;


		// Variables that influence objects
		float Degree_Base, Degree_Cornice, Force_Base, Force_Cornice;

		//The strenght of the movement
		float Magnitude;

		// Sin is the y axis, cos is the x axis. Together they make the slope, but it all depend on the degree
		float Sin, Cos, Z_Axis; //Z_sin is the z axis manipulation. Sin is y and z act like y but it can't use sin with is why it uses Z_sin 

		//Shape and type are used by friction to apply effects to sufaces.
		int Shape, Type;

		// A restirctive force that stop or slows the character. All objects have this
		float Friction;


		

		enum { X, Y, Z};

		
	public: 
		//Initializes variables 
		Physics(); 
		
		//Used to update variables of objects.
		void Game_Physics_Object_Update(Soul *Spirits[], Uint32 deltaTicks);

		// Uses state of being to hanlde physics.
		void Game_Physics(Soul *Spirits[], Uint32 deltaTicks);
		
		
		/*
		This code returns the state of being for an object. Collisions however are fixed inside the functions manually. 
		Collisions are not states of being. Determine  a fine line. 
		*/
		void Square_State_Of_Being_Calculation(Soul *Spirits[], int element_check, Uint32 deltaTicks);

		int Get_State_Of_Being();
		float Get_Slope_Projectory(int returner);

	
		
 }; 

 #endif // PHYSICS_H_INCLUDED