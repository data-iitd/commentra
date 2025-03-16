
import java.util.Scanner;

public class s493522692{

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // 'S'がN個、'c'がM個
        int N = sc.nextInt();
        int M = sc.nextInt();
        int tmp = Math.min(N, M / 2);
        int ans = tmp;
        N -= tmp;
        M -= tmp * 2;
        //fmt.Println(ans, N, M);
        System.out.println(ans + M / 4);
    }
}

