import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the integer n and the string s from the standard input
        int n = scanner.nextInt();
        String s = scanner.next();
        
        // Convert the characters in s to their corresponding integer values
        // 'R' -> 0, 'G' -> 1, 'B' -> 2
        int[] ns = new int[n];
        for (int i = 0; i < n; i++) {
            switch (s.charAt(i)) {
                case 'R':
                    ns[i] = 0;
                    break;
                case 'G':
                    ns[i] = 1;
                    break;
                case 'B':
                    ns[i] = 2;
                    break;
            }
        }
        
        // Construct a cumulative count array rgb to keep track of the counts of each color up to each position
        int[][] rgb = new int[n + 1][3];
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 3; j++) {
                rgb[i][j] = rgb[i - 1][j];
            }
            rgb[i][ns[i - 1]]++;
        }
        
        // Calculate the number of valid triplets (i, j, k) where ns[i] != ns[j] != ns[k] and ns[k] == tn
        // where tn is the third color different from ns[i] and ns[j]
        int sum = 0;
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                if (ns[i] != ns[j]) {
                    int tn = 3 - ns[i] - ns[j];
                    sum += rgb[n][tn] - rgb[j + 1][tn];
                    int k = 2 * j - i;
                    if (k < n && ns[k] == tn) {
                        sum--;
                    }
                }
            }
        }
        
        // Print the result
        System.out.println(sum);
        
        scanner.close();
    }
}

// <END-OF-CODE>
