#pragma once
#include <corecrt_math.h>
#include <stdexcept>

/// <summary>
/// 3次元ベクトル
/// </summary>
struct Vector3 final {
	float x;
	mutable float y;
	float z;

	Vector3() : x(0.0f), y(0.0f), z(0.0f) {}

	Vector3(const float x, const float y, const float z) : x(x), y(y), z(z) {}

	float Length() const;
	float SqrLength() const;
	float Distance(const Vector3& other) const;
	float DotProduct(const Vector3& other) const;

	bool IsZero(float tolerance = 0.01f) const;

	Vector3 Normalize();
	Vector3 CrossProduct(const Vector3& other) const;

	float& operator[](int index);
	const float& operator[](int index) const;

	Vector3 operator+(const Vector3& rhs) const;
	Vector3 operator-(const Vector3& rhs) const;
	Vector3 operator*(const float scalar) const;
	Vector3 operator/(const float divisor) const;

	Vector3 operator+(const float& rhs) const;
	Vector3 operator-(const float& rhs) const;
	Vector3 operator*(const Vector3& rhs) const;
	Vector3 operator/(const Vector3& rhs) const;

	Vector3& operator+=(const Vector3& rhs);
	Vector3& operator-=(const Vector3& rhs);
	Vector3& operator*=(float scalar);
	Vector3& operator/=(float divisor);
};

inline float Vector3::Length() const {
	const float sqrLength = SqrLength();
	if (sqrLength > 0.0f) {
		return sqrtf(sqrLength);
	} else {
		return 0.0f;
	}
}

inline float Vector3::SqrLength() const { return x * x + y * y + z * z; }

inline float Vector3::Distance(const Vector3& other) const {
	const float distX = other.x - x;
	const float distY = other.y - y;
	const float distZ = other.z - z;
	return sqrtf(distX * distX + distY * distY + distZ * distZ);
}

inline float Vector3::DotProduct(const Vector3& other) const { return x * other.x + y * other.y + z * other.z; }

inline bool Vector3::IsZero(float tolerance) const { return (fabsf(x) < tolerance) && (fabsf(y) < tolerance) && (fabsf(z) < tolerance); };

inline Vector3 Vector3::Normalize() {
	const float sqrLength = SqrLength();
	if (sqrLength > 0.0f) {
		const float invLength = 1.0f / sqrtf(sqrLength);
		return {x * invLength, y * invLength, z * invLength};
	} else {
		return {0.0f, 0.0f, 0.0f};
	}
}

inline Vector3 Vector3::CrossProduct(const Vector3& other) const { return {y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x}; }

inline float& Vector3::operator[](const int index) {
	if (index == 0) {
		return x;
	} else if (index == 1) {
		return y;
	} else if (index == 2) {
		return z;
	} else {
		throw std::out_of_range("Vector3型の添字演算子に無効なインデックスが渡されました\n");
	}
}

inline const float& Vector3::operator[](const int index) const {
	if (index == 0) {
		return x;
	} else if (index == 1) {
		return y;
	} else if (index == 2) {
		return z;
	} else {
		throw std::out_of_range("Vector3型の添字演算子に無効なインデックスが渡されました");
	}
}

inline Vector3 Vector3::operator+(const Vector3& rhs) const { return {x + rhs.x, y + rhs.y, z + rhs.z}; }

inline Vector3 Vector3::operator-(const Vector3& rhs) const { return {x - rhs.x, y - rhs.y, z - rhs.z}; }

inline Vector3 Vector3::operator*(const float scalar) const { return {x * scalar, y * scalar, z * scalar}; }

inline Vector3 Vector3::operator/(const float divisor) const { return {x / divisor, y / divisor, z / divisor}; }

inline Vector3 Vector3::operator+(const float& rhs) const { return {x + rhs, y + rhs, z + rhs}; }

inline Vector3 Vector3::operator-(const float& rhs) const { return {x - rhs, y - rhs, z - rhs}; }

inline Vector3 Vector3::operator*(const Vector3& rhs) const { return {x * rhs.x, y * rhs.y, z * rhs.z}; }

inline Vector3 Vector3::operator/(const Vector3& rhs) const { return {x / rhs.x, y / rhs.y, z / rhs.z}; }

inline Vector3& Vector3::operator+=(const Vector3& rhs) {
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	return *this;
}

inline Vector3& Vector3::operator-=(const Vector3& rhs) {
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
	return *this;
}

inline Vector3& Vector3::operator*=(const float scalar) {
	x *= scalar;
	y *= scalar;
	z *= scalar;
	return *this;
}

inline Vector3& Vector3::operator/=(const float divisor) {
	x /= divisor;
	y /= divisor;
	z /= divisor;
	return *this;
}