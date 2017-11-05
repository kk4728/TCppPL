
template <class T, int i>
class Buffer
{
	T v[i];
	int sz;

public:
	Buffer() : sz(i) {}
};

void f1()
{
	Buffer< char, 127> cbuff;

	Buffer<double, 8> dbuff;
}

void f2(int i)
{
	Buffer<int ,i> bx; //i must a constant parameter
}


