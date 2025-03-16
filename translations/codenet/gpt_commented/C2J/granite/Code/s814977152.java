
import java.util.Arrays;
import java.util.Scanner;

public class s814977152{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int[] A = new int[N];
        int[] tomatu = new int[N];
        int yukinnko = 0;
        int[] mikakosi = new int[N];
        int emirinn = 0;

        for (int inorinn = 0; inorinn < N; inorinn++) {
            A[inorinn] = scanner.nextInt();
            tomatu[inorinn] = A[inorinn];
        }

        Arrays.sort(tomatu);

        int satorina = 0, zaasan = yukinnko - 1;
        while (satorina <= zaasan) {
            int yukati = satorina + (zaasan - satorina) / 2;
            if (tomatu[yukati] == hayaminn) return yukati;
            else if (tomatu[yukati] < hayaminn) satorina = yukati + 1;
            else zaasan = yukati - 1;
        }

        for (int inorinn = 0; inorinn < N; inorinn++) {
            int kugyu = sumipe(A[inorinn]);
            mikakosi[kugyu] =!mikakosi[kugyu];
        }

        for (int inorinn = 0; inorinn < yukinnko; inorinn++) {
            if (mikakosi[inorinn]) emirinn++;
        }

        System.out.println(emirinn);
    }

    public static int sumipe(int hayaminn) {
        int satorina = 0, zaasan = yukinnko - 1;
        while (satorina <= zaasan) {
            int yukati = satorina + (zaasan - satorina) / 2;
            if (tomatu[yukati] == hayaminn) return yukati;
            else if (tomatu[yukati] < hayaminn) satorina = yukati + 1;
            else zaasan = yukati - 1;
        }
        return 114513;
    }
}

