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
	void DumpToFile() {
		std::ofstream errorFile("error_dump.txt", std::ios_base::app);
		if (errorFile) {
			errorFile << "Code Name: " << Codename << "\n";
			errorFile << "Code: " << Code << "\n";
			errorFile << "Critical: " << std::boolalpha << Critical << "\n";
			errorFile << "------------------------" << "\n";
			errorFile.close();
		}
	}
};

enum ErrorType {
	UNKNOWN_SYMBOL,                  // Unknown Character or Symbol
	IMPORTANT_DLL_CORRUPTED,         // Required dynamic-link library (DLL) is corrupted
	LACK_OF_AUTHORITY,               // Insufficient permissions for an operation
	INVALID_FILE_FORMAT,             // A file format is unrecognized or incompatible
	SYSTEM_RESOURCES_EXHAUSTED,      // The system ran out of a key resource (like memory)
	DEVICE_NOT_FOUND,                // A regular device (like a disk drive or printer) is not found or unexpectedly disconnect
	CRITICAL_DEVICE_NOT_FOUND,       // An Important device (Like Network or Display) is not found or unexpectedly disconnect
	IO_ERROR,                        // An error occurred in input/output operations
	SYSTEM_INTERRUPT,                // An operation was interrupted by a signal or other event
	KERNEL_ERROR,                    // An internal error in the operating system kernel
	UNKNOWN                          // Only use this if the error is unrecongizeable
};

enum HintType {
	OPTIMIZE_CPU_USAGE,             // Tips for optimizing CPU usage
	SAVE_BATTERY,                   // Tips for saving battery life
	INCREASE_SECURITY,              // Tips for improving system security
	FREE_UP_SPACE,                  // Tips for freeing up disk space
	BOOST_PERFORMANCE,              // Tips for boosting overall performance
	PROTECT_PRIVACY,                // Tips for protecting user's privacy
	REDUCE_EYE_STRAIN,              // Tips for reducing eye strain
	CUSTOMIZE_OS,                   // Tips for customizing the OS
	USE_KEYBOARD_SHORTCUTS,         // Tips for using keyboard shortcuts
	MAINTAIN_PC_HEALTH,             // Tips for maintaining overall PC health
	UNKNOWN_HINT                    // This is used as a backup
};


// Declaration of class members

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
void ShowHint(HintType hint = UNKNOWN_HINT) {
	switch (hint) {
	case OPTIMIZE_CPU_USAGE:
		Info("Consider running resource-intensive tasks in the background using '&' or with 'nice' to lower their priority.");
		break;
	case SAVE_BATTERY:
		Info("Disable unnecessary services, and consider using a minimal CLI-based OS to save battery.");
		break;
	case INCREASE_SECURITY:
		Info("Always update your system with the latest security patches. Be cautious when using root privileges.");
		break;
	case FREE_UP_SPACE:
		Info("Use commands like 'du' and 'df' to check disk usage. Consider cleanup with 'rm' and 'rmdir' for files and directories.");
		break;
	case BOOST_PERFORMANCE:
		Info("Keep your system up to date, and consider using performance monitoring tools like 'top' or 'htop'.");
		break;
	case PROTECT_PRIVACY:
		Info("Use secure communication protocols and consider encryption for sensitive data. Avoid transmitting private data unless necessary.");
		break;
	case REDUCE_EYE_STRAIN:
		Info("Consider using a CLI theme with a dark background and light text. Make sure to take breaks and look away from the screen regularly.");
		break;
	case CUSTOMIZE_OS:
		Info("Check out the man pages for various commands to learn about customization options. The 'alias' command is a great place to start.");
		break;
	case USE_KEYBOARD_SHORTCUTS:
		Info("Learning command line keyboard shortcuts can greatly speed up your workflow. Examples: Ctrl + A (beginning of line), Ctrl + E (end of line).");
		break;
	case MAINTAIN_PC_HEALTH:
		Info("Regularly check the system logs for any warnings or errors. Keep your system updated and avoid running unnecessary services.");
		break;
	case UNKNOWN_HINT:
		Info("This is a default hint. It seems you've found an unknown hint category.");
		break;
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
		CriticalError("We've detected the Host OS is attempting to terminate either the core OS or a subprocess of the OS that requires it to run. Make sure your host OS doesn't detect this as a threat", error9.Code, false);
		break;
	case KERNEL_ERROR:
		CriticalError("An unexpected Internalized kernel error appeared, OS cannot continue to run further. Sorry for your inconveinence from this", error10.Code, false);
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
