#include <iostream>
#include <limits>
#include <iomanip>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <algorithm>
#include "ImportantMessages.h"
bool Scheduledshutdown = false;
int Counter = 0;
bool High_Permission = false;
bool RanCommand = false;
std::string PasswordA = "NaP";
std::string UserA;
std::string Runablecommand = "Non HR perms:\ncalculator-permissions\nHR perms:\ngivepermissions-logininfo-update";
std::string VersionA = "V0.0.7 RC";
std::string Credit = "OperatorOS\nDesigned by Rayan\nCreated by Rayan\nConcept by Rayan\nThank you for using this Applications";
bool Find(const std::string& input, const std::string& searchTerm) {
	// Perform case-insensitive search
	std::string lowercaseInput = input;
	std::string lowercaseSearchTerm = searchTerm;
	std::transform(lowercaseInput.begin(), lowercaseInput.end(), lowercaseInput.begin(), ::tolower);
	std::transform(lowercaseSearchTerm.begin(), lowercaseSearchTerm.end(), lowercaseSearchTerm.begin(), ::tolower);

	// Use std::string find() function to search for the term
	if (lowercaseInput.find(lowercaseSearchTerm) != std::string::npos) {
		return true;  // Found the term
	}

	// Search not found
	return false;
}


class Userspec {
private:
	std::string name;
	std::string pass;
	bool isAdmin;

public:
	Userspec(const std::string& Aname, const std::string& Apass, bool Aadmin) :
		name(Aname), pass(Apass), isAdmin(Aadmin) {
	}

	// Getter methods
	std::string getName() const {
		return name;
	}

	std::string getPass() const {
		return pass;
	}

	bool isAdminUser() const {
		return isAdmin;
	}

	// Setter methods, if needed
	void setName(const std::string& newName) {
		name = newName;
	}

	void setPass(const std::string& newPass) {
		pass = newPass;
	}

	void setAdmin(bool newAdmin) {
		isAdmin = newAdmin;
	}
};



std::string Com = "chelp-help-run-hp-credits-about-test";
bool promptYesorNoA(std::string text) {
	bool YesorNo = false;
	std::string value;
	
	do {

		std::cout << text << std::endl;
		std::cout << "Would you like to continue\nWARNING: use Y or N or else you will get an error on this version\nEnter the option below\nOption: ";
		std::cin >> value;


		


		if (value == "y") {
		
			YesorNo = true; 
		
		}

		if (value == "n") {
			
			
			YesorNo = false; 
		
		
		}

	} while (value != "y" && value != "n");




	return YesorNo;

}
int test() {
	std::cout << "Hello, world" << std::endl;
	return(0);
}

int about() {
	std::cout << VersionA << std::endl;
	return(0);
}
void syscom() {

	

}

int credits() {
	std::cout << Credit << std::endl;

	return(0);
}

int hp() {
	
	bool HP_finished = false;
	
	if (Counter < 3) {
		if (High_Permission == false) {
			std::string Submittedpassword;
			std::cout << "Before we give you High permissions we need to know if this is you\nPassword: ";
			std::cin >> Submittedpassword;
			if (Submittedpassword == PasswordA) {

				High_Permission = true;
				std::cout << std::endl << "Authorized!\nMake sure to remove High permission by running the command again after using for your security as this can be used to destory your OS" << std::endl;
				HP_finished = true;
			}
			else {
				Counter = Counter + 1;
				std::cout << std::endl << "SECURITY ERROR: For some reason you haven't authorized to use this machine please log out and be in correct user to be authorized" << std::endl;

			}
		}
	}
	else {

		std::cout << "Please try again later" << std::endl;

	}
	if (High_Permission == true and HP_finished == false) {

		std::cout << "High Perms are now false, you may continue on your work" << std::endl;

		High_Permission = false;

	}


	return(0);
}
void runAd(std::string Program) {




}
int run() {
	std::cout << "What do you want to run?" << std::endl;
	std::string CommandsA;
	std::cout << Runablecommand << std::endl;
	std::cin >> CommandsA;
	bool Sentcommand = false;

	if (CommandsA == "exit") {

		Sentcommand = true;
		return(0);
	}
	if (CommandsA == "calculator") {
		bool Dividedby0{};
		std::string Operation = "";
		std::string Dividedby0string = "infinity";
		int value1 = NULL;
		int value2 = NULL;
		int results = NULL;
		
		std::cout << "Options: * - / +\nOperation?\n";
		std::cin >> Operation;

		std::cout << std::endl << "First value\n";
		std::cin >> value1;

		std::cout << std::endl << "Second value\n";
		std::cin >> value2;

		if (Operation == "*") {

			results = value1 * value2;

		}
		if (Operation == "/") {
			if (value2 == 0) {

				Dividedby0 = true;

			}
			else {
				results = value1 / value2;
			}
		}
		if (Operation == "-") {

			results = value1 - value2;

		}
		if (Operation == "+") {

			results = value1 + value2;

		}
		
		if (Dividedby0 == true) {
			std::cout << std::endl << Dividedby0string << std::endl;
			std::cout << "OH NO WHY YOU DIVIDED BY ZERO I AM GOING TO EXPLODEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE" << std::endl;
		}
		else {

			std::cout << std::endl << results << std::endl;
		}

		Sentcommand = true;
	}
	if (CommandsA == "permissions") {
		
		std::cout << "works" << std::endl;
		Sentcommand = true;
	}
	if (CommandsA == "givepermissions") {
		if (!High_Permission) {
			ErrorHandler(LACK_OF_AUTHORITY);
		}
		else {
			std::cout << "works" << std::endl;
			Sentcommand = true;
		}
	}
	if (CommandsA == "logininfo") {
		
		if (!High_Permission) {
			ErrorHandler(LACK_OF_AUTHORITY);
		}
		else {
			std::cout << "works" << std::endl;
			Sentcommand = true;
		}
	}
	if (CommandsA == "update") {
		
		if (!High_Permission) {
			ErrorHandler(LACK_OF_AUTHORITY);
		}
		else {
			std::cout << "works" << std::endl;
			Sentcommand = true;
		}
	}
	if (Sentcommand == false) {

		std::cout << "ERROR: Either you did not type anything, sent a invalid Command or user doesn't have permissions to run it\nplease make sure that the command is available and HP permissions are true before sending the same command" << std::endl;

	}

	RanCommand = Sentcommand;

	return(0);
}

