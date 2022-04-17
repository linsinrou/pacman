#ifndef GHOST_H
#define GHOST_H

class ghost
{
public:
	ghost(int, int);
	void ghost1_move(int, int);
	void ghost2_move(int, int);
	void ghost3_move(int, int);
	void ghost4_move(int, int);
private:
	int x;
	int y;
};
#endif