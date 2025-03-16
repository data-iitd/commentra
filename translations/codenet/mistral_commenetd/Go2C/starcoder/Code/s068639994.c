
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

// Define macros for handling errors
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define massert(cond,...) do { if (!(cond)) { eprintf(__VA_ARGS__); exit(EXIT_FAILURE); } } while (0)

// Define macros for handling arrays
#define mnew(T, n) ((T*) malloc(sizeof(T) * (n)))
#define mnew0(T, n) ((T*) calloc(sizeof(T), (n)))
#define mfree(p) free(p)
#define mcpy(dst, src, n) memcpy(dst, src, sizeof(dst[0]) * (n))
#define mzero(a, n) memset(a, 0, sizeof(a[0]) * (n))
#define mset(a, v, n) memset(a, v, sizeof(a[0]) * (n))

// Define macros for handling pairs
#define mp(T, a, b) ((T*) {.first = (a),.second = (b) })
#define mpmake(T, a, b) (T) {.first = (a),.second = (b) }
#define mpfirst(p) ((p).first)
#define mpsecond(p) ((p).second)

// Define macros for handling triples
#define mt(T, a, b, c) ((T*) {.first = (a),.second = (b),.third = (c) })
#define mtmake(T, a, b, c) (T) {.first = (a),.second = (b),.third = (c) }
#define mtfirst(t) ((t).first)
#define mtsecond(t) ((t).second)
#define mtthird(t) ((t).third)

// Define macros for handling quadruples
#define mq(T, a, b, c, d) ((T*) {.first = (a),.second = (b),.third = (c),.fourth = (d) })
#define mqmake(T, a, b, c, d) (T) {.first = (a),.second = (b),.third = (c),.fourth = (d) }
#define mqfirst(q) ((q).first)
#define mqsecond(q) ((q).second)
#define mqthird(q) ((q).third)
#define mqfourth(q) ((q).fourth)

// Define macros for handling quintuples
#define mq(T, a, b, c, d, e) ((T*) {.first = (a),.second = (b),.third = (c),.fourth = (d),.fifth = (e) })
#define mqmake(T, a, b, c, d, e) (T) {.first = (a),.second = (b),.third = (c),.fourth = (d),.fifth = (e) }
#define mqfirst(q) ((q).first)
#define mqsecond(q) ((q).second)
#define mqthird(q) ((q).third)
#define mqfourth(q) ((q).fourth)
#define mqfifth(q) ((q).fifth)

// Define macros for handling sextuples
#define ms(T, a, b, c, d, e, f) ((T*) {.first = (a),.second = (b),.third = (c),.fourth = (d),.fifth = (e),.sixth = (f) })
#define msmake(T, a, b, c, d, e, f) (T) {.first = (a),.second = (b),.third = (c),.fourth = (d),.fifth = (e),.sixth = (f) }
#define msfirst(s) ((s).first)
#define mssecond(s) ((s).second)
#define msthird(s) ((s).third)
#define msfourth(s) ((s).fourth)
#define msfifth(s) ((s).fifth)
#define mssixth(s) ((s).sixth)

// Define macros for handling septuples
#define ms(T, a, b, c, d, e, f, g) ((T*) {.first = (a),.second = (b),.third = (c),.fourth = (d),.fifth = (e),.sixth = (f),.seventh = (g) })
#define msmake(T, a, b, c, d, e, f, g) (T) {.first = (a),.second = (b),.third = (c),.fourth = (d),.fifth = (e),.sixth = (f),.seventh = (g) }
#define msfirst(s) ((s).first)
#define mssecond(s) ((s).second)
#define msthird(s) ((s).third)
#define msfourth(s) ((s).fourth)
#define msfifth(s) ((s).fifth)
#define mssixth(s) ((s).sixth)
#define mseventh(s) ((s).seventh)

// Define macros for handling octuples
#define mo(T, a, b, c, d, e, f, g, h) ((T*) {.first = (a),.second = (b),.third = (c),.fourth = (d),.fifth = (e),.sixth = (f),.seventh = (g),.eighth = (h) })
#define momake(T, a, b, c, d, e, f, g, h) (T) {.first = (a),.second = (b),.third = (c),.fourth = (d),.fifth = (e),.sixth = (f),.seventh = (g),.eighth = (h) }
#define mofirst(o) ((o).first)
#define mosecond(o) ((o).second)
#define mosthird(o) ((o).third)
#define mofouht(o) ((o).fourth)
#define mofifth(o) ((o).fifth)
#define mosixth(o) ((o).sixth)
#define mosthird(o) ((o).seventh)
#define moeighth(o) ((o).eighth)

