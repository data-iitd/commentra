
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.StringTokenizer;

public class s953070177{
    public static void main(String[] args) throws IOException {
        // Determine the input source: standard input or a file specified as a command-line argument.
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

        // Read the number of elements from the input.
        int n = Integer.parseInt(reader.readLine());

        // Initialize an array to hold the elements and a variable to store the total sum of absolute differences.
        int[] aa = new int[n + 2];
        int sum = 0;

        // Read the elements into the array and calculate the total sum of absolute differences between consecutive elements.
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        for (int i = 0; i < n; i++) {
            aa[i + 1] = Integer.parseInt(tokenizer.nextToken());
            sum += Math.abs(aa[i + 1] - aa[i]);
        }
        // Include the difference between the last element and the element before it.
        sum += Math.abs(aa[n + 1] - aa[n]);

        // Calculate and print the result for each element.
        for (int i = 1; i < n + 1; i++) {
            // Calculate the new sum of absolute differences if the i-th element is removed.
            int ans = sum - Math.abs(aa[i + 1] - aa[i]) - Math.abs(aa[i] - aa[i - 1]) + Math.abs(aa[i + 1] - aa[i - 1]);
            writer.write(String.valueOf(ans)); // Output the result for the current element.
            writer.newLine();
        }

        // Flush the buffered writer to ensure all output is written.
        writer.flush();
    }
}

// Translate the above Java code to C++ and end with comment "