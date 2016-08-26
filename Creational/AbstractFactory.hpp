/*
 * file:       AbstractFactory.hpp
 *
 * created:    25.08.2016
 * author:     Anton Kashcheev
 */

#ifndef CREATIONAL_ABSTRACTFACTORY_HPP
#define CREATIONAL_ABSTRACTFACTORY_HPP

// создание общих групп объектов

/*
 * лучше всего сделать
 * на макросах с переменным числом аргументов
 *
 * осталось с ними разобраться
 */

#include "../Common/Templates.hpp"

#define tplAbstractFactoryMethod(TYPE_NAME)				\
static TYPE_NAME *create##TYPE_NAME()					\
{														\
	return new TYPE_NAME();								\
}														\
														\
template<class ... Args>								\
static TYPE_NAME *create##TYPE_NAME(Args ... args)		\
{														\
	return new TYPE_NAME(templates::foward(args) ...);	\
}

#define tplAbstractFactory(FACTORY_NAME, MESSAGE, ...)	\
namespace tpl											\
{														\
class FACTORY_NAME										\
{														\
public:													\
	FACTORY_NAME() { /*std::cout << MESSAGE << '\n';*/ }	\
};														\
}

#endif // CREATIONAL_ABSTRACTFACTORY_HPP
