import java.util.Scanner;

public class CurrencyConverter {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of currency inputs from the user
        int N = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character
        
        // Create a list of converted currency values
        double[] convertedValues = new double[N];
        
        for (int i = 0; i < N; i++) {
            // Read each input line
            String input = scanner.nextLine();
            
            // Replace 'JPY' with its equivalent in float and 'BTC' with its equivalent in float
            if (input.contains("JPY")) {
                input = input.replace("JPY", "* 1.0");
            } else if (input.contains("BTC")) {
                input = input.replace("BTC", "* 380000.0");
            }
            
            // Evaluate the expression and store the result in the list
            convertedValues[i] = eval(input);
        }
        
        // Calculate and print the total sum of the converted currency values
        double totalSum = 0;
        for (double value : convertedValues) {
            totalSum += value;
        }
        
        System.out.println(totalSum);
    }
}
