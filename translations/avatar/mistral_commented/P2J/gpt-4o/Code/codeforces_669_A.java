import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Get the value of n from user input
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        // Calculate the result and print it out
        System.out.println((n * 2 + 1) / 3);
        
        scanner.close();
    }
}
// <END-OF-CODE>
