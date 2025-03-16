import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // Read the number of elements
        int n = sc.nextInt();
        
        // Read the list 't' and prepend a 0 for 1-based indexing
        int[] t = new int[n + 1];
        t[0] = 0;
        for (int i = 1; i <= n; i++) {
            t[i] = sc.nextInt();
        }
        
        // Read the list 'a' and prepend a 0 for 1-based indexing
        int[] a = new int[n + 1];
        a[0] = 0;
        for (int i = 1; i <= n; i++) {
            a[i] = sc.nextInt();
        }
        
        // Initialize the answer list and a count list to track occurrences
        List<Integer> ans = new ArrayList<Integer>();
        int[] cnt = new int[n + 1];
        
        // Count the occurrences of each element in list 'a'
        for (int i = 1; i <= n; i++) {
            cnt[a[i]]++;
        }
        
        // Iterate through each index from 1 to n
        for (int i = 1; i <= n; i++) {
            // Check if the current element in 't' is 1
            if (t[i] == 1) {
                // Initialize a current path list starting with the current index
                List<Integer> crt = new ArrayList<Integer>();
                crt.add(i);
                // Set x to the corresponding value in 'a'
                int x = a[i];
                
                // Continue to follow the chain while the count of x is 1
                while (cnt[x] == 1) {
                    crt.add(x);  // Add x to the current path
                    x = a[x];  // Move to the next index in the chain
                }
                
                // Update the answer if the current path is longer than the previous answer
                if (crt.size() > ans.size()) {
                    ans = crt;  // Store a copy of the current path
                }
            }
        }
        
        // Print the length of the longest path found
        System.out.println(ans.size());
        
        // Print the elements of the longest path as a space-separated string
        for (int i = 0; i < ans.size(); i++) {
            System.out.print(ans.get(i) + " ");
        }
    }
}

