#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MOD 1000000007
#define MAX_N 100000
#define MAX_TOKENS 4

typedef struct {
    char *s;
    int len;
} String;

typedef struct {
    String s;
    long val;
} Cache;

typedef struct {
    Cache *cache;
    int size;
} CacheArray;

typedef struct {
    CacheArray *cache_array;
    int size;
} CacheMap;

typedef struct {
    CacheMap *cache_map;
    int size;
} CacheMapArray;

typedef struct {
    CacheMapArray *cache_map_array;
    int size;
} CacheMapMap;

typedef struct {
    CacheMapMap *cache_map_map;
    int size;
} CacheMapMapArray;

typedef struct {
    CacheMapMapArray *cache_map_map_array;
    int size;
} CacheMapMapMap;

typedef struct {
    CacheMapMapMap *cache_map_map_map;
    int size;
} CacheMapMapMapArray;

typedef struct {
    CacheMapMapMapArray *cache_map_map_map_array;
    int size;
} CacheMapMapMapMap;

typedef struct {
    CacheMapMapMapMap *cache_map_map_map_map;
    int size;
} CacheMapMapMapMapArray;

typedef struct {
    CacheMapMapMapMapArray *cache_map_map_map_map_array;
    int size;
} CacheMapMapMapMapMap;

typedef struct {
    CacheMapMapMapMapMap *cache_map_map_map_map_map;
    int size;
} CacheMapMapMapMapMapArray;

typedef struct {
    CacheMapMapMapMapMapArray *cache_map_map_map_map_map_array;
    int size;
} CacheMapMapMapMapMapMap;

typedef struct {
    CacheMapMapMapMapMapMap *cache_map_map_map_map_map_map;
    int size;
} CacheMapMapMapMapMapMapArray;

typedef struct {
    CacheMapMapMapMapMapMapArray *cache_map_map_map_map_map_map_array;
    int size;
} CacheMapMapMapMapMapMapMap;

typedef struct {
    CacheMapMapMapMapMapMapMap *cache_map_map_map_map_map_map_map_array;
    int size;
} CacheMapMapMapMapMapMapMapMap;

typedef struct {
    CacheMapMapMapMapMapMapMapMap *cache_map_map_map_map_map_map_map_map_array;
    int size;
} CacheMapMapMapMapMapMapMapMapMap;

typedef struct {
    CacheMapMapMapMapMapMapMapMapMap *cache_map_map_map_map_map_map_map_map_map_array;
    int size;
} CacheMapMapMapMapMapMapMapMapMapMap;

typedef struct {
    CacheMapMapMapMapMapMapMapMapMapMap *cache_map_map_map_map_map_map_map_map_map_map_array;
    int size;
} CacheMapMapMapMapMapMapMapMapMapMapMap;

typedef struct {
    CacheMapMapMapMapMapMapMapMapMapMapMap *cache_map_map_map_map_map_map_map_map_map_map_map_array;
    int size;
} CacheMapMapMapMapMapMapMapMapMapMapMapMap;

typedef struct {
    CacheMapMapMapMapMapMapMapMapMapMapMapMap *cache_map_map_map_map_map_map_map_map_map_map_map_map_array;
    int size;
} CacheMapMapMapMapMapMapMapMapMapMapMapMapMap;

typedef struct {
    CacheMapMapMapMapMapMapMapMapMapMapMapMapMap *cache_map_map_map_map_map_map_map_map_map_map_map_map_map_array;
    int size;
} CacheMapMapMapMapMapMapMapMapMapMapMapMapMapMap;

typedef struct {
    CacheMapMapMapMapMapMapMapMapMapMapMapMapMapMap *cache_map_map_map_map_map_map_map_map_map_map_map_map_map_map_array;
    int size;
} CacheMapMapMapMapMapMapMapMapMapMapMapMapMapMapMap;

typedef struct {
    CacheMapMapMapMapMapMapMapMapMapMapMapMapMapMapMap *cache_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_array;
    int size;
} CacheMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMap;

typedef struct {
    CacheMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMap *cache_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_array;
    int size;
} CacheMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMap;

typedef struct {
    CacheMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMap *cache_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_array;
    int size;
} CacheMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMap;

typedef struct {
    CacheMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMap *cache_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_array;
    int size;
} CacheMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMap;

typedef struct {
    CacheMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMap *cache_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_array;
    int size;
} CacheMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMap;

typedef struct {
    CacheMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMap *cache_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_array;
    int size;
} CacheMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMap;

typedef struct {
    CacheMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMap *cache_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_array;
    int size;
} CacheMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMap;

typedef struct {
    CacheMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMap *cache_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_array;
    int size;
} CacheMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMap;

typedef struct {
    CacheMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMap *cache_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_array;
    int size;
} CacheMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMap;

typedef struct {
    CacheMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMap *cache_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_array;
    int size;
} CacheMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMap;

typedef struct {
    CacheMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMap *cache_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_array;
    int size;
} CacheMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMap;

typedef struct {
    CacheMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMap *cache_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_array;
    int size;
} CacheMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMap;

typedef struct {
    CacheMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMap *cache_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_array;
    int size;
} CacheMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMap;

typedef struct {
    CacheMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMap *cache_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_array;
    int size;
} CacheMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMap;

typedef struct {
    CacheMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMap *cache_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_array;
    int size;
} CacheMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMap;

typedef struct {
    CacheMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMap *cache_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_array;
    int size;
} CacheMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMap;

typedef struct {
    CacheMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMap *cache_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_array;
    int size;
} CacheMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMap;

typedef struct {
    CacheMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMap *cache_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_array;
    int size;
} CacheMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMap;

typedef struct {
    CacheMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMap *cache_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_array;
    int size;
} CacheMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMap;

typedef struct {
    CacheMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMap *cache_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_array;
    int size;
} CacheMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMap;

typedef struct {
    CacheMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMap *cache_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_map_array;
    int size;
} CacheMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMap;

typedef struct {
    CacheMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMapMap *cache_map_map_map_m