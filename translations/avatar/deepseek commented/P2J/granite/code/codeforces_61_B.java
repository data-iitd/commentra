
import java.util.*;
import java.io.*;

public class codeforces_61_B{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] arr = new String[3];
        for (int i = 0; i < 3; i++) {
            arr[i] = br.readLine().replaceAll("[^a-z]", "").toLowerCase();
        }
        Arrays.sort(arr);
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            String s = br.readLine().replaceAll("[^a-z]", "").toLowerCase();
            if (Arrays.asList(arr).contains(s)) {
                System.out.println("ACC");
            } else {
                System.out.println("WA");
            }
        }
    }
}

Translate the above Java code to C++ and end with comment "