#pragma once

#include <memory>

template <typename T>
class Vector
{
public:
	Vector(int capacity = 4)
	{
		data = new T[capacity];

		for (int i = 0; i < capacity; i++)
		{
			data[i] = T();
		}
	}

	~Vector()
	{
		// 메모리 해제
		if(data)
		{
			delete[] data;
			data = nullptr;
		}
	}
	
	// 배열에 새로운 데이터 삽입 함수
	void Push(const T& item)
	{
		// 현재 배열이 가득 찻다면
		if (size == capacity)
		{
			// 새롭게 배열 할당
			IncreaseCapacity(capacity * 2);
		}

		// 배열에 저장
		data[size] = item;
		size++;
	}

	void Push(const T&& item)
	{
		// 현재 배열이 가득 찻다면
		if (size == capacity)
		{
			// 새롭게 배열 할당
			IncreaseCapacity(capacity * 2);
		}

		// 배열에 저장
		data[size] = std::move(item);
		size++;
	}

	// 배열이 비었는지 보는 함수
	inline bool Empty() const { return size == 0; }

	// 현재 배열에 저장된 데이터의 개수를 반환하는 함수
	inline int Size() const { return size; }

	// 인덱스 연산자 오버로딩
	T& operator[](int index)
	{
		// index 범위 확인
		if (index < 0 || index >= size)
		{
			__debugbreak();
		}

		return data[index];
	}


private:
	// 배열 크기를 늘리는 함수
	void IncreaseCapacity(int newCapacity)
	{
		// 새로운 공간 할당
		T* newData = new T[newCapacity];
		for (int i = 0; i < newCapacity; i++)
		{
			newData[i] = T();
		}
		
		if (data)
		{
			for (int i = 0; i < size; i++)
			{
				newData[i] = data[i];
			}

			delete[] data;
		}

		// 정리
		data = newData;
		capacity = newCapacity;
	}

private:
	// 힙 공간에 저장할 데이터 배열
	T* data = nullptr;

	// 현재 저장할 위치
	int size = 0;

	// 전체 배열 크기
	int capacity = 4;
};
