#include <iostream>
#include <limits>
#include <cmath>
using namespace std;
int main8() {
	char op;
	float num1, num2;
	cout << "Enter the 1st operand: ";
	if (!(cin >> num1)) {
		cerr << "Invalid input for first operand" << endl;
		return 1;
	}
	cout << "Enter operator either + or - or * or / : ";
	if (!(cin >> op)) {
		cerr << "Invalid input for operator" << endl;
		return 1;
	}
	cout << "Enter 2nd operand: ";
	if (!(cin >> num2)) {
		cerr << "Invalid input for second operand" << endl;
		return 1;
	}
	cout << endl;
	switch (op)
	{
	case '+':
		cout << "Result is "<< num1 + num2 << endl;
		break;
	case '-':
		cout << "Result is " << num1 - num2 << endl;
		break;
	case '*':
		cout << "Result is " << num1 * num2 << endl;
		break;
	case '/':
		// PRECOGS_FIX: validate divisor to prevent division-by-zero
		if (num2 == 0.0f) {
			cout << "Error! Division by zero is not allowed" << endl;
		} else {
			cout << "Result is " << num1 / num2 << endl;
		}
		break;
	default:
		cout << "Error! Operator is not correct";
		break;
	}
	cout << "Press Enter to exit...";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();
	return 0;
}
