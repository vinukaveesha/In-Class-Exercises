#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF INT_MAX

// Structure to represent a city and its time cost
struct Node {
    int city;
    int time_cost;

    bool operator>(const Node& other) const {
        return time_cost > other.time_cost;
    }
};

void dijkstra(const vector<vector<int>>& graph, int source, vector<int>& time_costs) {   // Dijkstra's algorithm implementation
    int numCities = graph.size();

    time_costs.assign(numCities, INF);                                                   // Initialize time costs to infinity

    priority_queue<Node, vector<Node>, greater<Node>> pq;                                // Priority queue to store nodes (city, time cost)

    time_costs[source] = 0;        // Set source city's time cost to 0
    pq.push({source, 0});

    while (!pq.empty()) {
        // Extract the city with the minimum timecost
        int currCity = pq.top().city;
        int currTimeCost = pq.top().time_cost;
        pq.pop();

        // If the extracted timecost is greater than the recorded timecost, ignore
        if (currTimeCost > time_costs[currCity])
            continue;

        // Search neighbors of the current city
        for (int neighbor = 0; neighbor < numCities; ++neighbor) {
            int edgeWeight = graph[currCity][neighbor];
            int totalTimeCost = currTimeCost + edgeWeight;

            // If a shorter path is found, update the timecost and enqueue the neighbor
            if (edgeWeight != 0 && totalTimeCost < time_costs[neighbor]) {
                time_costs[neighbor] = totalTimeCost;
                pq.push({neighbor, totalTimeCost});
            }
        }
    }
}

int main() {

    vector<vector<int>> graph = {
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}
    };

    int numCities = graph.size();

    int source = 0;
    vector<int> time_costs;

    dijkstra(graph, source, time_costs);

    cout << "Minimum time costs from Node " << source << ":\n";
    for (int i = 0; i < numCities; ++i)
    {
        if (i != source) {
            cout << " -> Node " << i << ": ";

            if (time_costs[i] == INF)
            {
                cout << "No path";
            }
            else
            {
                cout << time_costs[i];
            }
            cout << endl;
        }
    }

    return 0;
}
