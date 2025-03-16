import java.util.*; 

public class Main { 
    public static void main(String[] args) { 
        // Create a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in); 
        
        // Read the integer N (length of the string) and K (number of changes allowed)
        int N = Integer.parseInt(sc.next()); 
        int K = Integer.parseInt(sc.next()); 
        
        // Read the string S
        String S = sc.next(); 
        
        // Convert the string S into a character array for manipulation
        char[] c1 = S.toCharArray(); 
        char[] c3 = S.toCharArray(); 
        
        // Initialize a flag to track changes and a count for 'R' occurrences
        boolean flag = false; 
        int count = 0; 
        
        // First pass: Change 'L' to 'R' up to K times
        for (int i = 0; i < N; i++) { 
            // If the flag is set and the current character is 'R', increment count and reset flag
            if (flag && c1[i] == 'R') { 
                flag = false; 
                count++; 
            } 
            // Break the loop if K changes have been made
            if (count == K) { 
                break; 
            } 
            // If the current character is 'L', set the flag and change 'L' to 'R'
            if (c1[i] == 'L') { 
                flag = true; 
                c1[i] = 'R'; 
            } 
        } 
        
        // Reset flag and count for the second pass
        flag = false; 
        count = 0; 
        
        // Second pass: Change 'R' to 'L' up to K times
        for (int i = 0; i < N; i++) { 
            // If the flag is set and the current character is 'L', increment count and reset flag
            if (flag && c3[i] == 'L') { 
                flag = false; 
                count++; 
            } 
            // Break the loop if K changes have been made
            if (count == K) { 
                break; 
            } 
            // If the current character is 'R', set the flag and change 'R' to 'L'
            if (c3[i] == 'R') { 
                flag = true; 
                c3[i] = 'L'; 
            } 
        } 
        
        // Convert the modified character arrays back to strings
        String S1 = new String(c1); 
        String S3 = new String(c3); 
        
        // Initialize variables to count consecutive characters in S1
        count = 1; 
        int sum1 = 0; 
        char bef = S1.charAt(0); 
        
        // Count the number of consecutive characters in S1
        for (int i = 1; i < N; i++) { 
            if (S1.charAt(i) == bef) { 
                count++; 
                // If it's the last character, add the count to sum1
                if (i == N - 1) { 
                    sum1 += count - 1; 
                } 
            } else { 
                bef = S1.charAt(i); 
                sum1 += count - 1; 
                count = 1; 
            } 
        } 
        
        // Reset count and initialize variables to count consecutive characters in S3
        count = 1; 
        int sum3 = 0; 
        bef = S3.charAt(0); 
        
        // Count the number of consecutive characters in S3
        for (int i = 1; i < N; i++) { 
            if (S3.charAt(i) == bef) { 
                count++; 
                // If it's the last character, add the count to sum3
                if (i == N - 1) { 
                    sum3 += count - 1; 
                } 
            } else { 
                bef = S3.charAt(i); 
                sum3 += count - 1; 
                count = 1; 
            } 
        } 
        
        // Output the maximum of the two sums calculated from S1 and S3
        System.out.println(Math.max(sum1, sum3)); 
    } 
}
