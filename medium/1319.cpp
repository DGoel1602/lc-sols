struct DSU {
    int n;
    vector<int> p, sizes;
    DSU(int num): sizes(num, 1) {
        n = num;
        p.reserve(num);
        for(int i = 0; i<num; i++) p.push_back(i);
    }

    int find(int x){
        if(x == p[x]) return x;
        p[x] = find(p[x]);
        return p[x];
    }

    void join(int a, int b){
        a = find(a); b = find(b);
        if(a == b) return;

        if(sizes[a] < sizes[b]) swap(a, b);

        p[b] = a;
        sizes[a] += sizes[b];
        n--;
    }
};


class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() + 1 < n) return -1;

        DSU dsu(n);        
        for(vector<int> con: connections) dsu.join(con[0], con[1]);
        return dsu.n-1;
    }
};