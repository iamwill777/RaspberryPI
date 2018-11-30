/*
 * @author William Ruan
 * @description This is the header file for hostname
 * @date October 3rd, 2018
*/

#include <unistd.h>
#include <limits.h>
#include <sstream>
#include <iostream>

// Declares new class hostName
class hostName{
	private:
		char * name;
		size_t len;
	public:
		// Constructor
		hostName(char *, size_t);
		// Destructor
		~hostName();
		// Gets host name
		char * getName();
		// Prints out data to user
		void toString ();
};		
