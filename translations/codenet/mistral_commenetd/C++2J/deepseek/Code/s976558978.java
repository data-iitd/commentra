import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader fin = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter fout = new PrintWriter(new OutputStreamWriter(System.out));

        String[] tokens = fin.readLine().split(" ");
        int a = Integer.parseInt(tokens[0]);
        int b = Integer.parseInt(tokens[1]);

        if (a < b) {
            for (int i = 0; i < b; i++) {
                fout.print(a);
            }
            fout.println();
        } else {
            for (int i = 0; i < a; i++) {
                fout.print(b);
            }
            fout.println();
        }

        fout.close();
    }
}
