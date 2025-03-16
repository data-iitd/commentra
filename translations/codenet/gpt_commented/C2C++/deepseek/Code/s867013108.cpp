#include <iostream>
#include <vector>
#define DAYS 365

int main() {
    int n, i;
    std::vector<int> nyuyoku_ticket(DAYS), pool_ticket(DAYS);
    std::vector<int> nyuyoku_member(DAYS), pool_member(DAYS);
    std::vector<int> seiki_ryoukin(DAYS), waribiki_ryoukin(DAYS), saiyasune(DAYS);

    std::cin >> n;
    for (i = 0; i < n; i++) {
        std::cin >> nyuyoku_ticket[i] >> pool_ticket[i] >> nyuyoku_member[i] >> pool_member[i];

        if (nyuyoku_member[i] >= 5 && pool_member[i] >= 2) {
            seiki_ryoukin[i] = ((nyuyoku_ticket[i] * nyuyoku_member[i] + pool_ticket[i] * pool_member[i]) * 8) / 10;
            saiyasune[i] = seiki_ryoukin[i];
        } else if (nyuyoku_member[i] >= 5) {
            seiki_ryoukin[i] = nyuyoku_ticket[i] * nyuyoku_member[i] + pool_ticket[i] * pool_member[i];
            waribiki_ryoukin[i] = ((nyuyoku_ticket[i] * nyuyoku_member[i] + pool_ticket[i] * 2) * 8) / 10;
            saiyasune[i] = (seiki_ryoukin[i] >= waribiki_ryoukin[i]) ? waribiki_ryoukin[i] : seiki_ryoukin[i];
        } else if (pool_member[i] >= 2) {
            seiki_ryoukin[i] = nyuyoku_ticket[i] * nyuyoku_member[i] + pool_ticket[i] * pool_member[i];
            waribiki_ryoukin[i] = ((nyuyoku_ticket[i] * 5 + pool_ticket[i] * pool_member[i]) * 8) / 10;
            saiyasune[i] = (seiki_ryoukin[i] >= waribiki_ryoukin[i]) ? waribiki_ryoukin[i] : seiki_ryoukin[i];
        } else {
            seiki_ryoukin[i] = nyuyoku_ticket[i] * nyuyoku_member[i] + pool_ticket[i] * pool_member[i];
            waribiki_ryoukin[i] = ((nyuyoku_ticket[i] * 5 + pool_ticket[i] * 2) * 8) / 10;
            saiyasune[i] = (seiki_ryoukin[i] >= waribiki_ryoukin[i]) ? waribiki_ryoukin[i] : seiki_ryoukin[i];
        }
    }

    for (i = 0; i < n; i++) {
        std::cout << saiyasune[i] << std::endl;
    }

    return 0;
}
