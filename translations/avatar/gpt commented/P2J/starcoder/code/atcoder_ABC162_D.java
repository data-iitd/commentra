import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // Read the integer input N which represents the length of the string
        int N = sc.nextInt();
        
        // Read the string input S which consists of characters 'R', 'G', and 'B'
        String S = sc.next();
        
        // Convert the string into a list of characters for easier manipulation
        List<Character> arr = new ArrayList<>();
        for (char c : S.toCharArray()) {
            arr.add(c);
        }
        
        // Count the occurrences of each color in the string
        int rNum = 0;
        int gNum = 0;
        int bNum = 0;
        for (char c : arr) {
            if (c == 'R') {
                rNum++;
            } else if (c == 'G') {
                gNum++;
            } else if (c == 'B') {
                bNum++;
            }
        }
        
        // Initialize a variable to keep track of the number of valid RGB combinations found
        int sum = 0;
        
        // Loop through possible steps to form combinations of three characters
        for (int step = 1; step <= Math.ceil(N / 2.0); step++) {
            // Loop through the string to form combinations based on the current step
            for (int i = 0; i < N - 2 * step; i++) {
                // Create a substring of three characters at the current indices
                String s = "" + arr.get(i) + arr.get(i + step) + arr.get(i + step * 2);
                
                // Check if the formed substring is one of the valid RGB permutations
                if (s.equals("RGB") || s.equals("RBG") || s.equals("BGR") || s.equals("BRG") || s.equals("GBR") || s.equals("GRB")) {
                    // Increment the count of valid combinations found
                    sum++;
                }
            }
        }
        
        // Calculate and print the result: total combinations minus the valid RGB combinations found
        System.out.println(rNum * gNum * bNum - sum);
    }
}

