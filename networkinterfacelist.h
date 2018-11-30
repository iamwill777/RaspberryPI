/*
 * @author William Ruan
 * @description This is the header file for networkinterfacelist
 * @date October 3rd, 2018
*/

#include <string.h>
#include <stdio.h>
#include <sstream>
#include <iostream>
#include <vector>
#include <dirent.h>

// Declares networkinterfacelist class
class networkinterfacelist{
	private:
		// Class variables
		DIR * dir;
		struct dirent * ent;
		std::vector<std::string> networkList;
	public:
		// Constructor for networkinterfacelist object
		networkinterfacelist(DIR *);
		// Destructor
		~networkinterfacelist();
		// Gets list of network interfaces
		std::vector<std::string> getNetworkList();
		// Fills network list
		void fillNetworkList();
		// Returns data to user
		void toString ();
};		
