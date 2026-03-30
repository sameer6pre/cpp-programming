int main5() {
	int n;
	float sum = 0.0f;
	cout << "Enter the value of n: ";
	if (!(cin >> n) || n <= 0) {
		cerr << "Invalid input. n must be a positive integer." << endl;
		return 1;
	}
	for (int i = 1; i <= n; ++i)
		sum += 1.0f / static_cast<float>(i); // PRECOGS_FIX: ensure floating-point division to avoid integer truncation
	cout << "Sum is : " << sum << endl;
	// PRECOGS_FIX: avoid calling system(), use a portable, input-driven pause instead
	cout << "Press Enter to continue...";
	cin.ignore();
	cin.get();
	return 0;
}
