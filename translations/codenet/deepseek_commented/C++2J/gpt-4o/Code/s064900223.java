import java.util.Scanner;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Step 4: Read the input value for `n`
        ArrayList<Integer> p = new ArrayList<>(n); // Step 5: Create a list `p` of size `n`
        
        for (int i = 0; i < n; i++) { // Step 6: Read values into the list `p`
            p.add(scanner.nextInt());
        }
        
        int ans = 0; // Step 7: Initialize `ans` to 0
        for (int i = 0; i < n - 1; i++) { // Step 8: Loop through the list `p`
            if (p.get(i) == i + 1) { // If the current element `p[i]` is equal to `i+1`
                p.set(i + 1, p.get(i)); // Set the next element `p[i+1]` to `p[i]`
                ans += 1; // Increment `ans`
            }
        }
        
        if (p.get(n - 1) == n) { // Step 9: Check the last element
            ans += 1; // Increment `ans` if the last element is equal to `n`
        }
        
        System.out.println(ans); // Step 10: Output the result
    }
}

// <END-OF-CODE>
