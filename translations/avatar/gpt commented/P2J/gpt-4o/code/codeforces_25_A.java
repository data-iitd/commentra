import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read an integer input which represents the number of elements
        int n = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character
        
        // Read a line of input, split it into individual elements, and create a list
        String[] input = scanner.nextLine().split(" ");
        int[] list = new int[n];
        
        for (int i = 0; i < n; i++) {
            list[i] = Integer.parseInt(input[i]) % 2; // 1 for odd, 0 for even
        }
        
        // Check if there is exactly one odd number in the list
        int sum = 0;
        for (int value : list) {
            sum += value;
        }
        
        if (sum == 1) {
            // If there is one odd number, print its position (1-based index)
            for (int i = 0; i < n; i++) {
                if (list[i] == 1) {
                    System.out.println(i + 1);
                    break;
                }
            }
        } else {
            // If there are no odd numbers, print the position of the first even number (1-based index)
            for (int i = 0; i < n; i++) {
                if (list[i] == 0) {
                    System.out.println(i + 1);
                    break;
                }
            }
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
