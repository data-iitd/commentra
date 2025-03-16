
import java.util.*;

public class Main
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);

        while (true)
        {
            int a = sc.nextInt();
            if (a < 0)
                break;

            int b = a;
            int c = 0;
            int k = 0;

            while (a > 0)
            {
                b--;
                c++;
                if (c == 3)
                {
                    k++;
                    c = 0;
                }
                a--;
            }
            System.out.println(k);
        }
    }
}

