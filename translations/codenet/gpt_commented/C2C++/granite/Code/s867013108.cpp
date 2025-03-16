
/*
	C++ では main() ではなく int main() として記述する。
	main()  は int 型の値を返す必要がある。
	したがって、C++ では main()  の戻り値を明示的に int 型にキャストして返す必要がある。
*/

#include <iostream>
#define DAYS 365	//   maximum number of days

int main(void)
{
	int n, i; // Declare variables for number of days and loop index
	int nyuyoku_ticket[DAYS], pool_ticket[DAYS]; // Arrays to store ticket prices for each day
	int nyuyoku_member[DAYS], pool_member[DAYS]; // Arrays to store the number of tickets used for each day
	int seiki_ryoukin[DAYS], waribiki_ryoukin[DAYS], saiyasune[DAYS]; // Arrays to store calculated prices

	std::cin >> n; // Input the number of days for which prices need to be calculated
	for (i = 0; i < n; i++)
	{
		// Input ticket prices and the number of tickets used for the current day
		std::cin >> nyuyoku_ticket[i] >> pool_ticket[i] >> nyuyoku_member[i] >> pool_member[i];

		// Check if the discount condition for both tickets is met
		if (nyuyoku_member[i] >= 5 && pool_member[i] >= 2)
		{
			// Calculate the total price with discount
			seiki_ryoukin[i] = ((((nyuyoku_ticket[i] * nyuyoku_member[i]) + (pool_ticket[i] * pool_member[i])) * 8) / 10);
			saiyasune[i] = seiki_ryoukin[i]; // Store the discounted price
		}
		// Check if only the nyuyoku ticket discount condition is met
		else if (nyuyoku_member[i] >= 5)
		{
			// Calculate the total price without discount
			seiki_ryoukin[i] = (nyuyoku_ticket[i] * nyuyoku_member[i]) + (pool_ticket[i] * pool_member[i]);
			// Calculate the price with discount for pool tickets
			waribiki_ryoukin[i] = ((((nyuyoku_ticket[i] * nyuyoku_member[i]) + (pool_ticket[i] * 2)) * 8) / 10);
			// Compare and store the cheaper option
			if (seiki_ryoukin[i] >= waribiki_ryoukin[i])
			{
				saiyasune[i] = waribiki_ryoukin[i];
			}
			else
			{
				saiyasune[i] = seiki_ryoukin[i];
			}
		}
		// Check if only the pool ticket discount condition is met
		else if (pool_member[i] >= 2)
		{
			// Calculate the total price without discount
			seiki_ryoukin[i] = (nyuyoku_ticket[i] * nyuyoku_member[i]) + (pool_ticket[i] * pool_member[i]);
			// Calculate the price with discount for nyuyoku tickets
			waribiki_ryoukin[i] = ((((nyuyoku_ticket[i] * 5) + (pool_ticket[i] * pool_member[i])) * 8) / 10);
			// Compare and store the cheaper option
			if (seiki_ryoukin[i] >= waribiki_ryoukin[i])
			{
				saiyasune[i] = waribiki_ryoukin[i];
			}
			else
			{
				saiyasune[i] = seiki_ryoukin[i];
			}
		}
		// If no discount conditions are met
		else
		{
			// Calculate the total price without discount
			seiki_ryoukin[i] = (nyuyoku_ticket[i] * nyuyoku_member[i]) + (pool_ticket[i] * pool_member[i]);
			// Calculate the price with discount for both tickets
			waribiki_ryoukin[i] = ((((nyuyoku_ticket[i] * 5) + (pool_ticket[i] * 2)) * 8) / 10);
			// Compare and store the cheaper option
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
	// Output the cheapest total price for each day
	for (i = 0; i < n; i++)
	{
		std::cout << saiyasune[i] << std::endl;
	}
	return 0; // End of the program
}

