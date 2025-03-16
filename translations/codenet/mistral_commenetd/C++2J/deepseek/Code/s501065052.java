import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt(); // Read the number of elements in the memory array from the standard input

        int[] mem = new int[N + 1]; // Allocate memory for an integer array of size N+1 to store the memory locations of each process

        for (int i = 1; i <= N; ++i) { // Read the memory locations of each process and store them in the mem array
            int P = scanner.nextInt();
            mem[P] = i;
        }

        int maxcnt = 1; // Initialize maxcnt to 1, which will store the maximum length of a consecutive increasing sequence of memory locations
        int cnt = 1; // Initialize cnt to 1, which will store the current length of such a sequence

        for (int i = 1; i < N; ++i) { // Traverse the mem array and update maxcnt and cnt variables accordingly
            if (mem[i] < mem[i + 1]) {
                cnt++;
            } else {
                maxcnt = Math.max(maxcnt, cnt);
                cnt = 1;
            }
        }

        // Update maxcnt with the length of the last consecutive increasing sequence
        maxcnt = Math.max(maxcnt, cnt);

        System.out.println(N - maxcnt); // Print the result N - maxcnt to the standard output
    }
}

