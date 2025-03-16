import java.util.Scanner;

public class CurrencySum {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Ask the user for the number of inputs
        int N = Integer.parseInt(scanner.nextLine());
        
        // Create an array 'x' of size 'N'
        double[] x = new double[N];
        
        // Read inputs and calculate values
        for (int i = 0; i < N; i++) {
            String input = scanner.nextLine();
            input = input.replace("JPY", "* 1.0").replace("BTC", "* 380000.0");
            x[i] = eval(input);
        }
        
        // Print the sum of all the elements in the array 'x'
        double sum = 0;
        for (double value : x) {
            sum += value;
        }
        System.out.println(sum);
        
        scanner.close();
    }
    
    // Method to evaluate the expression
    private static double eval(String expression) {
        // This is a simple implementation using JavaScript engine
        // Note: This requires Java 6 or higher
        try {
            return (double) new javax.script.ScriptEngineManager()
                .getEngineByName("JavaScript")
                .eval(expression);
        } catch (Exception e) {
            e.printStackTrace();
            return 0;
        }
    }
}

// <END-OF-CODE>
