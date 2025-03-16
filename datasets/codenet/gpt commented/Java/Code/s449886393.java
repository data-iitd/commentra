import java.util.*; // Importing the utility package for using Scanner
import static java.lang.System.*; // Importing System class for easy access to out
import java.math.*; // Importing the math package (not used in this code)

public class Main {

    public static void main(String[] args) {
        // Creating a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in);
        
        // Array containing the days of the week
        String[] youbi = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
        
        // Reading the input day from the user
        String s = sc.next();
        
        // Variable to store the number of days until the next Sunday
        int ans = 0;
        
        // Loop through the days of the week to find the input day
        for(int i = 0; i < youbi.length; i++) {
            // Check if the current day matches the input day
            if (youbi[i].equals(s)) {
                // Calculate the number of days until the next Sunday
                ans = 7 - i;
            }
        }
        
        // Output the result: number of days until the next Sunday
        out.println(ans);
    }
}
