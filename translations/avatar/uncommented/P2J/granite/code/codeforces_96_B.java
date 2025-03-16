
import java.util. * ;
class GFG {
    static Vector < Long > l = new Vector < Long > ( ) ;
    static long limit = 10000000000L ;
    static void gen ( long number, long four, long seven ) {
        if ( number > limit )
            return ;
        if ( number > 0 && four == seven )
            l.add ( number ) ;
        gen ( number * 10 + 4, four + 1, seven ) ;
        gen ( number * 10 + 7, four, seven + 1 ) ;
    }
    static void main ( ) {
        gen ( 0, 0, 0 ) ;
        Collections. sort ( l ) ;
        Scanner sc = new Scanner ( System. in ) ;
        long n = sc. nextLong ( ) ;
        long ans = 0 ;
        for ( Long val : l ) {
            if ( val >= n ) {
                ans = val ;
                break ;
            }
        }
        System. out. println ( ans ) ;
    }
}
