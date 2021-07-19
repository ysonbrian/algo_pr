#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

struct Employee
{
	int age;
	char name;
};

class Cat
{
	public:
		Cat()
		{
			std::cout << "meow" << std::endl;
		}
		~Cat()
		{
			std::cout << "bye" << std::endl;
		}
	private:
		int mAge;
};

bool operator< (const Employee & lhs, const Employee & rhs)
{
	return lhs.age < rhs.age;
}

int main()
{
	// Cat * catp = new Cat;
	// Safer C++ style heap Cat
	std::unique_ptr<Cat> catp = std::make_unique<Cat>();

	// Cat * catap = new Cat[5];
	// Safer C++ style heap Cats(Cat array)
	std::vector<Cat> cats(5);

	std::unique_ptr<int> ip = std::make_unique<int>();
	*ip = 100;

	std::vector<int> ints(5);

	std::cout<<"How many cats ?" << std::endl;
	int catCount;
	std:: cin >> catCount;

	std::vector<Cat> catss(catCount);

	// std::vector<Employee> v {
	// 	{200,'A'},
	// 	{200,'B'},
	// 	{200,'C'},
	// 	{200,'D'},
	// 	{200,'E'},
	// };

	// for (int i =9; i < 100; i++) {
	// 	v.emplace_back(Employee{i,'Z'});
	// }

	// // stable_sort(v.begin(), v.end());
	// std::sort(v.begin(), v.end());
	// for(const Employee& e : v){
	// 	std::cout << e.age << ", " << e.name << std::endl;
	// }


	return 0;
}