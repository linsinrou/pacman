#include <iostream>
#include <windows.h>
#include <vector>
#include "pacman.h"

using namespace std;
char newmap[25][50];

char map[25][50] = {
		"+###############################################+",
		"#........#.....................####.............#",
		"#........#........................#.............#",
		"###.####..#####.##...#########....#.............#",
		"#...#........................#..................#",
		"#...####................#....##############.....#",
		"#........#....####......#.........#.............#",
		"#...######....#......#..#.........#.............#",
		"#.............####...#.....#......#...######....#",
		"#..####..###.........##...........#........#....#",
		"#..........######..#######.###....#####....###..#",
		"#............................................#..#",
		"##.###.####......###...#######....#########..#..#",
		"#...#.............#....#..............#.........#",
		"#..#####..........#....#..............########..#",
		"#...#..####.......###.................#.....##..#",
		"#......#............#.................#.....#...#",
		"###..####..........############...#####.....#...#",
		"#......#.....###....#.................#.....#...#",
		"#......#.......#....#.....####........#.....#...#",
		"#......###..#########........#..........#####...#",
		"#......#............####.....#........##........#",
		"#......#.......######........#####....#...#######",
		"#...................#.........#.................#",
		"#################################################",
};

void getxy(short x, short y)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE); // 擷取指定標準裝置的控制代碼(標準輸入、標準輸出或標準錯誤)。
	COORD position = { x, y };

	SetConsoleCursorPosition(hStdout, position);
}

struct walk 
{
	int count;
	int x;
	int y;
	int back;
};

struct target
{
	int x;
	int y;
};

vector<target> walk_queue;

vector<walk> arr;

void ShowMap()
{
	for (int i = 0; i < 25; i++) {
		cout << map[i] << endl;
	}
}

void AddArray(int x, int y, int wc, int back)
{
	if (newmap[y][x] == ' ' || newmap[y][x] == '.')
	{
		newmap[y][x] = '#';
		walk tmp;
		tmp.x = x;
		tmp.y = y;
		tmp.count = wc;
		tmp.back = back;
		arr.push_back(tmp);
	}
}

void FindRoad(int nx, int ny, int x, int y)
{
	//x,y = pacman; nx,ny = ghost
	memcpy(newmap, map, sizeof(map));//將 map 指向的記憶體區塊複製 sizeof(map) 個到 tmp_map 指向的記憶體區塊
	
	walk tmp;
	tmp.x = nx;
	tmp.y = ny;
	tmp.count = 0;
	tmp.back = -1;
	arr.push_back(tmp);

	
	for (int i = 0; i < arr.size(); i++)//FindRoad
	{
		if (arr[i].x == x && arr[i].y == y) {
			
			target tmp2;
			while (arr[i].count != 0) {
				tmp2.x = arr[i].x;
				tmp2.y = arr[i].y;
				walk_queue.push_back(tmp2);

				i = arr[i].back;
			}

			break;
		}

		AddArray(arr[i].x + 1, arr[i].y, arr[i].count + 1, i);
		AddArray(arr[i].x - 1, arr[i].y, arr[i].count + 1, i);
		AddArray(arr[i].x, arr[i].y + 1, arr[i].count + 1, i);
		AddArray(arr[i].x, arr[i].y - 1, arr[i].count + 1, i);

	}

	arr.clear();
}

int main()
{
	/*char map[25][50] = {
		"+###############################################+",
		"#........#.....................####.............#",
		"#........#........................#.............#",
		"###.####..#####.##...#########....#.............#",
		"#...#........................#..................#",
		"#...####................#....##############.....#",
		"#........#....####......#.........#.............#",
		"#...######....#......#..#.........#.............#",
		"#.............####...#.....#......#...######....#",
		"#..####..###.........##...........#........#....#",
		"#..........######..#######.###....#####....###..#",
		"#............................................#..#",
		"##.###.####......###...#######....#########..#..#",
		"#...#.............#....#..............#.........#",
		"#..#####..........#....#..............########..#",
		"#...#..####.......###.................#.....##..#",
		"#......#............#.................#.....#...#",
		"###..####..........############...#####.....#...#",
		"#......#.....###....#.................#.....#...#",
		"#......#.......#....#.....####........#.....#...#",
		"#......###..#########........#..........#####...#",
		"#......#............####.....#........##........#",
		"#......#.......######........#####....#...#######",
		"#...................#.........#.................#",
		"#################################################",
	};*/

	bool running = true;
	int x = 15, y = 16, endx = 1, endy = 1, point = 0, newx, newy;
	int frame = 0, oldx, oldy;

	//Pacman openmap;

	system("cls");
	//openmap.ShowMap();
	ShowMap();

	getxy(x, y); 
	cout << "P";

	getxy(endx, endy);
	cout << "E";
	FindRoad(endx, endy, x, y);

	while (running)
	{
		/*getxy(endx, endy);
		cout << ".";

		if (map[endy][endx + 1] == '.')
		{
			endx++;//right
		}
		else if (map[endy][endx + 1] == '#' || map[endy + 1][endx] == '#')
		{
			if (map[endy + 1][endx] == '#')
			{
				endx--;
			}
			else
				endy++;
		}
		
		getxy(endx, endy);
		cout << "E";*/

		getxy(x, y); 
		cout << " ";

		oldx = x;
		oldy = y;

		if (GetAsyncKeyState(VK_UP)) 
		{
			if (map[y - 1][x] == '.') 
			{ 
				y--; 
				point++; 
			}
			else if (map[y - 1][x] == ' ')
			{
				y--;
			}	
		}

		if (GetAsyncKeyState(VK_DOWN)) 
		{
			if (map[y + 1][x] == '.') 
			{ 
				y++; 
				point++; 
			}
			else if (map[y + 1][x] == ' ')
			{
				y++;
			}		
		}

		if (GetAsyncKeyState(VK_LEFT))
		{
			if (map[y][x - 1] == '.') 
			{ 
				x--;
				point++; 
			}
			else if (map[y][x - 1] == ' ')
			{
				x--;
			}	
		}

		if (GetAsyncKeyState(VK_RIGHT)) 
		{
			if (map[y][x + 1] == '.') 
			{ 
				x++; 
				point++; 
			}
			else if (map[y][x + 1] == ' ')
			{
				x++;
			}				
		}

		if (oldx != x || oldy != y) 
		{
			FindRoad(endx, endy, x, y);
		}

		getxy(x, y); 
		cout << "P";

		getxy(endx, endy);
		cout << ".";

		if (frame % 3 == 0 && walk_queue.size() != 0)
		{
			endx = walk_queue.back().x;
			endy = walk_queue.back().y;
			walk_queue.pop_back();
		}

		getxy(endx, endy);
		cout << "E";

		if (endx == x && endy == y)
		{
			break;
		}

		getxy(50, 1); 
		cout << "上下左右鍵控制，碰到E結束: " << point;
		Sleep(100);
		frame++;
		
	}

	system("cls");
	cout << "You Lose and your score is : " << point;
	cin.get();


	return 0;
}