// Define macros for handling nonuples
#define mn(T, a, b, c, d, e, f, g, h, i) ((T*) {.first = (a),.second = (b),.third = (c),.fourth = (d),.fifth = (e),.sixth = (f),.seventh = (g),.eighth = (h),.ninth = (i) })
#define mnmake(T, a, b, c, d, e, f, g, h, i) (T) {.first = (a),.second = (b),.third = (c),.fourth = (d),.fifth = (e),.sixth = (f),.seventh = (g),.eighth = (h),.ninth = (i) }
#define mnfirst(n) ((n).first)
#define mnsecond(n) ((n).second)
#define mnthird(n) ((n).third)
#define mnfourth(n) ((n).fourth)
#define mnfifth(n) ((n).fifth)
#define mnsixth(n) ((n).sixth)
#define mnseventh(n) ((n).seventh)
#define mneighth(n) ((n).eighth)
#define mnninth(n) ((n).ninth)

// Define macros for handling decuples
#define md(T, a, b, c, d, e, f, g, h, i, j) ((T*) {.first = (a),.second = (b),.third = (c),.fourth = (d),.fifth = (e),.sixth = (f),.seventh = (g),.eighth = (h),.ninth = (i),.tenth = (j) })
#define mdmake(T, a, b, c, d, e, f, g, h, i, j) (T) {.first = (a),.second = (b),.third = (c),.fourth = (d),.fifth = (e),.sixth = (f),.seventh = (g),.eighth = (h),.ninth = (i),.tenth = (j) }
#define mdfirst(d) ((d).first)
#define mdsecond(d) ((d).second)
#define mdthird(d) ((d).third)
#define mdfourth(d) ((d).fourth)
#define mdfifth(d) ((d).fifth)
#define mdsixth(d) ((d).sixth)
#define mdseventh(d) ((d).seventh)
#define mdeighth(d) ((d).eighth)
#define mdninth(d) ((d).ninth)
#define mdtenth(d) ((d).tenth)

// Define macros for handling undecuples
#define mu(T, a, b, c, d, e, f, g, h, i, j, k) ((T*) {.first = (a),.second = (b),.third = (c),.fourth = (d),.fifth = (e),.sixth = (f),.seventh = (g),.eighth = (h),.ninth = (i),.tenth = (j),.eleventh = (k) })
#define mumake(T, a, b, c, d, e, f, g, h, i, j, k) (T) {.first = (a),.second = (b),.third = (c),.fourth = (d),.fifth = (e),.sixth = (f),.seventh = (g),.eighth = (h),.ninth = (i),.tenth = (j),.eleventh = (k) }
#define mufirst(u) ((u).first)
#define musecond(u) ((u).second)
#define muthird(u) ((u).third)
#define mufouht(u) ((u).fourth)
#define mufifth(u) ((u).fifth)
#define musixth(u) ((u).sixth)
#define museventh(u) ((u).seventh)
#define mueighth(u) ((u).eighth)
#define muninth(u) ((u).ninth)
#define mutenth(u) ((u).tenth)
#define mueleventh(u) ((u).eleventh)

// Define macros for handling duodecuples
#define md(T, a, b, c, d, e, f, g, h, i, j, k, l) ((T*) {.first = (a),.second = (b),.third = (c),.fourth = (d),.fifth = (e),.sixth = (f),.seventh = (g),.eighth = (h),.ninth = (i),.tenth = (j),.eleventh = (k),.twelfth = (l) })
#define mdmake(T, a, b, c, d, e, f, g, h, i, j, k, l) (T) {.first = (a),.second = (b),.third = (c),.fourth = (d),.fifth = (e),.sixth = (f),.seventh = (g),.eighth = (h),.ninth = (i),.tenth = (j),.eleventh = (k),.twelfth = (l) }
#define mdfirst(d) ((d).first)
#define mdsecond(d) ((d).second)
#define mdthird(d) ((d).third)
#define mdfourth(d) ((d).fourth)
#define mdfifth(d) ((d).fifth)
#define mdsixth(d) ((d).sixth)
#define mdseventh(d) ((d).seventh)
#define mdeighth(d) ((d).eighth)
#define mdninth(d) ((d).ninth)
#define mdtenth(d) ((d).tenth)
#define mdeleventh(d) ((d).eleventh)
#define mdtwelfth(d) ((d).twelfth)

