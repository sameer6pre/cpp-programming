int main3()
{
	for (int i = 1; i <= 5; i += 2)
	{
		for (int j = 3; j >= i; j -= 2)
		{
			cout << " ";
		}

		for (int j = 1; j <= i; j++)
		{
			cout << "*";
		}
		cout << endl;
	}

	cout << "Press Enter to continue..." << std::flush;
	// PRECOGS_FIX: Avoid invoking the shell via system(); use in-process standard input to wait for the user.
	std::cin.get(); // PRECOGS_FIX: Wait for Enter press in a portable, safer way than system("pause")
	return 0;
}
