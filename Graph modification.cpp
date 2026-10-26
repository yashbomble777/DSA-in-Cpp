#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

class MessagingNetwork {
private:
    unordered_map<string, vector<string>> adjList;

public:
    // Function to add a bidirectional contact relationship (Edge)
    void addContact(const string& user1, const string& user2) {
        if (find(adjList[user1].begin(), adjList[user1].end(), user2) == adjList[user1].end()) {
            adjList[user1].push_back(user2);
        }
        if (find(adjList[user2].begin(), adjList[user2].end(), user1) == adjList[user2].end()) {
            adjList[user2].push_back(user1);
        }
    }

    // A. Insert a new vertex and its associated edges
    void addVertexWithEdges(const string& newUser, const vector<string>& contacts) {
        cout << "\n[Operation] Inserting new user: " << newUser << " with initial contacts...\n";
        for (const auto& contact : contacts) {
            addContact(newUser, contact);
        }
    }

    // B. Remove a selected edge between two users
    void removeEdge(const string& user1, const string& user2) {
        cout << "\n[Operation] Removing contact link between " << user1 << " and " << user2 << "...\n";
        
        // Remove user2 from user1's contact list
        if (adjList.find(user1) != adjList.end()) {
            auto& v1 = adjList[user1];
            v1.erase(remove(v1.begin(), v1.end(), user2), v1.end());
        }
        // Remove user1 from user2's contact list
        if (adjList.find(user2) != adjList.end()) {
            auto& v2 = adjList[user2];
            v2.erase(remove(v2.begin(), v2.end(), user1), v2.end());
        }
    }

    // C. Calculate and display the degree and direct neighbours of each vertex
    void displayVertexDegreeAndNeighbors() {
        cout << "\n========================================\n";
        cout << "   VERTEX DEGREES & DIRECT NEIGHBORS    \n";
        cout << "========================================\n";
        
        for (const auto& pair : adjList) {
            string user = pair.first;
            const vector<string>& contacts = pair.second;
            
            cout << "User: " << user << "\n";
            cout << "  - Degree (Total Contacts): " << contacts.size() << "\n";
            cout << "  - Direct Neighbors: ";
            
            if (contacts.empty()) {
                cout << "None";
            } else {
                for (size_t i = 0; i < contacts.size(); ++i) {
                    cout << contacts[i];
                    if (i != contacts.size() - 1) {
                        cout << ", ";
                    }
                }
            }
            cout << "\n----------------------------------------\n";
        }
    }
};

int main() {
    MessagingNetwork network;

    // Establishing initial contact relationships
    network.addContact("Alice", "Bob");
    network.addContact("Alice", "Charlie");
    network.addContact("Bob", "David");
    network.addContact("Charlie", "David");

    // Display initial network state
    cout << "=== INITIAL NETWORK STATE ===";
    network.displayVertexDegreeAndNeighbors();

    // A. Insert a new vertex "Frank" with edges to "Alice" and "David"
    network.addVertexWithEdges("Frank", {"Alice", "David"});
    
    // Display graph after insertion
    cout << "=== NETWORK AFTER INSERTING 'Frank' ===";
    network.displayVertexDegreeAndNeighbors();

    // B. Remove an edge between "Bob" and "David"
    network.removeEdge("Bob", "David");
    
    // Display graph after edge removal
    cout << "=== NETWORK AFTER REMOVING EDGE (Bob - David) ===";
    network.displayVertexDegreeAndNeighbors();

    return 0;
}