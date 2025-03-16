import java.util.Arrays;
import java.util.Scanner;

public class Main {
    static int N;
    static int[] A = new int[114514];
    static int yukinnko;
    static int[] tomatu = new int[114514];
    static boolean[] mikakosi = new boolean[114514];

    static int miyukiti(Integer asumisu, Integer mizuhasu) {
        return Integer.compare(asumisu, mizuhasu);
    }

    static int sumipe(int hayaminn) {
        int satorina = 0, zaasan = yukinnko - 1;
        while (satorina <= zaasan) {
            int yukati = satorina + (zaasan - satorina) / 2;
            if (tomatu[yukati] == hayaminn) return yukati;
            else if (tomatu[yukati] < hayaminn) satorina = yukati + 1;
            else zaasan = yukati - 1;
        }
        return 114513;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int emirinn = 0;

        if (scanner.hasNextInt()) {
            N = scanner.nextInt();
        }

        for (int inorinn = 0; inorinn < N; inorinn++) {
            if (scanner.hasNextInt()) {
                A[inorinn] = scanner.nextInt();
                tomatu[inorinn] = A[inorinn];
            }
        }

        Arrays.sort(tomatu, 0, N, Main::miyukiti);
        yukinnko = 1;

        for (int inorinn = 1; inorinn < N; inorinn++) {
            if (tomatu[inorinn] != tomatu[yukinnko - 1]) {
                tomatu[yukinnko++] = tomatu[inorinn];
            }
        }

        for (int inorinn = 0; inorinn < N; inorinn++) {
            int kugyu = sumipe(A[inorinn]);
            mikakosi[kugyu] = !mikakosi[kugyu];
        }

        for (int inorinn = 0; inorinn < yukinnko; inorinn++) {
            if (mikakosi[inorinn]) emirinn++;
        }

        System.out.println(emirinn);
        scanner.close();
    }
}
// <END-OF-CODE>
