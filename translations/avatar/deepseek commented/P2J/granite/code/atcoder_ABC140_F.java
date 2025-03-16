

import java.util.*;

public class atcoder_ABC140_F{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // Read the number of elements N
        int N = sc.nextInt();
        
        // Read the list of integers S, sort them in descending order
        List<Integer> S = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            S.add(sc.nextInt());
        }
        Collections.sort(S, Collections.reverseOrder());
        
        // Initialize a flag array to keep track of used elements
        boolean[] flag = new boolean[N];
        Arrays.fill(flag, true);
        
        // Initialize the current list with the first element of S
        List<Integer> cur = new ArrayList<>();
        cur.add(S.get(0));
        
        // Set the flag for the first element to False
        flag[0] = false;
        
        // Loop through N times
        for (int i = 0; i < N; i++) {
            int j = 0;
            int jM = cur.size();
            
            // Iterate over the elements of S
            for (int k = 0; k < N; k++) {
                if (flag[k] && S.get(k) < cur.get(j)) {
                    // Add the element to cur, set its flag to False, and increment j
                    cur.add(S.get(k));
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

Translate the above Java code to C++ and end with comment "