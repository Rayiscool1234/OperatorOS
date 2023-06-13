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
    UNKNOWN_SYMBOL,                  // Unknown Character or Symbol
    IMPORTANT_DLL_CORRUPTED,         // Required dynamic-link library (DLL) is corrupted
    LACK_OF_AUTHORITY,               // Insufficient permissions for an operation
    INVALID_FILE_FORMAT,             // A file format is unrecognized or incompatible
    SYSTEM_RESOURCES_EXHAUSTED,      // The system ran out of a key resource (like memory)
    DEVICE_NOT_FOUND,                // A regular device (like a disk drive or printer) is not found
    CRITICAL_DEVICE_NOT_FOUND,       // An Important device (Like Network or Display) is not found or unexpectedly disconnect
    IO_ERROR,                        // An error occurred in input/output operations
    SYSTEM_INTERRUPT,                // An operation was interrupted by a signal or other event
    KERNEL_ERROR,                    // An internal error in the operating system kernel
    UNKNOWN
};


Error error1("UNKNOWN_SYMBOL", "CE_0001", true);
Error error2("IMPORTANT_DLL_CORRUPTED", "CE_0002", true);
Error error3("LACK_OF_AUTHORITY", "W_0001", false);
Error error4("INVALID_FILE_FORMAT", "E_0002", false);
Error error5("SYSTEM_RESOURCES_EXHAUSTED", "CE_0003", true);
Error error6("DEVICE_NOT_FOUND", "W_0001", false);
Error error7("CRITICAL_DEVICE_NOT_FOUND", "CE_0004", true);
Error error8("IO_ERROR", "E_0003", false);
Error error9("SYSTEM_INTERRUPT", "CE_0005", true);
Error error10("KERNEL_ERROR", "CE_0006", true);
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
        std::cout << "\n\n\n\nYou ran into a error impossible to fix\nthis is some info about the error" << std::endl << Errortype << std::endl << Message << std::endl << "Press Enter to continue";
        std::cin.get();

        std::exit(EXIT_FAILURE);
    }
    else {
        std::cout << "\n\n\n\nLuckily this critical error isn't impossible to fix but all other processes must be stopped before continuing" <<
        std::endl << Errortype << std::endl << Message << std::endl << "Press enter to continue" << std::endl;
        std::cin.get();
    }
}

void ErrorHandler(ErrorType Errortype = UNKNOWN) {
    switch (Errortype) {

    case UNKNOWN_SYMBOL:
        CriticalError("You've inputted an unsupported character which caused major fatal error to occur", error1.Code, true);
        break;
    case IMPORTANT_DLL_CORRUPTED:
        CriticalError("For some unknown reason one of the critical DLL files used by OperatorOS has been corrupted beyond repair. You must fix this before starting the OS again", error2.Code, false);
        break;
    case LACK_OF_AUTHORITY:
        Warning("You don't have any permissions you run this process. Make sure to run it again with apporiate permissions");
        break;
    case INVALID_FILE_FORMAT:
        BasicError("The file you gave is either corrupted or Unsupported by OperatorOS. Please try again with another file.", error4.Code);
        break;
    case SYSTEM_RESOURCES_EXHAUSTED:
        CriticalError("Resources are limited to the point where the OperatorOS cannot continue running. Please run this again after you have enough memory.", error5.Code, false);
        break;
    case DEVICE_NOT_FOUND:
        Warning("UNEXPECTED Disconnect from a device. Was this intentional or this is a potential point of more Severe Errors to come");
        break;
    case CRITICAL_DEVICE_NOT_FOUND:
        CriticalError("UNEXPECTED Disconnect from a device. Loss of this device will result in sudden termination of the OS to protect itself", error7.Code, true);
        break;
    case IO_ERROR:
        BasicError("One of your I/O ports are causing unexpected behavior. Investigate this to prevent a severe error from developing", error8.Code);
        break;
    case SYSTEM_INTERRUPT:
        CriticalError("Something is attempting to end the OS session. This is SEVERELY BAD and you should deal with it immediately!", error9.Code, false);        
        break;
    case KERNEL_ERROR:
        CriticalError("An unexpected kernel appeared, OS cannot continue to run further. Sorry for your inconveinence from this", error10.Code, false);
        break;
    default:
        CriticalError("UNKNOWN ERROR! PROCEED WITH CAUTION", "UE", true);
        break;
    }
    /* you can add more error types here
      case >ERROR<:
        Whatever would happen here
        break;
    */
}
