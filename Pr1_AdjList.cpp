#include <iostream>
#include <string>
using namespace std;

struct Node 
{
    int dest;
    int time;
    int fuel;
    Node* next;

    Node(int d, int t, int f)
     {
        dest = d;
        time = t;
        fuel = f;
        next = nullptr;
    }
};


class Graph 
{
    string cities[10];
    Node* adjList[10];
    int n, m;

public:
    Graph()
     {
        for (int i = 0; i < 10; i++)
            adjList[i] = nullptr;
    }

    void read()
     {
        cout << "\nEnter number of cities: ";
        cin >> n;
        cin.ignore();

        cout << "\nEnter city names:\n";
        for (int i = 0; i < n; i++) 
        {
            cout << "City " << (i + 1) << ": ";
            getline(cin, cities[i]);
        }

        cout << "\nEnter number of flights: ";
        cin >> m;
        cin.ignore();

        cout << "\nEnter Source Destination Time Fuel (City Numbers start from 1)\n";
        for (int i = 0; i < m; i++) 
        {
            int src, dest, time, fuel;
            cout << "\nFor Flight-" << (i + 1) << " : ";
            cin >> src >> dest >> time >> fuel;
            cin.ignore();
            src--;
            dest--;
            addEdge(src, dest, time, fuel);
        }
    }

    void addEdge(int src, int dest, int time, int fuel) 
    {
        Node* newNode = new Node(dest, time, fuel);
        newNode->next = adjList[src];
        adjList[src] = newNode;
    }

    void display() 
    {
        cout << "\nAdjacency List:\n";
        for (int i = 0; i < n; i++)
         {
            cout << cities[i] << " -> ";
            Node* temp = adjList[i];
            while (temp != nullptr)
             {
                cout << "[" << cities[temp->dest] << ", Time: " << temp->time << ", Fuel: " << temp->fuel << "] -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
    }

    void checkConnection()
     {
        int src, dest;
        cout << "\nEnter source city number (1 to " << n << "): ";
        cin >> src;
        cin.ignore();
        cout << "Enter destination city number (1 to " << n << "): ";
        cin >> dest;
        cin.ignore();
        src--;
        dest--;

        if (src < 0 || src >= n || dest < 0 || dest >= n) {
            cout << "Invalid city numbers.\n";
            return;
        }

        Node* temp = adjList[src];
        while (temp != nullptr) {
            if (temp->dest == dest) 
            {
                cout << "Path exists between " << cities[src] << " and " << cities[dest] << ".\n";
                return;
            }
            temp = temp->next;
        }
        cout << "No path exists between " << cities[src] << " and " << cities[dest] << ".\n";
    }
};

int main() 
{
    Graph g;
    int ch;
    do
     {
        cout << "\nMenu:";
        cout << "\n1. Read Flight Data";
        cout << "\n2. Display Adjacency List";
        cout << "\n3. Check Connection";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;

        if (cin.fail()) 
        {
            cin.clear();        // Clear fail flag
            cin.ignore(1000, '\n');  
            cout << "Invalid input. Please enter a number between 1 and 4.\n";
            continue; // Restart loop
        }

        cin.ignore(); // Clear newline after int

        switch (ch) {
            case 1:
                g.read();
                break;
            case 2:
                g.display();
                break;
            case 3:
                g.checkConnection();
                break;
            case 4:
                cout << "Exiting...!!!\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (ch != 4);

    return 0;
}
