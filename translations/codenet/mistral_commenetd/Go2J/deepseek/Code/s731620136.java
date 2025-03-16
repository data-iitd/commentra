public class Main {
    public static void main(String[] args) {
        // Read input from standard input
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int N = scanner.nextInt();

        // Read the string S from standard input
        String S = scanner.next();

        // Initialize counters for red, blue, and green balls
        int nr = 0, nb = 0, ng = 0;

        // Count the number of red, blue, and green balls
        for (char c : S.toCharArray()) {
            if (c == 'R') nr++;
            else if (c == 'B') nb++;
            else if (c == 'G') ng++;
        }

        // Initialize a counter for the number of same-colored groups of three balls
        int same = 0;

        // Iterate through each index a from 1 to N-1
        for (int a = 1; a < N; a++) {
            int i = 0; // Initialize index i to 0
            int j = a; // Initialize index j to a
            int k = 2 * a; // Initialize index k to a multiplied by 2

            // Iterate through each index k from a*2 to N-1
            while (k < N) {
                // Check if the balls at indices i, j, and k have different colors
                if (S.charAt(i) != S.charAt(j) && S.charAt(i) != S.charAt(k) && S.charAt(j) != S.charAt(k)) {
                    same++; // If so, increment the same counter
                }

                // Update indices i, j, and k
                i++;
                j++;
                k++;
            }
        }

        // Calculate the total number of balls
        int tot = nr * nb * ng;

        // Print the result, which is the total number of balls minus the number of same-colored groups of three balls
        System.out.println(tot - same);
    }
}
