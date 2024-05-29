#include "pch.h"
#include "Reader.h"

void Reader::ReadGuaner()
{
	CFileDialog fDlg(TRUE, _T("txt"), _T("��Ա�����Ϣ"), OFN_OVERWRITEPROMPT, _T("�ı��ĵ�(*.txt)|*.txt"), NULL);
	CStdioFile file(fDlg.GetPathName(), CFile::modeRead);
	CString cs;
	setlocale(LC_CTYPE, ("chs"));
	Re.clear();
	while (file.ReadString(cs))
	{
		thing tmp;
		int x = cs.Find(_T("|"));
		int x2 = cs.Find(_T("|"), x + 1);
		int x3 = cs.Find(_T("|"), x2 + 1);
		int x4 = cs.Find(_T("|"), x3 + 1);

		int n = x2 - x - 1;
		int l = x3 - x2 - 1;
		int m = x4 - x3 - 1;
		tmp.SetOrigin(cs.Left(x));
		tmp.SetName(cs.Mid(x + 1, n));
		CString c = cs.Mid(x2 + 1, l);
		tmp.SetNum(_wtoi(c));
		tmp.SetTime(cs.Mid(x3 + 1, m));
		if (tmp.GetNum()==0) continue;
		CString d = cs.Right(cs.GetLength() - x4-1);
		tmp.SetLeaved(_wtoi(d));
		Re.push_back(tmp);
	}
	file.Close();
}

void Reader::Write()
{
	CFileDialog fDlg(FALSE, _T("txt"), _T("��Ա�����Ϣ"), OFN_OVERWRITEPROMPT, _T("�ı��ĵ�(*.txt)|*.txt"), NULL);
	CStdioFile file(fDlg.GetPathName(), CFile::modeWrite);
	list<thing>::iterator iter,qu;
	qu = Re.end();
	for (iter = Re.begin(); iter != qu; iter++) {
		CString cs = iter->GetOrigin(); cs += _T("|");
		cs += iter->GetName(); cs += _T("|");
		CString b; b.Format(L"%d", iter->GetNum());
		cs += b; cs += _T("|");
		cs += iter->GetTime(); cs += _T("|");
		CString e; e.Format(L"%d", iter->GetLeaved());
		cs += e; cs += "\n";
		if(iter->GetNum()==0)continue;
		file.WriteString(cs.GetBuffer());
	}
	file.Close();
}

int Reader::ComputeNeedKouzhao()
{
	CInfoFile file;
	file.ls.clear();
	file.ReadDocline();
	int num = 0;
	list<Diqu>::iterator iter;
	for (iter = file.ls.begin(); iter != file.ls.end(); iter++) {
		if (iter->GetThingname() == TEXT("����")&&iter->GetZhaungtai() == false) num += iter->GetNum();
	}
	file.ls.clear();
	return num;
}

int Reader::ComputeNeedMoney()
{
	CInfoFile file;
	file.ls.clear();
	file.ReadDocline();
	int num = 0;
	list<Diqu>::iterator iter;
	for (iter = file.ls.begin(); iter != file.ls.end(); iter++) {
		if (iter->GetThingname() == TEXT("��Ǯ") && iter->GetZhaungtai() == false) num += iter->GetNum();
	}
	file.ls.clear();
	return num;
}

int Reader::ComputeNeedFanghu()
{
	CInfoFile file;
	file.ls.clear();
	file.ReadDocline();
	int num = 0;
	list<Diqu>::iterator iter;
	for (iter = file.ls.begin(); iter != file.ls.end(); iter++) {
		if (iter->GetThingname() == TEXT("������") && iter->GetZhaungtai() == false) num += iter->GetNum();
	}
	file.ls.clear();
	return num;
}

int Reader::ComputeNeedFood()
{
	CInfoFile file;
	file.ls.clear();
	file.ReadDocline();
	int num = 0;
	list<Diqu>::iterator iter;
	for (iter = file.ls.begin(); iter != file.ls.end(); iter++) {
		if (iter->GetThingname() == TEXT("ʳ��")&&iter->GetZhaungtai()==false) num += iter->GetNum();
	}
	file.ls.clear();
	return num;
}


int Reader::ComputeWuKouzhao() {
	Re.clear();
	ReadGuaner();
	int total = 0;
	list<thing>::iterator ech;
	for (ech = Re.begin(); ech != Re.end(); ech++) {
		if (ech->GetName() == TEXT("����")) total += ech->GetLeaved();
	}
	Re.clear();
	return total;
}

