import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read an integer input N, which represents the number of elements in the list
        int N = scanner.nextInt();
        
        // Create a list to store the elements
        List<Integer> A = new ArrayList<>();
        
        // Read a line of input, split it into individual string elements, convert them to integers,
        // and store them in the list A
        for (int i = 0; i < N; i++) {
            A.add(scanner.nextInt());
        }
        
        // Calculate the GCD of all elements in the list A
        int gcd = A.get(0);
        for (int i = 1; i < N; i++) {
            gcd = gcd(gcd, A.get(i));
        }
        
        // Print the calculated GCD
        System.out.println(gcd);
    }
    
    // Helper method to calculate the GCD of two numbers
    public static int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
}
