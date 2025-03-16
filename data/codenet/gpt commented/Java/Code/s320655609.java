import java.util.*;
import java.io.*;
import java.nio.charset.StandardCharsets;

public class Main {
    // List to hold the constraints
    List<Long> constraints = new ArrayList<>();
    long N; // Variable to hold the input number
    long result; // Variable to store the final result

    // Constructor that initializes the input and performs calculations
    Main() throws IOException {
        // Set up a reader to read input from standard input with UTF-8 encoding
        InputStreamReader reader = new InputStreamReader(System.in, StandardCharsets.UTF_8);
        BufferedReader in = new BufferedReader(reader);
        
        // Read the first line of input as the value of N
        this.N = Long.parseLong(in.readLine());
        
        // Read the next 5 lines of input as constraints and add them to the list
        for (int i = 0; i < 5; ++i) {
            this.constraints.add(Long.parseLong(in.readLine()));
        }
        
        // Close the input reader
        in.close();

        // Call the calculation method to compute the result
        this.calc();
    }

    // Method to perform the calculation based on the constraints and N
    void calc() {
        long min = Long.MAX_VALUE; // Initialize min to the maximum possible value
        
        // Find the minimum value among the constraints
        for (Long c : this.constraints) {
            min = Math.min(min, c);
        }
        
        // Calculate the time required based on N and the minimum constraint
        long time = this.N / min;
        
        // If N is not perfectly divisible by min, increment time by 1
        if (this.N % min != 0) {
            ++time;
        }
        
        // Add 4 to the calculated time as a fixed overhead
        time += 4;
        
        // Store the final result
        this.result = time;
    }

    // Main method to run the program
    public static void main(String[] args) throws IOException {
        // Create an instance of Main which will handle input and calculations
        Main ins = new Main();
        
        // Print the final result to the standard output
        System.out.println(ins.result);
    }
}
