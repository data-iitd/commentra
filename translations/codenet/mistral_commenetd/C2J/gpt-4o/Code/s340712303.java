import java.util.Scanner;

public class Main {
    static final int N = 2000;
    static int[] math = new int[N + 1];
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Initialize variables
        int num1, a, num2, ans, sum = 0;
        
        // Initialize math array with first element as 1
        math[0] = 1;
        
        // Read the number of integers to be input
        System.out.println("Enter the number of integers to be input:");
        num1 = scanner.nextInt();
        
        // Read each integer and calculate its sum
        for (int i = 0; i < num1; i++) {
            System.out.println("Enter an integer:");
            a = scanner.nextInt();
            
            // Add the current integer to the sum
            sum += a;
            
            // Mark all the previous numbers as visited
            for (int j = sum - a; j >= 0; j--) {
                if (math[j] == 1) {
                    math[j + a] = 1;
                }
            }
        }
        
        // Read the number of integers to be checked
        System.out.println("Enter the number of integers to be checked:");
        num2 = scanner.nextInt();
        
        // Check each integer and print the result
        for (int i = 0; i < num2; i++) {
            System.out.println("Enter an integer to check:");
            ans = scanner.nextInt();
            
            // Check if the current integer is marked as visited
            if (math[ans] == 1) {
                System.out.println("yes");
            } else {
                System.out.println("no");
            }
        }
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
