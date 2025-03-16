#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    // Declare a map to store the minimum price for each weight
    int m[5001];

    // Iterate over possible quantities of items weighing 200 units
    for(int i=0; i*200<5001; i++){
        // Iterate over possible quantities of items weighing 300 units
        for(int j=0; j*300<5001; j++){
            // Iterate over possible quantities of items weighing 500 units
            for(int k=0; k*500<5001; k++){
                // Calculate the total weight based on the quantities of items
                int w = i*200 + j*300 + k*500;

                // Calculate the price based on the quantities of items
                int p = i/5*5*380*0.8 + i%5*380
                      + j/4*4*550*0.85 + j%4*550
                      + k/3*3*850*0.88 + k%3*850;

                // Update the map with the minimum price for the calculated weight
                if(m[w]) 
                    m[w] = min(m[w], p); // If weight already exists, take the minimum price
                else 
                    m[w] = p; // If weight does not exist, set the price
            }
        }
    }

    // Read input weights and output the corresponding minimum prices
    int n;
    while(scanf("%d", &n), n){
        printf("%d\n", m[n]); // Output the minimum price for the given weight
    }
}

