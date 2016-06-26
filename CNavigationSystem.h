/***************************************************************************
 *============= Copyright by Darmstadt University of Applied Sciences =======
 ****************************************************************************
 * Filename        : CNAVIGATIONSYSTEM.H
 * Author          :
 * Description     :
 *
 *
 ****************************************************************************/

#ifndef CNAVIGATIONSYSTEM_H
#define CNAVIGATIONSYSTEM_H

#include "CGPSSensor.h"
#include "CRoute.h"
#include "CPersistentTxt.h"
//#include "CPoiDatabase.h"
//#include "CWpDatabase.h"

class CNavigationSystem
{
private:
	void printRoute();
	void enterRoute();
	CGPSSensor m_GPSSensor;
	CRoute m_Route, m_Route2, m_res;
	CPoiDatabase m_PoiDatabase;
	CWpDatabase m_WpDatabase;
public:

	void run();

	CNavigationSystem();
};
/********************
 **  CLASS END
 *********************/
#endif /* CNAVIGATIONSYSTEM_H */
