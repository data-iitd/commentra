
#include <bits/stdc++.h>
using namespace std;

class FastReader { // Defining a FastReader class for reading input
    public :
    fastReader() { // Constructor for initializing the FastReader object
        s = new istringstream("");
    }

    string next() { // Method for reading the next token from the input
        while (s->peek() =='') s->ignore(); // Ignoring leading spaces
        string word = ""; // Initializing a string variable for storing the next token
        while (s->peek()!='' && s->peek()!= EOF) { // Till the next space or the end of the input is reached
            word += s->peek(); // Appending the next character to the string variable
            s->ignore(); // Ignoring the current character
        }
        return word; // Returning the next token
    }

    int nextInt() { // Method for reading the next integer from the input
        return stoi(next()); // Converting the next token to an integer and returning it
    }

    long long nextLong() { // Method for reading the next long integer from the input
        return stoll(next()); // Converting the next token to a long integer and returning it
    }

    double nextDouble() { // Method for reading the next double from the input
        return stod(next()); // Converting the next token to a double and returning it
    }

    string nextLine() { // Method for reading the next line from the input
        string str = ""; // Initializing an empty string variable for storing the line
        getline(cin, str); // Reading the next line and storing it in the string variable
        return str; // Returning the next line
    }

    private :
    istringstream *s; // Declaring a pointer to an istringstream object for reading input
};

int modPower(int x, int y, int mod) { // Method for calculating x raised to the power of y modulo mod
    int res = 1; // Initializing the result variable to 1
    x %= mod; // Calculating the remainder of x when divided by mod

    if (x == 0) return 0; // If x is 0, the result is 0

    while (y > 0) { // While y is greater than 0
        if (y % 2 == 1) { // If y is odd
            res = (res * x) % mod; // Multiplying the result with x and taking the modulo with mod
        }
        y = y >> 1; // Dividing y by 2
        x = (x * x) % mod; // Squaring x and taking the modulo with mod
    }
    return res; // Returning the final result
}

template <typename T1, typename T2> // Defining a generic pair class for storing two elements of different types
class pair {
    public :
    T1 first; // Declaring a variable for storing the first element
    T2 second; // Declaring a variable for storing the second element

    pair(T1 first, T2 second) { // Constructor for initializing the pair object
        this->first = first; // Initializing the first variable with the first argument
        this->second = second; // Initializing the second variable with the second argument
    }
};

int main() { // Main method for executing the program
    FastReader in; // Creating a FastReader object for reading input

    long long a[4]; // Declaring and initializing an array of long integers named a with size 4

    for (int i = 0; i < 4; i++) { // Iterating through the elements of the array a
        a[i] = in.nextLong(); // Reading the next long integer from the input and storing it in the current element of the array
    }

    long long result = max(a[0] * a[2], max(a[1] * a[3], max(a[0] * a[3], a[1] * a[2]))); // Calculating the maximum product of pairs of elements in the array a

    cout << result; // Printing the result to the standard output
    return 0;
}

