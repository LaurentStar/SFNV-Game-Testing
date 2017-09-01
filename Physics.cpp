#include "Function.h"


Physics::Physics()
{	
	//The character's coordinates. All int type
	Character_X = 0;
	Character_Y = 0;
	Character_Z = 0;
	 

	State_Of_Being = 0;
	
	Object_Type = 0;



	Degree_Base = 0;
	Degree_Cornice = 0;

	Magnitude = 0;

	
	Sin = 0;
	Cos = 0;
	Z_Axis = 0;

	Friction = 0;
	
	
}


void Physics::Game_Physics_Object_Update(Soul *Spirits[], Uint32 deltaTicks)
{

	for (int a = 0; a < MAX_GAME_OBJECTS ; a++ )
	{
		if(Spirits[a] != NULL)
		{			
			if(Spirits[a]->Get_Object_Type() !=  FLOOR)
			{
				if(Spirits[a]->Get_Gravity_Physics() !=  STATIC_G)
				{
					if(Spirits[a]->Get_Alive_Key() != false)
					{
					
						Spirits[a]->Variable_Update( deltaTicks);
					}
				}
			}
		//	else {break;}	
		}
	}

}
void Physics::Game_Physics(Soul *Spirits[], Uint32 deltaTicks)
{	
	for (int a = 0; a < MAX_GAME_OBJECTS ; a++ )
	{
		if(Spirits[a] != NULL)
		{

			if(Spirits[a]->Get_Object_Type() !=  FLOOR)
			{
				if(Spirits[a]->Get_Alive_Key() !=  false)
				{
					if(Spirits[a]->Get_Gravity_Physics() !=  STATIC_G)
					{
					
						//Spirits[a]->Variable_Update( deltaTicks);
						Square_State_Of_Being_Calculation(Spirits, a, deltaTicks);
					
					Spirits[a]->Soul_Physics(State_Of_Being, deltaTicks); 
						
						
					

					if(Spirits[a]->Get_Object_Type() ==   Selected_Character)
					{
						Spirits[a]->Soul_Input();
					}
					if(Spirits[a]->Get_Object_Type() == AI_SMART)
					{
						Spirits[a]->Soul_Input();
					}
					if(Spirits[a]->Get_Object_Type() ==  ON_SCREEN)
					{
						
						Spirits[a]->Soul_Input();
					}
					//Determine the objects state of being and finally call the Physic function at the end.
					//Dynamic objects can still interact with static objects but not vice versa. 

					}
				}
			}
		}
		else {break;}	
	}
}

