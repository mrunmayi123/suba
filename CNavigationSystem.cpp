

/***************************************************************************
 *============= Copyright by Darmstadt University of Applied Sciences =======
 ****************************************************************************
 * Filename        : CNAVIGATIONSYSTEM.CPP
 * Author          :
 * Description     :
 *
 *
 ****************************************************************************/


//System Include Files
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
//Own Include Files
#include "CNavigationSystem.h"
//#include"CRoute.h"
//#include"CWayPoint.h"
//#include"CPOI.h"
//#include"CWpDatabase.h"
//#include "CPersistentStorage.h"
//#include "CPersistentTxt.h"
//#include"CPoiDatabase.h"
//#define WPFILE "persis-wp.txt"
//#define POIFILE "persis-poi.txt"


//Method Implementations
/**
 * Constructor
 */

CNavigationSystem::CNavigationSystem(){}
/**
 *Method Name:run()
 *Method Description:To run the entire Navigation system.The only public function that the class has.
 *					The other functions are inaccessible to user.
 *@param: none
 *Return type value void
 */
void CNavigationSystem::run()
{
	CPersistentTxt store;
	enterRoute();
	CWpDatabase wdb;
	CPoiDatabase pdb;
	printRoute();
store.setMediaName("persis");
//store.writeData(m_PoiDatabase,m_WpDatabase);
}
/**
 * Method Name:enterRoute()
 * Method Description:The method connects the routes to the databases. It allows the user to enter the route
 * 					and and perform various funtions on it
 * @param:none
 * Return Type:void
 *
 */
void CNavigationSystem::enterRoute()
{

	m_Route.connectToPoiDatabase(&m_PoiDatabase);			//connects the route to POI database

	m_Route.connectToWpDatabase(&m_WpDatabase);		//connects the route to WayPoint database
	// TODO: Fügen Sie ab hier Ihren Programmcode ein
	cout << "MMP_Mand2 gestarted." << endl << endl;

	CWayPoint frankfurt("Frankfurt",23.38,77.13);		//creating CWayPoints
	m_WpDatabase.addWaypoint(frankfurt);				//Adding WayPoints to database
	CWayPoint nashik("Nashik",20,74.63);
	m_WpDatabase.addWaypoint(nashik);
	CWayPoint darmstadt("Darmstadt",49.8667,8.6500);
	m_WpDatabase.addWaypoint(darmstadt);
	CWayPoint berlin("Berlin",52.5166,13.4);
	m_WpDatabase.addWaypoint(berlin);
	CWayPoint tokio("Tokio",35.6833,139.6833);
	m_WpDatabase.addWaypoint(tokio);
	m_WpDatabase.print();										//printing database

	CPOI Mensa(RESTAURANT,"Mensa","Best Restaurant in Darmstadt ",70.75,12.8);//creating poi's
	m_PoiDatabase.addPoi(Mensa);		//adding POI's to database		//adding poi's to database
	CPOI Nashik(SIGHTSEEING,"Nashik","Piligrimage Centre",20,74.63);
	m_PoiDatabase.addPoi(Nashik);
	CPOI LuisenCenter(SUPERMARKET,"Luisen Center","Largest Mall in Frankfurt",56,87);
	m_PoiDatabase.addPoi(LuisenCenter);		//adding POI's to database

	CPOI EiffelTower(SIGHTSEEING,"Eiffel Tower","Wonders of World",12,123);
	m_PoiDatabase.addPoi(EiffelTower);		//adding POI's to database
	CPOI SarvannaBhavan(RESTAURANT,"Sarvanna Bhavan","Indian Restaurant in Frankfurt",34,78.6);
	m_PoiDatabase.addPoi(SarvannaBhavan);		//adding POI's to database
	CPOI Darmstadt(SIGHTSEEING,"Darmstadt","Science City of Germany ",75,30);
	m_PoiDatabase.addPoi(Darmstadt);		//adding POI's to database
	m_PoiDatabase.print();
	CWayPoint delhi("Delhi",29,75);		//creating CWayPoints
	//cout<<delhi;
	m_WpDatabase.addWaypoint(delhi);
	m_Route.addWayPoint("Delhi");						//adding waypoint to route
	m_Route.addWayPoint("Berlin");
	m_Route.addWayPoint("Darmstadt");
	m_Route.addWayPoint("Frankfurt");
	m_Route.addPoi("Mensa","Darmstadt");				//adding poi to route
	m_Route.addPoi("Darmstadt","Berlin");
	m_Route.addPoi("Sarvanna Bhavan","Delhi");
	//m_Route.print();
	CPOI Btor(SIGHTSEEING,"Brandenburger Tor","Famous Place in Germany ",45,32.6);
	m_PoiDatabase.addPoi(Btor);
	cout<<"-----Final----"<<endl;
	m_PoiDatabase.print();
	cout<<"-----Final WP----"<<endl;
	CWayPoint mumbai("Mumbai",56,80.0);
	m_WpDatabase.addWaypoint(mumbai);
	m_WpDatabase.print();
	m_Route+="Nashik";				//testing operator overloading for +=
	m_Route+="Darmstadt";

	CRoute m_Route2;				//creating 2nd route
	m_Route2.connectToPoiDatabase(&m_PoiDatabase);			//connects 2nd the route to POI database
	//	//	CWpDatabase wdb;
	m_Route2.connectToWpDatabase(&m_WpDatabase);		//connects the 2nd route to Waypoint database
	//
	m_Route2.addWayPoint("Mumbai");				//adding waypoints to route2
	m_Route2.addWayPoint("Darmstadt");
	m_Route2.addWayPoint("Delhi");
	m_Route2.addPoi("Brandenburger Tor","Mumbai");		//	adding poi to route2

	cout<<"------Printing Route 2------"<<endl;
	m_Route2.print();
	m_Route+m_Route2;	//adding routes 1


}
/**
 * Method Name:printRoute()
 * Method Description:to print the route
 * @param:none
 * Return Type:void
 */
void CNavigationSystem::printRoute()
{
	cout<<"---------Printing Route---------"<<endl;
	m_Route.print();
}
