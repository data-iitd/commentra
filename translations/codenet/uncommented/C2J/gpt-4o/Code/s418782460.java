import java.util.Scanner;

public class WaterLifeCalculator {
    private static final int MAX_STRING = 30;
    private static final int MAX_LINE = 2000000;
    private static final int MAX_HUMAN = 200000;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String sInput = scanner.nextLine();
        String[] firstLine = sInput.split(" ");
        int nHumanNumber = Integer.parseInt(firstLine[0]);
        int nWaterLength = Integer.parseInt(firstLine[1]);

        String sLongInputLine = scanner.nextLine();
        String[] comingSecStrings = sLongInputLine.split(" ");
        int[] anComingSec = new int[nHumanNumber];

        for (int i = 0; i < nHumanNumber; i++) {
            anComingSec[i] = Integer.parseInt(comingSecStrings[i]);
        }

        int nStart = anComingSec[0];
        int nNextHumanIndex = 0;
        int nWaterLife = 0;

        while (nNextHumanIndex < nHumanNumber) {
            int nStop = nStart + nWaterLength;

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
        System.out.println(nWaterLife);
        scanner.close();
    }
}

// <END-OF-CODE>
