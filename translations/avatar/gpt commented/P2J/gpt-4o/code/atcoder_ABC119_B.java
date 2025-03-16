import java.util.Scanner;

public class CurrencyConverter {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of currency inputs from the user
        int N = Integer.parseInt(scanner.nextLine());
        
        // Create a variable to hold the total sum of converted currency values
        double totalSum = 0.0;
        
        // For each input, replace 'JPY' with its equivalent in float and 'BTC' with its equivalent in float
        for (int i = 0; i < N; i++) {
            String input = scanner.nextLine();
            input = input.replace("JPY", "* 1.0").replace("BTC", "* 380000.0");
            totalSum += eval(input);
        }
        
        // Calculate and print the total sum of the converted currency values
        System.out.println(totalSum);
        
        scanner.close();
    }
    
    // Method to evaluate the expression
    private static double eval(String expression) {
        // This is a simple implementation using JavaScript engine to evaluate the expression
        try {
            return (double) new javax.script.ScriptEngineManager().getEngineByName("JavaScript").eval(expression);
        } catch (Exception e) {
            e.printStackTrace();
            return 0.0;
        }
    }
}

// <END-OF-CODE>
