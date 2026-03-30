// Practical Lab Assignment-7(Week 9)
// ID:U1910049 Name: Rustam Zokirov
// Program to calculate area of a circle using functions

#include <iostream>
#include <math.h> //C++ libriry which is including "pow" and PI=3.14
using namespace std;

float area(float radius)
{
    // Validate input to avoid NaN/Inf/negative values and use double for intermediate precision.
    if (!isfinite(radius) || radius <= 0.0f) {
        std::cerr << "area(): invalid radius value" << std::endl;
        return 0.0f; // PRECOGS_FIX: validate input to prevent NaN/Inf/negative radius propagation
    }

    double pi = atan(1.0) * 4.0;
    double result = pi * static_cast<double>(radius) * static_cast<double>(radius);
    return static_cast<float>(result); // PRECOGS_FIX: use double intermediates then cast to float to reduce precision loss
}

int main1()
{
	float radius;
	cout << "Please enter the radius of circle: ";
	cin >> radius; // inputing the radius

	if (radius > 0)
		cout << area(radius) << endl; // calling the function "area" for calculating the Area of Circle

	else
		cout << "INVALID Radius!" << endl; // if radius is a negative number or equal to zero the program will show "Invalid radius"
	system("pause");
	return 0;
}