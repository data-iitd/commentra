public class SumOfDigits {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        while (true) {
            String x = scanner.next();
            if (x.charAt(0) == '0') {
                break;
            }
            int sum = 0;
            for (int i = 0; i < x.length(); i++) {
                sum += x.charAt(i) - '0';
            }
            System.out.println(sum);
        }
        scanner.close();
    }
}
