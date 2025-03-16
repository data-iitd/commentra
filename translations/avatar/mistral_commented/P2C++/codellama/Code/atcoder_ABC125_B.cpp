#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> V;
    string V_temp;
    getline(cin, V_temp);
    stringstream V_stream(V_temp);
    int V_temp_i;
    while (V_stream >> V_temp_i)
    {
        V.push_back(V_temp_i);
    }

    vector<int> C;
    string C_temp;
    getline(cin, C_temp);
    stringstream C_stream(C_temp);
    int C_temp_i;
    while (C_stream >> C_temp_i)
    {
        C.push_back(C_temp_i);
    }

    vector<int> list;
    int ans = 0;
    int X = 0;
    int Y = 0;

    for (int i = 0; i < N; i++)
    {
        if (V[i] - C[i] > 0)
        {
            X = V[i];
            Y = C[i];
            list.push_back(X - Y);
            ans += X - Y;
        }
    }

    cout << sum(list.begin(), list.end()) << endl;
    cout << ans << endl;

    return 0;
}

