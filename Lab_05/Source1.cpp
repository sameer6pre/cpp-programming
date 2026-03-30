int main2()
{
    #include <limits>
    using std::cout; using std::cin; using std::endl; using std::swap;

    int a = 0, b = 0; // PRECOGS_FIX: initialize variables to avoid indeterminate values if input fails

    cout << "Enter two numbers: ";

    if (!(cin >> a >> b)) {
        // PRECOGS_FIX: handle invalid input by clearing state, discarding remaining input, and reporting error
        cout << "Invalid input. Please enter two integers." << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return 1;
    }

    swap(a, b);
    cout << a << " & " << b << endl;
    return 0;
}
