/*
 * @author William Ruan
 * @description This is the header file for networkinterface
 * @date October 3rd, 2018
*/

#include <string.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <dirent.h>

// Declares networkinterface class
class networkinterface{
	private: 
		// Class variables
		const char * fileName;
		struct dirent * ent;
		std::string mac;
		std::string network;
	public:
		// Constructor
		networkinterface(const char * , std::string);
		// Destructor
		~networkinterface();
		// Gets MAC interfaces
		std::string getMac();
		// Fills MAC list
		void fillMac();
		// Returns data to user
		void toString ();
};		
