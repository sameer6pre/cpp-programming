
int main()
{

	string user_choise;
	main_menu_view();
	cin >> user_choise;

	// main_menu_validation_check
	if (user_choise == "1")
	{
		system("cls");
		int x;
		cout << "Input Age: ";
		cin >> x;
		Person person1, person2(x);
		person1.Display();
		cout << endl;
		person2.Display();
	}
	else if (user_choise == "2")
	{
		system("cls");
		cout << "Records: " << endl;
		string name;
		float salary;
		string date_of_birth;
		cout << "Name: ";
		cin >> name;
		cout << "Salary: ";
		cin >> salary;
		cout << "Date of birth: ";
		cin >> date_of_birth;

		Records record1, record2(name, salary, date_of_birth);
		record1.Display();
		record2.Display();
		cout << endl;

		Records *ptr = &record1;
		ptr->alert_name();
		ptr->alert_salary();
		ptr->alert_date();

		record1.Display();
		record2.Display();
	}
	else if (user_choise == "3")
	{
		system("cls");
		Account a;
		a.Display();
		// PRECOGS_FIX: Removed explicit destructor call
		// a.~Account(); // Removed to prevent double free
	}
	else if (user_choise == "4")
	{
		system("cls");
		Rectangle r;
		double width1, height1;

		cout << "Enter the width of the rectangle: ";
		cin >> width1;
		cout << "Enter the height of the rectangle: ";
		cin >> height1;

		Rectangle r2(height1, width1);

		r2.setHeight(height1);
		r2.setWidth(width1);

		system("cls");

		int user_choice_1 = -1; // PRECOGS_FIX: Initialize variable to prevent use of uninitialized variable
		while (user_choice_1 != 0) // PRECOGS_FIX: Change condition to prevent uncontrolled recursion
		{
			cout << "Rectangle: \n";
			cout << "[1]  Area\n";
			cout << "[2]  Perimeter\n";
			cout << "[0]  Exit\n";
			cin >> user_choice_1;
			switch (user_choice_1)
			{
			case 1:
				system("cls");
				cout << "The Area is: (Default Constructor (5,5)) : " << r.getArea() << endl
					 << endl;
				cout << "The Area is: (Parametric Constructor) : " << r2.getArea() << endl;
				cout << endl;

				break;
			case 2:
				system("cls");
				cout << "The Perimeter is: (Default Constructor(5,5) : " << r.getPerimeter() << endl
					 << endl;
				cout << "The Perimeter is: (Parametric Constructor) : " << r2.getPerimeter() << endl;
				break;
			case 0:
				break;
			}
		}
	}
	else if (user_choise == "0")
	{
		return 0;
	}
	else
	{
		system("cls");
		cout << "Please try again !!!\n";
		main(); // PRECOGS_FIX: This can lead to uncontrolled recursion; consider redesigning
	}

	return 0;
}