# 42_So_Long

<div align="center"><br>
  <img src="https://user-images.githubusercontent.com/76601369/110706242-77158d00-81ef-11eb-8085-5da6f0988553.jpg" alt="https://user-images.githubusercontent.com/76601369/110706242-77158d00-81ef-11eb-8085-5da6f0988553.jpg" width="650" height="300">
</div>
</br>
<p> The So_Long project is a simple 2D game made with the MinilibX library.
</br> It will read a valid <code>.ber</code> file and render the game from that. You can use <code>W</code>, <code>A</code>, <code>S</code> and <code>D</code> to move around.
</p>
<p> Clone the project:</p>

```bash
git clone https://github.com/amarques02/42_So_long.git
```
<p> To run, use make to compile and pass the arguments you want as showed:</p>

```bash
make && ./so_long maze.ber
```
<p> Please make sure:
<ul>
	<li>You insert a valid map(It should exist in your root repo)</li>
	<li>The map should be surrounded by '1's (walls)</li>
  <li>It should also be rectangular</li>
  <li>Map can't have more than one 'P' (player) and 'E' (exit)</li>
  <li>There should be a valid path to complete the level</li>
</ul>
Otherwise you will receive an Error message.
</p>
<p> The goal of the game is to collect all the collectibles in the map - while avoiding the enemies!
</br> After that, head to the exit to complete the level.
</p>
