public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int N = scanner.nextInt(); // 1. Reading the values of N and K from the standard input.
        int K = scanner.nextInt(); // 1. Reading the values of N and K from the standard input.

        java.util.List<Integer> v = new java.util.ArrayList<>(); // 2. Initializing a list to store N integers.
        for (int i = 0; i < N; ++i)
            v.add(scanner.nextInt()); // 3. Reading N integers from the standard input and storing them in the list v.

        // 4. Calculating the number of groups that can be formed using the formula ceil((N-1) / (K-1)).
        int count = ((N - 1) + ((K - 1) - 1)) / (K - 1);
        System.out.println(count); // 5. Outputting the calculated count.
    }
}
