public class Main {
    public static void main(String[] args) {
        // Declare variables
        int n, l[] = new int[2001];
        int i, j, k, cnt = 0, tmp = 0;

        // Read the number of elements
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        n = scanner.nextInt();

        // Input the elements into the array
        for(i = 0; i < n; i++) {
            l[i] = scanner.nextInt();
        }

        // Sort the array using a simple bubble sort algorithm
        for(i = 0; i < n - 1; i++) {
            for(j = i + 1; j < n; j++) {
                // Swap elements if they are in the wrong order
                if(l[j] < l[i]) {
                    tmp = l[i];
                    l[i] = l[j];
                    l[j] = tmp;
                }
            }
        }

        // Count the number of valid triplets (i, j, k) such that l[i] + l[j] > l[k]
        for(i = 0; i < n - 2; i++) {
            for(j = i + 1; j < n - 1; j++) {
                for(k = j + 1; k < n; k++) {
                    // Check if the sum of two elements is greater than the third
                    if(l[i] + l[j] > l[k]) {
                        cnt++; // Increment count if the condition is satisfied
                    } else {
                        break; // Break if the condition is not satisfied (since array is sorted)
                    }
                }
            }
        }

        // Output the count of valid triplets
        System.out.println(cnt);
    }
}
