import java.util.*;
import java.io.*;
import java.nio.charset.StandardCharsets;

public class Main {
	List<Long> constraints = new ArrayList<>(); // Initialize a list to store constraints
	long N; // Declare a variable to store the value of N
	long result; // Declare a variable to store the final result

	Main() throws IOException { // Constructor to initialize and read input
		InputStreamReader reader = new InputStreamReader(System.in, StandardCharsets.UTF_8); // Create a reader for input stream
		BufferedReader in = new BufferedReader(reader); // Create a buffered reader to read input
		this.N = Long.parseLong(in.readLine()); // Read the value of N
		for (int i = 0; i < 5; ++i) { // Loop to read 5 constraints
			this.constraints.add(Long.parseLong(in.readLine())); // Add each constraint to the list
		}
		in.close(); // Close the buffered reader

		this.calc(); // Call the calc method to perform the calculations
	}

	void calc() { // Method to perform the calculation
		long min = Long.MAX_VALUE; // Initialize a variable to store the minimum value in constraints
		for (Long c : this.constraints) { // Loop through each constraint
			min = Math.min(min, c); // Update the minimum value
		}
		long time = this.N / min; // Calculate the number of steps by dividing N by the minimum constraint
		if (this.N % min != 0) { // Check if there is a remainder
			++time; // If there is a remainder, add one more step
		}
		time += 4; // Add 4 to the time to account for additional steps
		this.result = time; // Store the final result
	}

	public static void main(String[] args) throws IOException { // Main method to execute the program
		Main ins = new Main(); // Create an instance of the Main class
		System.out.println(ins.result); // Print the result to the standard output

	}

}
