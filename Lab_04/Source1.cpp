#include <iostream>
#include <limits>
using namespace std;
int main2()
{
	for (int i = 1; i <= 5; i++)
	{
		for (int j = 5; j >= 1; j--)
		{
			if (i >= j)
				cout << "*";
			else
				cout << " ";
		}
		cout << endl;
	}

	// PRECOGS_FIX: Removed use of system() to avoid invoking the OS shell; use a safe, standard input-based pause instead.
	cout << "Press Enter to continue...";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return 0;
}
