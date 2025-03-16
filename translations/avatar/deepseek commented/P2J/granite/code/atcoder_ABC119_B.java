

import java.util.Scanner;

public class atcoder_ABC119_B{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();  // Take an integer input N, which represents the number of elements.
        double[] x = new double[N];
        for (int i = 0; i < N; i++) {
            String s = scanner.next();  // Take a string input s.
            if (s.equals("JPY")) {
                x[i] = 1.0;  // Replace 'JPY' with 1.0.
            } else if (s.equals("BTC")) {
                x[i] = 380000.0;  // Replace 'BTC' with 380000.0.
            } else {
                x[i] = Double.parseDouble(s);  // Parse the string s as a double and assign it to x[i].
            }
        }
        double sum = 0.0;
        for (double d : x) {
            sum += d;  // Calculate the sum of the elements in the array x.
        }
        System.out.println(sum);  // Print the sum of the elements in the array x.
    }
}
// 