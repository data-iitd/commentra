import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Read the input values for l and r, which define the range
        Scanner scanner = new Scanner(System.in);
        int l = scanner.nextInt();
        int r = scanner.nextInt();
        
        // Initialize the current value to r and a counter for the number of digits
        int curr = r;
        int s = 0;

        // Count the number of digits in the current value (r)
        while (curr != 0) {
            s++;
            curr /= 10;
        }

        // Calculate the first power of ten greater than r
        int first = (int) Math.pow(10, s);

        // Calculate the second value as half of the first power of ten
        int second = first / 2;

        // Initialize the answer variable to store the maximum product found
        int ans = -1;

        // Iterate through the possible candidates: l, r, first, and second
        for (int i : new int[]{l, r, first, second}) {
            // Check if the candidate is within the range [l, r]
            if (i >= l && i <= r) {
                curr = i;
                StringBuilder rev = new StringBuilder();
                
                // Create the reverse number by subtracting each digit from 9
                for (char k : String.valueOf(curr).toCharArray()) {
                    rev.append(9 - Character.getNumericValue(k));
                }
                
                // Update the answer with the maximum product of the current number and its reverse
                ans = Math.max(ans, Integer.parseInt(rev.toString()) * curr);
            }
        }

        // Print the maximum product found
        System.out.println(ans);
    }
}
// <END-OF-CODE>
