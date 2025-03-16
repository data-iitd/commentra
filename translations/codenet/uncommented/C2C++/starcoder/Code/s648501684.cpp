#include <iostream>

using namespace std;

int main()
{
   long int n, k, q;
   
   cin>>n>>k>>q;
   
    int arr[n];
    for(long int i=0; i<=n; i++) {
        arr[i] = 0;
    }
    
    
    for(long int i=0; i<q; i++) {
        long int temp;
        cin>>temp;
        arr[temp] += 1;
    }
    
    for(long int i=1; i<=n; i++) {
        if(arr[i]>(q-k)) {
            cout<<"Yes"<<endl;
        } else {
            cout<<"No"<<endl;
        }
    }

    return 0;
}

