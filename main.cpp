//#include <iostream>
#include "shared_ptr.h"
#include "shared_count.h"
//using namespace std;

int main()
{
	int *p = new int(10);
	shared_ptr<int> pa(p);
	shared_ptr<int> pb(pa);
	pa.reset();
	cout<<pa.use_count()<<endl;
	cout<<pb.use_count()<<endl;
	return 0;
}
