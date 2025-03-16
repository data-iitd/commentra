
package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
)

// Define the modulo constant
const MOD = 1000000007

// Define a constant for the maximum size
const M = 1000000

// Define a constant for factorial calculations
const Nsq = 1000

// Define a constant for the maximum value of N
const Nmax = 1000000

// Define a constant for the maximum value of A
const Amax = 1000000

// Define a constant for the maximum value of j
const jmax = 1000000

// Define a constant for the maximum value of inv
const invmax = 1000000

// Define a constant for the maximum value of temp
const tempmax = 1000000

// Define a constant for the maximum value of ans
const ansmax = 1000000

// Define a constant for the maximum value of fact
const factmax = 1000000

// Define a constant for the maximum value of i
const imax = 1000000

// Define a constant for the maximum value of n
const nmax = 1000000

// Define a constant for the maximum value of m
const mmax = 1000000

// Define a constant for the maximum value of k
const kmax = 1000000

// Define a constant for the maximum value of l
const lmax = 1000000

// Define a constant for the maximum value of p
const pmax = 1000000

// Define a constant for the maximum value of q
const qmax = 1000000

// Define a constant for the maximum value of r
const rmax = 1000000

// Define a constant for the maximum value of s
const smax = 1000000

// Define a constant for the maximum value of t
const tmax = 1000000

// Define a constant for the maximum value of u
const umax = 1000000

// Define a constant for the maximum value of v
const vmax = 1000000

// Define a constant for the maximum value of w
const wmax = 1000000

// Define a constant for the maximum value of x
const xmax = 1000000

// Define a constant for the maximum value of y
const ymax = 1000000

// Define a constant for the maximum value of z
const zmax = 1000000

// Define a constant for the maximum value of a
const amax = 1000000

// Define a constant for the maximum value of b
const bmax = 1000000

// Define a constant for the maximum value of c
const cmax = 1000000

// Define a constant for the maximum value of d
const dmax = 1000000

// Define a constant for the maximum value of e
const emax = 1000000

// Define a constant for the maximum value of f
const fmax = 1000000

// Define a constant for the maximum value of g
const gmax = 1000000

// Define a constant for the maximum value of h
const hmax = 1000000

// Define a constant for the maximum value of i
const imax = 1000000

// Define a constant for the maximum value of j
const jmax = 1000000

// Define a constant for the maximum value of k
const kmax = 1000000

// Define a constant for the maximum value of l
const lmax = 1000000

// Define a constant for the maximum value of m
const mmax = 1000000

// Define a constant for the maximum value of n
const nmax = 1000000

// Define a constant for the maximum value of o
const omax = 1000000

// Define a constant for the maximum value of p
const pmax = 1000000

// Define a constant for the maximum value of q
const qmax = 1000000

// Define a constant for the maximum value of r
const rmax = 1000000

// Define a constant for the maximum value of s
const smax = 1000000

// Define a constant for the maximum value of t
const tmax = 1000000

// Define a constant for the maximum value of u
const umax = 1000000

// Define a constant for the maximum value of v
const vmax = 1000000

// Define a constant for the maximum value of w
const wmax = 1000000

// Define a constant for the maximum value of x
const xmax = 1000000

// Define a constant for the maximum value of y
const ymax = 1000000

// Define a constant for the maximum value of z
const zmax = 1000000

// Define a constant for the maximum value of a
const amax = 1000000

// Define a constant for the maximum value of b
const bmax = 1000000

// Define a constant for the maximum value of c
const cmax = 1000000

// Define a constant for the maximum value of d
const dmax = 1000000

// Define a constant for the maximum value of e
const emax = 1000000

// Define a constant for the maximum value of f
const fmax = 1000000

// Define a constant for the maximum value of g
const gmax = 1000000

// Define a constant for the maximum value of h
const hmax = 1000000

// Define a constant for the maximum value of i
const imax = 1000000

// Define a constant for the maximum value of j
const jmax = 1000000

// Define a constant for the maximum value of k
const kmax = 1000000

// Define a constant for the maximum value of l
const lmax = 1000000

// Define a constant for the maximum value of m
const mmax = 1000000

// Define a constant for the maximum value of n
const nmax = 1000000

// Define a constant for the maximum value of o
const omax = 1000000

// Define a constant for the maximum value of p
const pmax = 1000000

// Define a constant for the maximum value of q
const qmax = 1000000

// Define a constant for the maximum value of r
const rmax = 1000000

