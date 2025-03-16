import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        
        int H = Integer.parseInt(tokenizer.nextToken());
        int W = Integer.parseInt(tokenizer.nextToken());
        int N = Integer.parseInt(tokenizer.nextToken());
        
        int A = Math.max(H, W);
        int result = (N + A - 1) / A;
        
        System.out.println(result);
    }
    
    public static int max(int a, int b) {
        return a < b ? b : a;
    }
}
