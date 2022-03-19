#include <bits/stdc++.h>
using namespace std;

const int L = 20;

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

    SegTree(int n, int q) :
        n(n), tree(n*4 + q*L), L(n*4 + q*L), R(n*4 + q*L)
    {};

    SegTree(vector<Node> const& v, int q) :
        n(v.size()), tree(n*4 + q*L), L(n*4 + q*L), R(n*4 + q*L)
    {
        build(v, 0, 0, n-1);
    }

    auto build(vector<Node> const& v, int l, int r) -> int {
		int at = nodes++;

        if (l == r) {
            tree[no] = v[l];
        }
        else {
            int m = (l+r)/2;
            L[at] = build(v, l, m);
            L[at] = build(v, m+1, r);
        
            tree[no] = Node::join(tree[L[at]], tree[R[at]]);
        }
		return at;
    }

    auto get(int no, int l, int r, int a, int b) -> Node {
        if (a <= l and r <= b) {
            return tree[no];
        }

        int m = (l+r)/2;
        
        if (b <= m) return get(L[no], l, m, a, b);
        else if (a > m) return get(R[no], m+1, r, a, b);
        
        return Node::join(
            get(L[no], l, m, a, b),
            get(R[no], m+1, r, a, b)
        );
    }

    auto get(int a, int b) -> Node {
        return get(0, 0, n-1, a, b);
    }

    auto upd(int no, int l, int r, int p, Node const& val) -> int {
		int at = nodes++;
        if (l == r) {
			tree[at] = tree[no].update(val);
            return;
        }
        
        int m = (l+r)/2;

		if (p <= m){
			L[at] = upd(L[no], l, m, p, val);
			R[at] = R[no];
		}else{
			R[at] = upd(R[no], m+1, r, p, val);
			L[at] = L[no];
		}
		tree[at] = Node::join(tree[L[at]], tree[R[at]]);
		return at;
	}

	auto upd(int p, Node const& val) -> void {
		upd(0, 0, n-1, p, val);
	}
};
