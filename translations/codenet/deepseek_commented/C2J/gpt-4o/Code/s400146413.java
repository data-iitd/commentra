import java.util.Scanner;

public class LinearSearch {

    // Linear Search Function
    // Purpose: This function performs a linear search to find the key in the array S.
    // Parameters:
    //   - S: The array to be searched.
    //   - n: The size of the array S.
    //   - key: The value to be searched for.
    // Return Value: Returns 1 if the key is not found, otherwise returns 0.
    public static int linearSearch(int[] S, int n, int key) {
        int i = 0;
        while (i < n) {
            if (S[i] == key) {
                return 0; // Key found
            }
            i++;
        }
        return 1; // Key not found
    }

    // Main Function
    // Purpose: This function reads two arrays S and T, and counts the number of elements in T that are present in S using the linearSearch function.
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        int[] S = new int[n];
        for (int i = 0; i < n; i++) {
            S[i] = scanner.nextInt();
        }

        int q = scanner.nextInt();
        int[] T = new int[q];
        for (int j = 0; j < q; j++) {
            T[j] = scanner.nextInt();
        }

        int count = 0;
        for (int j = 0; j < q; j++) {
            int key = T[j];
            if (linearSearch(S, n, key) == 0) {
                count++;
            }
        }

        System.out.println(count);
        scanner.close();
    }
}

// <END-OF-CODE>
