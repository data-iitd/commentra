#include <iostream> // We include the standard input/output library

int main(){ // The main function is the entry point of the program
    int in; // We declare an integer variable named 'in' to store the input
    int h, m, s; // We declare three integer variables named 'h', 'm', and 's' to store hours, minutes, and seconds respectively

    std::cin >> in; // We read an integer input from the standard input and store it in the 'in' variable

    h = in / 3600; // We calculate the number of hours by dividing the input by the total number of seconds in an hour (3600) and storing the quotient in 'h'
    in %= 3600; // We calculate the remaining seconds by taking the modulus of the input with 3600 and storing the result in 'in'

    m = in / 60; // We calculate the number of minutes by dividing the remaining seconds by 60 and storing the quotient in 'm'
    in %= 60; // We calculate the remaining seconds by taking the modulus of the remaining seconds with 60 and storing the result in 'in'

    s = in; // We store the remaining seconds in 's'

    std::cout << h << ":" << m << ":" << s << std::endl; // We print the hours, minutes, and seconds in the format "HH:MM:SS" using the cout function
}

