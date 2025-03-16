public class Main {
    public static void main(String[] args) {
        int n = scanner.nextInt();
        int sum = 0;
        int m = n;
        for (int i = 0; i < 9; i++) {
            sum += n % 10;
            n /= 10;
        }
        if (m % sum == 0) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}
