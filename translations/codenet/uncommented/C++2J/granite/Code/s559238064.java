
import java.util.*;
import java.io.*;

public class s559238064{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        int n = s.length();
        for (int i = 0; i < n - 1; i++) {
            if (s.charAt(i) == s.charAt(i + 1)) {
                System.out.println("Bad");
                return;
            }
        }
        System.out.println("Good");
    }
}

