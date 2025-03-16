import java.util.Scanner;

public class WaterLifeDuration {
    private static final int MAX_STRING = 30;
    private static final int MAX_LINE = 2000000;
    private static final int MAX_HUMAN = 200000;

    public static void main(String[] args) {
        // Local variables
        Scanner scanner = new Scanner(System.in);
        String sInput; // Buffer for the first line of input
        int[] anComingSec = new int[MAX_HUMAN]; // Array to store the coming seconds of humans

        int nHumanNumber = 0; // Number of humans
        int nNextHumanIndex = 0; // Index for the next human
        int nWaterLength = 0; // Length of water coverage
        int nWaterLife = 0; // Total water life duration
        int nStart = 0; // Start time for water coverage
        int nStop = 0; // Stop time for water coverage

        // Read the first line of input containing number of humans and water length
        sInput = scanner.nextLine();
        String[] tokens = sInput.split(" ");
        nHumanNumber = Integer.parseInt(tokens[0]); // Convert first token to number of humans
        nWaterLength = Integer.parseInt(tokens[1]); // Convert to water length

        // Read the second line of input containing the coming seconds of humans
        sInput = scanner.nextLine();
        tokens = sInput.split(" ");
        for (int i = 0; i < nHumanNumber; i++) {
            anComingSec[i] = Integer.parseInt(tokens[i]); // Store each coming second in the array
        }

        // Initialize the start time for water coverage
        nStart = anComingSec[0];

        // Main loop to calculate the total water life duration
        while (nNextHumanIndex < nHumanNumber) {
            if (nNextHumanIndex == nHumanNumber) {
                break; // Exit if all humans have been processed
            } else {
                nStop = nStart + nWaterLength; // Calculate stop time based on water length
                if (anComingSec[nNextHumanIndex] < nStop) {
                    // Process humans that arrive before the current stop time
                    while (nNextHumanIndex < nHumanNumber && anComingSec[nNextHumanIndex] < nStop) {
                        if (nStop <= anComingSec[nNextHumanIndex] + nWaterLength) {
                            nStop = anComingSec[nNextHumanIndex] + nWaterLength; // Extend stop time if necessary
                            nNextHumanIndex++; // Move to the next human
                        }
                    }
                    if (nNextHumanIndex == nHumanNumber) {
                        nWaterLife += (nStop - nStart); // Add to water life if all humans are processed
                        break;
                    }
                }
                nWaterLife += (nStop - nStart); // Add the duration of water coverage
                nStart = nStop; // Update start time for the next iteration
                if (nStart < anComingSec[nNextHumanIndex]) {
                    nStart = anComingSec[nNextHumanIndex]; // Adjust start time if necessary
                }
            }
        }

        // Output the total water life duration
        System.out.println(nWaterLife);

        scanner.close(); // Close the scanner
    }
}
// <END-OF-CODE>
