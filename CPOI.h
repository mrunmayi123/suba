/***************************************************************************
 *============= Copyright by Darmstadt University of Applied Sciences =======
 ****************************************************************************
 * Filename        : CPOI.H
 * Author          :
 * Description     :
 *
 *
 ****************************************************************************/

#ifndef CPOI_H
#define CPOI_H
#include <iostream>		// Header für die Standard-IO-Objekte (z.B. cout, cin)
//#include<string>
#include <stdlib.h>
using namespace std;
//#include "CPoiDatabase.h"
//#include "CRoute.h"
//#include"t_poi.h"
#include "CWayPoint.h"
enum t_poi {RESTAURANT,SIGHTSEEING,SUPERMARKET,NOTFOUND};

class CPOI:public CWayPoint
{
private:
	string m_description;
	t_poi m_type;
public:

	CPOI(t_poi type, string name, string description, double latitude, double longitude);
	void getAllDataByReference(string & name, double & latitude, double & longitude, t_poi& type, string & description);		//getting all data by reference
	~CPOI();
	friend ostream& operator <<(ostream& out, const CPOI& p);
	void print(int format);
};
/********************
 **  CLASS END
 *********************/
#endif /* CPOI_H */
