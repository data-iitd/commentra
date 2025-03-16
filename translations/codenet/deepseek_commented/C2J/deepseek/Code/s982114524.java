public class SumOfNumbers {
    public static void main(String[] args) {
        int i, N, x;
        x = 0;
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        N = scanner.nextInt();
        for(i = 1; i <= N; i++) {
            x += i;
        }
        System.out.println(x);
    }
}
