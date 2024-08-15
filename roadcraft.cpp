#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <limits>
#include <queue>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class Link;
class Node;

class Link {
public:
    int DestinationNodeID;
    double weight;

    Link() {}
    Link(int destNodeID, double w) {
        DestinationNodeID = destNodeID;
        weight = w;
    }
    void setLinkValues(int destNodeID, double w) {
        DestinationNodeID = destNodeID;
        weight = w;
    }
    void setWeight(double w) {
        weight = w;
    }

    int getDestinationNodeID() {
        return DestinationNodeID;
    }
    double getWeight() {
        return weight;
    }
};

class Node {
public:
    int state_id;
    string state_name;

    list<Link> linkList;

    Node() {
        state_id = 0;
        state_name = "";
    }

    Node(int id, string sname) {
        state_id = id;
        state_name = sname;
    }

    int getStateID() {
        return state_id;
    }
    string getStateName() {
        return state_name;
    }
    void setID(int id) {
        state_id = id;
    }
    void setStateName(string sname) {
        state_name = sname;
    }

    list<Link> getLinkList() {
        return linkList;
    }

    void printLinkList() {
        cout << "[";
        for (auto it = linkList.begin(); it != linkList.end(); it++) {
            cout << it->getDestinationNodeID() << "(" << it->getWeight() << ") --> ";
        }
        cout << "]";
        cout << endl;
    }

    void updateNodeName(string sname) {
        state_name = sname;
        cout << "Node Name Updated Successfully";
    }
};

class Graph {
    vector<Node> nodes;

public:
    bool checkIfNodeExistByID(int nid) {
        bool flag = false;
        for (int i = 0; i < nodes.size(); i++) {
            if (nodes.at(i).getStateID() == nid) {
                return true;
            }
        }
        return flag;
    }

    void addNode(Node newNode) {
        bool check = checkIfNodeExistByID(newNode.getStateID());
        if (check == true) {
            cout << "Node with this ID already exists" << endl;
        } else {
            nodes.push_back(newNode);
            cout << "New Node Added Successfully" << endl;
        }
    }

    Node getNodeByID(int nid) {
        Node temp;
        for (int i = 0; i < nodes.size(); i++) {
            temp = nodes.at(i);
            if (temp.getStateID() == nid) {
                return temp;
            }
        }
        return temp;
    }

    bool checkIfLinkExistByID(int fromNode, int toNode) {
        Node n = getNodeByID(fromNode);
        list<Link> l;
        l = n.getLinkList();
        bool flag = false;
        for (auto it = l.begin(); it != l.end(); it++) {
            if (it->getDestinationNodeID() == toNode) {
                flag = true;
                return flag;
                break;
            }
        }
        return flag;
    }

    void updateNode(int oldNID, string nname) {
        bool check = checkIfNodeExistByID(oldNID);
        if (check == true) {
            for (int i = 0; i < nodes.size(); i++) {
                if (nodes.at(i).getStateID() == oldNID) {
                    nodes.at(i).setStateName(nname);
                    break;
                }
            }
            cout << "Node(State) Updated Successfully " << endl;
        }
    }

    void addLinkByID(int fromNode, int toNode, double weight) {
        bool check1 = checkIfNodeExistByID(fromNode);
        bool check2 = checkIfNodeExistByID(toNode);

        bool check3 = checkIfLinkExistByID(fromNode, toNode);
        if ((check1 && check2 == true)) {
            if (check3 == true) {
                cout << "Link between " << getNodeByID(fromNode).getStateName() << "(" << fromNode << ") and "
                     << getNodeByID(toNode).getStateName() << "(" << toNode << ") Already Exists" << endl;
            } else {
                for (int i = 0; i < nodes.size(); i++) {
                    if (nodes.at(i).getStateID() == fromNode) {
                        Link l(toNode, weight);
                        nodes.at(i).linkList.push_back(l);
                    } else if (nodes.at(i).getStateID() == toNode) {
                        Link l(fromNode, weight);
                        nodes.at(i).linkList.push_back(l);
                    }
                }

                cout << "Link between " << fromNode << " and " << toNode << " added Successfully" << endl;
            }
        } else {
            cout << "Invalid Node ID entered." << endl;
        }
    }

