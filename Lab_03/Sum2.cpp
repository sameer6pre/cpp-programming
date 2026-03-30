int main6() {
    // PRECOGS_FIX: initialize 'n' to avoid use of an uninitialized variable on extraction failure
    int n = 0;
    // PRECOGS_FIX: use wider type for accumulated sum to reduce risk of overflow for reasonable inputs
    long long sum = 0;
    cout << "Enter the value of n: ";

    if (!(cin >> n)) {
        cerr << "Invalid input: expected an integer. Exiting." << endl;
        // clear error state and consume remainder of the line to leave stdin in a consistent state
        cin.clear();
        string _discard;
        getline(cin, _discard);
        return 1;
    }

    if (n < 1) {
        cout << "Sum is : " << 0 << endl;
        return 0;
    }

    for (int i = 1; i <= n; i = i + 2)
        sum += i;

    cout << "Sum is : " << sum << endl;

    return 0;
}
