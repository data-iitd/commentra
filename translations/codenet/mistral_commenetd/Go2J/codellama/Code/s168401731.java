
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // open standard input as default file if no arguments are provided
        File fp = new File("/dev/stdin");
        // open output file if provided as an argument
        File wfp = new File("/dev/stdout");
        if (args.length > 0) {
            fp = new File(args[0]);
            // create output file if provided as an argument
            if (args.length > 1) {
                wfp = new File(args[1]);
            }
        }

        // initialize scanner and writer
        Scanner scanner = new Scanner(fp);
        PrintWriter writer = new PrintWriter(wfp);

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
        writer.println(ans);
        // flush the writer buffer
        writer.flush();

        // close the scanner and writer
        scanner.close();
        writer.close();
    }
}

