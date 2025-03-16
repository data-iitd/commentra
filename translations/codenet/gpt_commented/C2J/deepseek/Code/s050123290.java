public class SumOfDigits {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        while (true) {
            String input = scanner.nextLine();
            if (input.equals("0")) break;
            int sum = 0;
            for (int i = 0; i < input.length(); i++) {
                sum += input.charAt(i) - '0';
            }
            System.out.println(sum);
        }
        scanner.close();
    }
}
