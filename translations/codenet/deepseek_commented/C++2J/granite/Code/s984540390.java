
import java.util.*;
import java.io.*;

public class s984540390{
    public static void main(String[] args) throws IOException {
        // Input the value of h
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long h = Long.parseLong(br.readLine());

        // Loop to calculate the answer
        long ans = 0, cnt = 1;
        while (h!= 1) {
            if (h % 2!= 0) {
                h--; // Decrement h if it is odd
            }
            h /= 2; // Divide h by 2
            cnt *= 2; // Double the count
            ans += cnt; // Increment the sum by the current count
        }

        // Output the final result
        System.out.println(ans + 1);
    }
}
