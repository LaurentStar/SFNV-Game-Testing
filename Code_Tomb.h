// This tomb of coding piece is the final resting place of redudant code. Eventually this code gets erased when confirm
// to be of absoltuely no value.



////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
/*//Layering for floating objects
int Rendering::Layering_Decider( Square character_base, Square character_cornice, Square square_base, Square square)
 {
	int Starting_Point_One,  Starting_Point_Two; 
	int Upper_Track, Bottom_Track;
		//The sides of the rectangles 
	int Square_Base_Left, Square_Base_Right, Square_Base_Top, Square_Base_Bottom;
	int Square_Left, Square_Right, Square_Top, Square_Bottom, Square_Front_Cliff, Square_Back_Cliff;

	//The character defined
	int Character_Cornice_Left, Character_Cornice_Right, Character_Cornice_Top, Character_Cornice_Bottom;
	
	//The Character's based
	int Character_Base_Left, Character_Base_Right, Character_Base_Top, Character_Base_Bottom, Character_Base_Point;
*/	
	/************************************************************
	//					DEFINING OF ALL VARIABLES			   //
	************************************************************/
	//Calculate the sides of rect A 
/*	Square_Base_Left = square_base.x; 
	Square_Base_Right = square_base.x + square_base.w; 
	Square_Base_Top = square_base.y; 
	Square_Base_Bottom = square_base.y + square_base.h; 


	//Calculate the sides of rect A 
	Square_Left = square.x; 
	Square_Right = square.x + square.w; 
	Square_Top = square.y; 
	Square_Bottom = square.y + square.h; 
	Square_Front_Cliff = square.y + square.front_cliff;
	Square_Back_Cliff =  square.y + square.h - square.front_cliff;

	//Calculate the side of the character's square
	Character_Cornice_Left = character_cornice.x;	
	Character_Cornice_Right = character_cornice.x + character_cornice.w;
	Character_Cornice_Top = character_cornice.y;
	Character_Cornice_Bottom = character_cornice.y + character_cornice.h;

	Character_Base_Left = character_base.x;
	Character_Base_Right = character_base.x + character_base.w;
	Character_Base_Top = character_base.y;
	Character_Base_Bottom = character_base.y + character_base.h;
	Character_Base_Point = character_base.front_cliff;

	Starting_Point_One = Square_Base_Top - CHARACTER_LENGHT;
	Starting_Point_Two = Square_Base_Bottom + CHARACTER_LENGHT;

	Upper_Track = Character_Base_Point - Square_Base_Top;
	Bottom_Track = Square_Base_Bottom - Character_Base_Point; 


	//If the player is in front of an object.
	if ((Character_Base_Top > Square_Base_Bottom - 5) && (Character_Base_Bottom > Square_Base_Top ))
	{
		return LAYER_ZERO;
	}
		
	
	

	if ((Character_Base_Top <= Square_Base_Bottom - 5) && (Character_Base_Bottom >= Square_Base_Top)) 
	{
			if ((Character_Base_Top <= Square_Base_Bottom - 5)&& (Character_Base_Point >= Square_Base_Bottom - 5))
			{
				return LAYER_ZERO;
			}
			if (Character_Cornice_Bottom <= Square_Top + Upper_Track)
			{
				return LAYER_ZERO;
			}
			
			if (Character_Cornice_Bottom >= Square_Top + Upper_Track + 7 )
			{
				return LAYER_ONE;
			}
		//
		
		/*if (Character_Cornice_Bottom >= Square_Bottom)
		{
			return LAYER_ONE;
		}
	}*/

	/*if ((Character_Base_Bottom >= Square_Base_Top - 4) && (Character_Base_Top >= Square_Base_Bottom - 4))  
	{
		if (Character_Cornice_Bottom >= Square_Front_Cliff)
		{
			return LAYER_ZERO;
		}
		
		if (Character_Cornice_Bottom <= Square_Back_Cliff)
		{
			return LAYER_ONE;
		}
	}

	//If the Player is behind an object
	if ((Character_Base_Bottom  < Square_Base_Top ) && (Character_Base_Top  < Square_Base_Top))
	{
		return LAYER_ONE;
	}
	return LAYER_ZERO;
 }*/


