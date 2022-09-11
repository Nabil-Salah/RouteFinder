#include <iostream>
#include "SubwayLoader.h"
#include "SubwayPrinter.h"
using namespace std;



int main()
{
    SubwayLoader loader{};
    Subway objectville;
    objectville= loader.loadFromFile("ObjectvilleSubway.txt");

    if (objectville.hasStation("Alex")) {
        cout<<"station in Objecville test passed\n";
    }
    else {
        cout << "station in Objecville test failed\n";
    }
    if (objectville.hasConnection("Alex","Damnohour","alexo")) {
        cout << "connection in Objecville test passed\n";
    }
    else {
        cout << "station in Objecville test failed\n";
    }
    vector<Connection>testroute = objectville.getDirections("Alex", "cod");
    SubwayPrinter print;
    print.printDirections(testroute);
}
