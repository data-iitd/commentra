import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read n and m
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        scanner.nextLine(); // Consume the newline
        
        // Read the input line and count "-"
        String inputLine = scanner.nextLine();
        int sa = (int) inputLine.chars().filter(ch -> ch == '-').count();
        sa = Math.min(n - sa, sa);
        
        StringBuilder ss = new StringBuilder();
        
        // Process each pair of a and b
        for (int i = 0; i < m; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            b -= a;
            
            // Check the condition and append result
            if (b % 2 != 0 && b <= sa * 2) {
                ss.append("1\n");
            } else {
                ss.append("0\n");
            }
        }
        
        // Print the result
        System.out.print(ss.toString());
        
        scanner.close();
    }
}

// <END-OF-CODE>
