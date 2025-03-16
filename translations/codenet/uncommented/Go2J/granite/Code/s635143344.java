
import java.util.Arrays;
import java.util.Scanner;

public class s635143344{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] in = new int[3];
        for (int i = 0; i < 3; i++) {
            in[i] = scanner.nextInt();
        }
        Arrays.sort(in);

        System.out.println(in[2] * 10 + in[1] + in[0]);
    }
}
// 