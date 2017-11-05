
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
	//Buffer<int ,i> bx; //i must a constant parameter
}





/////////////////////////////////////////////////
template<class T, int i> T& lookup(Buffer<T, i>& b, const char*p);

class Record
{
	const char r[12];
};

template <class T> class vector {};
template<class T> T* create();

void f3()
{
	vector<int> v;
	int *p = create<int>();
}

template<class T, class U> T implicit_cast(U u) { return u; }

void g(int i)
{
	//implicit_cast(i);
	implicit_cast<double> (i);
	implicit_cast<char, double>(i);
	//implicit_cast<char*, int>(i); // int -> char*, error
}


