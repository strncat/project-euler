#include <iostream>
#include <math.h>
#include <algorithm>
#include <stdio.h>
#include <unordered_map>
#include <functional>
#include <utility>
#include <set>
#include <numeric>

#define N 10000

int isPalindrome(int n) {
    int reminder, reverse = 0, number = n;
    while (n > 0) {
        reminder = n % 10;
        reverse = reverse * 10 + reminder;
        n = n / 10;
    }
    return (reverse == number);
}

int largestPalindrome(int n) {
    int palindrome, largestPalindrome = 0;
    for (int i = 999; i >= 0; i--) {
        for (int j = i; j >= 0; j--) {
            if (i * j < largestPalindrome) { break; }
            palindrome = isPalindrome(i * j);
            if (palindrome && i * j > largestPalindrome && i * j <= n) {
                largestPalindrome = i * j;
            }
        }
    }
    return largestPalindrome;
}

int main(int argc, const char * argv[]) {
    clock_t begin, end;
    double time_spent;
    begin = clock();

    printf("%d\n", largestPalindrome(999999));

    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("time spent = %f\n", time_spent);
    return 0;
}
