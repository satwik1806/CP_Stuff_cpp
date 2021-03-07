// Fenwick tree. kindaa dynamic prefix sum
// author - Satwik_Tiwari
int a[mxn];
template <typename T>
class BinaryIndexedTree {
private:
    vector<T> data;
public:
    BinaryIndexedTree(int n) : data(n) {
        for (int i = 0; i < n; i++) data[i] = a[i];
        for (int i = 0; i < n; i++) {
            int j = i | (i + 1);
            if (j < n)
                data[j] += data[i];
        }
    }

    T sum(int i) { // ask queries like [0,i)
        T s = T();
        s = 0;
        while (i) {
            s += data[i - 1];
            i &= i - 1;
        }
        return s;
    }

    void update(int i, const T &x) { // bit[i] += x
        while (i < size(data)) {
            data[i] += x;
            i |= i + 1;
        }
    }

    //for binary searching in fenwick tree.
    T findkth(int k) { // find largest index such that the sum(idx) <= k
        int ind = -1; int x = size(data);
        int bits;
        for (bits = 0; x != 0; ++ bits) x >>= 1;
        for (int d = bits - 1; d >= 0; d--) {
            int right_ind = ind + (1 << d);
            if (right_ind < size(data) && k >= data[right_ind]) {
                ind = right_ind;
                k -= data[ind];
            }
        }
        return (T)ind; // return -1 if k < sum(1).
    }

    void printpref() { //for debugging incase. don't forget to commentout.
        vector<int> out;
        for (int i = 1; i <= size(data); i++) out.push_back(sum(i));
        debug(out);
    }
};

//update array a in main.