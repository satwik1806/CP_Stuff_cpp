int spf[mxn];

void precompute() {
    for (int i = 0; i < mxn; i++) spf[i] = 1;

    for (int i = 2; i < mxnli++) {
        if (spf[i] == 1) {
            spf[i] = i;
            for (int j = 2 * i; j < mxn; j += i)
                spf[j] = i;
        }
    }
}

void pf(int n) {
    vector<int> res;
    while (n != 1) {
        int p = spf[n];
        res.push_back(p);
        n /= p;
    }
    return res;
}