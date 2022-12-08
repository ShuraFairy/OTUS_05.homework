#pragma once

#include <tuple>
#include <map>

template<typename T, T default_value>
class Matrix
{
	using data_storage = std::map<std::tuple<size_t, size_t>, T>;

	class MatrixElement
	{
	public:
		MatrixElement(data_storage& data, size_t row, size_t column) : data(data), row(row), column(column)
		{ };

		operator T() 
		{
			return data.count({ row, column }) > 0 ? data[{row, column}] : default_value;
		}
		operator const T() const 
		{
			return data.count({ row, column }) > 0 ? data[{row, column}] : default_value;
		}
		MatrixElement& operator=(const T & element) 
		{
			if (element != default_value)
				data[{row, column}] = element;
			else
				data.erase({ row,column });
			return *this;
		};
	private:
		data_storage& data;
		size_t row, column;
	};

	class MatrixRow
	{
	public:
		MatrixRow(data_storage& data, size_t row) : data(data), row(row) {};
		MatrixElement operator[](size_t column_index) 
		{
			return MatrixElement(data, row, column_index);
		};
	private:
		data_storage& data;
		size_t row;
	};

public:
	class iterator : public std::iterator<std::bidirectional_iterator_tag, T> 
	{
	public:
		iterator(typename data_storage::iterator iter) : iter(iter) {};
		bool operator==(iterator& rhs) { return iter == rhs.iter; }
		bool operator!=(iterator& rhs) { return iter != rhs.iter; }
		iterator& operator--() { --iter; return *this; }
		iterator& operator++() { ++iter; return *this; }

		std::tuple<size_t, size_t, T> operator*() 
		{ 
			return { std::get<0>(iter->first), std::get<1>(iter->first), iter->second }; 				
		}
	protected:
		typename data_storage::iterator iter;
	};

	class const_iterator : public std::iterator<std::bidirectional_iterator_tag, T> 
	{
	public:
		const_iterator(typename data_storage::const_iterator iter) : iter(iter) {};
		bool operator==(const_iterator& rhs) const { return iter == rhs.iter; }
		bool operator!=(const_iterator& rhs) const { return iter != rhs.iter; }
		const const_iterator& operator--() const { --iter; return *this; }
		const const_iterator& operator++() const { ++iter; return *this; }
		std::tuple<size_t, size_t, T> operator*() 
		{ 
			return { std::get<0>(iter->first), std::get<1>(iter->first), iter->second 
		}; 
	}
	protected:
		typename data_storage::const_iterator iter;
	};

	size_t size() const { return data.size(); };

	MatrixRow operator[](size_t index) 
	{
		return MatrixRow(data, index);
	};
	Matrix::iterator begin() { return data.begin(); };
	Matrix::iterator end() { return data.end(); };

	Matrix::iterator ñbegin() const{ return data.cbegin(); };
	Matrix::iterator ñend() const { return data.cend(); };
private:
	data_storage data;
};

