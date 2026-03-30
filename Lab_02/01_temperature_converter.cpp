#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

int main() {
    float temp = 0.0f; // PRECOGS_FIX: initialize to avoid use of indeterminate value
    char unit = '\0';

    cout << "Enter the temperature: ";
    string tempStr;
    if (!getline(cin, tempStr)) {
        cerr << "Failed to read temperature input." << endl;
        return 1;
    }

    // Validate and parse temperature string safely
    {
        stringstream ss(tempStr);
        if (!(ss >> temp) || !(ss.eof())) {
            cerr << "Invalid temperature. Please enter a numeric value." << endl;
            return 1;
        }
    }

    cout << "Enter the unit (C/F): ";
    string unitStr;
    if (!getline(cin, unitStr) || unitStr.empty()) {
        cerr << "Failed to read unit input." << endl;
        return 1;
    }

    // Normalize and validate unit character
    unit = static_cast<char>(toupper(static_cast<unsigned char>(unitStr[0]))); // PRECOGS_FIX: normalize to uppercase and bound to first character
    if (unit == 'C') {
        cout << fixed << setprecision(2);
        cout << "The temperature in Fahrenheit is " << (temp * 9.0f / 5.0f) + 32.0f << "F." << endl;
    } else if (unit == 'F') {
        cout << fixed << setprecision(2);
        cout << "The temperature in Celsius is " << (temp - 32.0f) * 5.0f / 9.0f << "C." << endl;
    } else {
        cout << "Invalid unit. Use 'C' or 'F'." << endl;
    }

    return 0;
}
