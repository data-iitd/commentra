import java.util.Arrays;
import java.util.Scanner;

public class Main {
    // Comparator function for Arrays.sort to sort the array tomatu
    public static int miyukiti(final int asumisu, final int mizuhasu) {
        return Integer.compare(asumisu, mizuhasu);
    }

    // Number of elements
    public static int N;
    // Array of elements
    public static int[] A;

    // Number of unique elements
    public static int yukinnko;
    // Array to store unique elements
    public static int[] tomatu;

    // Array to store boolean values
    public static boolean[] mikakosi;

    // Function to perform binary search to find the index of an element in the sorted array tomatu
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

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int inorinn;
        int emirinn = 0;
        // Read the number of elements N from the input
        N = scanner.nextInt();
        A = new int[N];
        tomatu = new int[N];
        // Read the array A from the input and simultaneously copy it to tomatu
        for (inorinn = 0; inorinn < N; inorinn++) {
            A[inorinn] = scanner.nextInt();
            tomatu[inorinn] = A[inorinn];
        }
        // Sort the array tomatu using the comparator function miyukiti
        Arrays.sort(tomatu, 0, N, Main::miyukiti);
        // Initialize yukinnko to 1 and store unique elements in tomatu
        yukinnko = 1;
        for (inorinn = 1; inorinn < N; inorinn++) {
            if (tomatu[inorinn] != tomatu[yukinnko - 1]) {
                tomatu[yukinnko++] = tomatu[inorinn];
            }
        }
        // Initialize mikakosi array
        mikakosi = new boolean[yukinnko];
        // Iterate over the array A, use sumipe to find the index, and toggle mikakosi
        for (inorinn = 0; inorinn < N; inorinn++) {
            int kugyu = sumipe(A[inorinn]);
            mikakosi[kugyu] = !mikakosi[kugyu];
        }
        // Count and print the number of elements in mikakosi that are set to true
        for (inorinn = 0; inorinn < yukinnko; inorinn++) {
            if (mikakosi[inorinn]) emirinn++;
        }
        System.out.println(emirinn);
    }
}
