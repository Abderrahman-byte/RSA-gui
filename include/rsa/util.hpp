#ifndef _RSAUTILS_H_ 
#define _RSAUTILS_H_ 1

#define MAX_PRIMES_INTERVAL 100
#define MAX_PRIVATE_KEY 400

extern long generatePrime ();
extern bool isPrime (long);
extern long expMod (long, long, long);
extern long generateRSAPrivateKey (long, long);
extern long generateRSAPublicKey (long, long, long);
extern long pgcd (long, long);
extern bool checkPublicKey (long, long, long, long);

#endif
