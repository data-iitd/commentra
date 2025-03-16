
import java.util.Scanner;

public class s898107093{
    public static void main(String[] args) {
        // Declare pointers for storing team names and initialize scores
        String[] t, h;
        int n, taro = 0, hanako = 0, i;

        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);

        // Read the number of rounds (n) from input
        n = scanner.nextInt();

        // Allocate memory for team names for both players
        t = new String[n];
        h = new String[n];
        
        // Loop through each round to read team names and calculate scores
        for (i = 0; i < n; i++) {
            // Read team names for both players
            t[i] = scanner.next();
            h[i] = scanner.next();
            
            // Compare team names and update scores based on the comparison
            if (t[i].compareTo(h[i]) < 0) {
                // If Hanako's team name is lexicographically smaller, she gets 3 points
                hanako += 3;
            }
            if (t[i].compareTo(h[i]) > 0) {
                // If Taro's team name is lexicographically larger, he gets 3 points
                taro += 3;
            }
            if (t[i].compareTo(h[i]) == 0) {
                // If both team names are the same, both players get 1 point
                taro += 1;
                hanako += 1;
            }
        }
        
        // Output the final scores of Taro and Hanako
        System.out.println(taro + " " + hanako);
        
        // Close the Scanner object to release system resources
        scanner.close();
    }
}
