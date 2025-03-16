
import java.util.*;
// Importing the Java utility library.

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // Creating a Scanner object to read input from standard input.

        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        int d = sc.nextInt();
        // Reading four integers from standard input.

        System.out.println(Math.max(a * c, b * d));
        // Printing the maximum of two possible products of two of the given numbers.
    }
}
