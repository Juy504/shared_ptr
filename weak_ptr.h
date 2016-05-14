#ifndef __WEAK_PTR_H__
#define __WEAK_PTR_H__
#include "shared_ptr.h"
#include "shared_count.h"
template <class T>
class shared_ptr;
template <class T>
class weak_ptr
{
	typedef T element_type;
	friend class shared_ptr<T>;
public:
	weak_ptr():px(0)pn()
	{}
	weak_ptr(weak_ptr<T>const &r)
		:px(r.px),pn(r.pn)
	{}
	weak_ptr(shared_ptr<T>const &r)
		:px(r.px),pn(r.pn)
	{}
	weak_ptr& operator=(shared_ptr<T>const &r)
	{
		px = r.px;
		pn = r.pn;
		return *this;
	}
	bool expired() const
	{
		return pn.use_count_ == 0;
	}
	shared_ptr<T> lock() const
	{
		return shared_ptr<element_type>(*this);
	}
	long use_count() const
	{
		return pn.use_count();
	}
private:
	weak_count<T> pn;
	T* px;
};
#endif
