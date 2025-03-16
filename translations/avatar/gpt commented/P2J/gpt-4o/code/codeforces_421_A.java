import java.util.Scanner;
import java.util.HashSet;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read three integers from input: n (number of elements), a, and b
        int n = scanner.nextInt();
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        
        // Read a list of integers from input and store it in lista
        HashSet<Integer> lista = new HashSet<>();
        for (int i = 0; i < a; i++) {
            lista.add(scanner.nextInt());
        }
        
        // Read another list of integers from input and store it in listb
        for (int i = 0; i < b; i++) {
            scanner.nextInt(); // Assuming we read but do not use listb
        }
        
        // Iterate through the range of n (from 0 to n-1)
        for (int k = 0; k < n; k++) {
            // Check if the current index + 1 is present in lista
            if (lista.contains(k + 1)) {
                // If present, print 1 followed by a space
                System.out.print(1 + " ");
            } else {
                // If not present, print 2 followed by a space
                System.out.print(2 + " ");
            }
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
