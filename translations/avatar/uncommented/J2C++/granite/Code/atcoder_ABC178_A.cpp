
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    int x = atoi(s.c_str());
    bool bool = x == 1? true : false;
    int result =!bool? 1 : 0;
    printf("%d\n", result);
    return 0;
}
//END-OF-CODE