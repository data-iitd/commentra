
import java.util.*;

public class atcoder_ABC140_F{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements
        int N = scanner.nextInt();
        
        // Read the list of integers, sort it in descending order
        List<Integer> S = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            S.add(scanner.nextInt());
        }
        Collections.sort(S, Collections.reverseOrder());
        
        // Initialize a flag list to track which elements have been used
        boolean[] flag = new boolean[N];
        Arrays.fill(flag, true);
        
        // Initialize the current list with the largest element
        List<Integer> cur = new ArrayList<>();
        cur.add(S.get(0));
        
        // Mark the first element as used
        flag[0] = false;
        
        // Iterate N times to build the current list
        for (int i = 0; i < N; i++) {
            int j = 0;  // Index for the current list
            int jM = cur.size();  // Length of the current list
            
            // Try to find the next largest unused element
            for (int k = 0; k < N; k++) {
                // Check if the current element is unused and smaller than the last added element
                if (flag[k] && S.get(k) < cur.get(j)) {
                    cur.add(S.get(k));  // Add the element to the current list
                    j++;  // Move to the next index in the current list
                    flag[k] = false;  // Mark this element as used
                    
                    // If we have added enough elements, break out of the loop
                    if (j == jM) {
                        break;
                    }
                }
            }
            
            // If we couldn't find a suitable element, return "No"
            if (j!= jM) {
                System.out.println("No");
                return;
            }
            
            // Sort the current list in descending order for the next iteration
            Collections.sort(cur, Collections.reverseOrder());
        }
        
        // If we successfully built the list, return "Yes"
        System.out.println("Yes");
    }
}

Translate the above Java code to C++ and end with comment "