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
 */

#include "../Common/Preprocessor.hpp"
#include "../Common/Templates.hpp"

#undef OVERLOADING
#define OVERLOADING(SUBJ) tplAbstractFactoryMethod(SUBJ)

#define tplAbstractFactoryMethod(TYPE_NAME)			\
template<class ... Args>								\
TYPE_NAME *create##TYPE_NAME(Args &&... args)	\
{														\
	return new TYPE_NAME(templates::foward(args) ...);	\
}

#define tplAbstractFactory(FACTORY_NAME, ...)						\
namespace tpl														\
{																	\
namespace FACTORY_NAME												\
{																	\
	tplGenerator(__VA_ARGS__)										\
}																	\
}

#endif // CREATIONAL_ABSTRACTFACTORY_HPP
