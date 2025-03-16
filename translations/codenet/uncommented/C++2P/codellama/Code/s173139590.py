#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;

    int ac_count = 0;
    int wa_count = 0;
    int tle_count = 0;
    int re_count = 0;
    for i in range(n):
        s = input()
        if s=="AC":
            ac_count+=1
        elif s=="WA":
            wa_count+=1
        elif s=="TLE":
            tle_count+=1
        elif s=="RE":
            re_count+=1
    print("AC x", ac_count)
    print("WA x", wa_count)
    print("TLE x", tle_count)
    print("RE x", re_count)
}

