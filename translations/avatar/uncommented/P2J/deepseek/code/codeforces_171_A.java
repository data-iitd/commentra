import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] input = scanner.nextLine().split(" ");
        String a = input[0];
        String b = input[1];
        
        int maxLength = Math.max(a.length(), b.length());
        a = String.format("%1$" + maxLength + "s", a).replace(' ', '0');
        b = String.format("%1$-" + maxLength + "s", b).replace(' ', '0');
        
        StringBuilder result = new StringBuilder();
        int carry = 0;
        
        for (int i = maxLength - 1; i >= 0; i--) {
            int sum = (a.charAt(i) - '0') + (b.charAt(i) - '0') + carry;
            if (sum > 9) {
                result.append(sum - 10);
                carry = 1;
            } else {
                result.append(sum);
                carry = 0;
            }
        }
        
        if (carry == 1) {
            result.append(1);
        }
        
        System.out.println(Integer.parseInt(result.reverse().toString()));
    }
}
