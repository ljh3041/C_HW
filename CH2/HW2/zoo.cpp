#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
#pragma region �ʼ���ɰ��̵�
//////////////////////// �ʼ� ��� �κ� //////////////////////// 

class Animal
{
public:
	Animal()
	{
		cout << " ������\n";
	}
	Animal(string name)
	{
		this->name = name;
		cout << name << " ������\n";
	}
	virtual void makeSound() = 0;
	virtual ~Animal()
	{
		cout << name << " ������\n";
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
		cout << "�۸�" << endl;
	}
};

class Cat : public Animal {
public:
	Cat(string name) : Animal(name)
	{

	}
	void makeSound() {
		cout << "�߿�" << endl;
	}
};

class Cow : public Animal {
public:
	Cow(string name) : Animal(name)
	{

	}
	void makeSound() {
		cout << "����" << endl;
	}
};
//////////////////////// �ʼ� ��� �κ� //////////////////////// 
#pragma endregion



#pragma region ������ɰ��̵�

class Zoo {
private:
	Animal* animals[10]; // ���� ��ü�� �����ϴ� ������ �迭
	int array_index = 0;
public:
	Zoo()
	{
		for (int i = 0; i < 10; i++)
		{
			animals[i] = nullptr;
		}
		cout << "�������� ����Ǿ���, ���� ������ ���� �� �ֽ��ϴ�.\n";
	}

	// ������ �������� �߰��ϴ� �Լ�
	// - Animal ��ü�� �����͸� �޾� ������ �迭�� �����մϴ�.
	// - ���� �����̶� ���� �� �߰��� �� �ֽ��ϴ�.
	// - �Է� �Ű�����: Animal* (�߰��� ���� ��ü)
	// - ��ȯ��: ����
	void addAnimal(Animal* animal)
	{
		if (array_index < 10)
		{
			animals[array_index] = animal;
			array_index++;
		}
		else
		{
			cout << "�̹� �迭�� ��ȭ�����Դϴ�.\n";
			delete animal;
		}
	}
	
	// �������� �ִ� ��� ������ �ൿ�� �����ϴ� �Լ�
	// - ��� ���� ��ü�� ���� ���������� �Ҹ��� ���� �����̴� ������ �����մϴ�.
	// - �Է� �Ű�����: ����
	// - ��ȯ��: ����
	void performActions()
	{
		for (int i = 0; i < array_index; i++)
		{
			animals[i]->makeSound();
		}
	}

	// Zoo �Ҹ���
	// - Zoo ��ü�� �Ҹ�� ��, ���� ���Ϳ� ����� ��� ���� ��ü�� �޸𸮸� �����մϴ�.
	// - �޸� ������ �����ϱ� ���� ���� �Ҵ�� Animal ��ü�� `delete` �մϴ�.
	// - �Է� �Ű�����: ����
	// - ��ȯ��: ����
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
	cout << "�ʼ� ��� ���̵� �κ�\n\n";
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
	cout << "���� ��� ���̵� �κ�\n\n";

	srand(static_cast<unsigned int>(time(NULL)));

	Zoo zoo;
	

	// ���� ������ �����ϴ� �Լ�
// - 0, 1, 2 �� �ϳ��� ������ �����Ͽ� ���� Dog, Cat, Cow ��ü �� �ϳ��� �������� �����մϴ�.
// - ������ ��ü�� Animal Ÿ���� �����ͷ� ��ȯ�˴ϴ�.
// - �Է� �Ű�����: ����
// - ��ȯ��: Animal* (������ ���� ��ü�� ������)
	for (int i = 0; i < 15; i++) {
		zoo.addAnimal(createRandomAnimal());
	}

	zoo.performActions();




	return 0;
}