
/*------------------------------------
........Bismillahir Rahmanir Rahim....
..........created by Abdul Aziz.......
------------------------------------*/
import java.util.*; // Import the Scanner class for input
import java.io.*; // Import the PrintStream class for output

public class s661446851{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Create a Scanner object for input
        PrintStream out = new PrintStream(System.out); // Create a PrintStream object for output
        int n = sc.nextInt(); // Read the input number
        out.println(!n); // Output the boolean negation of n
        sc.close(); // Close the Scanner object
    }
}
