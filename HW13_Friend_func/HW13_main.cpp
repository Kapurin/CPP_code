// ДЗ: Разложить классы по *.h и *.cpp

#include <iostream>
#include <conio.h>
#include "Point3D.h"
#include "Vector3D.h"




int main()
{
    Point3D p(3.0, 4.0, 5.0);
    Vector3D v(3.0, 3.0, -2.0);

    p.print();
    p.moveByVector(v);
    p.print();


    _getch();
    return 0;
}



