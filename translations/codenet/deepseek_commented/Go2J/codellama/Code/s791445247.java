// by syu
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
    public static void main(String[] args) {
        // Initialize a BufferedReader instance to read from standard input.
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

        // Read two integers, n and k, from the input.
        int n, k;
        try {
            n = Integer.parseInt(in.readLine());
            k = Integer.parseInt(in.readLine());
        } catch (IOException e) {
            e.printStackTrace();
            return;
        }

        // Check if n is divisible by k.
        if (n % k == 0) {
            // If n is divisible by k, print 0.
            System.out.println(0);
        } else {
            // If n is not divisible by k, print 1.
            System.out.println(1);
        }
    }
}

// 