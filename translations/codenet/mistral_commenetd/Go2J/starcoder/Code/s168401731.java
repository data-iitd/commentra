
package main;

import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        // open standard input as default file if no arguments are provided
        InputStream fp = System.in;
        // open output file if provided as an argument
        OutputStream wfp = System.out;
        if (args.length > 0) {
            fp = new FileInputStream(args[0]);
            // create output file if provided as an argument
            if (args.length > 1) {
                wfp = new FileOutputStream(args[1]);
            }
        }

        // initialize scanner and writer
        Scanner scanner = new Scanner(fp);
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(wfp));

        // read the first integer from the input
        int n = scanner.nextInt();

        // initialize answer variable
        String ans = "second";
        // iterate through the input integers
        for (int i = 0; i < n; i++) {
            // read the next integer from the input
            int a = scanner.nextInt();
            // check if the current integer is odd
            if (a % 2 == 1) {
                // update the answer if an odd integer is found
                ans = "first";
                // exit the loop if only one odd integer is found
                break;
            }
        }
        // write the answer to the output
        writer.write(ans);
        writer.newLine();
        // flush the writer buffer
        writer.flush();
    }
}

