#include "Product.h"
#include <string>
#include <iostream>

// global constant for this source (.cpp) file
const int kInvalidProductId = -1;

namespace fixed
{
	Product::Product(const char* name)
	{
		m_id = kInvalidProductId;
		m_value = 0;
		// copy name
		strcpy_s(m_name, name);

		std::cout << "Constructed product: " << m_name << '\n';
	}

	Product::~Product()
	{
		std::cout << "Destructed product: " << m_name << '\n';
	}
}

namespace dynamic
{
	Product::Product(const char* name)
	{
		m_id = kInvalidProductId;
		m_value = 0;

		// allocate and copy name
		int nameSize = strlen(name) + 1;
		m_name = new char[nameSize];
		strcpy_s(m_name, nameSize, name);
	}

	Product::Product(const Product& other)
	{
		m_id = other.m_id;
		m_value = other.m_value;

		// allocate and copy new name
		int nameSize = strlen(other.m_name) + 1;
		m_name = new char[nameSize];
		strcpy_s(m_name, nameSize, other.m_name);
	}

	Product::~Product()
	{
		// delete name if it was allocated
		if (m_name != nullptr)
		{
			delete[] m_name;
			m_name = nullptr;
		}
	}

	Product& Product::operator =(const Product& other)
	{
		m_id = other.m_id;
		m_value = other.m_value;

		// delete old name if it was allocated
		if (m_name != nullptr)
			delete[] m_name;

		// allocate and copy new name
		int nameSize = strlen(other.m_name) + 1;
		m_name = new char[nameSize];
		strcpy_s(m_name, nameSize, other.m_name);

		return *this;
	}
}
