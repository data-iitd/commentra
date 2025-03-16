
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class s940603045{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String N = br.readLine();
        int sum = 0;
        for (char c : N.toCharArray()) {
            sum += c - '0';
        }
        int m = Integer.parseInt(N);
        if (m % sum == 0) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}

