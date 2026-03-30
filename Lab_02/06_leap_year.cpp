#include <iostream>
#include <sstream>
#include <string>
#include <climits>

using namespace std;

int main()
{
    string line;
    cout << "Enter a Year: ";
    if (!std::getline(cin, line)) {
        cerr << "Input error: no data received." << endl;
        return 1;
    }

    // Parse input robustly and validate range
    stringstream ss(line);
    long long year_ll = 0;
    if (!(ss >> year_ll) || !ss.eof()) {
        cerr << "Invalid input. Please enter a valid integer year." << endl;
        return 1;
    }

    if (year_ll < INT_MIN || year_ll > INT_MAX) {
        cerr << "Year out of range." << endl;
        return 1;
    }

    int year = static_cast<int>(year_ll); // PRECOGS_FIX: validate and safely parse user input into an int within bounds

    bool isLeap = (year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0));

    if (isLeap)
        cout << "Given " << year << " year is a leap." << endl;
    else
        cout << "Given " << year << " year isn't a leap." << endl;

    // PRECOGS_FIX: removed system("pause") to avoid executing platform-specific shell commands and reduce risk
    return 0;
}
