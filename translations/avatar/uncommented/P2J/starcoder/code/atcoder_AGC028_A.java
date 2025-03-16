import java.util.*;
public class Main {
    public static void main ( String [ ] args ) {
        Scanner sc = new Scanner ( System.in );
        int N = sc.nextInt ( );
        int M = sc.nextInt ( );
        String S = sc.next ( );
        String T = sc.next ( );
        List < Integer > list_S = new ArrayList < > ( );
        List < Integer > list_T = new ArrayList < > ( );
        for ( int i = 0 ; i < N ; i ++ ) {
            list_S.add ( i, S.charAt ( i ) );
        }
        for ( int i = 0 ; i < M ; i ++ ) {
            list_T.add ( i, T.charAt ( i ) );
        }
        List < Integer > Number_i = new ArrayList < > ( );
        for ( int i = 0 ; i < N ; i ++ ) {
            Number_i.add ( i );
        }
        List < Integer > Number_iMN = new ArrayList < > ( );
        for ( int i = 0 ; i < Number_i.size ( ) ; i ++ ) {
            Number_iMN.add ( i, Number_i.get ( i ) * M / N );
        }
        List < Integer > Number_j = new ArrayList < > ( );
        for ( int j = 0 ; j < M ; j ++ ) {
            Number_j.add ( j );
        }
        List < Integer > Kaburi_j = new ArrayList < > ( );
        for ( int j = 0 ; j < Number_j.size ( ) ; j ++ ) {
            if ( Number_j.get ( j ) in Number_iMN ) {
                Kaburi_j.add ( j );
            }
        }
        List < Integer > Kaburi_i = new ArrayList < > ( );
        for ( int j = 0 ; j < Kaburi_j.size ( ) ; j ++ ) {
            Kaburi_i.add ( Kaburi_j.get ( j ) * N / M );
        }
        int counter = 0;
        int Flag = 0;
        int Kaburi_Size = Kaburi_i.size ( );
        while ( counter <= Kaburi_Size - 1 ) {
            if ( list_S.get ( Kaburi_i.get ( counter ) ) == list_T.get ( Kaburi_j.get ( counter ) ) ) {
                counter += 1;
            } else {
                Flag = 1;
                break;
            }
        }
        if ( Flag == 1 ) {
            System.out.println ( - 1 );
        } else {
            System.out.println ( N * M / Math.gcd ( N, M ) );
        }
    }
}
