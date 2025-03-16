import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(reader.readLine());
        
        int rt = (int) Math.sqrt(n);
        int minf = 100;
        
        for (int i = 1; i < rt + 1; i++) {
            if (n % i == 0) {
                int b = n / i;
                int ndigit = 0;
                while (b > 0) {
                    b /= 10;
                    ndigit++;
                }
                minf = Math.min(minf, ndigit);
            }
        }
        
        System.out.println(minf);
    }
}
