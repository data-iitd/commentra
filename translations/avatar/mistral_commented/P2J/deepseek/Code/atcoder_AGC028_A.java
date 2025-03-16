import java.util.Scanner;
import java.util.ArrayList;
import java.util.HashSet;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Get the dimensions N and M of the matrices S and T from user input
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        
        // Initialize variables S and T as strings
        String S = scanner.next();
        String T = scanner.next();
        
        // Convert strings S and T into lists
        char[] list_S = S.toCharArray();
        char[] list_T = T.toCharArray();
        
        // Initialize a list Number_i containing numbers from 0 to N-1
        ArrayList<Integer> Number_i = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            Number_i.add(i);
        }
        
        // Initialize an empty list Number_iMN to store the results of the division i*M/N
        ArrayList<Integer> Number_iMN = new ArrayList<>();
        
        // Iterate through each number i in the list Number_i
        for (int i : Number_i) {
            // Append the result of the division i*M/N to the list Number_iMN
            Number_iMN.add(i * M / N);
        }
        
        // Initialize a list Number_j containing numbers from 0 to M-1
        ArrayList<Integer> Number_j = new ArrayList<>();
        for (int j = 0; j < M; j++) {
            Number_j.add(j);
        }
        
        // Find the common elements between Number_iMN and Number_j using set intersection
        HashSet<Integer> Kaburi_j = new HashSet<>(Number_iMN);
        Kaburi_j.retainAll(Number_j);
        
        // Initialize an empty list Kaburi_i to store the integer representations of the common elements
        ArrayList<Integer> Kaburi_i = new ArrayList<>();
        
        // Iterate through each common element j in Kaburi_j
        for (int j : Kaburi_j) {
            // Append the integer representation of j to the list Kaburi_i
            Kaburi_i.add(j * N / M);
        }
        
        // Initialize a counter variable to keep track of the current index in Kaburi_i
        int counter = 0;
        
        // Initialize a flag variable to indicate whether there is a mismatch between S and T
        int Flag = 0;
        
        // Determine the size of Kaburi_i
        int Kaburi_Size = Kaburi_i.size();
        
        // Iterate through each index in Kaburi_i until the end of the list
        while (counter <= Kaburi_Size - 1) {
            // Check if the corresponding elements in S and T match
            if (list_S[Kaburi_i.get(counter)] != list_T[Kaburi_j.iterator().next()]) {
                // Set the flag variable to 1 if there is a mismatch
                Flag = 1;
                // Break out of the loop
                break;
            }
            // Increment the counter variable
            counter++;
        }
        
        // Define a function gcd(a, b) to calculate the greatest common divisor of two integers
        public static int gcd(int a, int b) {
            // While b is not equal to 0, keep updating a and b using the modulo operator
            while (b != 0) {
                int temp = b;
                b = a % b;
                a = temp;
            }
            // Return the final value of a as the greatest common divisor
            return a;
        }
        
        // Check if there is a mismatch between S and T
        if (Flag == 1) {
            // Print -1 if there is a mismatch
            System.out.println(-1);
        } else {
            // Calculate and print the product of N and M divided by their greatest common divisor
            System.out.println(N * M / gcd(N, M));
        }
    }
}
