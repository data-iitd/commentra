import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        long x = in.nextLong();
        long y = in.nextLong();
        if(Math.abs(x-y) <= 1) System.out.println("Brown");
        else System.out.println("Alice");
    }
}

