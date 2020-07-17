#ifndef ARRAY_HPP
#define  ARRAY_HPP

#include <ostream>
#include <sstream>
#include <fstream>

template<class T>
class Array
{
	size_t _size;
	T* _begin;
	T* _end;

public:
	explicit Array(size_t size) noexcept
		: _size(size), _begin(new T[_size]), _end(_begin + _size)
	{}

	~Array() { delete[] _begin; }

	using value_type     = T;
	using const_iterator = value_type const*;
	using iterator       = value_type*;
	
	inline const_iterator begin() const noexcept { return _begin; }

	inline const_iterator end() const noexcept { return _end; }

	inline iterator begin() noexcept { return _begin; }

	inline iterator end() noexcept { return _end; }

	inline size_t size() { return _size; }

	template<class _T, class... Args>
	void foreach(_T&& functor, Args&&... args) const { for (auto _item : *this) functor(_item, std::forward<Args>(args)...); }

	template<class _T, class... Args>
	void foreach(_T&& functor, Args&&... args) { for (auto _item : *this) functor(_item, std::forward<Args>(args)...); }

	template<class _T>
	void foreach(_T&& functor) const { for (auto _item : *this) functor(_item); }

	template<class _T>
	void foreach(_T&& functor) { for (auto _item : *this) functor(_item); }

	const T& operator[](size_t index) const { return _begin[index]; }

	T& operator[](size_t index) { return _begin[index]; }

	friend std::ostream& operator<<(std::ostream& os, const Array& arr)
	{
		os << "[";
		for (auto _it = arr.begin(); _it < arr.end()-1; ++_it) os << *_it << ", ";
		os << *(arr._end - 1);
		os << "]";

		return os;
	}

	friend std::stringstream& operator<<(std::sstream& ss, const Array& arr)
	{
		ss << "[";
		for (auto _it = arr.begin(); _it < arr.end() - 1; ++_it) ss << *_it << ", ";
		ss << *(arr._end - 1);
		ss << "]";

		return os;
	}

	friend std::fstream& operator<<(std::fstream& fs, const Array& arr)
	{
		fs << "[";
		for (auto _it = arr.begin(); _it < arr.end() - 1; ++_it) fs << *_it << ", ";
		fs << *(arr._end - 1);
		fs << "]";

		return os;
	}


};

#endif//ARRAY_HPP
