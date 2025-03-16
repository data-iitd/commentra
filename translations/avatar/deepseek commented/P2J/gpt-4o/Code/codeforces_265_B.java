import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();  // Read the number of elements in the list
        int[] l = new int[n];  // Initialize an array to store the elements

        // Read n elements and store them in the array l
        for (int i = 0; i < n; i++) {
            l[i] = scanner.nextInt();
        }

        long ans = n - 1;  // Initialize ans to n - 1, which will store the final answer
        int last = 0;  // Initialize last to 0, used to track the last element in the list

        // Iterate over each element in the array l
        for (int i = 0; i < n; i++) {
            ans += Math.abs(last - l[i]) + 1;  // Update ans based on the current element and last element
            last = l[i];  // Update last to the current element
        }

        System.out.println(ans);  // Print the final answer
        scanner.close();
    }
}

// <END-OF-CODE>
