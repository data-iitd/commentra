
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class s048939108{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String S = br.readLine();
        if (S.startsWith("YAKI")) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}

