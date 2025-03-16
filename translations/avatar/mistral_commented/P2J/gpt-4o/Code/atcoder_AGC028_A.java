import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Define input variables N and M as integers
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character

        // Comments: Get the dimensions N and M of the matrices S and T from user input

        // Initialize variables S and T as strings
        String S = scanner.nextLine();
        String T = scanner.nextLine();

        // Convert strings S and T into character arrays
        char[] list_S = S.toCharArray();
        char[] list_T = T.toCharArray();

        // Initialize a list Number_i containing numbers from 0 to N-1
        List<Integer> Number_i = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            Number_i.add(i);
        }

        // Initialize an empty list Number_iMN to store the results of the division i*M/N
        List<Integer> Number_iMN = new ArrayList<>();

        // Iterate through each number i in the list Number_i
        for (int i : Number_i) {
            // Append the result of the division i*M/N to the list Number_iMN
            Number_iMN.add((int) (i * M / N));
        }

        // Initialize a list Number_j containing numbers from 0 to M-1
        List<Integer> Number_j = new ArrayList<>();
        for (int j = 0; j < M; j++) {
            Number_j.add(j);
        }

        // Find the common elements between Number_iMN and Number_j using set intersection
        Set<Integer> set_iMN = new HashSet<>(Number_iMN);
        Set<Integer> set_j = new HashSet<>(Number_j);
        set_iMN.retainAll(set_j);
        List<Integer> Kaburi_j = new ArrayList<>(set_iMN);

        // Initialize an empty list Kaburi_i to store the integer representations of the common elements
        List<Integer> Kaburi_i = new ArrayList<>();

        // Iterate through each common element j in Kaburi_j
        for (int j : Kaburi_j) {
            // Append the integer representation of j to the list Kaburi_i
            Kaburi_i.add((int) (j * N / M));
        }

        // Initialize a counter variable to keep track of the current index in Kaburi_i
        int counter = 0;

        // Initialize a flag variable to indicate whether there is a mismatch between S and T
        int Flag = 0;

        // Determine the size of Kaburi_i
        int Kaburi_Size = Kaburi_i.size();

        // Iterate through each index in Kaburi_i until the end of the list
        while (counter < Kaburi_Size) {
            // Check if the corresponding elements in S and T match
            if (list_S[Kaburi_i.get(counter)] != list_T[Kaburi_j.get(counter)]) {
                // Set the flag variable to 1 if there is a mismatch
                Flag = 1;
                // Break out of the loop
                break;
            }
            // Increment the counter variable
            counter++;
        }

        // Define a function gcd(a, b) to calculate the greatest common divisor of two integers
        System.out.println(Flag == 1 ? -1 : (N * M) / gcd(N, M));
    }

    // Function to calculate the greatest common divisor
    public static int gcd(int a, int b) {
        while (b > 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
}
// <END-OF-CODE>
