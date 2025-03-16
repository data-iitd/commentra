import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read an integer input N (not used in further calculations)
        int N = scanner.nextInt();
        
        // Read a list of integers from input
        List<Integer> a = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            a.add(scanner.nextInt());
        }
        
        // Calculate the total using the XOR operation across all elements in the list 'a'
        int total = 0;
        for (int num : a) {
            total ^= num;
        }
        
        // For each element in the list 'a', compute the XOR with 'total' and print the results
        StringBuilder result = new StringBuilder();
        for (int num : a) {
            result.append(num ^ total).append(" ");
        }
        
        // Print the results
        System.out.println(result.toString().trim());
        
        scanner.close();
    }
}

// <END-OF-CODE>
