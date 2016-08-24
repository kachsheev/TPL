/*
 * file:       FactoryMethod.hpp
 *
 * created:    25.08.2016
 * author:     Anton Kashcheev
 */

#ifndef FACTORYMETHOD_HPP
#define FACTORYMETHOD_HPP

#include "../Common/Common.hpp"

namespace tpl {

//class Object
//{
//public:
//	virtual ~Object()
//	{
//	}
//};

template<class Object>
class FactoryMethod
{
public:
	static Object *create();

	template<class ... Args>
	static Object *create(Args ... args);
};


template<class Object>
Object *FactoryMethod::create()
{
	return new Object();
}

template<class Object>
template<class ... Args>
Object *FactoryMethod::create(Args ... args)
{
	return new Object(tlp::templates::foward(args) ...);
}

}

#endif // FACTORYMETHOD_HPP
