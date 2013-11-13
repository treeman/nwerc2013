// 100 first primes
2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97 101
103 107 109 113 127 131 137 139 149 151 157 163 167 173 179 181 191 193 197
199 211 223 227 229 233 239 241 251 257 263 269 271 277 281 283 293 307 311
313 317 331 337 347 349 353 359 367 373 379 383 389 397 401 409 419 421 431
433 439 443 449 457 461 463 467 479 487 491 499 503 509 521 523 541

// Some larger primes
104729 1299709 9999991 15485863 179424673 2147483647 32416190071
112272535095293 54673257461630679457

// prime sieve with prime checking
const int MAX_SIEVE = 1e7; // 1e7 in a few seconds

ll _sieve_size;
bitset<MAX_SIEVE + 10> bs;
vi primes;

void sieve(ll upperbound) {
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i <= _sieve_size; ++i)
        if (bs[i]) {
            for (ll j = i * i; j <= _sieve_size; j += i)
                bs[j] = 0;
            primes.push_back((int)i);
        }
}

bool isPrime(ll N) { // works for N <= (last prime in primes)^2
    if (N <= _sieve_size) return bs[N]; // O(1) sieve check for small primes
    for (int i = 0; i < (int)primes.size(); ++i) // brute force for larger
        if (N % primes[i] == 0) return false;
    return true; // more time if N is prime!
}
