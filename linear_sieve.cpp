const int N = 10000000;
int spf[N + 1];
void precompute(){
    for (int i = 2; i <= N; ++i){
        if (spf[i] == 0){
            spf[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= spf[i] && i * pr[j] <= N; ++j)
            spf[i * pr[j]] = pr[j];
    }
}

vector<int> getprimes(int x){
    vector<int> temp;
    while(x != 1){
        temp.push_back(spf[x]);
        x/=spf[x];
    }
    return temp;
}
