/*
 * @author William Ruan
 * @description This builds the object memory and its functions
 * @date October 3rd, 2018
*/

#include "memory.h"

using namespace std;

/*
 * Constructor for memory object
 * name: William Ruan
 * 
 */
memory::memory (struct sysinfo newInfo){
	info = newInfo;
}

/*
 * Destructor for memory object
 * name: William Ruan
 * 
 */
memory::~memory(){
}

/*
 * Gets total RAM
 * name: William Ruan
 * @return the total RAM to user
 * 
 */
int memory::getTotal(){
	return info.totalram;
}

/*
 * Gets the free ram
 * name: William Ruan
 * @return the free ram to user
 */
int memory::getFree(){
	return info.freeram;
}
/*
 * Prints out data to user
 * name: William Ruan
 * 
 */
void memory::toString(){
	// If sysinfo does not work it exits
	if (sysinfo(&info) != 0)
		cout << "There has been an error." << endl;
	else{
		cout << "Total Memory: " << getTotal() / 1000000 << " MB" << endl;
		cout << "Free Memory: " << getFree() / 1000000 << " MB" << endl;
	}
}


