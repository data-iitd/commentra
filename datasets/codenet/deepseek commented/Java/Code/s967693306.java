import java.io.*;
import java.util.*;

class Main{
    final static long INF = Long.MAX_VALUE / 2; // Define constant for infinity
    final static int MOD = 1_000_000_007; // Define constant for modulo
    final static int SIZE = 1_000_000; // Define size for arrays
    long[] fac = new long[SIZE]; // Array to store factorials
    long[] inv = new long[SIZE]; // Array to store modular inverses
    long[] finv = new long[SIZE]; // Array to store inverse factorials
    FastScanner sc = new FastScanner(); // Initialize FastScanner for input

    public static void main(String[] args) { // Main method to run the program
        new Main().solve(); // Create an instance of Main and call solve method
    }

    void solve(){
        int n = sc.nextInt(); // Read number of digits
        int m = sc.nextInt(); // Read number of constraints
        Map<Integer, Integer> map = new HashMap<>(); // Map to store constraints

        for(int i = 0; i < m; i++){
            int s = sc.nextInt(); // Read digit position
            int c = sc.nextInt(); // Read digit value
            if(map.get(s) != null && map.get(s) != c){ // Check for inconsistency
                System.out.println(-1); // Print -1 if inconsistent
                System.exit(0); // Exit the program
            }
            map.put(s, c); // Store the constraint
        }

        for(int i = 0; i < 1000; i++){
            String s = "" + i; // Convert integer to string
            boolean flag = true; // Flag to check validity
            if(s.length() < n) continue; // Skip if length is less than n
            for(int j = 0; j < n; j++){
                if((map.get(j + 1) != null && map.get(j + 1) != Character.getNumericValue(s.charAt(j))) || (map.get(j + 1) == null && Character.getNumericValue(s.charAt(j)) != 0)){
                    if(map.get(j + 1) == null && j == 0 && Character.getNumericValue(s.charAt(j)) == 1){
                        continue;
                    }
                    flag = false; // Set flag to false if invalid
                    break;
                }
            }
            if(flag && s.length() == n){ // Check if valid and has n digits
                System.out.println(s); // Print the valid number
                System.exit(0); // Exit the program
            }
        }

        System.out.println(-1); // Print -1 if no valid number found
    }

    // Helper methods for mathematical operations and string manipulations
    // ...
}