/*
 * file:       FactoryMethod.hpp
 *
 * created:    25.08.2016
 * author:     Anton Kashcheev
 */

#ifndef CREATIONAL_FACTORYMETHOD_HPP
#define CREATIONAL_FACTORYMETHOD_HPP

#include "../Common/Common.hpp"

namespace tpl {

//class Object
//{
//public:
//	virtual ~Object()
//	{
//	}
//};

// фабличный метод - обобщенный конструктор

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
	return new Object(tpl::templates::foward(args) ...);
}

}

#endif // CREATIONAL_FACTORYMETHOD_HPP
