#ifndef VECTOR2_H
#define VECTOR2_H

#include <cmath>

class Vector2 {
public:
	float x;
	float y;

	Vector2();
	Vector2(float x, float y);

	// ~Vector2();

	Vector2 operator+(const Vector2& other) const;
	Vector2 operator-(const Vector2& other) const;
	Vector2 operator-() const;
	Vector2 operator*(float scalar) const;
	Vector2 operator/(float scalar) const;
	Vector2& operator+=(const Vector2& other);
	Vector2& operator-=(const Vector2& other);
	Vector2& operator*=(float scalar);
	Vector2& operator/=(float scalar);
	bool operator==(const Vector2& other) const;
	bool operator!=(const Vector2& other) const;

	static Vector2 Normalize(const Vector2& vector);
	static float Magnitude(const Vector2& vector);
	static float Dot(const Vector2& vector, const Vector2& other);
	static float Distance(const Vector2& vector, const Vector2& other);
};

#endif
