/*
 * @author William Ruan
 * @description This builds the object networkinterfacelist and its functions
 * @date October 3rd, 2018
*/


#include "networkinterfacelist.h"

using namespace std;

/*
 * Constructor for networkinterfacelist object
 * name: William Ruan
 * 
 */
networkinterfacelist::networkinterfacelist(DIR * newDir){
	dir = newDir;
}

/*
 * Destructor for networkinterfacelist object
 * name: William Ruan
 * 
 */
networkinterfacelist::~networkinterfacelist(){
}

/*
 * Gets list of network interfaces
 * name: William Ruan
 * @return network interface list
 * 
 */
std::vector<std::string> networkinterfacelist::getNetworkList(){
	return networkList;
}

/*
 * Fills the network list variable from directory information
 * name: William Ruan
 * 
 */
void networkinterfacelist::fillNetworkList(){
	// Checks if directory is null
	if (dir != NULL) {
		// Gets all the information from directory
		while ((ent = readdir (dir)) != NULL){
			// Does not add the "." and ".." onto the list
			if (strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0)
				networkList.push_back(ent->d_name);
		}
	 }
	 // Closes directory
	 closedir (dir);
}

/*
 * Outputs data to user
 * name: William Ruan
 * 
 */
void networkinterfacelist::toString(){
	// Fills the list and outputs one by one to user
	fillNetworkList();
	cout << "Here are the available network interfaces: " << endl;
	for (unsigned i = 0; i < networkList.size(); i++)
		cout << networkList.at(i) << endl;
}


