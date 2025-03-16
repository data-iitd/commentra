import java.util.Scanner;

public class WaterWave {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        String[] parts = input.split(" ");
        int nHumanNumber = Integer.parseInt(parts[0]);
        int nWaterLength = Integer.parseInt(parts[1]);

        String longInputLine = scanner.nextLine();
        String[] arrivalTimes = longInputLine.split(" ");
        int[] anComingSec = new int[nHumanNumber];
        for (int i = 0; i < nHumanNumber; i++) {
            anComingSec[i] = Integer.parseInt(arrivalTimes[i]);
        }

        int nStart = anComingSec[0];
        int nWaterLife = 0;
        int nNextHumanIndex = 0;

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

            nStart = nStop;
            if (nStart < anComingSec[nNextHumanIndex]) {
                nStart = anComingSec[nNextHumanIndex];
            }
        }

        System.out.println(nWaterLife);
    }
}
