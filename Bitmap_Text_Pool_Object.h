#ifndef BITMAP_TEXT_OBJECT_H_INCLUDED
#define BITMAP_TEXT_OBJECT_H_INCLUDED

#include "Global.h"
#include "External_Configuration.h"
#include "Soul.h"

 class Bitmap_Text_Pool_Object:public Soul
 {
	 private:
			 SDL_Surface *Bitmap;
			 SDL_Rect Chars[256];
			 
			 Square C;
			 
			 Chain_Link Link;
			 
			 int New_Line, Space; 
			 int X_Coord, Y_Coord, Z_Coord;
			 

	 public: 

	 Bitmap_Text_Pool_Object(int x, int y, int z, SDL_Surface *font);


	 // Builds the font
	 void Build_Font(SDL_Surface *font);

	 void Variable_Setter_Special_Conditional(int condition, int condition2, bool conditionBool, int conditionInt);

	 Chain_Link Get_Chain_Link();

	 void Show_Text(int x, int y, std::string text, SDL_Surface *font);
	 //
	 ///////
	 ////////////////
	 //////////////////////////
	 //////////////////////////////////////
	 ///////////////////////////////////////////////////
	 //USELESS
	 ///////////////////////////////////////////////////
	 ///////////////////////////////////////
	 ///////////////////////////
	 ////////////////
	 ///////
	 //
	void Game_Start(External_Configuration config){}
	void Variable_Setter_Bool_Conditional(int condition, bool condition2){}
	void Variable_Setter_Int_Conditional(int condition, int condition2){}
	void Variable_Setter_Ai_Brain_Conditional(int condition, Ai_Brain Copy_Brain) {}
	void Variable_Setter(){}
	void Variable_Update(Uint32 deltaTicks){}
	void Soul_Physics(int condition, Uint32 deltaTicks){}
	void Soul_Logic(Ai_Brain Copy_Brain, Uint32 deltaTicks){}
	void Soul_Health_Condtions(Uint32 deltaTicks){}
	void Soul_Input(){}
	void Move_Special_Object(){}
	void Teleport_Direct_Input(){}
	void Teleport_Force_Input(float condition, int condition2){}
	void Command_Slave_Calculation(){}
	int Get_Type(){return 0;}
	int Get_Object_Type() {return 0;}
	bool Get_Alive_Key() {return false;}
	bool Get_Animated_Key() {return false;}
	bool Get_Active_Animation_Key() {return false;}

	int Get_Health() {return -1;}
	int Get_Gate_Type(){return 0;}
	int Get_Gravity_Physics() {return 0;}
	int Get_Object_Elevation() {return 0;}
	int Get_Object_State() {return 0;}
	int Get_Child_Num() {return 0;}


	bool Get_Render_Key() {return false;}
	
	
	std::string Get_Text() {return "";}

	int Get_X() {return X_Coord;}
	int Get_Y() {return Y_Coord;}
	int Get_Z() {return Z_Coord;}
	int Get_Center_Base() {return 0;}

	Square Get_Objects() {return C;}
	Square Get_Objects_Base() {return C;}
	Square Get_Objects_Children(int condition) {return C;}
	
	void Show(){}
	void Show_Base(){}

	void Show(int condition) {}
	void Show_Children(int condition, int condition2) {}

	void Show_Graphic_Fx_Shadowed() {}
	void Show_Graphic_Fx_Drop_Shadow(int coord) {}
	void Show_Graphic_Fx_Transparancy() {}
 };
#endif 