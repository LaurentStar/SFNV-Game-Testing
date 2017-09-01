#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

 class Timer 
 { 
	private: 
		//The clock time when the timer started 
		int startTicks; 

		//The ticks stored when the timer was paused 
		int pausedTicks; 

		//The timer status 
		bool paused; 
		bool started; 
		SDL_Event event; 
	public: 
		//Initializes variables 
		Timer::Timer(); 

		//The various clock actions 
		void start(); 
		void stop(); 
		void pause(); 
		void unpause(); 

		//Gets the timer's time 
		int get_ticks(); 

		//Checks the status of the timer 
		bool is_started(); 
		bool is_paused(); 
 }; 

 #endif // TILE_H_INCLUDED