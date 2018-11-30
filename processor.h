/*
 * @author William Ruan
 * @description This is the header file for processor
 * @date October 3rd, 2018
*/

#include <fstream>
#include <iostream>
#include <string>
#include <sys/sysinfo.h>

// Declares new processor class
class processor{
	private:
		// Helper method to open file
		void openFile ();
		struct sysinfo info;
		// Processor information
		std::string vendor; 
		std::string modelName;
		std::string clockSpeed;
	public:
		// Constructor for processor object
		processor(struct sysinfo);
		// Destructor for processor object
		~processor();
		// Gets CPU Info and clock speed
		unsigned long getOneMinute();
		unsigned long getFiveMinutes();
		unsigned long getFifteenMinutes();
		std::string getVendor();
		std::string getModelName();
		std::string getClockSpeed();
		// Outputs to user
		void toString ();
};		
