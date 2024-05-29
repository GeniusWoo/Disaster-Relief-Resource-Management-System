#pragma once
class GUANERS
{
	CString Name;
	long ID;
public:
	GUANERS() { Name = _T("Noname"); ID = 0; }
	long GetID() { return ID; }
	CString GetName() { return Name; }
	void SetID(CString na) { Name = na; }
	void SetName(long newID) { ID = newID; }

};

