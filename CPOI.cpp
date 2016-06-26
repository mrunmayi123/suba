

/***************************************************************************
 *============= Copyright by Darmstadt University of Applied Sciences =======
 ****************************************************************************
 * Filename        : CPOI.CPP
 * Author          :
 * Description     :
 *
 *
 ****************************************************************************/


//System Include Files
//#include<iostream>
//#include<string>
//#include <stdlib.h>
//using namespace std;
//Own Include Files

//#include "CPoiDatabase.h"
//#include "CWayPoint.h"
#include "CPOI.h"

//Method Implementations
/**
 * Method Name: print(int format)
 * Method Description: To print the POI
 * @param: integer(format of the latitude and longitude)
 * Return Value: void
 *
 */

void CPOI::print(int format)
{

	//cout<<"=====Point of Interest-Print Method====="<<endl;
	switch(m_type)						//switch case used to select printing according to type
	{
	case RESTAURANT:
		cout<<" of Type Restaurant: "<<m_description<<endl;
		CWayPoint::print(MMSS);
		//	cout<<getName()<<" on latitude "<<getLatitude()<<" and longitude "<<getLongitude()<<endl;
		break;

	case SIGHTSEEING:
		cout<<" of Type sight seeing: "<<m_description<<endl;
		CWayPoint::print(MMSS);
		//		cout<<getName()<<" on latitude "<<getLatitude()<<" and longitude "<<getLongitude()<<endl;
		break;
	case SUPERMARKET:
		cout<<"of Type supermarket:"<<m_description<<endl;
		CWayPoint::print(MMSS);
		//cout<<getName()<<" on latitude "<<getLatitude()<<" and longitude "<<getLongitude()<<endl;
		break;
	case NOTFOUND:
		cout<<"POI not found"<<endl;
		break;

	default:
		cout<<"Error input"<<endl;
	}

}
/**
 * Method Name:CPOI(t_poi type, string name, string description, double latitude, double longitude)
 * Method Description: Constructor of POI
 * @param: t_poi type, string name, string description, double latitude, double longitude
 * return value: none
 */
CPOI::CPOI(t_poi type, string name, string description, double latitude, double longitude):CWayPoint(name,latitude,longitude)
{
	//cout<<"==========POINT OF INTEREST=========="<<endl;
	set(name,latitude,longitude);
	m_type=type;
	//		m_name=name;
	//		m_latitude=latitude;
	//		m_longitude=longitude;
	m_description=description;

}
CPOI::~CPOI(){}
/**
 * Method Name:getAllDataByReference(string & name, double & latitude, double & longitude, t_poi& type, string & description)
 * Method Description:Getting all data by reference
 * @Param: string & name, double & latitude, double & longitude, t_poi& type, string & description
 * Return Value:Void
 */
void CPOI::getAllDataByReference(string & name, double & latitude, double & longitude, t_poi& type, string & description)
{
	name=getName();
	latitude=getLatitude();
	longitude=getLongitude();
	type=m_type;
	description=m_description;
}
/**
 * Method Name:operator <<(ostream& out, const CPOI& p)
 * Method Description: to overload the operator << to print function
 * @param:ostream& out, const CPOI& p
 * Return Value Type:ostream&
 *
 */
ostream& operator <<(ostream& out, const CPOI& p)
{
	int deg,deg1,mm,mm1;	//local declaration
	double ss,ss1;

	//CWayPoint cp;
	switch(p.m_type)						//switch case used to select printing according to type
	{
	case RESTAURANT:

		p.transformLongitude2degmmss(deg,mm,ss);
		p.transformLatitude2degmmss(deg1,mm1,ss1);
		out<<" of Type Restaurant: "<<p.m_description<<endl<<p.getName()<<" on latitude "<<p.getLatitude()<<" and longitude "<<p.getLongitude()<<endl;
		break;

	case SIGHTSEEING:

		p.transformLongitude2degmmss(deg,mm,ss);
		p.transformLatitude2degmmss(deg1,mm1,ss1);

		out<<" of Type sight seeing: "<<p.m_description<<endl<<p.getName()<<" on longitude= "<<deg<<" deg "<<mm<<" min "<<ss<<" sec "<<endl<<" on latitude= "<<deg1<<" deg "<<mm1<<" min "<<ss1<<" sec "<<endl;
		break;
	case SUPERMARKET:

		p.transformLongitude2degmmss(deg,mm,ss);
		p.transformLatitude2degmmss(deg1,mm1,ss1);
		out<<"of Type supermarket:"<<p.m_description<<endl<<p.getName()<<" on latitude "<<p.getLatitude()<<" and longitude "<<p.getLongitude()<<endl;
		break;
	case NOTFOUND:
			cout<<"POI not found"<<endl;
			break;

	default:
		out<<"Error input"<<endl;
	}
	return out;
}

