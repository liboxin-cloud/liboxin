#include "student.h"
void Base::ShowMenu()
{
	system("cls");
	cout << "\t\t\t************欢迎来到学生管理系统************" << endl;
	cout << "\t\t\t你可以进行以下操作:" << endl;
	cout << "\t\t\t|------------------------------------------|" << endl;
	cout << "\t\t\t|             1   添加学生信息             |" << endl;
	cout << "\t\t\t|------------------------------------------|" << endl;
	cout << "\t\t\t|             2   删除学生信息             |" << endl;
	cout << "\t\t\t|------------------------------------------|" << endl;
	cout << "\t\t\t|             3   修改学生信息             |" << endl;
	cout << "\t\t\t|------------------------------------------|" << endl;
	cout << "\t\t\t|             4   查询学生信息             |" << endl;
	cout << "\t\t\t|------------------------------------------|" << endl;
	cout << "\t\t\t|             5   显示所有信息             |" << endl;
	cout << "\t\t\t|------------------------------------------|" << endl;
	cout << "\t\t\t|             6   清空系统数据             |" << endl;
	cout << "\t\t\t|------------------------------------------|" << endl;
	cout << "\t\t\t|             0   退出                     |" << endl;
	cout << "\t\t\t|------------------------------------------|" << endl;
	cout << "\t\t\t请选择【0-6】：";
}

void Base::ExitSystem()
{
	cout << "您是否要退出系统（Y/N）:" << endl;
	string c;
	cin >> c;
	if (c == "Y" || c == "y")
	{
		cout << "欢迎下次使用" << endl;
		system("pause");
		exit(0);
	}
	else
	{
		system("pause");
		system("cls");
		return;
	}

}

void Base::AddStudent()
{
	string id;
	string name;
	string gender;
	int age;
	int grade;
	int classes;
	string c;
	FLAG:
	this->InitVector();
	cout << "请输入您要添加的学生学号：" << endl;
	cin >> id;
	for (auto& stud : student)
	{
		if (stud.m_id == id)
		{
			cout << "您添加的学号已经存在！添加失败" << endl;
			cout << "是否继续添加" << endl;
			cin >> c;
			if (c == "Y" || c == "y")
			{
				goto FLAG;
			}
			else
			{
				system("pause");
				system("cls");
				return;
			}
		}
	}
	cout << "请输入添加的学生姓名：" << endl;
	cin >> name;
	cout << "请输入添加的学生的性别：" << endl;
	while (true)
	{
		cin >> gender;
		if (gender == "男" || gender == "女")
		{
			break;
		}
		cout << "您输入的性别有误，请重新输入" << endl;
	}
	cout << "请输入您要添加的学生的年龄：" << endl;
	while (true)
	{
		cin >> age;
		if (age > 0 && age <= 120)
		{
			break;
		}
		cout << "您输入的年龄有误，请重新输入" << endl;
	}
	cout << "请输入您要添加的学生的年级(1 ~ 6)：" << endl;
	while (true)
	{
		cin >> grade;
		if (grade >= 1 && grade <= 6)
		{
			break;
		}
		cout << "您输入的年级有误，请重新输入：" << endl;
	}
	cout << "请输入您要添加的学生的班级(1 ~ 30)：" << endl;
	while (true)
	{
		cin >> classes;
		if (classes >= 1 && classes <= 30)
		{
			break;
		}
		cout << "您输入的学生的班级有误，请重新输入:" << endl;
	}
	ofstream ofs;
	ofs.open("student.txt", ios::in | ios::app);
	if (!ofs.is_open())
	{
		cout << "文件打开失败" << endl;
	}
	ofs << id << " " << name << " " << gender << " " << age << " " << grade << " " << classes << endl;
	ofs.close();
	cout << "已经成功添加学生：" << name << "(学号：" << id << ")" << endl;
	system("pause");
	system("cls");
	return;

}

