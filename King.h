#ifndef KING_H_INCLUDED
#define KING_H_INCLUDED

#include "Global.h"
 class King
 { 
	private: 
	
		Square character_base;
		Square character_cornice;
		float x_coord, y_coord, z_coord;
		int character_state_of_being;
		int character_collision_sides, character_collision_fronts, character_collision_tops; 
	public: 

		King();
		//int type only
		void character_variable_definer(int CS0B, float X, float Y, float Z, int CCS, int CCF, int CCT,  Square CB, Square CC);


		// Giving
		int get_character_int(int returner);
		float get_character_float(int returner);
		Square get_character_base();
		Square get_character_square();
 };
 #endif