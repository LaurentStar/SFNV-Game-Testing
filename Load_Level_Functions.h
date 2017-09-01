#ifndef LEVEL_LOAD_FUNCTION_H_INCLUDED
#define LEVEL_LOAD_FUNCTION_H_INCLUDED
#include "External_Configuration.h" 


// Pick the level to load
bool Pick_Level(Soul *Spirit[], External_Configuration &config, int level);

//Calls other functions to help it load level_1A
bool Load_Level_LEVEL_1_A( Soul *Spirit[], External_Configuration &config, int load_source);
int Load_Level_Lv1A_Floor(int Start_Num, Soul *Spirit[],External_Configuration &config, int load_source);
int Load_Level_Lv1A_Float(int Start_Num, Soul *Spirit[],External_Configuration &config, int load_source);
int Load_Level_Lv1A_Config(int Start_Num, Soul *Spirit[],External_Configuration &config, int load_source);


bool Load_Level_LEVEL_1_B( Soul *Spirit[], External_Configuration &config,int load_source );
int Load_Level_Lv1B_Floor(int Start_Num, Soul *Spirit[],External_Configuration &config, int load_source);
int Load_Level_Lv1B_Float(int Start_Num, Soul *Spirit[],External_Configuration &config, int load_source);
int Load_Level_Lv1B_Config(int Start_Num, Soul *Spirit[],External_Configuration &config, int load_source);

int Load_Level_Smart_AI(int Start_Num, Soul *Spirit[],External_Configuration &config, int load_source);
#endif // CHARACTER_H_INCLUDED