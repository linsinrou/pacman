#include "Pacman.h"
#include <iostream>

using namespace std;

char map[25][50] = {
		"+###############################################+",
		"|........#.....................####.............|",
		"|........#........................#.............|",
		"|##.####..#####.##...#########....#.............|",
		"|...#........................#..................|",
		"|...####................#....##############.....|",
		"|........#....####......#.........#.............|",
		"|...######....#......#..#.........#.............|",
		"|.............####...#.....#......#...######....|",
		"|..####..###.........##...........#........#....|",
		"|..........######..#######.###....#####....###..|",
		"|............................................#..|",
		"|#.###.####......###...#######....#########..#..|",
		"|...#.............#....#..............#.........|",
		"|..#####..........#....#..............########..|",
		"|...#..####.......###.................#.....##..|",
		"|......#............#.................#.....#...|",
		"|##..####..........############...#####.....#...|",
		"|......#.....###....#.................#.....#...|",
		"|......#.......#....#.....####........#.....#...|",
		"|......###..#########........#..........#####...|",
		"|......#............####.....#........##........|",
		"|......#.......######........#####....#...######|",
		"|...................#.........#.................|",
		"|+#############################################+|",
};

Pacman::Pacman()
{
	x = 1;
	y = 1;
}

Pacman::Pacman(int x, int y) {
	this->x = x;
	this->y = y;
}

void Pacman::ShowMap()
{
	for (int i = 0; i < 25; i++) {
		cout << map[i] << endl;
	}
}