// Define a constant for the maximum value of s
const smax = 1000000

// Define a constant for the maximum value of t
const tmax = 1000000

// Define a constant for the maximum value of u
const umax = 1000000

// Define a constant for the maximum value of v
const vmax = 1000000

// Define a constant for the maximum value of w
const wmax = 1000000

// Define a constant for the maximum value of x
const xmax = 1000000

// Define a constant for the maximum value of y
const ymax = 1000000

// Define a constant for the maximum value of z
const zmax = 1000000

// Define a constant for the maximum value of a
const amax = 1000000

// Define a constant for the maximum value of b
const bmax = 1000000

// Define a constant for the maximum value of c
const cmax = 1000000

// Define a constant for the maximum value of d
const dmax = 1000000

// Define a constant for the maximum value of e
const emax = 1000000

// Define a constant for the maximum value of f
const fmax = 1000000

// Define a constant for the maximum value of g
const gmax = 1000000

// Define a constant for the maximum value of h
const hmax = 1000000

// Define a constant for the maximum value of i
const imax = 1000000

// Define a constant for the maximum value of j
const jmax = 1000000

// Define a constant for the maximum value of k
const kmax = 1000000

// Define a constant for the maximum value of l
const lmax = 1000000

// Define a constant for the maximum value of m
const mmax = 1000000

// Define a constant for the maximum value of n
const nmax = 1000000

// Define a constant for the maximum value of o
const omax = 1000000

// Define a constant for the maximum value of p
const pmax = 1000000

// Define a constant for the maximum value of q
const qmax = 1000000

// Define a constant for the maximum value of r
const rmax = 1000000

// Define a constant for the maximum value of s
const smax = 1000000

// Define a constant for the maximum value of t
const tmax = 1000000

// Define a constant for the maximum value of u
const umax = 1000000

// Define a constant for the maximum value of v
const vmax = 1000000

// Define a constant for the maximum value of w
const wmax = 1000000

// Define a constant for the maximum value of x
const xmax = 1000000

// Define a constant for the maximum value of y
const ymax = 1000000

// Define a constant for the maximum value of z
const zmax = 1000000

// Define a constant for the maximum value of a
const amax = 1000000

// Define a constant for the maximum value of b
const bmax = 1000000

// Define a constant for the maximum value of c
const cmax = 1000000

// Define a constant for the maximum value of d
const dmax = 1000000

// Define a constant for the maximum value of e
const emax = 1000000

// Define a constant for the maximum value of f
const fmax = 1000000

// Define a constant for the maximum value of g
const gmax = 1000000

// Define a constant for the maximum value of h
const hmax = 1000000

// Define a constant for the maximum value of i
const imax = 1000000

// Define a constant for the maximum value of j
const jmax = 1000000

// Define a constant for the maximum value of k
const kmax = 1000000

// Define a constant for the maximum value of l
const lmax = 1000000

// Define a constant for the maximum value of m
const mmax = 1000000

// Define a constant for the maximum value of n
const nmax = 1000000

// Define a constant for the maximum value of o
const omax = 1000000

// Define a constant for the maximum value of p
const pmax = 1000000

// Define a constant for the maximum value of q
const qmax = 1000000

// Define a constant for the maximum value of r
const rmax = 1000000

// Define a constant for the maximum value of s
const smax = 1000000

// Define a constant for the maximum value of t
const tmax = 1000000

// Define a constant for the maximum value of u
const umax = 1000000

// Define a constant for the maximum value of v
const vmax = 1000000

// Define a constant for the maximum value of w
const wmax = 1000000

// Define a constant for the maximum value of x
const xmax = 1000000

// Define a constant for the maximum value of y
const ymax = 1000000

// Define a constant for the maximum value of z
const zmax = 1000000

// Define a constant for the maximum value of a
const amax = 1000000

// Define a constant for the maximum value of b
const bmax = 1000000

// Define a constant for the maximum value of c
const cmax = 1000000

// Define a constant for the maximum value of d
const dmax = 1000000

// Define a constant for the maximum value of e
const emax = 1000000

// Define a constant for the maximum value of f
const fmax = 1000000

// Define a constant for the maximum value of g
const gmax = 1000000

// Define a constant for the maximum value of h
const hmax = 1000000

// Define a constant for the maximum value of i
const imax = 1000000

// Define a constant for the maximum value of j
const jmax = 1000000

// Define a constant for the maximum value of k
const kmax = 1000000

// Define a constant for the maximum value of l
const lmax = 1000000

// Define 