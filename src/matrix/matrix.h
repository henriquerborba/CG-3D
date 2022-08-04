/*
 * matrix.h
 */

#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <iostream>
#include "../vectors/vector2.h"
#include "../vectors/Vector3.h"

class Matrix
{
public:
    Matrix(int, int);
    Matrix(float **, int, int);
    Matrix();
    ~Matrix();
    Matrix(const Matrix &);
    Matrix &operator=(const Matrix &);

    inline float &operator()(int x, int y) { return p[x][y]; }

    Matrix &operator+=(const Matrix &);
    Matrix &operator-=(const Matrix &);
    Matrix &operator*=(const Matrix &);
    Matrix &operator*=(float);
    Matrix &operator/=(float);
    Matrix operator^(int);
    Vector2 operator*(Vector2 v);
    Vector3 operator*(Vector3 v);

    void swapRows(int, int);
    Matrix transpose();

    static Matrix createIdentity(int);

    // transformations 2d
    static Matrix scale2d(float sx, float sy);
    static Matrix rotate2d(float angle);
    static Matrix translate2d(float positionX, float positionY);

    // transformations 3d
    static Matrix scale3d(float sx, float sy, float sz);
    static Matrix translate3d(float positionX, float positionY, float positionZ);
    static Matrix rotateY(float angle);
    static Matrix rotateX(float angle);
    static Matrix rotateZ(float angle);

    // functions on vectors
    static float dotProduct(Matrix, Matrix);

    // functions on augmented matrices
    Matrix inverse();

    void print();

private:
    int rows_, cols_;
    float **p;

    void allocSpace();
    Matrix expHelper(const Matrix &, int);
};

Matrix operator+(const Matrix &, const Matrix &);
Matrix operator-(const Matrix &, const Matrix &);
Matrix operator*(const Matrix &, const Matrix &);
Matrix operator*(const Matrix &, float);
Matrix operator*(float, const Matrix &);
Matrix operator/(const Matrix &, float);

#endif
