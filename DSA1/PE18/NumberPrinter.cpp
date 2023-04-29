#include "NumberPrinter.h"


NumberPrinter::NumberPrinter(int number) {
	m_number = number;
}


void NumberPrinter::Print() {

	for (int i = 0; i < 50; i++)
		std::cout << m_number;
}
