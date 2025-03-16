
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Initialize an empty map named 'm'
int main(){
    int m[5001];

    // Iterate through all possible indices 'i' that satisfy the condition i*200 < 5001
    for(int i=0;i*200<5001;i++){
        // Iterate through all possible indices 'j' that satisfy the condition j*300 < 5001
        for(int j=0;j*300<5001;j++){
            // Iterate through all possible indices 'k' that satisfy the condition k*500 < 5001
            for(int k=0;k*500<5001;k++){
                // Calculate the composite index 'w'
                int w=i*200+j*300+k*500;

                // Calculate the potential value 'p' for the given index 'w'
                int p=i/5*5*380*0.8+i%5*380
                     +j/4*4*550*0.85+j%4*550
                     +k/3*3*850*0.88+k%3*850;

                // If the map 'm' already contains the index 'w', update its value with the minimum of the current potential value and the existing one
                if(m[w] != 0){
                    m[w]=min(m[w],p);
                }

                // If the map 'm' does not contain the index 'w', add it with the current potential value as its value
                else{
                    m[w]=p;
                }
            }
        }
    }

    // Read integers from the standard input and print their corresponding potential values from the map 'm'
    int n;
    while(scanf("%d",&n),n){
        printf("%d\n",m[n]);
    }
}

