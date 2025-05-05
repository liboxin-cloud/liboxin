#include "student.h"
void Base::ShowMenu()
{
	system("cls");
	cout << "\t\t\t************��ӭ����ѧ������ϵͳ************" << endl;
	cout << "\t\t\t����Խ������²���:" << endl;
	cout << "\t\t\t|------------------------------------------|" << endl;
	cout << "\t\t\t|             1   ���ѧ����Ϣ             |" << endl;
	cout << "\t\t\t|------------------------------------------|" << endl;
	cout << "\t\t\t|             2   ɾ��ѧ����Ϣ             |" << endl;
	cout << "\t\t\t|------------------------------------------|" << endl;
	cout << "\t\t\t|             3   �޸�ѧ����Ϣ             |" << endl;
	cout << "\t\t\t|------------------------------------------|" << endl;
	cout << "\t\t\t|             4   ��ѯѧ����Ϣ             |" << endl;
	cout << "\t\t\t|------------------------------------------|" << endl;
	cout << "\t\t\t|             5   ��ʾ������Ϣ             |" << endl;
	cout << "\t\t\t|------------------------------------------|" << endl;
	cout << "\t\t\t|             6   ���ϵͳ����             |" << endl;
	cout << "\t\t\t|------------------------------------------|" << endl;
	cout << "\t\t\t|             0   �˳�                     |" << endl;
	cout << "\t\t\t|------------------------------------------|" << endl;
	cout << "\t\t\t��ѡ��0-6����";
}

