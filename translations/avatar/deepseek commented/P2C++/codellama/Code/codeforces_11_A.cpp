
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main () {
    int n, d;
    cin >> n >> d;
    // Taking input for two variables `n` and `d`

    vector <int> x;
    int m = 0, q = 0;
    // Initializing an empty vector `x` and two integer variables `m` and `q` to 0

    string s;
    cin >> s;
    // Taking input for the list `x` as a string

    stringstream ss(s);
    string temp;
    while (getline(ss, temp, ' ')) {
        x.push_back(stoi(temp));
    }
    // Converting the elements of the list `x` to integers

    for (int a = 0; a < x.size() - 1; a++) {
        if (x[a] >= x[a + 1]) {
            q = (x[a] - x[a + 1]) / d + 1;
            m = m + q;
            x[a + 1] = x[a + 1] + q * d;
        }
    }
    // Checking if the current element is greater than or equal to the next element
    // Calculating the number of steps `q` needed to make the current element less than the next element by at least `d`
    // Updating the value of `m` by adding `q` to it
    // Updating the next element in the list `x` by adding `q * d` to it

    cout << m << endl;
    // Printing the value of `m`

    return 0;
}

