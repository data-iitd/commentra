import java.io.* ; 
import java.util.* ; 

public class Main { 
    public static void main ( String [ ] args ) { 
        Scanner in = new Scanner ( System.in ) ; 
        PrintWriter pw = new PrintWriter ( System.out ) ; 
        
        // Reading coordinates of two points
        int x1 = in.nextInt ( ) , y1 = in.nextInt ( ) , x2 = in.nextInt ( ) , y2 = in.nextInt ( ) ; 
        
        // Checking conditions to find the other two corners of a square or print -1
        if ( x1 == x2 ) { 
            int dif = Math.abs ( y1 - y2 ) ; 
            pw.println ( ( x1 + dif ) + " " + y1 + " " + ( x1 + dif ) + " " + y2 ) ; 
        } else if ( y1 == y2 ) { 
            int dif = Math.abs ( x1 - x2 ) ; 
            pw.println ( ( x1 ) + " " + ( y1 + dif ) + " " + ( x2 ) + " " + ( y2 + dif ) ) ; 
        } else if ( Math.abs ( x1 - x2 ) == Math.abs ( y1 - y2 ) ) { 
            pw.println ( x1 + " " + y2 + " " + x2 + " " + y1 ) ; 
        } else { 
            pw.println ( - 1 ) ; 
        } 
        
        // Closing the writer to flush the output
        pw.close ( ) ; 
    } 
    
    // Debugging method to print debug statements
    static void debug ( Object...obj ) { 
        System.err.println ( Arrays.deepToString ( obj ) ) ; 
    } 
}