////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
/*void Character::Movement_Active(Uint32 deltaTicks)
{
	if(Game_Mode == GAMEPLAY_MODE)
	{
		if (Freeze_All_Actions == LEVEL_WRAP)
		{
			Magnitude = 0;
			Z_Vel = 0;
			Y_Vel = 0;
			X_Vel = 0;
		}
		if (Freeze_All_Actions == NOT_FROZEN)
		{
			switch (Character_State_Of_Being)
			{
				case GROUNDED:				Z_Vel = 0;  Z_Coord = Base - CHARACTER_HEIGHT; break;

				case GROUND_AGAINST_FRONT:			// Hard!!!!

										//	if (Z_Coord >= Base)
										//	{
										//		Z_Vel = 0;
										//		Z_Coord = Base - CHARACTER_HEIGHT;
										//	}
											if (Z_Coord +  CHARACTER_HEIGHT >= Base)
											{
												Z_Coord = Base - CHARACTER_HEIGHT;
											}
											//Z_Vel += GRAVITY * ( deltaTicks / 1000.f );
											//++Y_Coord;
											Y_Coord -= Y_Vel * ( deltaTicks / 1000.f ); 
											Z_Coord += Z_Vel * ( deltaTicks / 1000.f ); 
										
									
										
											break;

				case GROUND_AGAINST_BACK:			// Hard!!!!
											if (Z_Coord +  CHARACTER_HEIGHT >= Base)
											{
												//Z_Vel = 0;
												Z_Coord = Base - CHARACTER_HEIGHT;
												//Z_Vel -= Z_Vel/2;
											}

											//Z_Vel += GRAVITY * ( deltaTicks / 1000.f );
											//++Y_Coord;
											Y_Coord -= Y_Vel * ( deltaTicks / 1000.f ); 
											Z_Coord += Z_Vel * ( deltaTicks / 1000.f ); 
										
										
										
											break;

				case GROUND_INSIDE_FRONT:			// Hard!!!!
										
											Y_Coord -= Y_Vel * ( deltaTicks / 1000.f ); 
											++Y_Coord;
											Z_Coord = Base - CHARACTER_HEIGHT;
											++Z_Coord;
											break;
	
		
				case GROUND_INSIDE_BACK:			// Hard!!!!
											Y_Coord -= Y_Vel * ( deltaTicks / 1000.f ); 
											--Y_Coord;		
									 		if (Z_Coord + CHARACTER_HEIGHT >= Base)
											{
												Z_Coord = Base - CHARACTER_HEIGHT;
											}
											Z_Vel -= Z_Vel * ( deltaTicks / 1000.f ); 
											--Z_Coord;
											break;

											
											
											
				case MIDAIR:				Z_Vel += GRAVITY  * ( deltaTicks / 1000.f );
											Z_Vel  += Y_Vel * ( deltaTicks / 1000.f );  
											Z_Coord += Z_Vel  * ( deltaTicks / 1000.f );
										
											//Controlling the character's jump height....test
											if ((Space_Key == false)&&(Z_Vel < 0))
											{
												Z_Vel -= Z_Vel/20;
											}
											break;

				case FALLING_THROUGH_FLOOR1:	Z_Vel = 0;
												Z_Coord -= 2; 
												break;
				case FALLING_THROUGH_FLOOR2:	Z_Vel = 0;
												Z_Coord -= 5; 
												break;
				case FALLING_THROUGH_FLOOR3:	Z_Vel = 0;
												Z_Coord -= 7; 
												break;
				case STANDING_ON_TOP:		Z_Vel = Y_Vel;  Z_Coord += Z_Vel * ( deltaTicks / 1000.f ); break;
				case HIT_FROM_BELOW:		//Going down we do nothing
											if(Z_Vel > 0)
											{
												Z_Coord ++;
												Z_Coord += Z_Vel * ( deltaTicks / 1000.f ); 
												X_Coord -= X_Vel * ( deltaTicks / 1000.f ); 
											}

											// Going up we push down
											if(Z_Vel < 0)
											{
												Z_Coord += 3;
												Z_Vel = 0;
												Z_Vel += GRAVITY * ( deltaTicks / 1000.f ); 
												Z_Coord += Z_Vel * ( deltaTicks / 1000.f );
												X_Coord += X_Vel * ( deltaTicks / 1000.f );
											} break;
				case AGAINST_FRONT:			// Hard!!!!
											Z_Vel += GRAVITY * ( deltaTicks / 1000.f );
											++Y_Coord;
											Y_Coord -= Y_Vel* ( deltaTicks / 1000.f ); 
											Z_Coord += Z_Vel * ( deltaTicks / 1000.f ); break;
		
				case INSIDE_BACK:			// Hard!!!!
											Z_Vel += GRAVITY * ( deltaTicks / 1000.f );
											Y_Coord -= Y_Vel* ( deltaTicks / 1000.f ); 
											--Y_Coord;
										
											Z_Coord += Z_Vel * ( deltaTicks / 1000.f ); break;
											break;
				case INSIDE_FRONT:			// Hard!!!!
											Z_Vel += GRAVITY * ( deltaTicks / 1000.f );
											Y_Coord -= Y_Vel* ( deltaTicks / 1000.f ); 
											++Y_Coord;
										
											Z_Coord += Z_Vel * ( deltaTicks / 1000.f ); break;
											break;
		
				case AGAINST_BACK:			// Hard!!!!
											Z_Vel += GRAVITY * ( deltaTicks / 1000.f );
											//Z_Coord += Z_Vel * ( deltaTicks / 1000.f );
											Y_Coord -= Y_Vel * ( deltaTicks / 1000.f ); 
											Z_Coord += Z_Vel * ( deltaTicks / 1000.f ); break;
				case INSIDE_BLOCK:			
											Z_Vel += GRAVITY * ( deltaTicks / 1000.f ); break;
				case AGAINST_LEFT_SIDE:												
											Z_Vel += GRAVITY * ( deltaTicks / 1000.f );
											Z_Coord += Z_Vel * ( deltaTicks / 1000.f );
											++X_Coord;
											X_Coord -= X_Vel * ( deltaTicks / 1000.f ); break;
				case AGAINST_RIGHT_SIDE:	
											Z_Vel += GRAVITY * ( deltaTicks / 1000.f );
											--X_Coord;
											X_Coord -= X_Vel * ( deltaTicks / 1000.f ); break;
	
			}
		}
	
	}
}*/
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
/*void Character::Variable_Definer_Game_Start(Game_Auto_Configuration config)
{
	int X = 0, Y = 1, Z = 2; 

	X_Coord = config.Get_Coords(X);
	Y_Coord = config.Get_Coords(Y);
	Z_Coord = config.Get_Coords(Z);

	Character_Base.x = X_Coord;
	Character_Base.y = Y_Coord;
	Character_Base.w = CHARACTER_WIDTH;
	Character_Base.h = CHARACTER_LENGHT;

	Character_Cornice.x = X_Coord;
	Character_Cornice.y = Z_Coord;
	Character_Cornice.w = CHARACTER_WIDTH ;
	Character_Cornice.h = CHARACTER_HEIGHT ;

	Transparent_Barricade.x = X_Coord - CHARACTER_WIDTH;
	Transparent_Barricade.y = Z_Coord - CHARACTER_HEIGHT;
	Transparent_Barricade.w = CHARACTER_WIDTH * 3;
	Transparent_Barricade.h = CHARACTER_HEIGHT * 3;
}*/