    void updateLinkByID(int fromNode, int toNode, double newWeight) {
        bool check = checkIfLinkExistByID(fromNode, toNode);
        if (check == true) {
            for (int i = 0; i < nodes.size(); i++) {
                if (nodes.at(i).getStateID() == fromNode) {
                    for (auto it = nodes.at(i).linkList.begin(); it != nodes.at(i).linkList.end(); it++) {
                        if (it->getDestinationNodeID() == toNode) {
                            it->setWeight(newWeight);
                            break;
                        }
                    }
                } else if (nodes.at(i).getStateID() == toNode) {
                    for (auto it = nodes.at(i).linkList.begin(); it != nodes.at(i).linkList.end(); it++) {
                        if (it->getDestinationNodeID() == fromNode) {
                            it->setWeight(newWeight);
                            break;
                        }
                    }
                }
            }
            cout << "Link Weight Updated Successfully " << endl;
        } else {
            cout << "Link between " << getNodeByID(fromNode).getStateName() << "(" << fromNode << ") and "
                 << getNodeByID(toNode).getStateName() << "(" << toNode << ") DOES NOT Exist" << endl;
        }
    }

    void deleteLinkByID(int fromNode, int toNode) {
        bool check = checkIfLinkExistByID(fromNode, toNode);
        if (check == true) {
            for (int i = 0; i < nodes.size(); i++) {
                if (nodes.at(i).getStateID() == fromNode) {
                    for (auto it = nodes.at(i).linkList.begin(); it != nodes.at(i).linkList.end(); it++) {
                        if (it->getDestinationNodeID() == toNode) {
                            nodes.at(i).linkList.erase(it);
                            break;
                        }
                    }
                }

                if (nodes.at(i).getStateID() == toNode) {
                    for (auto it = nodes.at(i).linkList.begin(); it != nodes.at(i).linkList.end(); it++) {
                        if (it->getDestinationNodeID() == fromNode) {
                            nodes.at(i).linkList.erase(it);
                            break;
                        }
                    }
                }
            }
            cout << "Link Between " << fromNode << " and " << toNode << " Deleted Successfully." << endl;
        }
    }

    void deleteNodeByID(int nid) {
        int nIndex = 0;
        for (int i = 0; i < nodes.size(); i++) {
            if (nodes.at(i).getStateID() == nid) {
                nIndex = i;
            }
        }
        for (int i = 0; i < nodes.size(); i++) {
            for (auto it = nodes.at(i).linkList.begin(); it != nodes.at(i).linkList.end(); it++) {
                if (it->getDestinationNodeID() == nid) {
                    nodes.at(i).linkList.erase(it);
                    break;
                }
            }
        }
        nodes.erase(nodes.begin() + nIndex);
        cout << "Node Deleted Successfully" << endl;
    }

    void getAllNeighborsByID(int nid) {
        cout << getNodeByID(nid).getStateName() << " (" << getNodeByID(nid).getStateID() << ") --> ";
        for (int i = 0; i < nodes.size(); i++) {
            if (nodes.at(i).getStateID() == nid) {
                cout << "[";
                for (auto it = nodes.at(i).linkList.begin(); it != nodes.at(i).linkList.end(); it++) {
                    cout << it->getDestinationNodeID() << "(" << it->getWeight() << ") --> ";
                }
                cout << "]";
            }
        }
    }

