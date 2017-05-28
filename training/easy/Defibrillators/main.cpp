#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

double x_calc(double lonA, double lonB, double latA, double latB){
	return (lonB - lonA)*cos((latA + latB)/2);
}

double y_calc(double latA, double latB){
	return latA - latB;
}

double d_calc(double lonA, double lonB, double latA, double latB, int earth_radius){
	double lonA_rad = lonA * 0.0174532925;
	double lonB_rad = lonB * 0.0174532925;
	double latA_rad = latA * 0.0174532925;
	double latB_rad = latB * 0.0174532925;

	double x = x_calc(lonA_rad, lonB_rad, latA_rad, latB_rad);
	double y = y_calc(latA_rad, latB_rad);
	return sqrt(pow(x,2) + pow(y,2)) * earth_radius;
}

double get_number(string number){
	std::ostringstream stream;
	stream << number;
	std::string number_str = stream.str();
	std::replace(number_str.begin(), number_str.end(), ',', '.');
	return stod(number_str);
}

struct defibrillator{
	int id_;
	string name_;
	string address_;
	string phone_number_;
	double longitude_;
	double latitude_;
};

void split_and_store(string line, struct defibrillator * def_s){
	int pos_id = line.find(";", 0);
	int pos_name = line.find(";", pos_id+1);
	int pos_address = line.find(";", pos_name+1);
	int pos_phone = line.find(";", pos_address+1);
	int pos_long = line.find(";", pos_phone+1);
	int pos_lat = line.find(";", pos_long+1);

	string id = line.substr(0, pos_id);
	string name = line.substr(pos_id+1, pos_name-pos_id-1);
	string address = line.substr(pos_name+1, pos_address - pos_name -1);
	string phone = line.substr(pos_address+1, pos_phone - pos_address -1);
	string longi = line.substr(pos_phone+1, pos_long - pos_phone -1);
	string lati = line.substr(pos_long+1, pos_lat - pos_long -1);

	def_s->id_ = stoi(id);
	def_s->name_ = name;
	def_s->address_ = address;
	def_s->phone_number_ = phone;
	def_s->longitude_ = get_number(longi);  
	def_s->latitude_ = get_number(lati);
}

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
	string LON;
	cin >> LON; cin.ignore();
	string LAT;
	cin >> LAT; cin.ignore();
	int N;
	cin >> N; cin.ignore();

	vector<defibrillator *> defibrillators(N);
	for (int i = 0; i < N; i++) {
		defibrillators.at(i) = new defibrillator();
		string s;
		getline(cin, s);
		split_and_store(s, defibrillators.at(i));
	}


	double LON_human = get_number(LON);
	double LAT_human = get_number(LAT);

	//caluclate first
	double d_min = d_calc(LON_human, defibrillators.at(0)->longitude_, LAT_human, defibrillators.at(0)->latitude_, 6371);
	int defibrillator_id = 0;
	for(int i=1; i < defibrillators.size(); i++){
		double d = d_calc(LON_human, defibrillators.at(i)->longitude_, LAT_human, defibrillators.at(i)->latitude_, 6371);
		if (d < d_min) {
			d_min = d;
			defibrillator_id = i;
		}
	}
	cout << defibrillators.at(defibrillator_id)->name_ << endl;
}
