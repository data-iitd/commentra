import java.util.*;
public class Main {
    public static void main ( String [ ] args ) {
        Scanner sc = new Scanner ( System.in );
        String [ ] s = sc.nextLine ( ).split ( " " );
        int a = Integer.parseInt ( s [ 0 ] );
        int b = Integer.parseInt ( s [ 1 ] );
        System.out.println ( a * b / 100 );
    }
}
