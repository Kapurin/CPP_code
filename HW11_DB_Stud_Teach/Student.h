#pragma once
#include "Human.h"



class Student :public Human
{
private:
	int	m_course;			// ����
	double m_scholarship;	// ���������

public:
	// �����������
	Student();
	Student(std::string Name,
		std::string SecondName,
		std::string MiddleName,
		int YearBirth,
		int Course,
		double Scholarship);

	// ����������
	~Student();


	// �������-�������
	void setCourse(int Course);
	void setScholarship(double Scholarship);

	// �������-�������
	int getCourse() const;
	double getScholarship() const;

	// ����������� ���� �������
	virtual const char* getType();
};

