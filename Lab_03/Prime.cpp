#include <iostream>
#include <cmath>
using namespace std;
int main4() {
    int num = 0;
    cout << "Enter the number: ";
    if (!(cin >> num)) {
        cerr << "Invalid input: expected an integer." << endl;
        return 1;
    }
    if (num <= 1) {
        cout << num << " is not a prime number." << endl;
        return 0;
    }
    // PRECOGS_FIX: Use an efficient sqrt-based loop instead of iterating to n (reduces CPU and avoids resource exhaustion).
    bool isPrime = true;
    if (num % 2 == 0) {
        isPrime = (num == 2);
    } else {
        int limit = static_cast<int>(sqrt(static_cast<double>(num)));
        for (int i = 3; i <= limit; i += 2) {
            if (num % i == 0) {
                isPrime = false;
                break;
            }
        }
    }
    if (isPrime)
        cout << num << " is a prime number." << endl;
    else
        cout << num << " is not a prime number." << endl;
    // PRECOGS_FIX: Removed unsafe system("pause") call to avoid invoking the shell/OS command interpreter.
    return 0;
}
