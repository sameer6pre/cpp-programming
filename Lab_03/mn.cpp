int main1() {
    #include <limits>
    long long m = 0, n = 0; // use wider type for input to reduce overflow risk
    long long sum = 0;

    std::cout << "Enter the 1st number: ";
    if (!(std::cin >> n)) {
        std::cerr << "Invalid input. Expected an integer for the 1st number." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return 1;
    }

    std::cout << "Enter the 2nd number: ";
    if (!(std::cin >> m)) {
        std::cerr << "Invalid input. Expected an integer for the 2nd number." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return 1;
    }

    if (n < m) {
        long long count = m - n + 1;
        const long long MAX_ITER = 10000000LL; // reasonable cap to avoid resource exhaustion
        if (count > MAX_ITER) {
            std::cout << "Range too large. Aborting to prevent resource exhaustion." << std::endl;
        } else {
            // PRECOGS_FIX: perform arithmetic using wider intermediate (__int128) and check bounds to prevent overflow
            __int128 t = (__int128)(n + m) * (__int128)count;
            t /= 2; // arithmetic series formula safely in 128-bit
            if (t > std::numeric_limits<long long>::max() || t < std::numeric_limits<long long>::min()) {
                std::cout << "Sum is out of representable range." << std::endl;
            } else {
                sum = (long long)t; // safe cast after check
                std::cout << "The sum of the integers between the two numbers is " << sum << ";" << std::endl;
            }
        }
    }
    else if (m < n)
        std::cout << "Invalid numbers! Please try again." << std::endl;
    else { // m == n
        sum = n;
        std::cout << "The sum is " << sum << std::endl;
    }

    // PRECOGS_FIX: avoid system("pause"); use portable prompt to wait for Enter
    std::cout << "Press Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    return 0;
}
