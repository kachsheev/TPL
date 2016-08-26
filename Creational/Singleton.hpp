/*
 * file:       Singleton.hpp
 *
 * created:    25.08.2016
 * author:     Anton Kashcheev
 */
#ifndef CREATIONAL_SINGLETON_HPP
#define CREATIONAL_SINGLETON_HPP

#include "../Common/Templates.hpp"

// declaration
namespace tpl
{

template<class Object>
class Singleton final
{
public:
	Singleton() = delete;
	Singleton(const Singleton &) = delete;
	Singleton(Singleton &&) = delete;

	Singleton &operator =(const Singleton &) = delete;
	const Singleton &operator =(Singleton &&) = delete;

	static Object &instance();

	template<class ... Args>
	static Object &instance(Args ... args);
};

}

// implementation
namespace tpl
{

template<class Object>
Object &Singleton::instance()
{
	static Object object();
	return object;
}

template<class Object>
template<class ... Args>
Object &Singleton::instance(Args ... args)
{
	static Object object(templates::foward(args) ...);
	return object;
}

}

#endif // CREATIONAL_SINGLETON_HPP
