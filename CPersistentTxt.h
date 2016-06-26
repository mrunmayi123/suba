/***************************************************************************
 *============= Copyright by Darmstadt University of Applied Sciences =======
 ****************************************************************************
 * Filename        : CPERSISTENTACCESS.H
 * Author          :
 * Description     :
 *
 *
 ****************************************************************************/

#ifndef CPERSISTENTACCESS_H
#define CPERSISTENTACCESS_H

#include "CPersistentStorage.h"
//#include "CWpDatabase.h"
//#include "CPoiDatabase.h"

#define DELIMINATOR ","

class CPersistentTxt: public CPersistentStorage
{
private:
	string m_filename;
public:
	CPersistentTxt();
 //~CPersistentTxt();
	void setMediaName(string name);

	bool writeData(const CWpDatabase& waypointDb, const CPoiDatabase& poiDb);

	bool readData(CWpDatabase& waypointDb, CPoiDatabase& poiDb, MergeMode mode);
};
/********************
 **  CLASS END
 *********************/
#endif /* CPERSISTENTACCESS_H */
