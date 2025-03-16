import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read input values for N and K
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        
        // Read the string S
        String S = scanner.next();
        
        // Initialize a flag to determine if we can use a shortcut for output
        boolean aaaa = false;
        
        // Check if K is large enough or if 2^K is greater than or equal to N
        if (K >= 15) {
            aaaa = true;
        } else if (Math.pow(2, K) >= N) {
            aaaa = true;
        }
        
        // If the shortcut condition is met, print the minimum character repeated N times and exit
        if (aaaa) {
            char minChar = getMinChar(S);
            System.out.println(String.valueOf(minChar).repeat(N));
            return;
        }
        
        // Function to get the lexicographically smallest rotation of the string
        String smallestRotation = getLastDict(S);
        
        // If K is 1, simply print the smallest rotation
        if (K == 1) {
            System.out.println(smallestRotation);
        } else {
            int count = 0;
            // Count how many times the first character appears consecutively
            char firstChar = smallestRotation.charAt(0);
            for (char c : smallestRotation.toCharArray()) {
                if (c == firstChar) {
                    count++;
                } else {
                    break;
                }
            }
            
            // Check if the repeated character can fill the string of length N
            if (count * (Math.pow(2, K - 1)) >= N) {
                System.out.println(String.valueOf(firstChar).repeat(N));
            } else {
                // Construct the output string based on the count and the original string
                String repeatedString = String.valueOf(firstChar).repeat(count * ((int) Math.pow(2, K - 1) - 1));
                // Print the first N characters of the constructed string
                System.out.println(repeatedString + smallestRotation);
            }
        }
    }
    
    // Function to get the minimum character in a string
    private static char getMinChar(String s) {
        char minChar = s.charAt(0);
        for (char c : s.toCharArray()) {
            if (c < minChar) {
                minChar = c;
            }
        }
        return minChar;
    }
    
    // Function to get the lexicographically smallest rotation of the string
    private static String getLastDict(String s_str) {
        // Create a doubled string to facilitate rotation comparison
        String U = s_str + new StringBuilder(s_str).reverse().toString();
        // Find the minimum character in the original string
        char c = getMinChar(s_str);
        // Get the first occurrence of the minimum character
        int p = U.indexOf(c);
        int minindex = p;
        p += 1;
        
        // Iterate through the doubled string to find the smallest rotation
        while (p <= N) {
            if (U.charAt(p) == c) {
                // Compare the current rotation with the previously found minimum
                if (checkNormalDict(U, minindex, p)) {
                    minindex = p;
                }
            }
            p += 1;
        }
        
        // Return the smallest rotation of length N
        return U.substring(minindex, minindex + N);
    }
    
    // Function to compare two rotations of the string
    private static boolean checkNormalDict(String u, int pointer1, int pointer2) {
        // Compare characters of the two rotations
        for (int i = 0; i < N; i++) {
            if (u.charAt(pointer1 + i) > u.charAt(pointer2 + i)) {
                return true;
            } else if (u.charAt(pointer1 + i) < u.charAt(pointer2 + i)) {
                return false;
            }
        }
        return false;
    }
}
