public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int N = scanner.nextInt();
        int D = scanner.nextInt();
        int X = scanner.nextInt();
        int[] A = new int[101];
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextInt();
        }
        int num_of_chocolate = 0;
        for (int i = 0; i < N; i++) {
            int days = 0;
            int counter = 0;
            for (int j = 0; ; j++) {
                days = j * A[i] + 1;
                if (days <= D) {
                    counter++;
                } else {
                    break;
                }
            }
            num_of_chocolate += counter;
        }
        num_of_chocolate += X;
        System.out.println(num_of_chocolate);
    }
}
