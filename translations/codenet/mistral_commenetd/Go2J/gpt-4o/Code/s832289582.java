// Import necessary packages
import java.util.Scanner;

// Main class
public class Main {
    // Entry point of the program
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Create a Scanner instance for reading input
        int N = sc.nextInt(); // Read N from standard input
        int P = sc.nextInt(); // Read P from standard input
        String S = sc.next(); // Read S from standard input
        int answer = checkSubNumbers(N, P, S); // Call checkSubNumbers function and store the result
        System.out.println(answer); // Print the answer
    }

    // checkSubNumbers function checks if any subnumber of given string S is divisible by prime number P
    public static int checkSubNumbers(int N, int P, String S) {
        // Switch statement to check if P is equal to 2 or 5
        switch (P) {
            case 2:
            case 5:
                return checkTwoOrFive(N, P, S); // Call checkTwoOrFive function
            default:
                return checkNotTwoNorFive(N, P, S); // Call checkNotTwoNorFive function
        }
    }

    // checkTwoOrFive function checks if any subnumber of given string S is divisible by prime number P equal to 2 or 5
    public static int checkTwoOrFive(int N, int P, String S) {
        int answer = 0; // Initialize answer variable as 0
        // Iterate through the string S from the last character to the first character
        for (int i = N - 1; i >= 0; i--) {
            // Convert the substring from i to i+1 to an integer n
            int n = Character.getNumericValue(S.charAt(i));
            // If n is divisible by P, add its index to the answer variable
            if (n % P == 0) {
                answer += i + 1;
            }
        }
        return answer; // Return the answer
    }

    // checkNotTwoNorFive function checks if any subnumber of given string S is divisible by prime number P which is not equal to 2 or 5
    public static int checkNotTwoNorFive(int N, int P, String S) {
        int multiplier = 1; // Initialize multiplier variable as 1
        int answer = 0; // Initialize answer variable as 0
        int[] remainderLookup = new int[P]; // Create an array for storing the count of remainders
        int prevRemainder = -1; // Initialize prevRemainder variable as -1
        // Iterate through the string S from the last character to the first character
        for (int i = N - 1; i >= 0; i--) {
            // Get the digit from the string S at the current index i
            int digit = Character.getNumericValue(S.charAt(i));
            int remainder; // Declare remainder variable
            // If prevRemainder is equal to -1, get the remainder of the first digit by dividing it by P
            if (prevRemainder == -1) {
                remainder = digit % P;
            } else {
                // Otherwise, calculate the new remainder
                remainder = ((multiplier * digit) % P + prevRemainder) % P;
            }
            // If the remainder is equal to 0, add 1 to the answer variable
            if (remainder == 0) {
                answer++;
            }
            // Get the count of the current remainder from the array remainderLookup
            int count = remainderLookup[remainder];
            // Add the count to the answer variable
            answer += count;
            // Update the array remainderLookup with the new count of the current remainder
            count++;
            remainderLookup[remainder] = count;
            // Update the multiplier variable as multiplier * 10 % P
            prevRemainder = remainder;
            multiplier = (multiplier * 10) % P;
        }
        return answer; // Return the answer
    }
}

// <END-OF-CODE>
