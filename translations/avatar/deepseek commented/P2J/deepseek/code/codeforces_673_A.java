import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();  // Take input for the number of elements in the array
        int[] arr = new int[n];  // Create an array to store the elements
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();  // Take input for the array elements
        }

        // Check if the first element of the array is greater than 15
        if (arr[0] > 15) {
            System.out.println(15);  // If true, print 15
        } else {
            // Iterate through the array starting from the second element
            for (int i = 1; i < n; i++) {
                // Check if the difference between the current and previous element is greater than 15
                if (arr[i] - arr[i - 1] > 15) {
                    System.out.println(arr[i - 1] + 15);  // If true, print the previous element plus 15 and break the loop
                    break;
                }
            }
            // If the loop completes without breaking
            if (arr[n - 1] == 90 || arr[n - 1] + 15 >= 90) {
                System.out.println(90);  // If the last element is 90 or adding 15 to the last element is >= 90, print 90
            } else {
                System.out.println(arr[n - 1] + 15);  // Otherwise, print the last element plus 15
            }
        }
    }
}
