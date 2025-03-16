
import java.util.Scanner;

// Function to read a single integer from standard input
public static int I() {
    Scanner sc = new Scanner(System.in);
    return (sc.nextInt());
}

// Function to read a list of integers from standard input
public static int[] LI() {
    Scanner sc = new Scanner(System.in);
    String[] S = sc.nextLine().split(" ");
    int[] A = new int[S.length];
    for (int i = 0; i < S.length; i++) {
        A[i] = Integer.parseInt(S[i]);
    }
    return A;
}

public static void main(String[] args) {
    // Read the number of elements
    int N = I();
    
    // Read the list of integers, sort it in descending order
    int[] S = LI();
    java.util.Arrays.sort(S);
    
    // Initialize a flag list to track which elements have been used
    boolean[] flag = new boolean[S.length];
    
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
        for (int k = 0; k < S.length; k++) {
            // Check if the current element is unused and smaller than the last added element
            if (flag[k] && S[k] < cur[j]) {
                cur = java.util.Arrays.copyOf(cur, cur.length + 1);
                cur[j + 1] = S[k];  // Add the element to the current list
                j++;  // Move to the next index in the current list
                flag[k] = false;  // Mark this element as used
                
                // If we have added enough elements, break out of the loop
                if (j == jM) {
                    break;
                }
            }
        }
        else {
            // If we couldn't find a suitable element, return "No"
            System.out.println("No");
            return;
        }
        
        // Sort the current list in descending order for the next iteration
        java.util.Arrays.sort(cur);
    }
    
    // If we successfully built the list, return "Yes"
    System.out.println("Yes");
}

