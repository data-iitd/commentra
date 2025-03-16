import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner();

        // Read the number of elements
        int n = sc.nextInt();

        // Initialize an array to hold the float values
        double[] arr = new double[n];

        // Read each integer and convert it to double, then store in the array
        for (int i = 0; i < n; i++) {
            arr[i] = (double) sc.nextInt();
        }

        // Sort the array of double values
        Arrays.sort(arr);

        // Initialize a variable to keep track of the running average
        double prev = arr[0];

        // Iterate through the sorted array to calculate the average
        for (int i = 1; i < arr.length; i++) {
            prev = (prev + arr[i]) / 2;
        }

        // Print the final average
        System.out.printf("%f\n", prev);
    }

    static class Scanner {
        private BufferedReader reader;
        private String[] tokens;
        private int index;

        public Scanner() {
            reader = new BufferedReader(new InputStreamReader(System.in));
            tokens = new String[0];
            index = 0;
        }

        public String next() throws IOException {
            if (index >= tokens.length) {
                tokens = reader.readLine().split(" ");
                index = 0;
            }
            return tokens[index++];
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }
    }
}

// <END-OF-CODE>
