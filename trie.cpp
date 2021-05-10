typedef struct data
{
    data* bit[2];
    int pref_cnt = 0; //0 means nothing here
}trie;
trie* head;

void insert(int x){
    trie* curr = head;
    for(int i=31;i>=0;i--){
        int b = (x >> i) & 1;
        if(!curr->bit[b]) curr->bit[b] = new trie();
        curr = curr->bit[b];
        curr->pref_cnt++;
    }
}

void remove(int x){
    trie* curr = head;
    for(int i=31;i>=0;i--){
        int b = (x >> i) & 1;
        curr = curr->bit[b];
        curr->pref_cnt--;
    }
}

int find_maxxor(int x){
    trie* curr = head;
    int ans = 0;
    for(int shift = 31; shift >= 0; shift--){
        int b = (x >> shift) & 1;
        if(curr->bit[1-b] and curr->bit[1-b]->pref_cnt){
            ans = ans | (1 << shift);
            curr = curr->bit[1-b];
        }
        else curr = curr->bit[b];
        if(curr->pref_cnt == 0) break;
    }
    return ans;
}

// head = new trie(); don't forget to initiate head.
