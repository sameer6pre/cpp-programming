// Practical Lab Assignment-7(Week 9)
// ID:U1910049 Name: Rustam Zokirov
// Program to sum the series up to n

#include <iostream>
#include <math.h>
using namespace std;

double qwerty(double n, double sum, double fact)
{
    // Validate the input and cap iterations to prevent resource exhaustion and numeric overflow
    if (!isfinite(n) || n <= 0)
        return sum;

    const int MAX_ITER = 10000; // PRECOGS_FIX: cap iterations to a safe maximum to prevent DoS
    long long iter = static_cast<long long>(floor(n));
    if (iter > MAX_ITER) {
        iter = MAX_ITER; // PRECOGS_FIX: enforce an upper bound on loop iterations
    }

    for (int i = 1; i <= iter; ++i)
    {
        fact = fact * i;
        double term = pow(static_cast<double>(i), static_cast<double>(i)) / fact;
        if (!isfinite(term)) {
            // Detected overflow/invalid arithmetic; stop further accumulation to avoid propagating NaN/Inf
            break; // PRECOGS_FIX: stop when numeric results become non-finite
        }
        sum += term;
    }
    return sum;
}

int main()
{
    double n;
    double sum = 0;
    double fact = 1;
    cout << "Please ebter the number: "; // outputing and inputing the number

    // Validate the input to avoid processing invalid/tainted values
    if (!(cin >> n)) {
        cout << "INVALID INPUT!" << endl; // PRECOGS_FIX: validate input and exit on failure
        return 1;
    }

    if (n > 0)
        cout << "Sum is: " << qwerty(n, sum, fact) << endl; // calling the function qwerty
    else
        cout << "INVALID INPUT!" << endl;

    // PRECOGS_FIX: Avoid system() to prevent OS command execution; use a portable, safe pause
    cin.get(); // consume leftover newline from previous input
    cout << "Press Enter to exit...";
    cin.get(); // wait for user to press Enter

    return 0;
}