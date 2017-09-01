#include "King.h"
	
King::King()
{
	character_base.x = 0;
	character_cornice.x = 0;
	x_coord = 0;
	y_coord = 0;
	z_coord = 0;
	character_state_of_being = 0;
	character_collision_sides = 0;
	character_collision_fronts = 0;
	character_collision_tops = 0;
}
void King::character_variable_definer(int CS0B, float X, float Y, float Z, int CCS, int CCF, int CCT,  Square CB, Square CC)
{
		character_state_of_being = CS0B;
		
		character_collision_sides = CCS;
		character_collision_fronts = CCF;
		character_collision_tops = CCT;

		x_coord = X;
		y_coord = Y; 
		z_coord = Z; 
	
		character_base = CB;
		character_cornice = CC;
}

int King::get_character_int(int returner)
{
	enum {CHARACTER_STATE, RETURN_SIDES, RETURN_TOPS, RETURN_FRONTS };

	switch (returner)
	{
		case CHARACTER_STATE: return character_state_of_being; break;
		case RETURN_SIDES: return character_collision_sides; break;
		case RETURN_TOPS: return character_collision_tops; break;
		case RETURN_FRONTS: return character_collision_tops; break;
	}
	return -1;
}


float King::get_character_float(int returner)
{
	enum { X, Y, Z};

	switch (returner)
	{
		case X: return x_coord; break;
		case Y: return y_coord; break;
		case Z: return z_coord; break;
	}
	return -1;
}

Square King::get_character_base()
{
	return character_base;
}

Square King::get_character_square()
{
	return character_cornice;
}