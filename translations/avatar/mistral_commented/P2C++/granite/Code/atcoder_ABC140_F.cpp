
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to read an integer from standard input
int I(){
    int x;
    cin >> x;
    return x;
}

// Function to read a list of integers from standard input
vector<int> LI(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    return v;
}

// Main function to solve the problem
string solve(){
    int N = I();
    vector<int> S = LI();
    sort(S.begin(), S.end(), greater<int>());

    vector<bool> flag(N, true);
    vector<int> cur;

    cur.push_back(S[0]);
    flag[0] = false;

    for(int i=0; i<N; i++){
        int j = 0;
        int jM = cur.size();
        for(int k=0; k<N; k++){
            if(flag[k] && S[k] < cur[j]){
                cur.push_back(S[k]);
                j++;
                flag[k] = false;
                if(j == jM) break;
            }
        }
        if(j == jM) return "No";
        sort(cur.begin(), cur.end(), greater<int>());
    }

    return "Yes";
}

int main(){
    cout << solve() << endl;
    return 0;
}

