
import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        sc.close();

        // Initialize a flag variable and a dictionary to count occurrences of each character
        boolean x = true;
        int[] dt = new int[256];

        // Count the occurrences of each character in the input string
        for (int i = 0; i < s.length(); i++) {
            if (dt[s.charAt(i)] != 0) {
                dt[s.charAt(i)]++;  // Increment the count if the character is already in the dictionary
            } else {
                dt[s.charAt(i)] = 1;   // Initialize the count to 1 if the character is not in the dictionary
            }
        }

        // Initialize a counter for odd occurrences and a flag variable
        int cnt = 0;
        x = true;

        // Check the counts of each character to determine the number of odd occurrences
        for (int i = 0; i < dt.length; i++) {
            if (dt[i] % 2 != 0 && cnt < 1) {
                cnt++;  // Count the first odd occurrence
            } else if (dt[i] % 2 != 0 && cnt >= 1) {
                x = false;  // More than one odd occurrence found, set flag to False
                break;
            }
        }

        // Determine the output based on the number of odd occurrences and the length of the input
        if (x) {
            System.out.println("First");  // If there are no more than one odd occurrences, print "First"
        } else if (!x && s.length() % 2 == 0) {
            System.out.println("Second");  // If there are more than one odd occurrences and the length is even, print "Second"
        } else if (!x && s.length() % 2 != 0) {
            System.out.println("First");  // If there are more than one odd occurrences and the length is odd, print "First"
        }
    }
}

