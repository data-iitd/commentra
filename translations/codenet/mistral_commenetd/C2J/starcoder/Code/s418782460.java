
import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) {

		String sInput = ""; // Initialize a string to store a single input line
		String[] asInput = new String[2]; // Initialize an array to store the two input lines
		String[] asWords = new String[2]; // Initialize an array to store the tokens from the input lines
		String[] asComingSec = new String[2]; // Initialize an array to store the arrival times of the humans
		int nHumanNumber = 0; // Initialize a counter for the number of humans
		int nNextHumanIndex = 0; // Initialize a counter for the index of the next human
		int nWaterLength = 0; // Initialize the length of the water wave
		int nWaterLife = 0; // Initialize the life of the water wave
		int nStart = 0; // Initialize the start time of the water wave
		int nStop = 0; // Initialize the stop time of the water wave

		int nIndex = 0; // Initialize a counter for iterating through the array
		int i = 0; // Initialize a counter for iterating through the humans
		int j = 0; // Initialize a counter for iterating through the humans

		// Read the first line of input
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			sInput = br.readLine(); // Read a line from the standard input stream
			asInput = sInput.split(" "); // Parse the line using whitespace as the delimiter
			nHumanNumber = Integer.parseInt(asInput[0]); // Convert the first token to an integer representing the number of humans
			nWaterLength = Integer.parseInt(asInput[1]); // Convert the second token to an integer representing the length of the water wave
		} catch (IOException e) {
			e.printStackTrace();
		}

		// Read the second line of input
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			sInput = br.readLine(); // Read a line from the standard input stream
			asComingSec = sInput.split(" "); // Parse the line using whitespace as the delimiter
		} catch (IOException e) {
			e.printStackTrace();
		}

		// Initialize the start time of the water wave to the arrival time of the first human
		nStart = Integer.parseInt(asComingSec[0]);

		// Calculate the life of the water wave by iterating through the humans and finding the overlapping periods
		while (nNextHumanIndex < nHumanNumber) {
			if (nNextHumanIndex == nHumanNumber) {
				break; // If we have reached the last human, we are done
			} else {
				// Calculate the stop time of the water wave based on the start time and the length of the water wave
				nStop = nStart + nWaterLength;

				// Check if the next human arrives before the stop time of the water wave
				if (Integer.parseInt(asComingSec[nNextHumanIndex]) < nStop) {
					// If the next human arrives before the stop time, we need to find the maximum stop time that includes both the current and next human
					while (nNextHumanIndex < nHumanNumber && Integer.parseInt(asComingSec[nNextHumanIndex]) < nStop) {
						if (nStop <= Integer.parseInt(asComingSec[nNextHumanIndex]) + nWaterLength) {
							nStop = Integer.parseInt(asComingSec[nNextHumanIndex]) + nWaterLength; // Update the stop time to include the next human
							nNextHumanIndex++; // Move to the next human
						}
					}

					// If we have reached the end of the array, we have found the maximum stop time that includes all the humans
					if (nNextHumanIndex == nHumanNumber) {
						nWaterLife += (nStop - nStart); // Calculate the life of the water wave based on the start and stop times
						break; // Exit the loop
					}
				}

				// If the next human arrives after the stop time of the water wave, we can update the start time to the arrival time of the next human and continue the loop
				nStart = nStop;
				if (nStart < Integer.parseInt(asComingSec[nNextHumanIndex])) {
					nStart = Integer.parseInt(asComingSec[nNextHumanIndex]); // Update the start time to the arrival time of the next human
				}
			}
		}

		// Print the life of the water wave to the standard output stream
		System.out.println(nWaterLife);

	}

}

