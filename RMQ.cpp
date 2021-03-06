//Range Queries.
// Author - Satwik_Tiwari
template<typename T>
class RangeQuery{
private:
    vector<vector<T>> data;
public:
    RangeQuery(vector<T> &arr){ // make sure not to pass a global vector of size = mxn.
        vector<int> temp; int n = arr.size();
        for(int i=0;i<n;i++){
            temp.push_back(arr[i]);
        }
        data.push_back(temp);
        int i = 1;
        while(2*i <= n){
            vector<int> prev = data[size(data)-1];
            vector<int> put;
            for(int j=0;j<n-2*i+1;j++){
                put.push_back(func(prev[j],prev[j + i]));
            }
            data.push_back(put);
            i <<= 1;
        }
    }

    T func(T aa, T ab){ // change it according to you.
        return max(aa,ab);
    }

    T query(int st,int end){ // ask queries like query[st,end].
        int bits; end++; int x = end - st;
        for(bits = 0;x != 0; ++ bits) x >>= 1; bits--;
        return (func(data[bits][st],data[bits][end - (1 << bits)]));
    }

    T getitem(int idx){
        return (data[0][idx]);
    }
};
