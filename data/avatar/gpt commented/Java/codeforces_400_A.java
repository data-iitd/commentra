import java.io.BufferedReader; 
import java.io.IOException; 
import java.io.InputStreamReader; 
import java.io.PrintWriter; 
import java.util.Arrays; 

public class Main { 

    // Method to check if a given string can form a solution for a specific column count
    public static boolean isSolution(int columnsCount, String x) { 
        // Create an array to track if all positions for each column are 'X'
        boolean allXs[] = new boolean[columnsCount]; 
        Arrays.fill(allXs, true); // Initialize all positions as true (all 'X's)

        // Check each character in the string
        for (int i = 0; i < 12; i++) { 
            // If the character is not 'X', mark the corresponding column as false
            if (x.charAt(i) != 'X') 
                allXs[i % columnsCount] = false; 
        }

        // Check if any column has all 'X's
        for (int i = 0; i < columnsCount; i++) 
            if (allXs[i]) 
                return true; // Return true if a valid solution is found

        return false; // Return false if no valid solution is found
    } 

    public static void main(String[] args) throws IOException { 
        // Initialize BufferedReader to read input from the console
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
        // Initialize PrintWriter to output results to the console
        PrintWriter pw = new PrintWriter(System.out); 

        // Read the number of test cases
        int t = Integer.parseInt(br.readLine()); 

        // Process each test case
        for (int i = 0; i < t; i++) { 
            int possibleSolutions = 0; // Counter for possible solutions
            StringBuilder solutions = new StringBuilder(); // To store the solutions
            String s = br.readLine(); // Read the input string

            // Check for various column configurations and append valid solutions
            if (isSolution(12, s)) { 
                solutions.append(" 1x12"); 
                possibleSolutions++; 
            } 
            if (isSolution(6, s)) { 
                solutions.append(" 2x6"); 
                possibleSolutions++; 
            } 
            if (isSolution(4, s)) { 
                solutions.append(" 3x4"); 
                possibleSolutions++; 
            } 
            if (isSolution(3, s)) { 
                solutions.append(" 4x3"); 
                possibleSolutions++; 
            } 
            if (isSolution(2, s)) { 
                solutions.append(" 6x2"); 
                possibleSolutions++; 
            } 
            if (isSolution(1, s)) { 
                solutions.append(" 12x1"); 
                possibleSolutions++; 
            } 

            // Output the number of possible solutions and the solutions themselves
            pw.print(possibleSolutions); 
            pw.println(solutions); 
        } 

        // Flush and close the PrintWriter
        pw.flush(); 
        pw.close(); 
    } 
}
