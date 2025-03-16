import java.util.*;
public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int sum=0,i;
		while(true){
			String x=sc.next();
			if(x.equals("0"))
				break;
			for(i=0;i<x.length();i++){
				sum+=x.charAt(i)-'0';
			}
			System.out.println(sum);
			sum=0;
		}
	}
}
