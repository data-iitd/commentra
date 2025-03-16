#include <iostream>
using namespace std;

int main()
{
    // Read the number of currency inputs from the user
    int N;
    cin >> N;

    // Create a list of converted currency values
    // For each input, replace 'JPY' with its equivalent in float and 'BTC' with its equivalent in float
    float x[N];
    for (int i = 0; i < N; i++)
    {
        string input;
        cin >> input;
        x[i] = eval(input.replace("JPY", "* 1.0").replace("BTC", "* 380000.0"));
    }

    // Calculate and print the total sum of the converted currency values
    float sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += x[i];
    }
    cout << sum << endl;

    return 0;
}

