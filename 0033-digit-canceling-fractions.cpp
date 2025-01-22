//
//
//  Project Euler
//
//  Created by FB on 01/21/25.
//  Problem 33: Digit Cancelling Fractions https://projecteuler.net/problem=33
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

int main(int argc, const char * argv[]) {
    clock_t begin, end;
    double time_spent;
    begin = clock();

    // There are exactly four non-trivial examples of this type of fraction,
    // (1) less than one in value,
    // (2) and containing two digits in the numerator and denominator.

    int numerator = 1;
    int denominator = 1;
    for (int num = 10; num <= 99; num++) {
        for (int den = num+1; den <= 99; den++) {
            int n1 = num % 10;
            int n2 = num / 10;
            int d1 = den % 10;
            int d2 = den / 10;
            //
            if (n2 == d2 || n1 == d1) {
                continue; // even if it works, this is a trivial example
            }
            if (n1 == d2 || n2 == d1) {
                // example is 49/98. this will simplify to 4/8
                // now we want to check if 49/98 == 4/8 -> 49*8 == 98*4
                if (den * n2 == num * d1 || den * n1 == num * d2) {
                    printf("%d / %d\n", num, den);
                    numerator *= num;
                    denominator *= den;
                }
            }
        }
    }
    int gcd = std::gcd(numerator,denominator);
    printf("denominator = %d\n", denominator/gcd);

    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("time spent = %f\n", time_spent);
    return 0;
}
