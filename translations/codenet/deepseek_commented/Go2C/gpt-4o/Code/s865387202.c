#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int prefecture; // Represents the prefecture number of the city
    int position;   // Represents the position of the city in its prefecture
    int year;       // Represents the year the city was established
} City;

typedef struct {
<<<<<<< HEAD
    City **cities;  // Array of pointers to City
=======
    City *cities;   // Pointer to an array of cities
>>>>>>> 98c87cb78a (data updated)
    int count;      // Number of cities in this prefecture
} Prefecture;

typedef struct {
<<<<<<< HEAD
    Prefecture *prefectures; // Array of Prefectures
    int size;                // Number of prefectures
} CityMap;

int compare(const void *a, const void *b) {
    City *cityA = *(City **)a;
    City *cityB = *(City **)b;
    return cityA->year - cityB->year; // Compare by establishment year
=======
    Prefecture *prefectures; // Pointer to an array of prefectures
    int count;               // Number of prefectures
} CityMap;

int compare(const void *a, const void *b) {
    City *cityA = (City *)a;
    City *cityB = (City *)b;
    return cityA->year - cityB->year; // Compare cities by their establishment year
>>>>>>> 98c87cb78a (data updated)
}

int main() {
    int n, m; // Number of prefectures and cities
    scanf("%d %d", &n, &m);
    
    CityMap cityMap;
    cityMap.prefectures = (Prefecture *)calloc(n + 1, sizeof(Prefecture)); // Allocate memory for prefectures
<<<<<<< HEAD
    cityMap.size = n;
=======
    cityMap.count = n;
>>>>>>> 98c87cb78a (data updated)

    // Loop to read city entries
    for (int i = 0; i < m; i++) {
        int x, y; // Prefecture number and year
        scanf("%d %d", &x, &y);
        
        // Ensure the prefecture exists
        if (cityMap.prefectures[x].cities == NULL) {
<<<<<<< HEAD
            cityMap.prefectures[x].cities = (City **)malloc(sizeof(City *));
            cityMap.prefectures[x].count = 0;
        } else {
            cityMap.prefectures[x].cities = (City **)realloc(cityMap.prefectures[x].cities, (cityMap.prefectures[x].count + 1) * sizeof(City *));
        }
        
        // Create a new city and add it to the prefecture
        City *newCity = (City *)malloc(sizeof(City));
        newCity->prefecture = x;
        newCity->year = y;
        newCity->position = cityMap.prefectures[x].count;
        cityMap.prefectures[x].cities[cityMap.prefectures[x].count] = newCity;
        cityMap.prefectures[x].count++;
=======
            cityMap.prefectures[x].cities = (City *)malloc(sizeof(City) * m); // Allocate memory for cities
            cityMap.prefectures[x].count = 0; // Initialize city count
        }
        
        // Add the city to the prefecture
        City newCity = {x, cityMap.prefectures[x].count, y};
        cityMap.prefectures[x].cities[cityMap.prefectures[x].count++] = newCity; // Add city and increment count
>>>>>>> 98c87cb78a (data updated)
    }

    char results[m][13]; // Array to hold formatted city strings

    // Loop to sort and format cities
    for (int i = 1; i <= n; i++) {
<<<<<<< HEAD
        if (cityMap.prefectures[i].count > 0) {
            qsort(cityMap.prefectures[i].cities, cityMap.prefectures[i].count, sizeof(City *), compare); // Sort cities by year
            for (int idx = 0; idx < cityMap.prefectures[i].count; idx++) {
                City *ci = cityMap.prefectures[i].cities[idx];
                sprintf(results[ci->position], "%06d%06d", ci->prefecture, idx + 1); // Format the city string
=======
        if (cityMap.prefectures[i].cities != NULL) {
            qsort(cityMap.prefectures[i].cities, cityMap.prefectures[i].count, sizeof(City), compare); // Sort cities
            
            for (int idx = 0; idx < cityMap.prefectures[i].count; idx++) {
                sprintf(results[cityMap.prefectures[i].cities[idx].position], "%06d%06d", cityMap.prefectures[i].cities[idx].prefecture, idx + 1); // Format the city string
>>>>>>> 98c87cb78a (data updated)
            }
        }
    }

    // Print the results
    for (int i = 0; i < m; i++) {
        printf("%s\n", results[i]);
    }

    // Free allocated memory
    for (int i = 1; i <= n; i++) {
<<<<<<< HEAD
        for (int j = 0; j < cityMap.prefectures[i].count; j++) {
            free(cityMap.prefectures[i].cities[j]);
        }
=======
>>>>>>> 98c87cb78a (data updated)
        free(cityMap.prefectures[i].cities);
    }
    free(cityMap.prefectures);

    return 0;
}

// <END-OF-CODE>
