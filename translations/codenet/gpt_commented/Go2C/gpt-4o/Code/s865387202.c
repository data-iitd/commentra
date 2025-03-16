#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int prefecture; // Prefecture number
    int position;   // Position in the input
    int year;       // Year associated with the city
} City;

typedef struct {
    City* cities;   // Array of cities
    int count;      // Number of cities in this prefecture
} Prefecture;

<<<<<<< HEAD
int compare(const void* a, const void* b) {
    City* cityA = (City*)a;
    City* cityB = (City*)b;
    return cityA->year - cityB->year; // Sort by year
=======
typedef struct {
    Prefecture* prefectures; // Array of prefectures
    int count;               // Number of prefectures
} CityMap;

// Function to compare cities by year for qsort
int compareCities(const void* a, const void* b) {
    City* cityA = (City*)a;
    City* cityB = (City*)b;
    return cityA->year - cityB->year;
>>>>>>> 98c87cb78a (data updated)
}

int main() {
    int n, m; // n: number of prefectures, m: number of cities
    scanf("%d %d\n", &n, &m);
<<<<<<< HEAD
    
    Prefecture* prefectures = (Prefecture*)malloc((n + 1) * sizeof(Prefecture));
    for (int i = 0; i <= n; i++) {
        prefectures[i].cities = NULL;
        prefectures[i].count = 0;
    }
    
=======

    // Initialize the city map
    CityMap cityMap;
    cityMap.prefectures = (Prefecture*)malloc(n * sizeof(Prefecture));
    cityMap.count = n;

    // Initialize prefectures
    for (int i = 0; i < n; i++) {
        cityMap.prefectures[i].cities = NULL;
        cityMap.prefectures[i].count = 0;
    }

>>>>>>> 98c87cb78a (data updated)
    // Read city data from input
    for (int i = 0; i < m; i++) {
        int x, y; // x: prefecture number, y: year
        scanf("%d %d\n", &x, &y);
<<<<<<< HEAD
        
        // Resize the cities array for the prefecture
        prefectures[x].cities = (City*)realloc(prefectures[x].cities, (prefectures[x].count + 1) * sizeof(City));
        prefectures[x].cities[prefectures[x].count].prefecture = x;
        prefectures[x].cities[prefectures[x].count].year = y;
        prefectures[x].cities[prefectures[x].count].position = i;
        prefectures[x].count++;
    }

    // Prepare a results array to hold formatted output for each city
    char** results = (char**)malloc(m * sizeof(char*));
    for (int i = 0; i < m; i++) {
        results[i] = (char*)malloc(13 * sizeof(char)); // 12 for "000000000000" + 1 for '\0'
    }

    // Iterate over each group of cities in the prefectures
    for (int i = 1; i <= n; i++) {
        if (prefectures[i].count > 0) {
            // Sort the cities by year
            qsort(prefectures[i].cities, prefectures[i].count, sizeof(City), compare);
            // Format the output for each city based on its position and year
            for (int idx = 0; idx < prefectures[i].count; idx++) {
                City* ci = &prefectures[i].cities[idx];
=======
        x--; // Adjust for 0-based index

        // Resize the cities array for the prefecture
        cityMap.prefectures[x].count++;
        cityMap.prefectures[x].cities = (City*)realloc(cityMap.prefectures[x].cities, cityMap.prefectures[x].count * sizeof(City));
        cityMap.prefectures[x].cities[cityMap.prefectures[x].count - 1] = (City){x + 1, i, y}; // Store city
    }

    // Prepare results array
    char results[m][13]; // Each result will be a string of length 12 + 1 for null terminator

    // Iterate over each prefecture
    for (int i = 0; i < n; i++) {
        if (cityMap.prefectures[i].count > 0) {
            // Sort the cities by year
            qsort(cityMap.prefectures[i].cities, cityMap.prefectures[i].count, sizeof(City), compareCities);

            // Format the output for each city based on its position and year
            for (int idx = 0; idx < cityMap.prefectures[i].count; idx++) {
                City* ci = &cityMap.prefectures[i].cities[idx];
>>>>>>> 98c87cb78a (data updated)
                sprintf(results[ci->position], "%06d%06d", ci->prefecture, idx + 1);
            }
        }
    }
<<<<<<< HEAD
    
    // Print the results, joining them with newline characters
    for (int i = 0; i < m; i++) {
        printf("%s\n", results[i]);
        free(results[i]); // Free each result string
    }
    
    free(results); // Free the results array
    for (int i = 1; i <= n; i++) {
        free(prefectures[i].cities); // Free each prefecture's cities array
    }
    free(prefectures); // Free the prefectures array
=======

    // Print the results
    for (int i = 0; i < m; i++) {
        printf("%s\n", results[i]);
    }

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(cityMap.prefectures[i].cities);
    }
    free(cityMap.prefectures);
>>>>>>> 98c87cb78a (data updated)

    return 0;
}

// <END-OF-CODE>
