#include "CPersistentTxt.h"

/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CPERSISTENTACCESS.CPP
* Author          :
* Description     :
*
*
****************************************************************************/


//System Include Files

#include <iostream>
#include<string>
#include<stdlib.h>

#include <fstream>
#include <sstream>
#include <cstdio>
using namespace std;
#include<map>


//Own Include Files
//#include "CWpDatabase.h"
//#include"CWayPoint.h"
//#include"CPoiDatabase.h"
//#include"CPOI.h"
//#include "CPersistentStorage.h"
//#include"CPersistentAccess.h"


//Method Implementations
CPersistentTxt::CPersistentTxt()
		{

		}
/*CPersistentTxt::~CPersistentTxt()
{
}*/

/*CPersistentAccess::~CPersistentAccess()
{

}*/

void CPersistentTxt::setMediaName(string name)
{
	m_filename = name;
	cout<<"Hello..."<<endl;
}
bool CPersistentTxt::writeData(const CWpDatabase& waypointDb,const CPoiDatabase& poiDb)
{
	string wpfile=m_filename+"-wp.txt";
	string poifile=m_filename+"-poi.txt";
		fstream myFile;
		fstream myFile1;
		CWpDatabase db1 = waypointDb;
		CPoiDatabase db2 = poiDb;
		//myFile.open(m_filename.c_str(),fstream::out);
		map<string,CWayPoint>::iterator itr; // Iterator
		for(itr = db1.getWpDB().begin(); itr != db1.getWpDB().end(); ++itr)
		{


			myFile.open(wpfile.c_str(),fstream::out);
			string s=itr->second.getName()+DELIMINATOR+db2.dtos(itr->second.getLatitude())+DELIMINATOR+db2.dtos(itr->second.getLatitude());


			if (myFile.is_open())
			{
				//Write a single line
				myFile << s << endl;
				//return true;
				myFile.close();
			}
			else
			{
				return false;
			}


		}
		//it->second.print(2);


		string pname,pdes;
		t_poi ptype;
		double plat,plon;
		//CPOI p1;
		// p1.getAllDataByReference(pname,plat,plon,ptype,pdes);

		map<string,CPOI>::iterator iter; // Iterator
		for(iter = db2.getPoiDB().begin(); iter != db2.getPoiDB().end(); ++iter)
		{
			myFile1.open(poifile.c_str(),fstream::out);
			iter->second.getAllDataByReference(pname,plat,plon,ptype,pdes);
			string s=db2.enumToString(ptype)+DELIMINATOR+pname+DELIMINATOR+pdes+DELIMINATOR+db2.dtos(plat)+DELIMINATOR+db2.dtos(plon);


			if (myFile.is_open())
			{
				//Write a single line
				myFile1 << s << endl;
				myFile.close();
				//return true;
			}
			else
			{
				return false;
			}


		}
		return true;

}


bool CPersistentTxt::readData(CWpDatabase& waypointDb, CPoiDatabase& poiDb,
		MergeMode mode)
{
	return true;
}
