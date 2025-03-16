import java.util.Arrays;
import java.util.Scanner;

public class RibbonCutter {
    public static void cutRibbon() {
        // Create a Scanner object to take input from the user
        Scanner scanner = new Scanner(System.in);
        
        // Take input from the user, which is expected to be a list of three integers
        String input = scanner.nextLine();
        String[] inputArray = input.split(" ");
        
        // Assign the first integer in the input list to the variable 'length'
        int length = Integer.parseInt(inputArray[0]);
        
        // Create an array for the remaining three integers
        int[] arr = new int[3];
        for (int i = 0; i < 3; i++) {
            arr[i] = Integer.parseInt(inputArray[i + 1]);
        }
        
        // Sort the remaining three integers in ascending order
        Arrays.sort(arr);
        
        // Check if 'length' is perfectly divisible by the largest integer in 'arr'
        if (length % arr[2] == 0) {
            // Print the quotient and return if true
            System.out.println(length / arr[2]);
            return;
        }
        
        // Initialize 'ans' to 0 for storing the maximum number of ribbons
        int ans = 0;
        
        // If the two smaller integers are equal, proceed with this block
        if (arr[1] == arr[0]) {
            int k = 0;
            // Iterate through possible combinations of the two smaller integers
            for (int i = 0; i <= length / arr[2]; i++) {
                int check = length - i * arr[2];
                if (check >= 0 && check % arr[0] == 0) {
                    k = check / arr[0];
                    ans = Math.max(ans, k + i);
                }
            }
        } else {
            // If the two smaller integers are not equal, iterate through all three integers
            int k = 0;
            for (int i = 0; i <= length / arr[2]; i++) {
                for (int j = 0; j <= length / arr[1]; j++) {
                    int check = length - i * arr[2] - j * arr[1];
                    if (check >= 0 && check % arr[0] == 0) {
                        k = check / arr[0];
                        ans = Math.max(ans, k + i + j);
                    }
                }
            }
        }
        
        // Print the maximum number of ribbons that can be cut and return
        System.out.println(ans);
    }

    public static void main(String[] args) {
        // Call the function 'cutRibbon' to execute the program
        cutRibbon();
    }
}

// <END-OF-CODE>
