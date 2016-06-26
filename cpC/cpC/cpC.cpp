// cpC.cpp : Defines the entry point for the console application.
// implement linux "cp" command with C++ std library (fstream)

#include "stdafx.h"
#include <fstream>
#include <iostream>

#define BUFF_SIZE 256

int main(int argc, char * argv [])
{
	std::fstream bit_input, bit_output;

	if (argc != 3)
	{
		std::cerr << "E: cp command takes 3 parameters: cp file1 file2" << std::endl;
		return 1;
	}

	// open files
	bit_input.open (argv[1], std::fstream::in | std::fstream::binary);
	if (!bit_input.is_open())
	{
		std::cerr << "E: file \"" << argv[1] << "\" not found" << std::endl;
		return 2;
	}

	bit_output.open (argv[2], std::fstream::out | std::fstream::binary);
	if (!bit_output.is_open())
	{
		std::cerr << "E: file \"" << argv[2] << "\" not found" << std::endl;
		return 3;
	}

	// copy file
	char * buffer = new char[BUFF_SIZE];
	while (bit_input.read(buffer, BUFF_SIZE) && bit_input.good())
	{
		bit_output.write(buffer, BUFF_SIZE);
	}

	// resource collect
	bit_input.close();
	bit_output.close();
	delete[] buffer;
	

    return 0;
}

