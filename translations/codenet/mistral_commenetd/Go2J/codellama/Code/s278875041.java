// Importing required packages
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String a = sc.nextLine();
        String tmp = a.replaceAll("1", "0");
        String b = tmp.replaceAll("9", "1");
        String ans = b.replaceAll("0", "9");
        System.out.println(ans);
    }
}

// Printing the final answer
