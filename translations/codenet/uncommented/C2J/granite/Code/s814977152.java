
import java.util.Arrays;
import java.util.Scanner;

public class s814977152{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextInt();
        }
        int[] tomatu = Arrays.copyOf(A, N);
        Arrays.sort(tomatu);
        int yukinnko = 1;
        for (int i = 1; i < N; i++) {
            if (tomatu[i]!= tomatu[yukinnko - 1]) {
                tomatu[yukinnko++] = tomatu[i];
            }
        }
        int[] mikakosi = new int[yukinnko];
        for (int i = 0; i < N; i++) {
            int hayaminn = A[i];
            int satorina = 0, zaasan = yukinnko - 1;
            while (satorina <= zaasan) {
                int yukati = satorina + (zaasan - satorina) / 2;
                if (tomatu[yukati] == hayaminn) {
                    mikakosi[yukati] = 1 - mikakosi[yukati];
                    break;
                } else if (tomatu[yukati] < hayaminn) {
                    satorina = yukati + 1;
                } else {
                    zaasan = yukati - 1;
                }
            }
        }
        int emirinn = 0;
        for (int i = 0; i < yukinnko; i++) {
            emirinn += mikakosi[i];
        }
        System.out.println(emirinn);
    }
}

