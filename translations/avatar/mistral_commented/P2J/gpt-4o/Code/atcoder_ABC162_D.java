import java.util.Scanner;

public class ColorCombination {
    // Define a method to calculate the result based on the input values
    public static void calculate(int n, String s) {
        // Create an array to count occurrences of each color
        int rNum = 0, gNum = 0, bNum = 0;

        // Count the occurrences of 'R', 'G', and 'B'
        for (char c : s.toCharArray()) {
            if (c == 'R') rNum++;
            else if (c == 'G') gNum++;
            else if (c == 'B') bNum++;
        }

        // Initialize sum to 0
        int sum = 0;

        // Iterate through each step from 0 to the ceiling of N/2
        for (int step = 0; step < Math.ceil(n / 2.0); step++) {
            // Create a substring of three consecutive characters
            if (step + 2 < n) {
                String sub = s.substring(step, step + 3);
                // Check if the substring matches any of the six possible color combinations
                if (sub.equals("RGB") || sub.equals("RBG") || sub.equals("BGR") || 
                    sub.equals("BRG") || sub.equals("GBR") || sub.equals("GRB")) {
                    sum++;
                }
            }
        }

        // Print the result of the calculation
        System.out.println(rNum * gNum * bNum - sum);
    }

    public static void main(String[] args) {
        // Create a Scanner object to take input from the user
        Scanner scanner = new Scanner(System.in);
        
        // Take an integer input N and a string input S from the user
        int N = scanner.nextInt();
        String S = scanner.next();
        
        // Call the calculate method with the input values N and S
        calculate(N, S);
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
