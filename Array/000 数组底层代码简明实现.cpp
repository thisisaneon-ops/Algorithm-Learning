#include<iostream>
#include <stdexcept>
using namespace std;
template<class T>
class Array
{
public:
	Array(int capacity = 5)
		: size_(0)
		, capacity_(capacity)
	{
		array_ = new T[capacity];
	}
	~Array()
	{
		delete[] array_;
	}
	Array(const Array& array)
	{
		this->size_ = array.size_;
		this->capacity_ = array.capacity_;
		T* newarray = new T[array.capacity_];
		for (int i = 0; i < size_; i++)
		{
			newarray[i] = array.array_[i];
		}
		this->array_ = newarray;
	}
  Array& operator=(const Array& other)
  {
      if (this == &other)
          return *this;
  
      delete[] array_;
  
      size_ = other.size_;
      capacity_ = other.capacity_;
  
      array_ = new T[capacity_];
  
      for (int i = 0; i < size_; i++)
          array_[i] = other.array_[i];
  
      return *this;
  }
public:
	void push_back(const T& val)
	{
		if (size_ == capacity_)
		{
			expand();
		}
		array_[size_] = val;
		size_++;
	}
	void pop_back()
	{
		if (size_ == 0)
		{
			throw std::invalid_argument("invalid operation! you cant delete members from an empty array!");
		}
		size_--;
	}
	void erase(const T& val)
	{
		int i = 0;
		for (; i < size_; i++)
		{
			if (array_[i] == val)
			{
				break;
			}
		}
		if (i == size_)
		{
			return;
		}
		for (int j = i; j < size_ - 1; j++)
		{
			array_[j] = array_[j + 1];
		}
		size_--;
	}
	void update(int i, const T& val)
	{
		if (i < 0 || i >= size_)
		{
			throw std::invalid_argument("invalid index!");
		}
		array_[i] = val;
	}
	bool find(const T& val)
	{
		for (int i = 0; i < size_; i++)
		{
			if (array_[i] == val)
			{
				return true;
			}
		}
		return false;
	}
	void printArray()
	{
		for (int i = 0; i < size_; i++)
		{
			cout << array_[i] << " ";
		}
		cout << endl;
	}
	void insert(int pos, const T& val)
	{
		if (size_ == capacity_)
		{
			expand();
		}
		if (pos < 0 || pos > size_)
		{
			throw std::invalid_argument("invalid index!");
		}
		for (int j = size_; j > pos; j--)
		{
			array_[j] = array_[j - 1];
		}
		array_[pos] = val;
		size_++;
	}
private:
	void expand()
	{
		T* newarray_ = new T[capacity_ * 2];
		for (int i = 0; i < size_; i++)
		{
			newarray_[i] = array_[i];
		}
		delete[] array_;
		capacity_ *= 2;
		array_ = newarray_;
	}
	int size_;
	int capacity_;
	T* array_;
};
