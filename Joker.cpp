#include "Joker.h"

Joker::Joker()
{
	x_coord = 0;
	y_coord = 0;
	z_coord = 0;
	
	character_state_of_being = 0;
	character_collision_sides = 0; 
	character_collision_fronts = 0; 
	character_collision_tops = 0;
	/*
	character_base.x = x_coord;
	character_base.y = y_coord;
	character_base.r = z_coord;

	character_cornice.x;*/
}

void Joker::Character_variable_definer(Character &data)
{
	character_state_of_being = data.Get_Character_state_of_being();
	
	character_collision_sides = data.Get_Character_Collision(0);
	character_collision_tops =  data.Get_Character_Collision(1);
	character_collision_fronts = data.Get_Character_Collision(2);

	x_coord = data.Get_Character_Coord(0);
	y_coord = data.Get_Character_Coord(1);
	z_coord = data.Get_Character_Coord(2);

	character_base = data.Get_Character_Base();
	character_cornice = data.Get_Character();

	

}


void Joker::King_Character_variable_giving(King &data)
{
	//Character data definition
	data.character_variable_definer(character_state_of_being, x_coord, y_coord, z_coord, character_collision_sides, character_collision_tops, character_collision_fronts, character_base, character_cornice);
}
