
import java. util. Arrays ;
class GFG {
    static long ans = Long. MAX_VALUE ;
    static void rememberTheNumber ( int nums [ ], int i, String operations [ ], long ans [ ] ) {
        if ( i >= 3 ) {
            return ;
        }
        for ( int j = 0 ; j < 4 ; j ++ ) {
            for ( int k = j + 1 ; k < 4 ; k ++ ) {
                if ( nums [ j ]!= - 1 && nums [ k ]!= - 1 ) {
                    int s = nums [ j ] ;
                    nums [ j ] = - 1 ;
                    int t = nums [ k ] ;
                    if ( operations [ i ]. charAt ( 0 ) =='+') {
                        nums [ k ] = s + t ;
                    }
                    else if ( operations [ i ]. charAt ( 0 ) =='*') {
                        nums [ k ] = s * t ;
                    }
                    if ( i == 2 && nums [ k ] < ans [ 0 ] ) {
                        ans [ 0 ] = nums [ k ] ;
                    }
                    rememberTheNumber ( nums, i + 1, operations, ans ) ;
                    nums [ j ] = s ;
                    nums [ k ] = t ;
                }
            }
        }
    }
    public static void main ( String [ ] args ) {
        Scanner sc = new Scanner ( System. in ) ;
        int nums [ ] = new int [ 4 ] ;
        for ( int i = 0 ; i < 4 ; i ++ ) {
            nums [ i ] = sc. nextInt ( ) ;
        }
        String operations [ ] = new String [ 3 ] ;
        for ( int i = 0 ; i < 3 ; i ++ ) {
            operations [ i ] = sc. next ( ) ;
        }
        long ans [ ] = new long [ 1 ] ;
        ans [ 0 ] = Long. MAX_VALUE ;
        rememberTheNumber ( nums, 0, operations, ans ) ;
        System. out. println ( ans [ 0 ] ) ;
    }
}

Translate the above Python code to C++ and end with comment "