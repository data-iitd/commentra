import java.util.*;
public class Main {
    public static void main ( String [ ] args ) {
        Scanner sc = new Scanner ( System.in );
        String c = sc.next ( );
        System.out.println ( solve ( c ) );
    }
    public static String solve ( String c ) {
        String a = "abcdefghijklmnopqrstuvwxyz";
        int i = a.indexOf ( c );
        return a.substring ( i + 1, i + 2 );
    }
}
