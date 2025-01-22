//
//
//  Project Euler
//
//  Created by FB on 01/21/19.
//  Problem 05: Smallest Multiple https://projecteuler.net/problem=5
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

long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return b * a / gcd(a,b); // or we can use std::gcd in <numeric>
}

int main(int argc, const char * argv[]) {
    clock_t begin, end;
    double time_spent;
    begin = clock();

    long long n = 20, multiple;
    multiple = 1;
    for (int i = 2; i <= n; i++) {
        multiple = lcm(multiple, i);
    }
    printf("%llu\n", multiple);

    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("time spent = %f\n", time_spent);
    return 0;
}
