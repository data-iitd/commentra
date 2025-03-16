import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in);
        
        // Read the number of elements (n) and the threshold (k)
        int n = sc.nextInt();
        int k = sc.nextInt();
        
        // Initialize an array to store the input elements
        int[] a = new int[n];
        
        // Read n integers from input and store them in the array a
        for(int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        
        // Create an array to count occurrences of each number, initialized to zero
        Integer[] x = new Integer[200010];
        Arrays.fill(x, 0);
        
        // Count the occurrences of each number in the input array a
        for(int i = 0; i < n; i++) {
            x[a[i] - 1]++;
        }
        
        // Sort the occurrence array x in ascending order
        Arrays.sort(x, new Comparator<Integer>() {
            public int compare(Integer p1, Integer p2) {
                return p1 - p2;
            }
        });
        
        // Initialize a variable to hold the final answer
        int ans = 0;
        
        // Sum the occurrences of the first (200010 - k) elements
        for(int i = 0; i <= 200010 - k - 1; i++) {
            ans += x[i];
        }
        
        // Print the final answer
        System.out.println(ans);
    }
}
