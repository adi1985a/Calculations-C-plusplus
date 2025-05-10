#pragma once
#include <string>
#include <fstream>
#include <ctime>

namespace Utils {
    void clearScreen() {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    }

    void logError(const std::string& error) {
        std::ofstream logFile("error_log.txt", std::ios::app);
        time_t now = time(0);
        logFile << ctime(&now) << error << "\n";
        logFile.close();
    }

    bool isValidNumber(const std::string& str) {
        return !str.empty() && str.find_first_not_of("0123456789") == std::string::npos;
    }
}
