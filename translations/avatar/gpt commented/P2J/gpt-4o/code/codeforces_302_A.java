import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read two integers n and m from input
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        scanner.nextLine(); // Consume the newline
        
        // Count the number of '-' characters in the input string
        String inputString = scanner.nextLine();
        int sa = (int) inputString.chars().filter(ch -> ch == '-').count();
        
        // Calculate the minimum of the remaining characters (n - sa) and the count of '-' (sa)
        sa = Math.min(n - sa, sa);
        
        // Initialize a StringBuilder to store results
        StringBuilder ss = new StringBuilder();
        
        // Loop m times to read pairs of integers a and b
        for (int i = 0; i < m; i++) {
            // Read two integers a and b from input
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            b -= a;
            
            // Check if b is odd and less than or equal to double the count of '-'
            // Append "1\n" to the results if true, otherwise append "0\n"
            if (b % 2 == 1 && b <= sa * 2) {
                ss.append("1\n");
            } else {
                ss.append("0\n");
            }
        }
        
        // Print the concatenated results from the StringBuilder
        System.out.print(ss.toString());
        
        scanner.close();
    }
}

// <END-OF-CODE>
