#ifndef __SP_COUNTED_BASE_H__
#define __SP_COUNTED_BASE_H__
#include <iostream>
using namespace std;

//template<class T>
class sp_counted_base
{
	public:
	sp_counted_base():use_count_(1)
	{
		cout<<"construct sp_counted_base object"<<endl;
	}
	virtual	~sp_counted_base()
	{
		cout<<"free construct sp_counted_base object"<<endl;	
	}
	virtual void dispose() = 0;
	void destroy()
	{
		delete this;
	}
	void add_ref_copy()
	{
		++use_count_;
	}
	void weak_add_ref()
	{
		++weak_count_;
	}
	void release()
	{
		if(--use_count_ == 0)
			dispose();
	}
	void weak_release()
	{
		if(--weak_count_ == 0)
			destroy();
	}
	long use_count()
	{
		return use_count_;
	}
	private:
	long use_count_;
	long weak_count_;
};
#endif
