import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner();
        
        int n = sc.nextInt();
        double[] arr = new double[n];
        for (int i = 0; i < n; i++) {
            arr[i] = (double) sc.nextInt();
        }
        Arrays.sort(arr);
        
        double prev = arr[0];
        for (int i = 1; i < arr.length; i++) {
            prev = (prev + arr[i]) / 2;
        }

        System.out.printf("%f\n", prev);
    }
}

class Scanner {
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
