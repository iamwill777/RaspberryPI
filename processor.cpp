/*
 * @author William Ruan
 * @description This builds the object processor and its functions
 * @date October 3rd, 2018
*/

#include "processor.h"

using namespace std;

/*
 * Constructor for processor object
 * name: William Ruan
 * 
 */
processor:: processor(struct sysinfo newInfo){
	info = newInfo;
}

/*
 * Destructor for processor object
 * name: William Ruan
 * 
 */
 processor:: ~processor(){
}

/*
 * Gets load average for one minute
 * name: William Ruan
 * @return load average for one minute
 * 
 */
unsigned long processor:: getOneMinute(){
	return info.loads[0];
}

/*
 * Gets load average for five minutes
 * name: William Ruan
 * @return load average for five minutes
 * 
 */
unsigned long processor:: getFiveMinutes(){
	return info.loads[1];
}

/*
 * Gets load average for fifteen minutes
 * name: William Ruan
 * @return load average for fifteen minutes
 * 
 */
unsigned long processor:: getFifteenMinutes(){
	return info.loads[2];
}

/*
 * Gets vendor for processor
 * name: William Ruan
 * @return vendor for processor
 * 
 */
std::string processor:: getVendor(){
	return vendor;
}

/*
 * Gets model name for processor
 * name: William Ruan
 * @return model name for processor
 * 
 */
std::string processor:: getModelName(){
	return modelName;
}

/*
 * Gets clock speed for processor
 * name: William Ruan
 * @return clock speed for processor
 * 
 */
std::string processor:: getClockSpeed(){
	return clockSpeed;
}

/*
 * Outputs all the processor data to user
 * name: William Ruan
 * 
 */
void processor::toString(){
	// Outputs load averages
	if (sysinfo(&info) != 0)
		cout << "Error cannot get load averages." << endl;
	else{
		cout << "1 Minute Load Average: " << getOneMinute() << endl;
		cout << "5 Minute Load Average: " << getFiveMinutes() << endl;
		cout << "15 Minute Load Average: " << getFifteenMinutes() << endl;
	}
	// Calls helper method
	openFile();
	// Outputs processor information
	cout << vendor << endl;
	cout << modelName << endl;
	cout << clockSpeed << endl;
}

/*
 * Opens file and gets values from it
 * name: William Ruan
 * 
 */
void processor:: openFile(){
	// Gets file
	ifstream file("/proc/cpuinfo");
	string line;
	// Gets appropriate values from file
	if (file.is_open()){
		for (int i = 0; getline (file,line) && i < 8; i++){
			if (i== 1)
				vendor = line;
			else if (i == 4)
				modelName = line;
			else if (i == 6)
				clockSpeed = line;
		}
		// Close file
		file.close();
	}
}

