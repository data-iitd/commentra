import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Ask the user for the number of inputs
        int N = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character
        
        // Create a list 'x' of size 'N' using a list comprehension
        double[] x = new double[N];
        for (int i = 0; i < N; i++) {
            String input = scanner.nextLine();
            if (input.contains("JPY")) {
                x[i] = Double.parseDouble(input.replace("JPY", ""));
            } else if (input.contains("BTC")) {
                x[i] = Double.parseDouble(input.replace("BTC", "")) * 380000.0;
            }
        }
        
        // Print the sum of all the elements in the list 'x'
        double sum = 0;
        for (double value : x) {
            sum += value;
        }
        System.out.println(sum);
    }
}
