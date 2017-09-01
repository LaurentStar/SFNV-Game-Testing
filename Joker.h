#ifndef JOKER_H_INCLUDED
#define JOKER_H_INCLUDED
//#include "Character.h"

 class Joker
 { 
	 //The king is not the joker's friend. Joker accesses nothing!
	friend class King; 
	
	private: 
	/*	ALL DATA CURRENTLY NEEDED FROM THE CHARACTER CLASS.
		*Character_state
		* X Y Z Coords
	*/
		float x_coord, y_coord, z_coord;
		int character_state_of_being;
		int character_collision_sides, character_collision_fronts, character_collision_tops;
		Square character_base;
		Square character_cornice;


	public: 
	
		Joker();

		//Defining
	//	void Character_variable_definer(Character &data);
		

		//Giving to the king
	//	void King_Character_variable_giving(King &data);
 };
 #endif