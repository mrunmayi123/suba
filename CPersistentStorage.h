/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CPERSISTENTSTORAGE.H
* Author          :
* Description     :
*
*
****************************************************************************/

#ifndef CPERSISTENTSTORAGE_H
#define CPERSISTENTSTORAGE_H
#include<iostream>

//#include "CWpDatabase.h"
//#include "CPoiDatabase.h"
#include "CRoute.h"


enum MergeMode { MERGE, REPLACE };
class CPersistentStorage {
public:

    //virtual ~CPersistentStorage();

    virtual void setMediaName(std::string name) =0;



    virtual bool readData(CWpDatabase& waypointDb, CPoiDatabase& poiDb, MergeMode mode) = 0;

    virtual bool writeData(const CWpDatabase& waypointDb,const CPoiDatabase& poiDb) = 0;


};
/********************
**  CLASS END
*********************/
#endif /* CPERSISTENTSTORAGE_H */
