# Floyd-Warshall

This is an example of my ability to use C++ in a basic Object Oriented context. 

The Floyd-Warshall algorithm solves the all pairs shortest path problem using dynamic programming to achieve a cubic runtime. It works by finding the shortest path between a point i and some k and k and the other point j. If the path going through k is shorter than the already known path between i and j then the shortest path is updated.

The floyd-warshall.cpp file contains a class that builds graphs. In it you can create graphs by creating a Graph object and adding edges. 
Then you can find the shortest path between all pairs using the floyd-warshall function. 
This class demonstrates my ability to write object oriented code including the following concepts: 
    Polymorphism
    Exceptions
    Constructors
    Access Specifiers
    Encapsulation

The FW_tester.cpp is used to demonstrate the floyd-warshall.cpp class.