
#include <iostream>
using namespace std;
int main(){
    int in;
    int h,m,s;
    cin >> in;

    h = in / 3600;
    in %= 3600;

    m = in / 60;
    in %= 60;

    s = in;

    cout << h << ":" << m << ":" << s << endl;
}