////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
/*
void Character::Movement()
{
	if(Game_Mode == GAMEPLAY_MODE)
	{
			if (Freeze_All_Actions == LEVEL_WRAP)
			{
				Magnitude = 0;
				X_Vel = 0;
				Y_Vel = 0;
				Z_Vel = 0;
			}
			if (Freeze_All_Actions == NOT_FROZEN)
			{
				if (Character_Animation_Exception ==  -1)
				{
					switch (Button)
					{// Mag was 2.0 
						case NO_KEY: Magnitude -= 5.0; X_Vel = cos(Degree * DEG) * Magnitude;
										Y_Vel = -sin(Degree * DEG) * Magnitude; 
										if(Magnitude < 0) {Magnitude = 0; X_Vel = 0; Y_Vel = 0;} 
							break;
						case UP: Degree = 90.0; Magnitude = 50;  
									X_Vel = cos(Degree * DEG) * Magnitude;
									Y_Vel = -sin(Degree * DEG) * Magnitude; 
									//if (X_Vel >= (cos(Degree * DEG) * Magnitude)){X_Vel = cos(Degree * DEG) * Magnitude;}
									//if (Y_Vel <= (-sin(Degree * DEG) * Magnitude)){Y_Vel = -sin(Degree * DEG) * Magnitude;}
						 
							break;
						case UP_LEFT: Degree = 135.0; Magnitude = 50; 
									X_Vel = cos(Degree * DEG) * Magnitude; 
									Y_Vel = -sin(Degree * DEG) * Magnitude;		

							break;
						case UP_RIGHT: Degree = 45.0; Magnitude = 50; 
									X_Vel = cos(Degree * DEG) * Magnitude; 
									Y_Vel = -sin(Degree * DEG) * Magnitude;				
							break;
						case UP_DOWN: Magnitude -= Friction; if (Magnitude < 0) {Magnitude = 0;} X_Vel += 0; Y_Vel = 0; 
							break;
						case UP_SPACE: Degree = 90.0; Magnitude = 50;  
									X_Vel = cos(Degree * DEG) * Magnitude;
									Y_Vel = -sin(Degree * DEG) * Magnitude; 
									switch (Character_State_Of_Being) 
									{
										case GROUNDED:	Z_Coord -= 10; Z_Vel -= 100; break;
										case STANDING_ON_TOP: Z_Coord -= 10; Z_Vel -= 50; break;
									}
							break;
						case UP_RIGHT_SPACE: Degree = 45.0; Magnitude = 50;  
										X_Vel = cos(Degree * DEG) * Magnitude;
										Y_Vel = -sin(Degree * DEG) * Magnitude; 
										switch (Character_State_Of_Being) 
										{
											case GROUNDED:	Z_Coord -= 10; Z_Vel -= 500; break;
											case STANDING_ON_TOP: Z_Coord -= 10; Z_Vel -= 100; break;
										}
							break;
						case UP_LEFT_SPACE: Degree = 135.0; Magnitude = 50;  
										X_Vel = cos(Degree * DEG) * Magnitude;
										Y_Vel = -sin(Degree * DEG) * Magnitude; 
										switch (Character_State_Of_Being) 
										{
											case GROUNDED:	Z_Coord -= 10; Z_Vel -= 500; break;
											case STANDING_ON_TOP: Z_Coord -= 10; Z_Vel -= 100; break;
										}
							break;
						case DOWN: Degree = 270.0; Magnitude = 50;  
									X_Vel = cos(Degree * DEG) * Magnitude;
									Y_Vel = -sin(Degree * DEG) * Magnitude; 	
							break;
						case DOWN_LEFT: Degree = 225.0; Magnitude = 50;  
									X_Vel = cos(Degree * DEG) * Magnitude;
									Y_Vel = -sin(Degree * DEG) * Magnitude;
							break;
						case DOWN_RIGHT: Degree = 315.0; Magnitude = 50;  
									X_Vel = cos(Degree * DEG) * Magnitude;
									Y_Vel = -sin(Degree * DEG) * Magnitude;
							break;
						case DOWN_SPACE: Degree = 270.0; Magnitude = 50;  
									X_Vel = cos(Degree * DEG) * Magnitude;
									Y_Vel = -sin(Degree * DEG) * Magnitude; 
									switch (Character_State_Of_Being) 
									{
										case GROUNDED:	Z_Coord -= 10; Z_Vel -= 100; break;
										case STANDING_ON_TOP: Z_Coord -= 10; Z_Vel -= 100; break;
									}
							break;
						case DOWN_RIGHT_SPACE: Degree = 315.0; Magnitude = 50;  
										X_Vel = cos(Degree * DEG) * Magnitude;
										Y_Vel = -sin(Degree * DEG) * Magnitude; 
										switch (Character_State_Of_Being) 
										{
											case GROUNDED:	Z_Coord -= 10; Z_Vel -= 500; break;
											case STANDING_ON_TOP: Z_Coord -= 10; Z_Vel -= 100; break;
										}
							break;
						case DOWN_LEFT_SPACE: Degree = 225.0; Magnitude = 50;  
										X_Vel = cos(Degree * DEG) * Magnitude;
										Y_Vel = -sin(Degree * DEG) * Magnitude; 
										switch (Character_State_Of_Being) 
										{
											case GROUNDED:	Z_Coord -= 10; Z_Vel -= 500; break;
											case STANDING_ON_TOP: Z_Coord -= 10; Z_Vel -= 100; break;
										}
							break;
						case LEFT: Degree = 180.0; Magnitude = 50;  
									X_Vel = cos(Degree * DEG) * Magnitude;
									Y_Vel = -sin(Degree * DEG) * Magnitude; 
							break;
						case LEFT_RIGHT: Magnitude -= Friction; if (Magnitude < 0) {Magnitude = 0;} X_Vel += 0; Y_Vel = 0; 
							break;
						case  LEFT_SPACE: Degree = 180.0; Magnitude = 50;  
									X_Vel = cos(Degree * DEG) * Magnitude;
									Y_Vel = -sin(Degree * DEG) * Magnitude; 
									switch (Character_State_Of_Being) 
									{
										case GROUNDED:	Z_Coord -= 10; Z_Vel -= 70; break;
										case STANDING_ON_TOP: Z_Coord -= 10; Z_Vel -= 100; break;
									}
							break;
						case RIGHT: Degree = 0.0; Magnitude = 50;  
									X_Vel = cos(Degree * DEG) * Magnitude;
									Y_Vel = -sin(Degree * DEG) * Magnitude; 
							break;
						case RIGHT_SPACE: Degree = 0; Magnitude = 50;  
									X_Vel = cos(Degree * DEG) * Magnitude;
									Y_Vel = -sin(Degree * DEG) * Magnitude; 
									switch (Character_State_Of_Being) 
									{
										case GROUNDED:	Z_Coord -= 10; Z_Vel -= 70; break;
										case STANDING_ON_TOP: Z_Coord -= 10; Z_Vel -= 100; break;
									}
							break;
						case SPACE:  switch (Character_State_Of_Being) 
									{
										case GROUNDED:	Z_Coord -= 10; Z_Vel -= 880; 
										break;
										case STANDING_ON_TOP: Z_Coord -= 10; Z_Vel -= 100; break;
									}
							break;
				\
						case HARD_UP: Degree = 90.0; Magnitude = 300;  
									X_Vel = cos(Degree * DEG) * Magnitude;
									Y_Vel = -sin(Degree * DEG) * Magnitude; 
							break;
						case HARD_UP_LEFT: Degree = 135.0; Magnitude = 300; 
									X_Vel = cos(Degree * DEG) * Magnitude; 
									Y_Vel = -sin(Degree * DEG) * Magnitude;					
							break;
						case HARD_UP_RIGHT: Degree = 45.0; Magnitude = 300; 
									X_Vel = cos(Degree * DEG) * Magnitude; 
									Y_Vel = -sin(Degree * DEG) * Magnitude;				
							break;
						case HARD_UP_DOWN: Magnitude -= Friction; if (Magnitude < 0) {Magnitude = 0;} X_Vel += 0; Y_Vel = 0; 
							break;
						case HARD_UP_SPACE: Degree = 90.0; Magnitude = 300;  
									X_Vel = cos(Degree * DEG) * Magnitude;
									Y_Vel = -sin(Degree * DEG) * Magnitude; 
									switch (Character_State_Of_Being) 
									{
										case GROUNDED:	Z_Coord -= 10; Z_Vel -= 100; break;
										case STANDING_ON_TOP: Z_Coord -= 10; Z_Vel -= 50; break;
									}
							break;
						case HARD_UP_RIGHT_SPACE: Degree = 45.0; Magnitude = 300;  
										X_Vel = cos(Degree * DEG) * Magnitude;
										Y_Vel = -sin(Degree * DEG) * Magnitude; 
										switch (Character_State_Of_Being) 
										{
											case GROUNDED:	Z_Coord -= 10; Z_Vel -= 500; break;
											case STANDING_ON_TOP: Z_Coord -= 10; Z_Vel -= 100; break;
										}
							break;
						case HARD_UP_LEFT_SPACE: Degree = 135.0; Magnitude = 300;  
										X_Vel = cos(Degree * DEG) * Magnitude;
										Y_Vel = -sin(Degree * DEG) * Magnitude; 
										switch (Character_State_Of_Being) 
										{
											case GROUNDED:	Z_Coord -= 10; Z_Vel -= 500; break;
											case STANDING_ON_TOP: Z_Coord -= 10; Z_Vel -= 100; break;
										}
							break;
						case HARD_DOWN: Degree = 270.0; Magnitude = 300;  
									X_Vel = cos(Degree * DEG) * Magnitude;
									Y_Vel = -sin(Degree * DEG) * Magnitude; 		
							break;
						case HARD_DOWN_LEFT: Degree = 225.0; Magnitude = 300;  
									X_Vel = cos(Degree * DEG) * Magnitude;
									Y_Vel = -sin(Degree * DEG) * Magnitude;
							break;
						case HARD_DOWN_RIGHT: Degree = 315.0; Magnitude = 300;  
									X_Vel = cos(Degree * DEG) * Magnitude;
									Y_Vel = -sin(Degree * DEG) * Magnitude;
							break;
						case HARD_DOWN_SPACE: Degree = 270.0; Magnitude = 300;  
									X_Vel = cos(Degree * DEG) * Magnitude;
									Y_Vel = -sin(Degree * DEG) * Magnitude; 
									switch (Character_State_Of_Being) 
									{
										case GROUNDED:	Z_Coord -= 10; Z_Vel -= 300; break;
										case STANDING_ON_TOP: Z_Coord -= 10; Z_Vel -= 100; break;
									}
							break;
						case HARD_DOWN_RIGHT_SPACE: Degree = 315.0; Magnitude = 300;  
										X_Vel = cos(Degree * DEG) * Magnitude;
										Y_Vel = -sin(Degree * DEG) * Magnitude; 
										switch (Character_State_Of_Being) 
										{
											case GROUNDED:	Z_Coord -= 10; Z_Vel -= 500; break;
											case STANDING_ON_TOP: Z_Coord -= 10; Z_Vel -= 100; break;
										}
							break;
						case HARD_DOWN_LEFT_SPACE: Degree = 225.0; Magnitude = 300;  
										X_Vel = cos(Degree * DEG) * Magnitude;
										Y_Vel = -sin(Degree * DEG) * Magnitude; 
										switch (Character_State_Of_Being) 
										{
											case GROUNDED:	Z_Coord -= 10; Z_Vel -= 500; break;
											case STANDING_ON_TOP: Z_Coord -= 10; Z_Vel -= 100; break;
										}
							break;
						case HARD_LEFT: Degree = 180.0; Magnitude = 300;  
									X_Vel = cos(Degree * DEG) * Magnitude;
									Y_Vel = -sin(Degree * DEG) * Magnitude; 
							break;
						case HARD_LEFT_RIGHT: Magnitude -= Friction; if (Magnitude < 0) {Magnitude = 0;} X_Vel += 0; Y_Vel = 0; 
							break;
						case  HARD_LEFT_SPACE: Degree = 180.0; Magnitude = 300;  
									X_Vel = cos(Degree * DEG) * Magnitude;
									Y_Vel = -sin(Degree * DEG) * Magnitude; 
									switch (Character_State_Of_Being) 
									{
										case GROUNDED:	Z_Coord -= 10; Z_Vel -= 100; break;
										case STANDING_ON_TOP: Z_Coord -= 10; Z_Vel -= 100; break;
									}
							break;
						case HARD_RIGHT: Degree = 0.0; Magnitude = 300;  
									X_Vel = cos(Degree * DEG) * Magnitude;
									Y_Vel = -sin(Degree * DEG) * Magnitude; 
							break;
						case HARD_RIGHT_SPACE: Degree = 0; Magnitude = 300;  
									X_Vel = cos(Degree * DEG) * Magnitude;
									Y_Vel = -sin(Degree * DEG) * Magnitude; 
									switch (Character_State_Of_Being) 
									{
										case GROUNDED:	Z_Coord -= 10; Z_Vel -= 70; break;
										case STANDING_ON_TOP: Z_Coord -= 10; Z_Vel -= 100; break;
									}
							break;
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///Z X C///////////////////////////////////////////////////////////////
// THESE ARE VERY COMPLEX CONTROLS FOR FIGHTING ENEMIES AND OTHER ACTIONS. 
// MAY BE SEPARATED LATER INTO NEW FUNCTION IF COMPLEXITY INCREASES TOO MUCH
						
						case Z: Z_Vel -= Z_Vel; Z_Vel -= 3;	break;

						case X: Z_Vel -= Z_Vel; Z_Vel -= 3;	break;

						case C: Z_Vel -= Z_Vel; Z_Vel -= 3;	break;
					}
				}
			}
	
	
			if ((Degree >= 0) || (Degree <= 360))
			{
				Y_Vel = Y_Vel * -1;
		
				//X_Vel = X_Vel * -1;
		
	
			}
	}
}
*/

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
/*
 //Layering for ground objects
int Rendering::Layering_Decider_Two( Square character_base, Square character_cornice, Square square)
{		
	//The sides of the rectangles 
	int Square_Left, Square_Right, Square_Top, Square_Bottom, Square_Front_Cliff, Square_Back_Cliff;

	//The character defined
	int Character_Cornice_Left, Character_Cornice_Right, Character_Cornice_Top, Character_Cornice_Bottom;
	
	//The Character's based
	int Character_Base_Left, Character_Base_Right, Character_Base_Top, Character_Base_Bottom, Character_Base_Point;
	

	//Calculate the sides of rect A 
	Square_Left = square.x; 
	Square_Right = square.x + square.w; 
	Square_Top = square.y; 
	Square_Bottom = square.y + square.h; 
	Square_Front_Cliff = square.y + square.front_cliff;
	Square_Back_Cliff =  square.y + square.h - square.front_cliff;

	//Calculate the side of the character's square
	Character_Cornice_Left = character_cornice.x;	
	Character_Cornice_Right = character_cornice.x + character_cornice.w;
	Character_Cornice_Top = character_cornice.y;
	Character_Cornice_Bottom = character_cornice.y + character_cornice.h;

	Character_Base_Left = character_base.x;
	Character_Base_Right = character_base.x + character_base.w;
	Character_Base_Top = character_base.y;
	Character_Base_Bottom = character_base.y + character_base.h;
	Character_Base_Point = character_base.front_cliff;


	//If the player is in front of an object.
	if (Character_Base_Point <= Square_Top + 1 ) 
	{
		return LAYER_ONE;
	}
		

	//If the Player is behind an object
	if (Character_Base_Point >= Square_Top ) 
	{
		return LAYER_ZERO;
	}


	return LAYER_ZERO;
 }
 */


