# CContainer

<p align="center">
  <img style="width: 350px; height: 350px;" src="./docs/cc_logo.png" alt="Graphic design is my passion"/>
</p>

[![Codacy Badge](https://app.codacy.com/project/badge/Grade/b38128bf0876489a91f2a8c420866aca)](https://app.codacy.com/gh/lvntky/ccontainer/dashboard?utm_source=gh&utm_medium=referral&utm_content=&utm_campaign=Badge_grade)
![Codecov](https://img.shields.io/codecov/c/gh/lvntky/ccontainer)
![GitHub branch check runs](https://img.shields.io/github/check-runs/lvntky/ccontainer/master)

CContainer is a comprehensive STB style header-only library of data structures implemented in C. This library provides a variety of container types that are essential for managing collections of data in C programs. Each container is designed to be efficient, easy to use, and flexible, making CContainer a valuable tool for C developers.

## Features

- Dynamic Array (Vector)
    - Dynamic resizing
    - Random access
    - Efficient indexing
    - Functions: Initialization, Insertion, Deletion, Access, Resizing, Cleanup- 
- Linked List
    - Dynamic size
    - Efficient insertions/deletions at both ends
    - Sequential access
    - Functions: Initialization, Insertion, Deletion, Access, Cleanup- 
- Doubly Linked List
    - Dynamic size
    - Efficient insertions/deletions at both ends
    - Bidirectional sequential access
    - Functions: Initialization, Insertion, Deletion, Access, Cleanup- 
- Stack
    - LIFO (Last In, First Out) access
    - Functions: Initialization, Push, Pop, Peek, Cleanup- 
- Queue
    - FIFO (First In, First Out) access
    - Functions: Initialization, Enqueue, Dequeue, Peek, Cleanup- 
- Hash Map
    - Key-value pair storage
    - Efficient lookups, insertions, and deletions
    - Functions: Initialization, Insert, Remove, Get, Cleanup- 
- Set
    - Unique element storage
    - Efficient membership testing, insertion, and deletion
    - Functions: Initialization, Insert, Remove, Contains, Cleanup- 
- Binary Search Tree (BST)
    - Ordered elements
    - Efficient insertions, deletions, and lookups
    - Functions: Initialization, Insertion, Deletion, Search, Traversal, Cleanup- 
- Red-Black Tree
    - Self-balancing BST
    - Ensures balanced height for efficient operations
    - Functions: Initialization, Insertion, Deletion, Search, Traversal, Cleanup- 
- Heap (Priority Queue)
    - Efficient retrieval of the maximum or minimum element
    - Supports both max-heap and min-heap configurations
    - Functions: Initialization, Insertion, Deletion, Peek, Cleanup- 
- Graph
    - Nodes and edges
    - Supports directed and undirected graphs
    - Functions: Initialization, Add node, Add edge, Remove node, Remove edge, Traversal, Cleanup- 
- Trie (Prefix Tree)
    - Efficient prefix-based search
    - Useful for implementing dictionaries and autocomplete
    - Functions: Initialization, Insertion, Deletion, Search, Cleanup- 
- Bloom Filter
    - Probabilistic data structure for set membership testing
    - Space-efficient
    - Functions: Initialization, Add, Query, Cleanup- 
- B-Tree
    - Balanced tree for efficient disk storage operations
    - Used in databases and filesystems
    - Functions: Initialization, Insertion, Deletion, Search, Traversal, Cleanup- 

## Building and installing

See the [BUILDING](BUILDING.md) document.

## Contributing

See the [CONTRIBUTING](CONTRIBUTING.md) document.

## Development Status

You can check and inform development and implementation status of containers from [DEVELOPMENT](DEVELOPMENT.md) document.

## Licensing
This software is available under 2 [licenses](LICENSE) -- choose whichever you prefer.