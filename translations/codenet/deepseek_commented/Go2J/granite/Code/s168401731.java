
import java.io.*;
import java.util.*;

public class s168401731{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        // Check if command-line arguments are provided for file input/output.
        if (args.length > 0) {
            br = new BufferedReader(new FileReader(args[0]));
            if (args.length > 1) {
                bw = new BufferedWriter(new FileWriter(args[1]));
            }
        }

        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);

        String ans = "second";
        for (int i = 0; i < n; i++) {
            int a = Integer.parseInt(br.readLine());
            if (a % 2 == 1) {
                ans = "first";
                break;
            }
        }
        // Print the result based on the condition.
        bw.write(ans);
        bw.newLine();
        bw.flush();
    }
}

