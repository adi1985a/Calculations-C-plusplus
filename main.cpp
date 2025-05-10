#include <iostream>
#include <iomanip>
#include <limits>
#include "utils.h"

using namespace std;

// Function prototypes
void displayMenu();
void calculateSalary();
void calculateTicketSales();
void calculateClassPercentages();
void calculateCinemaProfit();
void convertTime();
void saveResults(const string& result);

int main() {
    char choice;
    do {
        displayMenu();
        cin >> choice;
        Utils::clearScreen();
        
        try {
            switch(choice) {
                case '1': calculateSalary(); break;
                case '2': calculateTicketSales(); break;
                case '3': calculateClassPercentages(); break;
                case '4': calculateCinemaProfit(); break;
                case '5': convertTime(); break;
                case '0': cout << "Exiting program...\n"; break;
                default: cout << "Invalid choice!\n";
            }
        } catch (const exception& e) {
            Utils::logError(e.what());
            cout << "An error occurred: " << e.what() << endl;
        }
        
        if (choice != '0') {
            cout << "\nPress any key to continue...";
            cin.ignore();
            cin.get();
        }
    } while (choice != '0');
    
    return 0;
}

void displayMenu() {
    cout << "+--------------------------------+\n";
    cout << "|           PROGRAM MENU         |\n";
    cout << "+--------------------------------+\n";
    cout << "| 1. Calculate Salary            |\n";
    cout << "| 2. Stadium Ticket Sales        |\n";
    cout << "| 3. Class Gender Percentages    |\n";
    cout << "| 4. Cinema Profit Calculator    |\n";
    cout << "| 5. Time Converter             |\n";
    cout << "| 0. Exit                       |\n";
    cout << "+--------------------------------+\n";
    cout << "Enter your choice: ";
}

void calculateSalary() {
    double hours, rate;
    cout << "=== Salary Calculator ===\n\n";
    
    do {
        cout << "Enter hours worked: ";
        cin >> hours;
    } while (hours < 0);
    
    do {
        cout << "Enter hourly rate (NOK): ";
        cin >> rate;
    } while (rate < 0);
    
    double salary = hours * rate;
    string result = "Salary calculation: " + to_string(salary) + " NOK";
    saveResults(result);
    
    cout << fixed << setprecision(2);
    cout << "\nSalary: " << salary << " NOK\n";
}

void calculateTicketSales() {
    int classA = 0, classB = 0, classC = 0;
    cout << "=== Stadium Ticket Sales Calculator ===\n\n";
    
    cout << "Enter number of Class A tickets (15 NOK): ";
    cin >> classA;
    cout << "Enter number of Class B tickets (12 NOK): ";
    cin >> classB;
    cout << "Enter number of Class C tickets (9 NOK): ";
    cin >> classC;
    
    double total = (classA * 15) + (classB * 12) + (classC * 9);
    cout << "\nTotal revenue: " << total << " NOK\n";
    saveResults("Ticket sales: " + to_string(total) + " NOK");
}

void calculateClassPercentages() {
    int boys = 0, girls = 0;
    cout << "=== Class Gender Distribution Calculator ===\n\n";
    
    cout << "Enter number of boys: ";
    cin >> boys;
    cout << "Enter number of girls: ";
    cin >> girls;
    
    int total = boys + girls;
    double boysPercent = (boys * 100.0) / total;
    double girlsPercent = (girls * 100.0) / total;
    
    cout << fixed << setprecision(2);
    cout << "\nBoys: " << boysPercent << "%\n";
    cout << "Girls: " << girlsPercent << "%\n";
    
    saveResults("Class percentages - Boys: " + to_string(boysPercent) + "%, Girls: " + to_string(girlsPercent) + "%");
}

void calculateCinemaProfit() {
    int adult = 0, children = 0;
    cout << "=== Cinema Profit Calculator ===\n\n";
    
    cout << "Enter number of adult tickets (10 NOK): ";
    cin >> adult;
    cout << "Enter number of children tickets (6 NOK): ";
    cin >> children;
    
    double grossProfit = (adult * 10) + (children * 6);
    double netProfit = grossProfit * 0.2;
    double distributor = grossProfit * 0.8;
    
    cout << fixed << setprecision(2);
    cout << "\nGross profit: " << grossProfit << " NOK\n";
    cout << "Net profit: " << netProfit << " NOK\n";
    cout << "Distributor share: " << distributor << " NOK\n";
    
    saveResults("Cinema profits - Gross: " + to_string(grossProfit) + ", Net: " + to_string(netProfit));
}

void convertTime() {
    int seconds;
    cout << "=== Time Converter ===\n\n";
    
    cout << "Enter time in seconds: ";
    cin >> seconds;
    
    int minutes = seconds / 60;
    int remainingSeconds = seconds % 60;
    
    cout << "\n" << seconds << " seconds is " << minutes << " minute(s) and " 
         << remainingSeconds << " second(s)\n";
    
    saveResults("Time conversion: " + to_string(seconds) + " seconds = " + 
               to_string(minutes) + "m " + to_string(remainingSeconds) + "s");
}

void saveResults(const string& result) {
    ofstream file("results.txt", ios::app);
    time_t now = time(0);
    file << ctime(&now) << result << "\n";
    file.close();
}
