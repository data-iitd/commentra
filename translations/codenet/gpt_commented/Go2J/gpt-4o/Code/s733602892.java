import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements N and the threshold K
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        
        // Read the two arrays of integers As and Fs
        int[] As = readInts(scanner, N);
        int[] Fs = readInts(scanner, N);
        
        // Sort the As array in ascending order
        Arrays.sort(As);
        // Sort the Fs array in descending order
        Arrays.sort(Fs);
        reverse(Fs);
        
        // Create an array to hold the scores calculated from As and Fs
        int[] scores = new int[N];
        for (int i = 0; i < N; i++) {
            // Calculate the score for each pair of As and Fs
            scores[i] = As[i] * Fs[i];
        }
        
        // Sort the scores in descending order
        Arrays.sort(scores);
        reverse(scores);
        
        // Initialize binary search boundaries
        int ok = scores[0]; // The maximum possible score
        int ng = -1;        // The minimum possible score

        // Perform binary search to find the maximum score that can be achieved
        while (ok - ng > 1) {
            int mid = (ok + ng) / 2; // Calculate the midpoint of the current range

            boolean isOK = true; // Flag to check if the current mid is achievable
            int k = K;           // Remaining threshold to adjust scores
            for (int i = 0; isOK && i < N; i++) {
                // If the current score exceeds mid, calculate how much we need to reduce
                if (As[i] * Fs[i] > mid) {
                    k -= As[i] - mid / Fs[i];
                }
                // If we exceed the allowed threshold, mark isOK as false
                if (k < 0) {
                    isOK = false;
                }
            }

            // Adjust binary search boundaries based on whether mid is achievable
            if (isOK) {
                ok = mid; // If achievable, move the upper boundary
            } else {
                ng = mid; // If not achievable, move the lower boundary
            }
        }

        // Print the maximum achievable score
        System.out.println(ok);
    }

    // Read an array of integers from input
    private static int[] readInts(Scanner scanner, int n) {
        int[] ret = new int[n];
        for (int i = 0; i < n; i++) {
            ret[i] = scanner.nextInt(); // Read each integer and store it in the array
        }
        return ret;
    }

    // Reverse an array
    private static void reverse(int[] array) {
        int left = 0;
        int right = array.length - 1;
        while (left < right) {
            int temp = array[left];
            array[left] = array[right];
            array[right] = temp;
            left++;
            right--;
        }
    }
}

// <END-OF-CODE>
