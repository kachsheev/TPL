/*
 * file:       Common.hpp
 *
 * created:    25.08.2016
 * author:     Anton Kashcheev
 */

#ifndef COMMON_HPP
#define COMMON_HPP

#include "Types.hpp"

namespace tpl
{namespace templates
{

template<class T>
struct RemoveReference
{
	typedef T Type;
};
template<class T>
struct RemoveReference<T &>
{
	typedef T Type;
};
template<class T>
struct RemoveReference<T &&>
{
	typedef T Type;
};

template<class T>
struct Traits: public RemoveReference<T>
{
	typedef typename RemoveReference<T>::Type Type;
	typedef Type & Reference;
	typedef const Type & ConstReference;
	typedef Type && LReference;
	typedef Type * Pointer;
	typedef const Type * ConstPointer;
	typedef Type * const PointerConst;
	typedef const Type * const ConstPointerConst;
};

template<class T>
struct Traits<T &>: public RemoveReference<T &>
{
	typedef typename RemoveReference<T>::Type Type;
	typedef Type & Reference;
	typedef const Type & ConstReference;
	typedef Type && LReference;
	typedef Type * Pointer;
	typedef const Type * ConstPointer;
	typedef Type * const PointerConst;
	typedef const Type * const ConstPointerConst;
};

template<class T>
struct Traits<const T &>: public RemoveReference<const T &>
{
	typedef typename RemoveReference<T>::Type Type;
	typedef Type & Reference;
	typedef const Type & ConstReference;
	typedef Type && LReference;
	typedef Type * Pointer;
	typedef const Type * ConstPointer;
	typedef Type * const PointerConst;
	typedef const Type * const ConstPointerConst;
};

template<class T>
struct Traits<T &&>: public RemoveReference<T &&>
{
	typedef typename RemoveReference<T>::Type Type;
	typedef Type & Reference;
	typedef const Type & ConstReference;
	typedef Type && LReference;
	typedef Type * Pointer;
	typedef const Type * ConstPointer;
	typedef Type * const PointerConst;
	typedef const Type * const ConstPointerConst;
};

template<class T>
struct Traits<T *>
{
	typedef T Type;
	typedef Type & Reference;
	typedef const Type & ConstReference;
	typedef Type && LReference;
	typedef Type * Pointer;
	typedef const Type * ConstPointer;
	typedef Type * const PointerConst;
	typedef const Type * const ConstPointerConst;
};

template<class T>
struct Traits<const T *>
{
	typedef T Type;
	typedef Type & Reference;
	typedef const Type & ConstReference;
	typedef Type && LReference;
	typedef Type * Pointer;
	typedef const Type * ConstPointer;
	typedef Type * const PointerConst;
	typedef const Type * const ConstPointerConst;
};

template<class T>
struct Traits<T * const>
{
	typedef T Type;
	typedef Type & Reference;
	typedef const Type & ConstReference;
	typedef Type && LReference;
	typedef Type * Pointer;
	typedef const Type * ConstPointer;
	typedef Type * const PointerConst;
	typedef const Type * const ConstPointerConst;
};

template<class T>
struct Traits<const T * const>
{
	typedef T Type;
	typedef Type & Reference;
	typedef const Type & ConstReference;
	typedef Type && LReference;
	typedef Type * Pointer;
	typedef const Type * ConstPointer;
	typedef Type * const PointerConst;
	typedef const Type * const ConstPointerConst;
};

template<class T> inline constexpr
T&& foward(T&& object) noexcept
{
	return static_cast<T &&>(object);
}

template<class T> inline constexpr
typename RemoveReference<T>::Type move(T &&object)
{
	return static_cast<typename RemoveReference<T>::Type &&>(object);
}

template<class ReturnType, class ... Args> constexpr
types::size_t countArgs(ReturnType (*)(Args ...))
{
	return sizeof ... (Args);
}

template<class Object, class ReturnType, class ... Args> constexpr
types::size_t countArgs(ReturnType (Object::*)(Args ...))
{
	return sizeof ... (Args);
}

template<class ... Args> constexpr
types::size_t countArgs()
{
	return sizeof ... (Args);
}

template<typename T> inline constexpr
const T &constantize(T &&obj) noexcept
{
	return static_cast<const T &>(obj);
}

}}

#endif // COMMON_HPP
