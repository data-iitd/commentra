import java.util.*;
public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int susum=0;
		while(true){
			String su=sc.next();
			if(su.charAt(0)=='0')break;
			for(int i=0;i<su.length();i++){
				susum=susum+(su.charAt(i)-'0');
			}
			System.out.println(susum);
			susum=0;
		}
	}
}