int Reader::ComputeWuMoney() {
	Re.clear();
	ReadGuaner();
	int total = 0;
	list<thing>::iterator ech;
	for (ech = Re.begin(); ech != Re.end(); ech++) {
		if (ech->GetName() == TEXT("��Ǯ")) total += ech->GetLeaved();
	}
	Re.clear();
	return total;
}

int Reader::ComputeWuFanghu() {
	Re.clear();
	ReadGuaner();
	int total = 0;
	list<thing>::iterator ech;
	for (ech = Re.begin(); ech != Re.end(); ech++) {
		if (ech->GetName() == TEXT("������")) total += ech->GetLeaved();
	}
	Re.clear();
	return total;
}

int Reader::ComputeWuFood() {
	Re.clear();
	ReadGuaner();
	int total = 0;
	list<thing>::iterator ech;
	for (ech = Re.begin(); ech != Re.end(); ech++) {
		if (ech->GetName() == TEXT("ʳ��")) total += ech->GetLeaved();
	}
	Re.clear();
	return total;
}
int Reader::ComputeWuZongKouzhao() {
	Re.clear();
	ReadGuaner();
	int total = 0;
	list<thing>::iterator ech;
	for (ech = Re.begin(); ech != Re.end(); ech++) {
		if (ech->GetName() == TEXT("����")) total += ech->GetNum();
	}
	Re.clear();
	return total;
}

int Reader::ComputeWuZongMoney() {
	Re.clear();
	ReadGuaner();
	int total = 0;
	list<thing>::iterator ech;
	for (ech = Re.begin(); ech != Re.end(); ech++) {
		if (ech->GetName() == TEXT("��Ǯ")) total += ech->GetNum();
	}
	Re.clear();
	return total;
}

int Reader::ComputeWuZongFanghu() {
	Re.clear();
	ReadGuaner();
	int total = 0;
	list<thing>::iterator ech;
	for (ech = Re.begin(); ech != Re.end(); ech++) {
		if (ech->GetName() == TEXT("������")) total += ech->GetNum();
	}
	Re.clear();
	return total;
}

int Reader::ComputeWuZongFood() {
	Re.clear();
	ReadGuaner();
	int total = 0;
	list<thing>::iterator ech;
	for (ech = Re.begin(); ech != Re.end(); ech++) {
		if (ech->GetName() == TEXT("ʳ��")) total += ech->GetNum();
	}
	Re.clear();
	return total;
}

void Reader::DistributeKouzhao() {
	int Needsum = ComputeNeedKouzhao(), Wusum = ComputeWuKouzhao();
	CInfoFile dfile;
	dfile.ReadDocline();
	ReadGuaner();
	list<Diqu>::iterator it;
	list<thing>::iterator ot,temp=Re.end();
	if (Needsum <= Wusum) {
		for (it = dfile.ls.begin(); it != dfile.ls.end(); it++) 
			if(it->GetThingname()== TEXT("����")&&it->GetZhaungtai()==false) it->Satisfied();
		int dieta = Wusum - Needsum;
		for (ot = Re.begin(); ot != Re.end(); ot++) {
			if (ot->GetName() == TEXT("����")&& ot->GetLeaved() >= dieta) {
				ot->SetLeaved(dieta);
				temp = ot; break;
			}
		}
		for (ot = Re.begin(); ot != Re.end(); ot++)
			if (ot->GetName() == TEXT("����")&&ot!=temp) ot->SetLeaved(0);
	}	
	else {
		int lay = Wusum;
		for (it = dfile.ls.begin(); it != dfile.ls.end(); it++)
			if (it->GetThingname() == TEXT("����") && it->GetZhaungtai() == false) {
				if (it->GetNum() <= lay) { it->Satisfied(); lay -= it->GetNum(); }
				else break;
			}
		int n = Wusum - lay;
		for (ot = Re.begin(); ot != Re.end(); ot++) {
			if (ot->GetName() == TEXT("����")) {
				if (ot->GetLeaved() < n) {
					n -= ot->GetLeaved(); ot->SetLeaved(0);
				}
				else ot->SetLeaved(ot->GetLeaved() - n);
			}
		}
	}
	dfile.WirteDocline();
	Write();
}

