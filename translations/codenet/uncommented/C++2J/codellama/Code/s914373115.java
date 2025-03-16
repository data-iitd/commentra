import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long x = sc.nextLong();
        int i = 0;
        long sum = 100;
        while (sum < x) {
            sum += sum / 100;
            i++;
        }
        System.out.println(i);
    }
}

