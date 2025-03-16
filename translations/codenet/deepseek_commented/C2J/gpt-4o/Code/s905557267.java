import java.util.Scanner;

public class Main {
    
    // Function to return the smaller of two integers
    public static int min(int a, int b) {
        return (a <= b) ? a : b;
    }

    // Function to remove chains of four or more consecutive identical elements
    public static int chain(int[] b, int n) {
        int count; // To count the length of the chain
        int color; // To store the color of the chain
        int[] a = new int[10000]; // Temporary array to hold the modified sequence
        
        // Copy the original array to a temporary array
        System.arraycopy(b, 0, a, 0, n);
        
        // Iterate through the array to find and remove chains of four or more elements
        for (int i = 0; i < n - 4; i++) {
            if (a[i] != 0 && a[i] == a[i + 1] && a[i] == a[i + 2] && a[i] == a[i + 3]) {
                count = 0;
                color = a[i];
                
                // Remove the chain by setting all elements to 0
                for (int j = i; j < n && a[j] == color; j++) {
                    a[j] = 0;
                    count++;
                }
                
                // Shift the remaining elements to fill the gap left by the removed chain
                for (int j = 0; i + j + count < 10000; j++) {
                    a[i + j] = a[i + j + count];
                    if (i + j + count < n) {
                        a[i + j + count] = 0;
                    }
                }
                
                // Reset the index to start checking from the beginning
                i = -1; // Set to -1 because it will be incremented to 0 in the next iteration
            }
        }
        
        count = 0;
        while (count < n && a[count] != 0) {
            count++;
        }
        
        // Check if the remaining sequence is a chain of four or more elements
        if (count == 4 && a[0] == a[1] && a[0] == a[2] && a[0] == a[3]) {
            return 0;
        }
        
        return count;
    }

    // Main function to read input, process it, and print the result
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        while (true) {
            // Initialize the array with zeros
            int[] a = new int[10000];
            int n = scanner.nextInt();
            if (n == 0) {
                break;
            }
            int ans = n;
            
            // Read the elements themselves
            for (int i = 0; i < n; i++) {
                a[i] = scanner.nextInt();
            }
            
            // Iterate over possible starting points for chains of four or more elements
            for (int i = 0; i < n - 4; i++) {
                int[] count = new int[3]; // To count occurrences of each color
                for (int j = i; j < i + 4; j++) {
                    if (a[j] - 1 >= 0) {
                        count[a[j] - 1]++;
                    }
                }
                
                int color = 0;
                for (int j = 0; j < 3; j++) {
                    if (count[j] >= 3) {
                        color = j + 1;
                        break;
                    }
                }
                
                if (color != 0) {
                    for (int j = i; j < i + 4; j++) {
                        int buf = a[j];
                        a[j] = color;
                        ans = min(ans, chain(a, n));
                        a[j] = buf;
                    }
                }
            }
            
            // Print the minimum length after processing
            System.out.println(ans);
        }
        
        scanner.close();
    }
}

// <END-OF-CODE>
