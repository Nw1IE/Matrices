//��������� ������
// ������ ������������� �������


#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <type_traits>
#include <numeric>
#include <initializer_list>

//��� ��������� ����� ������� ������� ������ ����� �������� ������ � ������ �������
// � �������� �������� �����. ��� ����� ��� ���� ������� ���� assert �������,
// ������������� ��������, ��� constraint ��������. ����� �� ���� �������� �����
// ���������� ������� ���������� ������ �������
template < typename Type, unsigned long long Coll, unsigned long long Row>
class Matrix {
public:
	Matrix() {}

	Matrix(/*����� ���������� ������� �� ������ ���� ��������*/);

	 Matrix(const Matrix& other)
	 {
		 for (int i = 0; i < Row; i++)
		 {
			 for (int j = 0; j < Coll; j++)
			 {
				 data_[i][j] = other.data_[i][j];
			 }
		 }
	 }

	 ~Matrix()
	 {
		 default;
	 }
	
	 const Matrix& operator=(const Matrix& other)
	 {
		 this->date_, other.data_, sizeof(Type)* Row* Coll;
		 return *this;
	 }

	 const Matrix& operator=(Matrix&& other)
	 {

	 }
	
	 Type& at(unsigned long long Row, unsigned long long Coll)
	 {
		 return data_[Row][Coll];
	 }

	 const Type& at(unsigned long long Row, unsigned long long Coll) const
	 {
		 return data_[Row][Coll];
	 }
		
	
	 friend const Matrix& operator+ (const Matrix<Type, Row, Coll>& lso)
	 {
		 Matrix<Type, Row, Coll> result;

		 for (int i = 0; i < Row; i++)
		 {
			 for (int j = 0; j < Coll; j++)
			 {
				 result[i][j] = lso[i][j] + rso[i][j];
			 }
		 }

		 return result;
	 }

	
	 friend const Matrix& operator- (const Matrix<Type, Row, Coll>& lso)
	 {
		 Matrix<Type, Row, Coll> result;

		 for (int i = 0; i < Row; i++)
		 {
			 for (int j = 0; j < Coll; j++)
			 {
				 result[i][j] = lso[i][j] - rso[i][j];
			 }
		 }

		 return result;
	 }

	 friend const Matrix& operator* (const Matrix<Type, Row, Coll>& lso)
	 {
		 Matrix<Type, Row, Coll> result;

		 for (int i = 0; i < Row; i++)
		 {
			 for (int j = 0; j < Coll; j++)
			 {
				 result[i][j] = 0;

				 for (int t = 0; t < Coll; t++)
				 {
					 result[i][j] += lso[i][t] * rso[t][j];
				 }
			 }
		 }

		 return result;
	 }


	 friend const Matrix& operator/ (const Matrix<Type, Row, Coll>& lso)
	 {
		 Matrix<Type, Row, Coll> result;

		 for (int i = 0; i < Row; i++)
		 {
			 for (int j = 0; j < Coll; j++)
			 {
				 result[i][j] = 0;

				 for (int t = 0; t < Coll; t++)
				 {
					 result[i][j] += lso[i][t] * (1 / rso[t][j]);
				 }
			 }
		 }

		 return result;
	 }

	 friend const Matrix & operator^(const Matrix & lso, const Integer & rso);
	 {
		 Matrix<Type, Row, Coll> result;

		 for (int i = 0; i < Row; i++)
		 {
			 for (int j = 0; j < Coll; j++)
			 {
				 result[i][j] = 0;

				 for (int t = 0; t < Coll; t++)
				 {
					 result[i][j] += lso[i][t] * (1 / rso[t][j]);
				 }
			 }
		 }

		 return result;
	 }
	
		
	 friend const Matrix& operator=+(const Matrix & lso, const Matrix & rso)
	 {
		 for (int i = 0; i < Row; i++)
		 {
			 for (int j = 0; j < Coll; j++)
			 {
				 lso[i][j] =+ rso[i][j];
			 }
		 }

		 return lso;
	 }

	 friend const Matrix& operator=-(const Matrix & lso, const Matrix & rso)
	 {
		 for (int i = 0; i < Row; i++)
		 {
			 for (int j = 0; j < Coll; j++)
			 {
				 lso[i][j] =- rso[i][j];
			 }
		 }

		 return lso;
	 }
	 friend const Matrix& operator=*(const Matrix& lso, const Matrix& rso)
	 {
		 Matrix<Type, Row, Coll> result;

		 for (int i = 0; i < Row; i++)
		 {
			 for (int j = 0; j < Coll; j++)
			 {
				 result[i][j] = 0;
				 for (int t = 0; t < Coll; t++)
				 {
					 result[i][j] =+ lso[i][t] * rso[t][j];
				 }
			 }
		 }
		 lso = result;

		 return lso;
	 }
	 friend const Matrix& operator= / (const Matrix & lso, const Matrix & rso)
	 {
		 Matrix<Type, Row, Coll> result;

		 for (int i = 0; i < Row; i++)
		 {
			 for (int j = 0; j < Coll; j++)
			 {
				 result[i][j] = 0;

				 for (int t = 0; t < Coll; t++)
				 {
					 result[i][j] += lso[i][t] * (1 / rso[t][j]);
				 }
			 }
		 }
		 lso = result;

		 return lso;
	 }

	 friend std::ostream& operator<<(std::ostream& outs, const Matrix& rso)
	 {
		 for (int i = 0; i < Row; i++)
		 {
			 for (int j = 0; j < Coll; j++)
			 {
				 outs << rso[i][j] << " ";
			 }
			 outs << "\n";
		 }
		 return outs;
	 }

	 friend std::istream& operator>>(std::istream& ins, const Matrix& rso)
	 {
		 for (int i = 0; i < Row; i++)
		 {
			 for (int j = 0; j < Coll; j++)
			 {
				 ins >> rso[i][j] >> " ";
			 }
		 }
		 return ins;
	 }

	Type begin() { return data_; }
	Type end() { return data_ + (Row * Coll); }
	
private:
	Type data_[Coll][Row];
	
};

namespace std
{

	template<typename Type, unsigned long long Row, unsigned long long Coll>
	struct hash<Matrix<Type, Row, Coll>>
	{
		size_t operator()(const Matrix<Type, unsigned long long, unsigned long long>&
			obj) {
			size_t result{};
			for (size_t i = 0; i < obj.rows(); i++)
			{
				for (size_t j = 0; j < obj.columns(); j++)
				{
					result <<= 1;
					result ^= hash<Type>()(obj[i][j]);
				}
			}
			return result;
		};

	};
}

#endif
//�� ������� ����� ����������� ��� ������ � ������� �����������������
//������������� ����� ������ �� ���������� ������� ��������� ������ � ����
// ������ ����� ����� �� ����������� �������(��� ������������ ��� � rational+real)
// First lectule in friday will be comprtition ow yours clown solutio;