void Physics::Square_State_Of_Being_Calculation(Soul *Spirits[], int element_check, Uint32 deltaTicks )
{

	Square Objects, Objects_Base, Sc,Sb; 
	bool Skip_Collision_Check = false;

	//The sides of the rectangle being checked
	int Objects_Left, Objects_Right, Objects_Top, Objects_Bottom, Objects_Front_Cliff;
	int Objects_Base_Left, Objects_Base_Right, Objects_Base_Top, Objects_Base_Bottom,  Objects_Base_Ground_Point;

	//The sides of the rectangles 
	int Sc_Left, Sc_Right, Sc_Top, Sc_Bottom, Sc_Front_Cliff, Sc_Back_Cliff, Sc_Height ;
	int Sb_Left, Sb_Right, Sb_Top, Sb_Bottom, Sb_Ground_Point;

	//Accuracy leveler. 
	int Upper_Starting_Point_One, Upper_Starting_Point_Two;
	int Bottom_Starting_Point_One, Bottom_Starting_Point_Two ;
		
	//Object tracking
	int Track_A, Track_B;
	
	
	
	
	int Starting_Point_One;
	int Starting_Point_Two;


	//Linking to Prime Object
	Objects = Spirits[element_check]->Get_Objects();
	Objects_Base = Spirits[element_check]->Get_Objects_Base(); 
	
	//Linking to Alpha object... VOID values
	Sc = Spirits[element_check]->Get_Objects();
	Sb = Spirits[element_check]->Get_Objects();
	
	//Object Prime real values
	Objects_Left = Objects.x;
	Objects_Right = Objects.x + Objects.w;
	Objects_Top = Objects.y;
	Objects_Bottom = Objects.y + Objects.h;
	Objects_Front_Cliff = Objects.front_cliff;

	Objects_Base_Left = Objects_Base.x;
	Objects_Base_Right = Objects_Base.x + Objects_Base.w;
	Objects_Base_Top = Objects_Base.y;
	Objects_Base_Bottom = Objects_Base.y + Objects_Base.h;
	Objects_Base_Ground_Point = Objects_Base.front_cliff;

	//Object Alpha Void values
	Sc_Left = 0; 
	Sc_Right = 0; 
	Sc_Top = 0; 
	Sc_Bottom = 0; 
	Sc_Front_Cliff = 0;
	Sc_Front_Cliff = 0;
	Sc_Back_Cliff = 0;
	Sc_Height = 0;

	Sb_Left = 0; 
	Sb_Right = 0; 
	Sb_Top = 0; 
	Sb_Bottom = 0; 
	Sb_Ground_Point = 0;


	//This is used on the cornice
	Upper_Starting_Point_One = 0;
	Upper_Starting_Point_Two = 0;
	Bottom_Starting_Point_One =  0;
	Bottom_Starting_Point_Two =  0;

	// Square on Square object tracking
	Track_A = 0;
	Track_B = 0;

	//This is used of the base of a square
	Starting_Point_One = 0;
	Starting_Point_Two = 0;

	for (int a = 0; a < MAX_GAME_OBJECTS ; a++ )
	{	
		if(Spirits[a] != NULL)
		{	
			if (Spirits[a]->Get_Object_Type() ==   CYRON_TANRYOKU)	
			{
				Skip_Collision_Check = true;
			}
			if (Spirits[a]->Get_Object_Type() ==  CXX120)	
			{
				Skip_Collision_Check = true;
			}
			if (Spirits[a]->Get_Object_Type() ==  THE_YS_GUY)	
			{
				Skip_Collision_Check = true;
			}
			if(Skip_Collision_Check == false)
			{
				if(Spirits[a]->Get_Object_Type() !=  FLOOR)
				{
			
					if (a != element_check )
					{
						
						//Update the compared object if it suppose to move. 
						//if(Spirits[a]->Get_Gravity_Physics() !=  STATIC_G)
					//	{
						//	Spirits[a]->Variable_Update( deltaTicks);		
						//}
					
					
						//Real Defintion
						Sc = Spirits[a]->Get_Objects();
						Sb = Spirits[a]->Get_Objects_Base();
					

						// Updating declared values
						Sc_Left = Sc.x; 
						Sc_Right = Sc.x + Sc.w; 
						Sc_Top = Sc.y; 
						Sc_Bottom = Sc.y + Sc.h + Sc.front_cliff; 
						Sc_Front_Cliff = Sc.y + Sc.front_cliff;
						Sc_Back_Cliff = Sc.y + Sc.h;
						Sc_Height = (Sc_Bottom - Sc_Front_Cliff)/*/2*/ ;

						Sb_Left = Sb.x; 
						Sb_Right = Sb.x + Sb.w; 
						Sb_Top = Sb.y; 
						Sb_Bottom = Sb.y + Sb.h; 
						Sb_Ground_Point = Sb.front_cliff;


						//Reference points.
						Upper_Starting_Point_One = Sc_Top -  Objects_Base.h;
						Upper_Starting_Point_Two = Sc_Front_Cliff  +  Objects_Base.h;
					
						Bottom_Starting_Point_One =  Sc_Back_Cliff - Objects_Base.h;
						Bottom_Starting_Point_Two =  Sc_Bottom + Objects_Base.h; 

						Starting_Point_One = Sb_Top - Objects_Base.h;
						Starting_Point_Two = Sb_Bottom + Objects_Base.h;
					
					
						//Character tracking
						Track_A =   Objects_Base_Ground_Point - Starting_Point_One;
						Track_B =   Starting_Point_Two -  Objects_Base_Ground_Point;


				


					

						//Touching the ground
						if (Objects_Bottom >= Objects_Base_Top)
						{
							State_Of_Being = GROUNDED;
 							//Spirits[element_check]->Soul_Physics(GROUNDED, deltaTicks);
	
							//All collsions related to the ground below
							if (State_Of_Being == GROUNDED)
							{
								//Nothing so far
							}
						}
					
						//////////////////////////////////////////////////////
						//Mid air
						//////////////////////////////////////////////////////

						if (Objects_Bottom < Objects_Base_Top -4)
						{
							State_Of_Being =  MIDAIR;
							//Spirits[element_check]->Soul_Physics(MIDAIR, deltaTicks);
							//All collsions related to being in midair
							if (State_Of_Being == MIDAIR)
							{
								//If the bases are touching
								if (Square_Object_Detection(Objects_Base, Sb )== true)
								{	

									////////////////////////////////////////////////////
									//FRONTS AND BEHIND CUBE
									////////////////////////////////////////////////////
  									if(( Objects_Top <= Sc_Bottom) && ( Objects_Bottom >= Sc_Front_Cliff )&&( Objects_Right >= Sc_Left ) && ( Objects_Left <= Sc_Right )&& (Track_B < Objects_Base.h) )
									{ 
									//	Spirits[element_check]->Soul_Physics(AGAINST_FRONT, deltaTicks);
									//	return AGAINST_FRONT; 
										State_Of_Being = AGAINST_FRONT;
										 break;
									} 

									if(( Objects_Top <= Sc_Back_Cliff) && ( Objects_Bottom >= Sc_Top ) && ( Objects_Right >= Sc_Left ) && ( Objects_Left <= Sc_Right )&& (Track_A < Objects_Base.h) )
									{ 
										//Spirits[element_check]->Soul_Physics(AGAINST_BACK, deltaTicks);	
										 State_Of_Being = AGAINST_BACK;
										 break;
									} 

									////////////////////////////////////////////////////
									//AGAINST THE SIDE OF SQUAE OBJECT
									////////////////////////////////////////////////////
									//if(( Objects_Bottom <= Upper_Starting_Point_Two - Track_B)&&(Objects_Top <= Upper_Starting_Point_Two  - Track_B ))
									if(( Objects_Bottom <= Bottom_Starting_Point_Two - Track_B   )&&(Objects_Top <= Bottom_Starting_Point_Two  - Track_B ))
									{	
										if ((Objects_Bottom >= Upper_Starting_Point_One + Track_A +  Objects.h/2) && ( Objects_Left <= Sc_Right - 2) && ( Objects_Left >= Sc_Left))
										{
											 State_Of_Being = AGAINST_RIGHT_SIDE;
											 break;
										}
										
										else if ((Objects_Bottom >= Upper_Starting_Point_One + Track_A +  Objects.h/2) &&( Objects_Right >= Sc_Left + 2) &&( Objects_Right <= Sc_Right ) )
										{
											 State_Of_Being = AGAINST_LEFT_SIDE;
											 break;
										}

										if ((Objects_Bottom >= Upper_Starting_Point_One + Track_A +  Objects.h/2) &&  ( Objects_Left <= Sc_Right - 1) && ( Objects_Right <= Sc_Right ))
										{
											//GOING_THROUGH_RIGHT_SIDE
											Spirits[element_check]->Soul_Physics(GOING_THROUGH_RIGHT_SIDE, deltaTicks);
											//break;
										 
										}
										
										if ((Objects_Bottom >= Upper_Starting_Point_One + Track_A +  Objects.h/2) &&  ( Objects_Right >= Sc_Left + 1) && ( Objects_Left >= Sc_Left ))
										{
											//return AGAINST_LEFT_SIDE
											Spirits[element_check]->Soul_Physics(GOING_THROUGH_LEFT_SIDE, deltaTicks);
										//	break;
										}
										
										////////////////////////////////////////////////////
										//ON_TOP, UNDER, AND INSIDE THE BLOCK
										////////////////////////////////////////////////////
										if ((Objects_Bottom >= Upper_Starting_Point_One + Track_A + Sc_Height /*14*/)  && ( Objects_Left <= Sc_Right) && ( Objects_Right >= Sc_Left))
										{
											//return INSIDE_BLOCK; 
											Spirits[element_check]->Soul_Physics(INSIDE_BLOCK, deltaTicks);
										}
									
										//This condition is too constant to be be activated once. 
										if ((Objects_Bottom >= Upper_Starting_Point_One + Track_A) && (Objects_Bottom <=  Upper_Starting_Point_Two - Track_B + 4) && ( Objects_Left <= Sc_Right) && ( Objects_Right >= Sc_Left ))
										{
											 State_Of_Being = STANDING_ON_TOP;
											 break;
											//Spirits[element_check]->Soul_Physics(STANDING_ON_TOP, deltaTicks);
										}

										if ((Objects_Bottom >= Upper_Starting_Point_One + Track_A + 5/*13*/)&&(Objects_Bottom <= Upper_Starting_Point_One + Track_B + 5 + (Sc_Height/2)/2) &&( Objects_Left <= Sc_Right - 3) && ( Objects_Right >= Sc_Left + 3 ))
										{
											//return FALLING_THROUGH_FLOOR1; 
											Spirits[element_check]->Soul_Physics(FALLING_THROUGH_FLOOR1, deltaTicks);
										}

										else if ((Objects_Bottom >= Upper_Starting_Point_One + Track_A + 5/*13*/)&&(Objects_Bottom <= Upper_Starting_Point_One + Track_B + 5 + Sc_Height/2) &&( Objects_Left <= Sc_Right - 3 ) && ( Objects_Right >= Sc_Left + 3 ))
										{
											//return FALLING_THROUGH_FLOOR2; 
											Spirits[element_check]->Soul_Physics(FALLING_THROUGH_FLOOR2, deltaTicks);
										}
										else if ((Objects_Bottom>= Upper_Starting_Point_One + Track_A + 5/*13*/)&&(Objects_Bottom <= Upper_Starting_Point_One + Track_B + 5 + Sc_Height) &&( Objects_Left <= Sc_Right - 3) && ( Objects_Right >= Sc_Left  + 3))
										{
											//return FALLING_THROUGH_FLOOR3; 
											Spirits[element_check]->Soul_Physics(FALLING_THROUGH_FLOOR3, deltaTicks);
										}

 
									} 

									//1ST. Part 2
									if(( Objects_Top >= Upper_Starting_Point_One + Track_A/* - Sc.h/2*/)&&(Objects_Bottom >=  Upper_Starting_Point_One + Track_A /*- Sc.h/2*/) )
									{	
										if ((Objects_Top <= Bottom_Starting_Point_One + Track_A) && ( Objects_Left <= Sc_Right) && ( Objects_Right >= Sc_Left)&& (Track_A > Objects_Base.h/2)&& (Track_B > Objects_Base.h/2)) 
										{		
											//return HIT_FROM_BELOW;
											Spirits[element_check]->Soul_Physics(HIT_FROM_BELOW, deltaTicks);
										}		
									} 


								


											
								/////////////////
								}
							}
						}			
					}
				}
			}
			else
			{
				Skip_Collision_Check = false;
			}
		}
	}
	 // May be upgraded later. Collision for circles yo be added later.                                                      
	 //return State_Of_Being; 

}

int Physics::Get_State_Of_Being()
{
	return State_Of_Being;
}
float Physics::Get_Slope_Projectory(int returner)
{
	enum {X, Y, Z};

	switch (returner)
	{
		case X:  return Cos; break;
		case Y:  return Sin; break;
		case Z:  return Z_Axis; break;
	}
	return -1; 
}







