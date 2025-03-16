import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Take the number of elements in the list as input
        int n = scanner.nextInt();
        
        // Initialize an array 'arr' to store the input elements
        int[] arr = new int[n];
        
        // Read the elements of the array
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        
        // Check if the first element of the array is greater than 15
        if (arr[0] > 15) {
            // If it is, print 15
            System.out.println(15);
        } else {
            // Else, iterate through the array starting from the second element
            for (int i = 1; i < n; i++) {
                // Check if the difference between the current and previous elements is greater than 15
                if (arr[i] - arr[i-1] > 15) {
                    // If it is, print the index of the previous element and add 15 to it
                    System.out.println(arr[i-1] + 15);
                    // Break the loop as we have found the answer
                    break;
                }
            }
            // Else, if we reach here, it means that no difference was greater than 15
            else {
                // Check if the last element of the array is 90 or if adding 15 to it results in 90 or more
                if (arr[n-1] == 90 || arr[n-1] + 15 >= 90) {
                    // If it is, print 90
                    System.out.println(90);
                } else {
                    // Else, print the last element plus 15
                    System.out.println(arr[n-1] + 15);
                }
            }
        }
    }
}
