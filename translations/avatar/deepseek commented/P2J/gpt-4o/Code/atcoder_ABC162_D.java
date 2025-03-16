import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Taking input for N and S
        int N = scanner.nextInt();
        String S = scanner.next();
        
        // Calling the function calculate with N and S as arguments
        calculate(N, S);
        
        scanner.close();
    }

    // Defining the function calculate that takes two parameters, n and s
    public static void calculate(int n, String s) {
        // Converting the string s into a character array
        char[] arr = s.toCharArray();
        
        // Calculating the counts of 'R', 'G', and 'B'
        int rNum = 0, gNum = 0, bNum = 0;
        for (char c : arr) {
            if (c == 'R') rNum++;
            else if (c == 'G') gNum++;
            else if (c == 'B') bNum++;
        }
        
        // Initializing sum to 0
        int sum = 0;
        
        // Iterating over possible step sizes from 1 to (n / 2) + 1
        for (int step = 1; step <= Math.ceil(n / 2.0); step++) {
            // Iterating over possible starting indices for the substring
            for (int i = 0; i <= n - 2 * step; i++) {
                // Forming a substring of length 3
                String substring = "" + arr[i] + arr[i + step] + arr[i + 2 * step];
                
                // Checking if the substring matches any of the patterns
                if (substring.equals("RGB") || substring.equals("RBG") || 
                    substring.equals("BGR") || substring.equals("BRG") || 
                    substring.equals("GBR") || substring.equals("GRB")) {
                    sum++;
                }
            }
        }
        
        // Printing the product of the counts of 'R', 'G', and 'B' minus sum
        System.out.println(rNum * gNum * bNum - sum);
    }
}

// <END-OF-CODE>
