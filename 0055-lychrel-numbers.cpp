//
//
//  Project Euler
//
//  Created by FB on 01/21/25
//  Problem 55: Lychrel Numbers https://projecteuler.net/problem=55
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

void add_vectors(std::vector<int> &a, std::vector<int> &b) {
    int carry = 0;
    for (int i = 0; i < a.size(); i++) {
        int cur = a[i];
        a[i] = (cur + b[i] + carry) % 10;
        carry = (cur + b[i] + carry) / 10;
    }
    // there shouldn't be carry left yet with 100 digits!
    assert(carry == 0);
}

bool is_palindrome(std::vector<int> &digits) {
    long size = 0;
    for (long i = digits.size() - 1; i >= 0; i--) {
        if (digits[i] != 0) { // first most significant digit
            size = i;
            break;
        }
    }
    long i = 0, j = size;
    while (i < j) {
        if (digits[i] != digits[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

void reverse_significant_digits(std::vector<int>& num, std::vector<int>& reversed) {
    int index = 0;
    for (long i = num.size() - 1; i >= 0; i--) {
        if (num[i] != 0 || index > 0) {
            reversed[index++] = num[i];
        }
    }
}

bool is_lychrel(std::vector<int>& num) {
    // less than 50 tries at most
    int tries = 49;

    while (tries--) {
        std::vector<int> reversed(num.size(), 0);
        reverse_significant_digits(num, reversed);

        add_vectors(num, reversed); // add result back in original
        if (is_palindrome(num)) {
            return false;
        }
    }
    return true; // after 49 iterations, we're still not a palindrome so we're lychrel
}

int main(int argc, const char * argv[]) {
    clock_t begin, end;
    double time_spent;
    begin = clock();

    int count = 0;
    for (int i = 0; i < 10000; i++) {
        // covert i to a vector
        std::vector<int> num(100, 0);
        int index = 0;
        int n = i;
        while (n > 0) {
            num[index++] = n%10;
            n /= 10;
        }
        
        if (is_lychrel(num)) {
            //printf("%d is lychrel\n", i);
            count++;
        }
    }
    printf("%d\n", count);

    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("time spent = %f\n", time_spent);
    return 0;
}
