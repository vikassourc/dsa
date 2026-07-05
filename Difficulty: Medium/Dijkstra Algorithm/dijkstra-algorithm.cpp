class Solution {
public:
    vector<int> dijkstra(int n, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int, int>>> adj(n);
        vector<int> dist(n, INT_MAX);

        for (int i = 0; i < edges.size(); i++) {
            int s = edges[i][0];
            int d = edges[i][1];
            int w = edges[i][2];

            adj[s].push_back({d, w});
            adj[d].push_back({s, w});
        }

        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            pair<int, int> p = pq.top();
            pq.pop();

            int d = p.first;
            int node = p.second;

            if (d > dist[node])
                continue;

            for (int j = 0; j < adj[node].size(); j++) {
                int neigh = adj[node][j].first;
                int weight = adj[node][j].second;

                if (d + weight < dist[neigh]) {
                    dist[neigh] = d + weight;
                    pq.push({d + weight, neigh});
                }
            }
        }

        return dist;
    }
};