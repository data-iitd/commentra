import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read x and y
        int x = scanner.nextInt();
        int y = scanner.nextInt();
        
        // Calculate the result
        int result = Math.max(x + y - 3 + ((y - x) % 3 > 0 ? 1 : 0), 0);
        
        // Print the result
        System.out.println(result);
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
