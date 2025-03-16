import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read user input and assign it to the variable 'n'
        int n = scanner.nextInt();
        
        // Create an array 'list' with the same length as 'n'
        int[] list = new int[n];
        
        // Read the input values and calculate the remainder of each value divided by 2
        for (int i = 0; i < n; i++) {
            list[i] = scanner.nextInt() % 2;
        }
        
        // Check if the sum of all elements in the list is equal to 1
        int sum = 0;
        for (int value : list) {
            sum += value;
        }
        
        if (sum == 1) {
            // If the condition is true, print the index of the first occurrence of the number 1 in the list
            for (int i = 0; i < n; i++) {
                if (list[i] == 1) {
                    System.out.println("The first number with remainder 1 is: " + (i + 1));
                    break;
                }
            }
        } else {
            // If the condition is false, print the index of the first occurrence of the number 0 in the list
            for (int i = 0; i < n; i++) {
                if (list[i] == 0) {
                    System.out.println("The first number with remainder 0 is: " + (i + 1));
                    break;
                }
            }
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
