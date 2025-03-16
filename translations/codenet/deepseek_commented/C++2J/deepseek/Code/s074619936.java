public class SumOfDigits {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        while (true) {
            String str = scanner.nextLine();
            if (str.equals("0")) break;
            int sum = 0;
            for (int i = 0; i < str.length(); i++) {
                char c = str.charAt(i);
                int num = Character.getNumericValue(c);
                sum += num;
            }
            System.out.println(sum);
        }
    }
}
