import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        System.out.println(a/(60*60) + ":" + a%(60*60)/60 + ":" + a%(60*60)%60);
    }
}
