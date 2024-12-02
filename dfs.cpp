#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v[n + 1];

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    vector<bool> visited(n + 1, false);
    stack<int> s;
    s.push(1);
    visited[1] = true;

    while (!s.empty()) {
        int node = s.top();
        s.pop();
        cout << node << " ";  
        for (int neighbor : v[node]) {
            if (!visited[neighbor]) {
                s.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }

    return 0;
}
