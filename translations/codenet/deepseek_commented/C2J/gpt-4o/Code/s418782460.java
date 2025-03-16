import java.util.Scanner;

public class WaterLifeCalculator {
    // Define constants for maximum sizes
    private static final int MAX_STRING = 30;
    private static final int MAX_LINE = 2000000;
    private static final int MAX_HUMAN = 200000;

    public static void main(String[] args) {
        // Declare variables for input and processing
        Scanner scanner = new Scanner(System.in);
        String sInput;
        int[] anComingSec = new int[MAX_HUMAN];

        int nHumanNumber = 0;
        int nNextHumanIndex = 0;
        int nWaterLength = 0;
        int nWaterLife = 0;
        int nStart = 0;
        int nStop = 0;

        // Read the first line of input which contains the number of humans and the water length
        sInput = scanner.nextLine();
        String[] firstLineParts = sInput.split(" ");
        nHumanNumber = Integer.parseInt(firstLineParts[0]);
        nWaterLength = Integer.parseInt(firstLineParts[1]);

        // Read the second line of input which contains the seconds when each human arrives
        sInput = scanner.nextLine();
        String[] arrivalTimes = sInput.split(" ");
        for (int i = 0; i < nHumanNumber; i++) {
            anComingSec[i] = Integer.parseInt(arrivalTimes[i]);
        }

        // Initialize the start time to the first human's arrival time
        nStart = anComingSec[0];

        // Process the data to calculate the water life
        while (nNextHumanIndex < nHumanNumber) {
            if (nNextHumanIndex == nHumanNumber) {
                break;
            } else {
                nStop = nStart + nWaterLength;
                if (anComingSec[nNextHumanIndex] < nStop) {
                    while (nNextHumanIndex < nHumanNumber && anComingSec[nNextHumanIndex] < nStop) {
                        if (nStop <= anComingSec[nNextHumanIndex] + nWaterLength) {
                            nStop = anComingSec[nNextHumanIndex] + nWaterLength;
                            nNextHumanIndex++;
                        }
                    }
                    if (nNextHumanIndex == nHumanNumber) {
                        nWaterLife += (nStop - nStart);
                        break;
                    }
                }
                nWaterLife += (nStop - nStart);
                nStart = nStop;
                if (nStart < anComingSec[nNextHumanIndex]) {
                    nStart = anComingSec[nNextHumanIndex];
                }
            }
        }

        // Output the result which is the total water life
        System.out.println(nWaterLife);
        scanner.close();
    }
}

// <END-OF-CODE>
