Simulation of the Tichu card game among 4 players in C++.

# Description

This project, written in C++, simulates a simplified version of the turn-based card game Tichu among 4 players. The players are divided into 2 teams, each consisting of 2 players, with teammates seated diagonally opposite each other. Each player starts with 14 cards and attempts to play all their cards by forming appropriate combinations in each round. The game ends when 3 out of the 4 players have no cards left.

At the start of each round, the player who won the previous round chooses a combination to play. The next player must either play a stronger combination of the same type or pass (if they lack or choose not to play such a combination). Once 3 players pass, the fourth player (the last player to play) wins all the cards from the table for that round.

Each combination consists of one or more cards and belongs to a specific category (type). In addition to the basic combinations, there are 4 special cards. Certain cards grant specific points to the player who collects them.

Each player has a name and an identifier that indicates their turn order in the game. The game maintains player scores, manages the start and end of each round, and displays the overall state, including the players' status and the table (based on the number of cards played). At the end of the game, the points of all players are tallied. The team with the highest score wins the game.

The project is divided into 4 deliverables. In the first deliverable, we are tasked with designing a class diagram for the Tichu game in the StarUML environment. The diagram includes all the main entities, variables, methods, associations, verbs, and multiplicities. In the remaining 3 deliverables, we implement the game in C++ code according to the requirements of each stage.
