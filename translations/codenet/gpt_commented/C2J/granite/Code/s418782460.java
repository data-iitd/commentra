
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class s418782460{
    public static void main(String[] args) throws IOException {
        // Local variables
        String sInput = ""; // Buffer for the first line of input
        String sLongInputLine = ""; // Buffer for long input line
        String[] asComingSec = new String[200000]; // Array to store the coming seconds of humans
        int nHumanNumber = 0; // Number of humans
        int nNextHumanIndex = 0; // Index for the next human
        int nWaterLength = 0; // Length of water coverage
        int nWaterLife = 0; // Total water life duration
        int nStart = 0; // Start time for water coverage
        int nStop = 0; // Stop time for water coverage

        // Read the first line of input containing number of humans and water length
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        sInput = br.readLine();
        StringTokenizer st = new StringTokenizer(sInput);
        nHumanNumber = Integer.parseInt(st.nextToken()); // Convert first token to number of humans
        nWaterLength = Integer.parseInt(st.nextToken()); // Convert to water length

        // Read the second line of input containing the coming seconds of humans
        sLongInputLine = br.readLine();
        st = new StringTokenizer(sLongInputLine);
        for (int i = 0; i < nHumanNumber; i++) {
            asComingSec[i] = st.nextToken(); // Store each coming second in the array
        }

        // Initialize the start time for water coverage
        nStart = Integer.parseInt(asComingSec[0]);

        // s418782460 loop to calculate the total water life duration
        while (nNextHumanIndex < nHumanNumber) {
            if (nNextHumanIndex == nHumanNumber) {
                break; // Exit if all humans have been processed
            } else {
                nStop = nStart + nWaterLength; // Calculate stop time based on water length
                if (Integer.parseInt(asComingSec[nNextHumanIndex]) < nStop) {
                    // Process humans that arrive before the current stop time
                    while (nNextHumanIndex < nHumanNumber && Integer.parseInt(asComingSec[nNextHumanIndex]) < nStop) {
                        if (nStop <= Integer.parseInt(asComingSec[nNextHumanIndex]) + nWaterLength) {
                            nStop = Integer.parseInt(asComingSec[nNextHumanIndex]) + nWaterLength; // Extend stop time if necessary
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
                if (nStart < Integer.parseInt(asComingSec[nNextHumanIndex])) {
                    nStart = Integer.parseInt(asComingSec[nNextHumanIndex]); // Adjust start time if necessary
                }
            }
        }

        // Output the total water life duration
        System.out.println(nWaterLife);

        // End of the program
        System.out.println("