#include <iostream>
#include <iomanip>
#include <limits>
#include <fstream>
#include <ctime>
#include <string>
#include <vector>
#include <thread>     // <<<
#include <chrono>     // <<<

#ifdef _WIN32
  #include <windows.h>
#endif

using namespace std;

// ANSI color codes (cross-platform where possible)
const string RESET   = "\033[0m";
const string RED     = "\033[31m";
const string GREEN   = "\033[32m";
const string YELLOW  = "\033[33m";
const string BLUE    = "\033[34m";
const string MAGENTA = "\033[35m";
const string CYAN    = "\033[36m";
const string WHITE   = "\033[37m";

// Utility functions
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void logError(const string& msg) {
    ofstream log("errors.log", ios::app);
    auto t = time(nullptr);
    log << put_time(localtime(&t), "%Y-%m-%d %H:%M:%S") 
        << " ERROR: " << msg << endl;
}

// Save a result line to history
void saveResult(const string& line) {
    ofstream out("history.txt", ios::app);
    auto t = time(nullptr);
    out << put_time(localtime(&t), "%Y-%m-%d %H:%M:%S") 
        << " | " << line << endl;
}

// ASCII banner
void displayBanner() {
    cout << CYAN << R"(
  __  __ 
 |  \/  |___  
 | |\/| / __|
 | |  | \__ \ 
 |_|  |_|___/                          
  Multi-Tool Utility v1.0 by Adrian Lesniak
)" << RESET << endl;
}

// About author
void showAbout() {
    clearScreen();
    displayBanner();
    cout << MAGENTA
         << "\nAbout the Author\n"
         << "----------------\n"
         << "Adrian Lesniak\n"
         << "Fullstack Developer & Software Engineer\n"
         << "GitHub: https://github.com/adi1985a\n"
         << "Email: your.email@example.com\n"
         << RESET;
    cout << "\nPress ENTER to return to menu...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

// View history file
void viewHistory() {
    clearScreen();
    displayBanner();
    cout << YELLOW << "\n-- Operation History --\n\n" << RESET;
    ifstream in("history.txt");
    if (!in) {
        cout << RED << "No history found.\n" << RESET;
    } else {
        string line;
        while (getline(in, line)) {
            cout << line << "\n";
        }
    }
    cout << "\nPress ENTER to return to menu...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

// Menu display
void displayMenu() {
    clearScreen();
    displayBanner();
    cout << GREEN
         << "\n[1] Calculate Salary\n"
         << "[2] Stadium Ticket Sales\n"
         << "[3] Class Gender %\n"
         << "[4] Cinema Profit\n"
         << "[5] Time Converter\n"
         << "[6] View History\n"
         << "[7] About Author\n"
         << "[0] Exit\n"
         << RESET
         << "\nEnter choice: ";
}

// 1. Salary
void calculateSalary() {
    clearScreen();
    displayBanner();
    cout << BLUE << "\n=== Salary Calculator ===\n\n" << RESET;

    double hours, rate;
    do {
        cout << "Hours worked: ";
    } while (!(cin >> hours) || hours < 0 && (cin.clear(), cin.ignore(10000, '\n'), true));
    do {
        cout << "Hourly rate (NOK): ";
    } while (!(cin >> rate) || rate < 0 && (cin.clear(), cin.ignore(10000, '\n'), true));

    double salary = hours * rate;
    cout << GREEN << fixed << setprecision(2)
         << "\n--> Salary: " << salary << " NOK\n" << RESET;

    saveResult("Salary: " + to_string(salary) + " NOK");
    cout << "\nPress ENTER to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

// 2. Ticket Sales
void calculateTicketSales() {
    clearScreen();
    displayBanner();
    cout << BLUE << "\n=== Stadium Ticket Sales ===\n\n" << RESET;

    int a,b,c;
    cout << "Class A (15 NOK): "; cin >> a;
    cout << "Class B (12 NOK): "; cin >> b;
    cout << "Class C ( 9 NOK): "; cin >> c;
    double total = a*15 + b*12 + c*9;

    cout << GREEN << fixed << setprecision(2)
         << "\n--> Total Revenue: " << total << " NOK\n" << RESET;
    saveResult("Ticket Sales Total: " + to_string(total) + " NOK");

    cout << "\nPress ENTER to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

// 3. Class Gender Percentages
void calculateClassPercentages() {
    clearScreen();
    displayBanner();
    cout << BLUE << "\n=== Class Gender Distribution ===\n\n" << RESET;

    int boys, girls;
    cout << "Number of boys: ";   cin >> boys;
    cout << "Number of girls: ";  cin >> girls;
    int tot = boys + girls;
    double pb = 100.0 * boys / tot;
    double pg = 100.0 * girls / tot;

    cout << GREEN << fixed << setprecision(1)
         << "\n--> Boys: " << pb << "%\n"
         << "--> Girls: " << pg << "%\n" << RESET;
    saveResult("Class % - Boys: " + to_string(pb) + "%, Girls: " + to_string(pg) + "%");

    cout << "\nPress ENTER to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

// 4. Cinema Profit
void calculateCinemaProfit() {
    clearScreen();
    displayBanner();
    cout << BLUE << "\n=== Cinema Profit Calculator ===\n\n" << RESET;

    int adult, child;
    cout << "Adult tickets (10 NOK): ";    cin >> adult;
    cout << "Children tickets (6 NOK): "; cin >> child;

    double gross = adult*10 + child*6;
    double net   = gross * 0.2;
    double dist  = gross * 0.8;

    cout << GREEN << fixed << setprecision(2)
         << "\n--> Gross: " << gross << " NOK\n"
         << "--> Net  : " << net   << " NOK\n"
         << "--> Dist : " << dist  << " NOK\n" << RESET;
    saveResult("Cinema Profit Gross: " + to_string(gross));

    cout << "\nPress ENTER to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

// 5. Time Converter
void convertTime() {
    clearScreen();
    displayBanner();
    cout << BLUE << "\n=== Time Converter ===\n\n" << RESET;

    int sec;
    cout << "Seconds: "; cin >> sec;
    int m = sec / 60, s = sec % 60;

    cout << GREEN << "\n--> " << sec << "s = "
         << m << "m " << s << "s\n" << RESET;
    saveResult("Time Convert: " + to_string(sec) + "s -> " +
               to_string(m) + "m " + to_string(s) + "s");

    cout << "\nPress ENTER to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

int main() {
    while (true) {
        displayMenu();
        char ch;
        cin >> ch;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        try {
            switch (ch) {
                case '1': calculateSalary();         break;
                case '2': calculateTicketSales();    break;
                case '3': calculateClassPercentages(); break;
                case '4': calculateCinemaProfit();   break;
                case '5': convertTime();             break;
                case '6': viewHistory();             break;
                case '7': showAbout();               break;
                case '0': 
                    cout << YELLOW << "\nGoodbye!\n" << RESET;
                    return 0;
                default:
                    cout << RED << "Invalid choice!\n" << RESET;
                    this_thread::sleep_for(chrono::seconds(1));
            }
        }
        catch (const exception& e) {
            logError(e.what());
            cout << RED << "Error: " << e.what() << RESET << endl;
            cout << "Press ENTER to continue...";
            cin.get();
        }
    }
    return 0;
}
