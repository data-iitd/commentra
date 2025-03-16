import java.util.Scanner;

public class CurrencySum {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int N = Integer.parseInt(scanner.nextLine());  // Take an integer input N
        double sum = 0.0;  // Initialize sum to 0.0
        
        for (int i = 0; i < N; i++) {
            String input = scanner.nextLine();  // Read the input string
            input = input.replace("JPY", "* 1.0").replace("BTC", "* 380000.0");  // Replace currency symbols
            
            // Evaluate the expression and add to sum
            sum += evaluateExpression(input);
        }
        
        System.out.println(sum);  // Print the sum of the elements
        scanner.close();
    }
    
    private static double evaluateExpression(String expression) {
        // This method evaluates the mathematical expression in the string
        // Note: Using a simple script engine to evaluate the expression
        try {
            return (double) new javax.script.ScriptEngineManager()
                .getEngineByName("JavaScript")
                .eval(expression);
        } catch (Exception e) {
            e.printStackTrace();
            return 0.0;  // Return 0.0 in case of an error
        }
    }
}
