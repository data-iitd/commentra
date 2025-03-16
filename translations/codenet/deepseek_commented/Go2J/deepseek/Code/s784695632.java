import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare two integer variables x and y
        int x, y;
        
        // Create a Scanner object to read input from the standard input stream
        Scanner scanner = new Scanner(System.in);
        
        // Read two integers from the standard input and store them in x and y
        x = scanner.nextInt();
        y = scanner.nextInt();
        
        // Print the result of x + y/2
        System.out.println(x + y/2);
    }
}

