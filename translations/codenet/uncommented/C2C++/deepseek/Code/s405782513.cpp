#include <iostream>
#include <vector>

int main()
{
    std::vector<int> c(3);
    
    while (std::cin >> c[0] >> c[1] >> c[2]) {
        std::vector<int> card(10, 0);
        int sum = c[0] + c[1];
        
        for (int i = 0; i < 3; i++) {
            card[c[i] - 1] = 1;
        }
        
        int count = 0;
        for (int i = 0; i < 10; i++) {
            if (card[i] == 0 && sum + i + 1 <= 20) {
                count++;
            }
        }
        
        if (count >= 4) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }
    
    return 0;
}
