//zeta transform
for(int i = 0; i < N; i++) {
    for(int mask = 0; mask < (1 << N); mask++) {
        if((mask & (1 << i)) != 0) {
            f[mask] += f[mask ^ (1 << i)];
        }
    }
}

//mobius transform
// Apply odd-negation transform
for(int mask = 0; mask < (1 << N); mask++) {
    if((__builtin_popcount(mask) % 2) == 1) {
        f[mask] *= -1;
    }
}

// Apply zeta transform
for(int i = 0; i < N; i++) {
    for(int mask = 0; mask < (1 << N); mask++) {
        if((mask & (1 << i)) != 0) {
            f[mask] += f[mask ^ (1 << i)];
        }
    }
}

// Apply odd-negation transform
for(int mask = 0; mask < (1 << N); mask++) {
    if((__builtin_popcount(mask) % 2) == 1) {
        f[mask] *= -1;
    }
}
for(int mask = 0; mask < (1 << N); mask++)  mu[mask] = f[mask];
