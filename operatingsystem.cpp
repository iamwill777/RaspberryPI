/*
 * @author William Ruan
 * @description This builds the object operatingsystem and its functions
 * @date October 3rd, 2018
*/

#include "operatingsystem.h"

using namespace std;

/*
 * Constructor for operatingsystem object
 * name: William Ruan
 * 
 */
operatingsystem::operatingsystem(struct utsname newName, struct sysinfo newInfo){
	name = newName;
	info = newInfo;
}

/*
 * Destructor for operatingsystem object
 * name: William Ruan
 * 
 */
operatingsystem::~operatingsystem(){
}

/*
 * Gets total uptime in seconds from sysinfo
 * name: William Ruan
 * @return total uptime
 * 
 */
long operatingsystem::getUptime(){
	if (sysinfo(&info) != 0)
		return 0;
	else
		return info.uptime;
}

/*
 * Gets system name from utsname
 * name: William Ruan
 * @return sysname
 * 
 */
char * operatingsystem::getSystemName(){
	return name.sysname;
}

/*
 * Gets release code from utsname
 * name: William Ruan
 * @return release
 * 
 */
char * operatingsystem::getRelease(){
	return name.release;
}

/*
 * Gets machine version from utsname
 * name: William Ruan
 * @return version
 * 
 */
char * operatingsystem::getVersion(){
	return name.version;
}

/*
 * Gets machine code from utsname
 * name: William Ruan
 * @return machine
 * 
 */
char * operatingsystem::getMachine(){
	return name.machine;
}

/*
 * Outputs operating system data to user
 * name: William Ruan
 * 
 */
void operatingsystem::toString(){
	// Gets system information as long as its available
	if (uname(&name) != 0)
		printf("There has been an error.");
	else{
		printf("System Name = %s\n", getSystemName());
		printf("Release = %s\n", getRelease());
		printf("Version = %s\n", getVersion());
		printf("Machine = %s\n", getMachine());
		// Retrieves uptime and outputs in days, hours, minutes, seconds
		long uptime = getUptime();
		int format [4];
		int * printUptime = formatUptime(uptime, format);
		printf("Days Up = %d days\n", *(printUptime));
		printf("Hours Up= %d hours\n", *(printUptime + 1));
		printf("Minutes Up= %d minutes\n", *(printUptime + 2));
		printf("Seconds Up= %d seconds\n", *(printUptime + 3));
	}
}

/*
 * Helper function to divide uptime into days, hours, minutes and seconds
 * name: William Ruan
 * @param the uptime in seconds and a blank int array
 * @return pointer to the array
 * 
 */
int * operatingsystem::formatUptime(long uptime, int format []){
	int newUptime = 0;
	// Divides and mods the seconds into days, then hours, then minutes and finally seconds
	format[0] = uptime / DAY;
	newUptime = uptime % DAY;
	format[1] = newUptime / HOUR;
	newUptime = uptime % HOUR;
	format[2] = newUptime / MINUTE;
	newUptime = uptime % MINUTE;
	format[3] = newUptime;
	// Returns pointer
	return format;
}


