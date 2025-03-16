#include <iostream>
#define		DAYS	365		// 最大何日か？

int main(void)
{
	int n, i;
	int nyuyoku_ticket[DAYS], pool_ticket[DAYS];
	int	nyuyoku_member[DAYS], pool_member[DAYS];
	int seiki_ryoukin[DAYS], waribiki_ryoukin[DAYS], saiyasune[DAYS];

	/* 入場料金を入力受ける */
	std::cin >> n;

	/* 各日の入浴券とプール券の料金、使用数を入力受ける */
	for( i = 0; i < n; i++ )
	{
		std::cin >> nyuyoku_ticket[i] >> pool_ticket[i] >> nyuyoku_member[i] >> pool_member[i];

		/* 割引ルールをチェックして、最も安い合計料金を計算 */
		if( nyuyoku_member[i] >= 5 && pool_member[i] >= 2 )
		{
			seiki_ryoukin[i] = ( ( ( nyuyoku_ticket[i] * nyuyoku_member[i] ) + ( pool_ticket[i] * pool_member[i] ) ) * 8 ) / 10;
			saiyasune[i] = seiki_ryoukin[i];
		}
		else if( nyuyoku_member[i] >= 5 )
		{
			seiki_ryoukin[i] = ( nyuyoku_ticket[i] * nyuyoku_member[i] ) + ( pool_ticket[i] * pool_member[i] );
			waribiki_ryoukin[i] = ( ( ( nyuyoku_ticket[i] * 5 ) + ( pool_ticket[i] * pool_member[i] ) ) * 8 ) / 10;
			if( seiki_ryoukin[i] >= waribiki_ryoukin[i] )
			{
				saiyasune[i] = waribiki_ryoukin[i];
			}
			else
			{
				saiyasune[i] = seiki_ryoukin[i];
			}
		}
		else if( pool_member[i] >= 2 )
		{
			seiki_ryoukin[i] = ( nyuyoku_ticket[i] * nyuyoku_member[i] ) + ( pool_ticket[i] * pool_member[i] );
			waribiki_ryoukin[i] = ( ( ( nyuyoku_ticket[i] * 5 ) + ( pool_ticket[i] * pool_member[i] ) ) * 8 ) / 10;
			if( seiki_ryoukin[i] >= waribiki_ryoukin[i] )
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
			seiki_ryoukin[i] = ( nyuyoku_ticket[i] * nyuyoku_member[i] ) + ( pool_ticket[i] * pool_member[i] );
			waribiki_ryoukin[i] = ( ( ( nyuyoku_ticket[i] * 5 ) + ( pool_ticket[i] * 2 ) ) * 8 ) / 10;
			if( seiki_ryoukin[i] >= waribiki_ryoukin[i] )
			{
				saiyasune[i] = waribiki_ryoukin[i];
			}
			else
			{
				saiyasune[i] = seiki_ryoukin[i];
			}
		}
	}

	/* 各日の最も安い合計料金を出力 */
	for( i = 0; i < n; i++ )
	{
		std::cout << saiyasune[i] << std::endl;
	}

	return 0;
}

