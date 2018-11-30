/*
 * @author William Ruan
 * @description This builds the object networkinterface and its functions
 * @date October 3rd, 2018
*/

#include "networkinterface.h"

using namespace std;

/*
 * Constructor for networkinterface object
 * name: William Ruan
 * 
 */
networkinterface::networkinterface(const char * file, std::string newNetwork){
	fileName = file;
	network = newNetwork;
}

/*
 * Destructor for networkinterface object
 * name: William Ruan
 * 
 */
networkinterface::~networkinterface(){
}

/*
 * Gets MAC for user
 * name: William Ruan
 * @return returns MAC for the specified network interface
 * 
 */
std::string networkinterface::getMac(){
	return mac;
}

/*
 * Gets MAC from the address file
 * name: William Ruan
 * 
 */
void networkinterface::fillMac(){
	// Gets file
	ifstream file(fileName);
	string line;
	// Gets the MAC address from file
	if (file.is_open()){
		for (int i = 0; getline (file,line) && i < 10; i++){
			// Looks into the file to get MAC
			if (i == 0)
				mac = line;
		}
		// Close file
		file.close();
	}
}

/*
 * Outputs data to user
 * name: William Ruan
 * 
 */
void networkinterface::toString(){
	// Gets MAC first then outputs it
	fillMac();
	cout << "Here is the MAC address for " << network << ": " << mac << endl;
}


