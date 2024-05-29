#ifndef DIQU
#define DIQU

#include<iostream>
using namespace std;
class Diqu {
	CString Name;                                   //地区名称
	CString Thingname;                              //所需物名称
	int Num;                                    //数量
	bool Zhuangtai;                                //状态：是否满足需求
public:
	Diqu() { Num = 0; Zhuangtai = false; }
	Diqu(CString name, CString tname= '\0',int n=0) {
		Name = name; Thingname = tname;
		Num = n; Zhuangtai = false;
	}
	//返回接口
	CString GetName() { return Name; }
	CString GetThingname() { return Thingname; }
	bool GetZhaungtai() { return Zhuangtai; }
	int GetNum() { return Num; }
	//更改信息
	void SetName(CString name) { Name = name; }
	void Satisfied() { Zhuangtai = true; }                 //已满足需求
	void SetThingname(CString tname) { Thingname = tname; }
	void SetNum(int n) { Num = n; }
};



#endif // !DIQU

