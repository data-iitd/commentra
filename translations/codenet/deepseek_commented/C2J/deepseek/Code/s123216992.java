public class SwapNumbers {
    public static void main(String[] args) {
        while (true) {
            java.util.Scanner scanner = new java.util.Scanner(System.in);
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            if (a == 0 && b == 0) break;
            if (b < a) {
                int temp = a;
                a = b;
                b = temp;
            }
            System.out.println(a + " " + b);
        }
    }
}
