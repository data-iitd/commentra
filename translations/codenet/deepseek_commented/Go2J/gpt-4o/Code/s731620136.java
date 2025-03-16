import java.util.Scanner;

public class Main {
    // The main function reads input, processes it, and prints the result.
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // Reads the number of elements N and the string S.
        int N = sc.nextInt();
        String S = sc.next();

        if (N < 4) {
            System.out.println(0);
            return;
        }

        // Counts the number of 'R', 'B', and 'G' characters in S.
        int nr = 0, nb = 0, ng = 0;
        for (char c : S.toCharArray()) {
            if (c == 'R') {
                nr++;
            } else if (c == 'B') {
                nb++;
            } else if (c == 'G') {
                ng++;
            }
        }

        // Calculates the number of triplets where the characters are all different.
        int same = 0;
        for (int a = 1; a < N; a++) {
            int i = 0;
            int j = 1 * a;
            int k = 2 * a;
            if (k >= N) {
                break;
            }
            while (k < N) {
                if (S.charAt(i) != S.charAt(j) && S.charAt(i) != S.charAt(k) && S.charAt(j) != S.charAt(k)) {
                    same++;
                }
                i++;
                j++;
                k++;
            }
        }

        // Calculates the total number of possible triplets.
        int tot = nr * nb * ng;

        // Prints the difference between the total number of possible triplets and the number of triplets with all different characters.
        System.out.println(tot - same);
    }
}
// <END-OF-CODE>
