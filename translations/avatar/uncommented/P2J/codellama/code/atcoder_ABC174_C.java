import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
	public static void main ( String[] args ) throws java.lang.Exception
	{
		Scanner sc = new Scanner ( System.in );
		int k = sc.nextInt ( );
		int t = 0;
		for ( int i = 1 ; i <= k ; i++ )
		{
			t = ( t % k ) * 10 + 7;
			if ( t % k == 0 )
			{
				System.out.println ( i );
				break;
			}
		}
		if ( i > k )
			System.out.println ( - 1 );
	}
}

