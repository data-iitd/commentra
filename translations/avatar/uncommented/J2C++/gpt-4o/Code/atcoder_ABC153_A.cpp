#include <iostream>
using namespace std;

int main() {
    int h, a;
    cin >> h >> a;
    int num = 0;
    
    while (h > 0) {
        h -= a;
        num++;
    }
    
    cout << num << endl;
    return 0;
}

// <END-OF-CODE>
