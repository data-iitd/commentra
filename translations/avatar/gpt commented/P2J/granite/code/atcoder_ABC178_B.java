
import java.util.*;
import java.io.*;

class atcoder_ABC178_B {
    public static void main(String[] args) throws Exception {
        // Read four integers from input
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int a = Integer.parseInt(input[0]);
        int b = Integer.parseInt(input[1]);
        int c = Integer.parseInt(input[2]);
        int d = Integer.parseInt(input[3]);
        
        // Calculate the maximum value from the products of the pairs and return it
        int max = Math.max(a * c, Math.max(b * d, Math.max(a * d, b * c)));
        
        // Print the result
        System.out.println(max);
    }
}

Translate the above Java code to C++ and end with comment "