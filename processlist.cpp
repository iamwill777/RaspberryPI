/*
 * @author William Ruan
 * @description This builds the object processlist and its functions
 * @date October 3rd, 2018
*/

#include "processlist.h"

using namespace std;

/*
 * Constructor for processlist object
 * name: William Ruan
 * 
 */
processlist::processlist(DIR * newDir){
	dir = newDir;
}

/*
 * Destructor for processlist object
 * name: William Ruan
 * 
 */
 processlist::~processlist(){
}

/*
 * Get all the process IDs
 * name: William Ruan
 * @return the processID list
 * 
 */
std::vector<std::string> processlist::getProcesses(){
	return processes;
}

/*
 * Fills the processes list from all the numeric process IDs in directory
 * name: William Ruan
 * 
 */
void processlist::fillProcessList(){
	// Checks if directory is null
	if (dir != NULL) {
		// Finds all process IDs
		while ((ent = readdir (dir)) != NULL){
			// Only adds the process if it is a number
			if (isNumber(ent->d_name))
				processes.push_back(ent->d_name);
		}
	 }
	 // Closes directory
	 closedir (dir);
}

/*
 * Outputs process ID list to user
 * name: William Ruan
 * 
 */
void processlist::toString(){
	fillProcessList();
	cout << "Here are the Process IDs: " << endl;
	for (unsigned i = 0; i < processes.size(); i++)
		cout << processes.at(i) << endl;
}

/*
 * Helper method to determine if directory has a numeric value
 * name: William Ruan
 * @param the directory name
 * @return whether it's numeric or not
 * 
 */
bool processlist::isNumber(const char * value){
	char * c;
	strtol(value, &c, 10);
	return * c == 0;
}

