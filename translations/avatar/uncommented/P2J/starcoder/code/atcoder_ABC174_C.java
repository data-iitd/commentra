import java.util.*;
public class Main
{
    public static void main ( String arg [ ] ) throws Exception
    {
        Scanner sc = new Scanner ( System.in ) ;
        int k = sc.nextInt ( ) ;
        int t = 0 ;
        for ( int i = 1 ; i <= k ; i ++ )
        {
            t = ( t % k ) * 10 + 7 ;
            if ( t % k == 0 )
            {
                System.out.println ( i ) ;
                break ;
            }
        }
        else
            System.out.println ( - 1 ) ;
    }
}
