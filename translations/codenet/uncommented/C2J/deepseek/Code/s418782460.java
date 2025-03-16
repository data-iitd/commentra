public class WaterLife {
    public static void main(String[] args) {
        // Read input
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String input = scanner.nextLine();
        String[] parts = input.split(" ");
        int nHumanNumber = Integer.parseInt(parts[0]);
        int nWaterLength = Integer.parseInt(parts[1]);

        String longInputLine = scanner.nextLine();
        String[] comingSecStr = longInputLine.split(" ");
        int[] anComingSec = new int[nHumanNumber];
        for (int i = 0; i < nHumanNumber; i++) {
            anComingSec[i] = Integer.parseInt(comingSecStr[i]);
        }

        int nStart = anComingSec[0];
        int nNextHumanIndex = 0;
        int nWaterLife = 0;

        while (nNextHumanIndex < nHumanNumber) {
            int nStop = nStart + nWaterLength;
            if (nNextHumanIndex < nHumanNumber && anComingSec[nNextHumanIndex] < nStop) {
                while (nNextHumanIndex < nHumanNumber && anComingSec[nNextHumanIndex] < nStop) {
                    if (nStop <= anComingSec[nNextHumanIndex] + nWaterLength) {
                        nStop = anComingSec[nNextHumanIndex] + nWaterLength;
                    }
                    nNextHumanIndex++;
                }
            }
            nWaterLife += (nStop - nStart);
            nStart = nStop;
            if (nStart < anComingSec[nNextHumanIndex]) {
                nStart = anComingSec[nNextHumanIndex];
            }
        }

        System.out.println(nWaterLife);
    }
}
