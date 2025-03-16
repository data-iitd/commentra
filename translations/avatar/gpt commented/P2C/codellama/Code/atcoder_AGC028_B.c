#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the modulo constant
#define MOD 1000000007

// Define the maximum size
#define M 1000000

// Define the size for factorial calculations
#define Nsq 1000

// Define the maximum size for the array A
#define N 1000000

// Define the maximum size for the array inv
#define Ninv 1000000

// Define the maximum size for the array temp
#define Ntemp 1000000

// Define the maximum size for the array ans
#define Nans 1000000

// Define the maximum size for the array fact
#define Nfact 1000000

// Define the maximum size for the array j
#define Nj 1000000

// Define the maximum size for the array i
#define Ni 1000000

// Define the maximum size for the array k
#define Nk 1000000

// Define the maximum size for the array l
#define Nl 1000000

// Define the maximum size for the array m
#define Nm 1000000

// Define the maximum size for the array n
#define Nn 1000000

// Define the maximum size for the array o
#define No 1000000

// Define the maximum size for the array p
#define Np 1000000

// Define the maximum size for the array q
#define Nq 1000000

// Define the maximum size for the array r
#define Nr 1000000

// Define the maximum size for the array s
#define Ns 1000000

// Define the maximum size for the array t
#define Nt 1000000

// Define the maximum size for the array u
#define Nu 1000000

// Define the maximum size for the array v
#define Nv 1000000

// Define the maximum size for the array w
#define Nw 1000000

// Define the maximum size for the array x
#define Nx 1000000

// Define the maximum size for the array y
#define Ny 1000000

// Define the maximum size for the array z
#define Nz 1000000

// Define the maximum size for the array a
#define Na 1000000

// Define the maximum size for the array b
#define Nb 1000000

// Define the maximum size for the array c
#define Nc 1000000

// Define the maximum size for the array d
#define Nd 1000000

// Define the maximum size for the array e
#define Ne 1000000

// Define the maximum size for the array f
#define Nf 1000000

// Define the maximum size for the array g
#define Ng 1000000

// Define the maximum size for the array h
#define Nh 1000000

// Define the maximum size for the array i
#define Ni 1000000

// Define the maximum size for the array j
#define Nj 1000000

// Define the maximum size for the array k
#define Nk 1000000

// Define the maximum size for the array l
#define Nl 1000000

// Define the maximum size for the array m
#define Nm 1000000

// Define the maximum size for the array n
#define Nn 1000000

// Define the maximum size for the array o
#define No 1000000

// Define the maximum size for the array p
#define Np 1000000

// Define the maximum size for the array q
#define Nq 1000000

// Define the maximum size for the array r
#define Nr 1000000

// Define the maximum size for the array s
#define Ns 1000000

// Define the maximum size for the array t
#define Nt 1000000

// Define the maximum size for the array u
#define Nu 1000000

// Define the maximum size for the array v
#define Nv 1000000

// Define the maximum size for the array w
#define Nw 1000000

// Define the maximum size for the array x
#define Nx 1000000

// Define the maximum size for the array y
#define Ny 1000000

// Define the maximum size for the array z
#define Nz 1000000

// Define the maximum size for the array a
#define Na 1000000

// Define the maximum size for the array b
#define Nb 1000000

// Define the maximum size for the array c
#define Nc 1000000

// Define the maximum size for the array d
#define Nd 1000000

// Define the maximum size for the array e
#define Ne 1000000

// Define the maximum size for the array f
#define Nf 1000000

// Define the maximum size for the array g
#define Ng 1000000

// Define the maximum size for the array h
#define Nh 1000000

// Define the maximum size for the array i
#define Ni 1000000

// Define the maximum size for the array j
#define Nj 1000000

// Define the maximum size for the array k
#define Nk 1000000

// Define the maximum size for the array l
#define Nl 1000000

// Define the maximum size for the array m
#define Nm 1000000

// Define the maximum size for the array n
#define Nn 1000000

// Define the maximum size for the array o
#define No 1000000

// Define the maximum size for the array p
#define Np 1000000

// Define the maximum size for the array q
#define Nq 1000000

// Define the maximum size for the array r
#define Nr 1000000

// Define the maximum size for the array s
#define Ns 1000000

// Define the maximum size for the array t
#define Nt 1000000

// Define the maximum size for the array u
#define Nu 1000000

// Define the maximum size for the array v
#define Nv 1000000

// Define the maximum size for the array w
#define Nw 1000000

// Define the maximum size for the array x
#define Nx 1000000

// Define the maximum size for the array y
#define Ny 1000000