////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

/*
int Rendering::Layering_Decider_Pixel_Scan(Square square_base)
{
	int Square_Base_Left, Square_Base_Right, Square_Base_Top, Square_Base_Bottom;
	
	//Calculate the sides of rect A 
	Square_Base_Left = square_base.x; 
	Square_Base_Right = square_base.x + square_base.w; 
	Square_Base_Top = square_base.y; 
	Square_Base_Bottom = square_base.y + square_base.h; 

	return Square_Base_Top;
}*/


////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

/*int Collision_Detection_Shadow( Square Base, Square Cornice, Environment_Objects *object[],Environment_Objects *ground_object[], int returner)
{
	if (returner == 0)
	{
		// Shadow effect on character loop. 
		for (int i = 0; i < MAX_GROUND_OBJECTS; i++)
		{
		
			if (object[i] != NULL) // The array will always be 200 but not everything gets used. the remainder are pointed to null.
			{		
				if (Shadow_Enable(Base, Cornice, object[i]->Get_Floating_Square_Objects_Base(), object[i]->Get_Floating_Square_Objects())== true )
				{
					return 1;
				}
			}
			if (object[i] == NULL)
			{
				return 0;
			}
		}
	}


	// If the player is above a block give them the cooridantes of the cube and the position the shadow should be.
	// if the player is not above a cube give them a negative number and do nothing.
	if (returner == 1)
	{
		// Drop shadow that appears on the ground floor ect loop...
		for (int i = 0; i < MAX_GROUND_OBJECTS; i++)
		{
		
			if (object[i] != NULL) // The array will always be 200 but not everything gets used. the remainder are pointed to null.
			{		
//				if (Drop_Shadow_Enable(Base, Cornice, object[i]->Get_Floating_Square_Objects_Base(), object[i]->Get_Floating_Square_Objects(), 0)!= -1 )
//				{
//					
//					return Drop_Shadow_Enable(Base, Cornice, object[i]->Get_Floating_Square_Objects_Base(), object[i]->Get_Floating_Square_Objects(), 0);
//				}

			}
			if (ground_object[i] != NULL) // The array will always be 200 but not everything gets used. the remainder are pointed to null.
			{		
//				if (Drop_Shadow_Enable(Base, Cornice, ground_object[i]->Get_Ground_Square_Objects(), object[i]->Get_Ground_Square_Objects(), 1)!= -1 )
//				{
//					return Drop_Shadow_Enable(Base, Cornice, ground_object[i]->Get_Ground_Square_Objects(), ground_object[i]->Get_Ground_Square_Objects(), 1);
//				}
			}


			if (object[i] == NULL)
			{
				return 0;
			}
		}
	}
	

	
	return 0; // No collision
}*/

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

