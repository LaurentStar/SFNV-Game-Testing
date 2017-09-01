#include "Function.h"


Internal_Config::Internal_Config()
{

	Object_Current_X = 0; 
	Object_Current_Y = 0; 
	Object_Current_Z = 0;
	
	Type = -1;
	On_Screen_Type = -1;

	Location = 0;
	Level = 0;
	Warp_Type = 0;

	Total_Gate_Objects = 0;
	Total_Misc_Objects = 0;
	Total_Render_Objects = 0;
	Total_On_Screen_Misc_Objects = 0;
}


void Internal_Config::Optimization_Variable_Definer( Soul *Spirit[] )
{
	Total_Gate_Objects = 0;
	Total_Render_Objects = 0;
	Total_Misc_Objects = 0;
	Total_Hit_Box_Objects = 0;
	Total_On_Screen_Misc_Objects = 0;

	// Total Gate types
	for (int a = 0; a < MAX_GAME_OBJECTS ; a++ )
	{
		if(Spirit[a] != NULL)
		{
			if(Spirit[a]->Get_Object_Type() == CONFIG)
			{
				if(Spirit[a]->Get_Type() == GATE )
				{
					Track_Gate_Objects[Total_Gate_Objects] =  a;
					Total_Gate_Objects++;
				}
			
			}
		}
		else 
		{
			break;
		}
		
	}

	for (int s = Total_Gate_Objects; s < MAX_GAME_OBJECTS; s++ )
	{
			Track_Gate_Objects[s] =  -1;
	}


	/////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////

	//Total Render types
	for (int a = 0; a < MAX_GAME_OBJECTS ; a++ )
	{
		if(Spirit[a] != NULL)
		{
			if((Spirit[a]->Get_Object_Type() == ON_SCREEN_BG)||(Spirit[a]->Get_Object_Type() == ON_SCREEN))
			{				
					Track_Render_Objects[Total_Render_Objects] =  a;
					//Misc_Objects_Type[Total_Render_Objects] = Spirit[a]->Get_Type();
					Total_Render_Objects++;
			}
		}
		else 
		{
			break;
		}
		
	}

	for (int s =  Total_Render_Objects; s < MAX_GAME_OBJECTS; s++ )
	{
		Track_Render_Objects[s] =  -1;
	}


	/////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////

	//Total Misc types
	for (int a = 0; a < MAX_GAME_OBJECTS ; a++ )
	{
		if(Spirit[a] != NULL)
		{
			if(Spirit[a]->Get_Object_Type() == CONFIG)
			{				
					Track_Misc_Objects[Total_Misc_Objects] =  a;
					Misc_Objects_Type[Total_Misc_Objects] = Spirit[a]->Get_Type();
					Total_Misc_Objects++;
			}
		}
		else 
		{
			break;
		}
		
	}

	for (int s =  Total_Misc_Objects; s < MAX_GAME_OBJECTS; s++ )
	{
		Track_Misc_Objects[s] =  -1;
	}


	/////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////

	//Total Hit box types. // physics are not checked for these. 
	for (int a = 0; a < MAX_GAME_OBJECTS ; a++ )
	{
		if(Spirit[a] != NULL)
		{
			if(Spirit[a]->Get_Object_Type() == HIT_BOX)
			{				
					Track_Hit_Box_Objects[Total_Hit_Box_Objects] =  a;
					// THIS IS ONLY A DAMAGE FOR NOW. FINAL DECISION LATER Misc_Objects_Type[Total_Hit_Box_Objects] = Spirit[a]->Get_Type();
					Total_Hit_Box_Objects++;
			}
		}
		else 
		{
			break;
		}
		
	}

	for (int s =  Total_Hit_Box_Objects; s < MAX_GAME_OBJECTS; s++ )
	{
		Track_Hit_Box_Objects[s] =  -1;
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////

	//On screen Config
	for (int a = 0; a < MAX_GAME_OBJECTS ; a++ )
	{
		if(Spirit[a] != NULL)
		{
			if(Spirit[a]->Get_Object_Type() == ON_SCREEN_CONFIG)
			{
				//if(Spirit[a]->Get_Type() == RETURN_MENU_BUTTON )
				//{
					Track_On_Screen_Misc_Objects[ Total_On_Screen_Misc_Objects] =  a;
					On_Screen_Child_Num[Total_On_Screen_Misc_Objects] = Spirit[a]->Get_Child_Num();
					Total_On_Screen_Misc_Objects++;
				//}
			
			}
		}
		else 
		{
			break;
		}
		
	}

	for (int s = Total_On_Screen_Misc_Objects; s < MAX_GAME_OBJECTS; s++ )
	{
			 Track_On_Screen_Misc_Objects[s] =  -1;
			
			 if (s < 20)
			 {
				On_Screen_Child_Num[s] = 0;
			 }
	}


}

void Internal_Config::Optimization_Chain_Link_Definer( Soul *Spirit[] )
{
	//Making sure the object knows it address
	for (int a = 0; a < MAX_GAME_OBJECTS ; a++ )
	{	
		if(Spirit[a] != NULL)
		{
			Master_Link = Spirit[a]->Get_Chain_Link();
			if (Master_Link.Master_Address == -1)
			{
				Spirit[a]->Variable_Setter_Special_Conditional(0, 1, false, a);   // Set master address
			}

			Slave_Link = Spirit[a]->Get_Chain_Link();
			if (Slave_Link.Slave_Address == -1)
			{
				Spirit[a]->Variable_Setter_Special_Conditional(0, 2, false, a);   // Set slave
			}
		}
		else 
		{
			break;
		}
	}
}

void Internal_Config::Variable_Setter_Conditional(int condition)
{
	switch (condition)
	{

		case LV1A_1:	Level = LEVEL_1_A; 
						Warp_Type = LEVEL_WRAP;
			break;
		case LV1A_2:	Level = LEVEL_1_A; 
						Warp_Type = LEVEL_WRAP;
			break;
		case LV1A_3:	Level = LEVEL_1_A; 
						Warp_Type = LEVEL_WRAP;
			break;
		case LV1B_1:	Level = LEVEL_1_B; 
						Warp_Type = LEVEL_WRAP;
			break;
	}

}

void Internal_Config::Level_Gate_Collision(Soul *Spirit[], External_Configuration config)
{
	for (int a = 0; a < Total_Gate_Objects ; a++ )
	{
		if (Track_Gate_Objects[a] != Selected_Spirit)
		{
			if ( Square_Object_Detection(Spirit[ Selected_Spirit]->Get_Objects_Base(), Spirit[Track_Gate_Objects[a]]->Get_Objects_Base()) == true)
			{
				if ( Square_Object_Detection(Spirit[ Selected_Spirit]->Get_Objects(), Spirit[Track_Gate_Objects[a]]->Get_Objects()) == true)
				{
					//Identify the location the gate is suppose to go
					Location = Spirit[Track_Gate_Objects[a]]->Get_Gate_Type();
					
					//Set all other variables base on the location
					Variable_Setter_Conditional(Location);

					//Figure of out the level's name
					Level_Name = Level_Identitfier(Location);

					//Define new character coords
					Object_Current_X = Character_Coords_Matcher(Location, 0);
					Object_Current_Y = Character_Coords_Matcher(Location, 1);
					Object_Current_Z = Character_Coords_Matcher(Location, 2);
					
					//Save the file
					Write_Current_Location(Location, Level_Name, Object_Current_X, Object_Current_Y , Object_Current_Z);

					
					//Update the variables of the external config class
					config.Configurate_Current_Level_Name();
					config.Configurate_Current_Character_Coord();
					config.Configurate_Current_Level_Width_Lenght();
					
		



					//Begin the warp
					Level_Warpping(Warp_Type, Level, Location , 0, true, Spirit, config);

					//Reorganized the data
					//Optimization_Variable_Definer(Spirit);
					
					//Level_Warp_Key = true;

				}
			}	
			
			else 
			{
				if (Level_Warp != false)
				{
					Level_Warpping(0, LEVEL_1_A, LV1A_1 , 0, false, Spirit, config);
				}
				Level_Warpping(0, LEVEL_1_A, LV1A_1 , 0, false, Spirit, config);
			}
		}
	}
}

void Internal_Config::Misc_Object_Collision(Soul *Spirit[],External_Configuration config)
{
	if(Game_Mode == GAMEPLAY_MODE)
	{
		for (int a = 0; a < Total_Misc_Objects ; a++ )
		{
			if (Track_Misc_Objects[a] !=  Selected_Spirit)
			{
				if(Spirit[Track_Misc_Objects[a]]->Get_Type() != GATE)
				{
					//First check for any collision, then use a Switch to detrimine behaivor
					if ( Square_Object_Detection(Spirit[ Selected_Spirit]->Get_Objects_Base(), Spirit[Track_Misc_Objects[a]]->Get_Objects_Base()) == true)
					{
						if ( Square_Object_Detection(Spirit[ Selected_Spirit]->Get_Objects(), Spirit[Track_Misc_Objects[a]]->Get_Objects()) == true)
						{
							Type = Spirit[Track_Misc_Objects[a]]->Get_Type();

							switch (Type)
							{
								case SAVE_PAD:
												if (Button_Command() == Z)
												{
													if (Spirit[ Selected_Spirit]->Get_Object_State() == STANDING_ON_TOP)
													{
														 Spirit[XTARGET_REDICALX]->Teleport_Direct_Input();
														 Spirit[ Selected_Spirit]->Teleport_Force_Input(90, 20); // Move the charcater just above the save pad

														 //Move the other characters to the X Y AND Z SPOT. 0 = X, 1 = Y, Z = 2
														 //X TELEPORTING
														 Spirit[ XCYRON_TANRYOKUX ]->Variable_Setter_Int_Conditional(0, Spirit[ Selected_Spirit]->Get_X()); 
														 Spirit[ XTHE_YS_GUYX ]->Variable_Setter_Int_Conditional(0, Spirit[ Selected_Spirit]->Get_X());
														 Spirit[ XCXX120X ]->Variable_Setter_Int_Conditional(0, Spirit[ Selected_Spirit]->Get_X());
														 //Y TELEPORTING
														 Spirit[ XCYRON_TANRYOKUX ]->Variable_Setter_Int_Conditional(1, Spirit[ Selected_Spirit]->Get_Y()); 
														 Spirit[ XTHE_YS_GUYX ]->Variable_Setter_Int_Conditional(1, Spirit[ Selected_Spirit]->Get_Y());
														 Spirit[ XCXX120X ]->Variable_Setter_Int_Conditional(1, Spirit[ Selected_Spirit]->Get_Y());
														 //Z TELEPORTING
														 Spirit[ XCYRON_TANRYOKUX ]->Variable_Setter_Int_Conditional(2, Spirit[ Selected_Spirit]->Get_Z()); 
														 Spirit[ XTHE_YS_GUYX ]->Variable_Setter_Int_Conditional(2, Spirit[ Selected_Spirit]->Get_Z());
														 Spirit[ XCXX120X ]->Variable_Setter_Int_Conditional(2, Spirit[ Selected_Spirit]->Get_Z());

														 Change_Game_Mode(SAVE_MENU);
													}
												}
								
								
								
								
									break;






							}
						}
					}
				}	
			}
		}
	}
}

void Internal_Config::On_Screen_Misc_Object_Collision(Soul *Spirit[],External_Configuration config)
{

	bool Collide = false;
	bool break_free = false;
	for (int a = 0; a < Total_On_Screen_Misc_Objects ; a++ )
	{
		if (Track_On_Screen_Misc_Objects[a] != XTARGET_REDICALX)
		{	
			if ( Spirit[Track_On_Screen_Misc_Objects[a]]->Get_Alive_Key() == true)
			{
				if ( Square_Object_Detection(Spirit[XTARGET_REDICALX]->Get_Objects(), Spirit[Track_On_Screen_Misc_Objects[a]]->Get_Objects()) == true)
				{
					On_Screen_Type = Spirit[Track_On_Screen_Misc_Objects[a]]->Get_Type();
					Collide = true;
					Child_Num =  Spirit[Track_On_Screen_Misc_Objects[a]]->Get_Child_Num();

					switch (On_Screen_Type)
					{
						case RETURN_MENU_BUTTON:
												if (Button_Command() == Z)
												{
													Spirit[XTARGET_REDICALX]->Teleport_Direct_Input();
													Change_Game_Mode( GAMEPLAY_MODE);
												}
												break;
						case  SWITCH_MENU_BUTTON: 
												if (Button_Command() == Z)
												{
													Spirit[XSWITCH_MENU_BUTTON_EXPAND1X]->Variable_Setter_Bool_Conditional(1, true);
												}
												break;
						case  SWITCH_MENU_BUTTON_EXPAND1:	
							
										if (Button_Command() == Z)
										{

												for (int z = 0; z < Child_Num; z++)
												{	
													if (break_free == true)
													{
														break;
													}

													if ( Square_Object_Detection(Spirit[XTARGET_REDICALX]->Get_Objects(), Spirit[Track_On_Screen_Misc_Objects[a]]-> Get_Objects_Children(z)) == true)
													{	
														switch (z)
														{
															case 0:	Change_Selected_Character(THE_YS_GUY); 
																	break_free = true;
																	Spirit[XSWITCH_MENU_BUTTON_EXPAND1X]->Variable_Setter_Bool_Conditional(1, false);

																	// Set the characters to active accordingly
																	Spirit[XTHE_YS_GUYX]->Variable_Setter_Bool_Conditional(0, true);
																	Spirit[XCYRON_TANRYOKUX]->Variable_Setter_Bool_Conditional(0, false);
																	Spirit[XCXX120X]->Variable_Setter_Bool_Conditional(0, false);
																	break;
															case 1:	Change_Selected_Character(CYRON_TANRYOKU); 
																	break_free = true;	
																	Spirit[XSWITCH_MENU_BUTTON_EXPAND1X]->Variable_Setter_Bool_Conditional(1, false);

																	// Set the characters to active accordingly
																	Spirit[XTHE_YS_GUYX]->Variable_Setter_Bool_Conditional(0, false);
																	Spirit[XCYRON_TANRYOKUX]->Variable_Setter_Bool_Conditional(0, true);
																	Spirit[XCXX120X]->Variable_Setter_Bool_Conditional(0, false);
																	
																	break;
															case 2:	Change_Selected_Character(CXX120); 
																	break_free = true;	
																	Spirit[XSWITCH_MENU_BUTTON_EXPAND1X]->Variable_Setter_Bool_Conditional(1, false);	
																	
																	// Set the characters to active accordingly
																	Spirit[XTHE_YS_GUYX]->Variable_Setter_Bool_Conditional(0, false);
																	Spirit[XCYRON_TANRYOKUX]->Variable_Setter_Bool_Conditional(0, false);
																	Spirit[XCXX120X]->Variable_Setter_Bool_Conditional(0, true);
																	break;
														}
														//Go through everything else very quick and make sure it's set right.
														for(int i = XGHOSTX; i < XBLACK_BGX + 1; i++)
														{
															Spirit[i]->Variable_Setter();
														}
													}
												}
										}
							break;
					case SAVE_MENU_BUTTON:
											if (Button_Command() == Z)
											{
												Write_Save_Game_Pad(Spirit);
											}
										break;
					}
				}
			}
		}
	}	

	if(Collide == false)
	{
			if (Button_Command() == Z)
			{
				Spirit[XSWITCH_MENU_BUTTON_EXPAND1X]->Variable_Setter_Bool_Conditional(1, false);
			}
	}
	


}

void Internal_Config::Hit_Box_Object_Collision(Soul *Spirit[])
{
	if(Game_Mode == GAMEPLAY_MODE)
	{
		for (int a = 0; a < Total_Hit_Box_Objects ; a++ )
		{
			if (Track_Misc_Objects[a] !=  Selected_Spirit)
			{
				if(Spirit[Track_Misc_Objects[a]]->Get_Type() != GATE)
				{
					//First check for any collision, then use a Switch to detrimine behaivor
					if ( Square_Object_Detection(Spirit[ Selected_Spirit]->Get_Objects_Base(), Spirit[Track_Misc_Objects[a]]->Get_Objects_Base()) == true)
					{
						if ( Square_Object_Detection(Spirit[ Selected_Spirit]->Get_Objects(), Spirit[Track_Misc_Objects[a]]->Get_Objects()) == true)
						{
							Type = Spirit[Track_Misc_Objects[a]]->Get_Type();

							switch (Type)
							{
								case SAVE_PAD:
												if (Button_Command() == Z)
												{
													if (Spirit[ Selected_Spirit]->Get_Object_State() == STANDING_ON_TOP)
													{
														 Spirit[XTARGET_REDICALX]->Teleport_Direct_Input();
														 Spirit[ Selected_Spirit]->Teleport_Force_Input(90, 20); // Move the charcater just above the save pad

														 //Move the other characters to the X Y AND Z SPOT. 0 = X, 1 = Y, Z = 2
														 //X TELEPORTING
														 Spirit[ XCYRON_TANRYOKUX ]->Variable_Setter_Int_Conditional(0, Spirit[ Selected_Spirit]->Get_X()); 
														 Spirit[ XTHE_YS_GUYX ]->Variable_Setter_Int_Conditional(0, Spirit[ Selected_Spirit]->Get_X());
														 Spirit[ XCXX120X ]->Variable_Setter_Int_Conditional(0, Spirit[ Selected_Spirit]->Get_X());
														 //Y TELEPORTING
														 Spirit[ XCYRON_TANRYOKUX ]->Variable_Setter_Int_Conditional(1, Spirit[ Selected_Spirit]->Get_Y()); 
														 Spirit[ XTHE_YS_GUYX ]->Variable_Setter_Int_Conditional(1, Spirit[ Selected_Spirit]->Get_Y());
														 Spirit[ XCXX120X ]->Variable_Setter_Int_Conditional(1, Spirit[ Selected_Spirit]->Get_Y());
														 //Z TELEPORTING
														 Spirit[ XCYRON_TANRYOKUX ]->Variable_Setter_Int_Conditional(2, Spirit[ Selected_Spirit]->Get_Z()); 
														 Spirit[ XTHE_YS_GUYX ]->Variable_Setter_Int_Conditional(2, Spirit[ Selected_Spirit]->Get_Z());
														 Spirit[ XCXX120X ]->Variable_Setter_Int_Conditional(2, Spirit[ Selected_Spirit]->Get_Z());

														 Change_Game_Mode(SAVE_MENU);
													}
												}
								
								
								
								
									break;






							}
						}
					}
				}	
			}
		}
	}
}

void Internal_Config::Hit_Box_Placement()
{
	/*	switch (Master_Link.Master_Type)
		{
			/*case FLOOR:
				//STEP(3) Detect the sub type of the master
				switch (Master_Link.Master_Sub_Type)
				{	
					//FINAL STEP(4) Perform a specialize calculation for this object
					case 0: break;
					case 1: break;
					case 2: break;
				}
				break;

			case FLOAT:
				//STEP(3) Detect the sub type of the master
				switch (Master_Link.Master_Sub_Type)
				{	
					//FINAL STEP(4) Perform a specialize calculation for this object
					case 0: break;
					case 1: break;
					case 2: break;
				}
				break;
			case CONFIG:
				//STEP(3) Detect the sub type of the master
				switch (Master_Link.Master_Sub_Type)
				{	
					//FINAL STEP(4) Perform a specialize calculation for this object
					case 0: break;
					case 1: break;
					case 2: break;
				}
				break;
			case ON_SCREEN:
				//STEP(3) Detect the sub type of the master
				switch (Master_Link.Type_Master_Sub)
				{	
					//FINAL STEP(4) Perform a specialize calculation for this object
					case 0: break;
					case 1: break;
					case 2: break;
				}
				break;
			case ON_SCREEN_CONFIG:
				switch (Master_Link.Master_Sub_Type)
				{	
					//FINAL STEP(4) Perform a specialize calculation for this object
					case RETURN_MENU_BUTTON:	Slave_Object_Text_Speak_Calculation_MENU_BUTTON_TEXT(Spirit);break;
					case SWITCH_MENU_BUTTON:	Slave_Object_Text_Speak_Calculation_MENU_BUTTON_TEXT(Spirit);break;
					case SAVE_MENU_BUTTON:	 Slave_Object_Text_Speak_Calculation_MENU_BUTTON_TEXT(Spirit);break;
				}
				break;
			/*case ON_SCREEN_BG:
				//STEP(3) Detect the sub type of the master
				switch (Master_Link.Type_Master_Sub)
				{	
					//FINAL STEP(4) Perform a specialize calculation for this object
					case 0: break;
					case 1: break;
					case 2: break;
				}
				break;
			case BITMAP_TEXT: break;
			case CYRON_TANRYOKU:
			case THE_YS_GUY:
			case CXX120:
			case GHOST:
			case AI_SMART: 
			case AI_IDIOT:
			case HIT_BOX: break;
		}

	if((Master_Link.Active_Link == true) && (Master_Link.Performing == true) && (Master_Link.Perform == LINK_COMMAND_TEXT_TALK))
	{
		// Display the Text this objects wants to speak.
		Spirit[Slave_Link.Slave_Address]->Show_Text( Master_Link.Master_X_Child[0],  Master_Link.Master_Y_Child[0],  Master_Link.Master_Text, Screen); 
	}*/
}

void Internal_Config::Default_Object_Render(Soul *Spirit[])
{

	switch (Game_Mode)
	{
		case YOU_DUN_GOOFED: break;
		case START_MENU: break;

		case GAMEPLAY_MODE: break;
		case SAVE_MENU:
							for (int a = 0; a < Total_Render_Objects ; a++ )
							{
								if (Spirit[Track_Render_Objects[a]]->Get_Object_Type() ==  ON_SCREEN_BG)
								{
									if(Spirit[Track_Render_Objects[a]]->Get_Gate_Type() == SAVE_MENU)
									{
										if (Spirit[Track_Render_Objects[a]]->Get_Render_Key() == false)
										{
											Spirit[Track_Render_Objects[a]]->Variable_Setter_Bool_Conditional(0, true );
										}
									}
								}
							}
			
			break;

	}
}

//
		////
		/////////
		////////////////
		///HEALTH CONDITION FUNCTIONS FOR GAME OBJECTS//////////////
		////////////////
		/////////
		////
		//



void Internal_Config::Text_Speak(int spirit_num, Soul *Spirit[])
{
	/*/Define the text the objects wants to display
	std::string Text = Spirit[spirit_num]->Get_Text();
	Chain_Link  Link;
	int Slave_Num;
	int Slave_Orders = Spirit[spirit_num]->Get_Slave_Order(); // Orders the slave takes
	//int X = Spirit[spirit_num]->Get_X(); 
	//int Y = Spirit[spirit_num]->Get_Y(); 
	bool Activate = false;
	bool Performing = false;
	Square Text_Location = Spirit[spirit_num]->Get_Objects_Children(0);


	// Check if any slave object was freed by it's master
	for (int t = XBITMAP_TEXT_STARTX; t <  XBITMAP_TEXT_ENDX + 1 ; t++ )
	{
		Link = Spirit[t]->Get_Chain_Link();
		if(Link.Perform == -1)
		{
			Spirit[t]->Variable_Setter_Special_Conditional(0, 0, false, 0); // Turn off the active linking
			Spirit[t]->Variable_Setter_Special_Conditional(0, 1, false, -1);  // No real address values will be given for the master address
			Spirit[t]->Variable_Setter_Special_Conditional(0, 2, false, -1);  // No real address values will be given for the slave address
			Spirit[t]->Variable_Setter_Special_Conditional(0, 3, false, 0);  // Turn off all actions
			Spirit[t]->Variable_Setter_Special_Conditional(0, 4, false, 0);  // Set actions to idle 
			break;
		}
	}
	
	//Check if a link is already established link to the master 
	for (int t = XBITMAP_TEXT_STARTX; t <  XBITMAP_TEXT_ENDX + 1 ; t++ )
	{
		Link = Spirit[t]->Get_Chain_Link();
		if((Link.Active_Link == true) && (Link.Address_Master == spirit_num))
		{
			Activate = Link.Active_Link;
			Slave_Num = t;
			Performing = Link.Performing;
			break;
		}
	}

	//if the slave have not been assigned yet
	if(Activate != true)
	{
		for (int t = XBITMAP_TEXT_STARTX; t <  XBITMAP_TEXT_ENDX + 1 ; t++ )
		{
			Link = Spirit[t]->Get_Chain_Link();
			if(Link.Active_Link == false)
			{
				Activate = true;
				Slave_Num = t;
				Performing = Link.Performing;

				Spirit[t]->Variable_Setter_Special_Conditional(0, 0, true, 0); // The link is activated. Linking in progress
				Spirit[t]->Variable_Setter_Special_Conditional(0, 1, true, spirit_num);  // The address of the master is stored
				Spirit[t]->Variable_Setter_Special_Conditional(0, 2, true, Slave_Num );  // The address of the Slave stored
				Spirit[t]->Variable_Setter_Special_Conditional(0, 3, true, 0 );  // Turn on action listener
				Spirit[t]->Variable_Setter_Special_Conditional(0, 4, true, Slave_Orders );  // Do the specific actions
				break;
			}
		}
	}
	
	//If the object is linked perform an action
	if (Activate == true)
	{
		//If the master wants the slave to act
		if (Performing == true)
		{
			
			//The specific actions the master wants.
			switch (Slave_Orders)
			{
				case -1: Spirit[Slave_Num]->Variable_Setter_Special_Conditional(0, 4, false, -1);  // Set actions to idle 
					break;
				case 0: // Do nothing
					break;
				case 1: Spirit[Link.Address_Slave]->Show_Text( Text_Location.x, Text_Location.y, Text ,Screen); 
					break;
			}
		}
	}*/
}