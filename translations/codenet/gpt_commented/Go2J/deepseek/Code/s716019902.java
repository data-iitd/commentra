import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int sum = 0;

        for (int i = 1; i <= N; i++) {
            if (i % 3 == 0 || i % 5 == 0) {
                continue; // Skip numbers divisible by 3 or 5
            }
            sum += i; // Add the number to the sum
        }

        System.out.println(sum);
    }
}
