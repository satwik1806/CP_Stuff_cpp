const int max_n = 5e5;
int fact[max_n + 1]; int inv_fact[max_n + 1];

void precalculate(){
    fact[0] = 1;
    for(int i=1;i<=max_n;i++){
        fact[i] = i * fact[i-1];
        fact[i] %= mod;
    }
    inv_fact[max_n] = power(fact[max_n],mod-2,mod);
    for(int i = max_n-1; i>=0;i--){
        inv_fact[i] = inv_fact[i + 1] * (i + 1);
        inv_fact[i] %= mod;
    }
}

int ncr_mod(int nn, int r){
    int res = 1;
    while(nn or r){
        int a = nn%mod; int b = r%mod;
        if(a < b) return 0;
        res = res * fact[a] % mod * inv_fact[b] % mod * inv_fact[a - b] % mod;
        nn /= mod; r/= mod;
    }
    return res;
}
