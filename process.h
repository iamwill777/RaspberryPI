/*
 * @author William Ruan
 * @description This is the header file for process
 * @date October 3rd, 2018
*/

#include <string.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <dirent.h>

// Declares process class
class process{
	private: 
		// Class variables
		const char * fileName;
		struct dirent * ent;
		std::string id;
		std::string name;
		std::string ownerID;
		std::string ppID;
		std::string state;
	public:
		// Constructor for process object
		process(const char * , std::string);
		// Destructor for process object
		~process();
		// Gets specific values
		std::string getName();
		std::string getOwnerID();
		std::string getPPID();
		std::string getState();
		// Gets values from file
		void getData();
		// Returns data to user
		void toString ();
};		
