public class Main {
    public static void main(String[] args) {
        B();
    }

    public static void B() {
        long x, sum;
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        x = scanner.nextLong();
        int i = 0;
        sum = 100;
        while (sum < x) {
            sum += sum / 100;
            i++;
        }
        System.out.println(i);
    }
}
