
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, m, pos, ind = 1, cnt = 0;
    cin >> t >> m;
    vector<int> alocuente(m, 0);
    for (int i = 0; i < t; i++)
    {
        string op;
        cin >> op;
        if (op == "alloc")
        {
            pos = 0;
            for (int j = 0; j < m; j++)
            {
                if (alocuente[j] == 0)
                {
                    pos++;
                    if (pos == stoi(op.substr(1)))
                    {
                        alocuente[j - stoi(op.substr(1)) + 1 : j + 1] = vector<int>(stoi(op.substr(1)), ind);
                        cout << ind << endl;
                        ind++;
                        break;
                    }
                }
                else
                    pos = 0;
            }
            if (pos!= stoi(op.substr(1)))
                cout << "NULL" << endl;
        }
        else if (op == "erase")
        {
            pos = 0;
            if (stoi(op.substr(1)) not in alocuente or stoi(op.substr(1)) == 0)
                cout << "ILLEGAL_ERASE_ARGUMENT" << endl;
            else
            {
                for (int j = 0; j < m; j++)
                {
                    if (stoi(op.substr(1)) > 0 and alocuente[j] == stoi(op.substr(1)))
                    {
                        alocuente[j] = 0;
                    }
                }
            }
        }
        else if (op == "defragment")
        {
            cnt = 0;
            cnt = count(alocuente.begin(), alocuente.end(), 0);
            alocuente.erase(remove(alocuente.begin(), alocuente.end(), 0), alocuente.end());
            for (int j = 0; j < cnt; j++)
                alocuente.push_back(0);
        }
    }
    return 0;
}

