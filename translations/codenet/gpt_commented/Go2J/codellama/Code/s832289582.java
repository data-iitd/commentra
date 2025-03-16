
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize the input scanner with a buffer size of 256 KB
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)), "UTF-8");
        sc.useLocale(Locale.ENGLISH);
        sc.useDelimiter("\\s+");

        // Read the integer values N and P, and the string S from input
        int N = sc.nextInt();
        int P = sc.nextInt();
        String S = sc.next();

        // Check the sub-numbers based on the conditions and print the result
        int answer = checkSubNumbers(N, P, S);
        System.out.println(answer);
    }

    // checkSubNumbers determines the method to check sub-numbers based on the value of P
    private static int checkSubNumbers(int N, int P, String S) {
        switch (P) {
            case 2:
            case 5:
                // If P is 2 or 5, use the specific check for these primes
                return checkTwoOrFive(N, P, S);
            default:
                // For other primes, use the general check
                return checkNotTwoNorFive(N, P, S);
        }
    }

    // checkTwoOrFive counts the sub-numbers divisible by 2 or 5
    private static int checkTwoOrFive(int N, int P, String S) {
        int answer = 0;
        int n;

        // Iterate through the string S from the end to the beginning
        for (int i = N - 1; i >= 0; i--) {
            // Convert the character to an integer
            n = Integer.parseInt(S.substring(i, i + 1));

            // Check if the digit is divisible by P and update the answer
            if (n % P == 0) {
                answer += i + 1; // Count the number of valid sub-numbers
            }
        }
        return answer;
    }

    // checkNotTwoNorFive counts the sub-numbers for primes other than 2 and 5
    private static int checkNotTwoNorFive(int N, int P, String S) {
        int multiplier = 1; // Initialize the multiplier for 10^i % P
        int answer = 0; // Initialize the answer counter
        int[] remainderLookup = new int[P]; // Array to keep track of remainders
        int prevRemaider = -1; // Variable to store the previous remainder
        int digit, remainder, count;

        // Iterate through the string S from the end to the beginning
        for (int i = N - 1; i >= 0; i--) {
            digit = Integer.parseInt(S.substring(i, i + 1)); // Convert the character to an integer

            // Calculate the current remainder based on the previous remainder
            if (prevRemaider == -1) { // First digit case
                remainder = digit % P;
            } else {
                remainder = (((multiplier * digit) % P) + prevRemaider) % P;
            }

            // If the remainder is zero, increment the answer
            if (remainder == 0) {
                answer++;
            }

            // Update the count of sub-numbers with the current remainder
            count = remainderLookup[remainder];
            answer += count; // Add the count of previous occurrences of this remainder
            count++; // Increment the count for this remainder
            remainderLookup[remainder] = count; // Store the updated count
            prevRemaider = remainder; // Update the previous remainder
            multiplier = (multiplier * 10) % P; // Update the multiplier for the next digit
        }
        return answer;
    }
}

