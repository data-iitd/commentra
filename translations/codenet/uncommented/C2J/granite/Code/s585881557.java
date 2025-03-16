
import java.util.Scanner;

public class s585881557{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int h = sc.nextInt();
		int r = sc.nextInt();
		if(r > -h){System.out.println("1");}
		else if (r == -h){System.out.println("0");}
		else{System.out.println("-1");}
		sc.close();
	}
}
