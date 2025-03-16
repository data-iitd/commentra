
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> m(N, 0);
    vector<int> f(N, 0);

    int num_operations;
    cin >> num_operations;

    for (int i = 0; i < num_operations; i++)
    {
        string gender, start_time, end_time;
        cin >> gender >> start_time >> end_time;

        int start_time_int = stoi(start_time);
        int end_time_int = stoi(end_time) + 1;

        if (gender == "M")
        {
            m[start_time_int] += 2;
            m[end_time_int] -= 2;
        }
        else
        {
            f[start_time_int] += 2;
            f[end_time_int] -= 2;
        }
    }

    int a = 0, b = 0, c = 0;

    for (int i = 0; i < N; i++)
    {
        a += m[i];
        b += f[i];
        if (min(a, b) > c)
        {
            c = min(a, b);
        }
    }

    cout << c << endl;

    return 0;
}

