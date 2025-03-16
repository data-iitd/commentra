
import java.util.*;
public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int S = in.nextInt();
        if (S < 60)
            System.out.println("0:0:"+S);
        else if (S < 3600)
            System.out.println("0:"+S/60+":"+S%60);
        else
            System.out.println(S/3600+":"+(S%3600)/60+":"+(S%60));
    }
}

