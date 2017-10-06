#include <iostream>
#include <limits.h>

using namespace std;

class Matherr 
{
public:
	virtual void  debug_print() const  { std::cerr << "Math error"; }
};

class Overflow : public Matherr
{};

class Underflow : public Matherr {};
class Zerodivid : public Matherr {};

class Int_overflow : public Matherr
{
	const char* op;
	int a1, a2;
	
public:
	Int_overflow(const char* p, int a, int b)
	{
		op = p;
		a1 = a;
		a2 = b;
	}

	virtual void debug_print () const
	{
		cerr << op << '(' << a1 << ',' << a2 << ')' << endl;
	}
}	;

void g()
{
	try
	{
	}
	catch(Overflow) {}
	catch(Underflow) {}
	catch(Zerodivid) {}

}

int add(int x, int y)
{
	if( (x>0 && y>0 && x>INT_MAX-y) || (x<0 && y<0 && x < INT_MAX -y) )
	{
		throw Int_overflow("+", x, y);
	}

	return x + y;
}

void f()
{
	try
	{
		//g();
		int i1 = add(1, 2);
		int i2 = add(INT_MAX, -2);
		int i3 = add(INT_MAX, 2);
	}
	catch(Overflow)
	{
	}
	catch(Underflow)
	{
	}
	catch(Int_overflow& e)
	{
		e.debug_print();
	}
	catch(Matherr& m)
	{
		cout << "base class : ";
		m.debug_print();
	}

}


int main()
{
	f();
	return 0;
}