/*
void Character::Change_Character_Coord()
{
	std::ifstream Load( "current_location" ); if( Load == NULL ) {Load.close();  }
	
	//Name of the level
	std::string  READ_FILE;

	getline( Load, READ_FILE);	
	getline( Load, READ_FILE);	
	getline( Load, READ_FILE);	
	getline( Load, READ_FILE);	
	getline( Load, READ_FILE);	
	getline( Load, READ_FILE);	
	getline( Load, READ_FILE);	

	//Start recording the numbers
	Load >> X_Coord;
	Load >> Y_Coord;
	Load >> Z_Coord;	

	Load.close();
}*/

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

/*
int Character::Get_Character_State_Of_Being()
{
	return Character_State_Of_Being;
}*/


////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

/*
void Character::Show_Character_Gauge()
{	
	// Character's gauge
	Apply_Surface( 0, 360, Gauges,  Screen, &Gauges_Clips[ CT_GAUGES_CLIP_START ] ) ;

	// Health bars
	Apply_Surface( 30, 463, Gauges,  Screen, &Gauges_Clips[ HEALTH_CLIP_START + Character_Health] ) ;

}*/

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
/*
void Menu::Setup_Menu()
{ 
	Positioning = true;
	Target_X = SCREEN_WIDTH /2; 
	Target_Y = SCREEN_HEIGHT /2;
}*/
/*
void On_Screen_Object::Show_Save_Menu()
{
	Apply_Surface( 0, 0, ScreenEffects,  Screen, &Screen_Effects_Clips[CYRON_SAVE_MENU] ) ;

}

void On_Screen_Object::Show_Save_Menu_Reticle()
{
	Apply_Surface( Target_X, Target_Y, ScreenEffects,  Screen, &Screen_Effects_Clips[TARGET_WHITE] ) ;

}

void  On_Screen_Object::Show_Menu_Block()
{
	Apply_Surface( 460, 6, ScreenEffects,  Screen, &Screen_Effects_Clips[MENU_SAVE_RETURN] ) ;

	Apply_Surface( 460, 86, ScreenEffects,  Screen, &Screen_Effects_Clips[MENU_SAVE_SAVE] ) ;


} */

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

//Shadow effects
// Used to gather info from objects the character touches
/*int Collision_Detection_Info( Square Base, Square Cornice, Soul *Spirit[], int returner, int type)
{
	
	//What the character's base is touching
	int Base_Collision;

	//Tracking the player
	int Upper_Tracked, Bottom_Tracked;
	
	//A temporary varible for simplicity
	Square S;

	
		for (int i = 0; i < SMAX_GAME_OBJECTS; i++)
		{
			if (Spirit[i] != NULL) // The array will always be 200 but not everything gets used. the remainder are pointed to null.
			{
				if(Spirit[i]-> Get_Object_Type() == FLOAT )
				{
					Base_Collision = Base_Object_Detection(Base, Cornice, Spirit[i]->Get_Objects_Base());
			
					switch (Base_Collision)
					{
						case MIDAIR: break;
						case BASE_OBJECT_TOUCH: 			
					
							Upper_Tracked = Tracking(0, Base, Spirit[i]->Get_Objects_Base());
							Bottom_Tracked = Tracking(1, Base, Spirit[i]->Get_Objects_Base());
						
								if (Object_Detection_Above_Below(Upper_Tracked, Bottom_Tracked,  Cornice, Spirit[i]->Get_Objects())!= MIDAIR)
								{
									if(type == 1)
									{
										S = Spirit[i]->Get_Objects();
										if (returner == 0){	return Spirit[i]->Get_Type();	} // Type
										if (returner == 1){	return Spirit[i]->Get_X()+ S.w/2;	} // X
										if (returner == 2){	return Spirit[i]->Get_Y()+ S.h/5;} // Y
										if (returner == 3){	return Spirit[i]->Get_Z();	} // Z
									}
								}
					}		
				}
			
			}
		

			if (Spirit[i] == NULL)
			{
				//End the cycle!  There are no Collisions. 
				return -1;
			}
		}
		
	return -1; // No collision
}*/

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

/*
void Sky_Line_Clip()
{
	
	Sky_Line_Clips[CLIP_BLACK_BG].x = 0;
	Sky_Line_Clips[CLIP_BLACK_BG].y = 0;
	Sky_Line_Clips[CLIP_BLACK_BG].w = 640;
	Sky_Line_Clips[CLIP_BLACK_BG].h = 480;


}*/

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
/*
int Character::Get_Character_Altitude_Height()
{
	return Character_Altitude_Height;
}*/

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
/*/ Rendering, will be given to the render class
void Character::Show(int frame)
{

	Character_Frame = frame;
	if(Character_Drop_Shadow > 0)
	{
		Apply_Surface( (int)X_Coord - Camera.x, Character_Drop_Shadow - Camera.y, Character1,  Screen, &Character_Test_Clips[1] ) ;
	}
	
	Apply_Surface( (int)X_Coord - Camera.x , (int)Z_Coord - Camera.y, CryonTanryokuSheet , Screen, &Cyron_Tanryoku_Clips[Character_Frame] ) ;
//	if (Character_Shadow == true)
	//{
		//Apply_Surface( (int)X_Coord - Camera.x , (int)Z_Coord - Camera.y, ShadowCryonTanryokuSheet , Screen, &Cyron_Tanryoku_Clips[Character_Frame] ) ;
	//}

}*/
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////


/*
void Editor_Save_Floor( Environment_Objects *floor_object[], int level )
{
	
    //Open all floor maps
    std::ofstream Lv1AFloor( "Lv1AFloor.map" );
    std::ofstream Lv1BFloor( "Lv1BFloor.map" );
	switch (level)
	{
		case LEVEL_1_A:
				//Go through the tiles
				for( int t = 0; t < MAX_FLOOR_OBJECTS; t++ )
				{
					
					//Write tile type to file
			//		Lv1AFloor << floor_object[ t ]->get_type() << " ";
				} break;
		case LEVEL_1_B:
				//Go through the tiles
				for( int t = 0; t < MAX_FLOOR_OBJECTS; t++ )
				{
					//Write tile type to file
				//	Lv1BFloor << floor_object[ t ]->get_type() << " ";
				} break;


	}
    //Close the fileS
    Lv1AFloor.close();
	Lv1BFloor.close(); 
}
*/

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
/*
void External_Configuration::Configurate_Lenght_Width_Height(int type, int y, int z)
{
	int Type = type;

	switch (Type)
	{
		case LV1A_1: Exit_Height = y - z; Exit_Width = 20; Exit_Lenght = 50; break;
		case LV1A_2: break;
		case LV1A_3: break;
		case LV1B_1: Exit_Height = y - z; Exit_Width = 20; Exit_Lenght = 50; break;
	}
}*/

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
/*bool External_Configuration::Configurate_Total_Objects()
{
	/**********************************************					
	// Open one of these files base on level name.  
	
	if (Level_Name == "Lv1A")
	{	
		std::ifstream Lv1AFloatingXYZ ("Lv1AFloatingXYZ.map"); if( Lv1AFloatingXYZ == NULL ) { return false; } 
		std::ifstream Lv1AFloor ("Lv1AFloor.map") ;if( Lv1AFloor == NULL ) { return false; } 
			
		//Define the total number of  floating tilts within a level
		Lv1AFloatingXYZ >> Current_Total_Floating_Objects;
		Lv1AFloor >> Current_Total_Floor_Objects;


		//After everything is complete close the files.
		Lv1AFloatingXYZ.close(); 
		Lv1AFloor.close(); 

	}

	
	return true;
}*/

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

