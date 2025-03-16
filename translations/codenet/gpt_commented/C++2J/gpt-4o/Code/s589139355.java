import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare variables to hold scores and lengths
        int a, t = 0, h = 0, lt, lh, tt, hh, l;

        // Create a Scanner object for input
        Scanner scanner = new Scanner(System.in);

        // Read the number of rounds
        a = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character

        // Loop through each round
        for (int i = 0; i < a; ++i) {
            // Read the names of the players for the current round
            String taro = scanner.nextLine();
            String hana = scanner.nextLine();

            // Get the lengths of the names
            lt = taro.length();
            lh = hana.length();

            // Determine the longer name length
            if (lt > lh) {
                l = lt; // Taro's name is longer
            } else {
                l = lh; // Hana's name is longer or they are equal
            }

            // Initialize scores for this round
            tt = 0;
            hh = 0;

            // Compare the names and update scores based on the comparison
            if (taro.compareTo(hana) > 0) {
                t += 3; // Taro wins this round
            } else if (hana.compareTo(taro) > 0) {
                h += 3; // Hana wins this round
            } else {
                h += 1; // Tie: both get 1 point
                t += 1; // Tie: both get 1 point
            }
        }

        // Output the final scores of Taro and Hana
        System.out.println(t + " " + h);

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
