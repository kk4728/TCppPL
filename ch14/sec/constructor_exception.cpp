#include <iostream>

#include <vector>


using namespace std;




class X
{
	std::vector< int> v;

public:
	X(int) throw() ;
	X(char)  ;
	
};

X::X(int s) throw() 
try
	: v(s)
{

}
catch(...)
{


}


X::X(char s)  
try
	: v(s)
{

}
catch(...)
{

}
