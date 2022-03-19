#include <bits/stdc++.h>
using namespace std;

const int L = 30;

struct SegTreePersistent {
    struct Node {
        long long x;

        static auto join(Node const& lhs, Node const& rhs) -> Node {
            return {lhs.x + rhs.x};
        }

        Node update(Node rhs) {
            Node ret;
			ret.x = this->x + rhs.x;
        }
    };

    int n;
	int nodes = 0;
    vector<Node> tree;
	vector<int> L,R;
	Node ZERO; //o que deve retorna se vazio

    SegTree(int n, int q) :
        n(n), tree(q*L+5), L(q*L+5), R(q*L+5)
    {};

    auto get(int no, int l, int r, int a, int b) -> Node {
        if (a <= l and r <= b) {
            return tree[no];
        }

        int m = (l+r)/2;
        
        if (b <= m){
			return (L[no] ? get(L[no], l, m, a, b) : ZERO);
        }else if (a > m) return (R[no] ? get(R[no], m+1, r, a, b) : ZERO);
        
        return Node::join(
            (L[no] ? get(L[no], l, m, a, b) : ZERO),
            (R[no] ? get(R[no], m+1, r, a, b) : ZERO)
        );
    }

    auto get(int a, int b) -> Node {
        return get(0, 0, n-1, a, b);
    }

    auto upd(int no, int l, int r, int p, Node const& val) -> void {
        if (l == r) {
			tree[at] = tree[no].update(val);
            return;
        }
        
        int m = (l+r)/2;

		if (p <= m){
			if(L[no] == 0){
				L[no] = ++nodes;
			}
			L[no] = upd(L[no], l, m, p, val);
		}else{
			if(R[no] == 0){
				R[no] = ++nodes;
			}
			R[no] = upd(R[no], m+1, r, p, val);
		}
		tree[no] = Node::join( (L[no] ? tree[L[no]] : ZERO), (R[no]?tree[R[no]] : ZERO));
	}

	auto upd(int p, Node const& val) -> void {
		upd(0, 0, n-1, p, val);
	}
};
