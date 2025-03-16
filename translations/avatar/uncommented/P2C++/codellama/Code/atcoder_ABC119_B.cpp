
#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    double x[N];
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        if (s.find("JPY") != string::npos)
            x[i] = stod(s.replace(s.find("JPY"), 3, "")) * 1.0;
        else if (s.find("BTC") != string::npos)
            x[i] = stod(s.replace(s.find("BTC"), 3, "")) * 380000.0;
    }
    double sum = 0;
    for (int i = 0; i < N; i++)
        sum += x[i];
    cout << sum << endl;
    return 0;
}

