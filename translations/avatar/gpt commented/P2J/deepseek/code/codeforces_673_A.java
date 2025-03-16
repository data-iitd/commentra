import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read an integer input which represents the number of elements in the array
        int n = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character
        
        // Read the next line of input, split it by spaces, convert each element to an integer, and store it in a list
        String[] input = scanner.nextLine().split(" ");
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(input[i]);
        }
        
        // Check if the first element of the array is greater than 15
        if (arr[0] > 15) {
            // If true, print 15 as the output
            System.out.println(15);
        } else {
            // Iterate through the array starting from the second element
            for (int i = 1; i < arr.length; i++) {
                // Check if the difference between the current and previous element is greater than 15
                if (arr[i] - arr[i - 1] > 15) {
                    // If true, print the previous element plus 15 and exit the loop
                    System.out.println(arr[i - 1] + 15);
                    break;
                }
            }
            // If no break occurred, check the last element of the array
            if (arr[arr.length - 1] == 90 || arr[arr.length - 1] + 15 >= 90) {
                // If the last element is 90 or adding 15 to it results in 90 or more, print 90
                System.out.println(90);
            } else {
                // Otherwise, print the last element plus 15
                System.out.println(arr[arr.length - 1] + 15);
            }
        }
    }
}
