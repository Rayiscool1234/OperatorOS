#include <iostream>
#include <limits>
#include <iomanip>
#include <string>
#include <fstream>



class Error {

public:
	std::string Codename;
	std::string Code;

	bool Critical;
	Error(std::string Acodename, std::string Acode, bool Acritical) {

		Code = Acode;
		Codename = Acodename;
		Critical = Acritical;

	}
};

// Error zone

Error error1("SYMBOL_WITHOUT_EXCEPTION", "CE_0001", true);
Error error2("IMPORTANT_DLL_CORRUPTED", "CE_0002", true);
Error error3("", "", NULL);
Error error4("", "", NULL);
Error error5("", "", NULL);
Error error6("", "", NULL);
Error error7("", "", NULL);
Error error8("", "", NULL);
Error error9("", "", NULL);


void Info(std::string Message) {

	std::cout << "Here is a tip!\n" << Message << std::endl;
	

}

int Warning(std::string Message) {

	std::cout << "WARNING: " << Message << std::endl;

	return(0);
}

int BasicError(std::string Message, std::string Errortype) {

	std::cout << "ERROR: " << Errortype << Message << std::endl;
	return(0);
}

int CriticalError(std::string Message, std::string Errortype, bool Recoverable) {


	if (!Recoverable) {

		std::cout << std::endl << std::endl << std::endl << std::endl;
		std::cout << "You ran into a error impossible to fix\nthis is some info about the error" << std::endl << Errortype << std::endl << Message << std::endl << "Press any key to continue";
		std::cin.ignore();
		std::exit(EXIT_FAILURE);

	}
	else {
		std::cout << std::endl << std::endl << std::endl << std::endl;
		std::cout << "Luckily this critical error isn't impossible to fix but all other processes must be stopped before continuing" << std::endl << Errortype << std::endl << Message << std::endl << "Press any key to continue" << std::endl;
		std::cin.ignore();
	}
	return(0);
}



int ErrorHandler(std::string Errortype) {


	if (Errortype == "unknown_symbol") {

		CriticalError(error1.Codename, error1.Code, error1.Critical);

	}
	
	return(0);

}