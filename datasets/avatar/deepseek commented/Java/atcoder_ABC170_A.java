import java.io.BufferedReader;  // Importing BufferedReader for input operations
import java.io.IOException;    // Importing IOException for exception handling
import java.io.PrintWriter;    // Importing PrintWriter for output operations

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new java.io.InputStreamReader(System.in));  // Creating BufferedReader object for input
        PrintWriter pw = new PrintWriter(System.out);  // Creating PrintWriter object for output

        String[] input_array = br.readLine().split(" ");  // Reading input and splitting it into an array of strings
        int result = 0;  // Initializing a variable to store the count of non-zero elements

        // Iterating through the array and updating the result
        for (String str : input_array) {
            result += 1;  // Incrementing the result for each element
            if ("0".equals(str)) break;  // Breaking the loop if a zero is encountered
        }

        pw.println(result);  // Printing the result to the console
        br.close();  // Closing the BufferedReader object
        pw.close();  // Closing the PrintWriter object
    }
}
