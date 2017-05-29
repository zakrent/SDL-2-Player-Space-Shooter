#ifndef OSIM_VECTOR2D_H
#define OSIM_VECTOR2D_H

class Vector2D {
public:
    long double x, y;
    void normalize();
    Vector2D operator + (Vector2D SecVector);
    Vector2D operator - (Vector2D SecVector);
    Vector2D operator * (long double mul);
    void operator += (Vector2D SecVector);
    void operator -= (Vector2D SecVector);
    void operator *= (long double mul);
    Vector2D(long double x, long double y);

    ~Vector2D();
};

inline bool operator==(const Vector2D& first, const Vector2D& second){
    return first.x == second.x && first.y == second.y;
}

#endif 
