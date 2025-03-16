
#include <iostream>

int main() {
    int data; // Declaring a variable 'data' of type 'int' to read user input
    std::cin >> data; // Reading user input and storing it in the 'data' variable
    int result; // Declaring a variable 'result' of type 'int' to store the result
    result = data * data * data; // Assigning the value of 'data' cubed to the 'result' variable
    std::cout << result << std::endl; // Printing the result using the 'cout' object from 'iostream' library
    return 0;
}

