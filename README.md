# Resource manager
* Name: Yunfan He
* Date: 2023/11/26 ~ 2023/11/29

# Directory structure
```
│  README.md
│  ResourceManagerApp.sln
│
├─External (SFML)
│  ├─include
│  └─lib
│
├─ResourceManagerApp
│  │ 
│  ├─Fonts
│  │      arial.ttf
│  └─src
│      │  Main.cpp
│      ├─controller
│      │      Game.cpp
│      │      Game.h
│      ├─model
│      │      Graph.cpp
│      │      Graph.h
│      │      World.cpp
│      │      World.h
│      └─view
│              Screen.cpp
│              Screen.h
|
├─testcase
   │  resource.txt
   │  ResourceManagerApp.exe
   │
   └─Fonts
           arial.ttf           
```

# How to use?
Please navigate to the 'testcase' folder and run ResourceManagerApp.exe. Make sure that the 'resource.txt' file and 'Fonts/arial.ttf' are present in the same directory.

Once executed, you will see a topologically sorted directed acyclic graph.

There are several ways to operate the application:

* Click on nodes to enable/disable them using the mouse.
* Scroll the mouse wheel horizontally to move the canvas and view more nodes.
* Use the following keyboard commands (only allowing letters, numbers, spaces, and the Enter key). Enter to confirm the command. The entered commands will be displayed on the screen:
    - addnode A
    - addedge A B (B relies on A)
    - enable A
    - disable A
    - printgraph

# Code Explanation
The code is written in C++ and utilizes the SFML (Simple and Fast Multimedia Library). SFML provides basic rendering and input handling functionalities. I implemented the fundamental game loop: processInput, update, and render.

I used the MVC (Model-View-Controller) design pattern for development. 
The Controller (Class Game) manages the game loop, user input processing, and passes user input events to the Model and View components.

The Model (Class World) consists of a data structure representing a directed acyclic graph (DAG) to store the dependency relationships between items.

The View (Class Screen) displays the game interface, showcasing user input and visualizing the Model (DAG) by rendering nodes and edges. It presents a graphical representation of the user's input and the dependencies between items stored in the Model.

# What I've Done?

In the Controller:
- Read 'resource.txt' before the game starts.
- Write to 'resource.txt' after the game ends.
- Handle mouse scroll input to notify the View for canvas movement.
- Handle mouse click events to retrieve node information corresponding to the clicked position from the View and trigger node state flipping in the Model.

In the Model's Class DAG:
- Maintained a directed acyclic graph (DAG) and provided the following public methods:
   - void addNode(string name);
   - void addEdge(string parentName, string childName);
   - void disableNode(string name);
   - void enableNode(string name);
   - void printGraph();
   - void processUserInput(string userInput);
   - vector<Node*> getTopologicalOrder();
   - void toggleNode(Node* node);

In the View:
- Loaded fonts, set window parameters, divided the window into 'game' and 'hud' views.
- Displayed operational prompts and user input in the 'hud'.
- Visualized the DAG in the 'game' view, arranging it from left to right in topological order. Nodes' colors are determined based on their 'enabled' status, and arcs connect the nodes. 
- Calculated and returned node pointers to the Controller based on the mouse position.