    void shortestDistance(int sourceNode) {
        vector<int> dist(nodes.size(), numeric_limits<int>::max());
        dist[sourceNode] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push(make_pair(0, sourceNode));

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (auto it = nodes[u].linkList.begin(); it != nodes[u].linkList.end(); it++) {
                int v = it->getDestinationNodeID();
                int weight = it->getWeight();

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }

        cout << "Shortest distances from node " << sourceNode << " to all other nodes:" << endl;
        for (size_t i = 0; i < dist.size(); i++) {
            cout << "Node " << nodes[i].getStateName() << " (" << nodes[i].getStateID() << "): ";
            if (dist[i] == numeric_limits<int>::max()) {
                cout << "Not reachable" << endl;
            } else {
                cout << dist[i] << endl;
            }
        }
    }

    int shortestDistanceBetweenIDs(int sourceID, int destinationID) {
        vector<int> dist(nodes.size(), numeric_limits<int>::max());
        dist[sourceID] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push(make_pair(0, sourceID));

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (auto it = nodes[u].linkList.begin(); it != nodes[u].linkList.end(); it++) {
                int v = it->getDestinationNodeID();
                int weight = it->getWeight();

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }

        return dist[destinationID];
    }

    void printGraph() {
        for (int i = 0; i < nodes.size(); i++) {
            Node temp;
            temp = nodes.at(i);
            cout << temp.getStateName() << " (" << temp.getStateID() << ") --> ";
            temp.printLinkList();
        }
    }

    vector<int> shortestPath(int sourceNode, int destinationNode) {
        vector<double> dist(nodes.size(), numeric_limits<double>::max());
        vector<int> prev(nodes.size(), -1);

        dist[sourceNode] = 0;

        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
        pq.push(make_pair(0.0, sourceNode));

        while (!pq.empty()) {
            int u = pq.top().second;
            double currDist = pq.top().first;
            pq.pop();

            if (u == destinationNode) {
                break; // Stop once we reach the destination node
            }

            for (auto it = nodes[u].linkList.begin(); it != nodes[u].linkList.end(); it++) {
                int v = it->getDestinationNodeID();
                double weight = it->getWeight();

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    prev[v] = u; // Store the previous node in the shortest path
                    pq.push(make_pair(dist[v], v));
                }
            }
        }

        // Construct the path from the source to the destination
        vector<int> path;
        int curr = destinationNode;
        while (curr != -1) {
            path.push_back(curr);
            curr = prev[curr];
        }

        return path;
    }

    int findClosestNodeFromMultipleNodes(const vector<int>& nodeIDs) {
        if (nodeIDs.empty()) {
            cout << "Error: Empty input vector." << endl;
            return -1;
        }

        vector<double> closestDistances(nodes.size(), numeric_limits<double>::max());

        for (int sourceNode : nodeIDs) {
            vector<double> dist(nodes.size(), numeric_limits<double>::max());
            dist[sourceNode] = 0;

            priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
            pq.push(make_pair(0.0, sourceNode));

            while (!pq.empty()) {
                int u = pq.top().second;
                double currDist = pq.top().first;
                pq.pop();

                for (auto it = nodes[u].linkList.begin(); it != nodes[u].linkList.end(); it++) {
                    int v = it->getDestinationNodeID();
                    double weight = it->getWeight();

                    if (dist[u] + weight < dist[v]) {
                        dist[v] = dist[u] + weight;
                        pq.push(make_pair(dist[v], v));
                    }
                }
            }

            for (size_t i = 0; i < dist.size(); i++) {
                closestDistances[i] = min(closestDistances[i], dist[i]);
            }
        }

        int closestNode = -1;
        double minDistance = numeric_limits<double>::max();

        for (size_t i = 0; i < closestDistances.size(); i++) {
            if (closestDistances[i] < minDistance) {
                minDistance = closestDistances[i];
                closestNode = i;
            }
        }

        return closestNode;
    }
};

