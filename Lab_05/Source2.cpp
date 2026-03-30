// Practical Lab Assignment-7(Week 9)
// ID:U1910049 Name: Rustam Zokirov
// Program to convert into minutes

#include <iostream>
using namespace std;

double converting1(double hours, double minutes, double seconds)
{
    #include <cmath>
    #include <limits>

    // Validate that inputs are finite
    if (!std::isfinite(hours) || !std::isfinite(minutes) || !std::isfinite(seconds))
    {
        // PRECOGS_FIX: return NaN when inputs are not finite to avoid propagating INF/NaN silently
        return std::numeric_limits<double>::quiet_NaN();
    }

    // Normalize negative or out-of-range minute/second values in a safe way
    if (hours < 0.0 || minutes < 0.0 || seconds < 0.0)
    {
        // PRECOGS_FIX: reject negative time components by returning NaN
        return std::numeric_limits<double>::quiet_NaN();
    }

    // If seconds or minutes overflow their conventional ranges, normalize them into minutes/hours
    // e.g., 90 seconds -> 1 minute + 30 seconds
    double extraMinutesFromSeconds = std::floor(seconds / 60.0);
    seconds = std::fmod(seconds, 60.0);
    if (seconds < 0.0) seconds += 60.0; // defensive, though seconds >= 0 above

    minutes += extraMinutesFromSeconds;
    double extraHoursFromMinutes = std::floor(minutes / 60.0);
    minutes = std::fmod(minutes, 60.0);
    if (minutes < 0.0) minutes += 60.0;

    hours += extraHoursFromMinutes;

    // Final arithmetic; inputs are finite and normalized
    return (hours * 60.0) + minutes + (seconds / 60.0);
}

int main3()
{
    #include <cmath>
    #include <limits>

    double hours, minutes, seconds;

    std::cout << "Hours: ";
    if (!(std::cin >> hours)) // PRECOGS_FIX: validate extraction success to avoid uninitialized variable usage
    {
        std::cerr << "Invalid numeric input for Hours.\n";
        return 1;
    }

    std::cout << "Minutes: ";
    if (!(std::cin >> minutes)) // PRECOGS_FIX: validate extraction success
    {
        std::cerr << "Invalid numeric input for Minutes.\n";
        return 1;
    }

    std::cout << "Seconds: ";
    if (!(std::cin >> seconds)) // PRECOGS_FIX: validate extraction success
    {
        std::cerr << "Invalid numeric input for Seconds.\n";
        return 1;
    }

    // Basic semantic validation: non-negative
    if (hours >= 0 && minutes >= 0 && seconds >= 0)
        std::cout << "The time in minutes is " << converting1(hours, minutes, seconds) << std::endl;
    else
        std::cout << "Invalid inputs!" << std::endl;

    return 0;
}