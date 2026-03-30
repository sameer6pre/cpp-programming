#include <iostream>
#include <string>
#include <limits>
#include <cctype>

using namespace std;

int main() {
    string s;

    cout << "Enter a character: ";
    if (!(cin >> s)) {
        cerr << "Input error." << endl;
        return 1;
    }

    if (s.empty()) {
        cerr << "No input provided." << endl;
        return 1;
    }

    char c = s[0];
    if (s.size() > 1) {
        cerr << "Warning: more than one character entered; using first character." << endl;
    }

    if (!isalpha(static_cast<unsigned char>(c))) {
        cout << "Input is not an alphabetic character." << endl;
    } else if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
        cout << "The character is a vowel." << endl;
    } else {
        cout << "The character is a consonant." << endl;
    }

    // PRECOGS_FIX: Removed use of system() to avoid invoking the OS command processor; use a safe, portable pause instead
    cout << "Press Enter to continue..." << flush;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    return 0;
}