/*
int Set_Floor_Objects(int Start_Num, Soul *Spirit[], External_Configuration config)
{

	//Starting point of tile placement
	int x = 0, y = 0; 

	int Start_Number = Start_Num;

	// Total tiles is declared in respected files. it is the first number.
	int Total_Floor_Objects;

	int Level_Value;

	bool Failure = false; 
	//Name of the level
    std::string Level;
	Level = config.Get_Level_Name();
	
	// Level value is to make the code flexible
	Level_Value = Object_Setting_Helper(Level);

	// ALL the files are loaded but that aren't all used. This code has many switch case statements
	std::ifstream Lv1AFloor( "Lv1AFloor.map" );if( Lv1AFloor == NULL ) { return false; }
	std::ifstream Lv1BFloor( "Lv1BFloor.map" );if( Lv1BFloor == NULL ) { return false; }
		
	
	switch (Level_Value)
	{					 // Definig the total number of title. remember it the first element
		case LEVEL_1_A:  Lv1AFloor >> Total_Floor_Objects; break;
		case LEVEL_1_B:  Lv1BFloor >> Total_Floor_Objects; break;
	}

	//Initialize the tiles 
	for( int t = 0; t < Total_Floor_Objects; t++ ) 
	{ 
		//Determines what kind of tile will be made 
		int tileType = -1; 

		switch (Level_Value)
		{					 //Read from map file****** Stop loading if there was a problem
			case LEVEL_1_A:  Lv1AFloor >> tileType;  if( Lv1AFloor.fail() == true ) {Failure = true;} break;
			case LEVEL_1_B:  Lv1BFloor >> tileType;  if( Lv1BFloor.fail() == true ) {Failure = true;} break;																		

		}
		
		// if anything messed up shut down
		if (Failure == true)
		{
			Lv1AFloor.close(); 
			Lv1BFloor.close(); 
			return -1; 
				
		}

		

		//If the number is a valid tile number 
		if( ( tileType >= 0 ) && ( tileType <= FLOOR_TILE_SPRITES ) ) 
		{ 
			Spirit[ Start_Number ] = new Environment_Floor_Objects( x, y, tileType ); 
			//Move to next tile spot 
			x += TILE_WIDTH; 

		} 

		//If we don't recognize the tile type 
		else 
		{ 
			//CLOSE ALL FILES! ALL OF THEM
			Lv1AFloor.close(); 
			Lv1BFloor.close(); 
			return -1; 
		} 

		//If we've gone too far 
		if( x >= config.Get_Level_Width_Lenght(0)) 
		{ 
			//Move back 
			x = 0; 

			//Move to the next row 
			y += TILE_HEIGHT; 
		}
		Start_Number++;
	
	} 
	
	//Closing the file.
	Lv1AFloor.close(); 
	Lv1BFloor.close(); 
 	return Start_Number;

}
int Set_Floating_Objects( int Start_Num, Soul *Spirit[], External_Configuration config) 
 { 
	int x = 0, y = 0, z = 0; 
	int Total_Floating_Objects;	
	int Start_Number = Start_Num;

	int Level_Value;

	bool Failure = false; 
	//Name of the level
    std::string Level  = config.Get_Level_Name();
	
	// Level value is to make the code flexible
	Level_Value = Object_Setting_Helper(Level);
	
	
	std::ifstream Lv1AFloatingXYZ ("Lv1AFloatingXYZ.map" );if( Lv1AFloatingXYZ == NULL ) {Lv1AFloatingXYZ.close();  return false; }
	std::ifstream Lv1BFloatingXYZ ("Lv1BFloatingXYZ.map" );if( Lv1BFloatingXYZ == NULL ) {Lv1BFloatingXYZ.close();  return false; }

	switch (Level_Value)
	{					
						// Open one of these file ONLY for reading. 
		case LEVEL_1_A:	Lv1AFloatingXYZ >> Total_Floating_Objects; break;
		case LEVEL_1_B:	Lv1BFloatingXYZ >> Total_Floating_Objects; break;

	}
	
	
	
	//Initialize the tiles 
	for( int t = 0; t < Total_Floating_Objects; t++ ) 
	{ 
		int TileType = -1; 
		switch (Level_Value)
		{				//MUST BE READ IN THIS ORDER NO EXCEPTIONS!	
			case LEVEL_1_A: Lv1AFloatingXYZ >> TileType; Lv1AFloatingXYZ >> x; Lv1AFloatingXYZ >> y; Lv1AFloatingXYZ >> z;  
				if( Lv1AFloatingXYZ.fail() == true ) { Failure = true; }break;
			case LEVEL_1_B: Lv1BFloatingXYZ >> TileType; Lv1BFloatingXYZ >> x; Lv1BFloatingXYZ >> y; Lv1BFloatingXYZ >> z;  
				if( Lv1BFloatingXYZ.fail() == true ) { Failure = true; }break;

		}
		//If the was a problem in reading the map 
		if( Failure == true ) 
		{ 
			//CLOSE ALL FILES
			Lv1AFloatingXYZ.close(); 
			Lv1BFloatingXYZ.close(); 
			return -1; 
		} 

		//If the number is a valid tile number 
		if( ( TileType >= 0 ) && ( TileType <= FLOATING_TILE_SPRITES ) ) 
		{ 
			Spirit[ Start_Number ] = new Environment_Float_Objects ( x,  y, z, TileType ); 
		} 

		//If we don't recognize the tile type 
		else 
		{ 
			//CLOSE ALL FILES
			Lv1AFloatingXYZ.close(); 
			Lv1BFloatingXYZ.close(); 
			return -1; 
		} 

		Start_Number++;
	
	} 
	
					
	                                               

		Lv1AFloatingXYZ.close(); 
		Lv1BFloatingXYZ.close(); 
	

 return Start_Number; 
 } 
int Set_Config_Objects( int Start_Num, Soul *Spirit[], External_Configuration config)
{	
	int x = 0, y = 0, z = 0; 
	int Total_Config_Objects;
	
	int Start_Number = Start_Num;

	int Level_Value;

	bool Failure = false; 
	//Name of the level
    std::string Level  = config.Get_Level_Name();
	
	// Level value is to make the code flexible
	Level_Value = Object_Setting_Helper(Level);
	
	
	std::ifstream Lv1AConfig ("Lv1AConfig.map" );if( Lv1AConfig == NULL ) {Lv1AConfig.close();  return false; }
	std::ifstream Lv1BConfig ("Lv1BConfig.map" );if( Lv1BConfig == NULL ) {Lv1BConfig.close();  return false; }

	switch (Level_Value)
	{					
						// Open one of these file ONLY for reading. 
		case LEVEL_1_A:	Lv1AConfig >> Total_Config_Objects; break;
		case LEVEL_1_B:	Lv1BConfig >> Total_Config_Objects; break;

	}
	
	
	
	//Initialize the tiles 
	for( int t = 0; t < Total_Config_Objects; t++ ) 
	{ 
		int TileType = -1; 
		int GateType = -1;
		switch (Level_Value)
		{				//MUST BE READ IN THIS ORDER NO EXCEPTIONS!	
			case LEVEL_1_A: Lv1AConfig >> TileType; Lv1AConfig >> x; Lv1AConfig >> y; Lv1AConfig >> z;  Lv1AConfig >> GateType;
				if( Lv1AConfig.fail() == true ) { Failure = true; }break;
			case LEVEL_1_B: Lv1BConfig >> TileType; Lv1BConfig >> x; Lv1BConfig >> y; Lv1BConfig >> z;   Lv1AConfig >> GateType;
				if( Lv1BConfig.fail() == true ) { Failure = true; }break;

		}
		//If the was a problem in reading the map 
		if( Failure == true ) 
		{ 
			//CLOSE ALL FILES
			Lv1AConfig.close(); 
			Lv1BConfig.close(); 
			return -1; 
		} 

		//If the number is a valid tile number 
		if( ( TileType >= 0 ) && ( TileType <= FLOATING_TILE_SPRITES ) ) 
		{ 
			Spirit[ Start_Number ] = new  Config_Objects( x,  y, z, TileType, GateType ); 
		} 

		//If we don't recognize the tile type 
		else 
		{ 
			//CLOSE ALL FILES
			Lv1AConfig.close(); 
			Lv1BConfig.close(); 
			return -1; 
		} 

		Start_Number++;
	
	} 
	
					
	                                               

		Lv1AConfig.close(); 
		Lv1BConfig.close(); 
	

 return Start_Number; 
}*/

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

