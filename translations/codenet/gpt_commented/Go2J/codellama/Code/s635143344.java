
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] in = new int[3];
        for (int i = 0; i < in.length; i++) {
            in[i] = sc.nextInt();
        }
        Arrays.sort(in);
        int result = in[2] * 10 + in[1] + in[0];
        System.out.println(result);
    }
}

