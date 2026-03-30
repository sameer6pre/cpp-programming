#include <iostream>
#include <limits>

using namespace std;

int main() {
    int a = 0; // PRECOGS_FIX: initialize variable to avoid use of uninitialized memory
    cout << "Enter the number: ";
    if (!(cin >> a)) {
        cerr << "Invalid input. Please enter a valid integer." << endl; // PRECOGS_FIX: validate extraction and fail fast on invalid input
        return 1;
    }

    if (a % 2 == 0)
        cout << "Your number is Even!" << endl;
    else
        cout << "Your number is Odd!" << endl;

    system("pause");
    return 0;
}
