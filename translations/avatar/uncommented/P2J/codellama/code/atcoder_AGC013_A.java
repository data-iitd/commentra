
import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
	public static void main ( String[] args ) throws java.lang.Exception
	{
		Scanner sc = new Scanner ( System.in );
		int N = sc.nextInt ( );
		int A [] = new int [ N ];
		for ( int i = 0 ; i < N ; i++ )
		{
			A [ i ] = sc.nextInt ( );
		}
		A = Arrays.stream ( A ).distinct ( ).toArray ( );
		N = A.length;
		int i = 1;
		int ans = 0;
		while ( i < N - 1 )
		{
			if ( A [ i - 1 ] < A [ i ] > A [ i + 1 ] || A [ i - 1 ] > A [ i ] < A [ i + 1 ] )
			{
				ans += 1;
				i += 1;
			}
			i += 1;
		}
		System.out.println ( ans + 1 );
	}
}
