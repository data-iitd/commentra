#######
# Code
#######

# Include necessary libraries
#include <bits/stdc++.h>

// Define constants
const int inf = 1000000000;
const int mod = 1000000007;
const int dd[8][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1}, {-1, 1}, {1, 1}, {1, -1}, {-1, -1} };
const int ddn[8][2] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };

// Function to read an integer list from standard input
vector<int> LI( )
{
    vector<int> result;
    string str;
    getline( cin, str );
    stringstream ss( str );
    int temp;
    while ( ss >> temp )
    {
        result.push_back( temp );
    }
    return result;
}

// Function to read an integer from standard input
int I( )
{
    string str;
    getline( cin, str );
    stringstream ss( str );
    int result;
    ss >> result;
    return result;
}

// Function to read a float from standard input
float F( )
{
    string str;
    getline( cin, str );
    stringstream ss( str );
    float result;
    ss >> result;
    return result;
}

// Function to read a list from standard input, split by space
vector<string> LS( )
{
    string str;
    getline( cin, str );
    stringstream ss( str );
    vector<string> result;
    string temp;
    while ( ss >> temp )
    {
        result.push_back( temp );
    }
    return result;
}

// Function to read a string from standard input
string S( )
{
    string str;
    getline( cin, str );
    return str;
}

// Main function
int main( )
{
    // Read input values
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    // Calculate the maximum product of pairs of numbers
    int result = max( a*c, b*d, a*d, b*c );

    // Print the result
    cout << result << endl;

    return 0;
}

// End of code