int help() {

	std::cout << "QnA\nQ: How do we add applications\nA: You could but you need to have access to the source files which we have open source so add any function that seems fit\nQ: Why do some applications say they are under development\nA: Because these applicatons are planned in the future\nThat's it (if you want to know where to ask these question send them in the Github as a issue)" << std::endl;

	return(0);

}

int chelp() {

	std::cout << "These are the commands (these dashes are spaces)\n" << Com << std::endl;
	

	return(0);
}

void errortest() {
	std::string Output;
	std::cout << "What type of error" << std::endl;
	std::cin >> Output;
	if (Output == "symbol") { ErrorHandler(UNKNOWN_SYMBOL); }
	else if (Output == "dll") { ErrorHandler(IMPORTANT_DLL_CORRUPTED); }
	else if (Output == "authority") { ErrorHandler(LACK_OF_AUTHORITY); }
	else if (Output == "filetype") { ErrorHandler(INVALID_FILE_FORMAT); }
	else if (Output == "resource") { ErrorHandler(SYSTEM_RESOURCES_EXHAUSTED); }
	else if (Output == "device_r") { ErrorHandler(DEVICE_NOT_FOUND); }
	else if (Output == "device_c") { ErrorHandler(CRITICAL_DEVICE_NOT_FOUND); }
	else if (Output == "io") { ErrorHandler(IO_ERROR); }
	else if (Output == "interrupt") { ErrorHandler(SYSTEM_INTERRUPT); }
	else if (Output == "kernel") { ErrorHandler(KERNEL_ERROR); }
	else { ErrorHandler(); }

}

int CommandLibary(std::string Program) {
	
	bool Basicprogram_ran = false;

	if (RanCommand == true and Counter > 1) {

		Counter = Counter - 1;
		RanCommand = false;
	}
	
	// If you want to you can add a program here or in run function but be careful to not break other commands
	// if (Program == "") {}

	if (Program == "testerror") {
		errortest();
	}
	
	if (Program == "test") {

		test();
		return(0);
		Basicprogram_ran = true;
	}

	if (Program == "about") {
	
		about();
		return(0);
		Basicprogram_ran = true;
	}
	if (Program == "hp") {
	
		hp();
		return(0);
		Basicprogram_ran = true;
	}
	if (Program == "run") {
		run();
		return(0);
		Basicprogram_ran = true;
	}
	if (Program == "help") {
		help();
		return(0);
		Basicprogram_ran = true;
	}
	if (Program == "chelp") {
		chelp();
		return(0);
		Basicprogram_ran = true;
	}
	if (Program == "credits") {
		credits();
		return(0);
		Basicprogram_ran = true;

	}
	if (Program == "clear") {

		system("CLS");

	}
	if (Program == "shutdown") {
		
		bool NoworLater;
		if (!Scheduledshutdown) {
			std::cout << "Do you want to shutdown now or after 30 seconds you can always stop the shutdown" << std::endl;
			NoworLater = promptYesorNoA("WARNING: SHUTDOWN WILL CAUSE YOUR COMPUTER TO TURN OFF SO MAKE SURE TO USE THIS ONLY AS A EXAMPLE FOR YOUR INFOMATION\n\nYou have been warned");
			if (NoworLater) {

				system("C:\\Windows\\System32\\shutdown /s /t 0");
				std::cout << "shutting down...";
			}
			else {

				system("C:\\Windows\\System32\\shutdown /s");
				Scheduledshutdown = true;
				std::cout << "shutting down at 30 seconds" << std::endl;
			}
		}
		else {

			system("C:\\Windows\\System32\\shutdown /a");
			std::cout << "Shutdown cancelled" << std::endl;
			Scheduledshutdown = false;
		}
	}
	if (Program == "restart") {
		bool NoworLater;
		if (!Scheduledshutdown) {

			std::cout << "Do you want to restart now or after 30 seconds you can always stop the restart" << std::endl;
			NoworLater = promptYesorNoA("WARNING: SHUTDOWN WILL CAUSE YOUR COMPUTER TO TURN OFF SO MAKE SURE TO USE THIS ONLY AS A EXAMPLE FOR YOUR INFOMATION\n\nYou have been warned");
			if (NoworLater) {

				system("C:\\Windows\\System32\\shutdown /r /t 0");
				std::cout << "shutting down...";
			}
			else {

				system("C:\\Windows\\System32\\shutdown /r");
				Scheduledshutdown = true;
				std::cout << "shutting down at 30 seconds" << std::endl;
			}

		}
		else {

			system("C:\\Windows\\System32\\shutdown /a");
			std::cout << "Shutdown cancelled" << std::endl;
			Scheduledshutdown = false;
		}

	}
	if (Basicprogram_ran == true) {

		RanCommand = true;

	}
	Program = "";
	
	return(0);
	

}