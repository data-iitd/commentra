import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] input = br.readLine().split(" ");
        int[] a = new int[n];

        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(input[i]);
        }

        Arrays.sort(a);
        int min = a[0];
        boolean hasNonMultiple = false;

        for (int x : a) {
            if (x % min != 0) {
                hasNonMultiple = true;
                break;
            }
        }

        System.out.println(hasNonMultiple ? min : -1);
    }
}
// <END-OF-CODE>
