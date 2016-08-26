/*
 * file:       Prototype.hpp
 *
 * created:    25.08.2016
 * author:     Anton Kashcheev
 */
#ifndef CREATIONAL_PROTOTYPE_HPP
#define CREATIONAL_PROTOTYPE_HPP

#include "../Common/Templates.hpp"

// declaration
namespace tpl
{

/* Аналогично AbstractFactory нужно сделать порототип от множества типов.
 *
 * Разница только в том, что тут понадобится наследование и более крутое
 * использование макросов
 */

template<class Object>
class SinglePrototype
{
	Object object;
public:
	SinglePrototype();

	template<class ... Args>
	SinglePrototype(Args ... args);

	Object *clone();
};

}

// implementation
namespace tpl
{

template<class Object>
SinglePrototype<Object>::SinglePrototype() :
		object()
{
}

template<class Object>
template<class ... Args>
SinglePrototype<Object>::SinglePrototype(Args ... args) :
		object(templates::foward(args) ...)
{
}

template<class Object>
Object *SinglePrototype<Object>::clone()
{
	return new Object(object);
}

}

#define tplPrototypeClone(OBJECT)			\
		OBJECT *clone##OBJECT()						\
		{											\
			return singlePrototype##OBJECT.clone();	\
		}

#define tplPrototypeEncapsulate(OBJECT)					\
		SinglePrototype<OBJECT> singlePrototype##OBJECT;

#define tplPrototype(PROTOTYPE_NAME, MESSAGE, ...)	\
		namespace tpl												\
		{															\
		class PROTOTYPE_NAME										\
		{															\
		public:														\
			PROTOTYPE_NAME() { /*std::cout << MESSAGE << '\n';*/ }		\
		};															\
		}

#endif // PROTOTYPE_HPP
