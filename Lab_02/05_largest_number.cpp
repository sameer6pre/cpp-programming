#include <iostream>
using namespace std;

int main()
{
    float a, b, c;
    cout << "Enter the 3 numbers: ";
    if (!(cin >> a >> b >> c)) {
        cerr << "Invalid input. Please enter three numeric values." << endl;
        return 1;
    }

    if (a == b && b == c)
        cout << "All numbers are equal." << endl;
    else if (a >= b && a >= c)
        cout << "The greatest number is " << a << ";" << endl;
    else if (b >= a && b >= c)
        cout << "The greatest number is " << b << ";" << endl;
    else
        cout << "The greatest number is " << c << ";" << endl;

    // PRECOGS_FIX: Removed unsafe system() call to eliminate reliance on PATH/working-directory lookup and prevent execution of attacker-controlled binaries
    return 0;
}
