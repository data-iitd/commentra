
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct work{
    int time;
    int limit;
};

bool compare(work a, work b){
    return a.limit < b.limit;
}

int main(){
    int n;
    cin >> n;
    
    vector<work> ws(n);
    
    for(int i = 0; i < n; i++){
        int a, n;
        cin >> a >> n;
        ws[i].time = a;
        ws[i].limit = n;
    }
    
    sort(ws.begin(), ws.end(), compare);
    
    long long sum = 0;
    
    for(int i = 0; i < n; i++){
        sum += ws[i].time;
        
        if(sum > ws[i].limit){
            cout << "No" << endl;
            return 0;
        }
    }
    
    cout << "Yes" << endl;
    
    return 0;
}

