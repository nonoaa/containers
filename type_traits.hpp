#ifndef TYPE_TRAITS_HPP
#define TYPE_TRAITS_HPP

namespace ft
{
	// enable_if
	template <bool B, typname T = void>
	struct enable_if {};

	template <typename T>
	struct enable_if<true, T> { typedef T type; };

	struct false_type
	{
		typedef bool value_type;
		typedef false_type type;
		static const value_type value = false;
	}

	struct true_type
	{
		typedef bool value_type;
		typedef true_type type;
		static const value_type value = true;
	}

	template <class T> struct is_integral : public false_type {};

	template<> struct is_integral<bool> : public true_type {};
	template<> struct is_integral<char> : public true_type {};
	template<> struct is_integral<wchar_t> : public true_type {};
	template<> struct is_integral<signed char> : public true_type {};
	template<> struct is_integral<short int> : public true_type {};
	template<> struct is_integral<int> : public true_type {};
	template<> struct is_integral<long int> : public true_type {};
	template<> struct is_integral<unsigned char> : public true_type {};
	template<> struct is_integral<unsigned short int> : public true_type {};
	template<> struct is_integral<unsigned int> : public true_type {};
	template<> struct is_integral<unsigned long int> : public true_type {};

	template<> struct is_integral<const bool> : public true_type {};
	template<> struct is_integral<const char> : public true_type {};
	template<> struct is_integral<const wchar_t> : public true_type {};
	template<> struct is_integral<const signed char> : public true_type {};
	template<> struct is_integral<const short int> : public true_type {};
	template<> struct is_integral<const int> : public true_type {};
	template<> struct is_integral<const long int> : public true_type {};
	template<> struct is_integral<const unsigned char> : public true_type {};
	template<> struct is_integral<const unsigned short int> : public true_type {};
	template<> struct is_integral<const unsigned int> : public true_type {};
	template<> struct is_integral<const unsigned long int> : public true_type {};
}

#endif