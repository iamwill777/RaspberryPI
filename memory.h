/*
 * @author William Ruan
 * @description This is the header file for memory
 * @date October 3rd, 2018
*/

#include <sstream>
#include <iostream>
#include <sys/sysinfo.h>

// Constructor for class memory
class memory{
	private:	
		struct sysinfo info;
	public:
		// Constructor
		memory (struct sysinfo);
		// Destructor
		~memory();
		// Gets memory information
		int getTotal ();
		int getFree ();
		// Outputs to user
		void toString ();
};		
