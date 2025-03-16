
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        type arm struct{ l, r int }
        as := make([]arm, n)
        for i := range as {
            x, l := sc.nextInt(), sc.nextInt()
            as[i].l = x - l
            as[i].r = x + l

        }
        sort.Slice(as, func(i, j int) bool { return as[i].r < as[j].r })

        ans := 1
        r := as[0].r
        for i := 1; i < n; i++ {
            if as[i].l >= r {
                ans++
                r = as[i].r
            }
        }
        System.out.println(ans)
    }
}

