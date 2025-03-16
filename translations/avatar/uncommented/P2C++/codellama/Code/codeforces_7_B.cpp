#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    int t, m;
    cin >> t >> m;
    vector<int> alocuente(m, 0);
    int ind = 1;
    for (int i = 0; i < t; i++)
    {
        string op;
        cin >> op;
        if (op == "alloc")
        {
            int pos = 0;
            for (int j = 0; j < m; j++)
            {
                if (alocuente[j] == 0)
                {
                    pos++;
                    if (pos == stoi(op.substr(op.find(" ") + 1)))
                    {
                        for (int k = j - stoi(op.substr(op.find(" ") + 1)) + 1; k <= j; k++)
                        {
                            alocuente[k] = ind;
                        }
                        cout << ind << endl;
                        ind++;
                        break;
                    }
                }
                else
                {
                    pos = 0;
                }
            }
            if (pos == 0)
            {
                cout << "NULL" << endl;
            }
        }
        if (op == "erase")
        {
            int pos = 0;
            if (stoi(op.substr(op.find(" ") + 1)) == 0 || stoi(op.substr(op.find(" ") + 1)) > m)
            {
                cout << "ILLEGAL_ERASE_ARGUMENT" << endl;
            }
            else
            {
                for (int j = 0; j < m; j++)
                {
                    if (stoi(op.substr(op.find(" ") + 1)) > 0 && alocuente[j] == stoi(op.substr(op.find(" ") + 1)))
                    {
                        alocuente[j] = 0;
                    }
                }
            }
        }
        if (op == "defragment")
        {
            int cnt = 0;
            cnt = count(alocuente.begin(), alocuente.end(), 0);
            alocuente.erase(remove(alocuente.begin(), alocuente.end(), 0), alocuente.end());
            for (int j = 0; j < cnt; j++)
            {
                alocuente.push_back(0);
            }
        }
    }
    return 0;
}