/*

//ZERO CONSTRUCTOR (0)
Environment_Objects::Environment_Objects()
{
	Floor_Objects.x = 0;
	Floor_Objects.y = 0;
	Floor_Objects.w = 0;
	Floor_Objects.h = 0;
	Floor_Objects.front_cliff = 0;

    Floating_Objects.x = 0;
    Floating_Objects.y = 0;
    Floating_Objects.w = 0;
    Floating_Objects.h = 0;	
	Floating_Objects.front_cliff = 0;

	Floating_Objects_Base.x = 0;
	Floating_Objects_Base.y = 0;
	Floating_Objects_Base.w = 0;
	Floating_Objects_Base.h = 0;

	Grounded_Objects.x = 0;
	Grounded_Objects.y = 0;
	Grounded_Objects.w = 0;
	Grounded_Objects.h = 0;
	Grounded_Objects.front_cliff = 0;

	Type = 0;
	
	//Coordinates of the objects
	Object_Coord_x = 0;
	Object_Coord_y = 0;
	Object_Coord_z = 0;
	
	// Collsion detection properties of Objects. Width relates to x, Lenght relate to y, Height relates to z. 
	Object_Width = 0;
	Object_Lenght = 0;
	Object_Height = 0;

	//Determine rather an object is animated or not.
	Animated = false;
}

//FIRST CONSTRUCTOR (1)
/*Environment_Objects::Environment_Objects( int x, int y,  int object_type ): Soul(x, y,  object_type )
{
	
	//Assigns values to class variables
	Object_Coord_x = x;
	Object_Coord_y = y;

	// Uses the object type to set the width and lenght used for collision boxes.
	Width_Height_Assigner(object_type);


    //Get the offsets
    Floor_Objects.x = x;
    Floor_Objects.y = y;

    //Set the collision box
    Floor_Objects.w = Object_Width;
    Floor_Objects.h = Object_Lenght;
	
    //Get the tile type
    Type = object_type;

	

}



//SECOND CONSTRUCTOR (2)
Environment_Objects::Environment_Objects( int x, int y, int z,  int object_type )
{
	// Perfect
	Object_Elevation =  z;

	 
	// Assigns values to class variables
	Object_Coord_x = x;
	Object_Coord_y = y;
	Object_Coord_z = y - z;
	
	
	// Set the variables so everthing can be defined
	Square_Assigner(object_type, y);

    //Get the offsets
    Floating_Objects.x = Object_Coord_x;
    Floating_Objects.y = Object_Coord_z;
    Floating_Objects.w = Object_Width;
    Floating_Objects.h = Object_Height;
	Floating_Objects.front_cliff = Object_Front_Edge;

	Floating_Objects_Base.x = Object_Coord_x;
	Floating_Objects_Base.y = Object_Coord_y;
	Floating_Objects_Base.w = Object_Width;
	Floating_Objects_Base.h = Object_Lenght;

    //Get the tile type// Perfect
    Type = object_type;


}

//THIRD CONSTRUCTOR (3)
Environment_Objects::Environment_Objects( bool Required, int x, int y, int z, int object_type )
{
	// Perfect
	Object_Elevation =  z;

	 
	// Assigns values to class variables
	Object_Coord_x = x;
	Object_Coord_y = y;
	Object_Coord_z = y - z;
	
	
	// Set the variables so everthing can be defined
	Square_Assigner(object_type, y);

    //Get the offsets
    Grounded_Objects.x = Object_Coord_x;
    Grounded_Objects.y = Object_Coord_y;
    Grounded_Objects.w = Object_Width;
    Grounded_Objects.h = Object_Lenght;
	Grounded_Objects.front_cliff = Object_Elevation;

    //Get the tile type// Perfect
    Type = object_type;


	/**************************************************************************************
	//			VARIABLES IM NOT USING THAT NEED TO BE INTIALIZED. THEY ARE ALL 0		///

	

}


// Used for "FLOOR" objects only. Will be renamed later to match this...
void Environment_Objects::Width_Height_Assigner(int type)
{
	// Enum with "s" = standard square shape. Enum with "i" aren't squares, their rectangles.
	enum { LARGE_RED_TILE, LARGE_GREEN_TILE, LARGE_BLUE_TILE};

   switch (type)
   {
	   case LARGE_RED_TILE: Object_Width = 80; Object_Lenght = 80;  break;
	   case LARGE_BLUE_TILE: Object_Width = 80; Object_Lenght = 80; break;
	   case LARGE_GREEN_TILE: Object_Width = 80; Object_Lenght = 80; break;
   }
}

void Environment_Objects::Square_Assigner(int type, int y)
{
	

   switch (type)
   {
	   case BLUE_CUBE:	Object_Width = 40; Object_Lenght = 40;  Object_Front_Edge = Object_Lenght; 
					Object_Height = 80 ; 
				break;
	   case TALL_BLUE_CUBE: Object_Width = 40; Object_Lenght = 80;  Object_Front_Edge = Object_Lenght; 
					   Object_Height = 120 ;
				break;
	   ///case SAVE_PAD:	Object_Width = 49; Object_Lenght = 30;  Object_Front_Edge = Object_Lenght; 
		//			Object_Height = 60 ; 
		//			break;
   }
}

	
int Environment_Objects::Get_Type()
{
    return Type;
}
int Environment_Objects::Get_X()
{
    return Object_Coord_x;
}
int Environment_Objects::Get_Y()
{
    return Object_Coord_y;
}

int Environment_Objects::Get_Z()
{
    return Object_Coord_z;
}
//Square objects to be returned
Square Environment_Objects::Get_Floor_Objects()
{
    return Floor_Objects;
}
Square Environment_Objects::Get_Floating_Square_Objects()
{
	return Floating_Objects;
}
Square Environment_Objects::Get_Floating_Square_Objects_Base()
{
	return Floating_Objects_Base;
}

Square Environment_Objects::Get_Ground_Square_Objects()
{
	return Grounded_Objects;
}	

void Environment_Objects::Show_Environment_Float_Object(int condition)
{
	if (condition != 2)
	{
		if (condition == 0)
		{
			if( Square_Object_Detection (Camera, Floating_Objects ) == true ) 
			{
				Apply_Surface( Object_Coord_x - Camera.x, Object_Coord_z - Camera.y, FloatTileSheet, Screen, &Float_Object_Clips[Type] ); 
			}
		}
		
		if (condition == 1)
		{
			if( Square_Object_Detection (Camera, Floating_Objects ) == true ) 
			{
				Apply_Surface( Object_Coord_x - Camera.x, Object_Coord_z - Camera.y, TransparentFloatTileSheet, Screen, &Float_Object_Clips[Type] ); 
			}
		}
	}

}

void  Environment_Objects::Show_Environment_Float_Base_Object()
{
		if( Square_Object_Detection (Camera, Floating_Objects_Base ) == true ) 
		{
			Apply_Surface( Object_Coord_x - Camera.x, Object_Coord_y - Camera.y, ShadowFloatTileSheet, Screen, &Shadow_Float_Object_Clips[Type] ); 
		}
}

void  Environment_Objects::Show_Environment_Ground_Object()
{
		if( Square_Object_Detection (Camera, Grounded_Objects ) == true ) 
		{
			Apply_Surface( Object_Coord_x - Camera.x, Object_Coord_z - Camera.y, FloatTileSheet, Screen, &Float_Object_Clips[0] ); 
		}
}

void Environment_Objects::Show_Environment_Floor_Object()
{
		if( Square_Object_Detection (Camera, Floor_Objects ) == true ) 
		{
			Apply_Surface( Object_Coord_x - Camera.x, Object_Coord_y - Camera.y, FloorTileSheet, Screen, &Floor_Object_Clips[ Type ] ); 
		}


}

*/

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

