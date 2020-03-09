#pragma once
#include <string>


class Human
{

protected:
	std::string m_name;			// ���
	std::string m_secondName;	// �������
	std::string m_middleName;	// ��������
	int	m_yearBirth;			// ��� ��������
	int	m_workTime;				// ����/����
	double m_money;				// ���������/��
public:
	// �����������
	Human();
	Human(std::string Name,
		std::string SecondName,
		std::string MiddleName,
		int YearBirth,
		int WorkTime,
		double Money
	);

	// ����������
	~Human();


	// �������-�������
	void setName(std::string Name);
	void setSecondName(std::string SecondName);
	void setMiddleName(std::string MiddleName);
	void setYearBirth(int YearBirth);
	virtual void setWorkTime(int WorkTime);
	virtual void setMoney(double Money);

	// �������-�������
	std::string getName() const;
	std::string getSecondName() const;
	std::string getMiddleName() const;
	int getYearBirth() const;
	virtual int getWorkTime() const;
	virtual double getMoney() const;

	// ��������� ��� ��������
	std::string getFullName() const;

};




 



