public class SortThreeNumbers {
    public static void main(String[] args) {
        int a, b, c;
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();

        if (a > b) {
            int temp = a;
            a = b;
            b = temp;
        }

        if (b > c) {
            int temp = b;
            b = c;
            c = temp;
        }

        if (a > b) {
            int temp = a;
            a = b;
            b = temp;
        }

        System.out.println(a + " " + b + " " + c);
    }
}
