#ifndef GAME_AUTO_CONFIGURATION_H_INCLUDED
#define GAME_AUTO_CONFIGURATION_H_INCLUDED
#include <string>
#include "Global.h"

class External_Configuration
{
	private:
		

		// The coordinate when we start the game. Defined in constructor for now...
		int Game_Start_X_Coord, Game_Start_Y_Coord, Game_Start_Z_Coord;
		std::string Level_Name;

		int Level_Width, Level_Lenght; 



		//Current Location data varaible. Does not effect permenate save files
		int Current_X_Coord, Current_Y_Coord, Current_Z_Coord;
		std::string Current_Level_Name;


	public:
		
		External_Configuration();


		bool Configurate_Level_Name();
		bool Configurate_Current_Level_Name();
		bool Configurate_Character_Coord();
		bool Configurate_Current_Character_Coord();
		bool Configurate_Level_Width_Lenght();
		bool Configurate_Current_Level_Width_Lenght();

		


		std::string Get_Level_Name();
		std::string Get_Current_Level_Name();
		int Get_Level_Width_Lenght(int returner);
		int Get_Current_Level_Width_Lenght(int returner);
		int Get_Coords(int returner);
		int Get_Current_Coords(int returner);
		
	
};
 #endif // PHYSICS_H_INCLUDED