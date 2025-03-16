
import java. util. * ;
class GFG {
    static String leapyear ( int n ) {
        if ( n % 400 == 0 || ( n % 4 == 0 && n % 100!= 0 ) ) {
            return "y" ;
        }
        else {
            return "n" ;
        }
    }
    public static void main ( String [ ] args ) {
        Scanner sc = new Scanner ( System. in ) ;
        int n = sc. nextInt ( ) ;
        String d = "f" ;
        String ans = "f" ;
        if ( n % 400 == 0 || ( n % 4 == 0 && n % 100!= 0 ) ) {
            ans = "ly" ;
        }
        else {
            ans = "nly" ;
        }
        while ( true ) {
            if ( n % 400 == 0 || ( n % 4 == 0 && n % 100!= 0 ) ) {
                if ( d. equals ( "m" ) ) {
                    d = "w" ;
                    n += 1 ;
                }
                else if ( d. equals ( "t" ) ) {
                    d = "th" ;
                    n += 1 ;
                }
                else if ( d. equals ( "w" ) ) {
                    d = "f" ;
                    n += 1 ;
                }
                else if ( d. equals ( "th" ) ) {
                    d = "sa" ;
                    n += 1 ;
                }
                else if ( d. equals ( "f" ) ) {
                    d = "s" ;
                    n += 1 ;
                }
                else if ( d. equals ( "sa" ) ) {
                    d = "m" ;
                    n += 1 ;
                }
                else if ( d. equals ( "s" ) ) {
                    d = "t" ;
                    n += 1 ;
                }
            }
            else {
                if ( d. equals ( "m" ) ) {
                    d = "t" ;
                    n += 1 ;
                }
                else if ( d. equals ( "t" ) ) {
                    d = "w" ;
                    n += 1 ;
                }
                else if ( d. equals ( "w" ) ) {
                    d = "th" ;
                    n += 1 ;
                }
                else if ( d. equals ( "th" ) ) {
                    d = "f" ;
                    n += 1 ;
                }
                else if ( d. equals ( "f" ) ) {
                    d = "sa" ;
                    n += 1 ;
                }
                else if ( d. equals ( "sa" ) ) {
                    d = "s" ;
                    n += 1 ;
                }
                else if ( d. equals ( "s" ) ) {
                    d = "m" ;
                    n += 1 ;
                }
            }
            if ( d. equals ( "f" ) && ans. equals ( "ly" ) && leapyear ( n ). equals ( "y" ) ) {
                break ;
            }
            else if ( d. equals ( "f" ) && ans. equals ( "nly" ) && leapyear ( n ). equals ( "n" ) ) {
                break ;
            }
        }
        System. out. println ( n ) ;
    }
}
