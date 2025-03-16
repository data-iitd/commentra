#include <iostream>
#include <vector>

int main()
{
   long int n, k, q;
   
   std::cin >> n >> k >> q;
   
   std::vector<int> arr(n+1, 0);
    
    for(long int i=0; i<q; i++) {
        long int temp;
        std::cin >> temp;
        arr[temp] += 1;
    }
    
    for(long int i=1; i<=n; i++) {
        if(arr[i]>(q-k)) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }

    return 0;
}
