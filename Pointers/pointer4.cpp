//
// Created by Marius on 7/17/2017.
//
#include <iostream>
#include <cstdio>

int main() {
    char str1[] = "Hello";
    char str2[] = "World";
    char *s1 = str1, *s2 = str2;

    while (*s1++ = *s2++) {
        printf("%s ", str1);
    }
    printf("\n");
    return 0;
}

