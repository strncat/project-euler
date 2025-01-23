//
//
//  Project Euler
//
//  Created by FB on 01/21/19.
//  Problem 59: XOR Decryption https://projecteuler.net/problem=5
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

int main(int argc, const char * argv[]) {
    freopen("0059_cipher.txt" , "r" , stdin);
    clock_t begin, end;
    double time_spent;
    begin = clock();

    std::vector<char> encrypted;
    std::string str;
    std::cin >> str; // read the entire string
    std::stringstream ss(str);
    std::string token;
    char delimiter = ',';
    while (std::getline(ss, token, delimiter)) {
        int value = std::stoi(token);
        encrypted.push_back(value);
    }

    int key_length = 3;
    int sum = 0;
    for (char i = 'a'; i <= 'z'; i++) {
        for (char j = 'a'; j <= 'z'; j++) {
            for (char k = 'a'; k <= 'z'; k++) {
                std::vector<char> key = {i, j, k};
                // (1) try this key here
                std::vector<char> decrypted;
                bool valid = true; // by default, this will be a valid result
                for (int w = 0; w < encrypted.size(); w++) {
                    // If the password is shorter than the message, the key is repeated cyclically throughout the message.
                    char c = key[w % key_length] ^ encrypted[w];
                    if (std::isalnum(c) || c == '`' || c == '(' || c == ')' || c == ' ' || c == '?' ||
                        c == '!' || c == '.' || c == ',' || c == ';' || c == ':' || c == '-' ||
                        c == '\'' || c == '"' || c == '\\' || c == '/' || c == '[' || c == ']' || c == '+') {
                        decrypted.push_back(c);
                    } else {
                        valid = false;
                        break;
                    }
                }
                // (2) after we finish trying the key, we'll check if we have a valid result
                if (valid) {
                    printf("WORKS\n");
                    for (int i = 0; i < decrypted.size(); i++) {
                        printf("%c", decrypted[i]);
                        sum += decrypted[i];
                    }
                    break;
                }
            }
        }
    }
    printf("sum = %d\n", sum);

    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("time spent = %f\n", time_spent);
    return 0;
}
