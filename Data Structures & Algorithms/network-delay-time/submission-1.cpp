#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n);
        for (auto time: times) {
            int u = time[0] - 1;
            int v = time[1] - 1;
            int w = time[2];
            graph[u].push_back({v, w});
        }

        vector<int> dist(n, INT_MAX);
        dist[k-1] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k-1});
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dist[u]) continue;
            for (auto edge: graph[u]) {
                int v = edge.first;
                int w = edge.second;
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        int max_dist = *max_element(dist.begin(), dist.end());
        return max_dist == INT_MAX ? -1 : max_dist;
    }
};
