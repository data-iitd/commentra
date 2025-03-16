########
# Code #
########

# Include the necessary libraries
#include <bits/stdc++.h>
using namespace std;

// Define the modulus value
const int mod = 1000000007;

// Function to read an integer
int I()
{
    int x;
    cin >> x;
    return x;
}

// Function to read a list of integers
vector<int> III()
{
    vector<int> v;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        v.push_back(s[i] - '0');
    }
    return v;
}

// Function to read a list of lists (2D array)
vector<vector<int>> Line(int N)
{
    vector<vector<int>> v(N);
    for (int i = 0; i < N; i++)
    {
        v[i] = III();
    }
    return v;
}

// Function to read a string
string S()
{
    string s;
    cin >> s;
    return s;
}

// Function to print an integer
void O(int x)
{
    cout << x << endl;
}

// Function to print a list of integers
void OO(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

// Function to print a list of lists (2D array)
void OOO(vector<vector<int>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        OO(v[i]);
    }
}

// Function to print a string
void OS(string s)
{
    cout << s << endl;
}

// Function to print a list of strings
void OOS(vector<string> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
}

// Function to print a list of lists (2D array)
void OOOS(vector<vector<string>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        OOS(v[i]);
    }
}

// Function to print a list of pairs
void OOP(vector<pair<int, int>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].first << " " << v[i].second << endl;
    }
}

// Function to print a list of lists (2D array)
void OOOP(vector<vector<pair<int, int>>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        OOP(v[i]);
    }
}

// Function to print a list of lists (2D array)
void OOOOP(vector<vector<vector<pair<int, int>>>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        OOOP(v[i]);
    }
}

// Function to print a list of lists (2D array)
void OOOOOP(vector<vector<vector<vector<pair<int, int>>>>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        OOOOP(v[i]);
    }
}

// Function to print a list of lists (2D array)
void OOOOOOP(vector<vector<vector<vector<vector<pair<int, int>>>>>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        OOOOOP(v[i]);
    }
}

// Function to print a list of lists (2D array)
void OOOOOOOP(vector<vector<vector<vector<vector<vector<pair<int, int>>>>>>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        OOOOOOP(v[i]);
    }
}

// Function to print a list of lists (2D array)
void OOOOOOOOP(vector<vector<vector<vector<vector<vector<vector<pair<int, int>>>>>>>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        OOOOOOOP(v[i]);
    }
}

// Function to print a list of lists (2D array)
void OOOOOOOOOP(vector<vector<vector<vector<vector<vector<vector<vector<pair<int, int>>>>>>>>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        OOOOOOOOP(v[i]);
    }
}

// Function to print a list of lists (2D array)
void OOOOOOOOOOP(vector<vector<vector<vector<vector<vector<vector<vector<vector<pair<int, int>>>>>>>>>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        OOOOOOOOOP(v[i]);
    }
}

// Function to print a list of lists (2D array)
void OOOOOOOOOOOP(vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pair<int, int>>>>>>>>>>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        OOOOOOOOOOP(v[i]);
    }
}

// Function to print a list of lists (2D array)
void OOOOOOOOOOOOP(vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pair<int, int>>>>>>>>>>>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        OOOOOOOOOOOP(v[i]);
    }
}

// Function to print a list of lists (2D array)
void OOOOOOOOOOOOOP(vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pair<int, int>>>>>>>>>>>>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        OOOOOOOOOOOOP(v[i]);
    }
}

// Function to print a list of lists (2D array)
void OOOOOOOOOOOOOOP(vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pair<int, int>>>>>>>>>>>>>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        OOOOOOOOOOOOOP(v[i]);
    }
}

// Function to print a list of lists (2D array)
void OOOOOOOOOOOOOOOP(vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pair<int, int>>>>>>>>>>>>>>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        OOOOOOOOOOOOOOP(v[i]);
    }
}

// Function to print a list of lists (2D array)
void OOOOOOOOOOOOOOOOP(vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pair<int, int>>>>>>>>>>>>>>>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        OOOOOOOOOOOOOOOP(v[i]);
    }
}

// Function to print a list of lists (2D array)
void OOOOOOOOOOOOOOOOOP(vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pair<int, int>>>>>>>>>>>>>>>>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        OOOOOOOOOOOOOOOOP(v[i]);
    }
}

// Function to print a list of lists (2D array)
void OOOOOOOOOOOOOOOOOOP(vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pair<int, int>>>>>>>>>>>>>>>>>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        OOOOOOOOOOOOOOOOOP(v[i]);
    }
}

// Function to print a list of lists (2D array)
void OOOOOOOOOOOOOOOOOOOP(vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pair<int, int>>>>>>>>>>>>>>>>>>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        OOOOOOOOOOOOOOOOOOP(v[i]);
    }
}

// Function to print a list of lists (2D array)
void OOOOOOOOOOOOOOOOOOOOP(vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pair<int, int>>>>>>>>>>>>>>>>>>>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        OOOOOOOOOOOOOOOOOOOP(v[i]);
    }
}

// Function to print a list of lists (2D array)
void OOOOOOOOOOOOOOOOOOOOOP(vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pair<int, int>>>>>>>>>>>>>>>>>>>>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        OOOOOOOOOOOOOOOOOOOOP(v[i]);
    }
}

// Function to print a list of lists (2D array)
void OOOOOOOOOOOOOOOOOOOOOOP(vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pair<int, int>>>>>>>>>>>>>>>>>>>>>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        OOOOOOOOOOOOOOOOOOOOOP(v[i]);
    }
}

// Function to print a list of lists (2D array)
void OOOOOOOOOOOOOOOOOOOOOOOP(vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pair<int, int>>>>>>>>>>>>>>>>>>>>>>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        OOOOOOOOOOOOOOOOOOOOOOP(v[i]);
    }
}

// Function to print a list of lists (2D array)
void OOOOOOOOOOOOOOOOOOOOOOOOOP(vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pair<int, int>>>>>>>>>>>>>>>>>>>>>>>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        OOOOOOOOOOOOOOOOOOOOOOOOP(v[i]);
    }
}

// Function to print a list of lists (2D array)
void OOOOOOOOOOOOOOOOOOOOOOOOOOOP(vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pair<int, int>>>>>>>>>>>>>>>>>>>>>>>>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        OOOOOOOOOOOOOOOOOOOOOOOOOOOP(v[i]);
    }
}

// Function to print a list of lists (2D array)
void OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOP(vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pair<int, int>>>>>>>>>>>>>>>>>>>>>>>>>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOP(v[i]);
    }
}

// Function to print a list of lists (2D array)
void OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOP(vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pair<int, int>>>>>>>>>>>>>>>>>>>>>>>>>>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOP(v[i]);
    }
}

// Function to print a list of lists (2D array)
void OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOP(vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pair<int, int>>>>>>>>>>>>>>>>>>>>>>>>>>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOP(v[i]);
    }
}

// Function to print a list of lists (2D array)
void OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOP(vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<pair<int, int>>>>>>>>>>>>>>>>>>>>>>>>>>>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOP(v[i]);
    }
}

// Function to print a list of lists (2D array)
void OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOP(vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vec