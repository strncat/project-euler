//
//
//  Project Euler
//
//  Created by FB on 01/18/25.
//  50 Consecutive Prime Sum https://projecteuler.net/problem=50
//
//

#include <iostream>
#include <math.h>
#include <algorithm>
#include <sstream>
#include <cassert>
#define N 1000000

int prime[N];
std::vector<int> prime_numbers;
std::unordered_map<int,int> consecutive_sums;

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

void prime_sums() {
    int sum = 0;
    prime_numbers.push_back(0); // fake prime
    consecutive_sums[0] = 0;
    for (int i = 0; i < N; i++) {
        if (prime[i]) {
            sum += i;
            prime_numbers.push_back(i);
            consecutive_sums[i] = sum;
            if (prime_numbers.size() >  546) {
                break; // we don't need more than that!
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    clock_t begin, end;
    double time_spent;
    begin = clock();
    
    sieve();
    prime_sums();

    int p = 0;
    int max = 0;
    for (int i = prime_numbers.size() - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            int first = prime_numbers[i];
            int second = prime_numbers[j];
            int cons_sum = consecutive_sums[first] - consecutive_sums[second];
            if (prime[cons_sum] && max < abs(i - j)) {
                p = cons_sum;
                max = abs(i - j);
            }
        }
    }

    printf("%d\n", p);

    
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("time spent = %f\n", time_spent);
    return 0;
}