/*class Environment_Objects
{
    private:
    
	

	Square Floor_Objects;
	Square Floating_Objects, Floating_Objects_Base;
	Square Grounded_Objects;

    //The tile type
    int Type;
	
	//Coordinates of the objects
	int Object_Coord_x, Object_Coord_y, Object_Coord_z;
	
	// Collsion detection properties of Objects. Width relates to x, Lenght relate to y, Height relates to z. 
	int Object_Width, Object_Lenght, Object_Height;
	
	// The front edge of an object. Have a value in relation to y
	int Object_Front_Edge, Object_Elevation;

	// Activate animation for objects base on type
	bool Animated;


	enum {SQUARE, CIRCLE, TRIANGLE};


    public:
    
	//(0) This constructor set the values of a few special variables.
	Environment_Objects();

	//(1) The construtor for the base floor objects.Most base floor tiles are squares.
	//Environment_Objects( int x, int y,  int object_type );


	//(2) The construtor for floating square objects. Requires many many  test. Check logs to see completeion prerequisits.  
    Environment_Objects( int x, int y, int z, int object_type );

	//(3) The construtor for grounded square objects. Bool constructor has no usage. Used so compiler won't confuse consturtors.
    Environment_Objects( bool Required, int x, int y, int z, int object_type );

	// Use restricted to Constructor 1 until further anylisis. Uses type to give value to height and width. 
	void Width_Height_Assigner(int type);

	//Define a square using object type. 
	void Square_Assigner(int type , int y);

    //Get the tile type
    int Get_Type();
	int Get_X();
	int Get_Y();
	int Get_Z();
    //Get the collision box of squares. 
    Square Get_Floor_Objects();
	Square Get_Floating_Square_Objects();
	Square Get_Floating_Square_Objects_Base();
	Square Get_Ground_Square_Objects();

	//Display functions only
	void Show_Environment_Float_Object(int condition);
	void Show_Environment_Float_Base_Object();
	void Show_Environment_Ground_Object();
	void Show_Environment_Floor_Object();

	
	void Set_Values(int x, int y,  int object_type);

};*/

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
/*
//Saving the "floor" bit map type. 
void Editor_Save_Floor( Environment_Objects *floor_object[], int level );*/

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
/*void The_Ys_Guy::Variable_Definer_Active(Physics data, External_Configuration C, Soul *Spirit[], Uint32 deltaTicks)
{
	if(Game_Mode == GAMEPLAY_MODE)
	{
		//Character_Base.front_cliff = Character_Base.y + Character_Base.h/2; 
	
		//STATE OF BEING
		//Character_State_Of_Being = data.Game_Physics(Z_Coord, CHARACTER_HEIGHT, Y_Coord, Spirit, Character_Base, Character_Cornice );
	
		// Shadow conditions
		//Character_Shadow = Collision_Detection_Shadow( Character_Base, Character_Cornice, object,ground_object, 0);
	//	Character_Drop_Shadow = Collision_Detection_Shadow( Character_Base, Character_Cornice, object,ground_object, 1);

		//BUTTONS
		Button = Button_Command();

		//COODINATES
		X_Coord += X_Vel *( deltaTicks / 1000.f );
		Character_Base.x = X_Coord;
		Character_Cornice.x = X_Coord;


		Y_Coord += Y_Vel *( deltaTicks / 1000.f );	
		Character_Base.y = Y_Coord;
		Character_Cornice.y = Z_Coord;


		Character_Base.front_cliff = Character_Base.y + (CHARACTER_LENGHT/2); 
//		Base = Character_Base.y + Character_Base.h/2; 

		//Character_Altitude_Height =  Base - Z_Coord;
		

		// CONDITIONAL STATEMENTS
		if (X_Coord < 0)
		{X_Coord -= X_Vel *( deltaTicks / 1000.f );}
		if (X_Coord + CHARACTER_WIDTH > C.Get_Level_Width_Lenght(0))
		{X_Coord -= X_Vel *( deltaTicks / 1000.f );}
	
		if (Y_Coord < 0)
		{Y_Coord -= Y_Vel *( deltaTicks / 1000.f );}
		if (Y_Coord + CHARACTER_HEIGHT > C.Get_Level_Width_Lenght(0))
		{Y_Coord -= Y_Vel *( deltaTicks / 1000.f );}

		if (Character_Health > 20)
		{
			Character_Health = 20;
		}
		if (Character_Health <= 1)
		{
			Character_Health = 0;
		}


		//if (Degree)

	}
}*/

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
/*
float The_Ys_Guy::Get_Character_Coord(int returner)
{
	enum {X, Y,Z};
	switch (returner)
	{
		case X:  return X_Coord;
		case Y:	 return Y_Coord;
		case Z:  return Z_Coord;

	}

	return -1; 
}*/