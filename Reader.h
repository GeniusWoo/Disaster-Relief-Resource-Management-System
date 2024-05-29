#pragma once
#include <list>
#include <fstream>
#include <iostream>
#include <string>
#include"Diqu.h"
#include"CInfoFile.h"
#include"MFCApplication6.h"

class Reader
{
public:
	list< thing> Re;
	
	void ReadGuaner();
	void Write();
	int ComputeNeedKouzhao();
	int ComputeNeedMoney();
	int ComputeNeedFanghu();
	int ComputeNeedFood();
	int ComputeWuKouzhao();
	int ComputeWuMoney();
	int ComputeWuFanghu();
	int ComputeWuFood();

	int ComputeWuZongKouzhao();

	int ComputeWuZongMoney();

	int ComputeWuZongFanghu();

	int ComputeWuZongFood();

	void DistributeKouzhao();

	void DistributeMoney();

	void DistributeFanghu();

	void DistributeFood();

};

