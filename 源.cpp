#include "student.h"
int main()
{
	Base base;
	int c;
	base.CreateFile();
	while (true)
	{
		base.ShowMenu();
		cin >> c;
		while (cin.fail())
		{
			system("cls");
			base.ShowMenu();
			cin.clear();
			cin.ignore();
			cout << endl;
			cout << "您输入有误，请重新输入:" << endl;
			cin >> c;
		}
		switch (c)
		{
			case one:
				base.AddStudent();
				break;
			case two:
				base.DeleteStudent();
				break;
			case three:
				base.ModifiyStudent();
				break;
			case four:
				base.FindStudent();
				break;
			case five:
				base.ShowStudent();
				break;
			case six:
				base.ClearStudents();
				break;
			case zone:
				base.ExitSystem();
				break;
			default:
				continue;

		}

	}
	return 0;
}