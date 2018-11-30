/*
 * @author William Ruan
 * @description This is the header file for processlist
 * @date October 3rd, 2018
*/

#include <string.h>
#include <stdio.h>
#include <sstream>
#include <iostream>
#include <vector>
#include <dirent.h>

// Declares processlist class
class processlist{
	private:
		// Class variables
		DIR * dir;
		struct dirent * ent;
		std::vector<std::string> processes;
	public:
		// Constructor for processlist object
		processlist(DIR *);
		// Destructor for processlist object
		~processlist();
		// Gets list of processes
		std::vector<std::string> getProcesses();
		// Fills process list
		void fillProcessList();
		// Returns data to user
		void toString ();
		// Checks if Process ID is a number
		bool isNumber(const char * value);
};		
