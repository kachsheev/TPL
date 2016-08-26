/*
 * file:       Adapter.hpp
 *
 * created:    25.08.2016
 * author:     Anton Kashcheev
 */

#ifndef STRUCTURIAL_ADAPTER_HPP
#define STRUCTURIAL_ADAPTER_HPP

#include "../Common/Templates.hpp"

#define tplAdapter(OBJECT_NAME, METHOD_NAME)	\
namespace tpl									\
{												\
template<class Object>							\
class Adapter									\
{												\
	Object object;								\
public:											\
	Adapter();									\
												\
	template<class ... Args>					\
	Adapter(Args ... args);						\
	\
	\
	\
};												\
												\
template<class Object>							\
Adapter::Adapter():								\
		object()								\
{												\
}												\
template<class Object>							\
template<class ... Args>						\
Adapter::Adapter(Args ... args):				\
		object(templates::foward(args) ...)		\
{												\
}												\
}												\

#endif // STRUCTURIAL_ADAPTER_HPP
