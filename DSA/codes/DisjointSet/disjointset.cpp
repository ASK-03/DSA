#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
private:
    vector<int> size, rank, parent;
    int n;
    bool disjointSetByRank;
public:
    DisjointSet(int n, bool disjointSetByRank): n(n), disjointSetByRank(disjointSetByRank) {
        if(disjointSetByRank){
            rank.resize(n+1);
            parent.resize(n+1);
            for(int i=0; i<=n; i++) {
                parent[i] = i;
                rank[i] = 1;
            }
            return;
        }

        size.resize(n+1);
        parent.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUParent(int node){
        if(parent[node] == node) return node;
        return parent[node] = findUParent(parent[node]);
    }

    void unionByRank(int u, int v){
        assert(disjointSetByRank == true && "Wrong Function Call! This is a disjointset with union with size");
        int ult_u = findUParent(u);
        int ult_v = findUParent(v);
        if(ult_u == ult_v) return;
        else {
            if(rank[ult_u] > rank[ult_v]) {
                parent[ult_v] = ult_u;
            }
            else if(rank[ult_v] > rank[ult_u]) {
                parent[ult_u] = ult_v;
            }
            else {
                parent[ult_u] = ult_v;
                rank[ult_v]++;
            }
        }
        return;
    }    

    void unionBySize(int u, int v) {
        assert(disjointSetByRank == false && "Wrong Function Call! This is a disjointset with union with rank");
        int ult_u = findUParent(u);
        int ult_v = findUParent(v);
        if(ult_u == ult_v) return;
        if(size[ult_u] > size[ult_v]) {
            parent[ult_v] = ult_u;
            size[ult_u]+=size[ult_v];
        }
        else {
            parent[ult_u] = ult_v;
            size[ult_v]+=size[ult_u];
        }
        return;
    }
};

int main(){
    DisjointSet ds(7, false);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    // if 3 and 7 same or not
    if (ds.findUParent(3) == ds.findUParent(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    ds.unionBySize(3, 7);

    if (ds.findUParent(3) == ds.findUParent(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";
    return 0;
}