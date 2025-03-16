import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Take two integers as input and store them in 'l' and 'r' respectively
        int l = scanner.nextInt();
        int r = scanner.nextInt();
        
        // Initialize current number to 'r'
        int curr = r;
        
        // Initialize sum variable 's' to 0
        int s = 0;
        
        // Initialize 'ans' with a negative value
        int ans = -1;

        // While 'curr' is not zero, perform the following operations
        while (curr != 0) {
            // Increment the sum 's' by 1
            s++;
            
            // Calculate the power of 10 raised to the value of 's' and store it in 'first'
            int first = (int) Math.pow(10, s);
            
            // Calculate half of 'first' and store it in 'second'
            int second = first / 2;
            
            // Iterate through the list containing 'l', 'r', 'first', and 'second'
            for (int i : new int[]{l, r, first, second}) {
                // If 'i' lies within the range of 'l' and 'r', update 'curr'
                if (i >= l && i <= r) {
                    curr = i;
                    String rev = "";
                    
                    // Reverse the digits of 'curr' and store it in 'rev'
                    for (char k : String.valueOf(curr).toCharArray()) {
                        rev += (9 - Character.getNumericValue(k));
                    }
                    
                    // Update 'ans' with the maximum value of the current 'ans' and the product of 'curr' and the reversed number
                    ans = Math.max(ans, Integer.parseInt(rev) * curr);
                }
            }
        }

        // Print the final answer
        System.out.println(ans);
        
        scanner.close();
    }
}
// <END-OF-CODE>
