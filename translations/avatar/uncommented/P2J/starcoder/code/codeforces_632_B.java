public class Main {
    public static void main ( String [ ] args ) {
        Scanner sc = new Scanner ( System.in );
        int [ ] pieces = new int [ sc.nextInt ( ) ];
        for ( int i = 0 ; i < pieces.length ; i++ ) {
            pieces [ i ] = sc.nextInt ( );
        }
        System.out.println ( Bob_sMaxStrength ( pieces ) );
    }
    public static int Bob_sMaxStrength ( int [ ] pieces ) {
        int pScore = 0, sScore = 0, pMaxScore = 0, sMaxScore = 0 ;
        for ( int piece : pieces ) {
            if ( piece > 0 ) {
                pScore += piece ;
                if ( pScore > pMaxScore ) {
                    pMaxScore = pScore ;
                }
            } else {
                pScore -= piece ;
            }
        }
        for ( int i = pieces.length - 1 ; i >= 0 ; i-- ) {
            if ( pieces [ i ] > 0 ) {
                sScore += pieces [ i ] ;
                if ( sScore > sMaxScore ) {
                    sMaxScore = sScore ;
                }
            } else {
                sScore -= pieces [ i ] ;
            }
        }
        if ( pMaxScore > sMaxScore ) {
            return pMaxScore ;
        }
        return sMaxScore ;
    }
}
