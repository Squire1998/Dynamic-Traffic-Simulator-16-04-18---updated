#ifndef Vehicle_h
#define Vehicle_h
#include <stdlib.h>
#include <string>
using namespace std;


class Vehicle {

protected:
	float height;				// Protected members to be
	float length;				// accessed by derived classes
	float width;
	float acceleration;
	float breaking_distance;
	int max_speed;
	// Determines vehicle position on road
	int queue_position;
	float sep_dist;
	float intermediate;
	string name;

public:
	// add in constructors and destructors (probably need to add them for sub classes as opposed to parent class).
	void set_height(int);		// Setter methods
	void set_length(float);
	void set_width(float);
	void set_max_speed(float);
	void set_acceleration(float);
	void set_breaking_distance(float);
	void set_total_dist(float &);
	void set_name(string);
	float total_dist = 0;
	
	int grid_location;
	virtual void foo(){} // <- write about this


	int get_grid_location(){ return this->grid_location; }
	int get_total_dist() { return this->total_dist; }
	float get_height();			// Getter methods
	float get_length();
	float get_width();
	float get_acceleration();
	float get_breaking_distance();
	int get_max_speed();
	float get_ave_speed();
	string get_name();
	// Other
	int grid_loction_(int stop_s, int start_s);

	bool operator < (const Vehicle& rhs) const
	{
		return (this->total_dist < rhs.total_dist);
	}

	bool operator >(const Vehicle& rhs) const
	{
		return !(this->operator<(rhs));
	}

	// CONSTRUCTORS AND DESTRUCTORS

};



//bool comparison(Vehicle a, Vehicle b){
//	return a.queue() < b.queue();
//}

bool CompareVehicleLocation(Vehicle* lhs, Vehicle* rhs);


#endif // !VEHICLE_H


// Idea for implementing condition where car reduces speed by a percentage if braking distance is > seperation
// distance. Though not sure how to implement this as braking and seperation are private members of different classes
// i.e. not sure how we would compare them.