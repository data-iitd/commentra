
#include <bits/stdc++.h>
using namespace std;

int main() {
    string sa, sb;
    cin >> sa >> sb;
    int a = stoi(sa);
    int b = stoi(sb.substr(0, sb.find('.'))) * 100 + stoi(sb.substr(sb.find('.') + 1));
    cout << a * b / 100 << endl;
    return 0;
}
//END-OF-CODE