// #include "graph.h"
// #include "readFromFile.cpp"

// using namespace std; 

// /**
//  * Graph constructor 
//  * */
// Graph::Graph(vector<airportNode> first, vector<route> second) {
// }

// /**
//  * Constructs a graph given two vectors
//  * Parameters: vector of nodes (airports) & vector of edges (routes)
//  * Graph here is represented using an adjacency list 
//  * Adjacency list of choice: unordered-map of lists (where each list element is a pair)
//  * */
// void Graph::makeGraph(vector<airportNode> airports, vector<route> routes) {
//     //iterate through the routes vector and get the source and destination of each object 
//     for (auto it = routes.begin(); it != routes.end(); ++it) {
//         string source_string = (*it).source;
//         string destination_string = (*it).destination;

//         //find the corresponding airportNode of the source and destination strings respectively
//         //auto iter1 = find_if(airports.begin(), airports.end(), [&source_string](const airportNode & obj) { return obj.getName() == source; })
//         //auto iter2 = find_if(airports.begin(), airports.end(), [&destination_string](const airportNode & obj2) { return obj2.getName() == destination; })

//         airportNode node1;
//         string source_code = node1.getName();
//         match one(source_string);

//         //bool check1 = one(ide);
//         std::vector<airportNode>::iterator iter1 = find_if(airports.begin(), airports.end(), match(source_string));
//         airportNode source_node = (*iter1);
//         cout << source_node.code_ << "->" << source_node.city_ << endl; 

//         // if (iter1 != airports.end()) {
//         //     auto index1 = std::distance(airports.begin(), iter1);
//         //     airportNode source_node = (*iter1);
//         // }
        
//         airportNode node2; 
//         string destination_code = node2.getName(); 
//         match two(destination_string); 
//         //bool check2 = two(real);
//         std::vector<airportNode>::iterator iter2 = find_if(airports.begin(), airports.end(), match(destination_string));
//         airportNode destination_node = (*iter2);

//         // if (iter2 != airports.end()) {
//         //     auto index2 = std::distance(airports.begin(), iter2);
//         //     airportNode destination_node = (*iter2);
//         // }

//         if (destination_string == destination_node.code_ && source_string == source_node.code_) {
//             double weight = source_node.dist(destination_node);
//             adjL[source_node].push_back(make_pair(destination_node, weight));
//         } else {
//             cout << "Either the Source or Destination airports do not exist" << endl;
//         }
//     }
// }

// /**
//  * Prints the contents of the adjacency list aka "graph" 
//  * */
// void Graph::print() {
//     for (auto pair : adjL) {
//         airportNode initial = pair.first; 
//         list<std::pair<airportNode, double> > destinations = pair.second; 

//         cout << initial.code_ << "-->";
//         for (auto d : destinations) {
//             airportNode one = d.first; 
//             float weight = d.second; 
//             cout << one.code_ << " " << weight << ",";
//         }
//         cout << endl; 
//     }
// }


// int main() {
//     vector<airportNode> a = readAirports("data/airports.dat");
//     vector<route> b = readRoutes("data/routes.dat");
//     Graph graph = Graph(a, b);
//     graph.makeGraph(a, b);
//     graph.print();
// }