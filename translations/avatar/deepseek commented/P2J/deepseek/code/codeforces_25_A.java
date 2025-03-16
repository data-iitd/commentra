import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();  // Take an integer input representing the number of elements
        int[] list = new int[n];
        
        for (int i = 0; i < n; i++) {
            list[i] = scanner.nextInt() % 2;  // Read the next integer, calculate remainder modulo 2
        }
        
        // Check if the sum of the list is 1
        int sum = 0;
        for (int num : list) {
            sum += num;
        }
        
        if (sum == 1) {
            for (int i = 0; i < n; i++) {
                if (list[i] == 1) {
                    System.out.println(i + 1);  // Print the index of the first occurrence of 1 (adjusted for 1-based indexing)
                    break;
                }
            }
        } else {
            for (int i = 0; i < n; i++) {
                if (list[i] == 0) {
                    System.out.println(i + 1);  // Print the index of the first occurrence of 0 (adjusted for 1-based indexing)
                    break;
                }
            }
        }
    }
}
