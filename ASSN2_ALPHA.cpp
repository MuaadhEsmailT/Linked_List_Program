// created by Muaadh Esmail
#include <iostream>
#include <string>
#include"LinkedList.h"
using namespace std;

int main()
{

    int OR_UNORDER = 0;
    LinkedList<string> data;

    cout << "Add information based on:" << endl;
    cout << "[1] Unorder" << endl;
    cout << "[2] order" << endl;
    cin >> OR_UNORDER;

    if (OR_UNORDER == 1) {
        while (OR_UNORDER == 1) {
            data.unorder();

        }
    }
    else if (OR_UNORDER == 2) {
        while (OR_UNORDER == 2)
        {
            data.order();

        }
    }
    else {
        cout << "You most choose [1] OR [2]" << endl;
        return main();
    }


}
