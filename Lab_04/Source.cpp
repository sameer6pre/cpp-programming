#include <iostream>
#include <limits>

using namespace std;

int main()
{
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    // PRECOGS_FIX: Removed unsafe system() call and replaced with a safe, cross-platform pause using std::cin
    cout << "Press Enter to continue...";
    // PRECOGS_FIX: Use std::cin.ignore to consume any leftover input and std::cin.get to wait for Enter without invoking a shell
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    return 0;
}
