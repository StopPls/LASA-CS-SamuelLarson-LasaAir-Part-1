//
//  main.cpp
//  LLTemplate
//
//  Created by James Shockey on 12/6/16.
//  Copyright © 2016 James Shockey. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cmath> 
#include "slist.h"

using namespace std;

class Airport
{
public:
	char    code[5];
	double   longitude;
	double   latitude;
	std::string dtos(double d);
	std::string toString();

};



void simpleSortTotal(Airport* s[], int c);
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d);

int main()
{
	ifstream infile;
	char cNum[10];
	int ref = 0;
	slist thingy;
	slist hundred;
	infile.open("./USAirportCodes.csv");
	if (infile.is_open())
	{
		int   c = 0;
		string thepile;
		getline(infile, thepile);
		while (infile.good()) {
			Airport* a = new Airport();
			infile.getline(a->code, 256, ',');
			infile.getline(cNum, 256, ',');
			a->latitude = atof(cNum);
			infile.getline(cNum, 256, '\n');
			a->longitude = atof(cNum);


			if (!string(a->code).compare("AUS")) ref = c;

			thingy.add(a);

			c++;

		}
		infile.close();

	}
	else
	{
		cout << "Error opening file";
	}


	// Initialize Linked List

	// 
	slist list;
	Airport* farthest = (Airport*)thingy.get(0);

	for (int i = 0; i < thingy.size() - 1; i++) 
	{

		Airport* aPrime = (Airport*)thingy.get(i);
		double x = distanceEarth(aPrime->latitude, aPrime->longitude, 30.1944, 97.67);

		if (x < 161) {
			list.add(aPrime);
		}
		if (x > distanceEarth(farthest->latitude, farthest->longitude, 30.1944, 97.67)) {
			farthest = aPrime;
		}
	}

	cout << "List of Airports within 100 miles: " << "/n";
	for (int y = 0; y < list.size(); y++) {
		cout << ((Airport*)list.get(y))->toString();
	}
	cout << "Farthest: " << endl << farthest->toString();
}



#define pi 3.14159265358979323846
#define earthRadiusKm 6371.0

// This function converts decimal degrees to radians
double deg2rad(double deg) {
	return (deg * pi / 180);
}

//  This function converts radians to decimal degrees
double rad2deg(double rad) {
	return (rad * 180 / pi);
}


/**
 * Returns the distance between two points on the Earth.
 * Direct translation from http://en.wikipedia.org/wiki/Haversine_formula
 * @param lat1d Latitude of the first point in degrees
 * @param lon1d Longitude of the first point in degrees
 * @param lat2d Latitude of the second point in degrees
 * @param lon2d Longitude of the second point in degrees
 * @return The distance between the two points in kilometers
 */
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d) {
	double lat1r, lon1r, lat2r, lon2r, u, v;
	lat1r = deg2rad(lat1d);
	lon1r = deg2rad(lon1d);
	lat2r = deg2rad(lat2d);
	lon2r = deg2rad(lon2d);
	u = sin((lat2r - lat1r) / 2);
	v = sin((lon2r - lon1r) / 2);
	return 2.0 * earthRadiusKm * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}

string Airport::toString() {
	string stringo = "";
	for (int x = 0; x < 5; x++) 

	{
		stringo += code[x];
	}
	stringo += "\nLongitude: ";
	stringo += dtos(longitude);
	stringo += "\nLatitude: " + dtos(latitude) + "\n\n";
	return stringo;
}

std::string Airport::dtos(double d)

{
	std::string str = "";
	int a = (int)log10(d);
	int cnt = 0;
	while (d != 0) 
	{
		str += (char)48 + ((int)d / (pow(10, (double)a)));
		d = fmod(d, pow(10, (double)a));
		cnt++;
		d *= 10;
		if (cnt == a + 1) { str += '.'; }

	}
	return str;

}

void simpleSortTotal(slist s, int c)
{

	Airport* ref = (Airport*)s.get(c);

	for (int x = 0; x < s.size(); x++) 
	{
		Airport* a = (Airport*)s.get(x);

		for (int y = x; y < s.size(); y++) 
		{

			Airport* b = (Airport*)s.get(y);
			double xDis = distanceEarth(ref->latitude, ref->longitude, a->latitude, a->longitude);
			double yDis = (ref->latitude, ref->longitude, b->latitude, b->longitude);

			if (xDis > yDis)
			{
				Airport* temp = (Airport*)s.get(x);
				s.set(x, s.get(y));
				s.set(y, temp);
			}

		}

	}

}