// Define the maximum size for the array z
#define Nz 1000000

// Define the maximum size for the array a
#define Na 1000000

// Define the maximum size for the array b
#define Nb 1000000

// Define the maximum size for the array c
#define Nc 1000000

// Define the maximum size for the array d
#define Nd 1000000

// Define the maximum size for the array e
#define Ne 1000000

// Define the maximum size for the array f
#define Nf 1000000

// Define the maximum size for the array g
#define Ng 1000000

// Define the maximum size for the array h
#define Nh 1000000

// Define the maximum size for the array i
#define Ni 1000000

// Define the maximum size for the array j
#define Nj 1000000

// Define the maximum size for the array k
#define Nk 1000000

// Define the maximum size for the array l
#define Nl 1000000

// Define the maximum size for the array m
#define Nm 1000000

// Define the maximum size for the array n
#define Nn 1000000

// Define the maximum size for the array o
#define No 1000000

// Define the maximum size for the array p
#define Np 1000000

// Define the maximum size for the array q
#define Nq 1000000

// Define the maximum size for the array r
#define Nr 1000000

// Define the maximum size for the array s
#define Ns 1000000

// Define the maximum size for the array t
#define Nt 1000000

// Define the maximum size for the array u
#define Nu 1000000

// Define the maximum size for the array v
#define Nv 1000000

// Define the maximum size for the array w
#define Nw 1000000

// Define the maximum size for the array x
#define Nx 1000000

// Define the maximum size for the array y
#define Ny 1000000

// Define the maximum size for the array z
#define Nz 1000000

// Define the maximum size for the array a
#define Na 1000000

// Define the maximum size for the array b
#define Nb 1000000

// Define the maximum size for the array c
#define Nc 1000000

// Define the maximum size for the array d
#define Nd 1000000

// Define the maximum size for the array e
#define Ne 1000000

// Define the maximum size for the array f
#define Nf 1000000

// Define the maximum size for the array g
#define Ng 1000000

// Define the maximum size for the array h
#define Nh 1000000

// Define the maximum size for the array i
#define Ni 1000000

// Define the maximum size for the array j
#define Nj 1000000

// Define the maximum size for the array k
#define Nk 1000000

// Define the maximum size for the array l
#define Nl 1000000

// Define the maximum size for the array m
#define Nm 1000000

// Define the maximum size for the array n
#define Nn 1000000

// Define the maximum size for the array o
#define No 1000000

// Define the maximum size for the array p
#define Np 1000000

// Define the maximum size for the array q
#define Nq 1000000

// Define the maximum size for the array r
#define Nr 1000000

// Define the maximum size for the array s
#define Ns 1000000

// Define the maximum size for the array t
#define Nt 1000000

// Define the maximum size for the array u
#define Nu 1000000

// Define the maximum size for the array v
#define Nv 1000000

// Define the maximum size for the array w
#define Nw 1000000

// Define the maximum size for the array x
#define Nx 1000000

// Define the maximum size for the array y
#define Ny 1000000

// Define the maximum size for the array z
#define Nz 1000000

// Define the maximum size for the array a
#define Na 1000000

// Define the maximum size for the array b
#define Nb 1000000

// Define the maximum size for the array c
#define Nc 1000000

// Define the maximum size for the array d
#define Nd 1000000

// Define the maximum size for the array e
#define Ne 1000000

// Define the maximum size for the array f
#define Nf 1000000

// Define the maximum size for the array g
#define Ng 1000000

// Define the maximum size for the array h
#define Nh 1000000

// Define the maximum size for the array i
#define Ni 1000000

// Define the maximum size for the array j
#define Nj 1000000

// Define the maximum size for the array k
#define Nk 1000000

// Define the maximum size for the array l
#define Nl 1000000

// Define the maximum size for the array m
#define Nm 1000000

// Define the maximum size for the array n
#define Nn 1000000

// Define the maximum size for the array o
#define No 1000000

// Define the maximum size for the array p
#define Np 1000000

// Define the maximum size for the array q
#define Nq 1000000

// Define the maximum size for the array r
#define Nr 1000000

// Define the maximum size for the array s
#define Ns 1000000

// Define the maximum size for the array t
#define Nt 1000000

// Define the maximum size for the array u
#define Nu 1000000

// Define the maximum size for the array v
#define Nv 1000000

// Define the maximum size for the array w
#define Nw 1000000

// Define the maximum size for the array x
#define Nx 1000000

// Define the maximum size for the array y
#define Ny 1000000

// Define the maximum size for the array z
#define Nz 1000000

// Define the maximum size for the array a
#define Na 1000000

// Define the maximum size for the ar