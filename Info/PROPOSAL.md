# Final Project Proposal

## Leading Question

The purpose of this project is to investigate the shortest paths between two given airports (and possibly all the connecting airports) and identify the connectedness of a given airport. This can be used as a general search tool to find all of the possible paths from one airport to another and ultimately the shortest distance between two airports. This information will be printed to the user directly in the terminal after they are prompted to input the desired starting and ending airport codes.

## Dataset Acquisition and Processing

We will be using the airport, airline, and route data from OpenFlights.org in CSV format. We will create custom classes for airports, airlines, and routes to store the data for use in the graph. Our nodes will be the airports with the edges symbolizing the specific routes that will be taken. This will ultimately result in our data being represented by a directed graph.

Links to the datasets:
[airports.dat](https://raw.githubusercontent.com/jpatokal/openflights/master/data/airports.dat)
[airlines.dat](https://raw.githubusercontent.com/jpatokal/openflights/master/data/airlines.dat)
[routes.dat](https://raw.githubusercontent.com/jpatokal/openflights/master/data/routes.dat)

## Algorithms

- Depth-First Search (DFS). Inputs: Airport and Routes data. Output = DFS Iterator object. Ideal runtime: O(V + E), where V = Vertices and E = Edges.

- Dijkstra’s Algorithm: Finding the shortest path between two nodes (airports). Useful for finding the shortest distance between two destinations. Input: Names of two places, Output: Returns shortest path between those destinations. Ideal runtime: O( (E + V) log V), where V = Vertices and E = Edges.

- Betweenness Centrality Algorithm: Find the shortest path between two airports and compute a score based on the number of shortest paths that intersect it. In other words, we find the centrality of airports which tells us the importance of the airport as a transfer location. Input = Country Name, Output = Airport with highest centrality. Runtime: O(N^4), where N = Number of nodes.

## Timeline

- **April 9th:** Team Contract and Final Project Proposal Due

- **April 16th:** Mid-project Check-in

  - Have datasets downloaded and converted
  - Completed depth-first search traversal algorithm

- **May 1st:** Third-project Check-in

  - Start final report
  - Complete second algorithm
  - Begin working on begtweeness centrality algorithm

- **May 10th:** Video deadline

  - Finalize all code and squash bugs
  - Ensure testing suite is in working order
  - Review final report
  - Film video

- **May 12th:** Final Project Deliverables

  - Functional code-base that is compilable and runnable on the EWS machine.
  - A written report of our project stored as a MD file. The specific breakdown of the report is as follows:
    - GOALS - A two-page proposal including information about the datasets we used, the specific algorithms we chose, what final deliverable we completed, and the timeline we followed.
    - DEVELOPMENT - A document with exactly one paragraph per week, describing what was accomplished or attempted in that week.
    - RESULTS - A one- to two-page final report describing the final deliverables of your project, including any discoveries made.
  - A final presentation in the form of a short video (10 minutes or less) describing our project.