void Reader::DistributeMoney() {
	int Needsum = ComputeNeedMoney(), Wusum = ComputeWuMoney();
	CInfoFile dfile;
	dfile.ReadDocline();
	ReadGuaner();
	list<Diqu>::iterator it;
	list<thing>::iterator ot, temp = Re.end();
	if (Needsum <= Wusum) {
		for (it = dfile.ls.begin(); it != dfile.ls.end(); it++)
			if (it->GetThingname() == TEXT("��Ǯ") && it->GetZhaungtai() == false) it->Satisfied();
		int dieta = Wusum - Needsum;
		for (ot = Re.begin(); ot != Re.end(); ot++) {
			if (ot->GetName() == TEXT("��Ǯ") && ot->GetLeaved() >= dieta) {
				ot->SetLeaved(dieta);
				temp = ot; break;
			}
		}
		for (ot = Re.begin(); ot != Re.end(); ot++)
			if (ot->GetName() == TEXT("��Ǯ") && ot != temp) ot->SetLeaved(0);
	}
	else {
		int lay = Wusum;
		for (it = dfile.ls.begin(); it != dfile.ls.end(); it++)
			if (it->GetThingname() == TEXT("��Ǯ") && it->GetZhaungtai() == false) {
				if (it->GetNum() <= lay) { it->Satisfied(); lay -= it->GetNum(); }
				else break;
			}
		int n = Wusum - lay;
		for (ot = Re.begin(); ot != Re.end(); ot++) {
			if (ot->GetName() == TEXT("��Ǯ")) {
				if (ot->GetLeaved() < n) {
					n -= ot->GetLeaved(); ot->SetLeaved(0);
				}
				else ot->SetLeaved(ot->GetLeaved() - n);
			}
		}
	}
	dfile.WirteDocline();
	Write();
}

void Reader::DistributeFanghu() {
	int Needsum = ComputeNeedFanghu(), Wusum = ComputeWuFanghu();
	CInfoFile dfile;
	dfile.ReadDocline();
	ReadGuaner();
	list<Diqu>::iterator it;
	list<thing>::iterator ot, temp = Re.end();
	if (Needsum <= Wusum) {
		for (it = dfile.ls.begin(); it != dfile.ls.end(); it++)
			if (it->GetThingname() == TEXT("������") && it->GetZhaungtai() == false) it->Satisfied();
		int dieta = Wusum - Needsum;
		for (ot = Re.begin(); ot != Re.end(); ot++) {
			if (ot->GetName() == TEXT("������") && ot->GetLeaved() >= dieta) {
				ot->SetLeaved(dieta);
				temp = ot; break;
			}
		}
		for (ot = Re.begin(); ot != Re.end(); ot++)
			if (ot->GetName() == TEXT("������") && ot != temp) ot->SetLeaved(0);
	}
	else {
		int lay = Wusum;
		for (it = dfile.ls.begin(); it != dfile.ls.end(); it++)
			if (it->GetThingname() == TEXT("������") && it->GetZhaungtai() == false) {
				if (it->GetNum() <= lay) { it->Satisfied(); lay -= it->GetNum(); }
				else break;
			}
		int n = Wusum - lay;
		for (ot = Re.begin(); ot != Re.end(); ot++) {
			if (ot->GetName() == TEXT("������")) {
				if (ot->GetLeaved() < n) {
					n -= ot->GetLeaved(); ot->SetLeaved(0);
				}
				else ot->SetLeaved(ot->GetLeaved() - n);
			}
		}
	}
	dfile.WirteDocline();
	Write();
}

void Reader::DistributeFood() {
	int Needsum = ComputeNeedFood(), Wusum = ComputeWuFood();
	CInfoFile dfile;
	dfile.ReadDocline();
	ReadGuaner();
	list<Diqu>::iterator it;
	list<thing>::iterator ot, temp = Re.end();
	if (Needsum <= Wusum) {
		for (it = dfile.ls.begin(); it != dfile.ls.end(); it++)
			if (it->GetThingname() == TEXT("ʳ��") && it->GetZhaungtai() == false) it->Satisfied();
		int dieta = Wusum - Needsum;
		for (ot = Re.begin(); ot != Re.end(); ot++) {
			if (ot->GetName() == TEXT("ʳ��") && ot->GetLeaved() >= dieta) {
				ot->SetLeaved( dieta);
				temp = ot; break;
			}
		}
		for (ot = Re.begin(); ot != Re.end(); ot++)
			if (ot->GetName() == TEXT("ʳ��") && ot != temp) ot->SetLeaved(0);
	}
	else {
		int lay = Wusum;
		for (it = dfile.ls.begin(); it != dfile.ls.end(); it++)
			if (it->GetThingname() == TEXT("ʳ��") && it->GetZhaungtai() == false) {
				if (it->GetNum() <= lay) { it->Satisfied(); lay -= it->GetNum(); }
				else break;
			}
		int n = Wusum - lay;
		for (ot = Re.begin(); ot != Re.end(); ot++) {
			if (ot->GetName() == TEXT("ʳ��")) {
				if (ot->GetLeaved() < n) {
					n -= ot->GetLeaved(); ot->SetLeaved(0);
				}
				else ot->SetLeaved(ot->GetLeaved() - n);
			}
		}
	}
	dfile.WirteDocline();
	Write();
}