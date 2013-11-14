// find position and length of the repeated pattern in a generated sequence
ii floydCycleFinding(int x0) { // define int f(int x) which generates the sequence
    // 1st phase, hare 2x speed of turtoise
    int tortoise = f(x0), hare = f(f(x0));
    while (tortoise != hare) { tortoise = f(tortoise); hare = f(f(hare)); }
    // 2nd phase, find mu, same speed
    int mu = 0; hare = x0;
    while (tortoise != hare) { tortoise = f(tortoise); hare = f(hare); ++mu; }
    // 3rd phase, find lambda, hare moves tortoise still
    int lambda = 1; hare = f(tortoise);
    while (tortoise != hare) { hare = f(hare); ++lambda; }
    return ii(mu, lambda); // mu: start of cycle, lambda: cycle length
}
