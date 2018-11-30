/*
 * @author William Ruan
 * @description This builds the object hostname and its functions
 * @date October 3rd, 2018
*/

#include "hostname.h"

using namespace std; 

/*
 * Constructor for host name class
 * name: William Ruan
 * @param name of host, and length
 * @return
 * 
 */
hostName::hostName (char * newName, size_t length){
	name = newName;
	len = length;
}
/*
 * Destructor for host name class
 * name: William Ruan
 * 
 */
hostName::~hostName(){
}
/*
 * Gets host name
 * name: William Ruan
 * @return host name
 * 
 */
char * hostName::getName(){
	return name;
}
/*
 * Outputs data to user
 * name: William Ruan
 */
void hostName::toString(){
	if (gethostname(name, len) != 0)
		cout << "There has been an error." << endl;
	else
		cout << "The host name is " << getName() << "." << endl;
}

