#ifndef DIQU
#define DIQU

#include<iostream>
using namespace std;
class Diqu {
	CString Name;                                   //��������
	CString Thingname;                              //����������
	int Num;                                    //����
	bool Zhuangtai;                                //״̬���Ƿ���������
public:
	Diqu() { Num = 0; Zhuangtai = false; }
	Diqu(CString name, CString tname= '\0',int n=0) {
		Name = name; Thingname = tname;
		Num = n; Zhuangtai = false;
	}
	//���ؽӿ�
	CString GetName() { return Name; }
	CString GetThingname() { return Thingname; }
	bool GetZhaungtai() { return Zhuangtai; }
	int GetNum() { return Num; }
	//������Ϣ
	void SetName(CString name) { Name = name; }
	void Satisfied() { Zhuangtai = true; }                 //����������
	void SetThingname(CString tname) { Thingname = tname; }
	void SetNum(int n) { Num = n; }
};



#endif // !DIQU

