import java.io.BufferedReader; // Importing BufferedReader class for reading lines from standard input
import java.io.IOException; // Importing IOException for handling input/output errors
import java.io.InputStreamReader; // Importing InputStreamReader class for wrapping an input stream
import java.math.BigDecimal; // Importing BigDecimal class for handling decimal numbers

public class Main {
    // Main method is the entry point of the Java application
    public static void main(String[] args) throws IOException {
        // Creating BufferedReader object for reading input from the standard input stream
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

        // Reading the first line of input using StringTokenizer
        StringTokenizer st = new StringTokenizer(in.readLine());

        // Creating BigDecimal objects for reading and storing the first and second numbers from the input
        BigDecimal a = new BigDecimal(st.nextToken());
        BigDecimal b = new BigDecimal(st.nextToken());

        // Multiplying the two numbers using BigDecimal's multiply() method and storing the result in mul variable
        BigDecimal mul = a.multiply(b);

        // Creating a new StringTokenizer object for splitting the string representation of the multiplication result into parts using '.' as the delimiter
        st = new StringTokenizer(mul.toString(), ".");

        // Printing the first part of the multiplication result (before the decimal point) to the standard output stream
        System.out.println(st.nextElement());

        // Closing the BufferedReader object to release the system resources
        in.close();
    }
}
