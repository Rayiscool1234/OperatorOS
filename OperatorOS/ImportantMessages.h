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

enum ErrorType {
    UNKNOWN_SYMBOL,
    IMPORTANT_DLL_CORRUPTED
};

// Error zone
Error error1("SYMBOL_WITHOUT_EXCEPTION", "CE_0001", true);
Error error2("IMPORTANT_DLL_CORRUPTED", "CE_0002", true);
Error error3("", "", false);
Error error4("", "", false);
Error error5("", "", false);
Error error6("", "", false);
Error error7("", "", false);
Error error8("", "", false);
Error error9("", "", false);

void Info(std::string Message) {
    std::cout << "Here is a tip!\n" << Message << std::endl;
}

void Warning(std::string Message) {
    std::cout << "WARNING: " << Message << std::endl;
}

void BasicError(std::string Message, std::string Errortype) {
    std::cout << "ERROR: " << Errortype << " " << Message << std::endl;
}

void CriticalError(std::string Message, std::string Errortype, bool Recoverable) {
    if (!Recoverable) {
        std::cout << "\n\n\n\nYou ran into a error impossible to fix\nthis is some info about the error" << std::endl << Errortype << std::endl << Message << std::endl << "Press any key to continue";
        std::cin.ignore();
        std::exit(EXIT_FAILURE);
    }
    else {
        std::cout << "\n\n\n\nLuckily this critical error isn't impossible to fix but all other processes must be stopped before continuing" <<
        std::endl << Errortype << std::endl << Message << std::endl << "Press any key to continue" << std::endl;
        std::cin.ignore();
    }
}

void ErrorHandler(ErrorType Errortype) {
    switch (Errortype) {

    case UNKNOWN_SYMBOL:
        CriticalError("You've inputted an unsupported character which caused major fatal error to occur", error1.Code, true);
        break;
    case IMPORTANT_DLL_CORRUPTED:
        CriticalError("For some unknown reason one of the critical DLL files used by OperatorOS has been corrupted beyond repair. You must fix this.", error2.Code, false);
        break;
    default:

        break;
    }
    // you can add more error types here
    // case >ERROR<:
    //
    // 
}
