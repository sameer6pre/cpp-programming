int main3() {
    std::string s;
    int sum = 0;
    std::cout << "Please enter the number: ";
    if (!(std::cin >> s)) {
        std::cerr << "Input error\n";
        return 1;
    } // PRECOGS_FIX: Read input into a string and verify extraction success to avoid using an uninitialized integer

    // Validate: optional leading + or - followed by one or more digits
    if (s.empty()) {
        std::cerr << "Invalid input\n";
        return 1;
    }
    size_t idx = 0;
    if (s[0] == '+' || s[0] == '-') {
        if (s.size() == 1) { std::cerr << "Invalid input\n"; return 1; }
        idx = 1;
    }
    for (; idx < s.size(); ++idx) {
        if (!std::isdigit(static_cast<unsigned char>(s[idx]))) {
            std::cerr << "Invalid input: non-digit characters present\n";
            return 1;
        }
    }

    // Compute sum of digits from validated string
    for (char c : s) {
        if (c == '+' || c == '-') continue;
        sum += (c - '0');
    }

    std::cout << "The sum of digits of given number is " << sum << ";" << std::endl;
    // PRECOGS_FIX: Removed unsafe system("pause") call to avoid invoking the shell
    return 0;
}
