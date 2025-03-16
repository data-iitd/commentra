
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main() {
vector<string> scList;
string line;
while (getline(cin, line)) {
scList.push_back(line);
}

string numlist = scList[0];
stringstream ss(numlist);
string item;
vector<string> tokens;
while (getline(ss, item,'')) {
tokens.push_back(item);
}

int Sheep = stoi(tokens[0]);
int Wolve = stoi(tokens[1]);

if (Wolve >= Sheep) {
cout << "unsafe" << endl;
} else {
cout << "safe" << endl;
}

return 0;
}
//END-OF-CODE