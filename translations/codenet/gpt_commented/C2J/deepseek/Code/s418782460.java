public class WaterCoverage {
    public static void main(String[] args) {
        // Local variables
        String sInput = ""; // Buffer for the first line of input
        String[] psWord = null; // Array for tokenizing words
        String[] psInput = null; // Array for tokenizing input

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
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        sInput = scanner.nextLine();
        psInput = sInput.split(" "); // Tokenize the input
        nHumanNumber = Integer.parseInt(psInput[0]); // Convert first token to number of humans
        nWaterLength = Integer.parseInt(psInput[1]); // Convert to water length

        // Read the second line of input containing the coming seconds of humans
        sInput = scanner.nextLine();
        psInput = sInput.split(" "); // Tokenize the input
        int[] anComingSec = new int[nHumanNumber]; // Array to store the coming seconds of humans
        for (i = 0; i < nHumanNumber; i++) {
            anComingSec[i] = Integer.parseInt(psInput[i]); // Store each coming second in the array
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
                        nWaterLife = nWaterLife + (nStop - nStart); // Add to water life if all humans are processed
                        break;
                    }
                }
                nWaterLife = nWaterLife + (nStop - nStart); // Add the duration of water coverage
                nStart = nStop; // Update start time for the next iteration
                if (nStart < anComingSec[nNextHumanIndex]) {
                    nStart = anComingSec[nNextHumanIndex]; // Adjust start time if necessary
                }
            }
        }

        // Output the total water life duration
        System.out.println(nWaterLife);
    }
}
