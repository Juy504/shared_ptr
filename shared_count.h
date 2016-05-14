#ifndef __SHARED_COUNT_H__
#define __SHARED_COUNT_H__
#include "sp_counted_base.h"
#include "sp_counted_impl_xx.h"
template<class T>
class shared_count
{
	public:
	shared_count():pi_(0)
	{}
	shared_count(T*p):pi_(new sp_counted_impl_xx<T>(p))
	{}
	shared_count(shared_count<T>const&r)
		:pi_(r.pi_)
	{
		if(pi_ != 0)
			pi_->add_ref_copy();
		cout<<"copy construct shared_count object"<<endl;
	}
	~shared_count()
	{
		if(pi_ != 0)
			pi_->release();
		cout<<"free shared_count object"<<endl;
	}
	shared_count& operator=(shared_count<T>const& r)
	{
		sp_counted_base *tmp = r.pi_;
		if(tmp != pi_)
		{
			if(tmp != 0)
			{
				tmp->add_ref_copy();	
			}
			if(pi_ != 0)
			{
				pi_->release();
			}
		}
		return *this;
	}
	public:
	long use_count() const
	{
		return pi_ != 0?pi_->use_count():0;
	}
	void swap(shared_count<T> &r)
	{
		sp_counted_base* tmp = r.pi_;
		r.pi_ = pi_;
		pi_ = tmp;
	}
	bool unique() const
	{
		return use_count() == 1;
	}
	private:
	sp_counted_base *pi_;
};
template <class T>
class weak_count
{
public:
	weak_count():pi_(0)
	{
		cout<<"construct weak_count object"<<endl;
	}
	weak_count(weak_count<T>const &r)
		:pi_(r.pi_)
	{
		if(pi_ != 0)
			pi_->weak_add->ref();
	}
	weak_count(shared_count<T>const &r)
		:pi_(r.pi_)
	{
		if(pi_ != 0)
			pi_->weak_add_ref();
	}
	~weak_count()
	{
		cout<<"free weak_count object"<<endl;
		if(pi_ != 0)
		{
			pi_->weak_release();
		}
	}
public:
	long use_count() const
	{
		return pi_ != 0?pi_->use_count():0;
	}
	bool empty()
	{
		return pi_ == 0;
	}
private:
	sp_counted_base *pi_;
};
#endif
