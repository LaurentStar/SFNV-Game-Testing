#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED
/*
#include "Character.h"

 class Enemy_Object
 { 
	private:
		Square  Enemy_Base, Enemy_Cornice ;
		Circle Existance_Bubble; 
		
		int Type;
		
		

		float X_Coord, Y_Coord, Z_Coord; //RED!
		
		float Friction, Degree, Magnitude, X_Vel, Y_Vel, Z_Vel, Slope;
		int Base, Object_Elevation;
		int Enemy_Height, Enemy_Lenght, Enemy_Width;


		// Enemy will respawn after a certain time after death. 
		float Respawn_Timer;
		bool Dead, Respawn, Damaged, Healed; 
		int Enemy_Health;

		//Every enemy will have the same states of being with a few exception however they will not act completely the 
		//same

		int Enemy_State_Of_Being, Enemy_Basic_Action, Enemy_Action, Enemy_Mood;
		

		// Detrimine how long an enemy wait to do stuff
		float Enemy_Action_Timer, Enemy_Decider_Timer;
		int Enemy_Action_Randomize;
		int Enemy_Action_Phase;

		// Detrimine when the enemy is finished with action
		bool Action_Complete;
		bool Start_Action;
		enum { GRAVITY = 300};
	protected:


	public:
		Enemy_Object();

		Enemy_Object( int x, int y, int z, int enemy_type );


	//Depending on the enemy type detrimine traits about the enemy including collision boxes
	void Enemy_Type_Assigner(int type);

	void Enemy_Stats_General();

	// If the player come close enough, refresh the variables and calculate in real time
	void Enemy_Detection_Variable_Refresh(Physics p_data, Game_Auto_Configuration C, Environment_Objects *object[], Environment_Objects *ground_object[], Uint32 deltaTicks);
	
	void Enemy_Movement_Active(Uint32 deltaTicks);
	
//	void Enemy_Basic_Actions(Character data);
	
	// How the enemy act
	void Enemy_Behavior_Controller(Character data, Uint32 deltaTicks);

	void Enemy_Behavior_Chrome_Cyrstal_Trigger(); // Enemy decides what to do
	void Enemy_Behavior_Chrome_Cyrstal(Uint32 deltaTicks, Character data); // Performing an action

	Square Get_Enemy_Cornice();
	Square Get_Enemy_Base();

	void Show_Enemy();
	void Show_Enemy_Base();
 }; 
 */

 #endif 