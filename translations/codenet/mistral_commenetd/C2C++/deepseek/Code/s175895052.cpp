#include<iostream>
#include<string>

using namespace std;

// The main function is the starting point of the program
int main()
{
    string n; // A string is declared to store the input string

    // The cin object is used to read a string from the standard input stream
    cin >> n;

    // Check if the first three characters of the input string form an identical sequence
    if(((n[0]==n[1])&&(n[1]==n[2]))||((n[1]==n[2])&&(n[2]==n[3])))
    {
        // If the condition is true, print "Yes" to the standard output stream
        cout << "Yes" << endl;
    }
    else
    {
        // If the condition is false, print "No" to the standard output stream
        cout << "No" << endl;
    }

    // The program returns an integer value 0 upon successful execution
    return 0;
}