void Base::ShowStudent()
{
	this->InitVector();
	if (student.size() == 0)
	{
		cout << "系统中学生为空，请先添加学生！" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (auto& stu : student)
	{
		cout << "学号：" << stu.m_id
			<< "  姓名：" << stu.m_name
			<< "  性别：" << stu.m_gender
			<< "  年龄：" << stu.m_age
			<< "  年级：" << stu.m_grade
			<< "  班级：" << stu.m_classes << endl;
	}
	system("pause");
	system("cls");
	return;
}

void Base::FindStudent()
{
	this->InitVector();
	string id;
	int index = -1;
	bool flag = false;
	if (student.size() == 0)
	{
		cout << "学生的信息为空，请先添加学生信息" << endl;
		system("pause");
		system("cls");
		return;

	}
	cout << "请输入要查找的学生的学号：" << endl;
	cin >> id;
	for (int i = 0; i < student.size(); i++)
	{
		if (student[i].m_id == id)
		{
			index = i;
			flag = true;
			break;
		}
	}
	if (!flag)
	{
		cout << "您输入的学生不存在！" << endl;
		system("pause");
		system("cls");
		return;

	}
	cout << "学号：" << student[index].m_id
		<< "  姓名：" << student[index].m_name
		<< "  性别：" << student[index].m_gender
		<< "  年龄：" << student[index].m_age
		<< "  年级：" << student[index].m_grade
		<< "  班级：" << student[index].m_classes << endl;
	system("pause");
	system("cls");
	return;
}

void Base::DeleteStudent()
{
	this->InitVector();
	string id;
	bool flag = false;
	if (student.size() == 0)
	{
		cout << "学生的信息为空，请先添加学生信息" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "请输入您要查询的学生的学号：" << endl;
	cin >> id;
	for (auto& stu : student)
	{
		if (id == stu.m_id)
		{
			flag = true;
			break;
		}
	}
	if (!flag)
	{
		cout << "您输入的学生不存在" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < student.size(); i++)
	{
		if (id == student[i].m_id)
		{
			student.erase(student.begin() + i);
		}
	}
	this->ClearFile();
	this->SaveToFile();
	cout << "已经成功删除学生" << id << endl;
	system("pause");
	system("cls");
	return;
}

void Base::InitVector()
{
	student.clear();
	ifstream ifs;
	ifs.open("student.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
	}
	Student stu;
	while (ifs >> stu.m_id &&
		ifs >> stu.m_name &&
		ifs >> stu.m_gender &&
		ifs >> stu.m_age &&
		ifs >> stu.m_grade &&
		ifs >> stu.m_classes)
	{
		student.push_back(stu);
	}
	ifs.close();
}

void Base::ClearStudents()
{
	this->InitVector();
	string c;
	if (student.size() == 0)
	{
		cout << "学生的信息为空，请先添加学生信息" << endl;
		system("pause");
		system("cls");
		return;

	}
	cout << "您是否要清空所有学生的信息（Y/N）？" << endl;
	while (true)
	{
		cin >> c;
		if (c == "Y" || c == "y")
		{
			break;
		}
		else if (c == "N" || c == "n")
		{
			system("pause");
			system("cls");
			return;

		}
		else
		{
			cout << "您输入有误，请重新输入" << endl;
		}
	}
	this->ClearFile();
	this->InitVector();
	cout << "已经成功清全部学生信息！" << endl;
	system("pause");
	system("cls");
	return;
}

void Base::ModifiyStudent()
{
	this->InitVector();
	string _id;
	string _name;
	string id;
	string name;
	string gender;
	int age;
	int grade;
	int classes;

	int index = -1;
	bool flag = false;
	if (student.size() == 0)
	{
		cout << "学生的信息为空，请先添加学生的信息" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "请输入您要修改的学生学号：" << endl;
	cin >> id;
	for (int i = 0; i < student.size(); i++)
	{
		if (id == student[i].m_id)
		{
			index = i;
			flag = true;
			break;
		}
	}
	if (!flag)
	{
		cout << "您要修改的学生不存在！" << endl;
		system("pause");
		system("cls");
		return;
	}
	_id = id;
	_name = student[index].m_name;
	cout << "请输入您要修改学生的新学号：" << endl;
	cin >> id;
	student[index].m_id = id;
	cout << "请输入您要修改的学生的姓名：" << endl;
	cin >> name;
	student[index].m_name = name;
	cout << "请输入您要修改的学生的性别：" << endl;
	cin >> gender;
	while(true)
	{
		if (gender == "男" || gender == "女")
		{
			break;
		}
		cout << "您输入的性别有误，请重新输入：" << endl;
	}
	student[index].m_gender = gender;
	cout << "请输入您要修改的学生的年龄：" << endl;
	cin >> age;
	while (true)
	{
		if(age > 0 && age <= 120)
		{
			break;
		}
		cout << "您输入的年龄有误，请重新输入：" << endl;
	}
	student[index].m_age = age;
	cout << "请输入您要修改的学生的年级(1 ~ 6)：" << endl;
	cin >> grade;
	while (true)
	{
		if (grade > 0 && grade <= 6)
		{
			break;
		}
		cout << "您输入的年级有误，请重新输入：" << endl;
	}
	student[index].m_grade = grade;
	cout << "请输入您要修改的学生的班级(1 ~ 30)：" << endl;
	cin >> classes;
	while (true)
	{
		if (classes > 0 && classes <= 30)
		{
			break;
		}
		cout << "您输入的班级有误，请重新输入：" << endl;
	}
	student[index].m_classes = classes;
	
	this->ClearFile();
	this->SaveToFile();

	cout << "已经成功修改学号是" << _id << "姓名是" << _name
		<< " 为学号是" << id << "姓名是" << name << endl;
	system("pause");
	system("cls");
	return;
}

void Base::SaveToFile()
{
	ofstream ofs;
	ofs.open("student.txt", ios::in | ios::app);
	if (!ofs.is_open())
	{
		cout << "打开文件失败" << endl;
	}
	for (int i = 0; i < student.size(); i++)
	{
		ofs << student[i].m_id << " " 
			<< student[i].m_name << " " 
			<< student[i].m_gender << " " 
			<< student[i].m_age << " " 
			<< student[i].m_grade << " " 
			<< student[i].m_classes << endl;
	}
	ofs.close();
	return;
}

void Base::ClearFile()
{
	ofstream ofs;
	ofs.open("student.txt", ios::out | ios::trunc);
	if (!ofs.is_open())
	{
		cout << "文件打开失败" << endl;
	}
	ofs.close();
	return;
}

void Base::CreateFile()
{
	ofstream ofs;
	ofs.open("student.txt", ios::in | ios::app);
	ofs.close();
	return;
}
