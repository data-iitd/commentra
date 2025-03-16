import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt(); // Read number of strings from user
        int t = 0, h = 0; // Initialize variables

        for (int i = 0; i < a; ++i) { // Loop through each string pair
            String taro = scanner.next(); // Read first string from user
            String hana = scanner.next(); // Read second string from user
            int lt = taro.length(); // Get length of first string
            int lh = hana.length(); // Get length of second string

            int l; // Declare variable for maximum length
            if (lt > lh) { // Check if first string is longer
                l = lt; // Set length to be the maximum length
            } else {
                l = lh; // Set length to be the minimum length
            }

            int tt = 0, hh = 0; // Initialize variables for comparing characters

            if (taro.compareTo(hana) > 0) { // Check if first string is greater lexicographically
                t += 3; // Increment t if true
            } else if (hana.compareTo(taro) > 0) {
                h += 3; // Increment h if true
            } else if (hana.equals(taro)) { // Check if strings are equal
                t += 1; // Increment t if true
                h += 1; // Increment h if true
            }
        }

        System.out.println(t + " " + h); // Output the result
    }
}
