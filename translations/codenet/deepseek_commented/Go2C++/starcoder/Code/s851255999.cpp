
#include <bits/stdc++.h>
using namespace std;

int main(){
    // Read the number of works
    int n;
    cin >> n;
    
    // Create a vector of work structs with a length of n
    vector<work> ws(n);
    
    // Read the time and limit for each work and store them in the vector
    for(int i = 0; i < n; i++){
        int a, n;
        cin >> a >> n;
        ws[i] = work{a,n};
    }
    
    // Sort the vector of works based on the limit field
    sort(ws.begin(), ws.end(), [](work a, work b){ return a.limit < b.limit; });
    
    // Initialize a sum variable to keep track of the cumulative time
    int64_t sum = 0;
    
    // Iterate over the sorted vector of works, adding the time of each work to the sum
    for(auto w : ws){
        sum += w.time;
        
        // Check if the cumulative time exceeds the limit of the current work
        if(sum > w.limit){
            cout << "No" << endl;
            return 0;
        }
    }
    
    // If the loop completes without the sum exceeding any limit, print "Yes"
    cout << "Yes" << endl;
}

struct work{
    int time, limit;
};

struct works : vector<work>{
    bool operator()(work a, work b){
        return a.limit < b.limit;
    }
};

