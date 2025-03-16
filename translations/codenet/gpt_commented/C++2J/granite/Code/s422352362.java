
import java.util.*;
import java.io.*;

public class s422352362{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        // Read the number of elements
        int n = Integer.parseInt(br.readLine());
        
        // Read the input values into the array 'a'
        String[] input = br.readLine().split(" ");
        long[] a = new long[n + 1];
        for(int i = 1; i <= n; i++) {
            a[i] = Long.parseLong(input[i - 1]);
        }

        long[] pre = new long[n + 1];
        long[] last = new long[n + 1];

        long sumpre = 0, sumlast = 0;

        // Calculate prefix sums and store them in 'pre' array
        for(int i = 1; i < n; i++) {
            sumpre = sumpre + a[i];
            pre[i] = sumpre;
            // Debugging output for prefix sums (commented out)
            // bw.write(sumpre + "++\n");
        }

        // Calculate suffix sums and store them in 'last' array
        for(int i = n; i > 1; i--) {
            sumlast = sumlast + a[i];
            last[i] = sumlast;
            // Debugging output for suffix sums (commented out)
            // bw.write(sumlast + "+++\n");
        }

        // Initialize 'd' to a large value to find the minimum difference
        long d = (1L << 60);

        // Calculate the minimum absolute difference between prefix and suffix sums
        for(int i = 1; i < n; i++) {
            // Debugging output for the difference calculation (commented out)
            // bw.write((pre[i] - last[i + 1]) + "\n");
            d = Math.min(d, Math.abs(pre[i] - last[i + 1]));
        }

        // Output the minimum difference found
        bw.write(d + "\n");

        // Close the output stream
        bw.close();
    }
}

