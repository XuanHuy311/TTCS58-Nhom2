#include <iostream>
#include <vector>
#include <algorithm> // Hàm sort
using namespace std;

// Cau truc de luu canh do thi
// u, v la 2 dinh, w la trong so canh
struct dothi {
    int u, v, w;
};
// Ham so sanh der dung trong ham sort o duoi
bool cmp(const dothi &a, const dothi &b) {
    return a.w < b.w;
}
#define N 10005
// 2 mang su dung trong Disjoint Set
int cha[N], hang[N];

// Tìm xem u thuoc cây nào
int find(int u) {
    if (cha[u] != u) cha[u] = find(cha[u]);
    return cha[u];
}

// Hop nhat 2 cây ch? u và v,
// Tra ve false eu không the hop nhat
bool join(int u, int v) {
    u = find(u); v = find(v);
    if (u == v) return false;
    if (hang[u] == hang[v]) hang[u]++;
    if (hang[u] < hang[v]) cha[u] = v;
    else cha[v]=u;
    return true;
}

int main() {
    // Thêm dòng này de cin, cout chay nhanh
    ios::sync_with_stdio(false); cin.tie(0);

    // Nhap vào so dinh và so canh
    int n, m; cin >> n >> m;

    // Nhap danh sách các canh
    vector<dothi> dthi(m);
    for (dothi &e: dthi) cin >> e.u >> e.v >> e.w;

    // Sap xep lai các canh theo trong so tang dan
    sort(dthi.begin(), dthi.end(), cmp);

    // Khoi tao cau truc Disjoint Set
    for (int i=1; i<=n; i++) {
        cha[i] = i;
        hang[i] = 0;
    }

    // Luu t?ng tr?ng s? các c?nh trong cây khung nh? nh?t
    int mst_weight = 0;

    // Duyet qua các canh theo thu tu dd sap xep
    for (dothi &e: dthi) {
        // Thu hop nhat 2 cây chua u và v
        if (join(e.u, e.v)) {
            // Hop nhat thành công, ta thêm e và ket qua
            mst_weight += e.w;
        }
    }

    // Xuat ket qua
    cout << mst_weight;
    return 0;
}
