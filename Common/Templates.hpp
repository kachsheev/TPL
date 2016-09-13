/*
 * file:       Common.hpp
 *
 * created:    25.08.2016
 * author:     Anton Kashcheev
 */

#ifndef COMMON_HPP
#define COMMON_HPP

namespace tpl
{namespace templates
{

template<class T>
struct RemoveReference
{
	typedef T type;
};
template<class T>
struct RemoveReference<T &>
{
	typedef T type;
};
template<class T>
struct RemoveReference<T &&>
{
	typedef T type;
};

template<class T> inline
constexpr T&& foward(typename RemoveReference<T>::type& object) noexcept
{
	return static_cast<T &&>(object);
}

template<class T> inline
constexpr typename RemoveReference<T>::type move(T &&object)
{
	return static_cast<typename RemoveReference<T>::type>(object);
}

template<class ReturnType, class ... Args>
constexpr unsigned int getCountArgs(ReturnType (*)(Args ...))
{
	return sizeof ... (Args);
}

template<class Object, class ReturnType, class ... Args>
constexpr unsigned int getCountArgs(ReturnType (Object::*)(Args ...))
{
	return sizeof ... (Args);
}

template<class ... Args>
constexpr unsigned int getCountArgs()
{
	return sizeof ... (Args);
}

}}

#endif // COMMON_HPP
