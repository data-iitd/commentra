import java.util.Scanner;
import java.util.Arrays;
import java.util.Vector;

public class Solution {
    public static void main(String[] args) {
        // Create a Scanner object for easy input
        Scanner in = new Scanner(System.in);

        // Read the number of elements (n) and the number of largest counts to keep (k)
        int n = in.nextInt();
        int k = in.nextInt();

        // Create a vector to hold the counts of each number
        Vector<Integer> a = new Vector<Integer>();
        // Create a count array initialized to zero with a size of SIZE
        int[] cnt = new int[SIZE];

        // Read n integers and count their occurrences
        for(int i = 0; i < n; ++i){
            int x = in.nextInt();
            // Increment the count for the number x
            cnt[x]++;
        }

        // Transfer the counts of numbers that appeared at least once to vector a
        for(int i = 0; i < cnt.length; ++i){
            if(cnt[i] > 0)
                a.add(cnt[i]); // Add the count to vector a
        }

        // Initialize the answer variable to accumulate the result
        int ans = 0;
        // Sort the counts in ascending order
        Arrays.sort(a);

        // Calculate the number of counts to exclude (m) based on k
        int m = a.size() - k;
        // Sum the counts of the smallest m elements
        for(int i = 0; i < m; ++i){
            ans += a.get(i); // Add the count to the answer
        }

        // Output the final answer
        System.out.println(ans);
    }
}

