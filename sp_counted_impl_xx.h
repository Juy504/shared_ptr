#ifndef __SP_COUNTED_IMPL_XX_H__
#define __SP_COUNTED_IMPL_XX_H__
#include "sp_counted_base.h"
template<class T>
class sp_counted_impl_xx : public  sp_counted_base
{
	public:
	sp_counted_impl_xx(T*x)
		:px_(x)
	{
		cout<<"create sp_counted_impl_xx"<<endl;
	}
	~sp_counted_impl_xx()
	{
		cout<<"free sp_counted_impl_xx"<<endl;
	}
	virtual	void dispose()
	{
		delete (px_);
		delete this;
	}
	private:
		T* px_;
};
#endif
