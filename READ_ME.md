My rendition of the video game project by the 42 school.

The basic premise of the game involves collecting items on a map (2d array), then being able to exit once you've collected everything.
This game is completely written in C, using the mlx library which renders pixel data to a windowed screen using the X-window bitmap windowing system. 

Current features include:

2D sprite animations
Real time enemy pathfinding up to Nth enemies
Basic inventory system
Simple HUD indicators (step counter, time to win tracker, etc)
Fun, dynamic gameplay mechanics (pausing the chase by "playing dead", placing traps to ensnare enemies temporarily, bomb defusal, portals)
Scripted win and lose scenes (such as being killed by enemies, losing when the bomb timer reaches 0)

Working on:
Boss levels
Combat system
Healh bar and life system
