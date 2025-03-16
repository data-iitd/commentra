#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
    string inputNumbers;
    string temp;
    int a, b, c, d;
    int sum;
    string symbols[3];

    cin >> inputNumbers;

    temp = inputNumbers.substr(0, 1);
    a = stoi(temp);
    temp = inputNumbers.substr(1, 1);
    b = stoi(temp);
    temp = inputNumbers.substr(2, 1);
    c = stoi(temp);
    temp = inputNumbers.substr(3, 1);
    d = stoi(temp);

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                if (i == 0)
                {
                    sum = a + b;
                    symbols[0] = "+";
                }
                else
                {
                    sum = a - b;
                    symbols[0] = "-";
                }

                if (j == 0)
                {
                    sum = sum + c;
                    symbols[1] = "+";
                }
                else
                {
                    sum = sum - c;
                    symbols[1] = "-";
                }

                if (k == 0)
                {
                    sum = sum + d;
                    symbols[2] = "+";
                }
                else
                {
                    sum = sum - d;
                    symbols[2] = "-";
                }

                if (sum == 7)
                {
                    cout << a << symbols[0] << b << symbols[1] << c << symbols[2] << d << "=7" << endl;
                    return 0;
                }
            }
        }
    }

    return 0;
}
