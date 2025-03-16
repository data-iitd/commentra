import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Define variables x and y by unpacking the input
        int x = scanner.nextInt();
        int y = scanner.nextInt();
        
        // Calculate and print the maximum value between x + y - 3 + ((y - x) % 3 > 0) and 0
        int result = Math.max(x + y - 3 + ((y - x) % 3 > 0 ? 1 : 0), 0);
        System.out.println(result);
        
        scanner.close();
    }
}

// <END-OF-CODE>
