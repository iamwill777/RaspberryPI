/*
 * @author William Ruan
 * @description This builds the object process and its functions
 * @date October 3rd, 2018
*/

#include "process.h"

using namespace std;

/*
 * Constructor for process object
 * name: William Ruan
 * 
 */
process::process(const char * file, std::string newProcess){
	fileName = file;
	id = newProcess;
}

/*
 * Destructor for process object
 * name: William Ruan
 * 
 */
 process::~process(){
}

/*
 * Get the name of the process
 * name: William Ruan
 * @return the name of process
 * 
 */
std::string process::getName(){
	return name;
}

/*
 * Get the owner UID of the process
 * name: William Ruan
 * @return the owner UID
 * 
 */
std::string process::getOwnerID(){
	return ownerID;
}

/*
 * Get the parent process ID of the process
 * name: William Ruan
 * @return the PPID
 * 
 */
std::string process::getPPID(){
	return ppID;
}

/*
 * Get the state of the process
 * name: William Ruan
 * @return the state of process
 * 
 */
std::string process::getState(){
	return state;
}

/*
 * Gets the data from the status file
 * name: William Ruan
 * 
 */
void process::getData(){
	// Gets file
	ifstream file(fileName);
	string line;
	// Gets the name, owner ID, parent process ID, and state from file
	if (file.is_open()){
		for (int i = 0; getline (file,line) && i < 100; i++){
			if (i == 0)
				name = line;
			else if (i == 2)
				state = line;
			else if (i == 6)
				ppID = line;
			else if (i == 8)
				ownerID = line;
		}	
		// Close file
		file.close();
	}
	else{
		cout << "Error cannot get values." << endl;
	}
}

/*
 * Outputs the data to user
 * name: William Ruan
 * 
 */
void process::toString(){
	// Gets appropriate values from status file
	getData();
	cout << "Here are the values for Process ID: " << id << endl;
	cout << name << endl;
	cout << ownerID << endl;
	cout << ppID << endl;
	cout << state << endl;
}


