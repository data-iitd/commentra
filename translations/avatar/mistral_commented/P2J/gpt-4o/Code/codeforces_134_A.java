import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Reading the first line of input which contains the number of elements 'n' in the list 'w'
        int n = scanner.nextInt();
        long x = 0; // Assuming 'x' is defined somewhere in the code, as it is not provided in the original Python code.
        long[] w = new long[n];
        
        // Reading the elements into the array 'w'
        for (int i = 0; i < n; i++) {
            w[i] = scanner.nextLong();
            x += w[i]; // Assuming we need to calculate the total sum 'x' of the elements
        }
        
        // Initializing a list 'd' to store the indices of the elements that satisfy the condition
        List<Integer> d = new ArrayList<>();
        
        // Iterating through each element 'i' in the list 'w'
        for (int i = 0; i < n; i++) {
            // Calculating the average of the remaining sum of elements after removing the current element 'w[i]'
            // and checking if it's equal to the current element 'w[i]'
            if ((x - w[i]) / (n - 1) == w[i]) {
                // If the condition is true, append the index 'i+1' to the list 'd'
                d.add(i + 1);
            }
        }
        
        // Printing the length of the list 'd'
        System.out.println(d.size());
        
        // Printing the elements of the list 'd' separated by a space
        for (int i = 0; i < d.size(); i++) {
            System.out.print(d.get(i));
            if (i < d.size() - 1) {
                System.out.print(" ");
            }
        }
        
        scanner.close();
    }
}

// <END-OF-CODE>
