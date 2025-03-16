

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.StringTokenizer;

public class s168401731{

    public static void main(String[] args) throws IOException {
        // open standard input as default file if no arguments are provided
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        // open output file if provided as an argument
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
        if (args.length > 0) {
            reader = new BufferedReader(new FileReader(args[0]));
            // create output file if provided as an argument
            if (args.length > 1) {
                writer = new BufferedWriter(new FileWriter(args[1]));
            }
        }

        // initialize scanner and writer
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());

        // read the first integer from the input
        int n = Integer.parseInt(tokenizer.nextToken());

        // initialize answer variable
        String ans = "second";
        // iterate through the input integers
        for (int i = 0; i < n; i++) {
            // read the next integer from the input
            int a = Integer.parseInt(tokenizer.nextToken());
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
        // flush the writer buffer
        writer.flush();
        writer.close();
    }
}

