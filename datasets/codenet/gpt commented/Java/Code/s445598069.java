import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {
        // Create a BufferedReader to read input from the console
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // Read the number of elements from the input
        int n = Integer.parseInt(br.readLine());

        // Read the space-separated integers and split them into an array
        String str[] = br.readLine().split(" ");

        // Initialize an array to count occurrences of each number (up to 100010)
        int s[] = new int[100010];

        // Count the occurrences of each number in the input
        for (int i = 0; i < n; i++) {
            s[Integer.parseInt(str[i])]++;
        }

        // Initialize a variable to keep track of the number of unique counts
        int dec = 0;

        // Convert counts to either 1 or 2 based on their parity (odd/even)
        for (int i = 0; i < s.length; i++) {
            if (s[i] != 0) { // Only consider numbers that appeared in the input
                if (s[i] % 2 == 0) {
                    s[i] = 2; // Even count
                } else {
                    s[i] = 1; // Odd count
                }
            }
        }

        // Initialize counters for the number of odd and even counts
        int one = 0;
        int two = 0;

        // Count how many numbers have odd and even occurrences
        for (int i = 0; i < s.length; i++) {
            if (s[i] == 2) {
                two++; // Count of numbers with even occurrences
            } else if (s[i] == 1) {
                one++; // Count of numbers with odd occurrences
            }
        }

        // Adjust the count of odd occurrences if there is an odd number of even occurrences
        if (two % 2 != 0) {
            one--; // Decrease one count if the number of even occurrences is odd
        }

        // Output the total count of unique numbers considering the adjustments
        System.out.println(two + one);
    }
}
