
#include<stdio.h>
#include<stdlib.h>

int main(){
    // Declare a map to store the minimum price for each weight
    int **m = (int **)malloc(50001*sizeof(int *));
    for(int i=0; i<50001; i++)
        m[i] = (int *)malloc(50001*sizeof(int));

    // Iterate over possible quantities of items weighing 200 units
    for(int i=0; i*200<50001; i++){
        // Iterate over possible quantities of items weighing 300 units
        for(int j=0; j*300<50001; j++){
            // Iterate over possible quantities of items weighing 500 units
            for(int k=0; k*500<50001; k++){
                // Calculate the total weight based on the quantities of items
                int w = i*200 + j*300 + k*500;

                // Calculate the price based on the quantities of items
                int p = i/5*5*380*0.8 + i%5*380
                      + j/4*4*550*0.85 + j%4*550
                      + k/3*3*850*0.88 + k%3*850;

                // Update the map with the minimum price for the calculated weight
                if(m[w][0]) 
                    m[w][0] = (m[w][0] < p)? m[w][0] : p; // If weight already exists, take the minimum price
                else 
                    m[w][0] = p; // If weight does not exist, set the price
            }
        }
    }

    // Read input weights and output the corresponding minimum prices
    int n;
    while(scanf("%d", &n), n){
        printf("%d\n", m[n][0]); // Output the minimum price for the given weight
    }
}
