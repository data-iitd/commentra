import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Read an integer input from the user
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        // Initialize two variables: 'i' starting from 1 and 'j' starting from n*n
        int i = 1, j = n * n;

        // Loop until 'i' is less than 'j'
        while (i < j) {
            // Print the current values of 'i' and 'j'
            System.out.println(i + " " + j);
            
            // Increment 'i' to move towards the center
            i++;
            
            // Decrement 'j' to move towards the center
            j--;
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
