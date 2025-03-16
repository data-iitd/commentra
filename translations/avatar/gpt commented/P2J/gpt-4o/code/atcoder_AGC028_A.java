import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the values of N and M from input
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        scanner.nextLine(); // Consume the newline
        
        // Read the strings S and T from input
        String S = scanner.nextLine();
        String T = scanner.nextLine();
        
        // Convert strings S and T into character arrays for easier indexing
        char[] list_S = S.toCharArray();
        char[] list_T = T.toCharArray();
        
        // Create a list of indices from 0 to N-1
        List<Integer> Number_i = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            Number_i.add(i);
        }
        
        // Initialize an empty list to store calculated indices
        List<Double> Number_iMN = new ArrayList<>();
        
        // Calculate the scaled indices based on the ratio of M to N
        for (int i : Number_i) {
            Number_iMN.add(i * (double) M / N);
        }
        
        // Create a list of indices from 0 to M-1
        List<Integer> Number_j = new ArrayList<>();
        for (int j = 0; j < M; j++) {
            Number_j.add(j);
        }
        
        // Find the common indices between the scaled Number_iMN and Number_j
        Set<Double> set_iMN = new HashSet<>(Number_iMN);
        Set<Integer> set_j = new HashSet<>(Number_j);
        set_iMN.retainAll(set_j);
        
        // Initialize an empty list to store the corresponding indices in the original range
        List<Integer> Kaburi_i = new ArrayList<>();
        
        // Calculate the corresponding indices in the original range based on Kaburi_j
        for (Double j : set_iMN) {
            Kaburi_i.add((int) (j * N / M));
        }
        
        // Initialize a counter for iteration and a flag for mismatch detection
        int counter = 0;
        int Flag = 0;
        
        // Get the size of the Kaburi_i list
        int Kaburi_Size = Kaburi_i.size();
        
        // Check if the characters at the calculated indices in S and T match
        while (counter < Kaburi_Size) {
            if (list_S[Kaburi_i.get(counter)] == list_T[counter]) {
                // Characters match, continue checking
            } else {
                Flag = 1; // Set flag if a mismatch is found
                break; // Exit the loop on mismatch
            }
            counter++; // Move to the next index
        }
        
        // Function to calculate the greatest common divisor (GCD) of two numbers
        int gcd = gcd(N, M);
        
        // Output the result based on the flag indicating if a mismatch was found
        if (Flag == 1) {
            System.out.println(-1); // Print -1 if there was a mismatch
        } else {
            // Print the least common multiple (LCM) of N and M
            System.out.println((N * M) / gcd);
        }
        
        scanner.close();
    }
    
    // Function to calculate the greatest common divisor (GCD) of two numbers
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
