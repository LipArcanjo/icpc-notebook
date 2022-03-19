//Monogon Fortune Algorithm implementation
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
 
using ftype = long double;
const ftype EPS = 1e-12, INF = 1e100;
 
struct pt {
    ftype x, y;
    pt(ftype x = 0, ftype y = 0) : x(x), y(y) {}
    pt operator+(const pt &o) const {
        return pt(x + o.x, y + o.y);
    }
    pt operator-(const pt &o) const {
        return pt(x - o.x, y - o.y);
    }
    pt operator*(const ftype &f) const {
        return pt(x * f, y * f);
    }
    pt rot() const {
        return pt(-y, x);
    }
    ftype dot(const pt &o) const {
        return x * o.x + y * o.y;
    }
    ftype cross(const pt &o) const {
        return x * o.y - y * o.x;
    }
    ftype norm() const {
        return x * x + y * y;
    }
    ftype len() const {
        return hypotl(x, y);
    }
    bool operator<(const pt &o) const {
        return make_pair(x, y) < make_pair(o.x, o.y);
    }
};
 
bool collinear(pt a, pt b) {
    return abs(a.cross(b)) < 0.01;
}
 
pt lineline(pt a, pt b, pt c, pt d) {
    return a + (b - a) * ((c - a).cross(d - c) / (b - a).cross(d - c));
}
 
pt circumcenter(pt a, pt b, pt c) {
    b = (a + b) * 0.5;
    c = (a + c) * 0.5;
    return lineline(b, b + (b - a).rot(), c, c + (c - a).rot());
}
 
ftype sweepx;
 
struct arc {
    mutable pt p, q;
    mutable int id = 0, i;
    mutable ftype dirLen;
    void calcDirLen() const { dirLen = (p - q).len(); }
    arc(pt p, pt q, int i) : p(p), q(q), i(i) { calcDirLen(); }
    ftype gety(ftype x) const {
        if(q.y == INF) return INF;
        x += EPS;
        pt med = (p + q) * 0.5;
        pt dir = (p - q).rot();
        ftype D = (x - p.x) * (x - q.x);
        return med.y + ((med.x - x) * dir.x + sqrtl(D) * dirLen) / dir.y;
    }
    bool operator<(const ftype &y) const {
        return gety(sweepx) < y;
    }
    bool operator<(const arc &o) const {
        return gety(sweepx) < o.gety(sweepx);
    }
};
 
using beach = multiset<arc, less<>>;
 
struct event {
    ftype x;
    int id;
    beach::iterator it;
    event(ftype x, int id, beach::iterator it) : x(x), id(id), it(it) {}
    bool operator<(const event &e) const {
        return x > e.x;
    }
};
 
struct fortune {
    beach line;
    vector<pair<pt, int>> v;
    priority_queue<event> Q;
    vector<pii> edges;
    vector<bool> valid;
    int n, ti;
    fortune(vector<pt> p) {
        n = sz(p);
        v.resize(n);
        rep(i, 0, n) v[i] = {p[i], i};
        sort(all(v));
    }
    void upd(beach::iterator it) {
        if(it->i == -1) return;
        valid[-it->id] = false;
        auto a = prev(it);
        if(collinear(it->q - it->p, a->p - it->p)) return;
        it->id = --ti;
        valid.push_back(true);
        pt c = circumcenter(it->p, it->q, a->p);
        ftype x = c.x + (c - it->p).len();
        if(x > sweepx - EPS && a->gety(x) + EPS > it->gety(x)) {
            Q.push(event(x, it->id, it));
        }
    }
    void add_edge(int i, int j) {
        if(i == -1 || j == -1) return;
        edges.push_back({v[i].second, v[j].second});
    }
    void add(int i) {
        pt p = v[i].first;
        auto c = line.lower_bound(p.y);
        auto b = line.insert(c, arc(p, c->p, i));
        auto a = line.insert(b, arc(c->p, p, c->i));
        add_edge(i, c->i);
        upd(a); upd(b); upd(c);
    }
    void remove(beach::iterator it) {
        auto a = prev(it);
        auto b = next(it);
        line.erase(it);
        a->q = b->p;
        a->calcDirLen();
        add_edge(a->i, b->i);
        upd(a); upd(b);
    }
    void solve(ftype X = 1e9) {
        X *= 3;
        line.insert(arc(pt(-X, -X), pt(-X, X), -1));
        line.insert(arc(pt(-X, X), pt(-X, 2*X), -1));
        rep(i, 0, n) {
            Q.push(event(v[i].first.x, i, line.end()));
        }
        ti = 0;
        valid.assign(1, false);
        while(!Q.empty()) {
            event e = Q.top(); Q.pop();
            sweepx = e.x;
            if(e.id >= 0) {
                add(e.id);
            }else if(valid[-e.id]) {
                remove(e.it);
            }
        }
    }
};