public class SumOfNumbers {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        long n = scanner.nextLong();
        long b = (n * (n - 1)) / 2;
        System.out.println(b);
    }
}
