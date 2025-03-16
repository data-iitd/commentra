
import java.util.*;
import java.io.*;

public class s465977291{
    public static void main(String[] args) throws IOException {
        // Include necessary import statements for input/output operations, mathematical calculations, and data structures.

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int d = Integer.parseInt(input[1]);

        double a = d * 2 + 1;
        bw.write(String.valueOf(Math.ceil((double)n / a)));
        bw.newLine();

        br.close();
        bw.close();
    }
}

// Translate the above Java code to Python and end with comment "