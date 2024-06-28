#include "Vector2.h"

// Constructors
inline Vector2::Vector2() : x(0.0f), y(0.0f) {}

inline Vector2::Vector2(float x, float y) : x(x), y(y) {}

// Operator overloads
Vector2 Vector2::operator+(const Vector2& other) const {
	return Vector2(x + other.x, y + other.y);
}

Vector2 Vector2::operator-(const Vector2& other) const {
	return Vector2(x - other.x, y - other.y);
}

Vector2 Vector2::operator-() const {
	return Vector2(-x, -y);
}

Vector2 Vector2::operator*(float scalar) const {
	return Vector2(x * scalar, y * scalar);
}

Vector2 Vector2::operator/(float scalar) const {
	if (scalar != 0.0f) {
		return Vector2(x / scalar, y / scalar);
	}
	return *this; // return a copy of current vector if scalar is zero
}

Vector2& Vector2::operator+=(const Vector2& other) {
	x += other.x;
	y += other.y;
	return *this;
}

Vector2& Vector2::operator-=(const Vector2& other) {
	x -= other.x;
	y -= other.y;
	return *this;
}

Vector2& Vector2::operator*=(float scalar) {
	x *= scalar;
	y *= scalar;
	return *this;
}

Vector2& Vector2::operator/=(float scalar) {
	if (scalar != 0.0f) {
		x /= scalar;
		y /= scalar;
	}
	return *this;
}

bool Vector2::operator==(const Vector2& other) const {
	return x == other.x && y == other.y;
}

bool Vector2::operator!=(const Vector2& other) const {
	return !(*this == other);
}


// Static

Vector2 Vector2::Normalize(const Vector2& vector) {
	float mag = Magnitude(vector);
	if (mag != 0.0f) {
		return { vector.x / mag, vector.y / mag };
	}
	return vector;
}

float Vector2::Magnitude(const Vector2& vector) {
	return std::sqrt(vector.x * vector.x + vector.y * vector.y);
}

float Vector2::Dot(const Vector2& vector, const Vector2& other) {
	return vector.x * other.x + vector.y * other.y;
}

float Vector2::Distance(const Vector2& vector, const Vector2& other) {
	float dx = other.x - vector.x;
	float dy = other.y - vector.y;
	return std::sqrt(std::pow(dx, 2) + std::pow(dy, 2));
}