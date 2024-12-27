#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
#pragma region 필수기능가이드
//////////////////////// 필수 기능 부분 //////////////////////// 

class Animal
{
public:
	Animal()
	{
		cout << " 생성됨\n";
	}
	Animal(string name)
	{
		this->name = name;
		cout << name << " 생성됨\n";
	}
	virtual void makeSound() = 0;
	virtual ~Animal()
	{
		cout << name << " 삭제됨\n";
	}

	void set_name(string name)
	{
		this->name = name;
	};
	string get_name()
	{
		return this->name;
	}

private:
	string name;
};

class Dog : public Animal {
public:
	Dog(string name) : Animal(name)
	{

	}
	void makeSound() {
		cout << "멍멍" << endl;
	}
};

class Cat : public Animal {
public:
	Cat(string name) : Animal(name)
	{

	}
	void makeSound() {
		cout << "야옹" << endl;
	}
};

class Cow : public Animal {
public:
	Cow(string name) : Animal(name)
	{

	}
	void makeSound() {
		cout << "음메" << endl;
	}
};
//////////////////////// 필수 기능 부분 //////////////////////// 
#pragma endregion



#pragma region 도전기능가이드

class Zoo {
private:
	Animal* animals[10]; // 동물 객체를 저장하는 포인터 배열
	int array_index = 0;
public:
	Zoo()
	{
		for (int i = 0; i < 10; i++)
		{
			animals[i] = nullptr;
		}
		cout << "동물원이 개장되었고, 이제 동물이 들어올 수 있습니다.\n";
	}

	// 동물을 동물원에 추가하는 함수
	// - Animal 객체의 포인터를 받아 포인터 배열에 저장합니다.
	// - 같은 동물이라도 여러 번 추가될 수 있습니다.
	// - 입력 매개변수: Animal* (추가할 동물 객체)
	// - 반환값: 없음
	void addAnimal(Animal* animal)
	{
		if (array_index < 10)
		{
			animals[array_index] = animal;
			array_index++;
		}
		else
		{
			cout << "이미 배열이 포화상태입니다.\n";
			delete animal;
		}
	}
	
	// 동물원에 있는 모든 동물의 행동을 수행하는 함수
	// - 모든 동물 객체에 대해 순차적으로 소리를 내고 움직이는 동작을 실행합니다.
	// - 입력 매개변수: 없음
	// - 반환값: 없음
	void performActions()
	{
		for (int i = 0; i < array_index; i++)
		{
			animals[i]->makeSound();
		}
	}

	// Zoo 소멸자
	// - Zoo 객체가 소멸될 때, 동물 벡터에 저장된 모든 동물 객체의 메모리를 해제합니다.
	// - 메모리 누수를 방지하기 위해 동적 할당된 Animal 객체를 `delete` 합니다.
	// - 입력 매개변수: 없음
	// - 반환값: 없음
	~Zoo()
	{
		for (int i = 0; i < array_index; i++)
		{
			delete animals[i];
		}
	}
};

Animal* createRandomAnimal()
{

	int random_num = (rand() % 3);
	if (random_num % 3 == 0)
	{
		return new Dog("dog");
	}
	else if (random_num % 3 == 1)
	{
		return new Cat("cat");
	}
	else
	{
		return new Cow("Cow");
	}
}

#pragma endregion



int main()
{
	//////////
	cout << "필수 기능 가이드 부분\n\n";
	Animal* animal[3];
	animal[0] = new Dog("dog");
	animal[1] = new Cat("cat");
	animal[2] = new Cow("cow");

	for (int i = 0; i < 3; i++)
	{
		animal[i]->makeSound();
	}

	for (int i = 0; i < 3; i++)
	{
		delete animal[i];
	}
	cout << "\n\n";
	
	////////////
	cout << "도전 기능 가이드 부분\n\n";

	srand(static_cast<unsigned int>(time(NULL)));

	Zoo zoo;
	

	// 랜덤 동물을 생성하는 함수
// - 0, 1, 2 중 하나의 난수를 생성하여 각각 Dog, Cat, Cow 객체 중 하나를 동적으로 생성합니다.
// - 생성된 객체는 Animal 타입의 포인터로 반환됩니다.
// - 입력 매개변수: 없음
// - 반환값: Animal* (생성된 동물 객체의 포인터)
	for (int i = 0; i < 15; i++) {
		zoo.addAnimal(createRandomAnimal());
	}

	zoo.performActions();




	return 0;
}