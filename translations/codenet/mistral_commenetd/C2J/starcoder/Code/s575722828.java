
import java.util.*;

public class Main {

    public static void main(String[] args) {
        // Declare an integer variable named S
        int S;

        // Initialize an integer variable named S with a value read from the standard input
        Scanner sc = new Scanner(System.in);
        S = sc.nextInt();

        // Print the hours, minutes, and seconds of the given number of seconds
        System.out.printf("%d:%d:%d\n", (int)(S / 3600), (int)((S % 3600) / 60), S % 60);
    }
}

