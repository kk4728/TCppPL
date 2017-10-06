#include <iostream>
#include <cstdio>
#include <vector>






class File_ptr
{
	FILE* p;
	
public:
	File_ptr(const char* n, const char* a) {p = fopen(n, a);}
	File_ptr(FILE* pp) { p = pp; }

	~File_ptr() { if(p) fclose(p); }

	operator FILE* () { return p; }
	
};


class Y
{
	int *p;
	void init();

public:
	Y(int s) { p = new int [s]; init (); }
	~Y() { delete p; }

};

class Z
{
	std::vector<int> p;

	void init();

public:
	Z(int s) : p(s) { init (); }
	
};

int main()

{

	
	return 0;
}
