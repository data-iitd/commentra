
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // Read the number of elements N
        int N = sc.nextInt();
        
        // Read the list of integers S, sort them in descending order
        int[] S = new int[N];
        for (int i = 0; i < N; i++) {
            S[i] = sc.nextInt();
        }
        Arrays.sort(S);
        Arrays.sort(S, Collections.reverseOrder());
        
        // Initialize a flag array to keep track of used elements
        boolean[] flag = new boolean[N];
        
        // Initialize the current list with the first element of S
        List<Integer> cur = new ArrayList<Integer>();
        cur.add(S[0]);
        
        // Set the flag for the first element to False
        flag[0] = false;
        
        // Loop through N times
        for (int i = 0; i < N; i++) {
            int j = 0;
            int jM = cur.size();
            
            // Iterate over the elements of S
            for (int k = 0; k < N; k++) {
                if (!flag[k] && S[k] < cur.get(j)) {
                    // Add the element to cur, set its flag to False, and increment j
                    cur.add(S[k]);
                    j++;
                    flag[k] = false;
                    if (j == jM) {
                        break;
                    }
                }
            }
            
            // If no such element is found, return "No"
            if (j == jM) {
                System.out.println("No");
                return;
            }
            
            // Sort cur in descending order
            Collections.sort(cur, Collections.reverseOrder());
        }
        
        // Return "Yes" if the condition is satisfied
        System.out.println("Yes");
    }
}

