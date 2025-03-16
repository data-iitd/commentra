import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the integer input N which represents the length of the string
        int N = scanner.nextInt();
        
        // Read the string input S which consists of characters 'R', 'G', and 'B'
        String S = scanner.next();
        
        // Call the calculate function with the inputs N and S
        calculate(N, S);
    }
    
    public static void calculate(int n, String s) {
        // Convert the string into a list of characters for easier manipulation
        char[] arr = s.toCharArray();
        
        // Count the occurrences of each color in the string
        int rNum = 0, gNum = 0, bNum = 0;
        for (char c : arr) {
            if (c == 'R') rNum++;
            else if (c == 'G') gNum++;
            else if (c == 'B') bNum++;
        }
        
        // Initialize a variable to keep track of the number of valid RGB combinations found
        int sum = 0;
        
        // Loop through possible steps to form combinations of three characters
        for (int step = 1; step <= Math.ceil(n / 2.0); step++) {
            // Loop through the string to form combinations based on the current step
            for (int i = 0; i <= n - 2 * step; i++) {
                // Create a substring of three characters at the current indices
                String s1 = "" + arr[i] + arr[i + step] + arr[i + step * 2];
                
                // Check if the formed substring is one of the valid RGB permutations
                if (s1.equals("RGB") || s1.equals("RBG") || s1.equals("BGR") || s1.equals("BRG") || s1.equals("GBR") || s1.equals("GRB")) {
                    // Increment the count of valid combinations found
                    sum++;
                }
            }
        }
        
        // Calculate and print the result: total combinations minus the valid RGB combinations found
        System.out.println(rNum * gNum * bNum - sum);
    }
}
