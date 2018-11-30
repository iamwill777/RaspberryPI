/*
 * @author William Ruan
 * @description This is the header file for operatingsystem
 * @date October 3rd, 2018
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sys/utsname.h>
#include <sys/sysinfo.h>

// Declares operatingsystem class
class operatingsystem{
	private:
		// Helper variables for uptime
		const int MINUTE = 60;
		const int HOUR = 60 * 60;
		const int DAY = HOUR * 24;
		struct sysinfo info;
		struct utsname name;
	public:
		// Constructor for operatingsystem object
		operatingsystem(struct utsname, struct sysinfo);
		// Destructor
		~operatingsystem();
		// Gets uptime, and operating system data
		long getUptime();
		char * getSystemName();
		char * getRelease();
		char * getVersion();
		char * getMachine();
		// Returns data to user
		void toString ();
		// Helper function to format uptime
		int * formatUptime(long uptime, int format []);
};		
