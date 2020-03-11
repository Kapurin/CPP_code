#pragma once
#include <string>


class Human
{

protected:
	std::string m_name;			// ���
	std::string m_secondName;	// �������
	std::string m_middleName;	// ��������
	int	m_yearBirth;			// ��� ��������
public:
	// �����������
	Human();
	Human(std::string Name,
		std::string SecondName,
		std::string MiddleName,
		int YearBirth);

	// ����������
	~Human();


	// �������-�������
	void setName(std::string Name);
	void setSecondName(std::string SecondName);
	void setMiddleName(std::string MiddleName);
	void setYearBirth(int YearBirth);


	// �������-�������
	std::string getName() const;
	std::string getSecondName() const;
	std::string getMiddleName() const;
	int getYearBirth() const;

	// ����������� ���� �������
	virtual const char* getType();

	// ��������� ��� ��������
	std::string getFullName();

};




 



