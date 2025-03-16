public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();

        java.util.List<Integer> v = new java.util.ArrayList<>();
        for (int i = 0; i < N; ++i)
            v.add(scanner.nextInt());

        // ceil((N-1) / (K-1))
        int count = ((N - 1) + ((K - 1) - 1)) / (K - 1);
        System.out.println(count);
    }
}
