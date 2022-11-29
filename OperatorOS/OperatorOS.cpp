#include <iostream>
#include <limits>
#include <iomanip>
#include <string>
#include <fstream>
#include "UserCredentials.txt"
#include "Libcom.h" 

bool Debug = true;
bool Skip = false;
bool ExitNotice = false;
bool ExitRequest = false;
std::string Version = "V0.0.7 RC";
std::string User;
std::string Password;


int welcome() {

	std::cout << "Welcome to OperatorOS " << Version << std::endl;
	std::cout << "it seems like you are new, we will sign you up\nplease wait" << std::endl;
	std::string output;
	bool wantSkip;
	std::cout << "Skip?" << std::endl;
	std::cin >> output;
	if (output == "y") {
		wantSkip = true;

	}
	else {

		wantSkip = false;

	}
	if (Debug && wantSkip) {

		Skip = true;
		User = "Tester";
		Password = "a";
	}

	return(0);


}
bool promptYesorNo(std::string text) {
	bool YesorNo = false;
	std::string value;

	do {

		std::cout << text << std::endl;
		std::cout << "Would you like to continue with this infomation\nWARNING: use Y or N or else you will get an error on this version\nEnter the option below\nOption: ";
		std::cin >> value;


		for (int i = 0; 1 < value.length(); i++) value[i] = tolower(value[i]);

		
		if (value == "y") YesorNo = true;
		if (value == "n") YesorNo = false;

	} while(value != "y" && value != "n");




	return YesorNo;

}

int Bootup() {


	std::cout << "Installing files" << std::endl;
	
	std::cout << "Installation Completed" << std::endl;
	
	std::cout << "Verifying" << std::endl;
	
	std::cout << "Verification Complete" << std::endl;
	std::cout << "Booting." << std::endl;
	
	std::cout << "Booting.." << std::endl;
	
	std::cout << "Booting..." << std::endl;
	
	std::cout << "Booting...." << std::endl;
	
	std::cout << "Booting....."<< std::endl;

	return(0);


}

int Commandline() {
	std::string Command;
	do {
		do {



			std::cout << User << ">> ";
			std::cin >> Command;


			if (Command == "exit") {

				ExitNotice = true;

			}





		} while (Command.empty() == 1);
	
		CommandLibary(Command);
		Command = "";
	} while (ExitNotice == false);

	ExitRequest = true;
	
	return(0);

}

int Desktop() {

	
	std::cout << "Welcome, " << User << ". We thank you for using our OS." << std::endl;

	std::cout << "If you were wondering how to run programs it is simple\nyou can just do chelp Command to see what available programs are\nor you can do help for QnA" << std::endl;

	do {



		Commandline();


	} while (ExitRequest == false);



	exit(EXIT_SUCCESS);

	return(0);
}


int Usersave() {



	std::cout << "Saving Credentials" << std::endl;
	std::cout << "saved Credentials" << std::endl;
	PasswordA = Password;
	UserA = User;
	
	Userspec User`(User, Password, true);
		


	std::ofstream UserCredentials("UserCredentials.txt");
	if (UserCredentials.is_open())
	{
		UserCredentials << User + "\n";
		UserCredentials << Password;
		UserCredentials.close();

		return(0);



	}

	

	return(0);
}


int Usersignup() {
	bool YesorNo = false;
	if (Skip) {


	}
	else {
		do {
			std::cout << "Please Enter you Username" << std::endl;
			std::cout << "Username: ";
			std::getline(std::cin, User);
			std::cout << std::endl << "Please Enter a easy to remember and secure password as you can't change later" << std::endl;
			std::cout << std::endl << "Password: ";
			std::cin >> Password;
			std::cout << std::endl;

			YesorNo = promptYesorNo(User);


		} while (YesorNo != true);



		
	}
	Usersave();

	return(0);


}


int Usersignin() {








	return(0);


}

int main() {
	std::cout << "WARNING: THESE APPLICATIONS OR BOOTUP ARE NOT FINISHED PRODUCT" << std::endl;
	
	Bootup();
	welcome();

	

	Usersignup();

	Desktop();

	
}




