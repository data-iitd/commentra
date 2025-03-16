public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int N = scanner.nextInt();
        java.util.List<Integer> X = new java.util.ArrayList<>();
        java.util.List<Integer> Y = new java.util.ArrayList<>();

        for (int i = 0; i < N; i++) {
            int value = scanner.nextInt();
            X.add(value);
            Y.add(value);
        }

        java.util.Collections.sort(Y);

        int y = Y.get(N / 2);

        for (int i = 0; i < N; i++) {
            if (X.get(i) < y) {
                System.out.println(y);
            } else {
                System.out.println(y - 1);
            }
        }
    }
}
