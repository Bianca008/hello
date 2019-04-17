#include "Product.h"
#include <malloc.h>
#include <iostream>
#include <fstream>

// use one of the two implementations for product
//using namespace fixed;
using namespace dynamic;

void testProducts();
void testFiles();

int main()
{
	testProducts();

	testFiles();

	system("pause");

	return 0;
}

void testProducts()
{
	// static allocation of a single object
	Product product("Milka");

	// dynamic allocation of single object
	Product* pProduct = new Product("Poiana");
	delete pProduct;

	// dynamic allocation using malloc ...
	pProduct = (Product*)malloc(sizeof(Product));
	// ... and object construction with placement new (at already allocated memory)
	new(pProduct) Product("Love Potion");

	// manual destruction of object
	pProduct->~Product();
	// memory releasing
	free(pProduct);

	int n = 10;
	// allocate and construct multiple object
	Product* pProducts = new Product[n];
	// destruct and free multiple objects
	delete[] pProducts;

	// construct object from another object using copy constructor
	Product product2 = product;

	Product product3("W&G");
	// set object equal to another object (operator =)
	product2 = product3;
}

void testFiles()
{
	int number1 = 100, number2 = 10;

	// open file for writing
	std::ofstream fout("test.txt");
	// formated write (text mode)
	fout << number1;
	// binary write (binary mode)
	fout.write((const char*)&number2, sizeof(number2));

	// close file, so we can open it again for reading
	fout.close();

	// reset numbers, and read them from file
	number1 = number2 = -1;

	// open file for reading (note that file will automatically close once it's out of scope)
	std::ifstream fin("test.txt");
	// formated read (text mode)
	fin >> number1;
	// binary read (binary mode)
	fin.read((char*)&number2, sizeof(number2));

	// std::fstream can be used to open a file in any mode, or to use a file for both reading and writing
}