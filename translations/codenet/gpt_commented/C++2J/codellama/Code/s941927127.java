import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String W = sc.next();
        sc.close();

        // Sort the characters in the string in ascending order
        char[] W_array = W.toCharArray();
        Arrays.sort(W_array);

        // Iterate through the sorted string, checking pairs of characters
        for (int i = 0; i < W_array.length - 1; i += 2) {
            // Check if the current character is not equal to the next character
            if (W_array[i] != W_array[i + 1]) {
                // If they are not equal, print "No" and exit the program
                System.out.println("No");
                return;
            }
        }

        // If all pairs are equal, print "Yes"
        System.out.println("Yes");
    }
}

