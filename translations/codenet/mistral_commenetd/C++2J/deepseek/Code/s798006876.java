import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        final int MAX_N = 1000; // maximum size of the array
        int[] data = new int[MAX_N]; // array to store input data

        while (scanner.hasNextInt()) {
            int m = scanner.nextInt(); // number of elements in the array
            int nmi = scanner.nextInt(); // index of the start of the subarray
            int nma = scanner.nextInt(); // index of the end of the subarray

            if (nmi == 0) break; // exit the loop if nmi is 0

            for (int i = 0; i < m; i++) {
                data[i] = scanner.nextInt(); // read input data into the array
            }

            int ma = 0; // initialize maximum difference to 0
            int ans = 0; // initialize answer to 0

            for (int i = nmi - 1; i < nma; i++) { // iterate through the subarray
                if (ma <= data[i] - data[i + 1]) { // if current difference is greater than the previous maximum difference
                    ans = i + 1; // update answer with the index of the current element
                    ma = data[i] - data[i + 1]; // update maximum difference with the current difference
                }
            }

            System.out.println(ans); // print the answer
        }

        scanner.close();
    }
}
