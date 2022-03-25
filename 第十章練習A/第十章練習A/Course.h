#ifndef Course_h
#define Course_h
#include<iostream>
using namespace std;

class Course
{
public:
	void setMath(int);
	void setEnglish(int);
	void setComputer(int);
	int getMath(); 
	int getEnglish();
	int getComputer();
	int getSum();
	int getAverage();
	void printScore();
private:
	int math;
	int english;
	int computer;
};
#endif