
/*
	C++ 14
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, i;
	vector<int> nyuyoku_ticket, pool_ticket, nyuyoku_member, pool_member, seiki_ryoukin, waribiki_ryoukin, saiyasune;
	
	cin >> n;
	for( i = 0; i < n; i++ )
	{
		int x, y, b, p;
		cin >> x >> y >> b >> p;
		nyuyoku_ticket.push_back( x );
		pool_ticket.push_back( y );
		nyuyoku_member.push_back( b );
		pool_member.push_back( p );
		if( b >= 5 && p >= 2 )
		{
			seiki_ryoukin.push_back( ( ( ( x * b ) + ( y * p ) ) * 8 ) / 10 );
			saiyasune.push_back( seiki_ryoukin[i] );
		}
		else if( b >= 5 )
		{
			seiki_ryoukin.push_back( ( x * b ) + ( y * p ) );
			waribiki_ryoukin.push_back( ( ( ( x * b ) + ( y * 2 ) ) * 8 ) / 10 );
			if( seiki_ryoukin[i] >= waribiki_ryoukin[i] )
			{
				saiyasune.push_back( waribiki_ryoukin[i] );
			}
			else
			{
				saiyasune.push_back( seiki_ryoukin[i] );
			}
		}
		else if( p >= 2 )
		{
			seiki_ryoukin.push_back( ( x * b ) + ( y * p ) );
			waribiki_ryoukin.push_back( ( ( ( x * 5 ) + ( y * p ) ) * 8 ) / 10 );
			if( seiki_ryoukin[i] >= waribiki_ryoukin[i] )
			{
				saiyasune.push_back( waribiki_ryoukin[i] );
			}
			else
			{
				saiyasune.push_back( seiki_ryoukin[i] );
			}
		}
		else
		{
			seiki_ryoukin.push_back( ( x * b ) + ( y * p ) );
			waribiki_ryoukin.push_back( ( ( ( x * 5 ) + ( y * 2 ) ) * 8 ) / 10 );
			if( seiki_ryoukin[i] >= waribiki_ryoukin[i] )
			{
				saiyasune.push_back( waribiki_ryoukin[i] );
			}
			else
			{
				saiyasune.push_back( seiki_ryoukin[i] );
			}
		}
	}
	for( i = 0; i < n; i++ )
	{
		cout << saiyasune[i] << endl;
	}
	return 0;
}

/*
	C++ 17
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, i;
	vector<int> nyuyoku_ticket, pool_ticket, nyuyoku_member, pool_member, seiki_ryoukin, waribiki_ryoukin, saiyasune;
	
	cin >> n;
	for( i = 0; i < n; i++ )
	{
		int x, y, b, p;
		cin >> x >> y >> b >> p;
		nyuyoku_ticket.push_back( x );
		pool_ticket.push_back( y );
		nyuyoku_member.push_back( b );
		pool_member.push_back( p );
		if( b >= 5 && p >= 2 )
		{
			seiki_ryoukin.push_back( ( ( ( x * b ) + ( y * p ) ) * 8 ) / 10 );
			saiyasune.push_back( seiki_ryoukin[i] );
		}
		else if( b >= 5 )
		{
			seiki_ryoukin.push_back( ( x * b ) + ( y * p ) );
			waribiki_ryoukin.push_back( ( ( ( x * b ) + ( y * 2 ) ) * 8 ) / 10 );
			if( seiki_ryoukin[i] >= waribiki_ryoukin[i] )
			{
				saiyasune.push_back( waribiki_ryoukin[i] );
			}
			else
			{
				saiyasune.push_back( seiki_ryoukin[i] );
			}
		}
		else if( p >= 2 )
		{
			seiki_ryoukin.push_back( ( x * b ) + ( y * p ) );
			waribiki_ryoukin.push_back( ( ( ( x * 5 ) + ( y * p ) ) * 8 ) / 10 );
			if( seiki_ryoukin[i] >= waribiki_ryoukin[i] )
			{
				saiyasune.push_back( waribiki_ryoukin[i] );
			}
			else
			{
				saiyasune.push_back( seiki_ryoukin[i] );
			}
		}
		else
		{
			seiki_ryoukin.push_back( ( x * b ) + ( y * p ) );
			waribiki_ryoukin.push_back( ( ( ( x * 5 ) + ( y * 2 ) ) * 8 ) / 10 );
			if( seiki_ryoukin[i] >= waribiki_ryoukin[i] )
			{
				saiyasune.push_back( waribiki_ryoukin[i] );
			}
			else
			{
				saiyasune.push_back( seiki_ryoukin[i] );
			}
		}
	}
	for( i = 0; i < n; i++ )
	{
		cout << saiyasune[i] << endl;
	}
	return 0;
}

/*
	C++ 20
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, i;
	vector<int> nyuyoku_ticket, pool_ticket, nyuyoku_member, pool_member, seiki_ryoukin, waribiki_ryoukin, saiyasune;
	
	cin >> n;
	for( i = 0; i < n; i++ )
	{
		int x, y, b, p;
		cin >> x >> y >> b >> p;
		nyuyoku_ticket.push_back( x );
		pool_ticket.push_back( y );
		nyuyoku_member.push_back( b );
		pool_member.push_back( p );
		if( b >= 5 && p >= 2 )
		{
			seiki_ryoukin.push_back( ( ( ( x * b ) + ( y * p ) ) * 8 ) / 10 );
			saiyasune.push_back( seiki_ryoukin[i] );
		}
		else if( b >= 5 )
		{
			seiki_ryoukin.push_back( ( x * b ) + ( y * p ) );
			waribiki_ryoukin.push_back( ( ( ( x * b ) + ( y * 2 ) ) * 8 ) / 10 );
			if( seiki_ryoukin[i] >= waribiki_ryoukin[i] )
			{
				saiyasune.push_back( waribiki_ryoukin[i] );
			}
			else
			{
				saiyasune.push_back( seiki_ryoukin[i] );
			}
		}
		else if( p >= 2 )
		{
			seiki_ryoukin.push_back( ( x * b ) + ( y * p ) );
			waribiki_ryoukin.push_back( ( ( ( x * 5 ) + ( y * p ) ) * 8 ) / 10 );
			if( seiki_ryoukin[i] >= waribiki_ryoukin[i] )
			{
				saiyasune.push_back( waribiki_ryoukin[i] );
			}
			else
			{
				saiyasune.push_back( seiki_ryoukin[i] );
			}
		}
		else
		{
			seiki_ryoukin.push_back( ( x * b ) + ( y * p ) );
			waribiki_ryoukin.push_back( ( ( ( x * 5 ) + ( y * 2 ) ) * 8 ) / 10 );
			if( seiki_ryoukin[i] >= waribiki_ryoukin[i] )
			{
				saiyasune.push_back( waribiki_ryoukin[i] );
			}
			else
			{
				saiyasune.push_back( seiki_ryoukin[i] );
			}
		}
	}
	for( i = 0; i < n; i++ )
	{
		cout << saiyasune[i] << endl;
	}
	return 0;
}

/*
	C++ 23
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, i;
	vector<int> nyuyoku_ticket, pool_ticket, nyuyoku_member, pool_member, seiki_ryoukin, waribiki_ryoukin, saiyasune;
	
	cin >> n;
	for( i = 0; i < n; i++ )
	{
		int x, y, b, p;
		cin >> x >> y >> b >> p;
		nyuyoku_ticket.push_back( x );
		pool_ticket.push_back( y );
		nyuyoku_member.push_back( b );
		pool_member.push_back( p );
		if( b >= 5 && p >= 2 )
		{
			seiki_ryoukin.push_back( ( ( ( x * b ) + ( y * p ) ) * 8 ) / 10 );
			saiyasune.push_back( seiki_ryoukin[i] );
		}
		else if( b >= 5 )
		{
			seiki_ryoukin.push_back( ( x * b ) + ( y * p ) );
			waribiki_ryoukin.push_back( ( ( ( x * b ) + ( y * 2 ) ) * 8 ) / 10 );
			if( seiki_ryoukin[i] >= waribiki_ryoukin[i] )
			{
				saiyasune.push_back( waribiki_ryoukin[i] );
			}
			else
			{
				saiyasune.push_back( seiki_ryoukin[i] );
			}
		}
		else if( p >= 2 )
		{
			seiki_ryoukin.push_back( ( x * b ) + ( y * p ) );
			waribiki_ryoukin.push_back( ( ( ( x * 5 ) + ( y * p ) ) * 8 ) / 10 );
			if( seiki_ryoukin[i] >= waribiki_ryoukin[i] )
			{
				saiyasune.push_back( waribiki_ryoukin[i] );
			}
			else
			{
				saiyasune.push_back( seiki_ryoukin[i] );
			}
		}
		else
		{
			seiki_ryoukin.push_back( ( x * b ) + ( y * p ) );
			waribiki_ryoukin.push_back( ( ( ( x * 5 ) + ( y * 2 ) ) * 8 ) / 10 );
			if( seiki_ryoukin[i] >= waribiki_ryoukin[i] )
			{
				saiyasune.push_back( waribiki_ryoukin[i] );
			}
			else
			{
				saiyasune.push_back( seiki_ryoukin[i] );
			}
		}
	}
	for( i = 0; i < n; i++ )
	{
		cout << saiyasune[i] << endl;
	}
	return 0;
}

/*
	C++ 26
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, i;
	vector<int> nyuyoku_ticket, pool_ticket, nyuyoku_member, pool_member, seiki_ryoukin, waribiki_ryoukin, saiyasune;
	
	cin >> n;
	for( i = 0; i < n; i++ )
	{
		int x, y, b, p;
		cin >> x >> y >> b >> p;
		nyuyoku_ticket.push_back( x );
		pool_ticket.push_back( y );
		nyuyoku_member.push_back( b );
		pool_member.push_back( p );
		if( b >= 5 && p >= 2 )
		{
			seiki_ryoukin.push_back( ( ( ( x * b ) + ( y * p ) ) * 8 ) / 10 );
			saiyasune.push_back( seiki_ryoukin[i] );
		}
		else if( b >= 5 )
		{
			seiki_ryoukin.push_back( ( x * b ) + ( y * 2 ) );
			waribiki_ryoukin.push_back( ( ( ( x * b ) + ( y * 2 ) ) * 8 ) / 10 );
			if( seiki_ryoukin[i] >= waribiki_ryoukin[i] )
			{
				saiyasune.push_back( waribiki_ryoukin[i] );
			}
			else if( b >= 5 )
			{
				seiki_ryoukin.push_back( ( x * b ) + ( y * p ) );
				waribiki_ryoukin.push_back( ( ( ( x * b ) + ( y * p ) ) * 8 ) / 10 );
				if( seiki_ryoukin[i] >= waribiki_ryoukin[i] )
				{
					saiyasune.push_back( waribiki_ryoukin[i] );
				}
				else
				{
					seiki_ryoukin.push_back( ( x * b ) + ( y * 2 ) );
				if( seiki_ryoukin[i] >= waribiki_ryoukin[i] )
				{
					saiyasune.push_back( waribiki_ryoukin[i] );
				}
				else
				{
					seiki_ryoukin.push_back( ( x * b ) + ( y * 2 ) );
				if( seiki_ryoukin[i] >= waribiki_ryoukin[i] )
				{
					saiyasune.push_back( waribiki_ryoukin[i] );
				}
				else
				{
					seiki_ryoukin.push_back( ( x * b ) + ( y * 2 ) );
				if( seiki_ryoukin[i] >= waribiki_ryoukin[i] )
				{
					saiyasune.push_back( waribiki_ryoukin[i] );
				}
				else
				{
					seiki_ryoukin.push_back( ( x * b ) + ( y * 2 ) );
				if( seiki_ryoukin[i] >= waribiki_ryoukin[i] )
				{
					saiyasune.push_back( waribiki_ryoukin[i] );
				}
				else
				{
					seiki_ryoukin.push_back( ( x * b ) + ( y * 2 ) );
				if( seiki_ryoukin[i] >= waribiki_ryoukin[i] )
				{
					saiyasune.push_back( ( x * b ) + ( y * 2 ) );
				else
				{
					seiki_ryoukin.push_back( ( x * b ) + ( y * 2 ) );
				if( seiki_ryoukin[i] >= waribiki_ryoukin[i] )
				{
					saIYASUNE.push_back( waribiki_ryoukin[i] );
				else
				{
					seiki_ryoukin.push_back( ( x * b ) + ( y * 2 ) );
				if( seiki_ryoukin[i] >= waribiki_ryoukin[i] )
				{
					saIYASUNE.push_back( waribiki_ ryoukin[i] );
				else
				{
					seiki_ ryoukin.push_back( ( x * b ) + ( y * 2 ) );
				if( seiki_ ryoukin[i] >= waribiki_ ryoukin[i] )
				{
					saIYASUNE.push_back( ( x * b ) + ( y * 2 ) );
				else
				{
					seiki_ ryoukin[i] )
				{
					saIYASUNE.push_back( ( x * b ) + ( y * 2 ) );
				if( seiki_ ryoukin[i] >= waribiki_ ryoukin[i] )
				{
					saIYASUNE.push_back( ( x * b ) + ( y * 2 ) );
				else
				{
					saIYASUNE.push_back( ( x * b ) + ( y * 2 ) );
				if( seiki_ ryoukin[i] >= waribiki_ ryoukin[i] )
				{
					saIYASUNE.push_back( ( x * b ) + ( y * 2 ) );
				else
				{
					saIYASUNE.push_back( ( x * b ) + ( y * 2 ) );
				if( seiki_ ryoukin[i] >= waribiki_ ryoukin[i] )
				{
					saIYASUNE.push_back( ( x * b ) + ( y * 2 ) );
				else
				{
					saIYASUNE.push_back( ( x * b ) + ( y * 2 ) );
				if( seiki_ ryoukin[i] >= waribiki_ ryoukin[i] )
				{
					saIYASUNE.push_back( ( x * b ) + ( y * 2 ) );
				else
				{
					saIYASUNE.push_back( ( x * b ) + ( y * 2 ) );
				if( seiki_ ryoukin[i] >= waribiki_ ryoukin[i] )
				{
					saIYASUNE.push_back( ( x *