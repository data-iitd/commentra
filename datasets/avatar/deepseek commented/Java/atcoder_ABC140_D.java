import java.util.*; // Importing the Scanner class for input

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Create a Scanner object
        int N = Integer.parseInt(sc.next()); // Read the first integer N
        int K = Integer.parseInt(sc.next()); // Read the second integer K
        String S = sc.next(); // Read the string S
        
        char[] c1 = S.toCharArray(); // Convert the string S to a character array c1
        char[] c3 = S.toCharArray(); // Convert the string S to a character array c3
        
        boolean flag = false; // A flag to indicate whether we are flipping
        int count = 0; // A counter for the number of flips
        
        // Process c1 (Left to Right)
        for (int i = 0; i < N; i++) {
            if (flag && c1[i] == 'R') { // If we are flipping and encounter 'R'
                flag = false; // Reset the flag
                count++; // Increment the flip count
            }
            if (count == K) { // If we have made K flips, break out of the loop
                break;
            }
            if (c1[i] == 'L') { // If we encounter 'L'
                flag = true; // Set the flag to true
                c1[i] = 'R'; // Flip it to 'R'
            }
        }
        
        flag = false; // Reset the flag
        count = 0; // Reset the flip count
        
        // Process c3 (Right to Left)
        for (int i = 0; i < N; i++) {
            if (flag && c3[i] == 'L') { // If we are flipping and encounter 'L'
                flag = false; // Reset the flag
                count++; // Increment the flip count
            }
            if (count == K) { // If we have made K flips, break out of the loop
                break;
            }
            if (c3[i] == 'R') { // If we encounter 'R'
                flag = true; // Set the flag to true
                c3[i] = 'L'; // Flip it to 'L'
            }
        }
        
        String S1 = new String(c1); // Convert the modified c1 back to a string S1
        String S3 = new String(c3); // Convert the modified c3 back to a string S3
        
        count = 1; // Initialize count for consecutive characters
        int sum1 = 0; // Initialize sum for S1
        char bef = S1.charAt(0); // Initialize the previous character
        
        // Count consecutive characters in S1
        for (int i = 1; i < N; i++) {
            if (S1.charAt(i) == bef) { // If the current character is the same as the previous
                count++; // Increment the count
                if (i == N - 1) { // If it's the last character in the string
                    sum1 += count - 1; // Add the count minus one to the sum
                }
            } else { // If the current character is different
                bef = S1.charAt(i); // Update the previous character
                sum1 += count - 1; // Add the count minus one to the sum
                count = 1; // Reset the count
            }
        }
        
        count = 1; // Reset count for consecutive characters
        int sum3 = 0; // Initialize sum for S3
        bef = S3.charAt(0); // Initialize the previous character
        
        // Count consecutive characters in S3
        for (int i = 1; i < N; i++) {
            if (S3.charAt(i) == bef) { // If the current character is the same as the previous
                count++; // Increment the count
                if (i == N - 1) { // If it's the last character in the string
                    sum3 += count - 1; // Add the count minus one to the sum
                }
            } else { // If the current character is different
                bef = S3.charAt(i); // Update the previous character
                sum3 += count - 1; // Add the count minus one to the sum
                count = 1; // Reset the count
            }
        }
        
        // Print the maximum of the two sums
        System.out.println(Math.max(sum1, sum3));
    }
}
