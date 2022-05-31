#include <iostream>
#include <string>

using namespace std;

class Clock {
    protected:
        int Hour, minute, second;
        string meridian;
    public:
        Clock(int x, int y, int z, string r) {
            if (x <= 12 && x >= 1) Hour = x;
            if (z <= 60 && y >= 0) minute = y;
            if (z <= 60 && z >= 0) second = z;
            if(!r.compare("AM")||!r.compare("PM"))
                meridian = r;
        }
        void display() {
            cout<<Hour<<":"<<minute<<":"<<second<<" "<<meridian<<endl;
        }
};

class StandardClock : Clock {
    public: 
        StandardClock(int x, int y, int z, string r) : Clock(x, y, z, r) {};
        void display() {
            if(!meridian.compare("AM"))
                cout<<"上午 ";
            else
                cout<<"下午 ";
            cout<<Hour<<":"<<minute<<":"<<second<<endl;
        }
};

class MilitaryClock : Clock {
    public:
        MilitaryClock(int x, int y, int z, string r) : Clock(x, y, z, r) {};
        void display() {
            if(meridian.compare("AM"))
                Hour += 12;
            cout<<Hour<<":"<<minute<<":"<<second<<" "<<meridian<<endl;
        }
};

int main()
{
    Clock cc(10, 25, 43, "AM");
    StandardClock sc(10, 25, 43, "AM");
    MilitaryClock mc(10, 25, 43, "PM");
    cc.display();
    sc.display();
    mc.display();

    return 0;
}
