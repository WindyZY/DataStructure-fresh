/**********************************
Experience 2 2018/10/18
Cpp for the implementation of ArrayList
By ����  201730685202
***********************************/
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<stdlib.h>
#include"AList.h"

using namespace std;

int main()
{
	int instru;
	Alist L;
	//Build the image for the user
	cout << "                  * * * * * *��ӭʹ�ô��ɹ�˾������Ϣ����* * * * * *" << endl << endl;
	cout << "                    �Թ�˾��������������Ϣ����Ȩ������������Ƽ�ʻ" << endl;
	cout << "                  =                                                =" << endl;
	cout << "                  =      1.����������Ϣ        2.��ʾ������Ϣ      =" << endl;
	cout << "                  =                                                =" << endl;
	cout << "                  =      3.����������Ϣ        4.ɾ��������Ϣ      =" << endl;
	cout << "                  =                                                =" << endl;
	cout << "                  =      5.�޸�������Ϣ        0.�˳�����ϵͳ      =" << endl;
	cout << "                  =                                                =" << endl;
	cout << "                               ��˾�ĳ���ֻ������֮��             " << endl << endl;
	cout << "                                    �����빦��ѡ�" << endl;
	L.read();
	//Do instructions when users enter the function number
	while (cin >> instru)
	{
		switch (instru)
		{
		case 1:
			L.inputNew();
			break;
		case 2:
			L.display();
			break;
		case 3:
			cout << "                  1.Brand  2.Type  3.Color  4.Car number  5.Manufacture year  6.Num" << endl;
			cout << "                  Please choose the parameter you want to rely on and enter: " << endl;
			L.findPos();
			break;
		case 4:
			cout << "                  Please enter the number of the car: ";
			int n4;
			cin >> n4;
			L.getCar(n4 - 1);
			L.remove(n4 - 1);
			break;
		case 5:
			cout << "                  Please enter the number of the car: ";
			int n5;
			cin >> n5;
			L.getCar(n5 - 1);
			L.modify(n5 - 1);
			break;
		case 0:
			cout << "                  Do you want to save the changes?" << endl;
			cout << "                  1.Save  2.Not to Save" << endl;
			int n0;
			cin >> n0;
			if (n0 == 1)
				L.save();
			cout << "                  Are you sure that you want to exit?" << endl;
			cout << "                  1.Exit  2.Stay" << endl;
			int m0;
			cin >> m0;
			if(m0==1)
				//Or exit(0);
				return 0;            //Exit the program
			break;
		}
	}

	system("pause");
	return 0;
}