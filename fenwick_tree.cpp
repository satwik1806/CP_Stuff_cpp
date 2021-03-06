template <typename T>
class BinaryIndexedTree {
private:
	vector<T> data;
public:
	BinaryIndexedTree(int n = 0) : data(n + 1) { }
	T sum(int i) {
		T s = T();
		for (; i > 0; i -= i & -i) { s += data[i]; }
		return s;
	}
	void add(int i, const T &x) {
		for (++i; i < static_cast<int>(data.size()); i += i & -i) {
			data[i] += x;
		}
	}
};