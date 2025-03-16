
/*
URL_HERE
*/

import java.io.*;
import java.util.*;

public class s976558978{
    public static void main(String[] args) throws IOException {
        // Run local test with specified input file
        BufferedReader fin = new BufferedReader(new FileReader("dataabc155A.txt"));

        // Read two integers from input
        int a = Integer.parseInt(fin.readLine());
        int b = Integer.parseInt(fin.readLine());

        // Output the smaller integer b times
        if (a < b) {
            for (int i = 0; i < b; i++) {
                System.out.print(a + " ");
            }
            System.out.println();
        } else {
            for (int i = 0; i < a; i++) {
                System.out.print(b + " ");
            }
            System.out.println();
        }

        // Close the input file
        fin.close();
    }
}

