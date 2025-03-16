
package com.company;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        Map<Integer, City[]> h = new HashMap<>();

        for (int i = 0; i < m; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            if (!h.containsKey(x)) {
                h.put(x, new City[]{new City(x, y, i)});
            } else {
                City[] cities = h.get(x);
                City[] newCities = new City[cities.length + 1];
                System.arraycopy(cities, 0, newCities, 0, cities.length);
                newCities[cities.length] = new City(x, y, i);
                h.put(x, newCities);
            }
        }

        String[] results = new String[m];

        for (Map.Entry<Integer, City[]> entry : h.entrySet()) {
            City[] cities = entry.getValue();
            for (int i = 0; i < cities.length; i++) {
                City city = cities[i];
                results[city.position] = String.format("%06d%06d", city.prefecture, i + 1);
            }
        }

        for (String result : results) {
            System.out.println(result);
        }
    }

    static class City implements Comparable<City> {
        int prefecture;
        int year;
        int position;

        public City(int prefecture, int year, int position) {
            this.prefecture = prefecture;
            this.year = year;
            this.position = position;
        }

        @Override
        public int compareTo(City o) {
            return this.year - o.year;
        }
    }
}

