#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int t, m;
    cin >> t >> m;
    vector<int> alocuente(m);
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
                    if (pos == stoi(op.substr(1)))
                    {
                        for (int k = j - stoi(op.substr(1)) + 1; k <= j; k++)
                            alocuente[k] = ind;
                        cout << ind << endl;
                        ind++;
                        break;
                    }
                }
                else
                    pos = 0;
            }
            if (pos!= 0)
                cout << "NULL" << endl;
        }
        else if (op == "erase")
        {
            int pos = 0;
            if (stoi(op.substr(1)) == 0 || stoi(op.substr(1)) > m || alocuente[stoi(op.substr(1)) - 1]!= stoi(op.substr(1)))
                cout << "ILLEGAL_ERASE_ARGUMENT" << endl;
            else
            {
                for (int j = 0; j < m; j++)
                {
                    if (alocuente[j] == stoi(op.substr(1)))
                    {
                        alocuente[j] = 0;
                        break;
                    }
                }
            }
        }
        else if (op == "defragment")
        {
            int cnt = 0;
            for (int j = 0; j < m; j++)
                if (alocuente[j] == 0)
                    cnt++;
            for (int j = 0; j < cnt; j++)
                alocuente.push_back(0);
            alocuente.erase(alocuente.begin(), alocuente.begin() + cnt);
        }
    }
    return 0;
}
