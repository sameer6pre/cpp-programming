int main5()
{
	float sum = 0, fact = 1;
	for (int i = 1; i <= 7; i++)
	{
		fact = fact * i;
		sum += i / fact;
	}
	cout << "Sum is : " << sum << endl;
	// PRECOGS_FIX: Remove call to system() and replace with safe, portable stdin-based pause to avoid invoking a shell
	cout << "Press Enter to continue...";
	cin.get();
	return 0;
}
