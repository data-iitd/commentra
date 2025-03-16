public class Main {
    public static void main(String[] args) {
        int num1, num2, ans, sum = 0;
        int[] math = new int[2001];
        java.util.Scanner scanner = new java.util.Scanner(System.in);

        num1 = scanner.nextInt();
        for (int i = 0; i < num1; i++) {
            int a = scanner.nextInt();
            sum += a;
            for (int j = sum - a; j >= 0; j--) {
                if (math[j] == 1) math[j + a] = 1;
            }
        }

        num2 = scanner.nextInt();
        for (int i = 0; i < num2; i++) {
            ans = scanner.nextInt();
            if (math[ans] == 1) {
                System.out.println("yes");
            } else {
                System.out.println("no");
            }
        }
    }
}
