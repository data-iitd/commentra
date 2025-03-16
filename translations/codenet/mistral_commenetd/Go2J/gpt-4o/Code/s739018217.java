import java.util.Scanner;

public class Main {
    // The main method is the entry point of the program
    public static void main(String[] args) {
        // Declare and initialize two integer variables n and m using Scanner
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();

        // Calculate the value of x using the given formula
        int x = m * 1900 + (n - m) * 100;

        // Print the result using System.out.println
        System.out.println(x * Math.pow(2.0, m));
        
        scanner.close();
    }
}

// <END-OF-CODE>
