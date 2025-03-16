import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int A = sc.nextInt();
        int B = sc.nextInt();

        if ((A + B) % 2 == 0) {
            System.out.println((A + B) / 2);
            return;
        }
        System.out.println("IMPOSSIBLE");
    }
}
