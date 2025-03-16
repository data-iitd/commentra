
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class s418782460{

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        StringTokenizer st = new StringTokenizer(line);
        int nHumanNumber = Integer.parseInt(st.nextToken());
        int nWaterLength = Integer.parseInt(st.nextToken());

        int[] anComingSec = new int[nHumanNumber];
        line = br.readLine();
        st = new StringTokenizer(line);
        for (int i = 0; i < nHumanNumber; i++) {
            anComingSec[i] = Integer.parseInt(st.nextToken());
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
        }
        System.out.println(nWaterLife);
    }
}
