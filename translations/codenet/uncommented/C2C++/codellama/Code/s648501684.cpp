#include <iostream>

int main()
{
   long int n, k, q;
   
   std::cin >> n >> k >> q;
   
    int arr[n];
    for(long int i=0; i<=n; i++) {
        arr[i] = 0;
    }
    
    
    for(long int i=0; i<q; i++) {
        long int temp;
        std::cin >> temp;
        arr[temp] += 1;
    }
    
    for(long int i=1; i<=n; i++) {
        if(arr[i]>(q-k)) {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }
    }

    return 0;
}

