import java.util.Scanner; 

public class Main { 
    public static void main(String[] args) { 
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in); 
        
        // Read the number of rows (n), columns (m), and the minimum required value (x)
        int n = sc.nextInt(), m = sc.nextInt(), x = sc.nextInt(), min = Integer.MAX_VALUE; 
        
        // Initialize a 2D array to store the input values
        int[][] a = new int[n][m + 1]; 
        
        // Read the values into the 2D array
        for (int i = 0; i < n; i++) { 
            for (int j = 0; j <= m; j++) 
                a[i][j] = sc.nextInt(); 
        } 
        
        // Iterate through all possible combinations of rows using bit manipulation
        for (int i = 0; i < Math.pow(2, n); i++) { 
            // Create an array to track which rows are included in the current combination
            int[] status = new int[n]; 
            
            // Determine which rows are included in the current combination
            for (int j = 0; j < n; j++) { 
                if ((1 & i >> j) == 1) { 
                    status[j] = 1; 
                } 
            } 
            
            // Initialize an array to store the sum of the selected rows
            int[] res = new int[m + 1]; 
            
            // Calculate the sum of the selected rows
            for (int j = 0; j < n; j++) { 
                if (status[j] == 1) { 
                    for (int k = 0; k <= m; k++) { 
                        res[k] += a[j][k]; 
                    } 
                } 
            } 
            
            // Check if the current combination meets the minimum requirement for each column
            boolean flag = true; 
            for (int j = 1; j <= m; j++) { 
                if (res[j] < x) { 
                    flag = false; 
                    break; 
                } 
            } 
            
            // If the combination is valid, update the minimum value found
            if (flag) 
                min = Math.min(min, res[0]); 
        } 
        
        // Output the result: -1 if no valid combination was found, otherwise the minimum value
        if (min == Integer.MAX_VALUE) 
            System.out.println(-1); 
        else 
            System.out.println(min); 
    } 
}
