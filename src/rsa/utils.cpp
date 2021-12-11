#include <random>
#include <iostream>

#include "rsa/utils.hpp"

static bool seeded = false;

long generatePrime () {
    long i = 1;
    int count = 0;
    int n;

    if (!seeded) {
        srand (time(0));
        seeded = true;
    }

    n = rand() % MAX_PRIMES_INTERVAL;

    while (count < n) {
        if (isPrime(++i)) count++;
    }

    return i;
}


bool isPrime (long n) {
    bool response = true;

    for (int i = 2; i < n; i++) {
        if (n % i == 0) return false;
    }

    return response;
}

long expMod (long base, long exp, long mod) {
    long result = 1;

    for (int i = 0; i < exp; i++) result = ((result % mod) * (base % mod)) % mod;

    return result;
}

long generateRSAPublicKey (long q, long p, long e) {
    long m = (q - 1) * (p - 1);
    double d;
    long k = 0;

    do {
        d = (double)((double)m * (double)k + 1) / (double)e;
        k++;
    } while ((int)d != d || d == e);

    return (long)d;
}

long generateRSAPrivateKey (long q, long p) {
    long m = (q - 1) * (p - 1);
    int e;
    
    if (!seeded) {
        srand (time(0));
        seeded = true;
    }

    do {
        e = rand() % MAX_PRIVATE_KEY;
    } while (pgcd(e, m) != 1) ;

    return e;
}

long pgcd (long a, long b) {
    int result = 1;

    for (int i = 2; i <= a && i <= b; i++) {
        if (a % i == 0 && b % i == 0) result = i;
    }

    return result;
}