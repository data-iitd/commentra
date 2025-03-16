import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Taking input for N and S
        int N = scanner.nextInt();
        String S = scanner.next();
        
        // Calling the function calculate with N and S as arguments
        calculate(N, S);
    }
    
    // Defining the function calculate that takes two parameters, n and s
    public static void calculate(int n, String s) {
        // Converting the string s into a list of characters
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
        
        // Iterating over possible step sizes from 1 to (int)Math.ceil(n / 2) + 1
        for (int step = 1; step <= (int)Math.ceil((double)n / 2) + 1; step++) {
            // Iterating over possible starting indices for the substring
            for (int i = 0; i <= n - 2 * step; i++) {
                // Forming a substring of length 3
                String s1 = "" + arr[i] + arr[i + step] + arr[i + step * 2];
                
                // Checking if the substring matches any of the patterns
                if (s1.equals("RGB") || s1.equals("RBG") || s1.equals("BGR") || s1.equals("BRG") || s1.equals("GBR") || s1.equals("GRB")) {
                    sum = sum + 1;
                }
            }
        }
        
        // Printing the product of the counts of 'R', 'G', and 'B' minus sum
        System.out.println(rNum * gNum * bNum - sum);
    }
}
