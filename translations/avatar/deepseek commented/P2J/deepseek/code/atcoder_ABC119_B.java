import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();  // Take an integer input N, which represents the number of elements.
        double[] x = new double[N];
        for (int i = 0; i < N; i++) {
            String input = scanner.next();
            if (input.contains("JPY")) {
                x[i] = Double.parseDouble(input.replace("JPY", "")) * 1.0;
            } else if (input.contains("BTC")) {
                x[i] = Double.parseDouble(input.replace("BTC", "")) * 380000.0;
            }
        }
        double sum = 0;
        for (int i = 0; i < N; i++) {
            sum += x[i];
        }
        System.out.println(sum);  // Print the sum of the elements in the array x.
    }
}
