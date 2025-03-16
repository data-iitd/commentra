import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // Read the number of elements
        int N = sc.nextInt();
        
        // Read the list of integers, sort it in descending order
        int[] S = new int[N];
        for (int i = 0; i < N; i++) {
            S[i] = sc.nextInt();
        }
        Arrays.sort(S);
        for (int i = 0; i < N; i++) {
            S[i] = -S[i];
        }
        
        // Initialize a flag list to track which elements have been used
        boolean[] flag = new boolean[N];
        for (int i = 0; i < N; i++) {
            flag[i] = true;
        }
        
        // Initialize the current list with the largest element
        int[] cur = new int[1];
        cur[0] = S[0];
        
        // Mark the first element as used
        flag[0] = false;
        
        // Iterate N times to build the current list
        for (int i = 0; i < N; i++) {
            int j = 0;  // Index for the current list
            int jM = cur.length;  // Length of the current list
            
            // Try to find the next largest unused element
            for (int k = 0; k < N; k++) {
                // Check if the current element is unused and smaller than the last added element
                if (flag[k] && S[k] < cur[j]) {
                    int[] tmp = new int[jM + 1];
                    for (int l = 0; l < j; l++) {
                        tmp[l] = cur[l];
                    }
                    tmp[j] = S[k];
                    for (int l = j + 1; l < jM; l++) {
                        tmp[l] = cur[l - 1];
                    }
                    cur = tmp;
                    j += 1;  // Move to the next index in the current list
                    flag[k] = false;  // Mark this element as used
                    
                    // If we have added enough elements, break out of the loop
                    if (j == jM) {
                        break;
                    }
                }
            }
            
            // Sort the current list in descending order for the next iteration
            Arrays.sort(cur);
            for (int k = 0; k < jM; k++) {
                cur[k] = -cur[k];
            }
        }
        
        // If we successfully built the list, print "Yes"
        if (cur.length == N) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}

