
#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
    int pya;
    cin >> pya;
    string arre[pya];

    for (int i = 0; i < pya; i++)
    {
        cin >> arre[i];
    }

    string oString;
    cin >> oString;
    string lowString = oString;
    transform(lowString.begin(), lowString.end(), lowString.begin(), ::tolower);

    string letter1;
    cin >> letter1;
    string letter2 = "a";
    if (letter1 != "a")
    {
        letter2 = "b";
    }

    int valid[oString.length()];
    set<int> setcito;

    for (int i = 0; i < pya; i++)
    {
        int wat = 0;
        while (true)
        {
            int index = lowString.find(arre[i], wat);
            if (index < 0)
            {
                break;
            }
            for (int j = index; j < index + arre[i].length(); j++)
            {
                setcito.insert(j);
            }
            wat = index + 1;
        }
    }

    vector<char> oStringVec(oString.begin(), oString.end());

    for (int i : setcito)
    {
        char letter = letter1[0];
        if (lowString[i] != letter1[0])
        {
            letter = letter2[0];
        }
        if (oStringVec[i] >= 'a' && oStringVec[i] <= 'z')
        {
            oStringVec[i] = letter;
        }
        else
        {
            oStringVec[i] = toupper(letter);
        }
    }

    for (char x : oStringVec)
    {
        cout << x;
    }
    cout << endl;

    return 0;
}

