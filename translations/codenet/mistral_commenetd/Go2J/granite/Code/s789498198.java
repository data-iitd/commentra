
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class s789498198{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] ab = br.readLine().split(" ");
        int a = Integer.parseInt(ab[0]);
        int b = Integer.parseInt(ab[1]);
        if ((a + b) % 2 == 0) {
            System.out.println((a + b) / 2);
        } else {
            System.out.println("IMPOSSIBLE");
        }
    }
}
