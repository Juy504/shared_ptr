#ifndef __SHARED_PTR_H__
#define __SHARED_PTR_H__
#include "shared_count.h"
template<class T>
class shared_ptr{
	typedef shared_ptr<T> this_type;
	public:
	shared_ptr():px(0),pn()
	{}
	shared_ptr(T* p):px(p),pn(p)
	{
		cout<<"construct shared_ptr object"<<endl;
	}
	shared_ptr(shared_ptr<T> const &r)
		:px(r.px),pn(r.pn)
	{
		cout<<"copy construct shared_ptr object"<<endl;
	}
	~shared_ptr()
	{
		cout<<"free shared_ptr object"<<endl;
	}
	shared_ptr& operator=(shared_ptr<T> const& r)
	{
		this_type(r).swap(*this);
		return *this;
	}
	void reset()
	{
		this_type().swap(*this);
	}
	void reset(T* p)
	{
		assert(p == 0 || p == px);
		this_type(p).swap(*this);
	}
	long use_count()
	{
		return pn.use_count();
	}
	void swap(shared_ptr<T>& r)
	{
		T* tmp = r.px;
		r.px = px;
		px = tmp;
		pn.swap(r.pn);
	}
	public:
	T operator*()const
	{
		return *get();
	}
	T* operator->()const
	{
		return get();
	}
	void get()const
	{
		return px;
	}
	private:
	shared_count<T> pn;
	T *px;
};
#endif
