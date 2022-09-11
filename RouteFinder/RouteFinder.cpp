#include <iostream>
#include "SubwayLoader.h"
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
        if (objectville.hasConnection("Alex","mans","alexo")) {
            cout << "connection in Objecville test passed\n";
        }
        else {
            cout << "station in Objecville test failed\n";
        }
        
}
