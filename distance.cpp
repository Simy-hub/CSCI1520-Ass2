//assig2.cpp
/*CSCI1520
 *Assignment: 2
 */
#include <iostream>

int main()
{
	double lat1, lon1, lat2, lon2, φ1, φ2, λ,λ1, λ2, π, r;
	double a, c, dgc;
	double p, q,q1,q2,s,s1,s2,s3, drt;

	π = 3.14159265358979;
	r = 6371;

	std::cout << "Enter location 1 (lat lon) : ";
	std::cin >> lat1 >> lon1;
	std::cout << "Enter location 2 (lat lon) : ";
	std::cin >> lat2 >> lon2;

	φ1 = (lat1 * π) / 180;
	λ1 = (lon1 * π) / 180;
	φ2 = (lat2 * π) / 180;
	λ2 = (lon2 * π) / 180;
	a = pow(sin((φ2 - φ1) / 2), 2) + (cos(φ1)) * (cos(φ2)) * pow(sin((λ2 - λ1) / 2), 2);
	c = 2 * atan2(sqrt(a), sqrt(1 - a));
	dgc = r * c;

	p = log((tan(π / 4 + φ2 / 2)) / (tan(π / 4 + φ1 / 2)));
	q1= (φ2 - φ1) / p;
	q2= cos(φ1);
	s1 = λ2 - λ1;
	s2 = λ2 - λ1 - 2 * π;
	s3= λ2 - λ1 + 2 * π;
	λ = λ2 - λ1;

	if (lat1 != lat2)
		q = q1;
	if (lat1 == lat2)
	    q = q2;
	if (abs(λ) <= π)
		s = s1;
	else if (abs(λ) > π &&  lon1 < lon2)
		s = s2;
	else if (abs(λ) > π && lon1 >= lon2)
		s = s3;

	drt = sqrt(pow(φ2 - φ1, 2) + pow(q , 2)*pow(s,2)) * r;

	std::cout << "Great-circle distance = " << dgc << "km"<<"\n";
	std::cout << "  Rhumb line distance = " << drt << "km";


}

