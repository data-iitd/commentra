public class Main {
    public static void main(String[] args) {
        // Read the number of strings (N) and the length of each string (L)
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int L = scanner.nextInt();

        // Declare an array to hold the strings
        String[] S = new String[N];

        // Input the strings from the user
        for (int i = 0; i < N; i++) {
            S[i] = scanner.next();
        }

        // Sort the array of strings in lexicographical order
        Arrays.sort(S);

        // Output the sorted strings
        for (int i = 0; i < N; i++) {
            System.out.print(S[i]);
        }

        // Print a newline at the end of the output
        System.out.println();
    }
}
