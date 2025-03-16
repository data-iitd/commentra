import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        try {
            String[] input = br.readLine().split(" ");
            int a = Integer.parseInt(input[0]);
            double b = Double.parseDouble(input[1]);
            int bInt = (int) Math.round(b * 100);
            System.out.println(a * bInt / 100);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
// <END-OF-CODE>
