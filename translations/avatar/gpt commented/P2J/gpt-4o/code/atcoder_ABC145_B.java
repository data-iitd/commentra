import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read an integer input from the user
        int n = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character
        
        // Read a string input from the user
        String s = scanner.nextLine();
        
        // Check if the length of the string is odd
        if (n % 2 != 0) {
            // If the length is odd, print 'No' since it cannot be split into two equal halves
            System.out.println("No");
        } 
        // Check if the first half of the string is equal to the second half
        else if (s.substring(0, n / 2).equals(s.substring(n / 2))) {
            // If both halves are equal, print 'Yes'
            System.out.println("Yes");
        } else {
            // If the halves are not equal, print 'No'
            System.out.println("No");
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
