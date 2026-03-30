int main4()
{
	for (int i = 1; i <= 5; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
	for (int i = 1; i <= 5; i++)
	{
		for (int j = 5; j >= i; j--)
		{
			cout << "*";
		}
		cout << endl;
	}
	// PRECOGS_FIX: Replace unsafe system() invocation with a safe, portable wait for user input
	cout << "Press Enter to continue...";
	cout.flush();
	std::cin.get();
	return 0;
}
