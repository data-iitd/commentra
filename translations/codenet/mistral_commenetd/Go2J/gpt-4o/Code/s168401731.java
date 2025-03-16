import java.io.*;
import java.util.Scanner;

public class Main {
    // main function is the entry point of the program
    public static void main(String[] args) throws IOException {
        // open standard input as default file if no arguments are provided
        InputStream inputStream = System.in;
        PrintWriter writer = new PrintWriter(System.out);

        // open input file if provided as an argument
        if (args.length > 0) {
            inputStream = new FileInputStream(args[0]);
            // create output file if provided as an argument
            if (args.length > 1) {
                writer = new PrintWriter(new FileOutputStream(args[1]));
            }
        }

        // initialize scanner
        Scanner scanner = new Scanner(inputStream);

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
        writer.close();
        scanner.close();
    }
}
// <END-OF-CODE>
