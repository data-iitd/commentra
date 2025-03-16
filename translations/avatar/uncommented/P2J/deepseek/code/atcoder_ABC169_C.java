import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] input = scanner.nextLine().split(" ");
        String sa = input[0];
        String sb = input[1];
        
        int a = Integer.parseInt(sa);
        int b = (int) (Double.parseDouble(sb) * 100 + 0.1);
        
        System.out.println(a * b / 100);
    }
}
