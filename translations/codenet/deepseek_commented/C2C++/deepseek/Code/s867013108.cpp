#include <iostream>
#define DAYS 365  // Maximum number of days

int main()
{
    int n, i;
    int nyuyoku_ticket[DAYS], pool_ticket[DAYS];  // Prices of tickets for each day
    int nyuyoku_member[DAYS], pool_member[DAYS];  // Number of tickets each member will use for each day
    int seiki_ryoukin[DAYS], waribiki_ryoukin[DAYS], saiyasune[DAYS];  // Costs and final costs for each day

    // Read the number of days
    std::cin >> n;

    // Loop through each day
    for (i = 0; i < n; i++)
    {
        // Read the ticket prices and usage counts for the day
        std::cin >> nyuyoku_ticket[i] >> pool_ticket[i] >> nyuyoku_member[i] >> pool_member[i];

        // Check if the group qualifies for a discount
        if (nyuyoku_member[i] >= 5 && pool_member[i] >= 2)
        {
            // Calculate the cost with the maximum discount
            seiki_ryoukin[i] = (nyuyoku_ticket[i] * nyuyoku_member[i] + pool_ticket[i] * pool_member[i]) * 8 / 10;
            saiyasune[i] = seiki_ryoukin[i];
        }
        else if (nyuyoku_member[i] >= 5)
        {
            // Calculate the normal cost and the discounted cost if applicable
            seiki_ryoukin[i] = nyuyoku_ticket[i] * nyuyoku_member[i] + pool_ticket[i] * pool_member[i];
            waribiki_ryoukin[i] = (nyuyoku_ticket[i] * nyuyoku_member[i] + pool_ticket[i] * 2) * 8 / 10;
            if (seiki_ryoukin[i] >= waribiki_ryoukin[i])
            {
                saiyasune[i] = waribiki_ryoukin[i];
            }
            else
            {
                saiyasune[i] = seiki_ryoukin[i];
            }
        }
        else if (pool_member[i] >= 2)
        {
            // Calculate the normal cost and the discounted cost if applicable
            seiki_ryoukin[i] = nyuyoku_ticket[i] * nyuyoku_member[i] + pool_ticket[i] * pool_member[i];
            waribiki_ryoukin[i] = (nyuyoku_ticket[i] * 5 + pool_ticket[i] * pool_member[i]) * 8 / 10;
            if (seiki_ryoukin[i] >= waribiki_ryoukin[i])
            {
                saiyasune[i] = waribiki_ryoukin[i];
            }
            else
            {
                saiyasune[i] = seiki_ryoukin[i];
            }
        }
        else
        {
            // Calculate the normal cost and the discounted cost if applicable
            seiki_ryoukin[i] = nyuyoku_ticket[i] * nyuyoku_member[i] + pool_ticket[i] * pool_member[i];
            waribiki_ryoukin[i] = (nyuyoku_ticket[i] * 5 + pool_ticket[i] * 2) * 8 / 10;
            if (seiki_ryoukin[i] >= waribiki_ryoukin[i])
            {
                saiyasune[i] = waribiki_ryoukin[i];
            }
            else
            {
                saiyasune[i] = seiki_ryoukin[i];
            }
        }
    }

    // Output the cheapest total cost for each day
    for (i = 0; i < n; i++)
    {
        std::cout << saiyasune[i] << std::endl;
    }

    return 0;
}
