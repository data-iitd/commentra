public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int N = scanner.nextInt();
        int L = scanner.nextInt();
        String[] S = new String[N];
        for (int i = 0; i < N; i++) {
            S[i] = scanner.next();
        }
        java.util.Arrays.sort(S);
        for (int i = 0; i < N; i++) {
            System.out.print(S[i]);
        }
        System.out.println();
    }
}
