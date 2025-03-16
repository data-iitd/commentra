import java.util.Scanner;
import java.util.Arrays;

public class Main {

    public static void main(String[] args) {
        // Initialize Scanner to read input
        Scanner sc = new Scanner(System.in);
        // Read the number of elements
        int N = sc.nextInt();
        // Declare an array to store the elements
        long a[] = new long[N];
        // Declare temporary variable to store intermediate results
        int tmp;
        // Declare variable to store the final answer
        int ans = 0;
        
        // Read N elements into the array
        for (int z = 0; z < N; z++) {
            a[z] = sc.nextInt();
        }
        
        // Sort the array
        Arrays.sort(a);
        
        // Check if there is only one element and it is greater than 1
        if (N == 1 && a[0] > 1) {
            ans = 1;
        } else {
            // Iterate through the array to count occurrences of each element
            for (int j = 0; j < N; j++) {
                // Check if the current element is unique
                if (j == 0 || a[j] != a[j - 1]) {
                    tmp = 1;
                    // Count consecutive occurrences of the current element
                    for (int i = j + 1; i < N; i++) {
                        if (a[j] == a[i]) {
                            tmp++;
                        } else {
                            break;
                        }
                    }
                    
                    // Update the answer based on the count and the value of the element
                    if (tmp > a[j]) {
                        ans += tmp - a[j];
                    } else if (tmp < a[j]) {
                        ans += tmp;
                    }
                }
            }
        }
        
        // Print the final answer
        System.out.println(ans);
    }
}
