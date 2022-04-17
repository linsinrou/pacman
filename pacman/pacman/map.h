#ifndef MAP_H
#define MAP_H
class map
{
public:
	map(int, int, int);
	void getmap(int, int) const;
	void getpoint(int) const;
	void getlife(int) const;
	void getpoint(int) const;
	void move_x(int);
	void move_y(int);
	void print();
private:
	int x;
	int y;
	int count;
};
#endif
