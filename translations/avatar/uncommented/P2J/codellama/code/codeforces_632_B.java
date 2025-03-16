public class BobsMaxStrength {
    public static void main ( String [ ] args ) {
        Scanner scanner = new Scanner ( System.in );
        int n = scanner.nextInt ( );
        int [ ] pieces = new int [ n ];
        char [ ] pieces_type = new char [ n ];
        for ( int i = 0 ; i < n ; i++ ) {
            pieces [ i ] = scanner.nextInt ( );
            pieces_type [ i ] = scanner.next ( ).charAt ( 0 );
        }
        System.out.println ( BobsMaxStrength ( pieces , pieces_type ) );
    }
    public static int BobsMaxStrength ( int [ ] pieces , char [ ] pieces_type ) {
        int pScore = sScore = pMaxScore = sMaxScore = 0;
        for ( int i = 0 ; i < pieces.length ; i++ ) {
            if ( pieces_type [ i ] == 'B' ) {
                pScore += pieces [ i ];
                if ( pScore > pMaxScore ) {
                    pMaxScore = pScore;
                }
            }
        }
        for ( int i = 0 ; i < pieces.length ; i++ ) {
            if ( pieces_type [ i ] == 'A' ) {
                sScore += pieces [ i ];
                if ( sScore > sMaxScore ) {
                    sMaxScore = sScore;
                }
            }
        }
        for ( int i = pieces.length - 1 ; i >= 0 ; i-- ) {
            if ( pieces_type [ i ] == 'A' ) {
                sScore -= pieces [ i ];
                if ( sScore > sMaxScore ) {
                    sMaxScore = sScore;
                }
            }
        }
        if ( pMaxScore > sMaxScore ) {
            return pMaxScore;
        }
        return sMaxScore;
    }
}
