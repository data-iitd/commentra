import java.util.*;
public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int i,sum=0;
		int flag=0;
		String x=sc.next();
		do{
			for(i=0;i<1002;i++){
				if(x.charAt(i)==0){
					System.out.println(sum);
					break;
				}else{
					sum+=x.charAt(i)-0x30;
				}
			}
			sum=0;
			x=sc.next();
		}while(x.charAt(0)!=0x30);
	}
}
