
#include<iostream> // Including the standard input/output library

using namespace std; // Using the standard namespace

int main(){ // Starting the main function
	int a,b,c,d,e,f; // Declaring variables a to f as integers
	double x,y; // Declaring variables x and y as double precision floating point numbers

	while(1){ // Starting an infinite loop
		cin >> a >> b >> c >> d >> e >> f; // Reading the input into the variables
		if(cin.eof()){ // Checking if the end of file has been reached
			break; // Exiting the loop
		}
		y = (double)(c*d-f*a)/(b*d-e*a); // Calculating the value of y using the given formula
		x = (double)(c*e-f*b)/(a*e-d*b); // Calculating the value of x using the given formula
		if(y <= 0.0005){ // Checking if y is less than or equal to a very small positive number
			y = 0; // If so, set y to 0
		}
		if(x <= 0.0005){ // Checking if x is less than or equal to a very small positive number
			x = 0; // If so, set x to 0
		}
		cout << fixed << setprecision(3) << x << " " << y << endl; // Printing the values of x and y to the standard output with three decimal places
	}

	return 0; // Ending the main function with a return value of 0
}

