#include <iostream>

void FizzBuzz(int num)
{
	for (int i = 0; i <= num; i++)
	{
		if (i % 3 == 0 || i % 5 == 0)
		{
			std::cout << i << ": ";
			if (i % 3 == 0)
				std::cout << "Fizz";
			if (i % 5 == 0)
				std::cout << "Buzz";
			std::cout << std::endl;
		}
	}
}

int main()
{
	while (true)
	{
		int num = 0;
		system("cls");
		std::cout << "-FizzBuzz-" << std::endl;
		std::cout << "If the number is divisible by 3, print Fizz" << std::endl;
		std::cout << "If the number is divisible by 5, print Buzz" << std::endl;
		std::cout << "If the number is divisible by both, print FizzBuzz" << std::endl;
		std::cout << "Enter a number: ";
		std::cin >> num;
		FizzBuzz(num);
		system("pause");
	}

	return 0;
}