
import java.util.*;
public class Main {
    public static void main ( String [ ] args ) {
        Scanner sc = new Scanner ( System.in );
        int N = sc.nextInt ( );
        int M = sc.nextInt ( );
        String S = sc.next ( );
        String T = sc.next ( );
        List < Integer > Number_i = new ArrayList < > ( );
        for ( int i = 0 ; i < N ; i ++ ) {
            Number_i.add ( i );
        }
        List < Integer > Number_iMN = new ArrayList < > ( );
        for ( int i : Number_i ) {
            Number_iMN.add ( i * M / N );
        }
        List < Integer > Number_j = new ArrayList < > ( );
        for ( int j = 0 ; j < M ; j ++ ) {
            Number_j.add ( j );
        }
        List < Integer > Kaburi_j = new ArrayList < > ( );
        for ( int j : Number_j ) {
            if ( Number_iMN.contains ( j ) ) {
                Kaburi_j.add ( j );
            }
        }
        List < Integer > Kaburi_i = new ArrayList < > ( );
        for ( int j : Kaburi_j ) {
            Kaburi_i.add ( j * N / M );
        }
        int counter = 0;
        int Flag = 0;
        int Kaburi_Size = Kaburi_i.size ( );
        while ( counter <= Kaburi_Size - 1 ) {
            if ( S.charAt ( Kaburi_i.get ( counter ) ) == T.charAt ( Kaburi_j.get ( counter ) ) ) {
                counter += 1;
            } else {
                Flag = 1;
                break;
            }
        }
        if ( Flag == 1 ) {
            System.out.println ( "-1" );
        } else {
            System.out.println ( N * M / Math.gcd ( N, M ) );
        }
    }
}
