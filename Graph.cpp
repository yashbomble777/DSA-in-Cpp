#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

// Class representing the messaging network as an undirected graph
class MessagingNetwork {
private:
    // Adjacency list: maps each username to a vector of connected contact usernames
    unordered_map<string, vector<string>> adjList;

public:
    // Function to add a bidirectional contact relationship
    void addContact(const string& user1, const string& user2) {
        adjList[user1].push_back(user2);
        adjList[user2].push_back(user1);
    }

    // Function to display the contact list and total contact count for each user
    void displayContacts() {
        cout << "\n========================================\n";
        cout << "      MESSAGING NETWORK DIRECTORY       \n";
        cout << "========================================\n";
        
        for (const auto& pair : adjList) {
            string user = pair.first;
            const vector<string>& contacts = pair.second;
            
            cout << "User: **" << user << "**\n";
            cout << "  - Contacts: ";
            
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
            
            // Calculate and display total contacts
            cout << "\n  - Total Contacts: **" << contacts.size() << "**\n";
            cout << "----------------------------------------\n";
        }
    }
};

int main() {
    MessagingNetwork network;

    // Establishing contact relationships (Undirected edges)
    network.addContact("Alice", "Bob");
    network.addContact("Alice", "Charlie");
    network.addContact("Bob", "David");
    network.addContact("Charlie", "David");
    network.addContact("Charlie", "Eve");
    network.addContact("Eve", "Alice");

    // Display contacts and total counts for every user
    network.displayContacts();

    return 0;
}