void setupGraphFromCSV(Graph& graph, const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string sourceID, sourceName, destID, destName, weight;

        if (getline(iss, sourceID, ',') &&
            getline(iss, sourceName, ',') &&
            getline(iss, destID, ',') &&
            getline(iss, destName, ',') &&
            getline(iss, weight, ',')) {
            int sourceIDInt = stoi(sourceID);
            int destIDInt = stoi(destID);
            double weightInt = stod(weight);

            bool sourceExists = graph.checkIfNodeExistByID(sourceIDInt);
            if (!sourceExists) {
                Node v(sourceIDInt, sourceName);
                graph.addNode(v);
            }

            bool destExists = graph.checkIfNodeExistByID(destIDInt);
            if (!destExists) {
                Node v(destIDInt, destName);
                graph.addNode(v);
            }

            graph.addLinkByID(sourceIDInt, destIDInt, weightInt);
        }
    }

    file.close();
}

template <typename T>
void reverseVector(vector<T>& vec) {
    size_t start = 0;
    size_t end = vec.size() - 1;

    while (start < end) {
        swap(vec[start], vec[end]);
        start++;
        end--;
    }
}

int main() {
    Graph g;
    string sname;
    string filename;
    int numNodes;
    vector<int> nodeIDs;
    int id1, id2, w;
    int sourceID, destinationID;
    vector<int> shortestPath;
    int closestNode;
    int shortestDist;
    int option;
    bool check;

    do {
        cout << "What operation do you want to perform? "
             << "Select Option number. Enter 0 to exit." << endl;
        cout << "1. Add Node" << endl;
        cout << "2. Update Node" << endl;
        cout << "3. Delete Node" << endl;
        cout << "4. Add Link" << endl;
        cout << "5. Update Link" << endl;
        cout << "6. Delete Link" << endl;
        cout << "7. Check if 2 Nodes are Neighbors" << endl;
        cout << "8. Print All Neighbors of a Node" << endl;
        cout << "9. Print Graph" << endl;
        cout << "10. Clear Screen" << endl;
        cout << "11. Find Shortest Distance" << endl;
        cout << "12. Find Shortest Distance Between Nodes" << endl;
        cout << "13. Setup Graph from CSV" << endl;
        cout << "14. Find Shortest Path" << endl;
        cout << "15. Find Closest Node from Multiple Nodes" << endl;
        cout << "0. Exit Program" << endl;

        cout << endl << "Enter your option: ";

        cin >> option;
        Node n1;

        switch (option) {
        case 0:
            break;

        case 1:
            cout << "Add Node Operation -" << endl;
            cout << "Enter State ID: ";
            cin >> id1;
            cout << "Enter State Name: ";
            cin >> sname;
            n1.setID(id1);
            n1.setStateName(sname);
            g.addNode(n1);
            break;

        case 2:
            cout << "Update Node Operation -" << endl;
            cout << "Enter State ID of Node(State) to update: ";
            cin >> id1;
            cout << "Enter State Name: ";
            cin >> sname;
            g.updateNode(id1, sname);
            break;

        case 3:
            cout << "Delete Node Operation -" << endl;
            cout << "Enter ID of Node(State) to Delete: ";
            cin >> id1;
            g.deleteNodeByID(id1);
            break;

        case 4:
            cout << "Add Link Operation -" << endl;
            cout << "Enter ID of Source Node(State): ";
            cin >> id1;
            cout << "Enter ID of Destination Node(State): ";
            cin >> id2;
            cout << "Enter Weight of Link: ";
            cin >> w;
            g.addLinkByID(id1, id2, w);
            break;

        case 5:
            cout << "Update Link Operation -" << endl;
            cout << "Enter ID of Source Node(State): ";
            cin >> id1;
            cout << "Enter ID of Destination Node(State): ";
            cin >> id2;
            cout << "Enter UPDATED Weight of Link: ";
            cin >> w;
            g.updateLinkByID(id1, id2, w);
            break;

        case 6:
            cout << "Delete Link Operation -" << endl;
            cout << "Enter ID of Source Node(State): ";
            cin >> id1;
            cout << "Enter ID of Destination Node(State): ";
            cin >> id2;
            g.deleteLinkByID(id1, id2);
            break;

        case 7:
            cout << "Check if 2 Nodes are Neighbors -" << endl;
            cout << "Enter ID of Source Node(State): ";
            cin >> id1;
            cout << "Enter ID of Destination Node(State): ";
            cin >> id2;
            check = g.checkIfLinkExistByID(id1, id2);
            if (check == true) {
                cout << "Nodes are Neighbors (Link exists)" << endl;
            } else {
                cout << "Nodes are NOT Neighbors (Link does NOT exist)" << endl;
            }
            break;

        case 8:
            cout << "Print All Neighbors of a Node -" << endl;
            cout << "Enter ID of Node(State) to fetch all Neighbors: ";
            cin >> id1;
            g.getAllNeighborsByID(id1);
            break;

        case 9:
            cout << "Print Graph Operation -" << endl;
            g.printGraph();
            break;

        case 10:
            cout << "Clear Screen Operation -" << endl;
            // Clearing the screen by printing a bunch of newlines
            cout << string(100, '\n');
            break;

        case 11:
            cout << "Find Shortest Distance -" << endl;
            cout << "Enter the ID of the source node: ";
            cin >> id1;
            g.shortestDistance(id1);
            break;

        case 12:
            cout << "Find Shortest Distance -" << endl;
            cout << "Enter the ID of the source node: ";
            cin >> sourceID;
            cout << "Enter the ID of the destination node: ";
            cin >> destinationID;

            shortestDist = g.shortestDistanceBetweenIDs(sourceID, destinationID);
            if (shortestDist == numeric_limits<int>::max()) {
                cout << "There is no path between the nodes." << endl;
            } else {
                cout << "Shortest distance between nodes with IDs " << sourceID << " and " << destinationID << " is: " << shortestDist << endl;
            }
            break;

        case 13:
            cout << "Setup Graph from CSV -" << endl;
            filename = "E:\\OhmCraft\\chennaiCity.csv";
            setupGraphFromCSV(g, filename);
            break;

        case 14:
            cout << "Find Shortest Path -" << endl;
            cout << "Enter the ID of the source node: ";
            cin >> sourceID;
            cout << "Enter the ID of the destination node: ";
            cin >> destinationID;

            shortestPath = g.shortestPath(sourceID, destinationID);
            reverseVector(shortestPath);

            if (shortestPath.empty()) {
                cout << "There is no path between the nodes." << endl;
            } else {
                cout << "Shortest path between nodes with IDs " << sourceID << " and " << destinationID << ": ";
                for (size_t i = 0; i < shortestPath.size(); ++i) {
                    int node = shortestPath[i];
                    cout << g.getNodeByID(node).getStateName() << " (" << node << ")";
                    if (i != shortestPath.size() - 1) {
                        cout << " --> ";
                    }
                }
                cout << endl;
            }
            break;
        
        case 15:
            cout << "Find Closest Node from Multiple Nodes -" << endl;
            
            cout << "Enter the number of nodes you want to consider: ";
            cin >> numNodes;
            for (int i = 0; i < numNodes; ++i) {
                int nodeID;
                cout << "Enter ID of node " << i + 1 << ": ";
                cin >> nodeID;
                nodeIDs.push_back(nodeID);
            }

            closestNode = g.findClosestNodeFromMultipleNodes(nodeIDs);
            if (closestNode != -1) {
                cout << "Node " << g.getNodeByID(closestNode).getStateName() << " (" << closestNode << ") is closest to all the given nodes." << endl;
            } else {
                cout << "No nodes in the graph or all given nodes are disconnected." << endl;
            }
            break;

        default:
            cout << "Enter Proper Option number " << endl;
        }
        cout << endl;
    } while (option != 0);
    return 0;
}
