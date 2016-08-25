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
struct RemoveRefference
{
	typedef T type;
};
template<class T>
struct RemoveRefference<T &>
{
	typedef T type;
};
template<class T>
struct RemoveRefference<T &&>
{
	typedef T type;
};

template<class T> inline
T&& foward(typename RemoveRefference<T>::type& object) noexcept
{
	return static_cast<T &&>(object);
}

}}

#endif // COMMON_HPP
