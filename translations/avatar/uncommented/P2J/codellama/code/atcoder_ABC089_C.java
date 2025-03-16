import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
	public static void main ( String[] args ) throws java.lang.Exception
	{
		Scanner sc = new Scanner ( System.in );
		int N = sc.nextInt ( );
		String[] S = new String[N];
		for ( int i = 0 ; i < N ; i++ )
			S[i] = sc.next ( );
		String[] march = { "M" , "A" , "R" , "C" , "H" };
		int[] march_lis = new int[5];
		for ( String s : S )
			if ( s.toUpperCase ( ).charAt ( 0 ) == 'M' )
				march_lis[0]++;
			else if ( s.toUpperCase ( ).charAt ( 0 ) == 'A' )
				march_lis[1]++;
			else if ( s.toUpperCase ( ).charAt ( 0 ) == 'R' )
				march_lis[2]++;
			else if ( s.toUpperCase ( ).charAt ( 0 ) == 'C' )
				march_lis[3]++;
			else if ( s.toUpperCase ( ).charAt ( 0 ) == 'H' )
				march_lis[4]++;
		int ans = 0;
		for ( int x = 0 ; x < march_lis.length ; x++ )
			for ( int y = x + 1 ; y < march_lis.length ; y++ )
				for ( int z = y + 1 ; z < march_lis.length ; z++ )
					ans += march_lis[x] * march_lis[y] * march_lis[z];
		System.out.println ( ans );
	}
}
