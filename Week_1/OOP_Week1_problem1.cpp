#include <iostream>
//#include <cmath>

struct point {  // Here we make a struct that is going to resemble a point int the 2D space
    double x;   // Here w make x it can be a float or a double but double is more precise 
    double y;   // Here we take y the downfall of double is that it takes 8 bytes instead of 4
};

struct triangle // Here we make a struct triangle constisting of 3 point representing a triangle and area
{
    point p1; // point 1
    point p2; // point 2
    point p3; // point 3
    double Area; // this double holds the area of the triangle
};

void input_triangle(triangle& A) { // a fintion that recives a triangle as a reference in order to be able to change 
    std::cout << "Please input Point 1 X coodinate: "; // we prompt the user to input the X coordinate of point 1
    std::cin >> A.p1.x; // it's coordinates and set them based on user input 
    std::cout << "\n" << "Please input Point 1 Y coodinate: ";
    std::cin >> A.p1.y; // if A is not a reference we are going to change a copy that is going to be lost as soon as 
    std::cout << "\n" << "Please input Point 2 X coodinate: ";
    std::cin >> A.p2.x; // the function end 
    std::cout << "\n" << "Please input Point 2 Y coodinate: ";
    std::cin >> A.p2.y; // we cin each point's coordinate 
    std::cout << "\n" << "Please input Point 3 X coodinate: ";
    std::cin >> A.p3.x;
    std::cout << "\n" << "Please input Point 3 Y coodinate: ";
    std::cin >> A.p3.y;
    std::cout << "\n";
}

double area(const triangle& A) // we make a function that takes a const reference to a triangle A it is const because
{ // we aren't going to change anything 
    double a; // we create a local variable that is going to be deleted as soon as the funcion is finished 
    double b; // we store each side in such a variable
    double c;

    a = sqrt(pow(A.p1.x - A.p2.x, 2) + pow(A.p1.y - A.p2.y, 2));// we calculte each side using the pythagorean theorem
    b = sqrt(pow(A.p1.x - A.p3.x, 2) + pow(A.p1.y - A.p3.y, 2));
    c = sqrt(pow(A.p2.x - A.p3.x, 2) + pow(A.p2.y - A.p3.y, 2));

    //a = sqrt((A.p1.x-A.p2.x)*(A.p1.x - A.p2.x) + (A.p1.y - A.p2.y)* (A.p1.y - A.p2.y)); 
    // anoter way to calculate a, b and c without using pow 

    double p = (a + b + c) / 2; // another local variable for the half perimiter we are going to use it in the area
    return sqrt(p * (p - a) * (p - b) * (p - c)); // we calculate the area using herons formula

}

int main()
{
    std::cout << "This is a program that Sorts N triangles based on area --- N triangles are given with their 2D coordinates" << "\n";

    unsigned  int n; // this is an unsigned(we cant have -3 triangles) integer that is going to store the number of triangles 
    std::cout << "\n" << "Please input number of triangles N: "; // here we ask the user to input the nuber of triangles
    std::cin >> n; // we take n
    triangle* arr1 = new triangle[n]; // we make an array of n triangles in the dynamic memory
    for (int i = 0; i < n; i++) { // we use for loop to go trough all n triangles
        input_triangle(*(arr1 + i)); // we take the coordinates of each triangle
    }

    for (int i = 0; i < n; i++) { //  we use for loop to go trough all n triangles
        arr1[i].Area = area(*(arr1 + i)); // we set the area of each triangle to be eaqual to the calculated one
    }

    for (int i = 0; i < n - 1; i++) { // here we sort the triangles by area using a for loop in a for loop
        for (int j = i; j < n; j++) { // we compare the i trangle with all the remaing ones and choose the
            if (arr1[i].Area < arr1[j].Area) { // biggest to put n the i place 
                triangle temp = arr1[i]; // we swap the i triangle with the bigger j triangle
                arr1[i] = arr1[j]; // we use a temp value to do the swap
                arr1[j] = temp; // we can do it with a = a+b, b = a - b, a = a - b but if we do it like that
            }// we can loose information if a+b > than the max of double
        }
    }

    std::cout << "printing the triangles sorted by area" << "\n";

    for (int i = 0; i < n; i++) { //  we use for loop to go trough all n triangles
        std::cout << "Triangle " << i << " Area " << arr1[i].Area << "  --  "; // we print the Area
        std::cout << "Points: " << arr1[i].p1.x<<" " << arr1[i].p1.y << " " << arr1[i].p2.x << " " << arr1[i].p2.y << " " << arr1[i].p3.x << " " << arr1[i].p3.y << "\n";
        // we print each point of the triangle
    }

    delete[] arr1; // we delete the array that we alocated in the dynamic memory in order not to have a memory leak

    return 0;
}

