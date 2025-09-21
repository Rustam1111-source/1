#include "edu_math.h"

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define UNIMPLEMENTED \
    do { \
        fprintf(stderr, "[ERROR] function %s is unimplemented\n", __func__); \
        abort(); \
    } while (0)

#define UNUSED(x) (void)(x)

int edu_add(int a, int b) {
    return a + b;
}

int edu_sub(int a, int b) {
    return a - b;
}

int edu_mult(int a, int b) {
    return a * b;
}

int edu_div(int a, int b) {
    if(b == 0) {
        return EXIT_FAILURE;
    }
    return a / b;
    return 0;
}

int edu_mod(int a, int b) {
    if (b == 0){
        return EXIT_FAILURE;
    }
    return a%b;
    return 0;
}

int edu_pow(int a, int b) {
    if (b < 0){
        return EXIT_FAILURE;
    }
    int result = 1;
    for (int i = 0; i < b; i++) {
        // Проверка переполнения целого числа
        if (result > INT_MAX / b && a > 0) {
           return EXIT_FAILURE;
        }
        result *= a;
    }
    return result;
}


int edu_abs(int a) {
    return (a < 0) ? -a :a;
}

int edu_gcd(int a, int b) {
    a = edu_abs(a);
    b = edu_abs(b);
    
    // Обработка случая, когда оба числа нули
    if (a == 0 && b == 0) return 0;
    
    // Алгоритм Евклида
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int edu_lcm(int a, int b) {
    if (a == 0 || b == 0) return 0;

    a = edu_abs(a);
    b = edu_abs(b);

    if (a > INT_MAX / b){
        return EXIT_FAILURE;
    }

    return (a * b) / edu_gcd(a,b);
}

int edu_int_sqrt(int a) {
    if (a < 0){
        return EXIT_FAILURE;
    }
    if (a == 0 || a == 1)return a;

    // Бинарный поиск для целочисленного квадратного корня
    int left = 1, right = a;
    int result = 0;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        // Проверка на переполнение
        if (mid > INT_MAX / mid) {
            right = mid - 1;
            continue;
        }
        int square = mid * mid;
        
        if (square == a) {
            return mid;
        } else if (square < a) {
            left = mid + 1;
            result = mid;
        } else {
            right = mid - 1;
        }
    }
    
    return result;
}


int edu_sgn(int a) {
    if (a > 0) return 1;
    if (a < 0) return -1;
    return 0;
}

int edu_fact(int a) {
    if (a < 0){
        return EXIT_FAILURE;
    }
    if (a == 0 || a == 1) return 1;

    int result = 1;
    for (int i = 2; i<=a;i++){

        if (result > INT_MAX / i){
            return EXIT_FAILURE;
        }
        result *= i;
    }
    return result;
    // int res = 1;
    // for(int i = 1; i <= a; ++i) {
    //     res *= i;
    // }
    // return res;
    // return 0;
}
