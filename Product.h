// This file defines two implementations for Product class
// and puts them in separate namespaces

#pragma once

namespace fixed
{
	class Product
	{
	public:
		// Construct an object using only it's name.
		// Id and value will be invalid.
		Product(const char* name = "undefined");
		// Destroy the current object.
		~Product();

	private:
		int m_id;
		float m_value;
		char m_name[100];
	};
}

namespace dynamic
{
	// Note that for classes that have dynamically allocated members
	// you should implement a copy constructor, assignment operator and destructor;
	// more precisely you should pay attention to the rule of three:
	// https://en.wikipedia.org/wiki/Rule_of_three_(C%2B%2B_programming)
	class Product
	{
	public:
		// Construct an object using only it's name.
		// Id and value will be invalid.
		Product(const char* name = "undefined");
		// Construct an object from another object (copy constructor).
		Product(const Product& other);
		// Destroy the current object.
		~Product();

		// Make the current object equal to the other object (assignment operator).
		// Multiple assignments can be linked together 
		// as this function returns a reference to the current object.
		Product& operator =(const Product& other);

	private:
		int m_id;
		float m_value;
		char* m_name;
	};
}