// Define macros for handling tredecuples
#define mt(T, a, b, c, d, e, f, g, h, i, j, k, l, m) ((T*) {.first = (a),.second = (b),.third = (c),.fourth = (d),.fifth = (e),.sixth = (f),.seventh = (g),.eighth = (h),.ninth = (i),.tenth = (j),.eleventh = (k),.twelfth = (l),.thirteenth = (m) })
#define mtmake(T, a, b, c, d, e, f, g, h, i, j, k, l, m) (T) {.first = (a),.second = (b),.third = (c),.fourth = (d),.fifth = (e),.sixth = (f),.seventh = (g),.eighth = (h),.ninth = (i),.tenth = (j),.eleventh = (k),.twelfth = (l),.thirteenth = (m) }
#define mtfirst(t) ((t).first)
#define mtsecond(t) ((t).second)
#define mtthird(t) ((t).third)
#define mtfourth(t) ((t).fourth)
#define mtfifth(t) ((t).fifth)
#define mtsixth(t) ((t).sixth)
#define mtseventh(t) ((t).seventh)
#define mteighth(t) ((t).eighth)
#define mtninth(t) ((t).ninth)
#define mttenth(t) ((t).tenth)
#define mteleventh(t) ((t).eleventh)
#define mttwelfth(t) ((t).twelfth)
#define mtthirteenth(t) ((t).thirteenth)

// Define macros for handling quattuordecuples
#define mq(T, a, b, c, d, e, f, g, h, i, j, k, l, m, n) ((T*) {.first = (a),.second = (b),.third = (c),.fourth = (d),.fifth = (e),.sixth = (f),.seventh = (g),.eighth = (h),.ninth = (i),.tenth = (j),.eleventh = (k),.twelfth = (l),.thirteenth = (m),.fourteenth = (n) })
#define mqmake(T, a, b, c, d, e, f, g, h, i, j, k, l, m, n) (T) {.first = (a),.second = (b),.third = (c),.fourth = (d),.fifth = (e),.sixth = (f),.seventh = (g),.eighth = (h),.ninth = (i),.tenth = (j),.eleventh = (k),.twelfth = (l),.thirteenth = (m),.fourteenth = (n) }
#define mqfirst(q) ((q).first)
#define mqsecond(q) ((q).second)
#define mqthird(q) ((q).third)
#define mqfourth(q) ((q).fourth)
#define mqfifth(q) ((q).fifth)
#define mqsixth(q) ((q).sixth)
#define mqseventh(q) ((q).seventh)
#define mqeighth(q) ((q).eighth)
#define mqninth(q) ((q).ninth)
#define mqtenth(q) ((q).tenth)
#define mqeleventh(q) ((q).eleventh)
#define mqtwelfth(q) ((q).twelfth)
#define mqthirteenth(q) ((q).thirteenth)
#define mqfourteenth(q) ((q).fourteenth)

// Define macros for handling quindecuples
#define mq(T, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o) ((T*) {.first = (a),.second = (b),.third = (c),.fourth = (d),.fifth = (e),.sixth = (f),.seventh = (g),.eighth = (h),.ninth = (i),.tenth = (j),.eleventh = (k),.twelfth = (l),.thirteenth = (m),.fourteenth = (n),.fifteenth = (o) })
#define mqmake(T, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o) (T) {.first = (a),.second = (b),.third = (c),.fourth = (d),.fifth = (e),.sixth = (f),.seventh = (g),.eighth = (h),.ninth = (i),.tenth = (j),.eleventh = (k),.twelfth = (l),.thirteenth = (m),.fourteenth = (n),.fifteenth = (o) }
#define mqfirst(q) ((q).first)
#define mqsecond(q) ((q).second)
#define mqthird(q) ((q).third)
#define mqfourth(q) ((q).fourth)
#define mqfifth(q) ((q).fifth)
#define mqsixth(q) ((q).sixth)
#define mqseventh(q) ((q).seventh)
#define mqeighth(q) ((q).eighth)
#define mqninth(q) ((q).ninth)
#define mqtenth(q) ((q).tenth)
#define mqeleventh(q) ((q).eleventh)
#define mqtwelfth(q) ((q).twelfth)
#define mqthirteenth(q) ((q).thirteenth)
#define mqfourteenth(q) ((q).fourteenth)
#define mqfifteenth(q) ((q).fifteenth)

// Define macros for handling sexdecuples
#define ms(T, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p) ((T*) {.first = (a),.second = (b),.third = (c),.fourth = (d),.fifth = (e