
import java.util.Scanner;

// Function to read an integer from standard input
public static int I() {
    Scanner sc = new Scanner(System.in);
    return sc.nextInt();
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
    // Read the number of elements N
    int N = I();
    
    // Read the list of integers S, sort them in descending order
    int[] S = LI();
    java.util.Arrays.sort(S);
    
    // Initialize a flag array to keep track of used elements
    boolean[] flag = new boolean[S.length];
    
    // Initialize the current list with the first element of S
    int[] cur = new int[1];
    cur[0] = S[0];
    
    // Set the flag for the first element to False
    flag[0] = false;
    
    // Loop through N times
    for (int i = 0; i < N; i++) {
        int j = 0;
        int jM = cur.length;
        
        // Iterate over the elements of S
        for (int k = 0; k < S.length; k++) {
            if (flag[k] && S[k] < cur[j]) {
                // Add the element to cur, set its flag to False, and increment j
                int[] temp = new int[cur.length + 1];
                for (int l = 0; l < cur.length; l++) {
                    temp[l] = cur[l];
                }
                temp[cur.length] = S[k];
                cur = temp;
                j += 1;
                flag[k] = false;
                if (j == jM) {
                    break;
                }
            }
        }
        
        // If no such element is found, return "No"
        else {
            System.out.println("No");
            return;
        }
        
        // Sort cur in descending order
        java.util.Arrays.sort(cur);
    }
    
    // Return "Yes" if the condition is satisfied
    System.out.println("Yes");
}

