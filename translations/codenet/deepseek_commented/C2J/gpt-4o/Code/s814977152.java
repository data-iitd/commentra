import java.util.Arrays;
import java.util.Scanner;

public class Main {
    // Number of elements
    static int N;
    // Array of elements
    static int[] A = new int[114514];
    // Number of unique elements
    static int yukinnko;
    // Array to store unique elements
    static int[] tomatu = new int[114514];
    // Array to store boolean values
    static boolean[] mikakosi = new boolean[114514];

    // Function to perform binary search to find the index of an element in the sorted array tomatu
    static int sumipe(int hayaminn) {
        int satorina = 0, zaasan = yukinnko - 1;
        while (satorina <= zaasan) {
            int yukati = satorina + (zaasan - satorina) / 2;
            if (tomatu[yukati] == hayaminn) return yukati;
            else if (tomatu[yukati] < hayaminn) satorina = yukati + 1;
            else zaasan = yukati - 1;
        }
        return 114513; // Return a value indicating not found
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int emirinn = 0;

        // Read the number of elements N from the input
        N = scanner.nextInt();

        // Read the array A from the input and simultaneously copy it to tomatu
        for (int inorinn = 0; inorinn < N; inorinn++) {
            A[inorinn] = scanner.nextInt();
            tomatu[inorinn] = A[inorinn];
        }

        // Sort the array tomatu
        Arrays.sort(tomatu, 0, N);

        // Initialize yukinnko to 1 and store unique elements in tomatu
        yukinnko = 1;
        for (int inorinn = 1; inorinn < N; inorinn++) {
            if (tomatu[inorinn] != tomatu[yukinnko - 1]) {
                tomatu[yukinnko++] = tomatu[inorinn];
            }
        }

        // Iterate over the array A, use sumipe to find the index, and toggle mikakosi
        for (int inorinn = 0; inorinn < N; inorinn++) {
            int kugyu = sumipe(A[inorinn]);
            mikakosi[kugyu] = !mikakosi[kugyu];
        }

        // Count and print the number of elements in mikakosi that are set to true
        for (int inorinn = 0; inorinn < yukinnko; inorinn++) {
            if (mikakosi[inorinn]) emirinn++;
        }

        System.out.println(emirinn);
        scanner.close();
    }
}
// <END-OF-CODE>
