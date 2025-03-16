import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String S = reader.readLine();
        if (S.startsWith("YAKI")) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}
