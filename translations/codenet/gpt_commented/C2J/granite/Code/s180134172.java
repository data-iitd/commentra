
import java.util.Scanner;

public class s180134172{
    public static void main(String[] args) {
        // Declare variables
        int n, k, p[] = new int[99999], i, j, l, m, o = 0;

        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in);

        // Read the number of elements (n) and the number of smallest elements to sum (k)
        n = sc.nextInt();
        k = sc.nextInt();

        // Read n integers into the array p
        for(i = 0; i < n; i++) {
            p[i] = sc.nextInt();
        }

        // Selection sort algorithm to sort the array p in ascending order
        for(i = 0; i < n; i++) {
            l = i; // Assume the minimum is the first element
            for(j = i + 1; j < n; j++) {
                // Update l if a smaller element is found
                if(p[j] < p[l]) {
                    l = j;
                }
            }
            // Swap the found minimum element with the first element
            if(l!= i) {
                m = p[i];
                p[i] = p[l];
                p[l] = m;
            }
        }

        // Calculate the sum of the first k smallest elements in the sorted array
        for(i = 0; i < k; i++) {
            o += p[i];
        }

        // Print the result: the sum of the k smallest elements
        System.out.println(o);

        // Close the Scanner object
        sc.close();
    }
}
