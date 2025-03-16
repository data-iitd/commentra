import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int a, t = 0, h = 0, lt, lh, tt, hh, l; // Initialize variables

        a = scanner.nextInt(); // Read number of strings from user
        scanner.nextLine(); // Consume the newline character

        for (int i = 0; i < a; ++i) { // Loop through each string pair
            String taro = scanner.nextLine(); // Read first string from user
            String hana = scanner.nextLine(); // Read second string from user
            lt = taro.length(); // Get length of first string
            lh = hana.length(); // Get length of second string

            if (lt > lh) { // Check if first string is longer
                l = lt; // Set length to be the maximum length
            } else {
                l = lh; // Set length to be the minimum length
            }

            tt = 0; // Initialize variables for comparing characters
            hh = 0;

            if (taro.compareTo(hana) > 0) { // Check if first string is greater lexicographically
                t += 3; // Increment t if true
            } else if (hana.compareTo(taro) > 0) {
                h += 3; // Increment h if true
            } else if (hana.equals(taro)) { // Check if strings are equal
                h += 1; // Increment h if true
                t += 1; // Increment t if true
            }
        }

        System.out.println(t + " " + h); // Output the result

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
