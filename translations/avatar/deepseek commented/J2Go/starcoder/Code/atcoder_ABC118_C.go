
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the number of integers")
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	a := make([]int, n)
	fmt.Println("Enter the integers")
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	}
	if n == 1 {
		fmt.Println(a[0])
		return
	}
	a = func(a []int) []int {
		min := 0
		for i := 0; i < len(a); i++ {
			if a[i] == 0 {
				a = append(a[:i], a[i+1:]...)
				i--
			} else {
				if min!= 0 {
					a[i] = a[i] % min
					if a[i] == 1 {
						fmt.Println(1)
						return a
					}
				} else {
					min = a[i]
				}
			}
		}
		sort.Ints(a)
		return a
	}
	for {
		a = func(a []int) []int {
			min := 0
			for i := 0; i < len(a); i++ {
				if a[i] == 0 {
					a = append(a[:i], a[i+1:]...)
					i--
				} else {
					if min!= 0 {
						a[i] = a[i] % min
						if a[i] == 1 {
							fmt.Println(1)
							return a
						}
					} else {
						min = a[i]
					}
				}
			}
			sort.Ints(a)
			return a
		}
		a = func(a []int) []int {
			min := 0
			for i := 0; i < len(a); i++ {
				if a[i] == 0 {
					a = append(a[:i], a[i+1:]...)
					i--
				} else {
					if min!= 0 {
						a[i] = a[i] % min
						if a[i] == 1 {
							fmt.Println(1)
							return a
						}
					} else {
						min = a[i]
					}
				}
			}
			sort.Ints(a)
			return a
		}
		a = func(a []int) []int {
			min := 0
			for i := 0; i < len(a); i++ {
				if a[i] == 0 {
					a = append(a[:i], a[i+1:]...)
					i--
				} else {
					if min!= 0 {
						a[i] = a[i] % min
						if a[i] == 1 {
							fmt.Println(1)
							return a
						}
					} else {
						min = a[i]
					}
				}
			}
			sort.Ints(a)
			return a
		}
		a = func(a []int) []int {
			min := 0
			for i := 0; i < len(a); i++ {
				if a[i] == 0 {
					a = append(a[:i], a[i+1:]...)
					i--
				} else {
					if min!= 0 {
						a[i] = a[i] % min
						if a[i] == 1 {
							fmt.Println(1)
							return a
						}
					} else {
						min = a[i]
					}
				}
			}
			sort.Ints(a)
			return a
		}
		a = func(a []int) []int {
			min := 0
			for i := 0; i < len(a); i++ {
				if a[i] == 0 {
					a = append(a[:i], a[i+1:]...)
					i--
				} else {
					if min!= 0 {
						a[i] = a[i] % min
						if a[i] == 1 {
							fmt.Println(1)
							return a
						}
					} else {
						min = a[i]
					}
				}
			}
			sort.Ints(a)
			return a
		}
		a = func(a []int) []int {
			min := 0
			for i := 0; i < len(a); i++ {
				if a[i] == 0 {
					a = append(a[:i], a[i+1:]...)
					i--
				} else {
					if min!= 0 {
						a[i] = a[i] % min
						if a[i] == 1 {
							fmt.Println(1)
							return a
						}
					} else {
						min = a[i]
					}
				}
			}
			sort.Ints(a)
			return a
		}
		a = func(a []int) []int {
			min := 0
			for i := 0; i < len(a); i++ {
				if a[i] == 0 {
					a = append(a[:i], a[i+1:]...)
					i--
				} else {
					if min!= 0 {
						a[i] = a[i] % min
						if a[i] == 1 {
							fmt.Println(1)
							return a
						}
					} else {
						min = a[i]
					}
				}
			}
			sort.Ints(a)
			return a
		}
		a = func(a []int) []int {
			min := 0
			for i := 0; i < len(a); i++ {
				if a[i] == 0 {
					a = append(a[:i], a[i+1:]...)
					i--
				} else {
					if min!= 0 {
						a[i] = a[i] % min
						if a[i] == 1 {
							fmt.Println(1)
							return a
						}
					} else {
						min = a[i]
					}
				}
			}
			sort.Ints(a)
			return a
		}
		a = func(a []int) []int {
			min := 0
			for i := 0; i < len(a); i++ {
				if a[i] == 0 {
					a = append(a[:i], a[i+1:]...)
					i--
				} else {
					if min!= 0 {
						a[i] = a[i] % min
						if a[i] == 1 {
							fmt.Println(1)
							return a
						}
					} else {
						min = a[i]
					}
				}
			}
			sort.Ints(a)
			return a
		}
		a = func(a []int) []int {
			min := 0
			for i := 0; i < len(a); i++ {
				if a[i] == 0 {
					a = append(a[:i], a[i+1:]...)
					i--
				} else {
					if min!= 0 {
						a[i] = a[i] % min
						if a[i] == 1 {
							fmt.Println(1)
							return a
						}
					} else {
						min = a[i]
					}
				}
			}
			sort.Ints(a)
			return a
		}
		a = func(a []int) []int {
			min := 0
			for i := 0; i < len(a); i++ {
				if a[i] == 0 {
					a = append(a[:i], a[i+1:]...)
					i--
				} else {
					if min!= 0 {
						a[i] = a[i] % min
						if a[i] == 1 {
							fmt.Println(1)
							return a
						}
					} else {
						min = a[i]
					}
				}
			}
			sort.Ints(a)
			return a
		}
		a = func(a []int) []int {
			min := 0
			for i := 0; i < len(a); i++ {
				if a[i] == 0 {
					a = append(a[:i], a[i+1:]...)
					i--
				} else {
					if min!= 0 {
						a[i] = a[i] % min
						if a[i] == 1 {
							fmt.Println(1)
							return a
						}
					} else {
						min = a[i]
					}
				}
			}
			sort.Ints(a)
			return a
		}
		a = func(a []int) []int {
			min := 0
			for i := 0; i < len(a); i++ {
				if a[i] == 0 {
					a = append(a[:i], a[i+1:]...)
					i--
				} else {
					if min!= 0 {
						a[i] = a[i] % min
						if a[i] == 1 {
							fmt.Println(1)
							return a
						}
					} else {
						min = a[i]
					}
				}
			}
			sort.Ints(a)
			return a
		}
		a = func(a []int) []int {
			min := 0
			for i := 0; i < len(a); i++ {
				if a[i] == 0 {
					a = append(a[:i], a[i+1:]...)
					i--
				} else {
					if min!= 0 {
						a[i] = a[i] % min
						if a[i] == 1 {
							fmt.Println(1)
							return a
						}
					} else {
						min = a[i]
					}
				}
			}
			sort.Ints(a)
			return a
		}
		a = func(a []int) []int {
			min := 0
			for i := 0; i < len(a); i++ {
				if a[i] == 0 {
					a = append(a[:i], a[i+1:]...)
					i--
				} else {
					if min!= 0 {
						a[i] = a[i] % min
						if a[i] == 1 {
							fmt.Println(1)
							return a
						}
					} else {
						min = a[i]
					}
				}
			}
			sort.Ints(a)
			return a
		}
		a = func(a []int) []int {
			min := 0
			for i := 0; i < len(a); i++ {
				if a[i] == 0 {
					a = append(a[:i], a[i+1:]...)
					i--
				} else {
					if min!= 0 {
						a[i] = a[i] % min
						if a[i] == 1 {
							fmt.Println(1)
							return a
						}
					} else {
						min = a[i]
					}
				}
			}
			sort.Ints(a)
			return a
		}
		a = func(a []int) []int {
			min := 0
			for i := 0; i < len(a); i++ {
				if a[i] == 0 {
					a = append(a[:i], a[i+1:]...)
					i--
				} else {
					if min!= 0 {
						a[i] = a[i] % min
						if a[i] == 1 {
							fmt.Println(1)
							return a
						}
					} else {
						min = a[i]
					}
				}
			}
			sort.Ints(a)
			return a
		}
		a = func(a []int) []int {
			min := 0
			for i := 0; i < len(a); i++ {
				if a[i] == 0 {
					a = append(a[:i], a[i+1:]...)
					i--
				} else {
					if min!= 0 {
						a[i] = a[i] % min
						if a[i] == 1 {
							fmt.Println(1)
							return a
						}
					} else {
						min = a[i]
					}
				}
			}
			sort.Ints(a)
			return a
		}
		a = func(a []int) []int {
			min := 0
			for i := 0; i < len(a); i++ {
				if a[i] == 0 {
					a = append(a[:i], a[i+1:]...)
					i--
				} else {
					if min!= 0 {
						a[i] = a[i] % min
						if a[i] == 1 {
							fmt.Println(1)
							return a
						}
					} else {
						min = a[i]
					}
				}
			}
			sort.Ints(a)
			return a
		}
		a = func(a []int) []int {
			min := 0
			for i := 0; i < len(a); i++ {
				if a[i] == 0 {
					a = append(a[:i], a[i+1:]...)
					i--
				} else {
					if min!= 0 {
						a[i] = a[i] % min
						if a[i] == 1 {
							fmt.Println(1)
							return a
						}
					} else {
						min = a[i]
					}
				}
			}
			sort.Ints(a)
			return a
		}
		a = func(a []int) []int {
			min := 0
			for i := 0; i < len(a); i++ {
				if a[i] == 0 {
					a = append(a[:i], a[i+1:]...)
					i--
				} else {
					if min!= 0 {
						a[i] = a[i] % min
						if a[i] == 1 {
							fmt.Println(1)
							return a
						}
					} else {
						min = a[i]
					}
				}
			}
			sort.Ints(a)
			return a
		}
		a = func(a []int) []int {
			min := 0
			for i := 0; i < len(a); i++ {
				if a[i] == 0 {
					a = append(a[:i], a[i+1:]...)
					i--
				} else {
					if min!= 0 {
						a[i] = a[i] % min
						if a[i] == 1 {
							fmt.Println(1)
							return a
						}
					} else {
						min = a[i]
					}
				}
			}
			sort.Ints(a)
			return a
		}
		a = func(a []int) []int {
			min := 0
			for i := 0; i < len(a); i++ {
				if a[i] == 0 {
					a = append(a[:i], a[i+1:]...)
					i--
				} else {
					if min!= 0 {
						a[i] = a[i] % min
						if a[i] == 1 {
							fmt.Println(1)
							return a
						}
					} else {
						min = a[i]
					}
				}
			}
			sort.Ints(a)
			return a
		}
		a = func(a []int) []int {
			min := 0
			for i := 0; i < len(a); i++ {
				if a[i] == 0 {
					a = append(a[:i], a[i+1:]...)
					i--
				} else {
					if min!= 0 {
						a[i] = a[i] % min
						if a[i] == 1 {
							fmt.Println(1)
							return a
						}
					} else {
						min = a[i]
					}
				}
			}
			sort.Ints(a)
			return a
		}
		a = func(a []int) []int {
			min := 0
			for i := 0; i < len(a); i++ {
				if a[i] == 0 {
					a = append(a[:i], a[i+1:]...)
					i--
				} else {
					if min!= 0 {
						a[i] = a[i] % min
						if a[i] == 1 {
							fmt.Println(1)
							return a
						}
					} else {
						min = a[i]
					}
				}
			}
			sort.Ints(a)
			return a
		}
		a = func(a []int) []int {
			min := 0
			for i := 0; i < len(a); i++ {
				if a[i] == 0 {
					a = append(a[:i], a[i+1:]...)
					i--
				} else {
					if min!= 0 {
						a[i] = a[i] % min
						if a[i] == 1 {
							fmt.Println(1)
							return a
						}
					} else {
						min = a[i]
					}
				}
			}
			sort.Ints(a)
			return a
		}
		a = func(a []int) []int {
			min := 0
			for i := 0; i < len(a); i++ {
				if a[i] == 0 {
					a = append(a[:i], a[i+1:]...)
					i--
				} else {
					if min!= 0 {
						a[i] = a[i] % min
						if a[i] == 1 {
							fmt.Println(1)
							return a
						}
					} else {
						min = a[i]
					}
				}
			}
			sort.Ints(a)
			return a
		}
		a = func(a []int) []int {
			min := 0
			for i := 0; i < len(a); i++ {
				if a[i] == 0 {
					a