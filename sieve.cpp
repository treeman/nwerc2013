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
