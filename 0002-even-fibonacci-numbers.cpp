//
//
//  Project Euler
//
//  Created by FB on 03/22/19..
//  02 Even Fibonacci Numbers https://projecteuler.net/problem=2
//
//

#include <iostream>
#include <math.h>
#include <algorithm>
#include <sstream>
#include <cassert>
#define N 35 // the 35th term exceeds 4 million

// only calculate even fibonacci numbers
unsigned long long even[N] = {0};
void fibonacci_even() {
    even[0] = 0; even[1] = 2;
    for (int i = 2; i < N; i++) {
        even[i] = 4*even[i-1] + even[i-2];
    }
}

// all fibonacci's terms
unsigned long long all[N] = {0};
void fibonacci_all() {
    all[0] = 0; all[1] = 1; all[2] = 1;
    for (int i = 3; i < 35; i++) {
        all[i] = all[i-1] + all[i-2];
    }
}

int main(int argc, const char * argv[]) {
    clock_t begin, end;
    double time_spent;
    begin = clock();
    
    fibonacci_all();
    unsigned long long sum = 0;
    for (int i = 0; i < N; i++) {
        if (all[i] % 2 == 0) {
            sum += all[i];
        }
    }
    printf("sum = %llu\n", sum);
    
    fibonacci_even();
    sum = 0;
    int i = 0;
    while (even[i] < 4000000) {
        sum += even[i++];
    }
    printf("sum = %llu\n", sum);
    
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("time spent = %f\n", time_spent);
    return 0;
}

