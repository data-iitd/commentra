
// <START-OF-CODE>

import java.util.Scanner;

public class WaterLife {

    public static void main(String[] args) {
        // Local variables
        Scanner sc = new Scanner(System.in);
        String sInput = ""; // Buffer for the first line of input
        String[] asInput = null; // Array for tokenizing input
        String sLongInputLine = ""; // Buffer for long input line
        String[] asLongInputLine = null; // Array for tokenizing long input line
        int nHumanNumber = 0; // Number of humans
        int nNextHumanIndex = 0; // Index for the next human
        int nWaterLength = 0; // Length of water coverage
        int nWaterLife = 0; // Total water life duration
        int nStart = 0; // Start time for water coverage
        int nStop = 0; // Stop time for water coverage

        int nIndex = 0; // General index variable
        int i = 0; // Loop counter
        int j = 0; // Loop counter

        // Read the first line of input containing number of humans and water length
        sInput = sc.nextLine();
        asInput = sInput.split(" ");
        nHumanNumber = Integer.parseInt(asInput[0]);
        nWaterLength = Integer.parseInt(asInput[1]);

        // Read the second line of input containing the coming seconds of humans
        sLongInputLine = sc.nextLine();
        asLongInputLine = sLongInputLine.split(" ");

        // Initialize the start time for water coverage
        nStart = Integer.parseInt(asLongInputLine[0]);

        // Main loop to calculate the total water life duration
        while (nNextHumanIndex < nHumanNumber) {
            if (nNextHumanIndex == nHumanNumber) {
                break; // Exit if all humans have been processed
            } else {
                nStop = nStart + nWaterLength; // Calculate stop time based on water length
                if (Integer.parseInt(asLongInputLine[nNextHumanIndex]) < nStop) {
                    // Process humans that arrive before the current stop time
                    while (nNextHumanIndex < nHumanNumber && Integer.parseInt(asLongInputLine[nNextHumanIndex]) < nStop) {
                        if (nStop <= Integer.parseInt(asLongInputLine[nNextHumanIndex]) + nWaterLength) {
                            nStop = Integer.parseInt(asLongInputLine[nNextHumanIndex]) + nWaterLength; // Extend stop time if necessary
                            nNextHumanIndex++; // Move to the next human
                        }
                    }
                    if (nNextHumanIndex == nHumanNumber) {
                        nWaterLife = nWaterLife + (nStop - nStart); // Add to water life if all humans are processed
                        break;
                    }
                }
                nWaterLife = nWaterLife + (nStop - nStart); // Add the duration of water coverage
                nStart = nStop; // Update start time for the next iteration
                if (nStart < Integer.parseInt(asLongInputLine[nNextHumanIndex])) {
                    nStart = Integer.parseInt(asLongInputLine[nNextHumanIndex]); // Adjust start time if necessary
                }
            }
        }

        // Output the total water life duration
        System.out.println(nWaterLife);
    }
}

// 