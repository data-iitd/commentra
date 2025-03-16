import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Taking input for number of strings 'n' and number of problems 'q'
        int n = scanner.nextInt();
        int q = scanner.nextInt();
        
        // Taking input for the string 's'
        String s = scanner.next();
        
        // Array to store the cumulative sum of 'AC' substrings
        int[] cumsum = new int[n + 1];
        
        // Function definition for counting the number of 'AC' substrings in the given string 's'
        // The function takes two arguments: 'total' which is the current sum of 'AC' substrings and 'i' which is the index of the current character
        for (int i = 1; i < n; i++) {
            cumsum[i] = cumsum[i - 1];
            if (s.charAt(i - 1) == 'A' && s.charAt(i) == 'C') {
                cumsum[i]++;
            }
        }
        
        // Iterating through each problem in the list 'problems' and printing the difference between the cumulative sum at the end and start of the problem
        for (int i = 0; i < q; i++) {
            int l = scanner.nextInt();
            int r = scanner.nextInt();
            // Print the difference between the cumulative sum at the end and start of the problem
            System.out.println(cumsum[r - 1] - cumsum[l - 1]);
        }
    }
}

