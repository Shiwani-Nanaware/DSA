#include <iostream>
#include <cstring>
using namespace std;

class Graph {
    string cities[10];
    int n, m;
    int adjm1[10][10];  // For time
    int adjm2[10][10];  // For fuel

public:
    Graph() {
        memset(adjm1, 0, sizeof(adjm1));
        memset(adjm2, 0, sizeof(adjm2));
    }

    void read() {
        cout << "\nEnter number of cities: ";
        cin >> n;
        cin.ignore();
        cout << "\nEnter city names: ";
        for (int i = 0; i < n; i++) {
            cout << "\nCity " << (i + 1) << ": ";
            getline(cin, cities[i]);
        }

        cout << "\nEnter number of flights: ";
        cin >> m;
        cout << "\nEnter Source Destination Time Fuel (City Numbers start from 1)\n";
        for (int i = 0; i < m; i++) {
            cout << "\nFor Flight- " << (i + 1) << " : ";
            int src, dest, Time, Fuel;
            cin >> src >> dest >> Time >> Fuel;
            src--; dest--;  // Adjust to 0-based index
            adjm1[src][dest] = Time;
            adjm2[src][dest] = Fuel;
        }
    }

    void displayTimeMatrix() {
        cout << "\nAdjacency Matrix (Time Required):\n\t";
        for (int i = 0; i < n; i++) {
            cout << cities[i] << "\t";
        }
        cout << endl;

        for (int i = 0; i < n; i++) {
            cout << cities[i] << "\t";
            for (int j = 0; j < n; j++) {
                cout << adjm1[i][j] << "\t";
            }
            cout << endl;
        }
    }

    void displayFuelMatrix() {
        cout << "\nAdjacency Matrix (Fuel Required):\n\t";
        for (int i = 0; i < n; i++) {
            cout << cities[i] << "\t";
        }
        cout << endl;

        for (int i = 0; i < n; i++) {
            cout << cities[i] << "\t";
            for (int j = 0; j < n; j++) {
                cout << adjm2[i][j] << "\t";
            }
            cout << endl;
        }
    }

    void checkConnection() {
        int src, dest;
        cout << "\nEnter source city number (1 to " << n << "): ";
        cin >> src;
        cout << "Enter destination city number (1 to " << n << "): ";
        cin >> dest;
        src--; dest--;  // Adjust to 0-based index

        if (src < 0 || src >= n || dest < 0 || dest >= n) {
            cout << "Invalid city numbers.\n";
            return;
        }

        if (adjm1[src][dest] != 0)
            cout << "\nPath exists between " << cities[src] << " and " << cities[dest] << endl;
        else
            cout << "\nNo path exists between " << cities[src] << " and " << cities[dest] << endl;
    }
};

int main() {
    Graph g;
    int ch;
    do {
        cout << "\nMenu :";
        cout << "\n1. Read Flight Data";
        cout << "\n2. Display Time Matrix";
        cout << "\n3. Display Fuel Matrix";
        cout << "\n4. Check Connection";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            g.read();
            break;
        case 2:
            g.displayTimeMatrix();
            break;
        case 3:
            g.displayFuelMatrix();
            break;
        case 4:
            g.checkConnection();
            break;
        case 5:
            cout << "Exiting...!!!\n";
            break;
        default:
            cout << "Invalid choice\n";
        }
    } while (ch != 5);

    return 0;
}
