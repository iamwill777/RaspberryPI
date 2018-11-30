/*
 * @author William Ruan
 * @description This is the main menu file for all the utilities
 * @date October 3rd, 2018
*/

#include <cstdlib>
#include "hostname.h"
#include "operatingsystem.h"
#include "processor.h"
#include "memory.h"
#include "networkinterfacelist.h"
#include "networkinterface.h"
#include "processlist.h"
#include "process.h"

// Main program
// Combines all utilities together
int main(){
	int option;
	bool cont = true;
	std::cout << "This is a program that gives information about the Raspberry PI System." << std::endl;
	// Options for output
	// Continues until user quits with 7
	while (cont){
		std::cout << "Please enter 1 for host name information." << std::endl;
		std::cout << "Please enter 2 for operating system information." << std::endl;
		std::cout << "Please enter 3 for processor information." << std::endl;
		std::cout << "Please enter 4 for memory information." << std::endl;
		std::cout << "Please enter 5 for network interface information." << std::endl;
		std::cout << "Please enter 6 for processes information." << std::endl;
		std::cout << "Please enter 7 to quit." << std::endl;
		std::cin >> option;
		// Clears screen
		system("clear");
		if (option == 7)
			cont = false;
		// Outputs host name data
		else if(option == 1){
			std::cout << "Here is the requested information:" << std::endl;
			char hostname[HOST_NAME_MAX];
			hostName newHost(hostname, HOST_NAME_MAX);
			newHost.toString();
			std::cout << std::endl;
		}
		// Outputs operating system data
		else if(option == 2){
			std::cout << "Here is the requested information:" << std::endl;
			// Declares the two structures
			struct utsname name;
			struct sysinfo info;
			// Creates new object and returns data to user
			operatingsystem newOS(name, info);
			newOS.toString();
			std::cout << std::endl;
		}
		// Outputs processor information
		else if(option == 3){
			std::cout << "Here is the requested information:" << std::endl;
			// Creates new processor object and outputs data to user
			struct sysinfo info;
			processor newProcess(info);
			newProcess.toString();
			std::cout << std::endl;
		}
		// Outputs information on memory
		else if(option == 4){
			std::cout << "Here is the requested information:" << std::endl;
			struct sysinfo info;
			memory newMemory(info);
			newMemory.toString();
			std::cout << std::endl;
		}
		// Outputs information on network interfaces
		else if(option == 5){
			std::cout << "Here is the requested information:" << std::endl;
			// Gets list of network interfaces
			std::string str = "/sys/class/net";
			const char * directory = (str).c_str();
			DIR * dir = opendir(directory);
			networkinterfacelist newList (dir);
			newList.toString();
			// Gets the specific MAC address for each network interface
			const char * address;
			std::vector<std::string> list = newList.getNetworkList();
			for (unsigned i = 0; i < list.size(); i++){
				// Creates new address
				str = "/sys/class/net/" + list.at(i) + "/address";
				address = (str).c_str();
				// Creates new networkinterface object
				networkinterface mac (address, list.at(i));
				// Outputs MAC address for both network interfaces
				mac.toString();
			}
			std::cout << std::endl;
		}
		// Outputs information on active processes
		else if(option == 6){
			std::cout << "Here is the requested information:" << std::endl;
			// Gets list of process IDs
			std::string str = "/proc";
			const char * directory = (str).c_str();
			DIR * dir = opendir(directory);
			processlist newList (dir);
			newList.toString();
			// Gets the name, owner UID, parent process ID and state of each process
			const char * address;
			std::vector<std::string> list = newList.getProcesses();
			for (unsigned i = 0; i < list.size(); i++){
				// Creates new address
				str = "/proc/" + list.at(i) + "/status";
				address = (str).c_str();
				// Creates new process object
				process info (address, list.at(i));
				// Outputs data for all the processes
				info.toString();
			}
			std::cout << std::endl;
		}
		// If number is invalid it prompts user to reenter number
		else{
			std::cout << "Number is not valid, please try again: " << std::endl;
		}
	}
	// Exits
	std::cout << "Thank you for using this program. " << std::endl;
}
