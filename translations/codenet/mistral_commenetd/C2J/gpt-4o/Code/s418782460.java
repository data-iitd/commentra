import java.util.Scanner;

public class WaterWave {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the first line of input
        String firstLine = scanner.nextLine();
        String[] firstTokens = firstLine.split(" ");
        int nHumanNumber = Integer.parseInt(firstTokens[0]); // Number of humans
        int nWaterLength = Integer.parseInt(firstTokens[1]); // Length of the water wave

        // Initialize an array to store the arrival time of humans
        int[] anComingSec = new int[nHumanNumber];

        // Read the second line of input
        String secondLine = scanner.nextLine();
        String[] secondTokens = secondLine.split(" ");
        for (int i = 0; i < nHumanNumber; i++) {
            anComingSec[i] = Integer.parseInt(secondTokens[i]); // Store arrival times
        }

        // Initialize variables for water wave calculation
        int nWaterLife = 0; // Life of the water wave
        int nStart = anComingSec[0]; // Start time of the water wave
        int nNextHumanIndex = 0; // Index of the next human

        // Calculate the life of the water wave
        while (nNextHumanIndex < nHumanNumber) {
            int nStop = nStart + nWaterLength; // Calculate stop time of the water wave

            // Check if the next human arrives before the stop time of the water wave
            if (anComingSec[nNextHumanIndex] < nStop) {
                // Find the maximum stop time that includes both the current and next human
                while (nNextHumanIndex < nHumanNumber && anComingSec[nNextHumanIndex] < nStop) {
                    if (nStop <= anComingSec[nNextHumanIndex] + nWaterLength) {
                        nStop = anComingSec[nNextHumanIndex] + nWaterLength; // Update stop time
                    }
                    nNextHumanIndex++; // Move to the next human
                }
                // Calculate the life of the water wave
                nWaterLife += (nStop - nStart);
            }

            // Update the start time to the arrival time of the next human
            if (nNextHumanIndex < nHumanNumber) {
                nStart = Math.max(nStop, anComingSec[nNextHumanIndex]);
            }
        }

        // Print the life of the water wave
        System.out.println(nWaterLife);

        scanner.close();
    }
}

// <END-OF-CODE>
