#pragma once
#include "global.h"
class Student
{
public:
	Student() {};
	Student(string id, string name, string gender, int age, int grade, int classes)
	{
		this->m_id = id;
		this->m_name = name;
		this->m_gender = gender;
		this->m_age = age;
		this->m_grade = grade;
		this->m_classes = classes;
	}
	~Student() {};
public:
	string m_id;
	string m_name;
	string m_gender;
	int m_age;
	int m_grade;
	int m_classes;
};


class Base
{
public:
	void ShowMenu();
	void ExitSystem();
	void AddStudent();
	void ShowStudent();
	void FindStudent();
	void DeleteStudent();
	void InitVector();
	void ClearStudents();
	void ModifiyStudent();
	void SaveToFile();
	void ClearFile();
	void CreateFile();
private:
	vector<Student> student;
};