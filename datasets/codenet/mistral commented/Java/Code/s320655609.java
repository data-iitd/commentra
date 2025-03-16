
import java.util.*;
import java.io.*;
import java.nio.charset.StandardCharsets;

public class Main {
	// Initialize an empty ArrayList to store constraints
	List<Long> constraints = new ArrayList<>();
	// Initialize variables
	long N;
	long result;

	// Constructor
	public Main() throws IOException {
		// Create an InputStreamReader and BufferedReader to read input from standard input
		InputStreamReader reader = new InputStreamReader(System.in, StandardCharsets.UTF_8);
		BufferedReader in = new BufferedReader(reader);

		// Read the number of test cases N
		this.N = Long.parseLong(in.readLine());

		// Read and store 5 constraints
		for (int i = 0; i < 5; ++i) {
			this.constraints.add(Long.parseLong(in.readLine()));
		}

		// Close the BufferedReader
		in.close();

		// Call the calc() method to calculate the result
		this.calc();
	}

	// Calculate the result
	void calc() {
		// Initialize a variable to store the minimum constraint
		long min = Long.MAX_VALUE;

		// Iterate through the constraints and find the minimum one
		for (Long c : this.constraints) {
			min = Math.min(min, c);
		}

		// Calculate the time required to complete all tasks
		long time = this.N / min;

		// Check if the number of tasks N cannot be evenly divided by the minimum constraint
		if (this.N % min != 0) {
			// If not, add one to the time
			++time;
		}

		// Add 4 to the time to account for the time taken to read and process each constraint
		time += 4;

		// Store the result
		this.result = time;
	}

	// Main method to run the program
	public static void main(String[] args) throws IOException {
		// Create an instance of the Main class and call its constructor
		Main ins = new Main();

		// Print the result
		System.out.println(ins.result);
	}
}