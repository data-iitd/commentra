import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int susum = 0;
        int j = 0;
        while(true) {
            String su = sc.nextLine();
            if(su.charAt(0) == '0') break;
            for(j = 0; j < su.length(); j++) {
                susum += su.charAt(j) - '0';
            }
            System.out.println(susum);
            susum = 0;
        }
    }
}
