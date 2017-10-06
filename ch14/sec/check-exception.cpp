

class X {};
class Y {};

class B
{
public:
	virtual void f();
	virtual void g() throw(X, Y);
	virtual void h() throw(X);
};

class D: public B
{
public:
	void f() throw (X);
	void g() throw (X);
	//void h() throw (X,Y); //error, 限定变宽松了

};
