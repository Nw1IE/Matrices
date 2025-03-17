#pragma once
#ifdef MATRIX_HPP
#endif MATRIX_HPP

#include <iostream>
#include <type_traits>
#include <numeric>
#include <initializer_list>

//Это шаблоные класс матрицы который должен уметь работать ТОЛЬКО с целыми числами
// в качестве хранимых типов. Для этого вам надо изучить тему assert
// специализацию шаблонов, или constraint шаблонов. Любой из этих способов может
// ограничивать область применения вашего шаблона
template<typename Type, unsigned long long Coll, unsigned long long Row>
class Matrix {
public:
	Matrix();
	Matrix(/*набор параметров который вы можете сюда передать*/);
	Matrix(const Matrix& other);
	Matrix(Matrix&& dead);
	~Matrix();

	const Matrix& operator=(const Matrix& other);
	const Matrix& operator=(Matrix& other);

	//operator[]??? саечка за то что-бы реализовать это без В           д е н и с ь к а  п и п и с ь к а

	friend const Matrix& operator+(const Matrix& lso, const Matrix& rso);
	friend const Matrix& operator-(const Matrix& lso, const Matrix& rso);
	friend const Matrix& operator*(const Matrix& lso, const Matrix& rso);
	friend const Matrix& operator/(const Matrix& lso, const Matrix& rso);
	friend const Matrix& operator^(const Matrix& lso, const Matrix& rso);

	friend const Matrix& operator+=(const Matrix& lso, const Matrix& rso);
	friend const Matrix& operator-=(const Matrix& lso, const Matrix& rso);
	friend const Matrix& operator*=(const Matrix& lso, const Matrix& rso);
	friend const Matrix& operator/=(const Matrix& lso, const Matrix& rso);
	friend const Matrix& operator^=(const Matrix& lso, const Matrix& rso);
	
	friend std::ostream& operator<<(std::ostream& outs, const Matrix& rso);
	friend std::istream& operator>>(std::istream& ins, const Matrix& rso);


private:
	Type date_[Coll][Row];
};

namespace std {
	template<>
	struct hash<Matrix<Type, unsigned long long, unsigned long long>> // Это надо исправить
	{
		size_t  operator()(Matrix<Type, unsigned long long, unsigned long long>& obj)
			size_t result{};
			for (size_t i = 0; i < obj.rows(); i++)
			{
				for (size_t i = 0; i < obj.columns; i++)
				{
					result <<= 1;
					result ^= hash<Type>()(obj[i][j]);
				}
			}
			return result;
	};
	//Стркутура данного трейта-хеширования полностью корректна
	//наша задача исправить
}