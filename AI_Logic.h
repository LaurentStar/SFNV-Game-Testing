#ifndef AI_H_INCLUDED
#define AI_H_INCLUDED


class AI_Logic
{
	private:
	 // The space that the AI notices first. 
	Circle Personal_Space;


	
	Chain_Link Master_Link, Peer_Link, Slave_Link;

	Ai_Brain  Host_Brain;

	int Object_Type, Type; 

	public:
		AI_Logic();

		// Allows AI to talk to humans and other AI. //TO BE CONTINUED
		void AI_Talk();

		//Conditional compute logic values.
		void AI_Brains();

		//Dumb Ai programming
		void AI_Dumb_Brain(Soul *Spirit[]);

		// Sends very specific values to AI to perform instrucutions
		void AI_instructions();


		void Ai_Request(); // Does everything the AI cannot on its own

		///////
		//////////////////
		//////////////////////////
		/////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////
		//////////////////////////
		/////////////////
		//////
		void AI_Logic_CHROME_CRYSTAL(Soul *Spirit[]);
};

#endif // CHARACTER_H_INCLUDED



//AI CONCEPTS FOR THE GAME

/////////
//Move:// 
/////////
	/*Commanding the AI to move in a specfic way until a certain point is reached. This means the AI is given directional input and performs
	any actions availble and nessary to move in the direction specfied. 
	*/
	//Perceive Relations: The AI will beable to tell when to stop safely from falling off a climb or to know when it can't make jumps. 
	// The AI will be able to avoid attacks if it can notice, and run away in a smart way. It should be able to step aside or block AI and 
	// Players. I should be smart enough to not stray too far from an area or beable to talk to other AI to hunt down something specific.

/////////////
//perceive://
/////////////
	/*Allow the AI to notice it's environment, sounds, player behaivor, and player and other AI speech. The AI can detect objects around it
	and think of a way to get where it wants. 
	
	*/

	//Imagine//
	/* Allows the AI to imagine the outcome of solutions when it has time to think. 

	*/
	//Fight: The AI's fighting styles
	//Word: 