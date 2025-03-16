
// <START-OF-CODE>

import java.util.*;

public class WaterLife {

    public static void main(String[] args) {

        // Declare variables for input and processing
        String sInput = "";
        String[] asInput = null;
        String sLongInputLine = "";
        String[] asLongInputLine = null;

        int nHumanNumber = 0;
        int nNextHumanIndex = 0;
        int nWaterLength = 0;
        int nWaterLife = 0;
        int nStart = 0;
        int nStop = 0;

        int nIndex = 0;
        int i = 0;
        int j = 0;

        // Read the first line of input which contains the number of humans and the water length
        sInput = readLine();
        asInput = sInput.split(" ");
        nHumanNumber = Integer.parseInt(asInput[0]);
        nWaterLength = Integer.parseInt(asInput[1]);

        // Read the second line of input which contains the seconds when each human arrives
        sLongInputLine = readLine();
        asLongInputLine = sLongInputLine.split(" ");

        // Initialize the start time to the first human's arrival time
        nStart = Integer.parseInt(asLongInputLine[0]);

        // Process the data to calculate the water life
        while (nNextHumanIndex < nHumanNumber) {
            if (nNextHumanIndex == nHumanNumber) {
                break;
            } else {
                nStop = nStart + nWaterLength;
                if (Integer.parseInt(asLongInputLine[nNextHumanIndex]) < nStop) {
                    while (nNextHumanIndex < nHumanNumber && Integer.parseInt(asLongInputLine[nNextHumanIndex]) < nStop) {
                        if (nStop <= Integer.parseInt(asLongInputLine[nNextHumanIndex]) + nWaterLength) {
                            nStop = Integer.parseInt(asLongInputLine[nNextHumanIndex]) + nWaterLength;
                            nNextHumanIndex++;
                        }
                    }
                    if (nNextHumanIndex == nHumanNumber) {
                        nWaterLife = nWaterLife + (nStop - nStart);
                        break;
                    }
                }
                nWaterLife = nWaterLife + (nStop - nStart);
                nStart = nStop;
                if (nStart < Integer.parseInt(asLongInputLine[nNextHumanIndex])) {
                    nStart = Integer.parseInt(asLongInputLine[nNextHumanIndex]);
                }
            }
        }

        // Output the result which is the total water life
        System.out.println(nWaterLife);

    }

    public static String readLine() {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            return br.readLine();
        } catch (IOException e) {
            return null;
        }
    }
}

// 