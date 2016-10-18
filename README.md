# The Risk Game #

This is the project for Object-Oriented Programming classes at Faculty of Mechatronics, Warsaw University of Technology.

The idea for the game was inspired by the [strategy board game](https://en.wikipedia.org/wiki/Risk_(game)) of the same name with minor changes in the rules.

The program was written in **C++** language with the usage of following libraries:

* [Qt](https://www.qt.io/)
* [TinyXML2](http://www.grinninglizard.com/tinyxml2/index.html)

Also, the **XML** language was used to store the world information.
* * *
## Example solutions ##

### How does map work? ###
Information about the world (continents, regions, troops) is contained in `map.xml` file under `resource/map/`. There were number number of reasons why to use this format:

* It is easy to write a .xml file
* It is easy to modify it
* There are many C++ libraries to parse .xml files

**This section explains the logic behind `CMapDisplay` class**

One of the features is that a player would choose a region by clicking on it. Because the world map is stored as a .png file, it was necessary to deduce what region the player clicked on. It was solved by providing additional file called `MAPA_INFO.png`, which used *Red* colour channel to assign pixels to their respective regions. So, when a player clickes on the actual map, *x* and *y* position of the click is calculated into its position on the info map. 
Here's the info map which was used in the game: 
![MAPA_INFO.png](https://bitbucket.org/repo/Kkbo9e/images/2539803660-MAPA_INFO.png)

### Moving an army ###
Another feature is that a player can move his/her army from any region to any other, provided that there's a connection between them. To determine this [Dijkstra's algorithm](https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm) was used.
## Contact ##
Piotr Pokorski

piotr.pokorski94@gmail.com