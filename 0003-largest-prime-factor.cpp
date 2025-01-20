//
//
//  Project Euler
//
//  Created by FB on 03/22/19.
//  03 Largest Prime Factor https://projecteuler.net/problem=3
//
//

#include <iostream>
#include <math.h>
#include <algorithm>
#include <sstream>
#include <cassert>

unsigned long long max_prime_factorization(unsigned long long n) {
    unsigned long long max = 1, i;
    // prime factor 2
    while (n % 2 == 0) {
        n /= 2;
        if (2 > max) {
            max = 2;
        }
    }
    // all the other prime factors
    // note here that while yes we check against factors like 9
    // we don't ever add 9 to the list of factors since we had checked against
    // 3 before checking against 9!
    int limit = sqrt(n);
    for (i = 3; i <= limit; i += 2) {
        while (n % i == 0) {
            if (i > max) {
                max = i;
            }
            n /= i;
            //printf("prime factor = %llu\n", i);
        }
    }
    if (n > 2 && n > max) {
        max = n;
    }
    return max;
}

int main(int argc, const char * argv[]) {
    clock_t begin, end;
    double time_spent;
    begin = clock();
    
    unsigned long long n = 600851475143;
    unsigned long long largest_factor;
    largest_factor = max_prime_factorization(n);
    printf("%llu\n", largest_factor);
    
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("time spent = %f\n", time_spent);
    return 0;
}

