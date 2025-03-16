import java.util.*;
public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int i,j,max,max_j,buf;
		int io[]=new int[5];
		for(i=0;i<5;i++){
			io[i]=sc.nextInt();
		}
		for(i=0;i<5;i++){
			max=io[i];
			max_j=i;
			for(j=i+1;j<5;j++){
				if(max<io[j]){
					max=io[j];
					max_j=j;
				}
			}
			buf=io[i];
			io[i]=io[max_j];
			io[max_j]=buf;
			i<4?System.out.print(io[i]+" "):System.out.println(io[i]);
		}
	}
}
