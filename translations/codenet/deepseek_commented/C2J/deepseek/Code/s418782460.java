public class WaterLifeCalculator {
    public static void main(String[] args) {
        // Define constants for maximum sizes
        final int MAX_STRING = 30;
        final int MAX_LINE = 2000000;
        final int MAX_HUMAN = 200000;

        // Declare global arrays and variables
        char[] sLongInputLine = new char[MAX_LINE + 1];
        int[] anComingSec = new int[MAX_HUMAN];

        // Declare variables for input and processing
        char[] sInput = new char[MAX_STRING + 1];
        String psWord = null;
        String psInput = null;

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
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String inputLine = scanner.nextLine();
        String[] parts = inputLine.split(" ");
        nHumanNumber = Integer.parseInt(parts[0]);
        nWaterLength = Integer.parseInt(parts[1]);

        // Read the second line of input which contains the seconds when each human arrives
        inputLine = scanner.nextLine();
        parts = inputLine.split(" ");
        for (i = 0; i < nHumanNumber; i++) {
            anComingSec[i] = Integer.parseInt(parts[i]);
        }

        // Initialize the start time to the first human's arrival time
        nStart = anComingSec[0];

        // Process the data to calculate the water life
        while (nNextHumanIndex < nHumanNumber) {
            nStop = nStart + nWaterLength;
            if (anComingSec[nNextHumanIndex] < nStop) {
                while (nNextHumanIndex < nHumanNumber && anComingSec[nNextHumanIndex] < nStop) {
                    if (nStop <= anComingSec[nNextHumanIndex] + nWaterLength) {
                        nStop = anComingSec[nNextHumanIndex] + nWaterLength;
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
            if (nStart < anComingSec[nNextHumanIndex]) {
                nStart = anComingSec[nNextHumanIndex];
            }
        }

        // Output the result which is the total water life
        System.out.println(nWaterLife);
    }
}
