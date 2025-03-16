import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
	public static void main ( String [ ] args ) throws java.lang.Exception
	{
		// your code goes here
		Scanner sc = new Scanner ( System.in );
		String s = sc.nextLine ( );
		int k = sc.nextInt ( );
		int l = 0;
		for ( int i = 0; i < s.length ( ); i++ )
		{
			if ( s.charAt ( i ) != '1' )
			{
				break;
			}
			l++;
		}
		if ( l >= k )
		{
			System.out.println ( 1 );
		}
		else
		{
			System.out.println ( s.charAt ( l ) );
		}
	}
}
