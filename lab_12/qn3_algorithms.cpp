#include <iostream>
#include <vector>
#include <list>
using namespace std;

class MinHeap {
    vector<pair<int, int>> heap;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    void heapifyUp(int i) {
        while (i > 0 && heap[parent(i)].first > heap[i].first) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void heapifyDown(int i) {
        int smallest = i, l = left(i), r = right(i);
        if (l < heap.size() && heap[l].first < heap[smallest].first) smallest = l;
        if (r < heap.size() && heap[r].first < heap[smallest].first) smallest = r;
        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    void insert(pair<int, int> entry) {
        heap.push_back(entry);
        heapifyUp(heap.size() - 1);
    }

    pair<int, int> extractMin() {
        if (heap.empty()) return {-1, -1};
        pair<int, int> root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return root;
    }

    bool isEmpty() { return heap.empty(); }
};

class adjacency {
    vector<list<pair<int, int>>> adj_list;
    int num_vert;

public:
    adjacency(int vertices) {
        num_vert = vertices;
        adj_list.resize(vertices);
    }

    int insert(int u, int v, int w) {
        if (u < 0 || v < 0 || u >= num_vert || v >= num_vert)
            return -2;
        adj_list[u].push_back({v, w});
        adj_list[v].push_back({u, w});
        return 1;
    }

    void prims() {
        vector<bool> inMST(num_vert, false);
        vector<int> key(num_vert, 100000);
        MinHeap pq;

        key[0] = 0;
        pq.insert({0, 0});

        int totalWeight = 0;
        cout << "\nPrim's MST Edges:\n";

        while (!pq.isEmpty()) {
            pair<int, int> p = pq.extractMin();
            int u = p.second;

            if (inMST[u]) continue;

            inMST[u] = true;
            totalWeight += p.first;
            cout << "Included node: " << u << " (weight = " << p.first << ")\n";

            for (auto &[v, w] : adj_list[u]) {
                if (!inMST[v] && w < key[v]) {
                    key[v] = w;
                    pq.insert({w, v});
                }
            }
        }

        cout << "Total MST weight: " << totalWeight << endl;
    }

    void dijkstra(int src) {
        vector<int> dist(num_vert, 100000);
        dist[src] = 0;
        MinHeap pq;
        pq.insert({0, src});

        while (!pq.isEmpty()) {
            auto [d, u] = pq.extractMin();

            if (d > dist[u]) continue;

            for (auto &[v, w] : adj_list[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.insert({dist[v], v});
                }
            }
        }

        cout << "\nDijkstra's shortest paths from " << src << ":\n";
        for (int i = 0; i < num_vert; ++i) {
            cout << "Node " << i << " - Distance: " << dist[i] << "\n";
        }
    }

    int find(int parent[], int x) {
        while (parent[x] != x) {
            x = parent[x];
        }
        return x;
    }

    void union_sets(int parent[], int x, int y) {
        int px = find(parent, x);
        int py = find(parent, y);
        parent[py] = px;
    }

    void kruskals() {
        vector<pair<int, pair<int, int>>> edges;

        // Collect all unique edges
        for (int u = 0; u < num_vert; ++u) {
            for (auto &[v, w] : adj_list[u]) {
                if (u < v)
                    edges.push_back({w, {u, v}});
            }
        }

        // Bubble sort (ascending weight)
        for (int i = 0; i < edges.size(); ++i) {
            for (int j = i + 1; j < edges.size(); ++j) {
                if (edges[i].first > edges[j].first)
                    swap(edges[i], edges[j]);
            }
        }

        int parent[100];
        for (int i = 0; i < num_vert; i++)
            parent[i] = i;

        int totalWeight = 0;
        int count = 0;

        cout << "\nKruskal's MST Edges:\n";
        for (int i = 0; i < edges.size() && count < num_vert - 1; i++) {
            int w = edges[i].first;
            int u = edges[i].second.first;
            int v = edges[i].second.second;

            int set_u = find(parent, u);
            int set_v = find(parent, v);

            if (set_u != set_v) {
                union_sets(parent, u, v);
                cout << u << " - " << v << " (Weight = " << w << ")\n";
                totalWeight += w;
                count++;
            }
        }

        cout << "Total MST weight: " << totalWeight << "\n";
    }
};

void menu() {
    cout << "\n1. Insert Edge\n2. Prim's MST\n3. Kruskal's MST\n4. Dijkstra's Shortest Path\n5. Exit." << endl;
    cout << "Enter Your Choice: ";
}

int main() {
    int vertices;
    cout << "Enter number of vertices: ";
    cin >> vertices;

    adjacency matrix(vertices);

    int choice, u, v, w;

    do {
        menu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the vertices and weight (u v w): ";
                cin >> u >> v >> w;
                if (matrix.insert(u, v, w) == -2)
                    cout << "Invalid vertices!\n";
                else
                    cout << "Edge inserted.\n";
                break;

            case 2:
                matrix.prims();
                break;

            case 3:
                matrix.kruskals();
                break;

            case 4:
                int src;
                cout << "Enter source vertex: ";
                cin >> src;
                matrix.dijkstra(src);
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
