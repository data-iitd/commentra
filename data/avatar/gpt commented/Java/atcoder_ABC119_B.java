import java.util.Scanner; 
import java.util.stream.IntStream; 

public class Main { 
    public static void main(String[] args) { 
        // Create a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in); 
        
        // Read the number of currency entries
        int N = sc.nextInt(); 
        
        // Initialize arrays to hold the amounts and their corresponding currency units
        double[] x = new double[N]; 
        String[] u = new String[N]; 
        
        // Loop to read each amount and its currency unit
        for (int i = 0; i < N; ++i) { 
            x[i] = sc.nextDouble(); // Read the amount
            u[i] = sc.next(); // Read the currency unit
        } 
        
        // Calculate the total value in a standard currency and print the result
        System.out.println(solve(x, u)); 
        
        // Close the scanner to prevent resource leaks
        sc.close(); 
    } 
    
    // Method to solve the currency conversion problem
    static double solve(double[] x, String[] u) { 
        // Convert each amount to a standard currency and sum them up
        return IntStream.range(0, x.length)
            .mapToDouble(i -> x[i] * (u[i].equals("JPY") ? 1 : 380000)) // Convert JPY to standard currency (1) and other currencies to JPY (380000)
            .sum(); // Return the total sum
    } 
}
