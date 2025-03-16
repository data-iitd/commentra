import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int n, sum;
        
        // Step 4: Read input from the user
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        
        // Step 5: Calculate the sum of the first n natural numbers
        sum = (n * (n + 1)) / 2;
        
        // Step 6: Print the result
        System.out.println(sum);
        
        // Step 7: Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
