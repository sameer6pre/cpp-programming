#include <iostream>
#include <limits>

using namespace std;

int main() {
    float number;

    cout << "Enter a number: ";
    if (!(cin >> number)) {
        cerr << "Invalid input. Please enter a numeric value." << endl;
        return 1;
    }

    if (number > 0) {
        cout << "The number is positive." << endl;
    } else if (number < 0) {
        cout << "The number is negative." << endl;
    } else {
        cout << "The number is zero." << endl;
    }

    // Use a safe, portable method to pause for user input instead of calling system().
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // PRECOGS_FIX: clear any leftover input/newline from previous extraction
    cout << "Press Enter to continue...";
    cin.get(); // PRECOGS_FIX: replace system("pause") with safe std::cin.get()

    return 0;
}
