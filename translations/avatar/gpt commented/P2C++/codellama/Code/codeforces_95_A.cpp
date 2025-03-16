#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int main()
{
    int pya;
    cin >> pya;
    vector<string> arre;
    for (int i = 0; i < pya; i++)
    {
        string temp;
        cin >> temp;
        arre.push_back(temp);
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
    vector<int> valid(oString.length(), 0);
    set<int> setcito;
    for (string x : arre)
    {
        int wat = 0;
        while (true)
        {
            int index = lowString.find(x, wat);
            if (index < 0)
            {
                break;
            }
            for (int i = index; i < index + x.length(); i++)
            {
                setcito.insert(i);
            }
            wat = index + 1;
        }
    }
    vector<char> oString_vec(oString.begin(), oString.end());
    for (int i : setcito)
    {
        char letter = letter1[0];
        if (lowString[i] != letter1[0])
        {
            letter = letter2[0];
        }
        if (oString_vec[i] >= 'a' && oString_vec[i] <= 'z')
        {
            oString_vec[i] = letter;
        }
        else
        {
            oString_vec[i] = letter - 32;
        }
    }
    for (char x : oString_vec)
    {
        cout << x;
    }
    cout << endl;
    return 0;
}

