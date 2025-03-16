import java.util.Scanner;

public class RGBCombinations {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the integer input N which represents the length of the string
        int N = scanner.nextInt();
        // Read the string input S which consists of characters 'R', 'G', and 'B'
        String S = scanner.next();
        
        calculate(N, S);
        
        scanner.close();
    }

    public static void calculate(int n, String s) {
        // Count the occurrences of each color in the string
        int rNum = 0, gNum = 0, bNum = 0;
        
        for (char c : s.toCharArray()) {
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
                String combination = "" + s.charAt(i) + s.charAt(i + step) + s.charAt(i + step * 2);
                
                // Check if the formed substring is one of the valid RGB permutations
                if (combination.equals("RGB") || combination.equals("RBG") || 
                    combination.equals("BGR") || combination.equals("BRG") || 
                    combination.equals("GBR") || combination.equals("GRB")) {
                    // Increment the count of valid combinations found
                    sum++;
                }
            }
        }
        
        // Calculate and print the result: total combinations minus the valid RGB combinations found
        System.out.println(rNum * gNum * bNum - sum);
    }
}

// <END-OF-CODE>
