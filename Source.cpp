#include <iostream>

using namespace std;

class trip

{
protected:
	string name;
	int days;
public:
	trip() {
		name = "";
		days = 0;
	}

	trip(string str, int number):name(str), days(number) {}
	~trip() {}
	string get_name() { return name; }
	int get_days() { return days; }
	virtual int total_price() { return 0; }
};

class rest_abroad : public trip {
private:
	int one_day_price;
	int travel_price;
public:
	rest_abroad():trip(), one_day_price(0), travel_price(0) {}
	rest_abroad(string str1, int kst, int price1, int price2) : trip(str1, kst), one_day_price(price1), travel_price(price2){}
	~rest_abroad(){}
	int day_price() { return one_day_price; }
	int travel_pr() { return travel_price; }
	int total_price() { return (travel_price + one_day_price * days); }

	rest_abroad operator=(rest_abroad& obj) {
		this->name = obj.name;
		this->days = obj.days;
		this->one_day_price = obj.one_day_price;
		this->travel_price = obj.travel_price;

		return *this;
	}
};

void input(rest_abroad** p, int n) {
	for (int i = 0; i < n; i++) {
		cout << "Enter City Number " << i+1 << endl;
		string s;
		int d, d_price, b_price;
		cout << "Name of city: "; cin >> s;
		cout << "Amount of days: "; cin >> d;
		cout << "One day price: "; cin >> d_price;
		cout << "Bus cost: "; cin >> b_price;

		cout << "\n\n";

		p[i] = new rest_abroad(s, d, d_price, b_price);
	}
}

void sort_print(rest_abroad** p, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (p[j]->total_price() > p[j + 1]->total_price()) {
				rest_abroad temp = *p[j];
				*p[j] = *p[j + 1];
				*p[j + 1] = temp;
			}
		}
	}
	for (int i = 0;i < n;i++) {
		cout << "Name of city: " << p[i]->get_name() << "   " << "Amount of days: " << p[i]->get_days() << "   " << "Total Price: " << p[i]->total_price() << endl;
	}
}

int main() {
	rest_abroad **p;
	int kst;
	cout << "Enter amounts of trips: ";cin >> kst;
	cout << endl;
	p = new rest_abroad * [kst];
	input(p, kst);
	sort_print(p, kst);
	return 0;
}
