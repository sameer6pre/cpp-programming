int main() {
	int a = 0, b = 1, sum = 0;
	cout << a << endl;
	cout << b << endl;
	while (b < 100) {
		sum = a + b;
		a = b;
		b = sum;
		if (b > 100) {
			break;
		}
		cout << sum << endl;
	}
	// Use a safe, portable blocking read instead of system("pause") to avoid invoking a shell
	cout << "Press Enter to continue...";
	cin.get(); // PRECOGS_FIX: Replaced system("pause") with a simple, safe input wait to avoid invoking the OS shell
	return 0;
}
