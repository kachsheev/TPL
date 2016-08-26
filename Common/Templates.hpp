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
T&& foward(typename RemoveReference<T>::type& object) noexcept
{
	return static_cast<T &&>(object);
}

}}

#endif // COMMON_HPP
