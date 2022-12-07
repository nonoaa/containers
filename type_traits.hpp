#ifndef TYPE_TRAITS_HPP
#define TYPE_TRAITS_HPP

#include "type_traits"

namespace ft
{
	// enable_if
	template <bool B, typename T = void>
	struct enable_if {};

	template <typename T>
	struct enable_if<true, T> { typedef T type; };

	struct false_type
	{
		typedef bool value_type;
		typedef false_type type;
		static const value_type value = false;
	};

	struct true_type
	{
		typedef bool value_type;
		typedef true_type type;
		static const value_type value = true;
	};

	template <class T> struct is_integral : public false_type {};

	template<> struct is_integral<bool> : public true_type {};
	template<> struct is_integral<char> : public true_type {};
	template<> struct is_integral<char16_t> : public true_type {};
	template<> struct is_integral<char32_t> : public true_type {};
	template<> struct is_integral<wchar_t> : public true_type {};
	template<> struct is_integral<signed char> : public true_type {};
	template<> struct is_integral<short int> : public true_type {};
	template<> struct is_integral<int> : public true_type {};
	template<> struct is_integral<long int> : public true_type {};
	template<> struct is_integral<unsigned char> : public true_type {};
	template<> struct is_integral<unsigned short int> : public true_type {};
	template<> struct is_integral<unsigned int> : public true_type {};
	template<> struct is_integral<unsigned long int> : public true_type {};
	template<> struct is_integral<unsigned long long> : public true_type {};

	template<> struct is_integral<const bool> : public true_type {};
	template<> struct is_integral<const char> : public true_type {};
	template<> struct is_integral<const char16_t> : public true_type {};
	template<> struct is_integral<const char32_t> : public true_type {};
	template<> struct is_integral<const wchar_t> : public true_type {};
	template<> struct is_integral<const signed char> : public true_type {};
	template<> struct is_integral<const short int> : public true_type {};
	template<> struct is_integral<const int> : public true_type {};
	template<> struct is_integral<const long int> : public true_type {};
	template<> struct is_integral<const unsigned char> : public true_type {};
	template<> struct is_integral<const unsigned short int> : public true_type {};
	template<> struct is_integral<const unsigned int> : public true_type {};
	template<> struct is_integral<const unsigned long int> : public true_type {};
	template<> struct is_integral<const unsigned long long> : public true_type {};


	// template <class T> struct is_integral : public std::false_type {};

	// template<> struct is_integral<bool> : public std::true_type {};
	// template<> struct is_integral<char> : public std::true_type {};
	// template<> struct is_integral<char16_t> : public std::true_type {};
	// template<> struct is_integral<char32_t> : public std::true_type {};
	// template<> struct is_integral<wchar_t> : public std::true_type {};
	// template<> struct is_integral<signed char> : public std::true_type {};
	// template<> struct is_integral<short int> : public std::true_type {};
	// template<> struct is_integral<int> : public std::true_type {};
	// template<> struct is_integral<long int> : public std::true_type {};
	// template<> struct is_integral<long long> : public std::true_type {};
	// template<> struct is_integral<unsigned char> : public std::true_type {};
	// template<> struct is_integral<unsigned short int> : public std::true_type {};
	// template<> struct is_integral<unsigned int> : public std::true_type {};
	// template<> struct is_integral<unsigned long int> : public std::true_type {};
	// template<> struct is_integral<unsigned long long> : public std::true_type {};

	// template<> struct is_integral<const bool> : public std::true_type {};
	// template<> struct is_integral<const char> : public std::true_type {};
	// template<> struct is_integral<const char16_t> : public std::true_type {};
	// template<> struct is_integral<const char32_t> : public std::true_type {};
	// template<> struct is_integral<const wchar_t> : public std::true_type {};
	// template<> struct is_integral<const signed char> : public std::true_type {};
	// template<> struct is_integral<const short int> : public std::true_type {};
	// template<> struct is_integral<const int> : public std::true_type {};
	// template<> struct is_integral<const long int> : public std::true_type {};
	// template<> struct is_integral<const long long> : public std::true_type {};
	// template<> struct is_integral<const unsigned char> : public std::true_type {};
	// template<> struct is_integral<const unsigned short int> : public std::true_type {};
	// template<> struct is_integral<const unsigned int> : public std::true_type {};
	// template<> struct is_integral<const unsigned long int> : public std::true_type {};
	// template<> struct is_integral<const unsigned long long> : public std::true_type {};
}

#endif