import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare a variable to hold the input string
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        
        // Initialize the answer variable with "No"
        String ans = "No";
        
        // Check if the first occurrence of 'C' is before the last occurrence of 'F'
        int indexC = s.indexOf('C');
        int lastIndexF = s.lastIndexOf('F');
        
        if (indexC != -1 && indexC < lastIndexF) {
            // If true, set the answer to "Yes"
            ans = "Yes";
        }
        
        // Check if 'C' does not exist in the string
        if (indexC < 0) {
            // If true, set the answer to "No"
            ans = "No";
        }
        
        // Print the final answer
        System.out.println(ans);
        
        scanner.close();
    }
}

// <END-OF-CODE>
