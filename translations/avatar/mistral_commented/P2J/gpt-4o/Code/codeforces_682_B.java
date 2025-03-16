import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of test cases 'n'
        int n = scanner.nextInt();
        
        // Read the list 'l' of length 'n' containing 'n' integers
        int[] l = new int[n];
        for (int i = 0; i < n; i++) {
            l[i] = scanner.nextInt();
        }
        
        // Sort the list 'l' in ascending order
        Arrays.sort(l);
        
        // Initialize variable 'c' to 0
        int c = 0;
        
        // Iterate through the list 'l'
        for (int i : l) {
            // If the current element 'i' is greater than the previous count 'c', increment 'c' by 1
            if (i > c) {
                c++;
            }
        }
        
        // Print the final result, which is the number of unique elements in the list 'l' plus 1
        System.out.println(c + 1);
        
        scanner.close();
    }
}

// <END-OF-CODE>
