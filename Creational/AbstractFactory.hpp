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

#define OVERLOADING(SUBJ) tplAbstractFactoryMethod(SUBJ)
#include "../Common/Preprocessor.hpp"


#define tplAbstractFactory(FACTORY_NAME, ...)			\
namespace tpl											\
{														\
class FACTORY_NAME										\
{														\
public:													\
	FACTORY_NAME() = delete;							\
	FACTORY_NAME(FACTORY_NAME &&factory) = delete;		\
	FACTORY_NAME(const FACTORY_NAME &factory);			\
														\
	operator=(FACTORY_NAME &&factory) = delete;			\
	operator=(const FACTORY_NAME &factory) = delete;	\
														\
	tplGenerator(__VA_ARGS__)							\
};														\
}

#endif // CREATIONAL_ABSTRACTFACTORY_HPP
