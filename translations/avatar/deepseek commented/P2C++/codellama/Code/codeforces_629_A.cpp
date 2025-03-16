
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string line;
    int chocCount = 0;
    int nfat = 1;
    int happiness = 0;
    int posCount = 0;
    string cake[n];

    for (int i = 0; i < n; i++)
    {
        cin >> line;
        cake[i] = line;
        for (int j = 0; j < line.length(); j++)
        {
            if (cake[i][j] == 'C')
            {
                chocCount++;
            }
        }
        if (chocCount > 1)
        {
            for (int i = chocCount; i > chocCount - 2; i--)
            {
                nfat *= i;
            }
            happiness += nfat / 2;
        }
        nfat = 1;
        chocCount = 0;
    }

    for (int j = 0; j < n; j++)
    {
        chocCount = 0;
        for (int i = 0; i < n; i++)
        {
            if (cake[i][j] == 'C')
            {
                chocCount++;
            }
        }
        if (chocCount > 1)
        {
            for (int i = chocCount; i > chocCount - 2; i--)
            {
                nfat *= i;
            }
            happiness += nfat / 2;
        }
        nfat = 1;
        chocCount = 0;
    }

    cout << happiness << endl;

    return 0;
}