void Base::ExitSystem()
{
	cout << "���Ƿ�Ҫ�˳�ϵͳ��Y/N��:" << endl;
	string c;
	cin >> c;
	if (c == "Y" || c == "y")
	{
		cout << "��ӭ�´�ʹ��" << endl;
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
	cout << "��������Ҫ��ӵ�ѧ��ѧ�ţ�" << endl;
	cin >> id;
	for (auto& stud : student)
	{
		if (stud.m_id == id)
		{
			cout << "����ӵ�ѧ���Ѿ����ڣ����ʧ��" << endl;
			cout << "�Ƿ�������" << endl;
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
	cout << "��������ӵ�ѧ��������" << endl;
	cin >> name;
	cout << "��������ӵ�ѧ�����Ա�" << endl;
	while (true)
	{
		cin >> gender;
		if (gender == "��" || gender == "Ů")
		{
			break;
		}
		cout << "��������Ա���������������" << endl;
	}
	cout << "��������Ҫ��ӵ�ѧ�������䣺" << endl;
	while (true)
	{
		cin >> age;
		if (age > 0 && age <= 120)
		{
			break;
		}
		cout << "�������������������������" << endl;
	}
	cout << "��������Ҫ��ӵ�ѧ�����꼶(1 ~ 6)��" << endl;
	while (true)
	{
		cin >> grade;
		if (grade >= 1 && grade <= 6)
		{
			break;
		}
		cout << "��������꼶�������������룺" << endl;
	}
	cout << "��������Ҫ��ӵ�ѧ���İ༶(1 ~ 30)��" << endl;
	while (true)
	{
		cin >> classes;
		if (classes >= 1 && classes <= 30)
		{
			break;
		}
		cout << "�������ѧ���İ༶��������������:" << endl;
	}
	ofstream ofs;
	ofs.open("student.txt", ios::in | ios::app);
	if (!ofs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
	}
	ofs << id << " " << name << " " << gender << " " << age << " " << grade << " " << classes << endl;
	ofs.close();
	cout << "�Ѿ��ɹ����ѧ����" << name << "(ѧ�ţ�" << id << ")" << endl;
	system("pause");
	system("cls");
	return;

}

void Base::ShowStudent()
{
	this->InitVector();
	if (student.size() == 0)
	{
		cout << "ϵͳ��ѧ��Ϊ�գ��������ѧ����" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (auto& stu : student)
	{
		cout << "ѧ�ţ�" << stu.m_id
			<< "  ������" << stu.m_name
			<< "  �Ա�" << stu.m_gender
			<< "  ���䣺" << stu.m_age
			<< "  �꼶��" << stu.m_grade
			<< "  �༶��" << stu.m_classes << endl;
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
		cout << "ѧ������ϢΪ�գ��������ѧ����Ϣ" << endl;
		system("pause");
		system("cls");
		return;

	}
	cout << "������Ҫ���ҵ�ѧ����ѧ�ţ�" << endl;
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
		cout << "�������ѧ�������ڣ�" << endl;
		system("pause");
		system("cls");
		return;

	}
	cout << "ѧ�ţ�" << student[index].m_id
		<< "  ������" << student[index].m_name
		<< "  �Ա�" << student[index].m_gender
		<< "  ���䣺" << student[index].m_age
		<< "  �꼶��" << student[index].m_grade
		<< "  �༶��" << student[index].m_classes << endl;
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
		cout << "ѧ������ϢΪ�գ��������ѧ����Ϣ" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "��������Ҫ��ѯ��ѧ����ѧ�ţ�" << endl;
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
		cout << "�������ѧ��������" << endl;
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
	cout << "�Ѿ��ɹ�ɾ��ѧ��" << id << endl;
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
		cout << "�ļ���ʧ��" << endl;
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
		cout << "ѧ������ϢΪ�գ��������ѧ����Ϣ" << endl;
		system("pause");
		system("cls");
		return;

	}
	cout << "���Ƿ�Ҫ�������ѧ������Ϣ��Y/N����" << endl;
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
			cout << "��������������������" << endl;
		}
	}
	this->ClearFile();
	this->InitVector();
	cout << "�Ѿ��ɹ���ȫ��ѧ����Ϣ��" << endl;
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
		cout << "ѧ������ϢΪ�գ��������ѧ������Ϣ" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "��������Ҫ�޸ĵ�ѧ��ѧ�ţ�" << endl;
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
		cout << "��Ҫ�޸ĵ�ѧ�������ڣ�" << endl;
		system("pause");
		system("cls");
		return;
	}
	_id = id;
	_name = student[index].m_name;
	cout << "��������Ҫ�޸�ѧ������ѧ�ţ�" << endl;
	cin >> id;
	student[index].m_id = id;
	cout << "��������Ҫ�޸ĵ�ѧ����������" << endl;
	cin >> name;
	student[index].m_name = name;
	cout << "��������Ҫ�޸ĵ�ѧ�����Ա�" << endl;
	cin >> gender;
	while(true)
	{
		if (gender == "��" || gender == "Ů")
		{
			break;
		}
		cout << "��������Ա��������������룺" << endl;
	}
	student[index].m_gender = gender;
	cout << "��������Ҫ�޸ĵ�ѧ�������䣺" << endl;
	cin >> age;
	while (true)
	{
		if(age > 0 && age <= 120)
		{
			break;
		}
		cout << "������������������������룺" << endl;
	}
	student[index].m_age = age;
	cout << "��������Ҫ�޸ĵ�ѧ�����꼶(1 ~ 6)��" << endl;
	cin >> grade;
	while (true)
	{
		if (grade > 0 && grade <= 6)
		{
			break;
		}
		cout << "��������꼶�������������룺" << endl;
	}
	student[index].m_grade = grade;
	cout << "��������Ҫ�޸ĵ�ѧ���İ༶(1 ~ 30)��" << endl;
	cin >> classes;
	while (true)
	{
		if (classes > 0 && classes <= 30)
		{
			break;
		}
		cout << "������İ༶�������������룺" << endl;
	}
	student[index].m_classes = classes;
	
	this->ClearFile();
	this->SaveToFile();

	cout << "�Ѿ��ɹ��޸�ѧ����" << _id << "������" << _name
		<< " Ϊѧ����" << id << "������" << name << endl;
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
		cout << "���ļ�ʧ��" << endl;
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
		cout << "�ļ���ʧ��" << endl;
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
