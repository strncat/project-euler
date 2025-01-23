//
//
//  Project Euler
//
//  Created by FB on 01/23/25.
//  Problem 69: Totient Maximum https://projecteuler.net/problem=69
//
//

#include <iostream>
#include <math.h>
#include <algorithm>
#include <stdio.h>
#include <unordered_map>
#include <functional>
#include <utility>
#include <set>
#include <numeric>
#include <cassert>
#include <sstream>
#include <string>

#define N 10000000

int prime[N];

void sieve() {
    // mark all numbers as potential primes
    for (int i = 0; i < N; i++) {
        prime[i] = 1;
    }
    prime[0] = prime[1] = 0;
    int limit = sqrt(N);
    for (int p = 2; p <= limit; p++) {
        if (prime[p]) {
            // mark all multiples of p as not prime
            for (int i = p*p; i < N; i += p) {
                prime[i] = 0;
            }
        }
    }
}

void prime_factorization(int n, std::set<int>& factors) {
    // prime factor 2
    while (n % 2 == 0) {
        n /= 2;
        factors.insert(2);
    }
    // all the other prime factors
    int limit = sqrt(n);
    for (int i = 3; i <= limit; i += 2) {
        while (n % i == 0) {
            factors.insert(i);
            n /= i;
        }
    }
    // n is prime itself
    if (n > 2) {
        factors.insert(n);
    }
}

int main(int argc, const char * argv[]) {
    clock_t begin, end;
    double time_spent;
    begin = clock();

    sieve();

    double max = 0.0;
    int n = 0;
    for (int i = 1000000; i > 0; i--) {
        if (!prime[i]) {
            std::set<int> factors;
            prime_factorization(i, factors);
            double tot = 1;
            //printf("%d: ", i);
            for (auto e = factors.begin(); e != factors.end(); e++) {
                    //printf("%d, ", *e);
                tot *= *e / (*e - 1.0);
            }
            if (tot > max) {
                max = tot;
                n = i;
            }
            //printf("tot = %f \n", tot);
        }
    }

    printf("max n = %d\n", n);

    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("time spent = %f\n", time_spent);
    return 0;
}
