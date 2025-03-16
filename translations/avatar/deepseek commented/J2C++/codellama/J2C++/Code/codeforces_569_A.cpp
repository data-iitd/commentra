
#include <iostream>

using namespace std;

int main() {
    int T, S, q, previous, answer;
    
    cin >> T >> S >> q;
    
    previous = S;
    answer = 0;
    
    while (previous < T) {
        previous *= q;
        answer++;
    }
    
    cout << answer << endl;
    
    return 0;
}

