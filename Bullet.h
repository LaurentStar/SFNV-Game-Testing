#ifndef BULLET_H_INCLUDED
#define BULLET_H_INCLUDED


// Used by all active and alive objects including the player.
 class Bullet_Object
 { 
	private:
		Square  Bullet_Base, Bullet_Cornice ;
		Circle Existance_Bubble; 
		
		int Type;
		bool Active, Harm_Player, Harm_AI;
		
		// Placing the bullt
		float X_Coord, Y_Coord, Z_Coord; //RED!
		
		float Friction, Degree, Force_Degree, Magnitude,Force, X_Vel, Y_Vel, Z_Vel, Slope;
		int Bullet_Height, Bullet_Lenght, Bullet_Width;
		int Damage;

		// Detrimine how long a bullet exist
		float Bullet_Existance_Timer;
		int Bullet_Existance_Time;
	protected:


	public:
		Bullet_Object();


	//Depending on the enemy type detrimine traits about the enemy including collision boxes
	void Bullet_Definer(int type, int x, int y, int z ,int lenght, int width, int height, int time);
	void Bullet_Type_Assigner(Uint32 deltaTicks);


	bool Get_Harm_Player();
	bool Get_Active();
	int Get_Damage();
	int Get_Type();
	Square Get_Bullet_Cornice();
	Square Get_Bullet_Base();

	void Show_Enemy();
	void Show_Bullet_Base();
 }; 
 #endif 