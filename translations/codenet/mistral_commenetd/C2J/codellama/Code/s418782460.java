
import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String sInput = sc.nextLine();
        String[] sInputArray = sInput.split(" ");
        int nHumanNumber = Integer.parseInt(sInputArray[0]);
        int nWaterLength = Integer.parseInt(sInputArray[1]);
        int[] anComingSec = new int[nHumanNumber];
        for (int i = 0; i < nHumanNumber; i++) {
            anComingSec[i] = sc.nextInt();
        }
        int nStart = anComingSec[0];
        int nStop = 0;
        int nWaterLife = 0;
        int nNextHumanIndex = 0;
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
                nStart = nStop;
                if (nStart < anComingSec[nNextHumanIndex]) {
                    nStart = anComingSec[nNextHumanIndex];
                }
            }
        }
        System.out.println(nWaterLife);
    }
}

