import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the values of N and M
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        scanner.nextLine(); // Consume the newline
        
        // Read the string S
        String S = scanner.nextLine();
        // Read the string T
        String T = scanner.nextLine();
        
        // Convert string S and T to character arrays
        char[] list_S = S.toCharArray();
        char[] list_T = T.toCharArray();
        
        // Create a list of indices from 0 to N-1
        List<Integer> Number_i = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            Number_i.add(i);
        }
        
        // Calculate a new list where each element is i * M / N
        List<Double> Number_iMN = new ArrayList<>();
        for (int i : Number_i) {
            Number_iMN.add(i * (double) M / N);
        }
        
        // Create a list of indices from 0 to M-1
        List<Integer> Number_j = new ArrayList<>();
        for (int j = 0; j < M; j++) {
            Number_j.add(j);
        }
        
        // Find the intersection of Number_iMN and Number_j
        Set<Double> set_iMN = new HashSet<>(Number_iMN);
        Set<Integer> set_j = new HashSet<>(Number_j);
        set_iMN.retainAll(set_j);
        
        // Calculate Kaburi_i
        List<Integer> Kaburi_i = new ArrayList<>();
        for (Double j : set_iMN) {
            Kaburi_i.add((int) (j * N / M));
        }
        
        // Initialize counter and flag
        int counter = 0;
        int Flag = 0;
        int Kaburi_Size = Kaburi_i.size();
        
        // Iterate through Kaburi_i to check if corresponding characters in list_S and list_T are the same
        while (counter < Kaburi_Size) {
            if (list_S[Kaburi_i.get(counter)] != list_T[Number_j.get(counter)]) {
                Flag = 1;
                break;
            }
            counter++;
        }
        
        // Define a function to calculate the greatest common divisor (GCD) of two numbers
        int gcd = gcd(N, M);
        
        // If the flag is 1, print -1. Otherwise, print the result of N*M divided by the GCD of N and M.
        if (Flag == 1) {
            System.out.println(-1);
        } else {
            System.out.println((N * M) / gcd);
        }
        
        scanner.close();
    }
    
    // GCD function
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
